// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB074-0X2BB088 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAED0[];
extern "C" void func_00111B70();

// data-ok: retail's bytes at 0X2BB074
void *D_002BB074[5] = {(void *)D_002BAED0, (void *)71, (void *)77, (void *)0x1c0, (void *)func_00111B70};
