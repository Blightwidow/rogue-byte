// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB128-0X2BB13C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB114[];
extern "C" void func_00111E98();

// data-ok: retail's bytes at 0X2BB128
void *D_002BB128[5] = {(void *)D_002BB114, (void *)80, (void *)83, (void *)0x270, (void *)func_00111E98};
