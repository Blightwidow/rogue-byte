// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAB10-0X2BAB24 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAAE8[];
extern "C" void func_00110AD8();

// data-ok: retail's bytes at 0X2BAB10
void *D_002BAB10[5] = {(void *)D_002BAAE8, (void *)2, (void *)134, (void *)80, (void *)func_00110AD8};
