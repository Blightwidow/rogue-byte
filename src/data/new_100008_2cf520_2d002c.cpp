// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D002C-0X2D00A0 (piece data/new_100008_2cf520), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void FCanPuffcAttack__FP5PUFFC();
extern "C" void Goal_FHandleMessage();
extern "C" void Goal_FillVjoy();
extern "C" void HandleLoMessage();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void PresetPuffcAccel__FP5PUFFCf();
extern "C" void func_00132B08();
extern "C" void func_0017CAC8();
extern "C" void func_0017CB10();
extern "C" void func_0017CB40();
extern "C" void func_001EEFA0();
extern "C" void func_001EEFB8();

// data-ok: retail's bytes at 0X2D002C
void *D_002D002C[29] = {(void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)FCanPuffcAttack__FP5PUFFC, 0, (void *)func_0017CAC8, 0, (void *)func_0017CB10, 0, (void *)func_0017CB40, 0, (void *)PresetPuffcAccel__FP5PUFFCf, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};
