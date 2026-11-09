// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BDD20-0X2BDD8C (piece data/dmas-dzg), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void func_0016E1A8();

// data-ok: retail's bytes at 0X2BDD20
unsigned int D_002BDD20[26] = {4, 3, 0, 0, 11, 0, 11, 6, 7, 1, 0, 0, 2, 0, 0, 8, 0, 1, 9, 0, 1, 5, 10, 0, 1, 0};

// data-ok: retail's bytes at 0X2BDD88
void *D_002BDD88 = (void *)func_0016E1A8;
