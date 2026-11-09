// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB13C-0X2BB150 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB128[];
extern "C" void func_00111EF0();

// data-ok: retail's bytes at 0X2BB13C
void *D_002BB13C[5] = {(void *)D_002BB128, (void *)81, (void *)82, (void *)0x280, (void *)func_00111EF0};
