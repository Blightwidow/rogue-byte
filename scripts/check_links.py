#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""check_links.py: every relative link in the tracked markdown files points at a file that exists."""
import os
import re
import subprocess
import sys

broken = 0
for path in subprocess.check_output(['git', 'ls-files', '*.md'], text=True).split():
    if not os.path.isfile(path):
        continue
    for target in re.findall(r'\]\(([^)#\s]+)(?:#[^)]*)?\)', open(path).read()):
        if re.match(r'(https?:|mailto:)', target):
            continue
        if not os.path.exists(os.path.normpath(os.path.join(os.path.dirname(path), target))):
            print(f'{path}: broken link {target}')
            broken += 1
sys.exit(1 if broken else 0)
