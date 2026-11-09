// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BACDC-0X2BACF0 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BACC8[];
extern "C" void func_00111020();

// data-ok: retail's bytes at 0X2BACDC
void *D_002BACDC[5] = {(void *)D_002BACC8, (void *)25, (void *)26, (void *)0x2d0, (void *)func_00111020};
