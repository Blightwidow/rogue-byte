// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAF5C-0X2BAF70 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAF48[];
extern "C" void func_001117A8();

// data-ok: retail's bytes at 0X2BAF5C
void *D_002BAF5C[5] = {(void *)D_002BAF48, (void *)57, (void *)58, (void *)0x1010, (void *)func_001117A8};
