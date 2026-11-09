// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB6A0-0X2BB6B4 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB678[];

// data-ok: retail's bytes at 0X2BB6A0
void *D_002BB6A0[5] = {(void *)D_002BB678, (void *)150, (void *)151, (void *)48, 0};
