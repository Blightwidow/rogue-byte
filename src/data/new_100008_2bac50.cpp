// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAC50-0X2BAC64 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_00110E88();

// data-ok: retail's bytes at 0X2BAC50
void *D_002BAC50[5] = {(void *)D_002BAB24, (void *)18, (void *)20, (void *)0x100, (void *)func_00110E88};
