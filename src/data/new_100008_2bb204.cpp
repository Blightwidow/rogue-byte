// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB204-0X2BB218 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB1F0[];
extern "C" void func_001121B8();

// data-ok: retail's bytes at 0X2BB204
void *D_002BB204[5] = {(void *)D_002BB1F0, (void *)91, (void *)92, (void *)0x240, (void *)func_001121B8};
