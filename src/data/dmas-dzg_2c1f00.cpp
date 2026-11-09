// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C1F00-0X2C1F20 (piece data/dmas-dzg_2c1f00), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2C1F00
unsigned int D_002C1F00[4] = {0x4bfd70a4, 0x4bfd70a4, 0x4f7d70a4, 0};

// data-ok: retail's bytes at 0X2C1F10
unsigned int D_002C1F10[4] = {0x50008000, 0x50008000, 0x50400000, 0};
