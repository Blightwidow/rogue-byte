// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2AC838-0X2AC880 (piece rodata/sdk_2aa7b0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void func_00253E68();
extern "C" void func_00253FA8();
extern "C" void func_00254090();
extern "C" void func_002540A0();
extern "C" void func_002540B0();
extern "C" void func_00254298();
extern "C" void func_002542A8();
extern "C" void func_00254678();
extern "C" void func_00254708();
extern "C" void func_002547A0();

// data-ok: retail's bytes at 0X2AC838
extern void *const D_002AC838[18] = {(void *)func_002540A0, (void *)func_00253E68, (void *)func_00254678, (void *)func_00253FA8, (void *)func_00254708, (void *)func_00254090, (void *)func_002540A0, (void *)func_002547A0, (void *)func_002540B0, (void *)func_00254298, (void *)func_002542A8, 0, 0, 0, 0, 0, 0, 0};
