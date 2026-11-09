// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB704-0X2BB718 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAAE8[];
extern "C" void func_00113028();

// data-ok: retail's bytes at 0X2BB704
void *D_002BB704[5] = {(void *)D_002BAAE8, (void *)155, (void *)199, (void *)48, (void *)func_00113028};
