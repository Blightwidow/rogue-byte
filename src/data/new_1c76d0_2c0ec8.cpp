// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C0EC8-0X2C10B4 (piece data/new_1c76d0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// TODO: a plain word array over 64 elements is not ruled as typed data yet (docs/contributing/exceptions.md "Game data defined in
// source"); its type is Splat's guess, not recovered from the code that reads it
// data-ok: retail's bytes at 0X2C0EC8
unsigned int D_002C0EC8[72] = {0x200, 0x63c, 0x1a8, 0x200, 0x63d, 0x1ac, 0x200, 0x63e, 0x1b0, 0x200, 0x63f, 0x1b4, 0x200, 0x640, 0x1b8, 0x200, 0x641, 0x1bc, 0x200, 0x642, 0x1c0, 0x200, 0x643, 0x1c4, 0x200, 0x644, 0x1c8, 0x200, 0x646, 0x208, 0x200, 0x647, 0x1cc, 0x200, 0x648, 0x1d0, 0x200, 0x649, 0x1d4, 0x200, 0x64a, 0x1d8, 0x200, 0x64b, 0x1dc, 0x200, 0x64c, 0x1e0, 0x200, 0x64d, 0x1e4, 0x200, 0x64e, 0x1e8, 0x200, 0x64f, 0x1ec, 0, 0x650, 0x210, 0, 0x651, 0x214, 0, 0x652, 0x218, 0, 0x653, 0x21c, 0, 0x654, 0x220};

// data-ok: retail's bytes at 0X2C0FE8
float D_002C0FE8[2] = {0.7f, 0.0f};

// data-ok: retail's bytes at 0X2C0FF0
unsigned int D_002C0FF0[36] = {0xbf333333, 0x3f333333, 0, 0, 0, 0x3f4ccccd, 0, 0, 0x3f333333, 0x3f333333, 0, 0, 0xbf4ccccd, 0, 0, 0, 0, 0, 0, 0, 0x3f4ccccd, 0, 0, 0, 0xbf333333, 0xbf333333, 0, 0, 0, 0xbf4ccccd, 0, 0, 0x3f333333, 0xbf333333, 0, 0};

// data-ok: retail's bytes at 0X2C1080
unsigned int D_002C1080[4] = {0, 0, 0, 0};

// data-ok: retail's bytes at 0X2C1090
unsigned int D_002C1090[4] = {0x42c80000, 0, 0, 0};

// data-ok: retail's bytes at 0X2C10A0
float g_2c10a0 = 1.12e-43f;

// data-ok: retail's bytes at 0X2C10A4
float g_2c10a4 = 1.12e-43f;

// data-ok: retail's bytes at 0X2C10A8
float g_2c10a8 = 4.48e-43f;

// data-ok: retail's bytes at 0X2C10AC
float g_2c10ac = 3.36e-43f;

// data-ok: retail's bytes at 0X2C10B0
float g_2c10b0 = 0.1f;
