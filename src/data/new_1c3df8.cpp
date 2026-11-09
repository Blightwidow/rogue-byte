// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C0D18-0X2C0D60 (piece data/new_1c3df8), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char g_2dd5bc[];
extern char g_2e1e40[];
extern char g_2f7900[];

// data-ok: retail's bytes at 0X2C0D18
unsigned int D_002C0D18[4] = {0, 0, 0, 0};

// data-ok: retail's bytes at 0X2C0D28
void *D_002C0D28[6] = {(void *)g_2e1e40, (void *)g_2dd5bc, (void *)g_2f7900, 0, 0, 0};

// data-ok: retail's bytes at 0X2C0D40
unsigned int D_002C0D40[3] = {0x200, 0x182, 0x164};

// data-ok: retail's bytes at 0X2C0D4C
float D_002C0D4C = -5.0f;

// data-ok: retail's bytes at 0X2C0D50
float D_002C0D50[4] = {5.0f, 0.0f, 0.0f, 0.0f};
