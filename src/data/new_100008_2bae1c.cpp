// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAE1C-0X2BAE30 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_00111400();

// data-ok: retail's bytes at 0X2BAE1C
void *D_002BAE1C[5] = {(void *)D_002BAB24, (void *)41, (void *)42, (void *)224, (void *)func_00111400};
