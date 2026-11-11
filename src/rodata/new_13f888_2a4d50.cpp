// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A4D50-0X2A4D60 (piece rodata/new_13f888), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A4D50
extern const unsigned int D_002A4D50[2] = {0x6425, 0};

// data-ok: retail's bytes at 0X2A4D58
extern const unsigned int D_002A4D58[2] = {0x6b757061, 0x727543};
