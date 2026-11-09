// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAC78-0X2BAC8C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_00110F08();

// data-ok: retail's bytes at 0X2BAC78
void *D_002BAC78[5] = {(void *)D_002BAB24, (void *)20, (void *)21, (void *)240, (void *)func_00110F08};
