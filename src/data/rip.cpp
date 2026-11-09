// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BDAB0-0X2BDACC (piece data/rip), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2BDAB0
unsigned int D_002BDAB0[4] = {0x40a00000, 0, 0x3f000000, 0};

// data-ok: retail's bytes at 0X2BDAC0
unsigned int D_002BDAC0[3] = {0x44fa0000, 0, 0x3f800000};
