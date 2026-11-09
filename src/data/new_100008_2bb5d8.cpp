// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB5D8-0X2BB5EC (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB5B0[];
extern "C" void func_00112E40();

// data-ok: retail's bytes at 0X2BB5D8
void *D_002BB5D8[5] = {(void *)D_002BB5B0, (void *)140, (void *)141, (void *)112, (void *)func_00112E40};
