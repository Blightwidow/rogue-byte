// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB380-0X2BB394 (piece data/new_100008), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB36C[];
extern "C" void func_00112820();

// data-ok: retail's bytes at 0X2BB380
void *D_002BB380[5] = {(void *)D_002BB36C, (void *)110, (void *)111, (void *)224, (void *)func_00112820};
