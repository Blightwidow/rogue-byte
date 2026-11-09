// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB9C0-0X2BB9D4 (piece data/puffer-slotheap), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB704[];
extern "C" void func_00113808();

// data-ok: retail's bytes at 0X2BB9C0
void *D_002BB9C0[5] = {(void *)D_002BB704, (void *)190, (void *)191, (void *)80, (void *)func_00113808};
