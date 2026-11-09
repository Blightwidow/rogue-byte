// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB68C-0X2BB6A0 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB678[];

// data-ok: retail's bytes at 0X2BB68C
void *D_002BB68C[5] = {(void *)D_002BB678, (void *)149, (void *)150, (void *)48, 0};
