// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB038-0X2BB04C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAEE4[];
extern "C" void func_00111A68();

// data-ok: retail's bytes at 0X2BB038
void *D_002BB038[5] = {(void *)D_002BAEE4, (void *)68, (void *)69, (void *)0x410, (void *)func_00111A68};
