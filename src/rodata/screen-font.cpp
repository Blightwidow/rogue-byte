// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A3A10-0X2A3A30 (piece rodata/screen-font), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A3A10
extern const unsigned int D_002A3A10[8] = {0x3f800000, 0, 0, 0x3f800000, 0, 0, 0, 0};
