#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""test_public_tools.py: regression tests for the scripts that need neither the game nor the compiler: `python3 scripts/test_public_tools.py -v`."""
import os
import sys
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path[:0] = [HERE, os.path.join(HERE, 'build'), os.path.join(HERE, 'matching')]

import asm_units  # noqa: E402
import check_cleanup  # noqa: E402
import check_unit  # noqa: E402
import commit_msg  # noqa: E402
import compile_unit  # noqa: E402
import gen_context  # noqa: E402
import export_nonmatching  # noqa: E402
import list_functions  # noqa: E402
import prepare_report  # noqa: E402
import progress_comment  # noqa: E402


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
        self.config = json.load(open(os.path.join(self.ROOT, 'config', 'us', 'categories.json')))
        rows = csv.DictReader(open(os.path.join(self.ROOT, 'config', 'recovered', 'modules.tsv')), delimiter='\t')
        self.modules = {row['module'] for row in rows}

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


if __name__ == '__main__':
    unittest.main()
