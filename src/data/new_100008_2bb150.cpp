// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB150-0X2BB164 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB128[];
extern "C" void func_00111F48();

// data-ok: retail's bytes at 0X2BB150
void *D_002BB150[5] = {(void *)D_002BB128, (void *)82, (void *)83, (void *)0x290, (void *)func_00111F48};
