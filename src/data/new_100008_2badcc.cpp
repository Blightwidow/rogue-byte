// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BADCC-0X2BADE0 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BADA4[];
extern "C" void func_001112F0();

// data-ok: retail's bytes at 0X2BADCC
void *D_002BADCC[5] = {(void *)D_002BADA4, (void *)37, (void *)38, (void *)0x1a0, (void *)func_001112F0};
