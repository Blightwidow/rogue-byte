// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB2CC-0X2BB2E0 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB2B8[];
extern "C" void func_00112528();

// data-ok: retail's bytes at 0X2BB2CC
void *D_002BB2CC[5] = {(void *)D_002BB2B8, (void *)101, (void *)102, (void *)0x1b0, (void *)func_00112528};
