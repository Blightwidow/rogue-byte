// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BBB50-0X2BBB68 (piece data/rip_1cf0a0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2BBB50
unsigned int D_002BBB50[4] = {0x3f800000, 0, 0, 0};

// data-ok: retail's bytes at 0X2BBB60
float g_2bbb60 = 0.0f;

// data-ok: retail's bytes at 0X2BBB64
unsigned int g_2bbb64 = 0x3f800000;
