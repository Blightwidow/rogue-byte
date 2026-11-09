// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB254-0X2BB268 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB1F0[];
extern "C" void func_00112318();

// data-ok: retail's bytes at 0X2BB254
void *D_002BB254[5] = {(void *)D_002BB1F0, (void *)95, (void *)96, (void *)0x230, (void *)func_00112318};
