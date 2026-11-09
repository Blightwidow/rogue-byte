// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BABC4-0X2BABD8 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BABB0[];
extern "C" void func_00110CD0();

// data-ok: retail's bytes at 0X2BABC4
void *D_002BABC4[5] = {(void *)D_002BABB0, (void *)11, (void *)12, (void *)0x1e0, (void *)func_00110CD0};
