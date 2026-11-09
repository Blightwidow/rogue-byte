// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB614-0X2BB628 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB5B0[];
extern "C" void func_00112EE8();

// data-ok: retail's bytes at 0X2BB614
void *D_002BB614[5] = {(void *)D_002BB5B0, (void *)143, (void *)144, (void *)112, (void *)func_00112EE8};
