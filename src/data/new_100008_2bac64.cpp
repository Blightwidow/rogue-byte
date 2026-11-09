// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAC64-0X2BAC78 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAC50[];
extern "C" void func_00110EC0();

// data-ok: retail's bytes at 0X2BAC64
void *D_002BAC64[5] = {(void *)D_002BAC50, (void *)19, (void *)20, (void *)0x140, (void *)func_00110EC0};
