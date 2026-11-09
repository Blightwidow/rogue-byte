// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAD40-0X2BAD54 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];

// data-ok: retail's bytes at 0X2BAD40
void *D_002BAD40[5] = {(void *)D_002BAB24, (void *)30, (void *)34, (void *)224, 0};
