// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C59C8-0X2C5A68 (piece data/sdk_2c49d4), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_472200[];
extern "C" void func_00239920();

// data-ok: retail's bytes at 0X2C59C8
unsigned int D_002C59C8[10] = {0x3c1d0008, 0x60f809, 0x27bd1fc0, 0x2403fff8, 12, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2C59F0
void *D_002C59F0[16] = {(void *)90, (void *)func_00239920, (void *)91, (void *)0x80076000, (void *)252, 0, (void *)254, 0, (void *)253, 0, (void *)255, 0, (void *)0x12c, 0, (void *)8, 0};

// data-ok: retail's bytes at 0X2C5A30
unsigned int D_002C5A30[6] = {0, 0, 0xffffffff, 1, 0, 0};

// data-ok: retail's bytes at 0X2C5A48
unsigned int D_002C5A48[2] = {0, 0xffffffff};

// data-ok: retail's bytes at 0X2C5A50
unsigned int D_002C5A50 = 0;

// data-ok: retail's bytes at 0X2C5A54
unsigned int D_002C5A54 = 0;

// data-ok: retail's bytes at 0X2C5A58
void *D_002C5A58[2] = {0, (void *)D_472200};

// data-ok: retail's bytes at 0X2C5A60
unsigned int D_002C5A60[2] = {0, 0};
