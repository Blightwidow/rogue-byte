// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAB4C-0X2BAB60 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_00110B80();

// data-ok: retail's bytes at 0X2BAB4C
void *D_002BAB4C[5] = {(void *)D_002BAB24, (void *)5, (void *)6, (void *)0x120, (void *)func_00110B80};
