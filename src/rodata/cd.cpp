// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A2E50-0X2A2E68 (piece rodata/cd), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A2E50
extern const unsigned int D_002A2E50[2] = {127, 0};

// data-ok: retail's bytes at 0X2A2E58
extern const unsigned int D_002A2E58 = 0x17f;

// data-ok: retail's bytes at 0X2A2E5C
extern const unsigned int g_2a2e5c = 0x132aa3;

// data-ok: retail's bytes at 0X2A2E60
extern const unsigned int g_2a2e60[2] = {0xacdd3ee4, 0};
