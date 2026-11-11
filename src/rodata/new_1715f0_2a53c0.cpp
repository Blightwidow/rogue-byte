// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A53C0-0X2A53D4 (piece rodata/new_1715f0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A53C0
extern const unsigned int D_002A53C0[2] = {0x43480000, 0x44960000};

// data-ok: retail's bytes at 0X2A53C8
extern const unsigned int D_002A53C8[2] = {0xbf490fdb, 0x3f490fdb};

// data-ok: retail's bytes at 0X2A53D0
extern const float D_002A53D0 = -3.4028235e+38f;
