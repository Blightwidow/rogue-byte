// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB498-0X2BB4AC (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB10[];
extern "C" void func_00112B30();

// data-ok: retail's bytes at 0X2BB498
void *D_002BB498[5] = {(void *)D_002BAB10, (void *)124, (void *)125, (void *)0x160, (void *)func_00112B30};
