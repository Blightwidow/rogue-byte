// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X27A778-0X27A790 (piece rodata/puffer-slotheap), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_0029A7C0[];

// data-ok: retail's bytes at 0X27A778
extern void *const D_0027A778[6] = {(void *)0x65f, (void *)2, (void *)0x10010, (void *)D_0029A7C0, 0, 0};
