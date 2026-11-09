// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BE8D0-0X2BE900 (piece data/hide_183900), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2BE8D0
unsigned int D_002BE8D0[4] = {0, 0x42340000, 0x40900000, 0};

// data-ok: retail's bytes at 0X2BE8E0
unsigned int D_002BE8E0[4] = {0, 0x40f00000, 0x3f400000, 0};

// data-ok: retail's bytes at 0X2BE8F0
unsigned int g_2be8f0[4] = {0, 0, 0xc2480000, 0};
