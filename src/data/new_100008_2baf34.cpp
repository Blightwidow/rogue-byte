// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAF34-0X2BAF48 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEF8[];
extern "C" void func_00111728();

// data-ok: retail's bytes at 0X2BAF34
void *D_002BAF34[5] = {(void *)D_002BAEF8, (void *)55, (void *)56, (void *)0x1880, (void *)func_00111728};
