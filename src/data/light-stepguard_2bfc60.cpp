// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BFC60-0X2BFC94 (piece data/light-stepguard), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2BFC60
unsigned int D_002BFC60[12] = {0, 0, 0x3f000000, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BFC90
float g_2bfc90 = 1e+03f;
