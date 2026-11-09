// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB36C-0X2BB380 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB10[];
extern "C" void func_001127E8();

// data-ok: retail's bytes at 0X2BB36C
void *D_002BB36C[5] = {(void *)D_002BAB10, (void *)109, (void *)111, (void *)192, (void *)func_001127E8};
