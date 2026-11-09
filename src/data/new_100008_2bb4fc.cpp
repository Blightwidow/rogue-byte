// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB4FC-0X2BB510 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB4C0[];
extern "C" void func_00112C90();

// data-ok: retail's bytes at 0X2BB4FC
void *D_002BB4FC[5] = {(void *)D_002BB4C0, (void *)129, (void *)130, (void *)0x220, (void *)func_00112C90};
