// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB808-0X2BB81C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB7E0[];
extern "C" void func_00113318();

// data-ok: retail's bytes at 0X2BB808
void *D_002BB808[5] = {(void *)D_002BB7E0, (void *)168, (void *)169, (void *)224, (void *)func_00113318};
