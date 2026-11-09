// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BB998-0X2BB9AC (piece data/puffer-slotheap), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BB704[];
extern "C" void func_00113798();

// data-ok: retail's bytes at 0X2BB998
void *D_002BB998[5] = {(void *)D_002BB704, (void *)188, (void *)189, (void *)48, (void *)func_00113798};
