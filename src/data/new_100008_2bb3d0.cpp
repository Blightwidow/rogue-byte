// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB3D0-0X2BB3E4 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BAB10[];
extern "C" void func_00112900();

// data-ok: retail's bytes at 0X2BB3D0
void *D_002BB3D0[5] = {(void *)D_002BAB10, (void *)114, (void *)115, (void *)176, (void *)func_00112900};
