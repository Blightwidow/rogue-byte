// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAF0C-0X2BAF20 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEF8[];
extern "C" void NewSly();

// data-ok: retail's bytes at 0X2BAF0C
void *D_002BAF0C[5] = {(void *)D_002BAEF8, (void *)53, (void *)54, (void *)0x2060, (void *)NewSly};
