// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB77C-0X2BB790 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB768[];
extern "C" void func_00113190();

// data-ok: retail's bytes at 0X2BB77C
void *D_002BB77C[5] = {(void *)D_002BB768, (void *)161, (void *)162, (void *)192, (void *)func_00113190};
