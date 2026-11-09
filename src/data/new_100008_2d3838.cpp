// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D3838-0X2D4220 (piece data/new_100008_2d3838), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ALO_SetCloneId();
extern "C" void AccelSlotSoRotation();
extern "C" void AddBombCustomXps();
extern "C" void AddLo();
extern "C" void AddSoGravityAcceleration();
extern "C" void AddSoLoHierarchy();
extern "C" void AddSoWaterAcceleration();
extern "C" void AdjustSoXpVelocity();
extern "C" void Bomb_OnPoolClaim();
extern "C" void CBomb_PostLoad();
extern "C" void CReturnZeroLo();
extern "C" void CSo_Clone();
extern "C" void CloneAloHierarchy();
extern "C" void FAbsorbBombWkr();
extern "C" void FAbsorbSlotSoWkr();
extern "C" void FIgnoreSoIntersection();
extern "C" void FIsSoLocked();
extern "C" void FPointInAloParts();
extern "C" void FReturnFalseLo();
extern "C" void FireMissile();
extern "C" void FireSplmiss__FP7SPLMISSP3ALOP6VECTOR();
extern "C" void GetSoAngularVelocityVec();
extern "C" void GetSoCpdefi__FP2SOfP6CPDEFI();
extern "C" void GetSoVelocityVec();
extern "C" void HandleBombMessage__FP4BOMB5MSGIDPv();
extern "C" void HandleLoSpliceEvent();
extern "C" void HandleSlotSoMessage();
extern "C" void InitMissile();
extern "C" void InitRov__FP3ROV();
extern "C" void InitTarmiss();
extern "C" void LoadBombFromBrx();
extern "C" void MatchSoOtherObject();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PmatWorldSo();
extern "C" void PostLoMessage();
extern "C" void PoxaAllocSo();
extern "C" void PresetGroundmissAccel();
extern "C" void PresetTarmissAccel();
extern "C" void ProjectSlotSoTransform();
extern "C" void ProjectSoTransform();
extern "C" void PxfFromAloRef();
extern "C" void RemoveLo();
extern "C" void RenderSoSelf_thunk();
extern "C" void RotateSoToMat();
extern "C" void SetSoAngularVelocityVec();
extern "C" void SetSoParent();
extern "C" void SetSoVelocityVec();
extern "C" void StickTrigBomb();
extern "C" void TranslateSoToPos();
extern "C" void UpdateAloXfWorldHierarchy();
extern "C" void UpdateBomb__FP4BOMBf();
extern "C" void UpdateSlotSo();
extern "C" void UpdateSoBounds();
extern "C" void UpdateSoRoot();
extern "C" void bevy_physics_driver_1f9e70();
extern "C" void func_00113F10();
extern "C" void func_00113F20();
extern "C" void func_00113F30();
extern "C" void func_00114010();
extern "C" void func_00132B08();
extern "C" void func_0013AEB0();
extern "C" void func_001A6DC8();
extern "C" void func_001A6EF0();
extern "C" void func_001A6EF8();
extern "C" void func_001B0B78();
extern "C" void func_001B0C68();
extern "C" void func_001B0CA8();
extern "C" void func_001B0D08();
extern "C" void func_001B0D60();
extern "C" void func_001B1E00();
extern "C" void func_001B1E38();
extern "C" void func_001B1F40();
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
extern "C" void func_002297F0();

// data-ok: retail's bytes at 0X2D3838
void *D_002D3838[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleSlotSoMessage, 0, (void *)func_00114010, 0, (void *)func_001B0B78, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_001B0C68, 0, (void *)UpdateSoRoot, 0, (void *)func_001B0CA8, 0, (void *)func_001B0D08, 0, (void *)UpdateSlotSo, 0, (void *)ProjectSlotSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderSoSelf_thunk, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001B0D60, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AccelSlotSoRotation, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbSlotSoWkr, 0, 0};

// data-ok: retail's bytes at 0X2D3AA0
void *D_002D3AA0[160] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleBombMessage__FP4BOMB5MSGIDPv, 0, (void *)func_00113F30, 0, (void *)InitTarmiss, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_001B1E38, 0, (void *)UpdateSoRoot, 0, (void *)func_001B1E00, 0, (void *)CBomb_PostLoad, 0, (void *)UpdateBomb__FP4BOMBf, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)Bomb_OnPoolClaim, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_0013AEB0, 0, (void *)func_001F4FA8, 0, (void *)AddBombCustomXps, 0, (void *)func_001B1F40, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)PresetTarmissAccel, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbBombWkr, 0, (void *)LoadBombFromBrx, 0, (void *)StickTrigBomb, 0, (void *)FireSplmiss__FP7SPLMISSP3ALOP6VECTOR, 0, 0};

// data-ok: retail's bytes at 0X2D3D20
void *D_002D3D20[160] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleBombMessage__FP4BOMB5MSGIDPv, 0, (void *)func_00113F20, 0, (void *)InitRov__FP3ROV, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_001B1E38, 0, (void *)UpdateSoRoot, 0, (void *)func_001B1E00, 0, (void *)CBomb_PostLoad, 0, (void *)UpdateBomb__FP4BOMBf, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)Bomb_OnPoolClaim, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_0013AEB0, 0, (void *)func_001F4FA8, 0, (void *)AddBombCustomXps, 0, (void *)func_001B1F40, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)PresetGroundmissAccel, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbBombWkr, 0, (void *)LoadBombFromBrx, 0, (void *)StickTrigBomb, 0, (void *)FireMissile, 0, 0};

// data-ok: retail's bytes at 0X2D3FA0
void *D_002D3FA0[160] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleBombMessage__FP4BOMB5MSGIDPv, 0, (void *)func_00113F10, 0, (void *)InitMissile, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_001B1E38, 0, (void *)UpdateSoRoot, 0, (void *)func_001B1E00, 0, (void *)CBomb_PostLoad, 0, (void *)UpdateBomb__FP4BOMBf, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)Bomb_OnPoolClaim, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_0013AEB0, 0, (void *)func_001F4FA8, 0, (void *)AddBombCustomXps, 0, (void *)func_001B1F40, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbBombWkr, 0, (void *)LoadBombFromBrx, 0, (void *)StickTrigBomb, 0, (void *)FireMissile, 0, 0};
