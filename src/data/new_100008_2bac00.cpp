// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAC00-0X2BAC14 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BABB0[];
extern "C" void func_00110DA8();

// data-ok: retail's bytes at 0X2BAC00
void *D_002BAC00[5] = {(void *)D_002BABB0, (void *)14, (void *)15, (void *)0x1f0, (void *)func_00110DA8};
