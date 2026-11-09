// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BFA00-0X2BFA30 (piece data/jp-stepzap), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2BFA00
unsigned int D_002BFA00[4] = {0, 0, 0xc43b8000, 0};

// data-ok: retail's bytes at 0X2BFA10
unsigned int D_002BFA10[4] = {0, 0, 0x43fa0000, 0};

// data-ok: retail's bytes at 0X2BFA20
float D_002BFA20[4] = {-1.0f, 0.004f, 0.0f, 0.0f};
