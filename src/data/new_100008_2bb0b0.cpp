// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB0B0-0X2BB0C4 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB074[];
extern "C" void func_00111C80();

// data-ok: retail's bytes at 0X2BB0B0
void *D_002BB0B0[5] = {(void *)D_002BB074, (void *)74, (void *)75, (void *)0x1e0, (void *)func_00111C80};
