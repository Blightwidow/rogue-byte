// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAF84-0X2BAF98 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAF70[];
extern "C" void func_00111828();

// data-ok: retail's bytes at 0X2BAF84
void *D_002BAF84[5] = {(void *)D_002BAF70, (void *)59, (void *)60, (void *)0x1020, (void *)func_00111828};
