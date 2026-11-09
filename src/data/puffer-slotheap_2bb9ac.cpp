// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB9AC-0X2BB9C0 (piece data/puffer-slotheap), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB704[];
extern "C" void func_001137D0();

// data-ok: retail's bytes at 0X2BB9AC
void *D_002BB9AC[5] = {(void *)D_002BB704, (void *)189, (void *)190, (void *)80, (void *)func_001137D0};
