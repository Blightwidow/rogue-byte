// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB4D4-0X2BB4E8 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB4C0[];
extern "C" void func_00112C10();

// data-ok: retail's bytes at 0X2BB4D4
void *D_002BB4D4[5] = {(void *)D_002BB4C0, (void *)127, (void *)128, (void *)0x120, (void *)func_00112C10};
