// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB2E0-0X2BB2F4 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB2B8[];
extern "C" void func_00112580();

// data-ok: retail's bytes at 0X2BB2E0
void *D_002BB2E0[5] = {(void *)D_002BB2B8, (void *)102, (void *)103, (void *)0x1d0, (void *)func_00112580};
