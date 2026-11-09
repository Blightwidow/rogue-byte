// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAB38-0X2BAB4C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_00110B48();

// data-ok: retail's bytes at 0X2BAB38
void *D_002BAB38[5] = {(void *)D_002BAB24, (void *)4, (void *)5, (void *)0x170, (void *)func_00110B48};
