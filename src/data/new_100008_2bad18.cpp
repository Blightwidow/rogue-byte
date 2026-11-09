// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAD18-0X2BAD2C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_001110D8();

// data-ok: retail's bytes at 0X2BAD18
void *D_002BAD18[5] = {(void *)D_002BAB24, (void *)28, (void *)29, (void *)0x460, (void *)func_001110D8};
