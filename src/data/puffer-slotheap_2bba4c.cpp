// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BBA4C-0X2BBA60 (piece data/puffer-slotheap), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB704[];
extern "C" void func_001139A0();

// data-ok: retail's bytes at 0X2BBA4C
void *D_002BBA4C[5] = {(void *)D_002BB704, (void *)197, (void *)198, (void *)64, (void *)func_001139A0};
