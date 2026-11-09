// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D2938-0X2D2E58 (piece data/new_100008_2d2938), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void AddLo();
extern "C" void AddLoHierarchy();
extern "C" void AddTarget();
extern "C" void ApplyXfmProxy();
extern "C" void CReturnZeroLo();
extern "C" void ClearLoGrfField();
extern "C" void CloneLoVirtual();
extern "C" void CloneSpire__FP5SPIRET0();
extern "C" void CloneTarget();
extern "C" void CloneXfm();
extern "C" void FReturnFalseLo();
extern "C" void FUN_0012a860();
extern "C" void GetXfmAngularVelocity();
extern "C" void GetXfmMatWorld();
extern "C" void GetXfmVelocity();
extern "C" void HandleLoMessage();
extern "C" void HandleLoSpliceEvent();
extern "C" void InitHnd__FP3HND();
extern "C" void InitSpire__FP5SPIRE();
extern "C" void InitXfm_thunk();
extern "C" void LO_SetCloneId();
extern "C" void LoadSpireFromBrx();
extern "C" void LoadXfmFromBrx();
extern "C" void Member_FGetWrapRange();
extern "C" void Member_GetParam();
extern "C" void Member_GetRandomPos();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PostLoLoad();
extern "C" void PostLoMessage();
extern "C" void PostSpireLoad();
extern "C" void RemoveAloHierarchy();
extern "C" void RemoveLo();
extern "C" void RemoveLoHierarchy();
extern "C" void RemoveTarget();
extern "C" void RotateXfmToMat();
extern "C" void SetLoGrfField();
extern "C" void SetLoPosMatFromLo();
extern "C" void SetLoPosMatFromXf();
extern "C" void SetXfmParent();
extern "C" void Spire_AddLoHierarchy();
extern "C" void Spire_RemoveLoHierarchy();
extern "C" void TranslateXfmToPos();
extern "C" void UpdateLo();
extern "C" void func_00113A90();
extern "C" void func_00113AA0();
extern "C" void func_00113B40();
extern "C" void func_00132B08();
extern "C" void func_00182D70();
extern "C" void func_00184F98();
extern "C" void func_001A5B80();
extern "C" void func_001A5E80();
extern "C" void func_001A5ED8();
extern "C" void func_001A5EE0();
extern "C" void func_001A6130();
extern "C" void func_001A6148();
extern "C" void func_001A6178();
extern "C" void func_001A6C48();
extern "C" void func_001A6DC0();
extern "C" void func_001A6E80();
extern "C" void func_001A6EF0();
extern "C" void func_001A6EF8();
extern "C" void func_001CB4E0();
extern "C" void func_001CB5C8();
extern "C" void func_00210330();
extern "C" void func_0021D2C8();
extern "C" void func_0022FBD8();
extern "C" void func_00231220();
extern "C" void func_00231550();

// data-ok: retail's bytes at 0X2D2938
void *D_002D2938[16] = {(void *)0xff00, 0, 0, (void *)Member_FGetWrapRange, 0, (void *)Member_GetParam, (void *)0xff00, (void *)func_00184F98, 0, (void *)func_00182D70, 0, (void *)Member_GetRandomPos, (void *)0xff00, (void *)0x259a70, 0, 0};

// data-ok: retail's bytes at 0X2D2978
void *D_002D2978[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113B40, 0, (void *)InitHnd__FP3HND, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadXfmFromBrx, 0, (void *)func_0021D2C8, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveTarget, 0, (void *)AddTarget, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneTarget, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D2B18
void *D_002D2B18[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113AA0, 0, (void *)InitSpire__FP5SPIRE, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)Spire_AddLoHierarchy, 0, (void *)Spire_RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadSpireFromBrx, 0, (void *)PostSpireLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneSpire__FP5SPIRET0, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D2CB8
void *D_002D2CB8[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A90, 0, (void *)InitXfm_thunk, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadSpireFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};
