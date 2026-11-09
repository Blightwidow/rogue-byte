// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB240-0X2BB254 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB1F0[];
extern "C" void func_001122C0();

// data-ok: retail's bytes at 0X2BB240
void *D_002BB240[5] = {(void *)D_002BB1F0, (void *)94, (void *)95, (void *)0x250, (void *)func_001122C0};
