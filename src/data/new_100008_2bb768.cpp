// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB768-0X2BB77C (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB72C[];
extern "C" void func_00113158();

// data-ok: retail's bytes at 0X2BB768
void *D_002BB768[5] = {(void *)D_002BB72C, (void *)160, (void *)164, (void *)192, (void *)func_00113158};
