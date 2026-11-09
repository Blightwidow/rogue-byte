// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB2F4-0X2BB308 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEA8[];
extern "C" void func_001125D8();

// data-ok: retail's bytes at 0X2BB2F4
void *D_002BB2F4[5] = {(void *)D_002BAEA8, (void *)103, (void *)104, (void *)0x190, (void *)func_001125D8};
