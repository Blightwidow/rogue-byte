#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""test_public_tools.py: regression tests for the scripts that need neither the game nor the compiler: `python3 scripts/test_public_tools.py -v`."""
import os
import sys
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path[:0] = [HERE, os.path.join(HERE, 'build'), os.path.join(HERE, 'matching'), os.path.join(HERE, 'vu')]
sys.path.insert(0, os.path.join(HERE, 'build'))

import asm_units  # noqa: E402
import check_cleanup  # noqa: E402
import check_unit  # noqa: E402
import commit_msg  # noqa: E402
import boundaries  # noqa: E402
import compile_unit  # noqa: E402
import credit_audit  # noqa: E402
import gen_context  # noqa: E402
import harvest  # noqa: E402
import export_nonmatching  # noqa: E402
import list_functions  # noqa: E402
import idioms  # noqa: E402
import mutate  # noqa: E402
import neighborhood  # noqa: E402
import permute  # noqa: E402
import rules  # noqa: E402
import prologue_profile  # noqa: E402
import prepare_report  # noqa: E402
import progress_comment  # noqa: E402
import vuasm  # noqa: E402
import vudis  # noqa: E402


class CommitMessageTests(unittest.TestCase):
    def test_accepts_type_and_summary(self):
        self.assertEqual(commit_msg.check('names: recover 40 names in step-rwm\n\nbody'), [])

    def test_rejects_unknown_type(self):
        self.assertTrue(commit_msg.check('feat: add a thing'))

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

    def test_gnu_list_is_read(self):
        listed = compile_unit.gnu_functions() - compile_unit.loop5_functions()
        self.assertTrue(all(isinstance(address, int) for address in listed))
        if listed:
            self.assertEqual(compile_unit.assembler_for(next(iter(listed))), 'gnu')
        self.assertIsNone(compile_unit.assembler_for(0xDEADBEEF))

    def test_loop5_list_wins_over_the_gnu_list(self):
        listed = compile_unit.loop5_functions()
        self.assertTrue(all(isinstance(address, int) for address in listed))
        if listed:
            self.assertEqual(compile_unit.assembler_for(next(iter(listed))), 'ps2eeas-loop5')

    def test_sony_list_wins_over_every_other_list(self):
        listed = compile_unit.sony_functions()
        self.assertTrue(all(isinstance(address, int) for address in listed))
        if listed:
            self.assertEqual(compile_unit.assembler_for(next(iter(listed))), 'sony29')



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


class ProgressCommentTests(unittest.TestCase):
    GAME = {'functions': 10, 'bytes': 1000, 'named': 4, 'c_functions': 2, 'c_bytes': 200}

    def test_valid_summary_has_no_problems(self):
        self.assertEqual(progress_comment.validate({'game_code': self.GAME}), [])

    def test_missing_field_is_reported(self):
        self.assertEqual(len(progress_comment.validate({'game_code': {**self.GAME, 'c_bytes': None}})), 1)

    def test_comment_shows_the_change(self):
        head = {'game_code': {**self.GAME, 'c_functions': 5, 'c_bytes': 500}}
        comment = progress_comment.render({'game_code': self.GAME}, head)
        self.assertIn('20.00% | 50.00%', comment)
        self.assertIn('5 (+3)', comment)
        self.assertTrue(comment.startswith(progress_comment.MARKER))


class ContextTests(unittest.TestCase):
    LINES = ['    /* 0 00100000 0C000000 */  jal        Callee\n',
             '    /* 4 00100004 2A00023C */  lui        $v0, %hi(D_00200010)\n',
             '    /* 8 00100008 10004224 */  addiu      $v0, $v0, %lo(D_00200010 + 0x4)\n',
             '    /* C 0010000C 0800E003 */  jr         $ra\n']

    def test_parse_finds_calls_and_data_references(self):
        calls, references = gen_context.parse_function(self.LINES)
        self.assertEqual(calls, ['Callee'])
        self.assertEqual(references, [('D_00200010', 0), ('D_00200010', 4)])

    def test_prose_and_numbers_are_not_published(self):
        self.assertIsNone(gen_context.readable('Press START to continue'))
        self.assertIsNone(gen_context.readable('12345'))
        self.assertEqual(gen_context.readable('episodeBest'), 'episodeBest')

    def test_string_reader_reads_text_only(self):
        image = b'\0' * 0x80 + b'loot\0\xff\xfe\0'
        read = gen_context.string_reader(image)
        self.assertEqual(read(0x100000), 'loot')
        self.assertIsNone(read(0x100005))
        self.assertIsNone(read(0x90000000))

    def test_context_links_callers_callees_and_strings(self):
        functions = [{'address': 0x100000, 'name': 'Caller', 'lines': self.LINES},
                     {'address': 0x100100, 'name': 'Callee', 'lines': ['    /* 0 00100100 0800E003 */  jr         $ra\n']}]
        image = b'\0' * 0x100094 + b'hero\0'  # the string sits at address 0x200014 = D_00200010 + 4
        context = gen_context.build_context(functions, gen_context.string_reader(image), {}, {0x100000: 'sly1'})
        self.assertEqual(context['0X100000']['callees'], ['0X100100'])
        self.assertEqual(context['0X100100']['callers'], ['0X100000'])
        self.assertEqual(context['0X100000']['origin'], 'sly1')
        self.assertEqual(context['0X100000']['strings'], ['hero'])


class PrepareReportTests(unittest.TestCase):
    GOOD = {'measures': {'total_code': '100', 'matched_code': '40', 'total_functions': 10, 'matched_functions': 4}, 'units': [{'name': 'a'}]}

    def test_good_report_has_no_problems(self):
        self.assertEqual(prepare_report.problems(self.GOOD), [])

    def test_missing_measure_is_reported(self):
        bad = {**self.GOOD, 'measures': {'total_code': '100'}}
        self.assertEqual(len(prepare_report.problems(bad)), 3)

    def test_matched_over_total_is_reported(self):
        bad = {**self.GOOD, 'measures': {**self.GOOD['measures'], 'matched_code': '400'}}
        self.assertTrue(prepare_report.problems(bad))

    def test_no_units_is_reported(self):
        self.assertEqual(prepare_report.problems({**self.GOOD, 'units': []}), ['no units'])


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


if __name__ == '__main__':
    unittest.main()
