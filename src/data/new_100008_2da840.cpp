// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2DA840-0X2DAA10 (piece data/new_100008_2da840), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void AddLo();
extern "C" void AddLoHierarchy();
extern "C" void CReturnZeroLo();
extern "C" void ClearLoGrfField();
extern "C" void CloneGuardAim();
extern "C" void CloneLoVirtual();
extern "C" void FReturnFalseLo();
extern "C" void HandleDirAnimMessage();
extern "C" void HandleLoMessage();
extern "C" void HandleLoSpliceEvent();
extern "C" void LO_PmatWorld();
extern "C" void LO_SetCloneId();
extern "C" void LoadLoFromBrx();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PostGuardAimLoad();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void RemoveAloHierarchy();
extern "C" void RemoveLo();
extern "C" void RemoveLoHierarchy();
extern "C" void SetLoGrfField();
extern "C" void SetLoParent();
extern "C" void SetLoPosMatFromLo();
extern "C" void SetLoPosMatFromXf();
extern "C" void UpdateLo();
extern "C" void bevy_world_loads_b5_apply_xform();
extern "C" void func_00114190();
extern "C" void func_00114330();
extern "C" void func_00132B08();
extern "C" void func_001A5B80();
extern "C" void func_001A5E80();
extern "C" void func_001A5ED8();
extern "C" void func_001A5EE0();
extern "C" void func_001A6110();
extern "C" void func_001A6118();
extern "C" void func_001A6120();
extern "C" void func_001A6130();
extern "C" void func_001A6138();
extern "C" void func_001A6148();
extern "C" void func_001A6178();
extern "C" void func_001A6B30();
extern "C" void func_001A6C48();
extern "C" void func_001A6DC0();
extern "C" void func_001A6E80();
extern "C" void func_001A6EF0();
extern "C" void func_001A6EF8();
extern "C" void func_001CB4E0();
extern "C" void func_001CB5C8();
extern "C" void func_0020AD38();
extern "C" void func_00210330();
extern "C" void func_0022FBD8();

// data-ok: retail's bytes at 0X2DA840
void *D_002DA840[100] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114190, 0, (void *)func_0020AD38, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetLoParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadLoFromBrx, 0, (void *)PostGuardAimLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)func_001A6110, 0, (void *)func_001A6118, 0, (void *)LO_PmatWorld, 0, (void *)func_001A6B30, 0, (void *)func_001A6120, 0, (void *)func_001A6138, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)bevy_world_loads_b5_apply_xform, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneGuardAim, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, 0};

// data-ok: retail's bytes at 0X2DA9D0
void *D_002DA9D0[16] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleDirAnimMessage, 0, (void *)func_00114330, 0, 0};
