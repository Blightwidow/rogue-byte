// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BABD8-0X2BABEC (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BABB0[];
extern "C" void func_00110D18();

// data-ok: retail's bytes at 0X2BABD8
void *D_002BABD8[5] = {(void *)D_002BABB0, (void *)12, (void *)13, (void *)0x1c0, (void *)func_00110D18};
