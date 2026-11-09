// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BACF0-0X2BAD04 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BACA0[];
extern "C" void func_00111058();

// data-ok: retail's bytes at 0X2BACF0
void *D_002BACF0[5] = {(void *)D_002BACA0, (void *)26, (void *)27, (void *)0x190, (void *)func_00111058};
