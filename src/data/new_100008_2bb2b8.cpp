// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB2B8-0X2BB2CC (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEA8[];
extern "C" void func_001124D0();

// data-ok: retail's bytes at 0X2BB2B8
void *D_002BB2B8[5] = {(void *)D_002BAEA8, (void *)100, (void *)103, (void *)0x1b0, (void *)func_001124D0};
