// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAFAC-0X2BAFC0 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAF48[];
extern "C" void func_001118A8();

// data-ok: retail's bytes at 0X2BAFAC
void *D_002BAFAC[5] = {(void *)D_002BAF48, (void *)61, (void *)62, (void *)0x1020, (void *)func_001118A8};
