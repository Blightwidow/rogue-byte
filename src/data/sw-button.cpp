// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C3E70-0X2C3EA0 (piece data/sw-button), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2C3E70
unsigned int D_002C3E70[4] = {0x371, 0x36d, 0x36e, 0x36f};

// data-ok: retail's bytes at 0X2C3E80
float D_002C3E80[2] = {65.0f, 0.0f};

// data-ok: retail's bytes at 0X2C3E88
unsigned int D_002C3E88[6] = {0x43fa0000, 0, 0x3e800000, 0x451c4000, 0, 0};
