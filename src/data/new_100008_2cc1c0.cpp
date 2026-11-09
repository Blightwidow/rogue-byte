// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CC1C0-0X2CD378 (piece data/new_100008_2cc1c0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ALO_SetCloneId();
extern "C" void AddLo();
extern "C" void AddLoHierarchy();
extern "C" void AddSoGravityAcceleration();
extern "C" void AddSoLoHierarchy();
extern "C" void AddSoWaterAcceleration();
extern "C" void AddStepCustomXps();
extern "C" void AddStepguardHierarchy();
extern "C" void AdjustSoXpVelocity();
extern "C" void AdjustStepNewXp();
extern "C" void AdjustStepXpVelocity();
extern "C" void AdjustStepXps();
extern "C" void ApplyXfmProxy();
extern "C" void CLo_Clone();
extern "C" void CReturnZeroLo();
extern "C" void CSo_Clone();
extern "C" void CSo_LoadFromBrx();
extern "C" void CVolbtn_PostLoad();
extern "C" void CgeomExtraStep();
extern "C" void ClearLoGrfField();
extern "C" void CloneAloHierarchy();
extern "C" void CloneButton();
extern "C" void CloneGuard();
extern "C" void CloneLoVirtual();
extern "C" void CloneVolbtn__FP6VOLBTNT0();
extern "C" void FAbsorbButtonWkr();
extern "C" void FAbsorbGuardWkr();
extern "C" void FAbsorbSoWkr();
extern "C" void FIgnoreSoIntersection();
extern "C" void FIsGuardInvulnerable();
extern "C" void FIsGuardWkrLethal();
extern "C" void FIsSoLocked();
extern "C" void FPointInAloParts();
extern "C" void FReturnFalseLo();
extern "C" void FUN_0012a860();
extern "C" void GetSoAngularVelocityVec();
extern "C" void GetSoCpdefi__FP2SOfP6CPDEFI();
extern "C" void GetSoVelocityVec();
extern "C" void GetXfmAngularVelocity();
extern "C" void GetXfmMatWorld();
extern "C" void GetXfmVelocity();
extern "C" void GoalFollowCrvVjoy_Activate();
extern "C" void GoalFollowCrvVjoy_FillVjoy();
extern "C" void GoalFollowCrvVjoy_Init();
extern "C" void GoalFollowCrvVjoy_Update();
extern "C" void GoalFollowCrv_SetState();
extern "C" void GoalMurrayAi_Update();
extern "C" void Goal_Deactivate();
extern "C" void Goal_FHandleMessage();
extern "C" void Goal_FillVjoy();
extern "C" void GrfGuardCustomXps();
extern "C" void HandleLoMessage();
extern "C" void HandleLoSpliceEvent();
extern "C" void HandleStepguardMessage();
extern "C" void HandleWipeMessage();
extern "C" void InitButton();
extern "C" void InitLo();
extern "C" void InitVolbtn();
extern "C" void InitWipe();
extern "C" void LO_PmatWorld();
extern "C" void LO_SetCloneId();
extern "C" void LoadButtonFromBrx();
extern "C" void LoadStepFromBrx();
extern "C" void LoadVolbtnFromBrx__FP6VOLBTNP18CBinaryInputStream();
extern "C" void MatchSoOtherObject();
extern "C" void NGuardAlertLevel();
extern "C" void OnGuardAdd();
extern "C" void OnGuardRemove();
extern "C" void OnLoAdd__FP2LO();
extern "C" void OnPoActive();
extern "C" void PmatWorldSo();
extern "C" void PostButtonLoad();
extern "C" void PostGuardLoad();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void PostWipeLoad();
extern "C" void PoxaAllocSo();
extern "C" void PresetStepAccel();
extern "C" void ProjectSoTransform();
extern "C" void PvtGetCidB6();
extern "C" void PvtGetCidC1();
extern "C" void PvtGetCidC2();
extern "C" void PvtGetCidC3();
extern "C" void PvtGetCidC4();
extern "C" void PvtGetCidC5();
extern "C" void PvtGetCidC6();
extern "C" void PxfFromAloRef();
extern "C" void ReleaseAloSmKinds();
extern "C" void RemoveAloHierarchy();
extern "C" void RemoveLo();
extern "C" void RemoveLoHierarchy();
extern "C" void RemoveSoLoHierarchy();
extern "C" void RemoveStepguardHierarchy();
extern "C" void RemoveVolbtn();
extern "C" void RenderStepguardSelf();
extern "C" void RetainAloSmKinds();
extern "C" void RotateSoToMat();
extern "C" void RotateStepToMat();
extern "C" void RotateXfmToMat();
extern "C" void SetLoGrfField();
extern "C" void SetLoParent();
extern "C" void SetLoPosMatFromLo();
extern "C" void SetLoPosMatFromXf();
extern "C" void SetPoPlayable();
extern "C" void SetSoAngularVelocityVec();
extern "C" void SetSoParent();
extern "C" void SetSoVelocityVec();
extern "C" void SetXfmParent();
extern "C" void TranslateSoToPos();
extern "C" void TranslateStepToPos();
extern "C" void TranslateXfmToPos();
extern "C" void UpdateAloXfWorldHierarchy();
extern "C" void UpdateButton();
extern "C" void UpdateGuard();
extern "C" void UpdateLo();
extern "C" void UpdateSoBounds();
extern "C" void UpdateSoRoot();
extern "C" void UpdateVolbtn();
extern "C" void UpdateWipeState();
extern "C" void bevy_physics_driver_1f9e70();
extern "C" void bevy_world_loads_b5_apply_xform();
extern "C" void func_00113B90();
extern "C" void func_00113E00();
extern "C" void func_00113E10();
extern "C" void func_00113F40();
extern "C" void func_00114090();
extern "C" void func_001141C0();
extern "C" void func_00114490();
extern "C" void func_00132B08();
extern "C" void func_00144E20();
extern "C" void func_00144E68();
extern "C" void func_00145010();
extern "C" void func_00145080();
extern "C" void func_001450B0();
extern "C" void func_001453F0();
extern "C" void func_00145CD0();
extern "C" void func_00145D00();
extern "C" void func_00145D68();
extern "C" void func_00145DB0();
extern "C" void func_00146068();
extern "C" void func_001461C8();
extern "C" void func_001461F8();
extern "C" void func_00146260();
extern "C" void func_001462A8();
extern "C" void func_00146560();
extern "C" void func_001466C0();
extern "C" void func_001466F0();
extern "C" void func_00146758();
extern "C" void func_001467A0();
extern "C" void func_00146B18();
extern "C" void func_00146E98();
extern "C" void func_00146EE0();
extern "C" void func_001492B0();
extern "C" void func_0014A008();
extern "C" void func_0014A0A8();
extern "C" void func_0014A1B0();
extern "C" void func_0014A200();
extern "C" void func_0014A248();
extern "C" void func_0014A2A0();
extern "C" void func_0014B1A0();
extern "C" void func_0014B1D8();
extern "C" void func_0014B218();
extern "C" void func_0014B290();
extern "C" void func_0014B460();
extern "C" void func_0014FAC8();
extern "C" void func_0014FAF8();
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
extern "C" void func_001C41B8();
extern "C" void func_001C4228();
extern "C" void func_001CB4E0();
extern "C" void func_001CB518();
extern "C" void func_001CB5C8();
extern "C" void func_001CB5D0();
extern "C" void func_001EEF68();
extern "C" void func_001EEF98();
extern "C" void func_001EEFA0();
extern "C" void func_001EEFB8();
extern "C" void func_001F1F38();
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
extern "C" void func_00204C60();
extern "C" void func_00205008();
extern "C" void func_002052E0();
extern "C" void func_00206380();
extern "C" void func_002064D8();
extern "C" void func_002082D0();
extern "C" void func_00208BE0();
extern "C" void func_00209C88();
extern "C" void func_00210330();
extern "C" void func_002297F0();
extern "C" void func_0022FBD8();
extern "C" void func_00231220();
extern "C" void func_00231550();

// data-ok: retail's bytes at 0X2CC1C0
void *D_002CC1C0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidC6, 0, (void *)func_001EEF68, 0, (void *)func_00146E98, 0, (void *)func_00146EE0, 0, (void *)GoalMurrayAi_Update, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2CC240
void *D_002CC240[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidC5, 0, (void *)func_001466C0, 0, (void *)func_001466F0, 0, (void *)func_00146758, 0, (void *)func_001467A0, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)func_00146B18, 0, 0};

// data-ok: retail's bytes at 0X2CC2C0
void *D_002CC2C0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidC4, 0, (void *)func_001461C8, 0, (void *)func_001461F8, 0, (void *)func_00146260, 0, (void *)func_001462A8, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)func_00146560, 0, 0};

// data-ok: retail's bytes at 0X2CC340
void *D_002CC340[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidC3, 0, (void *)func_00145CD0, 0, (void *)func_00145D00, 0, (void *)func_00145D68, 0, (void *)func_00145DB0, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)func_00146068, 0, 0};

// data-ok: retail's bytes at 0X2CC3C0
void *D_002CC3C0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidC2, 0, (void *)func_00145010, 0, (void *)func_00145080, 0, (void *)func_001450B0, 0, (void *)func_001453F0, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2CC440
void *D_002CC440[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidC1, 0, (void *)func_00144E20, 0, (void *)func_00144E68, 0, (void *)Goal_Deactivate, 0, (void *)func_001EEF98, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2CC4C0
void *D_002CC4C0[34] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114490, 0, (void *)GoalFollowCrvVjoy_Init, 0, (void *)GoalFollowCrvVjoy_Activate, 0, (void *)Goal_Deactivate, 0, (void *)GoalFollowCrvVjoy_Update, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)GoalFollowCrvVjoy_FillVjoy, 0, (void *)GoalFollowCrv_SetState, 0, 0};

// data-ok: retail's bytes at 0X2CC548
void *D_002CC548[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleWipeMessage, 0, (void *)func_00114090, 0, (void *)InitWipe, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)CSo_LoadFromBrx, 0, (void *)PostWipeLoad, 0, (void *)UpdateWipeState, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbSoWkr, 0, 0};

// data-ok: retail's bytes at 0X2CC7B0
void *D_002CC7B0[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113B90, 0, (void *)InitVolbtn, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveVolbtn, 0, (void *)func_001A5B80, 0, (void *)LoadVolbtnFromBrx__FP6VOLBTNP18CBinaryInputStream, 0, (void *)CVolbtn_PostLoad, 0, (void *)UpdateVolbtn, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneVolbtn__FP6VOLBTNT0, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2CC950
void *D_002CC950[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113F40, 0, (void *)InitButton, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_001492B0, 0, (void *)UpdateSoRoot, 0, (void *)LoadButtonFromBrx, 0, (void *)PostButtonLoad, 0, (void *)UpdateButton, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CloneButton, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbButtonWkr, 0, 0};

// data-ok: retail's bytes at 0X2CCBB8
void *D_002CCBB8[182] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)func_0014B218, 0, (void *)func_00113E00, 0, (void *)func_0014B1A0, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_002064D8, 0, (void *)UpdateSoRoot, 0, (void *)LoadStepFromBrx, 0, (void *)func_0014B1D8, 0, (void *)UpdateGuard, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderStepguardSelf, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)RemoveStepguardHierarchy, 0, (void *)AddStepguardHierarchy, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)OnGuardAdd, 0, (void *)OnGuardRemove, 0, (void *)CReturnZeroLo, 0, (void *)TranslateStepToPos, 0, (void *)RotateStepToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)func_002052E0, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CloneGuard, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_00204C60, 0, (void *)AdjustStepNewXp, 0, (void *)func_001F4FB8, 0, (void *)AdjustStepXpVelocity, 0, (void *)AdjustStepXps, 0, (void *)func_00209C88, 0, (void *)AddStepCustomXps, 0, (void *)func_00206380, 0, (void *)FIsSoLocked, 0, (void *)CgeomExtraStep, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)PresetStepAccel, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbGuardWkr, 0, (void *)FIsGuardInvulnerable, 0, (void *)NGuardAlertLevel, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, (void *)func_00205008, 0, (void *)RetainAloSmKinds, 0, (void *)ReleaseAloSmKinds, 0, (void *)GrfGuardCustomXps, 0, (void *)func_0014B460, 0, (void *)func_001F1F38, 0, (void *)func_0014B290, 0, (void *)func_00208BE0, 0, 0};

// data-ok: retail's bytes at 0X2CCE90
void *D_002CCE90[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidB6, 0, (void *)func_0014A1B0, 0, (void *)func_0014A200, 0, (void *)func_0014A248, 0, (void *)func_0014A2A0, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2CCF10
void *D_002CCF10[100] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001141C0, 0, (void *)InitLo, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetLoParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)func_0014A008, 0, (void *)func_0014A0A8, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)func_001A6110, 0, (void *)func_001A6118, 0, (void *)LO_PmatWorld, 0, (void *)func_001A6B30, 0, (void *)func_001A6120, 0, (void *)func_001A6138, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)bevy_world_loads_b5_apply_xform, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CLo_Clone, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, 0};

// data-ok: retail's bytes at 0X2CD0A0
void *D_002CD0A0[182] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleStepguardMessage, 0, (void *)func_00113E10, 0, (void *)func_0014FAC8, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_002064D8, 0, (void *)UpdateSoRoot, 0, (void *)LoadStepFromBrx, 0, (void *)PostGuardLoad, 0, (void *)func_0014FAF8, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderStepguardSelf, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)RemoveStepguardHierarchy, 0, (void *)AddStepguardHierarchy, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)OnGuardAdd, 0, (void *)OnGuardRemove, 0, (void *)CReturnZeroLo, 0, (void *)TranslateStepToPos, 0, (void *)RotateStepToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)func_002052E0, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CloneGuard, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_00204C60, 0, (void *)AdjustStepNewXp, 0, (void *)func_001F4FB8, 0, (void *)AdjustStepXpVelocity, 0, (void *)AdjustStepXps, 0, (void *)func_00209C88, 0, (void *)AddStepCustomXps, 0, (void *)func_00206380, 0, (void *)FIsSoLocked, 0, (void *)CgeomExtraStep, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)PresetStepAccel, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbGuardWkr, 0, (void *)FIsGuardInvulnerable, 0, (void *)NGuardAlertLevel, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, (void *)func_00205008, 0, (void *)RetainAloSmKinds, 0, (void *)ReleaseAloSmKinds, 0, (void *)GrfGuardCustomXps, 0, (void *)FIsGuardWkrLethal, 0, (void *)func_001F1F38, 0, (void *)func_002082D0, 0, (void *)func_00208BE0, 0, 0};
