// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C1F50-0X2C1F70 (piece data/rip_1cde70), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2C1F50
unsigned int D_002C1F50[4] = {0x3f800000, 0x3fd55558, 0xc02aaaac, 0};

// data-ok: retail's bytes at 0X2C1F60
float g_2c1f60 = 0.5f;

// data-ok: retail's bytes at 0X2C1F64
unsigned int g_2c1f64 = 0x3f000000;

// data-ok: retail's bytes at 0X2C1F68
float g_2c1f68 = 2e+02f;

// data-ok: retail's bytes at 0X2C1F6C
float g_2c1f6c = 0.25f;
