// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C0D00-0X2C0D18 (piece data/pipe-steppipe), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2C0D00
float D_002C0D00 = 1.25e+03f;

// data-ok: retail's bytes at 0X2C0D04
unsigned int g_2c0d04 = 0xc2480000;

// data-ok: retail's bytes at 0X2C0D08
float g_2c0d08 = 1.8f;

// data-ok: retail's bytes at 0X2C0D0C
float g_2c0d0c = 25.0f;

// data-ok: retail's bytes at 0X2C0D10
float g_2c0d10[2] = {1.5e+02f, 0.0f};
