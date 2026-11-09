// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB0EC-0X2BB100 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAED0[];
extern "C" void func_00111D88();

// data-ok: retail's bytes at 0X2BB0EC
void *D_002BB0EC[5] = {(void *)D_002BAED0, (void *)77, (void *)78, (void *)0x5d0, (void *)func_00111D88};
