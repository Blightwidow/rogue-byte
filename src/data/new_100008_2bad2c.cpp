// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAD2C-0X2BAD40 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_00111138();

// data-ok: retail's bytes at 0X2BAD2C
void *D_002BAD2C[5] = {(void *)D_002BAB24, (void *)29, (void *)30, (void *)0x160, (void *)func_00111138};
