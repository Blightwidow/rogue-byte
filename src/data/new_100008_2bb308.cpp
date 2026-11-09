// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB308-0X2BB31C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEA8[];
extern "C" void func_00112630();

// data-ok: retail's bytes at 0X2BB308
void *D_002BB308[5] = {(void *)D_002BAEA8, (void *)104, (void *)105, (void *)0x180, (void *)func_00112630};
