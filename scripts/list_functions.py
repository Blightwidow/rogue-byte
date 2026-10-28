#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""list_functions.py [--module M] [--status c|asm] [--unnamed] [--min-size N] [--max-size N] [--sort size|address] [--limit N]:
the functions of site/data/report.json (written by `make progress`), to pick the next one to match. Smaller first with --sort size."""
import argparse
import json
import os

ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))

def select(functions, module=None, status=None, unnamed=False, minimum=0, maximum=None, order='address'):
    chosen = [f for f in functions if (module is None or f['module'] == module) and (status is None or f['status'] == status)
              and (not unnamed or not f['named']) and f['size'] >= minimum and (maximum is None or f['size'] <= maximum)]
    return sorted(chosen, key=(lambda f: (f['size'], int(f['address'], 16))) if order == 'size' else (lambda f: int(f['address'], 16)))

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--module')
    parser.add_argument('--status', choices=['c', 'matched', 'draft', 'asm'])
    parser.add_argument('--unnamed', action='store_true')
    parser.add_argument('--min-size', type=int, default=0)
    parser.add_argument('--max-size', type=int)
    parser.add_argument('--sort', choices=['size', 'address'], default='address')
    parser.add_argument('--limit', type=int, default=50)
    arguments = parser.parse_args()
    report = json.load(open(os.path.join(ROOT, 'site', 'data', 'report.json')))
    chosen = select(report['functions'], arguments.module, arguments.status, arguments.unnamed, arguments.min_size, arguments.max_size, arguments.sort)
    for function in chosen[:arguments.limit]:
        print(f"{function['address']:>9} {function['size']:>6} {function['status']:<7} {function['module']:<24} {function['name']}")
    print(f'{min(len(chosen), arguments.limit)} of {len(chosen)} functions')

if __name__ == '__main__':
    main()
