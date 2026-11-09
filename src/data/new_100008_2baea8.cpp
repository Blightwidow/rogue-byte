// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAEA8-0X2BAEBC (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB10[];
extern "C" void func_00111588();

// data-ok: retail's bytes at 0X2BAEA8
void *D_002BAEA8[5] = {(void *)D_002BAB10, (void *)48, (void *)109, (void *)0x150, (void *)func_00111588};
