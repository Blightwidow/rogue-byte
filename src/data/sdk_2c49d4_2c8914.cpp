// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C8914-0X2C8940 (piece data/sdk_2c49d4), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002C60C0[];
extern "C" void GlobalDtorSw();
extern "C" void StaticDestructMenus_thunk();
extern "C" void StaticInitDestroySndbank_thunk2();
extern "C" void func_0014FAA8();
extern "C" void func_001AE130();
extern "C" void func_00254EF0();

// data-ok: retail's bytes at 0X2C8914
void *D_002C8914[8] = {(void *)func_0014FAA8, (void *)func_001AE130, (void *)StaticDestructMenus_thunk, (void *)StaticInitDestroySndbank_thunk2, (void *)GlobalDtorSw, (void *)func_00254EF0, 0, (void *)1};

// data-ok: retail's bytes at 0X2C8934
void *D_002C8934[3] = {(void *)D_002C60C0, 0, 0};
