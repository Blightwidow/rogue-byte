// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAEBC-0X2BAED0 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEA8[];
extern "C" void func_001115D0();

// data-ok: retail's bytes at 0X2BAEBC
void *D_002BAEBC[5] = {(void *)D_002BAEA8, (void *)49, (void *)50, (void *)0x150, (void *)func_001115D0};
