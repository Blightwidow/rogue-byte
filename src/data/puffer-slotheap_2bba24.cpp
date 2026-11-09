// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BBA24-0X2BBA38 (piece data/puffer-slotheap), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB704[];
extern "C" void func_00113930();

// data-ok: retail's bytes at 0X2BBA24
void *D_002BBA24[5] = {(void *)D_002BB704, (void *)195, (void *)196, (void *)64, (void *)func_00113930};
