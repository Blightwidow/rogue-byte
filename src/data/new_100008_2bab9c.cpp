// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAB9C-0X2BABB0 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB88[];
extern "C" void func_00110C60();

// data-ok: retail's bytes at 0X2BAB9C
void *D_002BAB9C[5] = {(void *)D_002BAB88, (void *)9, (void *)10, (void *)0x120, (void *)func_00110C60};
