// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C5268-0X2C5288 (piece data/sdk_2c49d4), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void func_00239738();
extern "C" void func_00239898();

// data-ok: retail's bytes at 0X2C5268
void *D_002C5268[8] = {(void *)90, (void *)func_00239738, (void *)91, (void *)0x80074000, (void *)0xffffc402, 0, (void *)90, (void *)func_00239898};
