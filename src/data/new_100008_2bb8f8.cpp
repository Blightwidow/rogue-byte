// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB8F8-0X2BB90C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB704[];
extern "C" void func_001135B8();

// data-ok: retail's bytes at 0X2BB8F8
void *D_002BB8F8[5] = {(void *)D_002BB704, (void *)180, (void *)181, (void *)64, (void *)func_001135B8};
