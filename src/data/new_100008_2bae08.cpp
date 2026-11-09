// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAE08-0X2BAE1C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_001113C8();

// data-ok: retail's bytes at 0X2BAE08
void *D_002BAE08[5] = {(void *)D_002BAB24, (void *)40, (void *)41, (void *)240, (void *)func_001113C8};
