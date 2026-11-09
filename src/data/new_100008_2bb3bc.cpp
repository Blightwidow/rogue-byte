// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB3BC-0X2BB3D0 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB10[];
extern "C" void func_001128C8();

// data-ok: retail's bytes at 0X2BB3BC
void *D_002BB3BC[5] = {(void *)D_002BAB10, (void *)113, (void *)114, (void *)96, (void *)func_001128C8};
