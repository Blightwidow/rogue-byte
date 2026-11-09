// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB40C-0X2BB420 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB10[];
extern "C" void func_001129A8();

// data-ok: retail's bytes at 0X2BB40C
void *D_002BB40C[5] = {(void *)D_002BAB10, (void *)117, (void *)118, (void *)112, (void *)func_001129A8};
