// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB6B4-0X2BB6C8 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAAE8[];

// data-ok: retail's bytes at 0X2BB6B4
void *D_002BB6B4[5] = {(void *)D_002BAAE8, (void *)151, (void *)152, (void *)96, 0};
