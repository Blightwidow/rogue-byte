// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A2DF0-0X2A2E50 (piece rodata/util-splice-bif), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A2DF0
extern const unsigned int D_002A2DF0[4] = {0x7f7fffff, 0x7f7fffff, 0x7f7fffff, 0};

// data-ok: retail's bytes at 0X2A2E00
extern const unsigned int D_002A2E00[4] = {0xff7fffff, 0xff7fffff, 0xff7fffff, 0};

// data-ok: retail's bytes at 0X2A2E10
extern const unsigned int g_2a2e10[4] = {0, 0, 0, 0};

// data-ok: retail's bytes at 0X2A2E20
extern const unsigned int g_2a2e20[12] = {0x3f800000, 0x3f800000, 0x3f800000, 0x3f800000, 0x7f7fffff, 0x7f7fffff, 0x7f7fffff, 0x7f7fffff, 0xff7fffff, 0xff7fffff, 0xff7fffff, 0xff7fffff};
