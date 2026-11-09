// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB0C4-0X2BB0D8 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB074[];
extern "C" void func_00111CD8();

// data-ok: retail's bytes at 0X2BB0C4
void *D_002BB0C4[5] = {(void *)D_002BB074, (void *)75, (void *)76, (void *)0x250, (void *)func_00111CD8};
