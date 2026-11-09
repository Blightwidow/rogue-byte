// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB5C4-0X2BB5D8 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB5B0[];
extern "C" void func_00112E08();

// data-ok: retail's bytes at 0X2BB5C4
void *D_002BB5C4[5] = {(void *)D_002BB5B0, (void *)139, (void *)140, (void *)112, (void *)func_00112E08};
