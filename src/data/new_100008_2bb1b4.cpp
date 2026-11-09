// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB1B4-0X2BB1C8 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEA8[];
extern "C" void func_001120A8();

// data-ok: retail's bytes at 0X2BB1B4
void *D_002BB1B4[5] = {(void *)D_002BAEA8, (void *)87, (void *)88, (void *)0x1b0, (void *)func_001120A8};
