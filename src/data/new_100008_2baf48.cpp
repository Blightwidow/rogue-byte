// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BAF48-0X2BAF5C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEE4[];
extern "C" void NewGuard();

// data-ok: retail's bytes at 0X2BAF48
void *D_002BAF48[5] = {(void *)D_002BAEE4, (void *)56, (void *)68, (void *)0x1010, (void *)NewGuard};
