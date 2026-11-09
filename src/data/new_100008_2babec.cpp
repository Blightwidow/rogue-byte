// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BABEC-0X2BAC00 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BABB0[];
extern "C" void func_00110D60();

// data-ok: retail's bytes at 0X2BABEC
void *D_002BABEC[5] = {(void *)D_002BABB0, (void *)13, (void *)14, (void *)0x1d0, (void *)func_00110D60};
