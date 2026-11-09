#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Regression tests for the scripts that need neither the game nor the compiler: `python3 -m unittest discover -s tests -v`."""
import json
import os
import sys
import struct
import unittest

HERE = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'scripts')
sys.path[:0] = [HERE, os.path.join(HERE, 'build'), os.path.join(HERE, 'matching'), os.path.join(HERE, 'vu')]
sys.path.insert(0, os.path.join(HERE, 'build'))

import asm_units  # noqa: E402
import blockers_report  # noqa: E402
import check_cleanup  # noqa: E402
import claim  # noqa: E402
import check_source  # noqa: E402
import adopt  # noqa: E402
import classify_blockers  # noqa: E402
import classify_diffs  # noqa: E402
import check_unit  # noqa: E402
import commit_msg  # noqa: E402
import boundaries  # noqa: E402
import compile_unit  # noqa: E402
import credit_audit  # noqa: E402
import harvest  # noqa: E402
import export_nonmatching  # noqa: E402
import list_functions  # noqa: E402
import make_whole_files  # noqa: E402
import export_src  # noqa: E402
import idioms  # noqa: E402
import mutate  # noqa: E402
import neighborhood  # noqa: E402
import permute  # noqa: E402
import permute_stores  # noqa: E402
import search_guard  # noqa: E402
import boundary_suspects  # noqa: E402
import rules  # noqa: E402
import park  # noqa: E402
import record  # noqa: E402
import progress  # noqa: E402
import pair_versions  # noqa: E402
import version_check  # noqa: E402
import pal_report  # noqa: E402
import disc_extract  # noqa: E402
import prologue_profile  # noqa: E402
import vuasm  # noqa: E402
import vudis  # noqa: E402


class CommitMessageTests(unittest.TestCase):
    def test_accepts_type_and_summary(self):
        self.assertEqual(commit_msg.check('docs: explain the build\n\nbody'), [])

    def test_accepts_scope(self):
        self.assertEqual(commit_msg.check('feat(us): 1CBB58 exact match'), [])

    def test_rejects_unknown_type(self):
        self.assertTrue(commit_msg.check('decomp: add a thing'))

    def test_rejects_uppercase_scope(self):
        self.assertTrue(commit_msg.check('fix(Tools): a thing'))

    def test_rejects_long_body_line(self):
        self.assertTrue(commit_msg.check('docs: a thing\n\n' + 'word ' * 20))

    def test_accepts_long_url_line(self):
        self.assertEqual(commit_msg.check('docs: a thing\n\nhttps://example.com/' + 'x' * 100), [])

    def test_rejects_attribution_trailer(self):
        self.assertTrue(commit_msg.check('docs: a thing\n\nCo-Authored-By: Someone <a@b.c>'))

    def test_rejects_missing_type(self):
        self.assertTrue(commit_msg.check('Recover some names'))

    def test_rejects_trailing_period(self):
        self.assertTrue(commit_msg.check('docs: explain the build.'))

    def test_rejects_long_subject(self):
        self.assertTrue(commit_msg.check('fix: ' + 'x' * 130))

    def test_ignores_merge_commits(self):
        self.assertEqual(commit_msg.check('Merge branch main into topic'), [])


SAMPLE_DIFF = '\n'.join([
    'diff --git a/src/mat/Foo.c b/src/mat/Foo.c',
    '--- a/src/mat/Foo.c',
    '+++ b/src/mat/Foo.c',
    '@@ -3,0 +4,3 @@ int Foo(void)',
    '+    int value = M2C_FIELD(arg0, s32 *, 0x10);',
    '+    return value;',
    '+\tint tabbed; ',
    ''])


class CleanupTests(unittest.TestCase):
    def test_parse_diff_gives_line_numbers(self):
        self.assertEqual([number for number, _ in check_cleanup.parse_diff(SAMPLE_DIFF)['src/mat/Foo.c']], [4, 5, 6])

    def test_flags_raw_offsets_tabs_and_trailing_whitespace(self):
        problems = check_cleanup.check_lines(check_cleanup.parse_diff(SAMPLE_DIFF))
        self.assertEqual(len(problems), 3)  # the offset macro, then the tab and the trailing space of the last line
        self.assertIn('src/mat/Foo.c:4:', problems[0])

    def test_clean_lines_pass(self):
        self.assertEqual(check_cleanup.check_lines({'src/mat/Foo.c': [(1, 'int Foo(void) { return 1; }')]}), [])

    def test_other_files_are_not_code(self):
        self.assertEqual(check_cleanup.check_lines({'docs/a.md': [(1, 'M2C_FIELD tab\t')]}), [])

    def test_game_data_files_are_flagged(self):
        flagged = check_cleanup.check_files(['work/elf/SCUS_973.16', 'a/b.irx', 'x/y.s', 'build/a', 'tools/wibo'])
        self.assertEqual(len(flagged), 5)

    def test_source_files_are_not_flagged(self):
        self.assertEqual(check_cleanup.check_files(['src/mat/Foo.c', 'tools/README.md', 'docs/build/building.md', 'scripts/workflow.py']), [])

    def warnings_for(self, line):
        return check_cleanup.warn_lines({'src/mat/Foo.cpp': [(1, line)]})

    def test_warns_on_padding_member(self):
        self.assertEqual(len(self.warnings_for('struct SO { char pad0[0x58]; XF *pxf; };')), 1)

    def test_warns_on_cast_offset(self):
        self.assertEqual(len(self.warnings_for('    *(float *)(base + 0x1434) = g_2dded0;')), 1)

    def test_warns_on_hand_written_vtable_call(self):
        self.assertEqual(len(self.warnings_for('    vt->fn((char *)pobject + vt->delta, 6, 0, 0, 0, 0);')), 1)

    def test_warns_on_bare_long_outside_typedef(self):
        self.assertEqual(len(self.warnings_for('    long value = 0;')), 1)

    def test_typedef_of_long_is_not_warned(self):
        self.assertEqual(self.warnings_for('typedef long s64;'), [])

    def test_typed_member_access_is_not_warned(self):
        self.assertEqual(self.warnings_for('    pso->pxfLinear = pxf;'), [])

    def test_warnings_do_not_count_as_problems(self):
        self.assertEqual(check_cleanup.check_lines({'src/mat/Foo.cpp': [(1, '    long value = 0;')]}), [])


class AssemblyUnitTests(unittest.TestCase):
    CHUNK = ['.align 3\n', 'glabel func_00100000\n', '    /* 80 00100000 00000000 */  nop\n',
             '    /* 84 00100004 00000000 */  nop\n', '    /* 88 00100008 00000000 */  nop\n',
             '.size func_00100000, . - func_00100000\n']

    def test_split_adds_a_label_and_moves_the_size_with_its_label(self):
        pieces = asm_units.split_chunk(self.CHUNK, {0x100008})
        self.assertEqual(len(pieces), 2)
        self.assertIn('glabel func_00100008\n', pieces[1])
        self.assertFalse(any(line.startswith('.size') for line in pieces[1]))

    def test_no_split_at_the_start_of_a_chunk(self):
        self.assertEqual(len(asm_units.split_chunk(self.CHUNK, {0x100000})), 1)

    def test_split_keeps_an_existing_label(self):
        lines = self.CHUNK[:3] + ['  glabel inner\n'] + self.CHUNK[3:]
        pieces = asm_units.split_chunk(lines, {0x100004})
        self.assertEqual([line for line in pieces[1] if 'glabel' in line], ['  glabel inner\n'])


class WholeFileTests(unittest.TestCase):
    def test_whole_files_are_read_as_ranges(self):
        import tempfile
        with tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False) as handle:
            handle.write('start\tend\tfile\n0x116CA0\t0x117030\tmemory-bez/ary.cpp\n')
        self.addCleanup(os.remove, handle.name)
        self.assertEqual(asm_units.whole_files(handle.name), [(0x116CA0, 0x117030, 'memory-bez/ary.cpp')])

    def test_missing_list_means_no_whole_files(self):
        self.assertEqual(asm_units.whole_files('/nonexistent/whole_files.tsv'), [])

    def test_whole_file_bounds_are_split_points(self):
        self.assertTrue(all({start, end} <= asm_units.split_points() for start, end, _ in asm_units.whole_files()))


class MergeTests(unittest.TestCase):
    def test_chunk_inside_a_matched_function_is_folded_in(self):
        functions = [{'address': 0x100000, 'lines': ['a\n']}, {'address': 0x100050, 'lines': ['b\n']}, {'address': 0x100058, 'lines': ['c\n']}]
        merged = asm_units.merge_spans(functions, {0x100000: 0x58})
        self.assertEqual([(f['address'], f['lines']) for f in merged], [(0x100000, ['a\n', 'b\n']), (0x100058, ['c\n'])])

    def test_chunk_after_the_span_is_kept(self):
        functions = [{'address': 0x100000, 'lines': ['a\n']}, {'address': 0x100058, 'lines': ['c\n']}]
        self.assertEqual(len(asm_units.merge_spans(functions, {0x100000: 0x58})), 2)


class CategoryConfigTests(unittest.TestCase):
    ROOT = os.path.join(HERE, '..')

    def setUp(self):
        import csv
        import json
        with open(os.path.join(self.ROOT, 'config', 'us', 'categories.json')) as categories_file:
            self.config = json.load(categories_file)
        with open(os.path.join(self.ROOT, 'config', 'recovered', 'modules.tsv')) as modules_file:
            self.modules = {row['module'] for row in csv.DictReader(modules_file, delimiter='\t')}

    def test_every_sly1_file_has_a_subsystem(self):
        tokens = {token for module in self.modules if module != 'sdk' and not module.startswith('new_') for token in module.split('+')}
        missing = sorted(token for token in tokens - {'sdk'} if token not in self.config['files'])
        self.assertEqual(missing, [])

    def test_subsystems_are_defined_categories(self):
        ids = {category['id'] for category in self.config['categories']}
        used = set(self.config['files'].values()) | set(self.config.get('modules', {}).values())
        self.assertEqual(sorted(used - ids), [])

    def test_overrides_name_real_modules(self):
        self.assertEqual(sorted(set(self.config.get('modules', {})) - self.modules), [])


class NonMatchingTests(unittest.TestCase):
    def test_lowest_score_wins(self):
        self.assertEqual(export_nonmatching.choose([(9, 'a.c', 'c'), (3, 'b.cpp', 'c++')]), (3, 'b.cpp', 'c++'))

    def test_first_candidate_wins_a_tie(self):
        self.assertEqual(export_nonmatching.choose([(3, 'hand.cpp', 'c++'), (3, 'draft.c', 'c')])[1], 'hand.cpp')

    def test_sources_that_do_not_compile_are_skipped(self):
        self.assertEqual(export_nonmatching.choose([(None, 'a.c', 'c'), (12, 'b.c', 'c')])[1], 'b.c')
        self.assertIsNone(export_nonmatching.choose([(None, 'a.c', 'c')]))

    def test_names_become_file_names(self):
        self.assertEqual(export_nonmatching.file_name('func_001B2940'), 'fun_001b2940')
        self.assertEqual(export_nonmatching.file_name('Foo::Bar'), 'Foo__Bar')


class CompileUnitTests(unittest.TestCase):
    def test_extern_lines_move_to_the_top(self):
        text = '\t.file 1 "a.c"\nfoo:\n\tlui $2,%hi(g)\n\t.extern g,4\n\t.extern h,8'
        lines = compile_unit.hoist_externs(text).split('\n')
        self.assertEqual(lines[:2], ['\t.extern g,4', '\t.extern h,8'])
        self.assertEqual(len(lines), 5)

    def test_text_without_externs_is_unchanged(self):
        self.assertEqual(compile_unit.hoist_externs('a\nb'), 'a\nb')

    SPLAT = ['.align 3\n', 'glabel func_00100000\n', '    /* 80 00100000 3000BD27 */  addiu      $sp, $sp, 0x30\n',
             '  .L00100004:\n', '    /* 84 00100004 00000000 */  nop\n', '.size func_00100000, . - func_00100000\n']

    def test_include_asm_marker_becomes_the_splat_function(self):
        expanded = compile_unit.expand_include_asm('foo:\n\t.include_asm 0x100000\nbar:', {0x100000: self.SPLAT}).split('\n')
        self.assertEqual(expanded[expanded.index('func_00100000:') + 1], '\taddiu      $sp, $sp, 0x30')

    def test_included_assembly_keeps_its_delay_slots(self):
        expanded = compile_unit.expand_include_asm('\t.include_asm 0x100000', {0x100000: self.SPLAT}).split('\n')
        self.assertEqual((expanded[0], expanded[-1]), ('\t.set\tnoreorder', '\t.set\treorder'))

    def test_included_assembly_drops_comments_and_sizes(self):
        expanded = compile_unit.expand_include_asm('\t.include_asm 0x100000', {0x100000: self.SPLAT})
        self.assertFalse(any(token in expanded for token in ('/*', '.size')))

    def test_included_local_label_stays_a_label(self):
        self.assertIn('\n.L00100004:\n', compile_unit.expand_include_asm('\t.include_asm 0x100000', {0x100000: self.SPLAT}))

    def test_include_asm_of_an_unknown_address_raises(self):
        with self.assertRaises(KeyError):
            compile_unit.expand_include_asm('\t.include_asm 0x100008', {0x100000: self.SPLAT})

    def test_assembly_without_marker_is_unchanged(self):
        self.assertEqual(compile_unit.expand_include_asm('a\nb', {}), 'a\nb')

    def test_vadda_is_written_as_its_word(self):
        lines = ['glabel f\n', '    /* 80 00100000 BC12E04B */  vadda.xyzw $ACC, $vf0, $vf2\n']
        self.assertIn('\t.word\t0x4be012bc', compile_unit.splat_for_ps2eeas(lines).split('\n'))

    def test_c1_is_written_as_its_word(self):
        lines = ['glabel f\n', '    /* 80 00100000 44030046 */  c1         0x344\n']
        self.assertIn('\t.word\t0x46000344', compile_unit.splat_for_ps2eeas(lines).split('\n'))


class MakeWholeFilesTests(unittest.TestCase):
    MANIFEST = {0x100000: ('First', 8, 'module/First.cpp'), 0x100010: ('Second', 8, 'module/Second.cpp'),
                0x100020: ('Third', 8, 'module/Third.c')}

    def build(self, sources, functions=(0x100000, 0x100008, 0x100010), language=None):
        return make_whole_files.build_whole_file(0x100000, 0x100030, list(functions), self.MANIFEST, read_source=sources.__getitem__, language=language)

    def test_items_split_at_top_level(self):
        items = make_whole_files.split_items('#include "a.h"\nstruct S { int a; };\nint f(S *s) { return s->a; }\nextern int g;\n')
        self.assertEqual([make_whole_files.classify(item) for item in items],
                         [('preprocessor', '#include "a.h"'), ('type', 'S'), ('function', 'f'), ('declaration', 'g')])

    def test_semicolon_in_a_comment_does_not_end_an_item(self):
        self.assertEqual(len(make_whole_files.split_items('/* a; b */ extern int g;\n')), 1)

    def test_rename_skips_comments_and_longer_names(self):
        self.assertEqual(make_whole_files.rename('VT *x; /* VT */ VTable y;', 'VT', 'VT_1'), 'VT_1 *x; /* VT */ VTable y;')

    def test_unmatched_function_becomes_include_asm(self):
        _, text, _ = self.build({'module/First.cpp': 'void First() {}\n', 'module/Second.cpp': 'void Second() {}\n'})
        self.assertLess(text.index('void First'), text.index('INCLUDE_ASM(0X100008);'))

    def test_include_asm_header_is_added(self):
        _, text, _ = self.build({'module/First.cpp': 'void First() {}\n', 'module/Second.cpp': 'void Second() {}\n'})
        self.assertIn('#include "include_asm.h"', text)

    def test_identical_declaration_is_kept_once(self):
        _, text, _ = self.build({'module/First.cpp': 'extern int g;\nvoid First() { g = 1; }\n', 'module/Second.cpp': 'extern int g;\nvoid Second() { g = 2; }\n'})
        self.assertEqual(text.count('extern int g;'), 1)

    def test_differing_struct_takes_the_address_suffix(self):
        _, text, notes = self.build({'module/First.cpp': 'struct S { int a; };\nvoid First(S *s) {}\n', 'module/Second.cpp': 'struct S { char b; };\nvoid Second(S *s) {}\n'})
        self.assertIn('void Second(S_100010 *s)', text)

    def test_includes_go_to_the_top_once(self):
        _, text, _ = self.build({'module/First.cpp': '#include "sly2.h"\nvoid First() {}\n', 'module/Second.cpp': '#include "sly2.h"\nvoid Second() {}\n'})
        self.assertEqual(text.count('#include "sly2.h"'), 1)

    def test_c_source_in_a_cpp_file_keeps_c_linkage(self):
        sources = {'module/First.cpp': 'void First() {}\n', 'module/Third.c': 'void Third() {}\n'}
        _, text, _ = self.build(sources, functions=(0x100000, 0x100020))
        self.assertIn('extern "C" {\nvoid Third() {}\n}', text)

    def test_all_c_sources_make_a_c_file(self):
        language, _, _ = self.build({'module/Third.c': 'void Third() {}\n'}, functions=(0x100020,))
        self.assertEqual(language, 'c')

    def test_c_file_spells_linkage_as_c(self):
        self.assertEqual(make_whole_files.to_c('extern "C" int f(void);'), 'extern int f(void);')

    def test_m2c_unk_becomes_s32(self):
        self.assertEqual(make_whole_files.clean_text('M2C_UNK f(M2C_UNK *a);\n'), 's32 f(s32 *a);\n')

    def test_resolve_drops_the_later_conflicting_declaration(self):
        text = 'extern int g;\nextern char g;\nvoid f() {}\n'
        def compile_source(source, language):
            if 'extern char g;' in source:
                return False, 'x.cpp:2: conflicting types for `char g\'\nx.cpp:1: previous declaration as `int g\''
            return True, ''
        resolved, notes, error = make_whole_files.resolve(text, 'c++', compile_source)
        self.assertEqual((make_whole_files.tidy(resolved), error), ('extern int g;\n\nvoid f() {}\n', None))

    def test_resolve_stops_on_another_error(self):
        _, _, error = make_whole_files.resolve('void f() { x; }\n', 'c++', lambda source, language: (False, 'x.cpp:1: `x\' undeclared'))
        self.assertIn('undeclared', error)

    def test_only_the_sony_list_picks_another_assembler(self):
        self.assertIsNone(compile_unit.assembler_for(0xDEADBEEF))

    def test_sony_list_wins_over_every_other_list(self):
        listed = compile_unit.sony_functions()
        self.assertTrue(all(isinstance(address, int) for address in listed))
        if listed:
            self.assertEqual(compile_unit.assembler_for(next(iter(listed))), 'sony29')



class WholeFileRecordTests(unittest.TestCase):
    """The whole file as the only record of its functions: landing one (make_whole_files.insert_function, land), cutting one out of the
    whole object (cut_function), and the src/MANIFEST.tsv rows of export_src.py. Synthetic sources and objects only."""
    WHOLE = ('// SPDX-License-Identifier: GPL-3.0-or-later\n#include "sly2.h"\n#include "include_asm.h"\n\n'
             'struct S { int a; };\n\nvoid First(S *s) { s->a = 1; }\n\nINCLUDE_ASM(0x100010); // a comment\n\nINCLUDE_ASM(0X100020);\n')

    def test_marker_matches_any_spelling_of_the_address(self):
        marker = make_whole_files.include_asm_marker(0x100010)
        self.assertTrue(all(marker.search(text) for text in ('INCLUDE_ASM(0x100010);\n', 'INCLUDE_ASM(0X00100010); // x\n', 'INCLUDE_ASM(0x10001a);'.replace('a', '0'))))

    def test_marker_does_not_match_another_address(self):
        self.assertIsNone(make_whole_files.include_asm_marker(0x100010).search('INCLUDE_ASM(0x1000100);\n'))

    def test_whole_file_of_finds_the_range(self):
        self.assertEqual(make_whole_files.whole_file_of(0x100018, [(0x100000, 0x100030, 'm/a.cpp')]), (0x100000, 0x100030, 'm/a.cpp'))
        self.assertIsNone(make_whole_files.whole_file_of(0x100030, [(0x100000, 0x100030, 'm/a.cpp')]))

    def insert(self, source, address=0x100010, source_is_c=False, whole=None):
        return make_whole_files.insert_function(whole or self.WHOLE, address, source, source_is_c, 'c++')

    def test_landing_replaces_the_include_asm_line(self):
        text, _ = self.insert('void Second() {}\n')
        self.assertNotIn('0x100010', text)
        self.assertLess(text.index('void Second() {}'), text.index('INCLUDE_ASM(0X100020);'))

    def test_landing_drops_an_item_written_before(self):
        text, _ = self.insert('struct S { int a; };\nvoid Second(S *s) { s->a = 2; }\n')
        self.assertEqual(text.count('struct S {'), 1)

    def test_landing_renames_a_struct_defined_differently(self):
        text, notes = self.insert('struct S { char b; };\nvoid Second(S *s) { s->b = 2; }\n')
        self.assertIn('void Second(S_100010 *s)', text)

    def test_landing_adds_a_new_include_after_the_others(self):
        text, _ = self.insert('#include "m2c_macros.h"\nvoid Second() {}\n')
        self.assertIn('#include "include_asm.h"\n#include "m2c_macros.h"\n', text)

    def test_landing_keeps_c_linkage_of_a_c_source(self):
        text, _ = self.insert('void Second() {}\n', source_is_c=True)
        self.assertIn('extern "C" {\nvoid Second() {}\n}', text)

    def test_landing_the_last_include_asm_drops_its_header(self):
        whole = self.WHOLE.replace('\nINCLUDE_ASM(0X100020);\n', '')
        text, _ = self.insert('void Second() {}\n', whole=whole)
        self.assertNotIn('include_asm.h', text)

    def test_landing_without_the_line_raises(self):
        with self.assertRaises(ValueError):
            self.insert('void Second() {}\n', address=0x100018)

    def land(self, prove_result):
        import tempfile
        folder = tempfile.mkdtemp()
        self.addCleanup(__import__('shutil').rmtree, folder)
        os.makedirs(os.path.join(folder, 'src', 'm'))
        whole_path, source = os.path.join(folder, 'src', 'm', 'a.cpp'), os.path.join(folder, '100010.cpp')
        open(whole_path, 'w').write(self.WHOLE)
        open(source, 'w').write('void Second() {}\n')
        old = make_whole_files.ROOT
        make_whole_files.ROOT = folder
        try:
            result = make_whole_files.land(0x100010, source, [(0x100000, 0x100030, 'm/a.cpp')],
                                           compile_source=lambda text, language: (True, ''), prove=lambda: prove_result)
        finally:
            make_whole_files.ROOT = old
        return result, open(whole_path).read()

    def test_land_writes_the_file_when_the_range_proves(self):
        (ok, _, _), text = self.land(None)
        self.assertTrue(ok and 'void Second() {}' in text)

    def test_land_leaves_the_file_when_the_range_differs(self):
        (ok, message, _), text = self.land('bytes differ at 0X100014')
        self.assertEqual((ok, text), (False, self.WHOLE))
        self.assertIn('bytes differ', message)

    def whole_object(self):
        import tempfile
        folder = tempfile.mkdtemp()
        self.addCleanup(__import__('shutil').rmtree, folder)
        path = os.path.join(folder, 'whole.o')
        # three functions of 16 bytes; the second calls the third and an undefined name
        symbols = [('', 0, 0, 3), ('gcc2_compiled.', 0, 0, 0), ('Alpha', 0x0, 16, 2), ('Beta', 0x10, 16, 2), ('Gamma', 0x20, 16, 2), ('ext', 0, 0, 0x10)]
        code = b''.join(value.to_bytes(4, 'little') for value in range(1, 13))
        make_whole_files.write_object(path, code, symbols, 5, [(0x14, 5, 4), (0x18, 6, 4), (0x24, 6, 4)])
        return folder, path

    def test_function_symbols_leave_out_the_compiler_marker(self):
        _, path = self.whole_object()
        self.assertEqual(make_whole_files.function_symbols(path), {0x0: 'Alpha', 0x10: 'Beta', 0x20: 'Gamma'})

    def test_cut_keeps_only_the_function(self):
        from elftools.elf.elffile import ELFFile
        folder, path = self.whole_object()
        cut, _ = make_whole_files.cut_function(path, 0x10, os.path.join(folder, 'cut.o'))
        with open(cut, 'rb') as handle:
            self.assertEqual(ELFFile(handle).get_section_by_name('.text').data(), b''.join(value.to_bytes(4, 'little') for value in range(5, 9)))

    def test_cut_moves_the_relocations_to_the_function(self):
        from elftools.elf.elffile import ELFFile
        folder, path = self.whole_object()
        cut, _ = make_whole_files.cut_function(path, 0x10, os.path.join(folder, 'cut.o'))
        with open(cut, 'rb') as handle:
            elf = ELFFile(handle)
            symbols = elf.get_section_by_name('.symtab')
            found = [(relocation['r_offset'], symbols.get_symbol(relocation['r_info_sym']).name) for relocation in elf.get_section_by_name('.rel.text').iter_relocations()]
        self.assertEqual(found, [(0x4, 'Gamma'), (0x8, 'ext')])

    def test_cut_makes_a_called_function_of_the_file_an_undefined_name_with_its_offset(self):
        folder, path = self.whole_object()
        _, outside = make_whole_files.cut_function(path, 0x10, os.path.join(folder, 'cut.o'))
        self.assertEqual(outside, {'Gamma': 0x20})

    def test_cut_at_no_function_raises(self):
        folder, path = self.whole_object()
        with self.assertRaises(ValueError):
            make_whole_files.cut_function(path, 0x8, os.path.join(folder, 'cut.o'))

    REGISTRY = [{'address': '0x100000', 'name': 'First', 'size': '8', 'status': 'matched', 'source': 'fn/100000.cpp'},
                {'address': '0x100010', 'name': 'Second', 'size': '8', 'status': 'matched', 'source': 'fn/100010.cpp'},
                {'address': '0x200000', 'name': 'func_00200000', 'size': '8', 'status': 'matched', 'source': 'fn/200000.c'},
                {'address': '0x200010', 'name': 'Other', 'size': '8', 'status': 'tried', 'source': ''}]
    SOURCES = {'fn/100000.cpp': 'struct S;\nvoid First(S *s) {}\n', 'fn/100010.cpp': 'void Second() {}\n', 'fn/200000.c': 'void f(void) {}\n'}

    def rows(self, whole_text):
        return export_src.manifest_rows(self.REGISTRY, {0x200000: 'mod'}, [(0x100000, 0x100030, 'm/a.cpp')], {'m/a.cpp': whole_text},
                                        read_source=self.SOURCES.get)

    def test_a_function_inside_a_whole_file_is_recorded_by_the_file(self):
        rows, _, _ = self.rows('void First() {}\nvoid Second() {}\n')
        self.assertEqual([(row['file'], row['whole_file'], row['symbol']) for row in rows if row['address'] == '0X100000'], [('m/a.cpp', 'm/a.cpp', 'First')])

    def test_a_function_inside_a_whole_file_gets_no_copy(self):
        _, copies, _ = self.rows('void First() {}\nvoid Second() {}\n')
        self.assertEqual(copies, [('fn/200000.c', 'mod/fun_00200000.c')])

    def test_a_function_outside_whole_files_keeps_its_row(self):
        rows, _, _ = self.rows('')
        self.assertIn({'address': '0X200000', 'name': 'func_00200000', 'size': '8', 'file': 'mod/fun_00200000.c', 'whole_file': '', 'symbol': ''}, rows)

    def test_a_match_its_whole_file_still_includes_from_assembly_is_not_published(self):
        rows, _, unlanded = self.rows('void First() {}\nINCLUDE_ASM(0x100010);\n')
        self.assertEqual(([row['address'] for row in unlanded], '0X100010' in [row['address'] for row in rows]), (['0x100010'], False))

    def test_names_that_differ_only_in_case_do_not_share_a_file(self):
        registry = [{'address': '0x200000', 'name': 'Foo', 'size': '8', 'status': 'matched', 'source': 'a.c'},
                    {'address': '0x200008', 'name': 'foo', 'size': '8', 'status': 'matched', 'source': 'b.c'}]
        _, copies, _ = export_src.manifest_rows(registry, {}, [], {}, read_source=lambda path: None)
        self.assertEqual([destination for _, destination in copies], ['unsorted/Foo.c', 'unsorted/foo_200008.c'])

    def test_source_symbol_prefers_the_registry_name(self):
        self.assertEqual(export_src.source_symbol('static int helper() { return 1; }\nint Name__Fi(int a) { return a; }\nint Name() { return 0; }\n', 'Name'), 'Name')

    def test_source_symbol_falls_back_to_the_last_definition(self):
        self.assertEqual(export_src.source_symbol('int Helper() { return 1; }\nint Real() { return 0; }\n', 'func_00100000'), 'Real')

    def test_check_unit_reads_the_first_four_manifest_columns(self):
        import tempfile
        with tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False) as handle:
            handle.write('address\tname\tsize\tfile\twhole_file\tsymbol\n0X100000\tFirst\t8\tm/a.cpp\tm/a.cpp\tFirst\n')
        self.addCleanup(os.remove, handle.name)
        self.assertEqual(check_unit.rows(handle.name, 4), [['0X100000', 'First', '8', 'm/a.cpp']])


class PermuteMarkedTests(unittest.TestCase):
    def test_all_orders_up_to_five(self):
        self.assertEqual(len(permute.sampled_orders(3, 10)), 5)

    def test_sample_is_distinct_and_seeded(self):
        first = permute.sampled_orders(7, 10)
        self.assertEqual(len(set(first)), 10)
        self.assertEqual(first, permute.sampled_orders(7, 10))

    def test_neighbours_are_distinct_and_exclude_the_order(self):
        around = permute.neighbours((0, 1, 2, 3))
        self.assertEqual(len(around), len(set(around)))
        self.assertNotIn((0, 1, 2, 3), around)
        self.assertIn((1, 0, 2, 3), around)
        self.assertIn((1, 2, 3, 0), around)

    def test_climb_finds_a_reversed_order_one_step_at_a_time(self):
        target = (3, 1, 4, 0, 2, 5, 6)
        statements = [str(index) for index in range(7)]
        lines = ['x'] * 7
        slots = list(range(7))
        original = permute.judge
        permute.judge = lambda address, text, lang: sum(1 for position, value in enumerate(text.split('\n')) if int(value) != target[position]) if text != 'x' else 99
        try:
            score, order, used = permute.climb('0x0', lines, slots, statements, tuple(range(7)), 7, 2000, 2, 'c++')
        finally:
            permute.judge = original
        self.assertEqual((score, order), (0, target))
        self.assertGreater(used, 0)

    def test_marker_needs_the_trailing_comment(self):
        self.assertTrue(permute.MARK.search('    x->a = 1; //P'))
        self.assertFalse(permute.MARK.search('    x->a = 1; // P in the middle //P later'))
        self.assertFalse(permute.MARK.search('    x->a = 1;'))



class RulesTests(unittest.TestCase):
    def labels(self, source):
        return [label for label, _ in rules.edits(source).values()]

    def test_early_return_split_gives_each_arm_its_own_return(self):
        source = ('int Read(S *stream)\n{\n    int result;\n    int remaining = stream->remaining;\n    if (remaining < 2) {\n        Fill(stream);\n'
                  '        result = stream->value;\n    } else {\n        result = stream->cursor[0];\n        stream->remaining = remaining - 2;\n    }\n    return result;\n}\n')
        edited = dict((label, text) for text, (label, _) in rules.edits(source).items())
        then_first, else_first = edited['early_return_split then-first'], edited['early_return_split else-first']
        self.assertNotIn('    int result;\n', then_first)
        self.assertIn('return stream->value;', then_first)
        self.assertIn('int result = stream->cursor[0];', then_first)
        self.assertIn('if (remaining >= 2) {', else_first)

    def test_scalar_buffer_becomes_a_scalar_and_its_address(self):
        edited = list(rules.scalar_buffer('void f()\n{\n    short value[16 / sizeof(short)] __attribute__((aligned(16)));\n    Read(2, value);\n    use(value[0]);\n}\n'))
        self.assertEqual(len(edited), 1)
        self.assertIn('    short value;\n', edited[0][1])
        self.assertIn('Read(2, &value);', edited[0][1])
        self.assertIn('use(value);', edited[0][1])

    def test_chained_store_joins_stores_of_one_constant(self):
        edited = [text for _, text in rules.chained_store('void f(G *g)\n{\n    g->a = -1.0f;\n    g->b = 0;\n    g->c = -1.0f;\n}\n')]
        self.assertTrue(any('g->a = g->c = -1.0f;' in text and 'g->c = -1.0f;\n}' not in text for text in edited))
        self.assertTrue(any('g->c = g->a = -1.0f;' in text for text in edited))

    def test_index_first_rewrites_an_address_of_an_element(self):
        edited = rules.edits('void f(int i) { g(&table[i]); }')
        self.assertTrue(any('(unsigned)(table)' in text and '(i) * sizeof' in text for text in edited))

    def test_constify_marks_a_read_only_symbol(self):
        edited = list(rules.constify('extern float RO_002A1000;\nextern int D_00001234;\n'))
        self.assertEqual(edited[0][1], 'extern const float RO_002A1000;\nextern int D_00001234;\n')

    def test_constify_leaves_a_const_symbol(self):
        self.assertEqual(list(rules.constify('extern const float RO_002A1000;\n')), [])

    def test_long_long_becomes_long(self):
        self.assertEqual(list(rules.long_long('long long x;'))[0][1], 'long x;')

    def test_call_arguments_drops_appends_and_keeps_declaration_and_calls_in_step(self):
        source = 'extern "C" void Callee(int a);\nvoid F(int one, int two) {\n    Callee(one);\n}\n'
        edited = rules.edits(source)
        appended = [text for text in edited if 'void Callee(int a, int)' in text and 'Callee(one, two)' in text]
        dropped = [text for text in edited if 'void Callee(void)' in text and 'Callee()' in text]
        self.assertTrue(appended)
        self.assertTrue(dropped)

    def test_missing_parameter_inserts_a_dummy_at_a_skipped_register(self):
        edited = list(rules.missing_parameter('int F(int arg0, int arg1, int arg3) {\n    return arg3;\n}\n'))
        self.assertEqual(edited[0][1], 'int F(int arg0, int arg1, int unused_arg2, int arg3) {\n    return arg3;\n}\n')

    def test_missing_parameter_adds_a_leading_dummy_for_a_first_parameter_arg1(self):
        edited = list(rules.missing_parameter('void F(int arg1) {\n}\n'))
        self.assertEqual(edited[0][1], 'void F(int unused_arg0, int arg1) {\n}\n')

    def test_missing_parameter_leaves_a_complete_or_float_signature(self):
        self.assertEqual(list(rules.missing_parameter('void F(int arg0, int arg1) {\n}\n')), [])
        self.assertEqual(list(rules.missing_parameter('void F(float arg0, int arg2) {\n}\n')), [])

    def test_vcall_object_drops_the_trailing_object_argument(self):
        source = ('struct VT { char pad[4]; short delta; short unused; void (*fn)(void *, int, void *); };\n'
                  'struct Obj { char pad[12]; VT *vt; };\n'
                  'void F(Obj *obj) {\n    obj->vt->fn((char *)obj + obj->vt->delta, 5, obj);\n}\n')
        edited = list(rules.vcall_object(source))
        self.assertEqual(len(edited), 1)
        self.assertIn('void (*fn)(void *, int);', edited[0][1])
        self.assertIn('obj->vt->fn((char *)obj + obj->vt->delta, 5);', edited[0][1])

    def test_vcall_object_leaves_a_call_whose_last_argument_is_not_the_object(self):
        source = ('struct VT { void (*fn)(void *, int, void *); };\nvoid F(VT *vt, char *p, char *q) {\n    vt->fn(p, 5, q);\n}\n')
        self.assertEqual(list(rules.vcall_object(source)), [])

    def test_global_array_declares_the_global_as_an_array_and_reads_its_first_element(self):
        edited = list(rules.global_array('extern float g_2dded0;\nfloat F(void) {\n    return g_2dded0 + 1.0f;\n}\n'))
        self.assertEqual(edited[0][1], 'extern float g_2dded0[];\nfloat F(void) {\n    return g_2dded0[0] + 1.0f;\n}\n')

    def test_float_position_moves_a_float_parameter_in_declaration_and_calls(self):
        source = 'extern "C" void Callee(int a, float b, int c);\nvoid F(int x, int y) {\n    Callee(x, 1.0f, y);\n}\n'
        edited = rules.edits(source)
        self.assertTrue(any('Callee(float b, int a, int c)' in text and 'Callee(1.0f, x, y)' in text for text in edited))

    def test_index_loop_rebuilds_the_indexed_loop(self):
        source = ('void F(int *arr, int n) {\n    int i;\n    int *p;\n    i = 0;\n    if (n > 0) {\n        p = arr;\n        do {\n'
                  '            *p = i;\n            i += 1;\n            p += 4;\n        } while (i < n);\n    }\n}\n')
        edited = list(rules.index_loop(source))
        self.assertEqual(len(edited), 1)
        self.assertIn('for (i = 0; i < n; i++)', edited[0][1])
        self.assertIn('p = arr + i * 4;', edited[0][1])
        self.assertNotIn('do {', edited[0][1])

    def test_by_value_returns_the_class_instead_of_the_pointer(self):
        source = 'struct CRef { int a; };\nCRef *Op(CRef *pret, int x) {\n    pret->a = x;\n    return pret;\n}\n'
        edited = list(rules.by_value(source))[0][1]
        self.assertIn('CRef Op(int x) return __ret', edited)
        self.assertIn('__ret.a = x;', edited)
        self.assertIn('~CRef();', edited)

    def test_a_source_without_a_shape_gives_no_edit_and_no_error(self):
        self.assertEqual(rules.edits('int main() { return 0; }'), {})


class RecordScanTests(unittest.TestCase):
    def test_a_volatile_on_ordinary_data_is_flagged(self):
        found = record.scan('extern volatile int g_2deb20;\nint f(void) { return g_2deb20; }\n')
        self.assertEqual([what for _, what, _ in found], ['volatile'])

    def test_a_volatile_with_a_reason_marker_is_allowed(self):
        source = 'struct S { volatile int id; };  // volatile-ok: set by the alarm handler 0x239F28\n'
        self.assertEqual(record.scan(source), [])

    def test_a_volatile_marker_without_a_reason_is_flagged(self):
        found = record.scan('struct S { volatile int id; };  // volatile-ok:\n')
        self.assertEqual([what for _, what, _ in found], ['volatile'])

    def test_a_volatile_pointer_to_a_hardware_register_is_allowed(self):
        self.assertEqual(record.scan('void f(void) { *(volatile unsigned *)0x1000E010 = 1; }\n'), [])

    def test_a_register_pin_and_an_empty_asm_are_flagged(self):
        pin = record.scan('void f(void) { register int x asm("$6"); }\n')
        empty = record.scan('void f(void) { asm volatile("" : "+r"(x)); }\n')
        self.assertEqual([what for _, what, _ in pin], ['register pin'])
        self.assertEqual([what for _, what, _ in empty], ['inline asm'])

    def test_vu_and_lane_move_asm_are_flagged(self):
        vu = record.scan('void f(void) { asm volatile("lqc2 vf1, 0(%0)" : : "r"(p)); }\n')
        lane = record.scan('void f(void) { asm("mfc1 %0, %1" : "=r"(r) : "f"(x)); }\n')
        self.assertEqual([what for _, what, _ in vu], ['inline asm'])
        self.assertEqual([what for _, what, _ in lane], ['inline asm'])

    def test_the_shared_sqrt_helper_is_allowed(self):
        self.assertEqual(record.scan('float Sqrt(float x) {\n    float r;\n    asm volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x));\n    return r;\n}\n'), [])

    def test_an_asm_label_and_comments_are_not_flagged(self):
        self.assertEqual(record.scan('struct C { C(const C &) asm("C_Copy"); };\n'), [])
        self.assertEqual(record.scan('// a volatile flag would be wrong here\nint x;\n'), [])


class ClaimTests(unittest.TestCase):
    def setUp(self):
        import tempfile
        self.directory = tempfile.mkdtemp()
        self.saved = (claim.LAB, claim.WAVES, claim.RUNS_LOG, claim.fingerprint, claim.fragment_reason, classify_blockers.TABLE)
        claim.LAB = self.directory
        claim.WAVES = os.path.join(self.directory, 'waves')
        claim.RUNS_LOG = os.path.join(self.directory, 'runs.log')
        claim.fingerprint = lambda: 'now'
        claim.fragment_reason = lambda name: None
        classify_blockers.TABLE = os.path.join(self.directory, 'blockers.tsv')

    def tearDown(self):
        import shutil
        claim.LAB, claim.WAVES, claim.RUNS_LOG, claim.fingerprint, claim.fragment_reason, classify_blockers.TABLE = self.saved
        shutil.rmtree(self.directory)

    def write(self, name, text):
        path = os.path.join(self.directory, name)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, 'w') as handle:
            handle.write(text)

    def test_a_run_from_another_toolchain_is_ignored(self):
        self.write('runs.log', '1\tW1-a\t100000\t0\tdigest\tkept/a.cpp\told\n2\tW1-a\t100000\t5\tdigest\tkept/b.cpp\tnow\n')
        self.assertEqual(claim.runs('W1'), {0x100000: [('W1-a', 5, 'kept/b.cpp')]})

    def test_a_run_with_no_fingerprint_is_ignored(self):
        self.write('runs.log', '1\tW1-a\t100000\t0\tdigest\tkept/a.cpp\n')
        self.assertEqual(claim.runs('W1'), {})

    def test_the_queue_comes_from_the_registry_and_skips_blockers(self):
        header = 'address\tname\tsize\tstatus\tbest\ttries\tsource\tname_source\toption_name\n'
        rows = ['0x100000\tnear_miss\t64\ttried\t2\t1\t\t\t\n', '0x100100\tno_source\t64\ttried\t1\t1\t\t\t\n',
                '0x100200\tblocked\t64\ttried\t1\t1\t\t\t\n', '0x100300\tfar\t64\ttried\t9\t1\t\t\t\n', '0x100400\tdone\t64\tmatched\t0\t1\t\t\t\n']
        self.write('data/matching/functions.tsv', header + ''.join(rows))
        for address in ('100000', '100200', '100300', '100400'):
            self.write(f'data/matching/src/fn/{address}.cpp', 'int f();\n')
        self.write('blockers.tsv', 'address\tname\tsize\tkind\n0X100200\tblocked\t64\tvu\n')
        import argparse
        claim.init(argparse.Namespace(wave='T', addresses=None, near=2, min_score=1, min_size=0, max_size=1 << 30, budget=10))
        with open(os.path.join(claim.WAVES, 'T', 'wave.json')) as handle:
            self.assertEqual(json.load(handle)['queue'], [0x100000])


    def wave(self, queue, claims):
        os.makedirs(os.path.join(claim.WAVES, 'T'), exist_ok=True)
        with open(claim.state_path('T'), 'w') as handle:
            json.dump({'queue': queue, 'claims': claims, 'budget': 10}, handle)

    def test_done_refuses_a_worker_that_claimed_less_than_n_while_functions_are_free(self):
        import argparse
        self.wave([1, 2, 3], {'000001': 'k01'})
        self.assertEqual(claim.done(argparse.Namespace(wave='T', worker='k01', count=3)), 1)

    def test_done_accepts_a_worker_that_claimed_n(self):
        import argparse
        self.wave([1, 2, 3], {'000001': 'k01', '000002': 'k01', '000003': 'k02'})
        self.assertEqual(claim.done(argparse.Namespace(wave='T', worker='k01', count=2)), 0)

    def test_done_accepts_a_worker_when_the_queue_is_empty(self):
        import argparse
        self.wave([1, 2], {'000001': 'k01', '000002': 'k02'})
        self.assertEqual(claim.done(argparse.Namespace(wave='T', worker='k01', count=5)), 0)

    def test_among_equal_scores_the_best_run_is_the_clean_and_latest_one(self):
        self.write('kept/first.cpp', 'int f(char *p) { return M2C_FIELD(p, int *, 4); }\n')
        self.write('kept/second.cpp', 'struct A { int x; int y; };\nint f(A *p) { return p->y; }\n')
        self.write('kept/third.cpp', 'int f(char *p) { return M2C_FIELD(p, int *, 8); }\n')
        self.write('runs.log', '1\tW1-a\t100000\t0\td1\tkept/first.cpp\tnow\n2\tW1-a\t100000\t0\td2\tkept/second.cpp\tnow\n3\tW1-a\t100000\t0\td3\tkept/third.cpp\tnow\n')
        self.assertEqual(claim.best_runs('W1')[0x100000][2], 'kept/second.cpp')

    def test_among_equal_clean_scores_the_latest_run_wins(self):
        self.write('kept/first.cpp', 'int f(int *p) { return p[1]; }\n')
        self.write('kept/second.cpp', 'int f(int *p) { return *(p + 1); }\n')
        self.write('runs.log', '1\tW1-a\t100000\t0\td1\tkept/first.cpp\tnow\n2\tW1-a\t100000\t0\td2\tkept/second.cpp\tnow\n')
        self.assertEqual(claim.best_runs('W1')[0x100000][2], 'kept/second.cpp')

    def kept(self, name, text):
        self.write(name, text)
        return name

    def test_verify_marks_a_clean_zero_as_land_a_dirty_zero_as_park_and_a_changed_score_as_a_mismatch(self):
        import io
        import contextlib
        import scorer
        self.write('data/matching/functions.tsv', 'address\tname\tsize\tstatus\tbest\ttries\tsource\tname_source\toption_name\n'
                   '0x100000\tclean\t64\ttried\t3\t1\t\t\t\n0x100100\tdirty\t64\ttried\t3\t1\t\t\t\n0x100200\tdrift\t64\ttried\t3\t1\t\t\t\n0x100300\tnear\t64\ttried\t3\t1\t\t\t\n')
        clean = self.kept('kept/a.cpp', 'struct A { int x; };\nint f(A *p) { return p->x; }\n')
        dirty = self.kept('kept/b.cpp', 'int f(char *p) { return M2C_FIELD(p, int *, 4); }\n')
        drift = self.kept('kept/c.cpp', 'int f() { return 1; }\n')
        near = self.kept('kept/d.cpp', 'int f() { return 2; }\n')
        self.write('runs.log', f'1\tW1-a\t100000\t0\td1\t{clean}\tnow\n2\tW1-a\t100100\t0\td2\t{dirty}\tnow\n'
                   f'3\tW1-a\t100200\t0\td3\t{drift}\tnow\n4\tW1-a\t100300\t4\td4\t{near}\tnow\n')
        fresh = {'return 1;': 'score 5  (x)', 'return 2;': 'score 4  (x)'}
        saved = (scorer.report, scorer.registry)
        scorer.registry = lambda: None
        scorer.report = lambda address, text, lang='c++': next((v for k, v in fresh.items() if k in text), 'score 0  (x)')
        out, err = io.StringIO(), io.StringIO()
        try:
            with contextlib.redirect_stdout(out), contextlib.redirect_stderr(err):
                status = claim.verify(__import__('argparse').Namespace(wave='W1'))
        finally:
            scorer.report, scorer.registry = saved
        rows = {line.split('\t')[0]: line.split('\t')[3] for line in out.getvalue().strip().split('\n')}
        self.assertEqual((rows['0x100000'], rows['0x100200'], rows['0x100300'], status), ('LAND', 'MISMATCH logged 0, fresh 5', 'NEAR 4', 1))
        self.assertTrue(rows['0x100100'].startswith('PARK'))

    def test_land_refuses_when_logged_runs_are_ignored(self):
        import argparse
        import io
        import contextlib
        self.write('runs.log', '1\tW1-a\t100000\t0\td1\tkept/a.cpp\told\n')
        os.makedirs(os.path.join(claim.WAVES, 'W1'), exist_ok=True)
        with contextlib.redirect_stderr(io.StringIO()):
            status = claim.land(argparse.Namespace(wave='W1', reject=[], allow_ignored=False))
        self.assertEqual(status, 2)

    def test_runs_counts_the_runs_it_ignores(self):
        self.write('runs.log', '1\tW1-a\t100000\t0\tdigest\tkept/a.cpp\told\n2\tW1-a\t100000\t5\tdigest\tkept/b.cpp\tnow\n3\tW2-a\t100000\t0\td\tk\told\n')
        claim.runs('W1')
        self.assertEqual(claim.IGNORED['W1'], 1)


class RecordOnlyTests(unittest.TestCase):
    def test_only_keeps_the_sources_of_the_listed_addresses(self):
        sources = ['d/1EB960.cpp', 'd/1F78D8.cpp', 'd/202768.c', 'd/158988.cpp']
        self.assertEqual(record.only_sources(sources, ['0x1eb960', '202768']), ['d/1EB960.cpp', 'd/202768.c'])


class CompilerOverrideTests(unittest.TestCase):
    def test_ee_gcc_dir_replaces_the_compiler_for_one_run(self):
        saved = os.environ.get('EE_GCC_DIR')
        os.environ['EE_GCC_DIR'] = '/somewhere/ee-gcc2.95.3-107'
        try:
            self.assertEqual(compile_unit.compiler_directory(), '/somewhere/ee-gcc2.95.3-107')
        finally:
            if saved is None:
                del os.environ['EE_GCC_DIR']
            else:
                os.environ['EE_GCC_DIR'] = saved

    def test_without_the_variable_the_pinned_compiler_is_used(self):
        saved = os.environ.pop('EE_GCC_DIR', None)
        try:
            self.assertIn('ee-gcc2.95.3-136', compile_unit.compiler_directory())
        finally:
            if saved is not None:
                os.environ['EE_GCC_DIR'] = saved


class FingerprintTests(unittest.TestCase):
    def test_a_touched_file_with_the_same_content_keeps_its_digest(self):
        import scorer
        import tempfile
        with tempfile.NamedTemporaryFile('w', suffix='.txt', delete=False) as handle:
            handle.write('0x2396C0\n')
        before = scorer.content_digest(handle.name)
        os.utime(handle.name, (1, 1))
        self.assertEqual(scorer.content_digest(handle.name), before)
        os.remove(handle.name)

    def test_the_cache_key_depends_on_the_assembler_override(self):
        import scorer
        saved = os.environ.pop('TRY_ASSEMBLER', None)
        try:
            plain = scorer.cache_key('int f();', 'c++')
            os.environ['TRY_ASSEMBLER'] = 'sony29'
            self.assertNotEqual(scorer.cache_key('int f();', 'c++'), plain)
        finally:
            os.environ.pop('TRY_ASSEMBLER', None)
            if saved is not None:
                os.environ['TRY_ASSEMBLER'] = saved

    def test_a_changed_file_changes_its_digest(self):
        import scorer
        import tempfile
        with tempfile.NamedTemporaryFile('w', suffix='.txt', delete=False) as handle:
            handle.write('0x2396C0\n')
        before = scorer.content_digest(handle.name)
        with open(handle.name, 'a') as again:
            again.write('0x23E308\n')
        self.assertNotEqual(scorer.content_digest(handle.name), before)
        os.remove(handle.name)


class AdoptTieTests(unittest.TestCase):
    def setUp(self):
        import tempfile
        self.directory = tempfile.mkdtemp()
        self.sources = os.path.join(self.directory, 'fn')
        self.stage = os.path.join(self.directory, 'stage')
        os.makedirs(self.sources)
        os.makedirs(self.stage)
        self.saved = (adopt.SOURCES, adopt.scorer.judge)
        adopt.SOURCES = self.sources
        adopt.scorer.judge = lambda address, text, lang='c++': 0

    def tearDown(self):
        import shutil
        adopt.SOURCES, adopt.scorer.judge = self.saved
        shutil.rmtree(self.directory)

    def put(self, folder, name, text):
        with open(os.path.join(folder, name), 'w') as handle:
            handle.write(text)

    def test_a_clean_source_replaces_a_tied_one_that_breaks_a_rule(self):
        self.put(self.sources, '100000.cpp', 'int f(char *p) { return M2C_FIELD(p, int *, 4); }\n')
        self.put(self.stage, '100000.cpp', 'struct A { int x; int y; };\nint f(A *p) { return p->y; }\n')
        self.assertEqual(adopt.consider(self.stage, '100000.cpp', False), (1, 1, 1))

    def test_a_tied_source_does_not_replace_a_clean_one(self):
        self.put(self.sources, '100000.cpp', 'struct A { int x; int y; };\nint f(A *p) { return p->y; }\n')
        self.put(self.stage, '100000.cpp', 'struct B { int a; int y; };\nint f(B *p) { return p->y; }\n')
        self.assertEqual(adopt.consider(self.stage, '100000.cpp', False), (1, 0, 0))


class RepeatNoteTests(unittest.TestCase):
    def setUp(self):
        import importlib
        import tempfile
        self.module = importlib.import_module('try')
        self.directory = tempfile.mkdtemp()
        self.saved = (self.module.LAB, self.module.toolchain_fingerprint)
        self.module.LAB = self.directory
        self.source = os.path.join(self.directory, 'a.cpp')
        with open(self.source, 'w') as handle:
            handle.write('int f();\n')

    def tearDown(self):
        import shutil
        self.module.LAB, self.module.toolchain_fingerprint = self.saved
        shutil.rmtree(self.directory)

    def test_the_same_source_under_the_same_toolchain_is_a_repeat(self):
        self.module.toolchain_fingerprint = lambda: 'one'
        self.module.note_repeat(0x100000, self.source, 3)
        self.assertIn('judged 1 time', self.module.note_repeat(0x100000, self.source, 3))

    def test_the_same_source_under_another_toolchain_is_not(self):
        self.module.toolchain_fingerprint = lambda: 'one'
        self.module.note_repeat(0x100000, self.source, 3)
        self.module.toolchain_fingerprint = lambda: 'two'
        self.assertEqual(self.module.note_repeat(0x100000, self.source, 3), '')


class ScriptEntryPointTests(unittest.TestCase):
    def test_every_script_that_defines_main_calls_it(self):
        """A script that defines `main()` and never calls it exits 0 and prints nothing (record.py did, once, after an edit cut its last lines)."""
        import glob
        import re
        root = os.path.dirname(HERE)
        missing = []
        for path in sorted(glob.glob(os.path.join(HERE, '**', '*.py'), recursive=True)):
            with open(path, encoding='utf-8') as handle:
                text = handle.read()
            if re.search(r'^def main\(', text, re.M) and not re.search(r"^if __name__ == ['\"]__main__['\"]:", text, re.M):
                missing.append(os.path.relpath(path, root))
        self.assertEqual(missing, [])


class CheckSourceTests(unittest.TestCase):
    def kinds(self, text):
        return [(kind, message.split(':')[0]) for _, kind, message in check_source.problems(text)]

    def test_a_clean_source_has_no_problems(self):
        self.assertEqual(check_source.problems('struct A { int x; };\nint f(A *a)\n{\n    return a->x;\n}\n'), [])

    def test_inline_asm_is_banned(self):
        self.assertEqual(self.kinds('void f() { asm volatile("nop"); }\n')[0][0], 'banned')

    def test_the_shared_sqrt_helper_is_not_banned(self):
        self.assertEqual(check_source.problems('float Sqrt(float x)\n{\n    float r;\n    asm volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x));\n    return r;\n}\n'), [])

    def test_raw_m2c_offsets_are_a_cleanup_problem(self):
        self.assertEqual(self.kinds('int f(char *p) { return M2C_FIELD(p, int *, 4); }\n'), [('cleanup', 'M2C_UNK / M2C_FIELD')])

    def test_tabs_and_trailing_whitespace_are_a_cleanup_problem(self):
        self.assertEqual(sorted(message for _, message in self.kinds('int x;\t\nint y; \n')), ['a tab', 'trailing whitespace', 'trailing whitespace'])

    def test_a_scratch_array_nothing_uses_is_a_padding_local(self):
        found = self.kinds('int f(int a)\n{\n    int scratch[4];\n    (void)scratch;\n    return a;\n}\n')
        self.assertEqual(found, [('cleanup', 'padding local')])

    def test_an_unused_array_is_a_padding_local_whatever_its_name(self):
        found = self.kinds('int f(int a)\n{\n    int reserved[2];\n    (void)reserved;\n    return a;\n}\n')
        self.assertEqual(found, [('cleanup', 'padding local')])

    def test_an_unused_scalar_is_a_padding_local_whatever_its_name(self):
        self.assertEqual(self.kinds('int f(int a)\n{\n    int dead;\n    return a;\n}\n'), [('cleanup', 'padding local')])

    def test_an_unused_local_of_a_named_struct_type_is_allowed(self):
        self.assertEqual(check_source.problems('struct VECTOR { float x, y, z, w; };\nint f(int a)\n{\n    VECTOR hitPosition;\n    return a;\n}\n'), [])

    def test_a_scalar_set_from_a_call_is_not_padding(self):
        self.assertEqual(check_source.problems('int g();\nint f()\n{\n    int ignored = g();\n    return 0;\n}\n'), [])

    def test_struct_members_after_a_define_with_parentheses_are_not_locals(self):
        text = '#define FIELD(expr, offset) ((expr) + (offset))\nstruct Slot {\n    int buffer;\n    int pad[3];\n};\nint f(Slot *slot)\n{\n    return slot->buffer;\n}\n'
        self.assertEqual(check_source.problems(text), [])

    def test_a_scratch_buffer_a_callee_fills_is_not_padding(self):
        self.assertEqual(check_source.problems('void g(int *);\nint f()\n{\n    int scratch[3];\n    g(scratch);\n    return scratch[0];\n}\n'), [])

    def test_a_struct_member_named_unused_is_not_a_local(self):
        self.assertEqual(check_source.problems('struct A {\n    int unused;\n    int x;\n};\n'), [])

    def test_a_banned_source_goes_to_the_asm_archive_and_the_rest_to_cleanup_pending(self):
        banned = check_source.problems('void f() { asm("nop"); }\n')
        unclean = check_source.problems('int f(char *p) { return M2C_FIELD(p, int *, 4); }\n')
        self.assertEqual((check_source.destination(banned), check_source.destination(unclean)), ('asm-archive', 'cleanup-pending'))


class ParkTests(unittest.TestCase):
    def setUp(self):
        import tempfile
        self.previous = os.getcwd()
        self.directory = tempfile.mkdtemp()
        os.chdir(self.directory)
        os.makedirs('data/matching/src/fn')
        with open('data/matching/src/fn/100000.cpp', 'w') as handle:
            handle.write('int f();\n')

    def tearDown(self):
        import shutil
        os.chdir(self.previous)
        shutil.rmtree(self.directory)

    def row(self):
        return {'address': '0x100000', 'status': 'matched', 'best': '0', 'source': 'data/matching/src/fn/100000.cpp'}

    def test_an_asm_source_moves_to_the_archive_and_the_row_is_tried(self):
        row = self.row()
        destination = park.park(row, 'asm')
        self.assertEqual((row['status'], row['source'], os.path.exists(destination)), ('tried', '', True))
        self.assertTrue(destination.startswith(os.path.join('data', 'matching', 'asm-archive')))

    def test_an_unclean_source_moves_to_cleanup_pending(self):
        destination = park.park(self.row(), 'cleanup')
        self.assertTrue(destination.startswith(os.path.join('data', 'matching', 'cleanup-pending')))

    def test_a_regression_keeps_its_source_and_takes_the_new_score(self):
        row = self.row()
        self.assertEqual(park.park(row, 'regression', 3), '')
        self.assertEqual((row['status'], row['best'], os.path.exists('data/matching/src/fn/100000.cpp')), ('tried', '3', True))


class BlockerTests(unittest.TestCase):
    def test_vu_instructions_are_a_blocker(self):
        self.assertEqual(classify_blockers.kind_of(['lw', 'lqc2', 'jr']), 'vu')
        self.assertEqual(classify_blockers.kind_of(['vmulax.xyz', 'jr']), 'vu')

    def test_mmi_and_system_instructions(self):
        self.assertEqual(classify_blockers.kind_of(['pextuw', 'jr']), 'mmi')
        self.assertEqual(classify_blockers.kind_of(['mfc0', 'jr']), 'system')

    def test_plain_code_and_division_checks_are_not_blockers(self):
        self.assertIsNone(classify_blockers.kind_of(['addiu', 'div', 'break', 'mflo', 'jr']))

    def test_an_epilogue_left_behind_does_not_transfer_control(self):
        self.assertFalse(classify_blockers.transfers_control(['addiu', 'nop']))

    def test_a_function_that_returns_transfers_control(self):
        self.assertTrue(classify_blockers.transfers_control(['addiu', 'jr', 'nop']))

    def test_a_branch_transfers_control(self):
        self.assertTrue(classify_blockers.transfers_control(['bc1t', 'nop']))

    def test_a_call_target_is_a_reference(self):
        jal = (3 << 26) | (0x00100040 >> 2)
        self.assertIn(0x00100040, classify_blockers.references_in_words([jal], 0x00100000))

    def test_a_branch_target_is_a_reference(self):
        beq_forward_two = (4 << 26) | 2  # beq $zero, $zero, +2 at 0x100000: target 0x10000C
        self.assertIn(0x0010000C, classify_blockers.references_in_words([beq_forward_two], 0x00100000))

    def test_a_lui_addiu_pair_is_a_reference(self):
        lui = (15 << 26) | (2 << 16) | 0x0011  # lui $v0, 0x11
        addiu = (9 << 26) | (2 << 21) | (2 << 16) | 0x8000  # addiu $v0, $v0, -0x8000
        self.assertIn(0x00108000, classify_blockers.references_in_words([lui, addiu], 0x00100000))

    def test_a_pointer_in_data_is_a_reference(self):
        self.assertIn(0x00123450, classify_blockers.references_in_words([0x00123450], 0x002A0000))

    def test_an_address_nothing_aims_at_is_not_a_reference(self):
        self.assertNotIn(0x00100100, classify_blockers.references_in_words([0x00000000, (3 << 26) | (0x00100040 >> 2)], 0x00100000))

    def test_mnemonics_are_read_from_splat_lines(self):
        lines = ['    /* 0 00100000 0C000000 */  jal        Callee\n', '    /* 4 00100004 2A00023C */  lqc2       $vf1, 0($a0)\n']
        self.assertEqual(classify_blockers.mnemonics_of(lines), ['jal', 'lqc2'])

    REPORT = {'measures': {}, 'categories': [{'id': 'game', 'name': 'Game', 'measures': {}}], 'units': [
        {'name': 'a', 'metadata': {'progress_categories': ['game']}, 'sections': [], 'functions': [
            {'name': 'f', 'size': '100', 'fuzzy_match_percent': 100.0}, {'name': 'g', 'size': '300'}, {'name': 'h', 'size': '100', 'fuzzy_match_percent': 40.0}]}]}

    def test_a_blocker_counts_as_finished(self):
        import copy
        report = copy.deepcopy(self.REPORT)
        counted = blockers_report.apply(report, {'g'})
        self.assertEqual(counted, (1, 300))
        self.assertEqual(report['measures']['matched_code'], '400')
        self.assertEqual(report['measures']['matched_functions'], 2)
        self.assertEqual(report['categories'][0]['measures']['matched_code'], '400')

    def test_a_function_already_matched_is_not_counted_again(self):
        import copy
        report = copy.deepcopy(self.REPORT)
        self.assertEqual(blockers_report.apply(report, {'f'}), (0, 0))

    def test_recompute_without_blockers_keeps_the_totals(self):
        import copy
        report = copy.deepcopy(self.REPORT)
        blockers_report.recompute(report)
        self.assertEqual((report['measures']['total_code'], report['measures']['matched_code']), ('500', '100'))


class ProgressTests(unittest.TestCase):
    def capture(self, enabled, ticks):
        import io
        old = os.environ.get('PROGRESS')
        if enabled:
            os.environ['PROGRESS'] = '1'
        else:
            os.environ.pop('PROGRESS', None)
        try:
            stream = io.StringIO()
            tracker = progress.Progress(ticks, 'test', interval=0, stream=stream)
            for index in range(ticks):
                tracker.tick(f'item {index}')
            tracker.done('ok')
            return stream.getvalue(), tracker
        finally:
            if old is None:
                os.environ.pop('PROGRESS', None)
            else:
                os.environ['PROGRESS'] = old

    def test_nothing_is_printed_unless_progress_is_set(self):
        text, tracker = self.capture(False, 3)
        self.assertEqual(text, '')
        self.assertEqual(tracker.suffix(), '')

    def test_a_line_per_item_with_the_count_and_the_percentage(self):
        text, _ = self.capture(True, 4)
        lines = text.strip().split('\n')
        self.assertTrue(lines[0].startswith('[test] 1/4 25%'))
        self.assertTrue(lines[3].startswith('[test] 4/4 100%'))
        self.assertTrue(lines[-1].startswith('[test] done in'))

    def test_the_heartbeat_names_what_is_running_while_nothing_finishes(self):
        import io
        import time
        old = os.environ.get('PROGRESS')
        os.environ['PROGRESS'] = '1'
        try:
            stream = io.StringIO()
            tracker = progress.Progress(5, 'beat', interval=100, heartbeat=0.05, stream=stream)
            tracker.begin('1FC270')
            time.sleep(0.3)
            tracker.done()
            self.assertIn('running 1FC270', stream.getvalue())
            self.assertIn('0/5', stream.getvalue())
        finally:
            if old is None:
                os.environ.pop('PROGRESS', None)
            else:
                os.environ['PROGRESS'] = old

    def test_items_finishing_out_of_order_leave_the_others_running(self):
        import io
        old = os.environ.get('PROGRESS')
        os.environ['PROGRESS'] = '1'
        try:
            stream = io.StringIO()
            tracker = progress.Progress(3, 'order', interval=0, heartbeat=0, stream=stream)
            tracker.begin('A')
            tracker.begin('B')
            tracker.tick('6 -> 5', 'B')
            self.assertIn('1/3', stream.getvalue())
            self.assertIn('running A', stream.getvalue())
            self.assertNotIn('running A, B', stream.getvalue())
            self.assertIn('last 6 -> 5', stream.getvalue())
        finally:
            if old is None:
                os.environ.pop('PROGRESS', None)
            else:
                os.environ['PROGRESS'] = old

    def test_clock_formats_seconds_minutes_and_hours(self):
        self.assertEqual(progress.clock(42), '42s')
        self.assertEqual(progress.clock(125), '2m05s')
        self.assertEqual(progress.clock(3725), '1h02m')


class PairVersionsTests(unittest.TestCase):
    def test_a_jal_target_is_dropped(self):
        self.assertEqual(pair_versions.normalise(0x0C000100), pair_versions.normalise(0x0C0FFFFF))

    def test_an_address_immediate_is_dropped_but_the_registers_are_kept(self):
        lui_a = 0x3C040020  # lui $a0, 0x20
        lui_b = 0x3C040021
        lui_other_register = 0x3C050020
        self.assertEqual(pair_versions.normalise(lui_a), pair_versions.normalise(lui_b))
        self.assertNotEqual(pair_versions.normalise(lui_a), pair_versions.normalise(lui_other_register))

    def test_an_instruction_without_an_address_part_is_kept(self):
        self.assertNotEqual(pair_versions.normalise(0x00851021), pair_versions.normalise(0x00851022))  # addu: the function field matters


class DiscExtractTests(unittest.TestCase):
    def record(self, name, lba, size, is_directory=False):
        identifier = name.encode()
        length = 33 + len(identifier) + (1 - len(identifier) % 2)
        data = bytearray(length)
        data[0] = length
        struct.pack_into('<I', data, 2, lba)
        struct.pack_into('<I', data, 10, size)
        data[25] = 2 if is_directory else 0
        data[32] = len(identifier)
        data[33:33 + len(identifier)] = identifier
        return bytes(data)

    def test_directory_reads_names_extents_and_sizes(self):
        import io
        content = self.record('\x00', 20, 2048, True) + self.record('\x01', 20, 2048, True) + self.record('SYSTEM.CNF;1', 30, 50) + self.record('SUB', 40, 2048, True)
        sector = content + bytes(2048 - len(content))
        handle = io.BytesIO(bytes(2048 * 20) + sector)
        entries = disc_extract.directory(handle, 20, 2048)
        self.assertEqual(entries, [('SYSTEM.CNF', 30, 50, False), ('SUB', 40, 2048, True)])


class VersionCheckTests(unittest.TestCase):
    def test_a_lui_with_an_addiu_sign_extends_the_low_half(self):
        self.assertEqual(version_check.address_of(0x3C020029, 0x24428000), 0x288000)

    def test_a_lui_with_an_ori_zero_extends_the_low_half(self):
        self.assertEqual(version_check.address_of(0x3C020029, 0x3442F000), 0x29F000)

    def test_a_small_positive_low_half(self):
        self.assertEqual(version_check.address_of(0x3C02002B, 0x8C430010), 0x2B0010)


class PalReportTests(unittest.TestCase):
    def report(self):
        return {'version': 2, 'categories': [{'id': 'game', 'name': 'Game code'}], 'units': [
            {'name': 'one', 'functions': [{'name': 'A', 'size': '100', 'fuzzy_match_percent': 100.0}, {'name': 'B', 'size': '300', 'fuzzy_match_percent': 40.0}],
             'metadata': {'progress_categories': ['game']}},
            {'name': 'two', 'functions': [{'name': 'C', 'size': '200', 'fuzzy_match_percent': 100.0}], 'metadata': {'progress_categories': ['game']}},
            {'name': 'data/rodata', 'functions': [], 'metadata': {'progress_categories': ['data']}},
            {'name': 'data/rodata-c', 'functions': [], 'metadata': {'progress_categories': ['data']}}]}

    def test_only_a_function_checked_for_the_other_version_counts_as_matched(self):
        built = pal_report.build(self.report(), {'A': True, 'B': False, 'C': False}, {'.rodata': 5000, '.data': 0, '.vutext': 0, '.irx': 0})
        shown = built['measures']
        self.assertEqual((shown['total_code'], shown['matched_code'], shown['matched_functions'], shown['total_functions']), ('600', '100', 1, 3))

    def test_a_unit_is_complete_when_all_its_functions_are_matched(self):
        built = pal_report.build(self.report(), {'A': True, 'B': True, 'C': False}, {'.rodata': 5000, '.data': 0, '.vutext': 0, '.irx': 0})
        complete = {unit['name']: unit['metadata']['complete'] for unit in built['units']}
        self.assertTrue(complete['one'])
        self.assertFalse(complete['two'])

    def test_check_finds_a_matched_function_without_a_pal_row_and_a_stale_row(self):
        import argparse
        import json
        import tempfile
        with tempfile.TemporaryDirectory() as folder:
            os.makedirs(os.path.join(folder, 'src'))
            with open(os.path.join(folder, 'src', 'MANIFEST.tsv'), 'w') as handle:
                handle.write('address\tname\tsize\tfile\n0X100000\tA\t100\tx/A.cpp\n0X100100\tB\t100\tx/B.cpp\n')
            status = os.path.join(folder, 'c_status.tsv')
            with open(status, 'w') as handle:
                handle.write('us_address\tname\tother_address\tpair\tscore\taddresses\n0X100000\tA\t0X100000\tsame\t0\tok\n0X100200\tC\t0X100200\tsame\t0\tok\n')
            us_report = os.path.join(folder, 'us.json')
            json.dump(self.report(), open(us_report, 'w'))
            old = pal_report.LAB
            pal_report.LAB = folder
            try:
                missing = pal_report.check(argparse.Namespace(status=status, us_report=us_report, out=os.path.join(folder, 'eu.json')))
            finally:
                pal_report.LAB = old
        text = '\n'.join(missing)
        self.assertIn('B (0X100100) is matched but has no row', text.replace('0x', '0X'))
        self.assertIn('0X100200', text.replace('0x', '0X'))
        self.assertIn('eu.json is missing', text)

    def test_check_accepts_a_report_that_is_what_the_us_report_and_the_status_give(self):
        import argparse
        import json
        import tempfile
        with tempfile.TemporaryDirectory() as folder:
            os.makedirs(os.path.join(folder, 'src'))
            with open(os.path.join(folder, 'src', 'MANIFEST.tsv'), 'w') as handle:
                handle.write('address\tname\tsize\tfile\n0X100000\tA\t100\tx/A.cpp\n')
            status = os.path.join(folder, 'c_status.tsv')
            with open(status, 'w') as handle:
                handle.write('us_address\tname\tother_address\tpair\tscore\taddresses\n0X100000\tA\t0X100000\tsame\t0\tok\n')
            us_report, out = os.path.join(folder, 'us.json'), os.path.join(folder, 'eu.json')
            json.dump(self.report(), open(us_report, 'w'))
            json.dump(pal_report.build(self.report(), {'A': True}, {'.rodata': 5000, '.data': 0, '.vutext': 0, '.irx': 0}), open(out, 'w'))
            old = pal_report.LAB
            pal_report.LAB = folder
            try:
                self.assertEqual(pal_report.check(argparse.Namespace(status=status, us_report=us_report, out=out)), [])
                json.dump(pal_report.build(self.report(), {'A': False}, {'.rodata': 5000, '.data': 0, '.vutext': 0, '.irx': 0}), open(out, 'w'))
                stale = pal_report.check(argparse.Namespace(status=status, us_report=us_report, out=out))
            finally:
                pal_report.LAB = old
        self.assertEqual(len(stale), 1)
        self.assertIn('run `make pal`', stale[0])

    def test_the_data_unit_has_the_other_versions_size_and_the_owned_rodata_unit_is_left_out(self):
        built = pal_report.build(self.report(), {}, {'.rodata': 5000, '.data': 0, '.vutext': 0, '.irx': 0})
        names = [unit['name'] for unit in built['units']]
        self.assertIn('data/rodata', names)
        self.assertNotIn('data/rodata-c', names)
        self.assertEqual(built['measures']['total_data'], '5000')
        self.assertNotIn('matched_data', built['measures'])


class MutateM2cTests(unittest.TestCase):
    def rng(self):
        return mutate.random.Random(3)

    def test_leading_argument_declares_and_passes_arg0(self):
        lines = ['M2C_UNK Callee(s32);', 'void F(s8 *arg0) {', '    Callee(1);', '}']
        changed = mutate.leading_argument(lines, 2, self.rng())
        self.assertEqual(changed[0], 'M2C_UNK Callee(s8 *, s32);')
        self.assertEqual(changed[2], '    Callee(arg0, 1);')

    def test_leading_argument_needs_arg0(self):
        self.assertIsNone(mutate.leading_argument(['M2C_UNK Callee(s32);', 'void F(s8 *p) {', '    Callee(1);', '}'], 2, self.rng()))

    def test_return_kind_only_voids_a_discarded_result(self):
        lines = ['s32 Callee(s32);', 'void F(void) {', '    x = Callee(1);', '}']
        self.assertIsNone(mutate.callee_return_kind(lines, 2, self.rng()))
        lines[2] = '    Callee(1);'
        self.assertEqual(mutate.callee_return_kind(lines, 2, self.rng())[0], 'void Callee(s32);')

    def test_float_parameter_toggles_one_parameter(self):
        changed = mutate.float_parameter(['M2C_UNK SetRate(s8 *, M2C_UNK);', 'void F(void) {', '    SetRate(p, 1);', '}'], 2, self.rng())
        self.assertEqual(changed[0], 'M2C_UNK SetRate(s8 *, f32);')

    def test_pointer_stride_scales_back(self):
        lines = ['void F(void) {', '    s32 *cursor;', '    cursor += 4;', '}']
        changed = mutate.pointer_stride(lines, 2, mutate.random.Random(0))
        self.assertIn(changed[2], ('    cursor += 1;', '    cursor += 4;'))

    def test_bit_test_cast_adds_and_removes_the_int_cast(self):
        added = mutate.bit_test_cast(['    if ((x >> 0x3C) & 1) {'], 0, self.rng())
        self.assertIn('>> 0x3C) & 1', added[0])
        self.assertTrue('(int)' in added[0] or '(u32)' in added[0])
        removed = mutate.bit_test_cast(['    if ((int)(x >> 0x3C) & 1) {'], 0, self.rng())
        self.assertNotIn('(int)', removed[0])

    def test_long_shift_marks_the_constant_long(self):
        self.assertEqual(mutate.long_shift(['    f |= 0x8000 << 0x23;'], 0, self.rng())[0], '    f |= 0x8000L << 0x23;')

    def test_volatile_reads_are_not_a_mutation(self):
        self.assertNotIn(mutate.volatile_slot, mutate.MUTATIONS)


class ListingTests(unittest.TestCase):
    FUNCTIONS = [
        {'address': '0X100010', 'name': 'b', 'size': 40, 'module': 'm', 'status': 'asm', 'named': True},
        {'address': '0X100000', 'name': 'a', 'size': 8, 'module': 'm', 'status': 'c', 'named': False},
        {'address': '0X100020', 'name': 'c', 'size': 16, 'module': 'n', 'status': 'asm', 'named': False},
    ]

    def test_filters_by_module_and_status(self):
        self.assertEqual([f['name'] for f in list_functions.select(self.FUNCTIONS, module='m', status='asm')], ['b'])

    def test_sorts_smallest_first(self):
        self.assertEqual([f['name'] for f in list_functions.select(self.FUNCTIONS, order='size')], ['a', 'c', 'b'])

    def test_unnamed_only(self):
        self.assertEqual([f['name'] for f in list_functions.select(self.FUNCTIONS, unnamed=True)], ['a', 'c'])

    def test_unit_selector(self):
        entry = ['0X1002A8', 'Foo', '168', 'mat/Foo.cpp']
        self.assertTrue(all(check_unit.matches(entry, selector) for selector in (None, 'mat', '0X1002A8', 'Foo', 'src/mat/Foo.cpp')))
        self.assertFalse(check_unit.matches(entry, 'other'))


SAMPLE_SOURCE = '''extern "C" void func_00100010(int);
extern "C" int func_00100020(int);
void f(int *p)
{
    func_00100010(1);
    while (*p != 0) {
        *p = func_00100020(*p);
    }
    func_00100010(2);
}
'''.split('\n')


class MutationTests(unittest.TestCase):
    def results(self, mutation):
        rng = mutate.random.Random(1)
        found = set()
        for _ in range(50):
            for index in range(len(SAMPLE_SOURCE)):
                changed = mutation(SAMPLE_SOURCE, index, rng)
                if changed and changed != SAMPLE_SOURCE:
                    found.add('\n'.join(changed))
        return found

    def test_callee_returning_nothing_can_return_int(self):
        self.assertTrue(any('extern "C" int func_00100010(int);' in text for text in self.results(mutate.flip_callee_return)))

    def test_callee_used_in_an_expression_stays_int(self):
        self.assertFalse(any('extern "C" void func_00100020' in text for text in self.results(mutate.flip_callee_return)))

    def test_while_becomes_a_bottom_tested_goto_loop(self):
        self.assertTrue(any('goto test_5;' in text and 'if (*p != 0) goto loop_5;' in text for text in self.results(mutate.while_to_goto)))

    def test_while_with_break_is_left_alone(self):
        lines = ['void g(int *p)', '{', '    while (*p) {', '        if (*p == 3) break;', '    }', '}']
        self.assertIsNone(mutate.while_to_goto(lines, 2, mutate.random.Random(1)))

    def test_while_becomes_a_guarded_do_while(self):
        lines = ['void g(int *p)', '{', '    while (*p > 0) {', '        *p = *p - 1;', '    }', '}']
        text = '\n'.join(mutate.while_to_dowhile(lines, 2, mutate.random.Random(1)))
        self.assertIn('if (*p > 0) {', text)
        self.assertIn('} while (*p > 0);', text)

    def test_while_with_continue_is_not_rotated(self):
        lines = ['void g(int *p)', '{', '    while (*p) {', '        if (*p == 3) continue;', '    }', '}']
        self.assertIsNone(mutate.while_to_dowhile(lines, 2, mutate.random.Random(1)))

    def test_last_call_gains_a_return(self):
        self.assertTrue(any('    return;' in text for text in self.results(mutate.tail_return)))


class PrologueProfileTests(unittest.TestCase):
    def test_frame_with_ra_saved_first(self):
        words = [0x27BDFFE0, 0xFFBF0010, 0xFFB00000]  # addiu sp,sp,-32; sd ra,16(sp); sd s0,0(sp)
        self.assertEqual(prologue_profile.classify(words), 'sd stride 16, ra first')

    def test_quadword_save_is_a_different_class(self):
        words = [0x27BDFFC0, 0x7FB10010, 0xFFBF0000, 0x7FB00020]  # sq s1; sd ra; sq s0
        self.assertTrue(prologue_profile.classify(words).startswith('sdsq'))

    def test_function_without_frame_has_no_class(self):
        self.assertIsNone(prologue_profile.classify([0x03E00008, 0x00000000]))


class VuDisassemblerTests(unittest.TestCase):
    def test_upper_nop(self):
        self.assertEqual(vudis.decode_upper(0x000002FF), 'nop')

    def test_lower_nop(self):
        self.assertEqual(vudis.decode_lower(0x8000033C, 0), 'nop')

    def test_upper_add_with_destination_mask(self):
        self.assertEqual(vudis.decode_upper(0x01C208E8), 'add.xyz vf3, vf1, vf2')

    def test_upper_broadcast_accumulator(self):
        self.assertEqual(vudis.decode_upper(0x01E1003C), 'addax.xyzw ACC, vf0, vf1x')

    def test_lower_load_quadword(self):
        self.assertEqual(vudis.decode_lower(0x01E11004, 0), 'lq.xyzw vf1, 4(vi2)')

    def test_lower_branch_target_is_relative_to_next_instruction(self):
        self.assertEqual(vudis.decode_lower(0x520117FE, 10), 'ibne vi1, vi2, L9')

    def test_lower_xgkick(self):
        self.assertEqual(vudis.decode_lower(0x80002EFC, 0), 'xgkick vi5')


class VolatileSlotTests(unittest.TestCase):
    SOURCE = ['void f(void *vifs)', '{', '    unsigned *header;', '    Unpack(vifs, &header);', '    header[1] = 5;', '}']

    def rewritten(self, lines, index):
        return mutate.volatile_slot(lines, index, mutate.random.Random(1))

    def test_store_through_an_escaped_pointer_rereads_the_slot(self):
        self.assertEqual(self.rewritten(self.SOURCE, 4)[4], '    (*(unsigned * volatile *)&header)[1] = 5;')

    def test_second_rewrite_undoes_the_first(self):
        once = self.rewritten(self.SOURCE, 4)
        self.assertEqual(self.rewritten(once, 4)[4], '    header[1] = 5;')

    def test_pointer_whose_address_never_escapes_is_left_alone(self):
        lines = ['void f(void)', '{', '    unsigned *header;', '    header[1] = 5;', '}']
        self.assertIsNone(self.rewritten(lines, 3))


class NeighborhoodTests(unittest.TestCase):
    SOURCE = 'void f(int *p)\n{\n    int a;\n    int b;\n    int c;\n    a = p[0];\n    b = p[1];\n    c = a + b;\n    p[2] = c;\n}'

    def test_every_order_of_three_declarations_is_offered(self):
        orders = neighborhood.declaration_orders(self.SOURCE)
        self.assertEqual(len({text.split('{')[1].split('a = ')[0] for text in orders}), 5)  # 3! - the original

    def test_orders_keep_the_function_body(self):
        for text in neighborhood.declaration_orders(self.SOURCE):
            self.assertEqual(sorted(text.split('\n')), sorted(self.SOURCE.split('\n')))

    def test_single_edits_reach_swapped_operands(self):
        self.assertTrue(any('c = b + a;' in text for text in neighborhood.single_edits(self.SOURCE, 4)))


class IdiomTests(unittest.TestCase):
    def test_volatile_slot_and_goto_are_found(self):
        text = '    (*(unsigned * volatile *)&p)[0] = 1;\n    goto top;\n'
        self.assertEqual(idioms.idioms_of(text), {'volatile slot read', 'goto loop'})

    def test_callees_leave_keywords_out(self):
        self.assertEqual(idioms.callees('    if (x) Draw(a);\n    while (y) Step(b);'), {'Draw', 'Step'})


class BoundaryTests(unittest.TestCase):
    ROWS = [{'address': '0x100000', 'size': '16', 'status': 'tried', 'best': '3'},
            {'address': '0x100010', 'size': '32', 'status': 'todo', 'best': ''},
            {'address': '0x100030', 'size': '8', 'status': 'todo', 'best': ''}]
    MERGE = [{'lead': '0x100000', 'end': '0x100030', 'members': '0x100000,0x100010', 'evidence': ''}]

    def test_group_becomes_one_function_with_the_whole_size(self):
        merged = boundaries.apply_merges([dict(row) for row in self.ROWS], self.MERGE)
        self.assertEqual([(row['address'], row['size']) for row in merged], [('0x100000', '48'), ('0x100030', '8')])

    def test_score_kept_from_the_partial_size_is_cleared(self):
        merged = boundaries.apply_merges([dict(row) for row in self.ROWS], self.MERGE)
        self.assertEqual(merged[0]['best'], '')

    def test_merging_twice_changes_nothing(self):
        once = boundaries.apply_merges([dict(row) for row in self.ROWS], self.MERGE)
        twice = boundaries.apply_merges([dict(row) for row in once], self.MERGE)
        self.assertEqual(once, twice)


class HarvestTests(unittest.TestCase):
    DRAFT = 'M2C_UNK helper(M2C_UNK);\nvoid f(void *arg0) {\n    return;\n}\n'

    def test_draft_is_wrapped_and_pointers_stop_being_void(self):
        text = harvest.build(self.DRAFT)
        self.assertIn('extern "C" {', text)
        self.assertIn('void f(s8 *arg0)', text)

    def test_draft_with_an_unhandled_instruction_is_refused(self):
        self.assertIsNone(harvest.build('M2C_ERROR(/* unknown instruction: ldl */);'))

    def test_callee_return_type_follows_the_signatures(self):
        text = harvest.build(self.DRAFT, {'helper': 'void'})
        self.assertIn('void helper(M2C_UNK);', text)


class HarvestRepairTests(unittest.TestCase):
    def test_assignment_gets_a_cast_to_the_type_the_compiler_names(self):
        text = 'void f(void) {\n    p = q;\n}'
        message = "x.cpp:2: assignment to `s8 *' from `int *'"
        self.assertIn('p = (s8 *)(q);', harvest.repair_once(text, message))

    def test_argument_gets_a_cast_to_the_parameter_type(self):
        text = 'void f(void) {\n    g(a, b);\n}'
        message = "x.cpp:2: passing `char *' as argument 2 of `g(int, s8 *)' changes signedness"
        self.assertIn('(s8 *)(b)', harvest.repair_once(text, message))

    def test_unknown_error_is_left_alone(self):
        self.assertIsNone(harvest.repair_once('void f(void) {\n}', 'x.cpp:1: parse error'))


class CreditAuditTests(unittest.TestCase):
    def test_empty_asm_is_a_barrier(self):
        self.assertEqual(credit_audit.tier_of(credit_audit.flags_of('asm volatile("" : "+f" (x));')), 'barrier')

    def test_register_pinned_local_is_a_barrier(self):
        self.assertEqual(credit_audit.tier_of(credit_audit.flags_of('    register int bits asm("$2");')), 'barrier')

    def test_vu0_instruction_alone_does_not_lower_the_tier(self):
        self.assertEqual(credit_audit.tier_of(credit_audit.flags_of('asm("lqc2 vf1, 0(%0)" : : "r" (p));')), 'plain')

    def test_other_instruction_in_asm_is_asm(self):
        self.assertEqual(credit_audit.tier_of(credit_audit.flags_of('asm("mtc1 %1, %0" : "=f" (r) : "r" (v));')), 'asm')

    def test_volatile_pointer_cast_is_its_own_tier(self):
        self.assertEqual(credit_audit.tier_of(credit_audit.flags_of('(*(unsigned * volatile *)&p)[0] = 1;')), 'volatile')

    def test_plain_source_is_plain(self):
        self.assertEqual(credit_audit.tier_of(credit_audit.flags_of('int f(int a) { return a + 1; }')), 'plain')


try:
    import callee_sigs
    import rabbitizer  # noqa: F401
except ImportError:
    callee_sigs = None


@unittest.skipIf(callee_sigs is None, 'needs rabbitizer and pyelftools (.venv)')
class CalleeSignatureTests(unittest.TestCase):
    CALL = 0x0C000000
    NOP = 0
    RETURN = 0x03E00008

    def test_result_read_after_the_call_is_an_int(self):
        words = [self.CALL, self.NOP, 0x00441021, self.RETURN, self.NOP]  # jal, nop, addu $v0, $v0, $a0
        self.assertEqual(callee_sigs.call_use(words, 0), 'int')

    def test_result_overwritten_before_use_is_unused(self):
        words = [self.CALL, self.NOP, 0x24020001, 0x00441021, self.RETURN, self.NOP]  # addiu $v0, $zero, 1 first
        self.assertEqual(callee_sigs.call_use(words, 0), 'unused')

    def test_float_result_is_read_from_f0(self):
        words = [self.CALL, self.NOP, 0xE7A00010, self.RETURN, self.NOP]  # swc1 $f0, 0x10($sp)
        self.assertEqual(callee_sigs.call_use(words, 0), 'float')

    def test_value_written_to_v0_before_return_marks_the_callee(self):
        words = [0x24020001, self.RETURN, self.NOP]  # addiu $v0, $zero, 1; jr $ra
        self.assertEqual(callee_sigs.returns_in_tail(words, 0, 3), (True, False))

    def test_callee_without_a_result_is_void(self):
        words = [0x27BDFFF0, 0x27BD0010, self.RETURN, self.NOP]  # no write to $v0 or $f0
        self.assertEqual(callee_sigs.returns_in_tail(words, 0, 4), (False, False))


    def test_argument_register_read_before_written_is_a_parameter(self):
        self.assertEqual(callee_sigs.params_read([0x00851021, self.RETURN, self.NOP], 0, 3), 2)  # addu $v0, $a0, $a1

    def test_argument_register_written_first_is_not(self):
        self.assertEqual(callee_sigs.params_read([0x24050001, 0x00851021, self.RETURN, self.NOP], 0, 4), 1)  # addiu $a1, $zero, 1 first

    def test_call_arities_count_arguments(self):
        text = '    Draw(a, b + 1, c);\n    Reset();\n    x = Pair(f(1), 2);'
        self.assertEqual([(name, count) for name, _, count in callee_sigs.call_arities(text)], [('Draw', 3), ('Reset', 0), ('Pair', 2), ('f', 1)])


class VuAssemblerTests(unittest.TestCase):
    def roundtrip(self, upper, lower, flags='', index=0):
        upper_text, lower_text = vudis.decode_upper(upper), vudis.decode_lower(lower, index)
        return vuasm.assemble_pair(upper_text, lower_text, flags, index)

    def test_arithmetic_with_broadcast_field(self):
        word = 0x000207BC | (0b1110 << 21)
        self.assertEqual(self.roundtrip(word, 0x8000033C), (0x8000033C, word))

    def test_load_with_negative_offset(self):
        lower = 0x00000000 | (0b1111 << 21) | (3 << 16) | (4 << 11) | (0x7FE)  # lq.xyzw vf3, -2(vi4)
        self.assertEqual(self.roundtrip(0x000002FF, lower)[0], lower)

    def test_branch_target_is_the_instruction_index(self):
        lower = 0x20 << 25 | 5  # b, 5 instructions past the next one
        self.assertEqual(vudis.decode_lower(lower, 10), 'b L16')
        self.assertEqual(vuasm.assemble_lower('b L16', 10), lower)

    def test_float_constant_sets_the_i_flag(self):
        lower, upper = vuasm.assemble_pair('nop', 'loi 1.5', 'i', 0)
        self.assertEqual((lower, upper >> 31), (0x3FC00000, 1))

    def test_unreproducible_instruction_is_kept_as_raw_words(self):
        data = bytes.fromhex('0000000000000000') + bytes.fromhex('3c03000700000003')  # a lower word the text cannot express
        lines, raw = vuasm.source_lines(data)
        self.assertEqual((raw, vuasm.assemble('\n'.join(lines))), (1, data))

    def test_listing_of_vudis_is_accepted(self):
        text = '    0  0x000  nop                                          | nop                                      [e]\n'
        self.assertEqual(vuasm.assemble(text), bytes.fromhex('3c030080ff020040'))


class ReviewTests(unittest.TestCase):
    LOCAL = 'int f(int *p)\n{\n    int newline = 10;\n    p[0] = newline;\n    if (p[1] == newline) return 1;\n    return 0;\n}\n'

    def test_a_local_that_only_holds_a_literal_for_two_uses_is_a_warning(self):
        self.assertEqual([message.split(':')[0] for _, _, message in check_source.review(self.LOCAL)], ['literal local'])

    def test_a_local_that_changes_is_not_a_literal_holder(self):
        text = 'int f(int *p)\n{\n    int count = 0;\n    while (p[count]) count++;\n    return count;\n}\n'
        self.assertEqual(check_source.review(text), [])

    def test_a_local_read_from_memory_is_not_a_literal_holder(self):
        text = 'int f(int *p)\n{\n    int first = p[0];\n    p[1] = first;\n    p[2] = first;\n    return 0;\n}\n'
        self.assertEqual(check_source.review(text), [])

    def test_a_constant_true_condition_is_a_warning(self):
        text = 'int f(int x)\n{\n    if (x == 0 || 1) return 1;\n    return 0;\n}\n'
        self.assertEqual([message.split(':')[0] for _, _, message in check_source.review(text)], ['constant condition'])

    def test_review_never_fails_problems(self):
        self.assertEqual(check_source.problems(self.LOCAL), [])


class SearchGuardTests(unittest.TestCase):
    CLEAN = 'int f(int *p)\n{\n    p[0] = 1;\n    return 0;\n}\n'

    def test_a_rewrite_that_adds_a_padding_local_is_not_accepted(self):
        worse = 'int f(int *p)\n{\n    int scratch[4];\n    p[0] = 1;\n    return 0;\n}\n'
        self.assertFalse(search_guard.accept(self.CLEAN, worse))

    def test_a_rewrite_that_adds_inline_asm_is_not_accepted(self):
        worse = 'int f(int *p)\n{\n    asm volatile("lqc2 vf1, 0(%0)" : : "r"(p));\n    return 0;\n}\n'
        self.assertIn('banned', [kind for kind, _ in search_guard.new_findings(self.CLEAN, worse)])

    def test_a_finding_the_current_source_already_has_does_not_block_a_rewrite(self):
        old = 'int f(int *p)\n{\n    int newline = 10;\n    p[0] = newline;\n    p[1] = newline;\n    return 0;\n}\n'
        new = old.replace('p[1] = newline;', 'p[2] = newline;')
        self.assertTrue(search_guard.accept(old, new))

    def test_a_clean_rewrite_is_accepted(self):
        self.assertTrue(search_guard.accept(self.CLEAN, self.CLEAN.replace('p[0] = 1;', 'p[0] = 2;')))

    def test_a_wall_is_skipped_unless_the_environment_says_otherwise(self):
        wall = next(iter(search_guard.table(search_guard.WALLS, 'reason')))
        os.environ.pop('SEARCH_INCLUDE_WALLS', None)
        self.assertTrue(search_guard.skipped(wall).startswith('wall:'))
        os.environ['SEARCH_INCLUDE_WALLS'] = '1'
        try:
            self.assertIsNone(search_guard.skipped(wall))
        finally:
            os.environ.pop('SEARCH_INCLUDE_WALLS')

    def test_a_permanent_blocker_is_skipped(self):
        import csv
        with open(search_guard.BLOCKERS, encoding='utf-8') as handle:
            blocker = int(next(csv.DictReader(handle, delimiter='\t'))['address'], 16)
        self.assertTrue(search_guard.skipped(blocker).startswith('permanent blocker'))

    def test_a_function_whose_source_holds_inline_asm_is_skipped(self):
        import tempfile
        saved = search_guard.LAB
        with tempfile.TemporaryDirectory() as lab:
            folder = os.path.join(lab, 'data', 'matching', 'src', 'fn')
            os.makedirs(folder)
            with open(os.path.join(folder, '000010.cpp'), 'w', encoding='utf-8') as handle:
                handle.write('void f()\n{\n    asm volatile("lqc2 vf1, 0(%0)" : : "r"(0));\n}\n')
            with open(os.path.join(folder, '000020.cpp'), 'w', encoding='utf-8') as handle:
                handle.write('int g(int x)\n{\n    return x + 1;\n}\n')
            search_guard.LAB = lab
            try:
                self.assertTrue(search_guard.banned_source(0x10).startswith('banned construct'))
                self.assertIsNone(search_guard.banned_source(0x20))
                self.assertIsNone(search_guard.banned_source(0x30))
            finally:
                search_guard.LAB = saved

    def test_every_wall_row_has_a_reason_and_evidence(self):
        import csv
        with open(search_guard.WALLS, encoding='utf-8') as handle:
            rows = list(csv.DictReader(handle, delimiter='\t'))
        self.assertTrue(rows and all(row['reason'] and row['evidence'] and row['class'] in ('toolchain', 'tie') for row in rows))


class BoundarySuspectTests(unittest.TestCase):
    BASE = 0x1000
    JR, POP, PUSH, NOP, LW = 0x03E00008, 0x27BD0030, 0x27BDFFD0, 0, 0x8C820244

    def find(self, words, rows):
        return [(name, reason.split(':')[0]) for _, name, _, reason in boundary_suspects.suspects(rows, words, self.BASE)]

    def test_a_function_that_ends_at_jr_before_a_stack_pop_is_a_delay_slot_cut(self):
        words = [self.PUSH] + [self.NOP] * 18 + [self.JR, self.POP, self.NOP, self.JR, self.LW]
        rows = [(self.BASE, 80, 'Cut'), (self.BASE + 80, 16, 'Next')]
        self.assertEqual(self.find(words, rows), [('Cut', 'delay slot cut'), ('Next', 'epilogue tail')])  # the piece after the cut is the epilogue

    def test_an_eight_byte_piece_with_jr_and_a_stack_pop_is_an_epilogue_tail(self):
        words = [self.PUSH, self.NOP, self.JR, self.POP, self.NOP, self.NOP]
        self.assertEqual(self.find(words, [(self.BASE, 8, 'Body'), (self.BASE + 8, 8, 'Tail')]), [('Tail', 'epilogue tail')])

    def test_a_small_getter_is_not_a_suspect(self):
        words = [self.JR, self.LW]
        self.assertEqual(self.find(words, [(self.BASE, 8, 'Getter')]), [])


class DeadConstantOrderTests(unittest.TestCase):
    STORES = ['  a = -1;', '  b = 0;', '  c = -1;', '  d = -60;', '  e = -1;', '  f = -60;', '  g = x;']

    def test_the_last_store_of_a_constant_moves_to_the_front_of_its_group(self):
        first = permute_stores.dead_constant_orders(self.STORES)[0]
        self.assertEqual([first[index] for index in (0, 2, 4)], ['  e = -1;', '  a = -1;', '  c = -1;'])

    def test_stores_of_other_values_and_single_constants_stay_in_place(self):
        for order in permute_stores.dead_constant_orders(self.STORES):
            self.assertEqual((order[1], order[6]), ('  b = 0;', '  g = x;'))

    def test_a_region_without_a_repeated_constant_has_no_candidates(self):
        self.assertEqual(permute_stores.dead_constant_orders(['  a = 1;', '  b = 2;', '  c = x;']), [])

    def test_no_candidate_equals_the_input(self):
        self.assertNotIn(self.STORES, permute_stores.dead_constant_orders(self.STORES))


class ClassifyDiffsTests(unittest.TestCase):
    def test_a_diff_with_no_hunk_is_stale_not_follows(self):
        self.assertEqual(classify_diffs.class_of(0, [], 0), ('stale', ''))

    def test_a_branch_offset_only_hunk_is_follows(self):
        hunk = (['beq $a0, $zero, . + 4 + (0x3 << 2)'], ['beq $a0, $zero, . + 4 + (0x4 << 2)'])
        self.assertEqual(classify_diffs.class_of(2, [hunk], 0)[0], 'follows')

    def test_a_register_only_hunk_is_register(self):
        hunk = (['addu $v0, $a0, $a1'], ['addu $v1, $a0, $a1'])
        self.assertEqual(classify_diffs.class_of(1, [hunk], 0), ('register', 'register'))


class MovablesFlagTests(unittest.TestCase):
    def test_a_listed_function_is_compiled_with_the_flag(self):
        self.assertTrue(compile_unit.movables_for(0x20C0E8))

    def test_an_unlisted_function_is_not(self):
        self.assertFalse(compile_unit.movables_for(0x100000))


class DataDefinitionTests(unittest.TestCase):
    def kinds(self, text):
        return [message for _, _, message in check_source.data_definitions(text)]

    def test_a_marked_scalar_constant_is_allowed(self):
        self.assertEqual(self.kinds('// data-ok: pooled float\nconst float g_x = 1.5f;\n'), [])

    def test_a_definition_without_the_marker_is_banned(self):
        self.assertEqual(len(self.kinds('const float g_x = 1.5f;\n')), 1)

    def test_a_large_typed_table_with_the_marker_is_allowed(self):
        self.assertEqual(self.kinds('// data-ok: table\nconst int g_t[4000] = {0};\n'), [])

    def test_a_long_byte_array_is_banned_as_a_dump(self):
        self.assertIn('a dump, not typed data', self.kinds('// data-ok: bytes\nconst unsigned char g_b[65] = {0};\n')[0])

    def test_an_extern_declaration_and_a_static_constant_are_not_definitions(self):
        self.assertEqual(self.kinds('extern float g_x;\nstatic const float huge = 1.0e30f;\n'), [])

    def test_a_local_with_an_initializer_is_not_a_definition(self):
        self.assertEqual(self.kinds('void f()\n{\n    float a = 1.0f;\n}\n'), [])


if __name__ == '__main__':
    unittest.main()
