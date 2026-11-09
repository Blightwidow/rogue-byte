// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB5EC-0X2BB600 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB5B0[];
extern "C" void func_00112E78();

// data-ok: retail's bytes at 0X2BB5EC
void *D_002BB5EC[5] = {(void *)D_002BB5B0, (void *)141, (void *)142, (void *)96, (void *)func_00112E78};
