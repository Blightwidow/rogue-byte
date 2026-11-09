// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAD90-0X2BADA4 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_00111218();

// data-ok: retail's bytes at 0X2BAD90
void *D_002BAD90[5] = {(void *)D_002BAB24, (void *)34, (void *)35, (void *)0x110, (void *)func_00111218};
