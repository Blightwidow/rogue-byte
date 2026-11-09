// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BD4C4-0X2BD4E0 (piece data/button-cd), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2BD4C4
unsigned int g_2bd4c4[7] = {0xffffffff, 0x8000, 8, 0x1000, 0x4000, 0x1000, 0x8000};
