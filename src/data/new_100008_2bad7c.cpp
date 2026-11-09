// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAD7C-0X2BAD90 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAD68[];
extern "C" void func_001111E0();

// data-ok: retail's bytes at 0X2BAD7C
void *D_002BAD7C[5] = {(void *)D_002BAD68, (void *)33, (void *)34, (void *)0x110, (void *)func_001111E0};
