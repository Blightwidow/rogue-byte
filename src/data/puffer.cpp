// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB948-0X2BB95C (piece data/puffer), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB704[];
extern "C" void func_00113698();

// data-ok: retail's bytes at 0X2BB948
void *D_002BB948[5] = {(void *)D_002BB704, (void *)184, (void *)185, (void *)64, (void *)func_00113698};
