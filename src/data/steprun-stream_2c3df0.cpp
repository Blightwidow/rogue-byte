// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C3DF0-0X2C3E60 (piece data/steprun-stream), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2C3DF0
float D_002C3DF0[4] = {0.1f, 0.0f, 0.0f, 0.0f};

// data-ok: retail's bytes at 0X2C3E00
unsigned int D_002C3E00[20] = {0, 0, 0, 0, 0x42c80000, 0, 0, 0, 0xc2c80000, 0, 0, 0, 0, 0x42c80000, 0, 0, 0, 0xc2c80000, 0, 0};

// data-ok: retail's bytes at 0X2C3E50
float g_2c3e50 = 1e+02f;

// data-ok: retail's bytes at 0X2C3E54
float g_2c3e54 = -6e+02f;

// data-ok: retail's bytes at 0X2C3E58
float D_002C3E58[2] = {0.0f, 0.0f};
