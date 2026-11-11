// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A8A98-0X2A8AA8 (piece rodata/po-screen), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A8A98
extern const unsigned int D_002A8A98[2] = {0, 0};

// data-ok: retail's bytes at 0X2A8AA0
extern const unsigned int D_002A8AA0[2] = {0x6425, 0};
