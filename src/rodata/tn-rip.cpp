// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A5000-0X2A5010 (piece rodata/tn-rip), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A5000
extern const unsigned int D_002A5000[4] = {0xc2480000, 0, 0, 0};
