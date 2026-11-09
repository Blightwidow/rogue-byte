// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2DC070-0X2DD230 (piece data/new_100008_2dc070), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ALO_SetCloneId();
extern "C" void AddLo();
extern "C" void AddLoHierarchy();
extern "C" void AddSoGravityAcceleration();
extern "C" void AddSoLoHierarchy();
extern "C" void AddSoWaterAcceleration();
extern "C" void AddWaterExternalAccelerations();
extern "C" void AdjustSoXpVelocity();
extern "C" void ApplyXfmProxy();
extern "C" void CLo_Clone();
extern "C" void CReturnZeroLo();
extern "C" void CSo_Clone();
extern "C" void CSo_LoadFromBrx();
extern "C" void ClearLoGrfField();
extern "C" void CloneAloHierarchy();
extern "C" void CloneLoVirtual();
extern "C" void CloneXfm();
extern "C" void FAbsorbSoWkr();
extern "C" void FIgnoreSoIntersection();
extern "C" void FIsSoLocked();
extern "C" void FPointInAloParts();
extern "C" void FPointInAloParts_thunk();
extern "C" void FReturnFalseLo();
extern "C" void FUN_0012a860();
extern "C" void GetSoAngularVelocityVec();
extern "C" void GetSoCpdefi__FP2SOfP6CPDEFI();
extern "C" void GetSoVelocityVec();
extern "C" void GetXfmAngularVelocity();
extern "C" void GetXfmMatWorld();
extern "C" void GetXfmVelocity();
extern "C" void HandleLoMessage();
extern "C" void HandleLoSpliceEvent();
extern "C" void HandleWaterMessage();
extern "C" void InitBrk();
extern "C" void InitWarp();
extern "C" void InitXfm();
extern "C" void LO_PmatWorld();
extern "C" void LO_SetCloneId();
extern "C" void LoadLoFromBrx();
extern "C" void LoadVolumeFromBrx();
extern "C" void LoadWarpFromBrx();
extern "C" void LoadXfmFromBrx();
extern "C" void MatchSoOtherObject();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PmatWorldSo();
extern "C" void PostBrkLoad();
extern "C" void PostLoLoad();
extern "C" void PostLoMessage();
extern "C" void PoxaAllocSo();
extern "C" void ProjectSoTransform();
extern "C" void PxfFromAloRef();
extern "C" void RemoveAloHierarchy();
extern "C" void RemoveLo();
extern "C" void RemoveLoHierarchy();
extern "C" void RemoveSoLoHierarchy();
extern "C" void RemoveWater();
extern "C" void RotateSoToMat();
extern "C" void RotateXfmToMat();
extern "C" void SetLoGrfField();
extern "C" void SetLoParent();
extern "C" void SetLoPosMatFromLo();
extern "C" void SetLoPosMatFromXf();
extern "C" void SetSoAngularVelocityVec();
extern "C" void SetSoParent();
extern "C" void SetSoVelocityVec();
extern "C" void SetXfmParent();
extern "C" void TranslateSoToPos();
extern "C" void TranslateXfmToPos();
extern "C" void UpdateAloXfWorldHierarchy();
extern "C" void UpdateLo();
extern "C" void UpdateSoBounds();
extern "C" void UpdateSoBounds_thunk();
extern "C" void UpdateSoRoot();
extern "C" void UpdateWarp();
extern "C" void UpdateWater();
extern "C" void UpdateWrMatrixes__FP2WR();
extern "C" void bevy_physics_driver_1f9e70();
extern "C" void bevy_world_loads_b5_apply_xform();
extern "C" void func_00113A40();
extern "C" void func_00113A60();
extern "C" void func_00113B70();
extern "C" void func_00113B80();
extern "C" void func_00113BB0();
extern "C" void func_00113CA0();
extern "C" void func_00113CB0();
extern "C" void func_00113FA0();
extern "C" void func_001140C0();
extern "C" void func_00114140();
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
extern "C" void func_001A6DC8();
extern "C" void func_001A6E80();
extern "C" void func_001A6EF0();
extern "C" void func_001A6EF8();
extern "C" void func_001CB4E0();
extern "C" void func_001CB518();
extern "C" void func_001CB5C8();
extern "C" void func_001CB5D0();
extern "C" void func_001F2FE0();
extern "C" void func_001F3078();
extern "C" void func_001F3118();
extern "C" void func_001F3590();
extern "C" void func_001F3B28();
extern "C" void func_001F3C70();
extern "C" void func_001F3CC8();
extern "C" void func_001F3E00();
extern "C" void func_001F3EA8();
extern "C" void func_001F3FB0();
extern "C" void func_001F4010();
extern "C" void func_001F4A80();
extern "C" void func_001F4CA0();
extern "C" void func_001F4F10();
extern "C" void func_001F4FA8();
extern "C" void func_001F4FB0();
extern "C" void func_001F4FB8();
extern "C" void func_001F4FC0();
extern "C" void func_001F5988();
extern "C" void func_001F5990();
extern "C" void func_001F5998();
extern "C" void func_001F7410();
extern "C" void func_001FA328();
extern "C" void func_001FA528();
extern "C" void func_001FADD0();
extern "C" void func_00210330();
extern "C" void func_00227350();
extern "C" void func_00227380();
extern "C" void func_00227E20();
extern "C" void func_00227E58();
extern "C" void func_00228140();
extern "C" void func_00228720();
extern "C" void func_00228BB0();
extern "C" void func_002297F0();
extern "C" void func_00229EF0();
extern "C" void func_00229F88();
extern "C" void func_0022A060();
extern "C" void func_0022A908();
extern "C" void func_0022B720();
extern "C" void func_0022FBD8();
extern "C" void func_00231220();
extern "C" void func_00231550();

// data-ok: retail's bytes at 0X2DC070
void *D_002DC070[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A60, 0, (void *)func_00227350, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)func_00227380, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2DC210
void *D_002DC210[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113B80, 0, (void *)InitXfm, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadVolumeFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)func_00227E58, 0, (void *)func_00227E20, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2DC3B0
void *D_002DC3B0[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113B70, 0, (void *)InitXfm, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadVolumeFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2DC550
void *D_002DC550[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113CB0, 0, (void *)InitXfm, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)func_00228720, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2DC6F0
void *D_002DC6F0[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113BB0, 0, (void *)InitWarp, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadWarpFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateWarp, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2DC890
void *D_002DC890[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113CA0, 0, (void *)InitXfm, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)func_00228140, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2DCA30
void *D_002DCA30[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleWaterMessage, 0, (void *)func_00113FA0, 0, (void *)InitBrk, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveWater, 0, (void *)UpdateSoRoot, 0, (void *)CSo_LoadFromBrx, 0, (void *)PostBrkLoad, 0, (void *)UpdateWater, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds_thunk, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_00228BB0, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)AddWaterExternalAccelerations, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts_thunk, 0, (void *)func_001F7410, 0, (void *)FAbsorbSoWkr, 0, 0};

// data-ok: retail's bytes at 0X2DCC98
void *D_002DCC98[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001140C0, 0, (void *)func_00229EF0, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)CSo_LoadFromBrx, 0, (void *)func_00229F88, 0, (void *)func_0022A060, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_0022A908, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbSoWkr, 0, 0};

// data-ok: retail's bytes at 0X2DCF00
void *D_002DCF00[100] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114140, 0, (void *)func_0022B720, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetLoParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadLoFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateWrMatrixes__FP2WR, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)func_001A6110, 0, (void *)func_001A6118, 0, (void *)LO_PmatWorld, 0, (void *)func_001A6B30, 0, (void *)func_001A6120, 0, (void *)func_001A6138, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)bevy_world_loads_b5_apply_xform, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CLo_Clone, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, 0};

// data-ok: retail's bytes at 0X2DD090
void *D_002DD090[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A40, 0, (void *)InitXfm, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadXfmFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};
