// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CA280-0X2CA300 (piece data/so-sm), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void HandleLoMessage();
extern "C" void PartHandle_AddRef();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void Sm_Release();
extern "C" void func_00114360();
extern "C" void func_00114370();

// data-ok: retail's bytes at 0X2CA280
void *D_002CA280[16] = {0, 0, 0, (void *)PartHandle_AddRef, 0, (void *)Sm_Release, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114370, 0, 0};

// data-ok: retail's bytes at 0X2CA2C0
void *D_002CA2C0[16] = {0, 0, 0, (void *)PartHandle_AddRef, 0, (void *)Sm_Release, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114360, 0, 0};
