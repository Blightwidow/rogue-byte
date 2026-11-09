// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CE488-0X2CE4A0 (piece data/dmas), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void func_00157798();

// data-ok: retail's bytes at 0X2CE488
void *D_002CE488[6] = {0, 0, 0, (void *)func_00157798, 0, 0};
