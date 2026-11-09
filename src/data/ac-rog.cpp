// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C0248-0X2C0268 (piece data/ac-rog), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2C0248
unsigned int D_002C0248[4] = {0x41c80000, 0, 0x3e800000, 0};

// data-ok: retail's bytes at 0X2C0258
unsigned int D_002C0258[4] = {0x100, 123, 0x230, 0};
