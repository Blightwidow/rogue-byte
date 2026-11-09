// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D3200-0X2D36D0 (piece data/new_100008_2d3200), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void AddCnvo();
extern "C" void AddLo();
extern "C" void AddLoHierarchy();
extern "C" void ApplyXfmProxy();
extern "C" void CLo_Clone();
extern "C" void CReturnZeroLo();
extern "C" void ClearLoGrfField();
extern "C" void CloneCnvo();
extern "C" void CloneLoVirtual();
extern "C" void CloneXfm();
extern "C" void FReturnFalseLo();
extern "C" void FUN_0012a860();
extern "C" void GetXfmAngularVelocity();
extern "C" void GetXfmMatWorld();
extern "C" void GetXfmVelocity();
extern "C" void HandleLoMessage();
extern "C" void HandleLoSpliceEvent();
extern "C" void InitCnvo__FP4CNVO();
extern "C" void InitLight();
extern "C" void InitLo();
extern "C" void LO_PmatWorld();
extern "C" void LO_SetCloneId();
extern "C" void LoadLoFromBrx();
extern "C" void LoadXfmFromBrx();
extern "C" void OnLightAdd();
extern "C" void OnLightRemove();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PostLightLoad();
extern "C" void PostLoLoad();
extern "C" void PostLoMessage();
extern "C" void RemoveAloHierarchy();
extern "C" void RemoveCnvo();
extern "C" void RemoveLo();
extern "C" void RemoveLoHierarchy();
extern "C" void RotateLightToMat();
extern "C" void RotateXfmToMat();
extern "C" void SetLoGrfField();
extern "C" void SetLoParent();
extern "C" void SetLoPosMatFromLo();
extern "C" void SetLoPosMatFromXf();
extern "C" void SetXfmParent();
extern "C" void TranslateLightToPos();
extern "C" void TranslateXfmToPos();
extern "C" void UpdateLo();
extern "C" void bevy_world_loads_b5_apply_xform();
extern "C" void func_00113A30();
extern "C" void func_00113A50();
extern "C" void func_00113C90();
extern "C" void func_00132B08();
extern "C" void func_001A3430();
extern "C" void func_001A3460();
extern "C" void func_001A34B0();
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
extern "C" void func_00210330();
extern "C" void func_0022FBD8();
extern "C" void func_00231220();
extern "C" void func_00231550();

// data-ok: retail's bytes at 0X2D3200
void *D_002D3200[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113C90, 0, (void *)InitCnvo__FP4CNVO, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddCnvo, 0, (void *)RemoveCnvo, 0, (void *)func_001A5B80, 0, (void *)LoadXfmFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneCnvo, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D33A0
void *D_002D33A0[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A50, 0, (void *)InitLight, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)func_001A3430, 0, (void *)func_001A34B0, 0, (void *)func_001A5B80, 0, (void *)LoadXfmFromBrx, 0, (void *)PostLightLoad, 0, (void *)UpdateLo, 0, (void *)func_001A3460, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)OnLightRemove, 0, (void *)OnLightAdd, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateLightToPos, 0, (void *)RotateLightToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D3540
void *D_002D3540[100] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A30, 0, (void *)InitLo, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetLoParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadLoFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)func_001A6110, 0, (void *)func_001A6118, 0, (void *)LO_PmatWorld, 0, (void *)func_001A6B30, 0, (void *)func_001A6120, 0, (void *)func_001A6138, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)bevy_world_loads_b5_apply_xform, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CLo_Clone, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, 0};
