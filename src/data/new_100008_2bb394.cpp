// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB394-0X2BB3A8 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB10[];
extern "C" void func_00112858();

// data-ok: retail's bytes at 0X2BB394
void *D_002BB394[5] = {(void *)D_002BAB10, (void *)111, (void *)112, (void *)128, (void *)func_00112858};
