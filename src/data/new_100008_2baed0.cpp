// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAED0-0X2BAEE4 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEA8[];
extern "C" void func_00111628();

// data-ok: retail's bytes at 0X2BAED0
void *D_002BAED0[5] = {(void *)D_002BAEA8, (void *)50, (void *)79, (void *)0x180, (void *)func_00111628};
