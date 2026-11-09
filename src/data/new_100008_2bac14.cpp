// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAC14-0X2BAC28 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_00110DE0();

// data-ok: retail's bytes at 0X2BAC14
void *D_002BAC14[5] = {(void *)D_002BAB24, (void *)15, (void *)16, (void *)0x1c0, (void *)func_00110DE0};
