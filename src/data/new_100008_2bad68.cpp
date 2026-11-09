// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAD68-0X2BAD7C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAD40[];
extern "C" void func_001111A8();

// data-ok: retail's bytes at 0X2BAD68
void *D_002BAD68[5] = {(void *)D_002BAD40, (void *)32, (void *)34, (void *)240, (void *)func_001111A8};
