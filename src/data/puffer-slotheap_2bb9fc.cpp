// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB9FC-0X2BBA10 (piece data/puffer-slotheap), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB704[];
extern "C" void func_001138C0();

// data-ok: retail's bytes at 0X2BB9FC
void *D_002BB9FC[5] = {(void *)D_002BB704, (void *)193, (void *)194, (void *)80, (void *)func_001138C0};
