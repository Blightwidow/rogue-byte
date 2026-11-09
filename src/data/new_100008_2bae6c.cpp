// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAE6C-0X2BAE80 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_001114E0();

// data-ok: retail's bytes at 0X2BAE6C
void *D_002BAE6C[5] = {(void *)D_002BAB24, (void *)45, (void *)46, (void *)0x130, (void *)func_001114E0};
