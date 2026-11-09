// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BACB4-0X2BACC8 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BACA0[];
extern "C" void func_00110FB0();

// data-ok: retail's bytes at 0X2BACB4
void *D_002BACB4[5] = {(void *)D_002BACA0, (void *)23, (void *)24, (void *)0x140, (void *)func_00110FB0};
