// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D4820-0X2D7468 (piece data/new_100008_2d4820), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ALO_SetCloneId();
extern "C" void AddCrv();
extern "C" void AddLo();
extern "C" void AddLoHierarchy();
extern "C" void AddPzlinkHierarchy();
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
extern "C" void CPathZone_LoadFromBrx();
extern "C" void CReturnZeroLo();
extern "C" void CSo_Clone();
extern "C" void CSo_LoadFromBrx();
extern "C" void CgeomExtraStep();
extern "C" void ClearLoGrfField();
extern "C" void CloneAloHierarchy();
extern "C" void CloneGuard();
extern "C" void CloneLoVirtual();
extern "C" void ClonePipe();
extern "C" void ClonePo();
extern "C" void ClonePool_AddLoGrfEntry();
extern "C" void ClonePool_RemoveLoGrfEntry();
extern "C" void CloneXfm();
extern "C" void EnterZoneScriptBeh();
extern "C" void ExitZoneScriptBeh();
extern "C" void FAbsorbDprizeWkr();
extern "C" void FAbsorbGuardWkr();
extern "C" void FAbsorbSoWkr();
extern "C" void FIgnoreSoIntersection();
extern "C" void FInvulnerablePo();
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
extern "C" void Goal_FHandleMessage();
extern "C" void Goal_FillVjoy();
extern "C" void GrfGuardCustomXps();
extern "C" void HandleLoMessage();
extern "C" void HandleLoSpliceEvent();
extern "C" void HandlePoMessage();
extern "C" void HandleStepguardMessage();
extern "C" void InitCoin__FP4COIN();
extern "C" void InitDprize();
extern "C" void InitPathzone();
extern "C" void InitPipe__FP4PIPE();
extern "C" void InitPo();
extern "C" void InitPzlink();
extern "C" void InitSo();
extern "C" void InitStgSwitch();
extern "C" void InitZoneScriptBeh();
extern "C" void LO_PmatWorld();
extern "C" void LO_SetCloneId();
extern "C" void LoadCoinFromBrx();
extern "C" void LoadCrvFromBrx();
extern "C" void LoadDprizeFromBrx();
extern "C" void LoadLoFromBrx();
extern "C" void LoadPoFromBrx();
extern "C" void LoadStepFromBrx();
extern "C" void LoadStgSwitchFromBrx();
extern "C" void LoadXfmFromBrx();
extern "C" void MatchSoOtherObject();
extern "C" void NGuardAlertLevel();
extern "C" void Obstacle_AddLoHierarchy();
extern "C" void Obstacle_Clone();
extern "C" void Obstacle_Init();
extern "C" void Obstacle_LoadFromBrx();
extern "C" void Obstacle_PostLoad();
extern "C" void Obstacle_RemoveLoHierarchy();
extern "C" void OnGuardAdd();
extern "C" void OnGuardRemove();
extern "C" void OnLoAdd__FP2LO();
extern "C" void OnPoActive();
extern "C" void Pipe_AddLoGrfEntry();
extern "C" void Pipe_PostLoLoad();
extern "C" void Pipe_RemoveLoGrfEntry();
extern "C" void PmatWorldSo();
extern "C" void PostClueLoad();
extern "C" void PostCrvLoad();
extern "C" void PostDprizeLoad();
extern "C" void PostGuardLoad();
extern "C" void PostLoLoad();
extern "C" void PostLoMessage();
extern "C" void PostPrizeSpewerLoad();
extern "C" void PostPzlinkLoad();
extern "C" void PostScriptMessage();
extern "C" void PostSoLoad();
extern "C" void PoxaAllocSo();
extern "C" void PresetStepAccel();
extern "C" void ProjectDprizeTransform();
extern "C" void ProjectSoTransform();
extern "C" void PxfFromAloRef();
extern "C" void ReleaseAloSmKinds();
extern "C" void RemoveAloHierarchy();
extern "C" void RemoveCrv();
extern "C" void RemoveLo();
extern "C" void RemoveLoHierarchy();
extern "C" void RemovePzlinkHierarchy();
extern "C" void RemoveSoLoHierarchy();
extern "C" void RemoveStepguardHierarchy();
extern "C" void RenderDprizeAll();
extern "C" void RenderPrizeSpewer();
extern "C" void RenderStepguardSelf();
extern "C" void RetainAloSmKinds();
extern "C" void RotateSoToMat();
extern "C" void RotateStepToMat();
extern "C" void RotateXfmToMat();
extern "C" void RtAlo_LoadFromBrx();
extern "C" void SetCluebottleState();
extern "C" void SetCoinState();
extern "C" void SetDprizeDprizes();
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
extern "C" void UpdateCoin();
extern "C" void UpdateDprize();
extern "C" void UpdateGuard();
extern "C" void UpdateLo();
extern "C" void UpdateSo();
extern "C" void UpdateSoBounds();
extern "C" void UpdateSoRoot();
extern "C" void UpdateZoneScriptBeh();
extern "C" void bevy_physics_driver_1f9e70();
extern "C" void bevy_world_loads_b5_apply_xform();
extern "C" void func_00113A70();
extern "C" void func_00113A80();
extern "C" void func_00113AC0();
extern "C" void func_00113AE0();
extern "C" void func_00113AF0();
extern "C" void func_00113B20();
extern "C" void func_00113CE0();
extern "C" void func_00113D30();
extern "C" void func_00113DD0();
extern "C" void func_00113DE0();
extern "C" void func_00113EF0();
extern "C" void func_00113FB0();
extern "C" void func_00113FC0();
extern "C" void func_00113FD0();
extern "C" void func_00113FE0();
extern "C" void func_00113FF0();
extern "C" void func_00114000();
extern "C" void func_00114030();
extern "C" void func_00114040();
extern "C" void func_001141D0();
extern "C" void func_001144F0();
extern "C" void func_00132B08();
extern "C" void func_00182D70();
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
extern "C" void func_001B9F80();
extern "C" void func_001BA018();
extern "C" void func_001BA0B8();
extern "C" void func_001BA128();
extern "C" void func_001BAD80();
extern "C" void func_001BADB8();
extern "C" void func_001BADF0();
extern "C" void func_001BB250();
extern "C" void func_001BBEA8();
extern "C" void func_001BEA40();
extern "C" void func_001BEE60();
extern "C" void func_001C3958();
extern "C" void func_001C3A08();
extern "C" void func_001C3A88();
extern "C" void func_001C3BB0();
extern "C" void func_001C3ED0();
extern "C" void func_001C41B8();
extern "C" void func_001C4228();
extern "C" void func_001C5098();
extern "C" void func_001C6508();
extern "C" void func_001C6588();
extern "C" void func_001C65F8();
extern "C" void func_001C67D8();
extern "C" void func_001C6880();
extern "C" void func_001C68F0();
extern "C" void func_001C6AB8();
extern "C" void func_001C6B28();
extern "C" void func_001C7E38();
extern "C" void func_001C7E68();
extern "C" void func_001C7EA8();
extern "C" void func_001C8280();
extern "C" void func_001C82F0();
extern "C" void func_001C8350();
extern "C" void func_001CA788();
extern "C" void func_001CA7B8();
extern "C" void func_001CB4E0();
extern "C" void func_001CB518();
extern "C" void func_001CB5C8();
extern "C" void func_001CB5D0();
extern "C" void func_001CB908();
extern "C" void func_001CBA20();
extern "C" void func_001CBA68();
extern "C" void func_001CBAC0();
extern "C" void func_001CBB58();
extern "C" void func_001CBBA8();
extern "C" void func_001CBEB0();
extern "C" void func_001CBEE0();
extern "C" void func_001CBF90();
extern "C" void func_001E6340();
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
extern "C" void func_00259AF8();
extern "C" void func_00259B08();

// data-ok: retail's bytes at 0X2D4820
void *D_002D4820[182] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleStepguardMessage, 0, (void *)func_00113DD0, 0, (void *)func_001B9F80, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_002064D8, 0, (void *)UpdateSoRoot, 0, (void *)LoadStepFromBrx, 0, (void *)func_001BA018, 0, (void *)func_001BA128, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderStepguardSelf, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)RemoveStepguardHierarchy, 0, (void *)AddStepguardHierarchy, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001BA0B8, 0, (void *)OnGuardRemove, 0, (void *)CReturnZeroLo, 0, (void *)TranslateStepToPos, 0, (void *)RotateStepToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)func_002052E0, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CloneGuard, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_00204C60, 0, (void *)AdjustStepNewXp, 0, (void *)func_001F4FB8, 0, (void *)AdjustStepXpVelocity, 0, (void *)AdjustStepXps, 0, (void *)func_00209C88, 0, (void *)AddStepCustomXps, 0, (void *)func_00206380, 0, (void *)FIsSoLocked, 0, (void *)CgeomExtraStep, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)PresetStepAccel, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbGuardWkr, 0, (void *)FIsGuardInvulnerable, 0, (void *)NGuardAlertLevel, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, (void *)func_00205008, 0, (void *)RetainAloSmKinds, 0, (void *)ReleaseAloSmKinds, 0, (void *)GrfGuardCustomXps, 0, (void *)FIsGuardWkrLethal, 0, (void *)func_001F1F38, 0, (void *)func_002082D0, 0, (void *)func_00208BE0, 0, 0};

// data-ok: retail's bytes at 0X2D4AF8
void *D_002D4AF8[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001144F0, 0, (void *)InitZoneScriptBeh, 0, (void *)EnterZoneScriptBeh, 0, (void *)ExitZoneScriptBeh, 0, (void *)UpdateZoneScriptBeh, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D4B78
void *D_002D4B78[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114030, 0, (void *)InitStgSwitch, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)LoadStgSwitchFromBrx, 0, (void *)PostSoLoad, 0, (void *)UpdateSo, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001BAD80, 0, (void *)func_001BADB8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001BBEA8, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001BB250, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)func_001BADF0, 0, 0};

// data-ok: retail's bytes at 0X2D4DE0
void *D_002D4DE0[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113AF0, 0, (void *)Obstacle_Init, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)Obstacle_AddLoHierarchy, 0, (void *)Obstacle_RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)Obstacle_LoadFromBrx, 0, (void *)Obstacle_PostLoad, 0, (void *)UpdateLo, 0, (void *)func_001E6340, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)Obstacle_Clone, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D4F80
void *D_002D4F80[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113CE0, 0, (void *)func_001BEA40, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)RtAlo_LoadFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001BEE60, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D5120
void *D_002D5120[100] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001141D0, 0, (void *)InitPzlink, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetLoParent, 0, (void *)AddPzlinkHierarchy, 0, (void *)RemovePzlinkHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadLoFromBrx, 0, (void *)PostPzlinkLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)func_001A6110, 0, (void *)func_001A6118, 0, (void *)LO_PmatWorld, 0, (void *)func_001A6B30, 0, (void *)func_001A6120, 0, (void *)func_001A6138, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)bevy_world_loads_b5_apply_xform, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CLo_Clone, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, 0};

// data-ok: retail's bytes at 0X2D52B0
void *D_002D52B0[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113B20, 0, (void *)InitPathzone, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)CPathZone_LoadFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D5450
void *D_002D5450[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114040, 0, (void *)InitSo, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)CSo_LoadFromBrx, 0, (void *)PostPrizeSpewerLoad, 0, (void *)UpdateSo, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderPrizeSpewer, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbSoWkr, 0, 0};

// data-ok: retail's bytes at 0X2D56B8
void *D_002D56B8[16] = {(void *)0xfe70, 0, (void *)0xfe70, (void *)func_001C3BB0, (void *)0xfe70, (void *)func_001C3958, (void *)0xfe70, (void *)func_001C3A08, 0, (void *)func_00182D70, (void *)0xfe70, (void *)func_001C3A88, (void *)0xfe70, (void *)func_00259AF8, 0, 0};

// data-ok: retail's bytes at 0X2D56F8
void *D_002D56F8[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113AC0, 0, (void *)InitPipe__FP4PIPE, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadCrvFromBrx, 0, (void *)PostCrvLoad, 0, (void *)UpdateLo, 0, (void *)func_001E6340, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveCrv, 0, (void *)AddCrv, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)ClonePipe, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D5898
void *D_002D5898[166] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandlePoMessage, 0, (void *)func_00113D30, 0, (void *)InitPo, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)LoadPoFromBrx, 0, (void *)PostSoLoad, 0, (void *)UpdateSo, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)ClonePo, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbSoWkr, 0, (void *)FInvulnerablePo, 0, (void *)func_001C3ED0, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, 0};

// data-ok: retail's bytes at 0X2D5B30
void *D_002D5B30[166] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandlePoMessage, 0, (void *)func_00113EF0, 0, (void *)func_001C8280, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)LoadPoFromBrx, 0, (void *)func_001C82F0, 0, (void *)func_001C8350, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)ClonePo, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbSoWkr, 0, (void *)FInvulnerablePo, 0, (void *)func_001C3ED0, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, 0};

// data-ok: retail's bytes at 0X2D5DC8
void *D_002D5DC8[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A80, 0, (void *)func_001CA788, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadXfmFromBrx, 0, (void *)PostClueLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)ClonePool_AddLoGrfEntry, 0, (void *)ClonePool_RemoveLoGrfEntry, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)func_001CA7B8, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D5F68
void *D_002D5F68[156] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)func_001C5098, 0, (void *)func_00114000, 0, (void *)func_001C7E38, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)LoadDprizeFromBrx, 0, (void *)PostDprizeLoad, 0, (void *)UpdateDprize, 0, (void *)ProjectDprizeTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderDprizeAll, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001C7E68, 0, (void *)func_001C7EA8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbDprizeWkr, 0, (void *)SetCluebottleState, 0, 0};

// data-ok: retail's bytes at 0X2D61D8
void *D_002D61D8[156] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)func_001C5098, 0, (void *)func_00113FF0, 0, (void *)InitCoin__FP4COIN, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)LoadCoinFromBrx, 0, (void *)PostDprizeLoad, 0, (void *)UpdateCoin, 0, (void *)ProjectDprizeTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderDprizeAll, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbDprizeWkr, 0, (void *)SetCoinState, 0, 0};

// data-ok: retail's bytes at 0X2D6448
void *D_002D6448[156] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)func_001C5098, 0, (void *)func_00113FD0, 0, (void *)func_001C6AB8, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)LoadDprizeFromBrx, 0, (void *)PostDprizeLoad, 0, (void *)UpdateDprize, 0, (void *)ProjectDprizeTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderDprizeAll, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbDprizeWkr, 0, (void *)func_001C6B28, 0, 0};

// data-ok: retail's bytes at 0X2D66B8
void *D_002D66B8[156] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)func_001C5098, 0, (void *)func_00113FE0, 0, (void *)func_001C67D8, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)LoadDprizeFromBrx, 0, (void *)PostDprizeLoad, 0, (void *)func_001C6880, 0, (void *)ProjectDprizeTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderDprizeAll, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbDprizeWkr, 0, (void *)func_001C68F0, 0, 0};

// data-ok: retail's bytes at 0X2D6928
void *D_002D6928[312] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)func_001C5098, 0, (void *)func_00113FC0, 0, (void *)func_001C6508, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)LoadDprizeFromBrx, 0, (void *)PostDprizeLoad, 0, (void *)func_001C6588, 0, (void *)ProjectDprizeTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderDprizeAll, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbDprizeWkr, 0, (void *)func_001C65F8, 0, 0, 0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)func_001C5098, 0, (void *)func_00113FB0, 0, (void *)InitDprize, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)LoadDprizeFromBrx, 0, (void *)PostDprizeLoad, 0, (void *)UpdateDprize, 0, (void *)ProjectDprizeTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderDprizeAll, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbDprizeWkr, 0, (void *)SetDprizeDprizes, 0, 0};

// data-ok: retail's bytes at 0X2D6E08
void *D_002D6E08[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113A70, 0, (void *)func_001CA788, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadXfmFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)ClonePool_AddLoGrfEntry, 0, (void *)ClonePool_RemoveLoGrfEntry, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)func_001CA7B8, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D6FA8
void *D_002D6FA8[16] = {(void *)0xfe70, 0, (void *)0xfe70, (void *)func_001CBA68, (void *)0xfe70, (void *)func_001CBAC0, (void *)0xfe70, (void *)func_001CBB58, 0, (void *)func_00182D70, (void *)0xfe70, (void *)func_001CBBA8, (void *)0xfe70, (void *)func_00259B08, 0, 0};

// data-ok: retail's bytes at 0X2D6FE8
void *D_002D6FE8[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113AE0, 0, (void *)func_001CB908, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadCrvFromBrx, 0, (void *)Pipe_PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001E6340, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)Pipe_RemoveLoGrfEntry, 0, (void *)Pipe_AddLoGrfEntry, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)func_001CBA20, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D7188
void *D_002D7188[184] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleStepguardMessage, 0, (void *)func_00113DE0, 0, (void *)func_001CBEB0, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_002064D8, 0, (void *)UpdateSoRoot, 0, (void *)LoadStepFromBrx, 0, (void *)PostGuardLoad, 0, (void *)UpdateGuard, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)RenderStepguardSelf, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)RemoveStepguardHierarchy, 0, (void *)AddStepguardHierarchy, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)OnGuardAdd, 0, (void *)OnGuardRemove, 0, (void *)CReturnZeroLo, 0, (void *)TranslateStepToPos, 0, (void *)RotateStepToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)func_002052E0, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CloneGuard, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_00204C60, 0, (void *)AdjustStepNewXp, 0, (void *)func_001F4FB8, 0, (void *)AdjustStepXpVelocity, 0, (void *)AdjustStepXps, 0, (void *)func_00209C88, 0, (void *)AddStepCustomXps, 0, (void *)func_00206380, 0, (void *)FIsSoLocked, 0, (void *)CgeomExtraStep, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)PresetStepAccel, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbGuardWkr, 0, (void *)FIsGuardInvulnerable, 0, (void *)NGuardAlertLevel, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, (void *)func_00205008, 0, (void *)RetainAloSmKinds, 0, (void *)ReleaseAloSmKinds, 0, (void *)GrfGuardCustomXps, 0, (void *)FIsGuardWkrLethal, 0, (void *)func_001F1F38, 0, (void *)func_002082D0, 0, (void *)func_001CBEE0, 0, (void *)func_001CBF90, 0, 0};
