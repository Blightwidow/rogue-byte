// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CE2B8-0X2CE2F8 (piece data/crv-lo_2ce2b8), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void HandleLoMessage();
extern "C" void HitFx_AddRef();
extern "C" void HitFx_Release();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void func_00114340();

// data-ok: retail's bytes at 0X2CE2B8
void *D_002CE2B8[16] = {0, 0, 0, (void *)HitFx_AddRef, 0, (void *)HitFx_Release, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114340, 0, 0};
