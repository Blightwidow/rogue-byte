// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB664-0X2BB678 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAAE8[];

// data-ok: retail's bytes at 0X2BB664
void *D_002BB664[5] = {(void *)D_002BAAE8, (void *)147, (void *)148, (void *)96, 0};
