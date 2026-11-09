// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB7F4-0X2BB808 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB7E0[];
extern "C" void func_001132E0();

// data-ok: retail's bytes at 0X2BB7F4
void *D_002BB7F4[5] = {(void *)D_002BB7E0, (void *)167, (void *)168, (void *)240, (void *)func_001132E0};
