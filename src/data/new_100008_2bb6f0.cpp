// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB6F0-0X2BB704 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAAE8[];
extern "C" void func_00112FF0();

// data-ok: retail's bytes at 0X2BB6F0
void *D_002BB6F0[5] = {(void *)D_002BAAE8, (void *)154, (void *)155, (void *)48, (void *)func_00112FF0};
