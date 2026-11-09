// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB268-0X2BB27C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEA8[];
extern "C" void func_00112370();

// data-ok: retail's bytes at 0X2BB268
void *D_002BB268[5] = {(void *)D_002BAEA8, (void *)96, (void *)97, (void *)0x250, (void *)func_00112370};
