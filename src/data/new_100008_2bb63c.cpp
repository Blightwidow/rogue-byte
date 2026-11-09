// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB63C-0X2BB650 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAAE8[];
extern "C" void func_00112F58();

// data-ok: retail's bytes at 0X2BB63C
void *D_002BB63C[5] = {(void *)D_002BAAE8, (void *)145, (void *)146, (void *)112, (void *)func_00112F58};
