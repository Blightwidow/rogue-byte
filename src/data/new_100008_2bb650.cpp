// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB650-0X2BB664 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAAE8[];
extern "C" void func_00112F80();

// data-ok: retail's bytes at 0X2BB650
void *D_002BB650[5] = {(void *)D_002BAAE8, (void *)146, (void *)147, (void *)64, (void *)func_00112F80};
