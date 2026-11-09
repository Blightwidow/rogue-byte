// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB1A0-0X2BB1B4 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEA8[];
extern "C" void func_00112050();

// data-ok: retail's bytes at 0X2BB1A0
void *D_002BB1A0[5] = {(void *)D_002BAEA8, (void *)86, (void *)87, (void *)0x180, (void *)func_00112050};
