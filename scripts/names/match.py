#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""scripts/names/match.py - transfers Sly 1 function names onto Sly 2 by matching their code.

  python3 scripts/names/match.py work/export/sly1.jsonl work/export/sly2.jsonl config/recovered/ work/elf/SCUS_971.98 work/elf/SCUS_973.16 [work/export/sly1_bsim.jsonl work/export/sly2_bsim.jsonl]

With the BSim exports (ExportBsimFeatures.java: decompiler data-flow features, mostly compiler-proof), `score` leans on
their TF-IDF cosine and a `bsim` pass pairs nearest neighbours directly.

Inputs are ExportFunctions.java exports. Outputs:
  config/recovered/sly2_symbol_addrs.txt   splat format, one line per matched function, with the match method and score
  config/recovered/matches.tsv             every match: sly2 entry, sly1 entry, name, method, score
  config/recovered/report.md               coverage per method and per Sly 1 module, and the largest unmatched Sly 2 functions

Sly 2 was built with a different compiler setup than Sly 1 (its prologues save registers with sd/ld where Sly 1 uses sq/lq),
so only library code matches word for word. The anchors are those exact matches; everything else is scored on features that
survive a compiler change (`score`): which matched functions it calls, its constants, and a coarse instruction profile.

Passes, strongest first; each pass only looks at functions neither side has matched yet:
  1. exact     the instruction words with addresses and immediates masked are identical, and that shape is unique on both sides
  2. strings   the same set of referenced strings, unique on both sides
  3. calls     propagation: the unmatched callees of a matched pair, best candidate by `score`, clearly ahead of the runner-up
  4. callers   the same from the other side: the functions that call a matched pair
  5. vtables   pointer tables in the data (the engine's class method tables) that share matched methods are aligned slot by
               slot; the unmatched slots between aligned ones pair up by position (Sly 2 classes gained methods, so the
               alignment allows inserted slots)
  6. classes   whole class tables paired by a fingerprint of their methods (the matched functions they call, weighted by
               rarity, their constants, methods already matched); inside a paired class the unmatched methods take their
               best candidate among the other class's methods, helped by a similar relative slot position
  8a. slot     (with order, once the others settle) seeds from scripts/names/class_methods.py (config/recovered/class_method_pairs.tsv): methods
               aligned in vtable order inside the class pairs of the class diff (blind test: 19 of 34 re-paired, 0 wrong)
  8. order     (once the others settle) Sly 2 keeps Sly 1's function order inside a source file: between two anchors
               adjacent in both games, equal gaps pair by position, unequal ones (gap <= 20, slack <= 4) by a monotone
               alignment on score; every pair needs BSim cosine >= 0.3 (2026-10-20)
  9. mutual    unmatched pairs that are each other's nearest BSim neighbour (cosine >= 0.5, margin >= 0.05) and sit
               between the Sly 2 partners of their neighbouring anchors (2026-10-20)
     Both carry extra vetoes, since a check measured them worse than the base: size ratio under 0.5, or 3+
     more or fewer calls. After they add pairs, passes 3 to 7 run again. The mutual pass is disabled (see
     MUTUAL_THRESHOLD).
  7. global    any named Sly 1 function whose best Sly 2 candidate (same call count, give or take) is strong and clearly ahead
Passes 3 to 7 repeat until nothing new is found.
"""
import collections
import csv
import difflib
import re
import json
import math
import os
import struct
import sys

# MIPS (R5900) encodings: what changes between two builds of the same source is addresses (jumps, calls, %hi/%lo and
# $gp-relative offsets) and sometimes constants; the opcode and the registers mostly stay. These masks keep the latter.
J_TYPE = {0x02, 0x03}  # j, jal: 26-bit target
I_TYPE_MASK_IMMEDIATE = {
    0x01,  # regimm branches (bltz, bgez, ...)
    0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17,  # beq, bne, blez, bgtz and the likely forms
    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,  # addi, addiu, slti, sltiu, andi, ori, xori, lui
    0x18, 0x19, 0x1A, 0x1B, 0x1E, 0x1F,  # daddi, daddiu, ldl, ldr, lq, sq
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,  # loads
    0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,  # stores
    0x31, 0x33, 0x36, 0x37, 0x39, 0x3E, 0x3F,  # lwc1, pref, lqc2, ld, swc1, sqc2, sd
}


# Sly 2's statically linked PS2 SDK (989snd, libcdvd, libgcc...): 2026-10-20, from strings and the
# named neighbours on both edges. Game engine code (mangled names) doesn't belong here.
SDK_START, SDK_END = 0x2319E8, 0x256CE8
# Gates of the order and mutual passes (sweep in docs/build/name-recovery.md, 2026-10-20); MATCH_SWEEP="order,mutual" overrides. The mutual
# pass is off: its pairs disagreed with the call graph more as its BSim threshold rose (0.5: half inconsistent; 0.85:
# all), the clone families BSim can't tell apart. A threshold above 1 disables it.
ORDER_GATE, MUTUAL_THRESHOLD = 0.3, 2.0
if os.environ.get('MATCH_SWEEP'):
    ORDER_GATE, MUTUAL_THRESHOLD = (float(v) for v in os.environ['MATCH_SWEEP'].split(','))
# Library functions keep their own prefixes (Sly 1's 989snd client is mangled too, snd_GotReturns__Fv, and linked
# near the start of Sly 1, so neither mangling nor address tells library from engine there).
LIBRARY_NAME = re.compile(r'^(snd_|sce|Sce|Cd|Sif|Pad|Mc|Mtap|Dma|Gs|Vif|Gif|Ipu|Mpeg|_mpeg|__builtin|__ml__|__pl__|__mi__|__dv__)')


def mask(word):
    opcode = word >> 26
    if opcode in J_TYPE:
        return word & 0xFC000000
    if opcode in I_TYPE_MASK_IMMEDIATE:
        return word & 0xFFFF0000
    return word


# Instructions that mostly reflect the compiler's register saving and moves, not the source: left out of the profile.
NOISE = {'sq', 'lq', 'sd', 'ld', 'move', '_move', 'nop', 'addiu', '_addiu', 'daddu', 'or'}
BRANCHES = {'beq', 'bne', 'beql', 'bnel', 'blez', 'bgtz', 'bltz', 'bgez', 'bc1t', 'bc1f', 'bc1tl', 'bc1fl', 'beqz', 'bnez', 'b', '_beqz', '_bnez', '_b'}


def constants(words):
    """The source's constants: li/ori/andi/slti immediates, and lui values that are not addresses (float constants like
    0x3F80 = 1.0f; the ELF lives at 0x00100000-0x00400000, so lui 0x0010-0x003F builds addresses)."""
    found = collections.Counter()
    for word in words:
        opcode, rs, immediate = word >> 26, (word >> 21) & 31, word & 0xFFFF
        if opcode == 0x0F:  # lui
            if not 0x0010 <= immediate <= 0x003F and immediate != 0:
                found[('hi', immediate)] += 1
        elif opcode in (0x09, 0x0D) and rs == 0:  # li (addiu/ori from $zero)
            if immediate not in (0, 1, 0xFFFF):
                found[('li', immediate)] += 1
        elif opcode in (0x0C, 0x0A, 0x0B):  # andi, slti, sltiu
            found[('op', opcode, immediate)] += 1
    return found


def load(path):
    functions = {}
    with open(path, encoding='utf-8') as f:
        for line in f:
            function = json.loads(line)
            function['shape'] = tuple(mask(w) for w in function['words'])
            function['grams'] = collections.Counter(zip(function['mnemonics'], function['mnemonics'][1:], function['mnemonics'][2:]))
            function['profile'] = collections.Counter(m for m in function['mnemonics'] if m not in NOISE)
            function['constants'] = constants(function['words'])
            function['branches'] = sum(1 for m in function['mnemonics'] if m in BRANCHES)
            functions[function['entry']] = function
    return functions


def pointer_tables(elf_path, functions, stride, minimum=3):
    """The class method tables: runs of slots in the loaded segments whose pointer is a function entry (a 0 pointer keeps
    its slot). Sly 1 slots are 4 bytes (after a 16-byte header: parent table, class id, flag, object size); Sly 2 slots
    are 8 bytes, (pointer, 0), C++ style, so both alignments are scanned. Adjacent tables often meet without a header
    word that breaks the run (all-zero headers), so a run also ends where code references the data: a constructor
    storing its class's table. Each table is a list of entries (None for 0)."""
    referenced = {target for function in functions.values() for target in function['data']}
    data = open(elf_path, 'rb').read()
    program_header_offset, = struct.unpack_from('<I', data, 0x1C)
    program_header_count, = struct.unpack_from('<H', data, 0x2C)
    tables = []
    for index in range(program_header_count):
        kind, offset, _vaddr, _paddr, file_size = struct.unpack_from('<IIIII', data, program_header_offset + index * 32)
        if kind != 1:
            continue
        for alignment in range(0, stride, 4):
            run = []
            for position in range(offset + alignment, offset + file_size - stride + 1, stride):
                value, = struct.unpack_from('<I', data, position)
                tail_ok = stride == 4 or struct.unpack_from('<I', data, position + 4)[0] == 0
                address = _vaddr + position - offset
                if run and any(a in referenced for a in range(address, address + stride)):
                    while run and run[-1] is None:
                        run.pop()
                    if sum(1 for e in run if e) >= minimum:
                        tables.append(run)
                    run = []
                if tail_ok and value in functions:
                    run.append(value)
                elif tail_ok and value == 0 and run:
                    run.append(None)
                else:
                    while run and run[-1] is None:
                        run.pop()
                    if sum(1 for e in run if e) >= minimum:
                        tables.append(run)
                    run = []
    return tables


def load_bsim(paths, sly1, sly2):
    """Adds function['bsim']: the TF-IDF weighted, unit-length BSim feature vector (dict), shared IDF over both games."""
    raw = []
    for functions, path in ((sly1, paths[0]), (sly2, paths[1])):
        with open(path, encoding='utf-8') as f:
            for line in f:
                record = json.loads(line)
                if record['entry'] in functions:
                    raw.append((functions, record['entry'], collections.Counter(record['features'])))
    document_frequency = collections.Counter(feature for _, _, features in raw for feature in features)
    total = len(raw)
    for functions, entry, features in raw:
        vector = {k: v * math.log(total / document_frequency[k]) for k, v in features.items()}
        norm = math.sqrt(sum(x * x for x in vector.values())) or 1.0
        functions[entry]['bsim'] = {k: x / norm for k, x in vector.items()}


def cosine(a, b):
    if len(a) > len(b):
        a, b = b, a
    return sum(x * b.get(k, 0.0) for k, x in a.items())


def callers_of(functions):
    callers = collections.defaultdict(list)
    for function in functions.values():
        for callee in function['calls']:
            callers[callee].append(function['entry'])
    return callers


def overlap(a, b):
    """Weighted Jaccard of two Counters; None when both are empty (no evidence either way)."""
    if not a and not b:
        return None
    union = sum((a | b).values())
    return sum((a & b).values()) / union if union else None


def ratio(x, y):
    return 1.0 if x == y else min(x, y) / max(x, y) if max(x, y) else 1.0


def similarity(a, b):
    """0..1: the instruction 3-gram profiles' overlap, scaled down when the sizes differ a lot."""
    if not a['grams'] or not b['grams']:
        return 1.0 if a['shape'] == b['shape'] else 0.0
    common = sum((a['grams'] & b['grams']).values())
    total = max(sum(a['grams'].values()), sum(b['grams'].values()))
    return common / total


class Matcher:
    def score(self, e1, e2):
        """0..1, compiler-proof: agreement of the already matched callees, constants, coarse profile, sizes."""
        a, b = self.sly1[e1], self.sly2[e2]
        parts = []  # (weight, value)
        mapped = [self.forward[c] for c in a['calls'] if c in self.forward]
        if mapped:
            callees2 = collections.Counter(b['calls'])
            hits = sum((collections.Counter(mapped) & callees2).values())
            parts.append((3.0, hits / max(len(mapped), sum(1 for c in b['calls'] if c in self.backward), 1)))
        constant_overlap = overlap(a['constants'], b['constants'])
        if constant_overlap is not None:
            parts.append((2.0, constant_overlap))
        profile_overlap = overlap(a['profile'], b['profile'])
        if profile_overlap is not None:
            parts.append((1.5, profile_overlap))
        parts.append((1.0, ratio(len(a['calls']), len(b['calls']))))
        parts.append((0.5, ratio(a['branches'], b['branches'])))
        parts.append((0.5, ratio(len(a['words']), len(b['words']))))
        base = sum(w * v for w, v in parts) / sum(w for w, _ in parts)
        # BSim only raises a score: true pairs whose body changed between the games still have low cosines (measured:
        # bottom quartile 0.04-0.36), while unrelated pairs almost never reach a high one (99th percentile 0.18)
        if 'bsim' in a and 'bsim' in b and len(a['words']) >= 8:
            return max(base, 0.5 * base + 0.5 * cosine(a['bsim'], b['bsim']))
        return base

    def __init__(self, sly1, sly2, tables1=(), tables2=()):
        self.sly1, self.sly2 = sly1, sly2
        self.tables1, self.tables2 = list(tables1), list(tables2)
        self.class_pairs = []
        self.vetoed = []
        self.extended = False
        self.seeds = []
        self.bsim_ready = any('bsim' in f for f in sly1.values())
        self.forward = {}  # sly1 entry -> sly2 entry
        self.backward = {}  # sly2 entry -> (sly1 entry, method, score)
        self.callers1, self.callers2 = callers_of(sly1), callers_of(sly2)

    def named(self, entry1):
        return self.sly1[entry1]['name'] is not None

    def veto(self, entry1, entry2, method):
        """Why a proposed match can't be right, or None. The byte-identical exact pass is exempt. 2026-10-20
        (ground-truth-4, assets-4) found each of these producing confirmed wrong names."""
        if method == 'exact':
            return None
        name = self.sly1[entry1]['name'] or ''
        if SDK_START <= entry2 < SDK_END and '__' in name and not LIBRARY_NAME.match(name):
            return 'game name in the SDK block'  # SetSoNoInteract on a 989snd wrapper
        size2 = len(self.sly2[entry2]['words'])
        if method == 'bsim' and size2 < 4:
            return 'bsim on a stub'  # CloneLoHierarchy on an 8-byte j; nop thunk
        if method in ('order', 'mutual', 'slot'):
            words1, words2 = len(self.sly1[entry1]['words']), len(self.sly2[entry2]['words'])
            if ratio(words1, words2) < 0.5:
                return 'size ratio under 0.5'
            if abs(len(self.sly1[entry1]['calls']) - len(self.sly2[entry2]['calls'])) >= 3:
                return 'call count differs by 3+'
        callers2, callers1 = len(self.callers2.get(entry2, ())), len(self.callers1.get(entry1, ()))
        if size2 < 16 and callers2 >= 20 and callers2 >= 10 * (callers1 + 1):
            return 'small helper with far more callers'  # FOpenFile on a 118-caller stack helper
        return None

    def add(self, entry1, entry2, method, score):
        if entry1 in self.forward or entry2 in self.backward:
            return False
        reason = self.veto(entry1, entry2, method)
        if reason:
            self.vetoed.append((entry2, entry1, self.sly1[entry1]['name'], method, score, reason))
            return False
        self.forward[entry1] = entry2
        self.backward[entry2] = (entry1, method, score)
        return True

    def unique_key_pass(self, key, method, minimum_words=4):
        groups1, groups2 = collections.defaultdict(list), collections.defaultdict(list)
        for entry, function in self.sly1.items():
            if entry not in self.forward and len(function['words']) >= minimum_words:
                k = key(function)
                if k:
                    groups1[k].append(entry)
        for entry, function in self.sly2.items():
            if entry not in self.backward and len(function['words']) >= minimum_words:
                k = key(function)
                if k:
                    groups2[k].append(entry)
        found = 0
        for k, entries1 in groups1.items():
            entries2 = groups2.get(k, [])
            if len(entries1) == 1 and len(entries2) == 1:
                found += self.add(entries1[0], entries2[0], method, 1.0)
        return found

    def best(self, e1, candidates, threshold, margin):
        scored = sorted(((self.score(e1, e2), e2) for e2 in candidates if e2 not in self.backward), reverse=True)[:2]
        if scored and scored[0][0] >= threshold and (len(scored) == 1 or scored[0][0] - scored[1][0] >= margin):
            return scored[0]
        return None

    def neighbour_pass(self, method, neighbours1, neighbours2, threshold=0.7, margin=0.08):
        """For every matched pair, each unmatched neighbour on the Sly 1 side takes its best unmatched neighbour on the Sly 2 side."""
        found = 0
        for entry1, entry2 in list(self.forward.items()):
            candidates = [e for e in dict.fromkeys(neighbours2(entry2)) if e in self.sly2 and e not in self.backward]
            if not candidates:
                continue
            for e1 in dict.fromkeys(neighbours1(entry1)):
                if e1 not in self.sly1 or e1 in self.forward:
                    continue
                pick = self.best(e1, candidates, threshold, margin)
                if pick:
                    found += self.add(e1, pick[1], method, round(pick[0], 3))
                    candidates = [c for c in candidates if c != pick[1]]
        return found

    def vtable_pass(self, threshold=0.45, minimum_anchors=2):
        """Aligns each Sly 1 pointer table with the Sly 2 table that shares the most matched slots, then pairs the
        unmatched slots inside equal-length gaps between aligned slots. A slot is strong structural evidence, so the
        score threshold is lower than elsewhere; it still rejects a slot whose code clearly differs."""
        tables_with = collections.defaultdict(set)
        for index, table in enumerate(self.tables2):
            for entry in table:
                if entry:
                    tables_with[entry].add(index)
        found = 0
        for table1 in self.tables1:
            mapped = [self.forward.get(e) if e else None for e in table1]
            votes = collections.Counter(i for m in mapped if m for i in tables_with.get(m, ()))
            if not votes:
                continue
            index2, anchors = votes.most_common(1)[0]
            if anchors < minimum_anchors:
                continue
            table2 = self.tables2[index2]
            tokens1 = [m if m else ('unmatched', position) for position, m in enumerate(mapped)]
            blocks = difflib.SequenceMatcher(None, tokens1, table2, autojunk=False).get_matching_blocks()
            previous1 = previous2 = 0
            for block in blocks:
                gap1, gap2 = table1[previous1:block.a], table2[previous2:block.b]
                if len(gap1) == len(gap2):
                    for e1, e2 in zip(gap1, gap2):
                        if e1 and e2 and e1 not in self.forward and e2 not in self.backward and self.score(e1, e2) >= threshold:
                            found += self.add(e1, e2, 'vtable', round(self.score(e1, e2), 3))
                previous1, previous2 = block.a + block.size, block.b + block.size
        return found

    def class_fingerprint(self, table, side):
        """The Sly 2 entries a class's methods call (Sly 1 callees through the matches so far), and its own matched methods,
        each weighted by rarity; plus its methods' constants."""
        functions = self.sly1 if side == 1 else self.sly2
        callees = collections.Counter()
        constants_found = collections.Counter()
        for method in set(e for e in table if e):
            function = functions[method]
            constants_found.update(function['constants'])
            if side == 1:
                if method in self.forward:
                    callees[('method', self.forward[method])] += 1
                for callee in function['calls']:
                    if callee in self.forward:
                        callees[('call', self.forward[callee])] += 1
            else:
                if method in self.backward:
                    callees[('method', method)] += 1
                for callee in function['calls']:
                    if callee in self.backward:
                        callees[('call', callee)] += 1
        return callees, constants_found

    def class_pass(self, table_threshold=0.25, table_margin=0.05, method_threshold=0.5, method_margin=0.05):
        # how many Sly 2 functions call each callee: common helpers say little about a class
        call_frequency = collections.Counter(c for f in self.sly2.values() for c in set(f['calls']))
        weight = lambda key: 1.0 / (1 + call_frequency.get(key[1], 0)) ** 0.5 if key[0] == 'call' else 2.0

        def weighted_overlap(a, b):
            keys = set(a) | set(b)
            union = sum(max(a[k], b[k]) * weight(k) for k in keys)
            return sum(min(a[k], b[k]) * weight(k) for k in keys) / union if union else 0.0

        # a method in many tables is an inherited default: ambiguous inside one class, left to the other passes
        tables_per1 = collections.Counter(e for t in self.tables1 for e in set(t) if e)
        tables_per2 = collections.Counter(e for t in self.tables2 for e in set(t) if e)
        prints1 = [self.class_fingerprint(t, 1) for t in self.tables1]
        prints2 = [self.class_fingerprint(t, 2) for t in self.tables2]
        found = 0
        used2 = set()
        pairs = []
        for i, (calls1, constants1) in enumerate(prints1):
            if not calls1:
                continue
            scored = []
            for j, (calls2, constants2) in enumerate(prints2):
                if not calls2:
                    continue
                size = ratio(len(self.tables1[i]), len(self.tables2[j]))
                constant_overlap = overlap(constants1, constants2) or 0.0
                scored.append((0.65 * weighted_overlap(calls1, calls2) + 0.2 * constant_overlap + 0.15 * size, j))
            scored.sort(reverse=True)
            if scored and scored[0][0] >= table_threshold and (len(scored) == 1 or scored[0][0] - scored[1][0] >= table_margin):
                pairs.append((scored[0][0], i, scored[0][1]))
        self.class_pairs = []
        for table_score, i, j in sorted(pairs, reverse=True):
            if j in used2:
                continue
            used2.add(j)
            self.class_pairs.append((i, j, round(table_score, 3)))
            table1, table2 = self.tables1[i], self.tables2[j]
            methods1 = [e for e in dict.fromkeys(table1) if e and e not in self.forward and tables_per1[e] <= 3]
            methods2 = [e for e in dict.fromkeys(table2) if e and e not in self.backward and tables_per2[e] <= 3]
            # many candidates make a wrong pick likelier: ask for more as the class grows
            threshold = method_threshold if len(methods2) <= 8 else method_threshold + 0.2
            position1 = {e: table1.index(e) / len(table1) for e in methods1}
            position2 = {e: table2.index(e) / len(table2) for e in methods2}
            for e1 in methods1:
                scored = sorted(((0.85 * self.score(e1, e2) + 0.15 * (1 - abs(position1[e1] - position2[e2])), e2) for e2 in methods2 if e2 not in self.backward), reverse=True)[:2]
                if scored and scored[0][0] >= threshold and (len(scored) == 1 or scored[0][0] - scored[1][0] >= method_margin):
                    found += self.add(e1, scored[0][1], 'class', round(scored[0][0], 3))
        return found

    def bsim_pass(self, threshold=0.85, margin=0.05, minimum_words=8, common=300):
        """Named Sly 1 functions against their nearest Sly 2 functions by BSim cosine (inverted index over the features
        that are not in too many functions), checked with the full `score`."""
        if not self.bsim_ready:
            return 0
        index = collections.defaultdict(list)
        for entry, function in self.sly2.items():
            if entry not in self.backward and 'bsim' in function:
                for feature in function['bsim']:
                    index[feature].append(entry)
        found = 0
        for entry1, function in self.sly1.items():
            if entry1 in self.forward or not self.named(entry1) or 'bsim' not in function or len(function['words']) < minimum_words:
                continue
            totals = collections.Counter()
            for feature, x in function['bsim'].items():
                postings = index.get(feature, ())
                if len(postings) <= common:
                    for entry2 in postings:
                        totals[entry2] += x * self.sly2[entry2]['bsim'][feature]
            candidates = [e for e, _ in totals.most_common(5) if e not in self.backward]
            if not candidates:
                continue
            cosines = sorted(((cosine(function['bsim'], self.sly2[e]['bsim']), e) for e in candidates), reverse=True)
            best_cosine, best = cosines[0]
            runner_up = cosines[1][0] if len(cosines) > 1 else 0.0
            if best_cosine >= threshold and best_cosine - runner_up >= margin and self.score(entry1, best) >= 0.7:
                found += self.add(entry1, best, 'bsim', round(best_cosine, 3))
        return found

    def seed_pass(self):
        found = 0
        for entry1, entry2, score in self.seeds:
            if entry1 in self.sly1 and entry2 in self.sly2:
                found += self.add(entry1, entry2, 'slot', score)
        return found

    def cosine_of(self, entry1, entry2):
        a, b = self.sly1[entry1].get('bsim'), self.sly2[entry2].get('bsim')
        return cosine(a, b) if a and b else 0.0

    def order_pass(self, slack=4, max_gap=20, minimum=0.5, gate=None):
        gate = ORDER_GATE if gate is None else gate
        if not self.bsim_ready:
            return 0
        order1, order2 = sorted(self.sly1), sorted(self.sly2)
        rank1, rank2 = {e: i for i, e in enumerate(order1)}, {e: i for i, e in enumerate(order2)}
        anchors = sorted(self.forward.items())
        proposals = []
        for (a, b), (c, d) in zip(anchors, anchors[1:]):
            if d <= b:
                continue
            gap1, gap2 = rank1[c] - rank1[a], rank2[d] - rank2[b]
            if gap1 < 2 or gap2 < 2 or gap1 > max_gap or abs(gap1 - gap2) > slack:
                continue
            between1 = [order1[rank1[a] + t] for t in range(1, gap1)]
            between2 = [order2[rank2[b] + t] for t in range(1, gap2)]
            if gap1 == gap2:
                pairs = list(zip(between1, between2))
            else:
                pairs = self.monotone_alignment([x for x in between1 if x not in self.forward],
                                                [y for y in between2 if y not in self.backward], minimum)
            for x, y in pairs:
                if x not in self.forward and y not in self.backward and self.cosine_of(x, y) >= gate:
                    proposals.append((x, y))
        found = 0
        for x, y in proposals:
            found += self.add(x, y, 'order', round(self.score(x, y), 3))
        return found

    def monotone_alignment(self, xs, ys, minimum):
        """The order-keeping pairing of xs and ys that maximises the summed score, pairs under minimum excluded."""
        scores = [[self.score(x, y) for y in ys] for x in xs]
        n, k = len(xs), len(ys)
        best = [[0.0] * (k + 1) for _ in range(n + 1)]
        step = [[None] * (k + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                options = [(best[i - 1][j], 'up'), (best[i][j - 1], 'left')]
                if scores[i - 1][j - 1] >= minimum:
                    options.append((best[i - 1][j - 1] + scores[i - 1][j - 1], 'diagonal'))
                best[i][j], step[i][j] = max(options)
        pairs, i, j = [], n, k
        while i and j:
            if step[i][j] == 'diagonal':
                pairs.append((xs[i - 1], ys[j - 1]))
                i, j = i - 1, j - 1
            elif step[i][j] == 'up':
                i -= 1
            else:
                j -= 1
        return pairs

    def mutual_pass(self, threshold=None, margin=0.05, common=300):
        threshold = MUTUAL_THRESHOLD if threshold is None else threshold
        if not self.bsim_ready:
            return 0
        import bisect
        free1 = [e for e, f in self.sly1.items() if e not in self.forward and f['name'] and 'bsim' in f]
        free2 = [e for e, f in self.sly2.items() if e not in self.backward and 'bsim' in f]

        def nearest(sources, targets, side_from, side_to):
            index = collections.defaultdict(list)
            for entry in targets:
                for feature in side_to[entry]['bsim']:
                    index[feature].append(entry)
            result = {}
            for entry in sources:
                totals = collections.Counter()
                for feature, x in side_from[entry]['bsim'].items():
                    postings = index.get(feature, ())
                    if len(postings) <= common:
                        for other in postings:
                            totals[other] += x * side_to[other]['bsim'][feature]
                # the index skips very common features: shortlist with it, then rank by the exact cosine
                shortlist = sorted(((cosine(side_from[entry]['bsim'], side_to[other]['bsim']), other) for other, _ in totals.most_common(5)), reverse=True)
                if shortlist:
                    runner_up = shortlist[1][0] if len(shortlist) > 1 else 0.0
                    result[entry] = (shortlist[0][1], shortlist[0][0], shortlist[0][0] - runner_up)
            return result

        forward_best = nearest(free1, free2, self.sly1, self.sly2)
        backward_best = nearest(free2, free1, self.sly2, self.sly1)
        anchors1 = sorted(self.forward)
        found = 0
        for x, (y, value, gap) in forward_best.items():
            if value < threshold or gap < margin or backward_best.get(y, (None,))[0] != x:
                continue
            position = bisect.bisect_left(anchors1, x)
            if position == 0 or position >= len(anchors1):
                continue
            low, high = self.forward[anchors1[position - 1]], self.forward[anchors1[position]]
            if not (high > low and low < y < high):
                continue  # outside its address window
            found += self.add(x, y, 'mutual', round(value, 3))
        return found

    def fuzzy_pass(self, threshold=0.8, margin=0.1, minimum_words=12):
        """Named Sly 1 functions against every unmatched Sly 2 function with about the same number of calls."""
        by_calls = collections.defaultdict(list)
        for entry, function in self.sly2.items():
            if entry not in self.backward and len(function['words']) >= minimum_words:
                by_calls[len(function['calls'])].append(entry)
        found = 0
        for entry1, function in self.sly1.items():
            if entry1 in self.forward or len(function['words']) < minimum_words or not self.named(entry1):
                continue
            n = len(function['calls'])
            candidates = [e for k in range(max(0, n - 1), n + 2) for e in by_calls.get(k, []) if e not in self.backward]
            candidates = [e for e in candidates if ratio(len(function['words']), len(self.sly2[e]['words'])) > 0.5]
            pick = self.best(entry1, candidates, threshold, margin)
            if pick:
                found += self.add(entry1, pick[1], 'global', round(pick[0], 3))
        return found

    def run(self):
        log = []
        log.append(('exact', self.unique_key_pass(lambda f: f['shape'], 'exact')))
        log.append(('strings', self.unique_key_pass(lambda f: tuple(sorted(set(f['strings']))), 'strings', minimum_words=1)))
        for round_number in range(1, 20):
            found_calls = self.neighbour_pass('calls', lambda e: self.sly1[e]['calls'], lambda e: self.sly2[e]['calls'])
            found_callers = self.neighbour_pass('callers', lambda e: sorted(self.callers1[e]), lambda e: sorted(self.callers2[e]))
            found_exact = self.unique_key_pass(lambda f: f['shape'], 'exact')
            found_vtable = self.vtable_pass() + self.class_pass() + self.bsim_pass()
            found_fuzzy = self.fuzzy_pass()
            total = found_calls + found_callers + found_exact + found_vtable + found_fuzzy
            log.append((f'round {round_number}', total))
            if total == 0:
                if self.extended or not self.bsim_ready:
                    break
                self.extended = True  # once the base passes settle: order and mutual, then the rounds again
                # late, so they fill gaps instead of re-routing the cascade: applied first, the slot seeds moved
                # LoadLoFromBrx off the base loader 0x231170 and InitEyes onto InitCircler's function
                extra = self.seed_pass() + self.order_pass() + self.mutual_pass()
                log.append(('slot seeds + order + mutual', extra))
                if extra == 0:
                    break
        return log


def module_of(name):
    # GCC 2.95 mangling: Name__FP<len><TYPE>... -> the first class-ish argument is the module (CloneAsegbl__FP6ASEGBLP2LO -> ASEGBL)
    if '__F' in name:
        rest = name.split('__F', 1)[1].lstrip('PRC')
        digits = ''
        while rest and rest[0].isdigit():
            digits += rest[0]
            rest = rest[1:]
        if digits:
            return rest[:int(digits)]
    if '__' in name:
        tail = name.split('__', 1)[1]
        digits = ''
        while tail and tail[0].isdigit():
            digits += tail[0]
            tail = tail[1:]
        if digits:
            return tail[:int(digits)]
    return '(free)'


def main():
    if len(sys.argv) not in (6, 8):
        sys.exit(__doc__)
    sly1, sly2 = load(sys.argv[1]), load(sys.argv[2])
    if len(sys.argv) == 8:
        load_bsim(sys.argv[6:8], sly1, sly2)
    out = sys.argv[3]
    os.makedirs(out, exist_ok=True)
    tables1, tables2 = pointer_tables(sys.argv[4], sly1, 4), pointer_tables(sys.argv[5], sly2, 8)
    print(f'pointer tables: {len(tables1)} in Sly 1, {len(tables2)} in Sly 2')
    matcher = Matcher(sly1, sly2, tables1, tables2)
    seeds_path = os.path.join(out, 'class_method_pairs.tsv')
    if os.path.isfile(seeds_path):
        with open(seeds_path, encoding='utf-8') as f:
            matcher.seeds = [(int(r['sly1_entry'], 16), int(r['sly2_entry'], 16), float(r['score'])) for r in csv.DictReader(f, delimiter='\t')]
    log = matcher.run()

    with open(os.path.join(out, 'vetoed.tsv'), 'w', encoding='utf-8') as f:
        f.write('sly2_entry\tsly1_entry\tname\tmethod\tscore\treason\n')
        for entry2, entry1, name, method, score, reason in sorted(set(matcher.vetoed)):
            f.write(f'0x{entry2:X}\t0x{entry1:X}\t{name or ""}\t{method}\t{score}\t{reason}\n')
    rows = []
    for entry2, (entry1, method, score) in sorted(matcher.backward.items()):
        rows.append((entry2, entry1, sly1[entry1]['name'], method, score))
    named_rows = [r for r in rows if r[2]]
    with open(os.path.join(out, 'matches.tsv'), 'w', encoding='utf-8') as f:
        f.write('sly2_entry\tsly1_entry\tname\tmethod\tscore\n')
        for entry2, entry1, name, method, score in rows:
            f.write(f'0x{entry2:X}\t0x{entry1:X}\t{name or ""}\t{method}\t{score}\n')
    with open(os.path.join(out, 'sly2_symbol_addrs.txt'), 'w', encoding='utf-8') as f:
        f.write('// Sly 2 (SCUS-97316) names transferred from the Sly 1 decomp by scripts/names/match.py. Unverified: check before relying on them.\n')
        used = collections.Counter()
        for entry2, entry1, name, method, score in named_rows:
            used[name] += 1
            unique = name if used[name] == 1 else f'{name}_{used[name]}'
            f.write(f'{unique} = 0x{entry2:X}; // type:func match:{method} score:{score} sly1:0x{entry1:X}\n')

    methods = collections.Counter(r[3] for r in named_rows)
    named1 = sum(1 for f in sly1.values() if f['name'])
    modules1 = collections.Counter(module_of(f['name']) for f in sly1.values() if f['name'])
    modules_matched = collections.Counter(module_of(r[2]) for r in named_rows)
    unmatched2 = sorted((f for e, f in sly2.items() if e not in matcher.backward), key=lambda f: -len(f['words']))
    with open(os.path.join(out, 'report.md'), 'w', encoding='utf-8') as f:
        f.write('# Sly 1 -> Sly 2 name transfer\n\n')
        f.write(f'- Sly 1 functions: {len(sly1)} ({named1} named by the decomp)\n')
        f.write(f'- Sly 2 functions: {len(sly2)}\n')
        f.write(f'- Sly 2 functions given a Sly 1 name: **{len(named_rows)}** ({100 * len(named_rows) / len(sly2):.1f}% of Sly 2, {100 * len(named_rows) / max(named1, 1):.1f}% of the named Sly 1 functions)\n\n')
        f.write('## By method\n\n| Method | Matches |\n|---|---|\n')
        for method, count in methods.most_common():
            f.write(f'| {method} | {count} |\n')
        f.write('\n## Passes\n\n| Pass | New matches |\n|---|---|\n')
        for name, count in log:
            f.write(f'| {name} | {count} |\n')
        f.write('\n## By Sly 1 module (largest first)\n\n| Module | Sly 1 named | Found in Sly 2 |\n|---|---|---|\n')
        for module, count in modules1.most_common(60):
            f.write(f'| {module} | {count} | {modules_matched.get(module, 0)} |\n')
        f.write('\n## Largest unmatched Sly 2 functions (likely new or rewritten in Sly 2)\n\n| Entry | Instructions | Strings |\n|---|---|---|\n')
        for function in unmatched2[:40]:
            strings = ', '.join(sorted(set(function['strings'])))[:80].replace('|', '/')
            f.write(f"| 0x{function['entry']:X} | {len(function['words'])} | {strings} |\n")
    print(open(os.path.join(out, 'report.md'), encoding='utf-8').read().split('## By Sly 1 module')[0])


if __name__ == '__main__':
    main()
