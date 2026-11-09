// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB010-0X2BB024 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAF48[];
extern "C" void func_001119E8();

// data-ok: retail's bytes at 0X2BB010
void *D_002BB010[5] = {(void *)D_002BAF48, (void *)66, (void *)67, (void *)0x1010, (void *)func_001119E8};
