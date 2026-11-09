// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB04C-0X2BB060 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAED0[];
extern "C" void func_00111AC0();

// data-ok: retail's bytes at 0X2BB04C
void *D_002BB04C[5] = {(void *)D_002BAED0, (void *)69, (void *)70, (void *)0x1e0, (void *)func_00111AC0};
