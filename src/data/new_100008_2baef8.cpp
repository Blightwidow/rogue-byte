// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAEF8-0X2BAF0C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEE4[];

// data-ok: retail's bytes at 0X2BAEF8
void *D_002BAEF8[5] = {(void *)D_002BAEE4, (void *)52, (void *)56, (void *)0x1320, 0};
