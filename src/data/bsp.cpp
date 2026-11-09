// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BBB10-0X2BBB50 (piece data/bsp), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BBAF0[];

// data-ok: retail's bytes at 0X2BBB10
unsigned int D_002BBB10[4] = {0, 0, 0x2bbad0, 0};

// data-ok: retail's bytes at 0X2BBB20
void *D_002BBB20[12] = {0, 0, (void *)D_002BBAF0, 0, 0, 0, (void *)0xbf800000, 0, 0, 0, 0, 0};
