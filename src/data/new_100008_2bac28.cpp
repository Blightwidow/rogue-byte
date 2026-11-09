// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAC28-0X2BAC3C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_00110E18();

// data-ok: retail's bytes at 0X2BAC28
void *D_002BAC28[5] = {(void *)D_002BAB24, (void *)16, (void *)17, (void *)0x180, (void *)func_00110E18};
