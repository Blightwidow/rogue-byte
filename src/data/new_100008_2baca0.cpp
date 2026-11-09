// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BACA0-0X2BACB4 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB24[];
extern "C" void func_00110F78();

// data-ok: retail's bytes at 0X2BACA0
void *D_002BACA0[5] = {(void *)D_002BAB24, (void *)22, (void *)28, (void *)0x130, (void *)func_00110F78};
