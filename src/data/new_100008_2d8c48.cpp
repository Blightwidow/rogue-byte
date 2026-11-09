// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D8C48-0X2D9BE0 (piece data/new_100008_2d8c48), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ALO_SetCloneId();
extern "C" void AddLo();
extern "C" void AddLoHierarchy();
extern "C" void AddSoGravityAcceleration();
extern "C" void AddSoLoHierarchy();
extern "C" void AddSoWaterAcceleration();
extern "C" void AdjustSoXpVelocity();
extern "C" void ApplyXfmProxy();
extern "C" void CLo_Clone();
extern "C" void CReturnZeroLo();
extern "C" void CSeq_Clone();
extern "C" void CSeq_LoadFromBrx();
extern "C" void CSm_LoadFromBrx();
extern "C" void CSo_Clone();
extern "C" void CSo_LoadFromBrx();
extern "C" void ClearLoGrfField();
extern "C" void CloneAloHierarchy();
extern "C" void CloneCrv();
extern "C" void CloneLoVirtual();
extern "C" void CloneSaa();
extern "C" void FAbsorbSoWkr();
extern "C" void FIgnoreSoIntersection();
extern "C" void FIsSoLocked();
extern "C" void FMatchesSaaOid();
extern "C" void FPointInAloParts();
extern "C" void FReturnFalseLo();
extern "C" void FUN_0012a860();
extern "C" void GetSoAngularVelocityVec();
extern "C" void GetSoCpdefi__FP2SOfP6CPDEFI();
extern "C" void GetSoVelocityVec();
extern "C" void GetXfmAngularVelocity();
extern "C" void GetXfmMatWorld();
extern "C" void GetXfmVelocity();
extern "C" void Goal_Deactivate();
extern "C" void Goal_FHandleMessage();
extern "C" void Goal_FillVjoy();
extern "C" void HandleLoMessage();
extern "C" void HandleLoSpliceEvent();
extern "C" void HandleSmaMessage();
extern "C" void InitCircler__FP7CIRCLERP4SAAF();
extern "C" void InitCrv();
extern "C" void InitEyes__FP4EYESP4SAAF();
extern "C" void InitJsg();
extern "C" void InitLoop__FP4LOOPP4SAAF();
extern "C" void InitPingpong__FP8PINGPONGP4SAAF();
extern "C" void InitSaa();
extern "C" void InitScroller__FP8SCROLLERP4SAAF();
extern "C" void InitSm();
extern "C" void InitSo();
extern "C" void LO_PmatWorld();
extern "C" void LO_SetCloneId();
extern "C" void LoadCrvFromBrx();
extern "C" void MatchSoOtherObject();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PartHandle_AddRef();
extern "C" void PmatWorldSo();
extern "C" void PostLoLoad();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void PostSmLoad();
extern "C" void PostSoLoad();
extern "C" void PoxaAllocSo();
extern "C" void ProjectSoTransform();
extern "C" void PsaiFromEyesShd__FP4EYESP3SHD();
extern "C" void PxfFromAloRef();
extern "C" void RemoveAloHierarchy();
extern "C" void RemoveLo();
extern "C" void RemoveLoHierarchy();
extern "C" void RemoveSoLoHierarchy();
extern "C" void RotateSoToMat();
extern "C" void RotateXfmToMat();
extern "C" void SendSmaMessage();
extern "C" void SetLoGrfField();
extern "C" void SetLoParent();
extern "C" void SetLoPosMatFromLo();
extern "C" void SetLoPosMatFromXf();
extern "C" void SetSoAngularVelocityVec();
extern "C" void SetSoParent();
extern "C" void SetSoVelocityVec();
extern "C" void SetXfmParent();
extern "C" void Sm_Release();
extern "C" void Sma_AddRef();
extern "C" void Sma_Release();
extern "C" void TranslateSoToPos();
extern "C" void TranslateXfmToPos();
extern "C" void UCompleteCircler__FP7CIRCLER();
extern "C" void UCompleteLoop__FP4LOOP();
extern "C" void UCompletePingpong__FP8PINGPONG();
extern "C" void UCompleteSaa__FP3SAA();
extern "C" void UCompleteScroller__FP8SCROLLER();
extern "C" void UpdateAloXfWorldHierarchy();
extern "C" void UpdateCircler__FP7CIRCLERf();
extern "C" void UpdateEyes__FP4EYESf();
extern "C" void UpdateJsg();
extern "C" void UpdateLo();
extern "C" void UpdateLoop__FP4LOOPf();
extern "C" void UpdatePingpong__FP8PINGPONGf();
extern "C" void UpdateScroller__FP8SCROLLERf();
extern "C" void UpdateShuffle__FP7SHUFFLEf();
extern "C" void UpdateSo();
extern "C" void UpdateSoBounds();
extern "C" void UpdateSoRoot();
extern "C" void bevy_gfx_screen_C2d9500_v15();
extern "C" void bevy_physics_driver_1f9e70();
extern "C" void bevy_world_loads_b5_apply_xform();
extern "C" void func_00113AB0();
extern "C" void func_00113D10();
extern "C" void func_00114020();
extern "C" void func_001140B0();
extern "C" void func_00114100();
extern "C" void func_00114130();
extern "C" void func_00114290();
extern "C" void func_001142B0();
extern "C" void func_001142C0();
extern "C" void func_001142D0();
extern "C" void func_001142E0();
extern "C" void func_001142F0();
extern "C" void func_00114300();
extern "C" void func_00114310();
extern "C" void func_00114350();
extern "C" void func_001143C0();
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
extern "C" void func_001E6340();
extern "C" void func_001E9858();
extern "C" void func_001E9AC0();
extern "C" void func_001EDA50();
extern "C" void func_001EEF68();
extern "C" void func_001EEF70();
extern "C" void func_001EEF98();
extern "C" void func_001EEFA0();
extern "C" void func_001EEFB8();
extern "C" void func_001EF850();
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
extern "C" void func_0022FBD8();
extern "C" void func_00231220();
extern "C" void func_00231550();

// data-ok: retail's bytes at 0X2D8C48
void *D_002D8C48[100] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114130, 0, (void *)InitJsg, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetLoParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)CSeq_LoadFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateJsg, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)func_001A6110, 0, (void *)func_001A6118, 0, (void *)LO_PmatWorld, 0, (void *)func_001A6B30, 0, (void *)func_001A6120, 0, (void *)func_001A6138, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)bevy_world_loads_b5_apply_xform, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CSeq_Clone, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, 0};

// data-ok: retail's bytes at 0X2D8DD8
void *D_002D8DD8[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001140B0, 0, (void *)InitSo, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)CSo_LoadFromBrx, 0, (void *)func_001E9858, 0, (void *)UpdateSo, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001E9AC0, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbSoWkr, 0, 0};

// data-ok: retail's bytes at 0X2D9040
void *D_002D9040[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113AB0, 0, (void *)InitCrv, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadCrvFromBrx, 0, (void *)PostLoLoad, 0, (void *)UpdateLo, 0, (void *)func_001E6340, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneCrv, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D91E0
void *D_002D91E0[24] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114310, 0, (void *)InitCircler__FP7CIRCLERP4SAAF, 0, (void *)UpdateCircler__FP7CIRCLERf, 0, (void *)UCompleteCircler__FP7CIRCLER, 0, (void *)FMatchesSaaOid, 0, 0};

// data-ok: retail's bytes at 0X2D9240
void *D_002D9240[24] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114300, 0, (void *)InitScroller__FP8SCROLLERP4SAAF, 0, (void *)UpdateScroller__FP8SCROLLERf, 0, (void *)UCompleteScroller__FP8SCROLLER, 0, (void *)FMatchesSaaOid, 0, 0};

// data-ok: retail's bytes at 0X2D92A0
void *D_002D92A0[24] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001142F0, 0, (void *)InitEyes__FP4EYESP4SAAF, 0, (void *)UpdateEyes__FP4EYESf, 0, (void *)UCompleteSaa__FP3SAA, 0, (void *)PsaiFromEyesShd__FP4EYESP3SHD, 0, 0};

// data-ok: retail's bytes at 0X2D9300
void *D_002D9300[24] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001142E0, 0, (void *)CloneSaa, 0, (void *)UpdateShuffle__FP7SHUFFLEf, 0, (void *)UCompleteSaa__FP3SAA, 0, (void *)FMatchesSaaOid, 0, 0};

// data-ok: retail's bytes at 0X2D9360
void *D_002D9360[24] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001142D0, 0, (void *)InitPingpong__FP8PINGPONGP4SAAF, 0, (void *)UpdatePingpong__FP8PINGPONGf, 0, (void *)UCompletePingpong__FP8PINGPONG, 0, (void *)FMatchesSaaOid, 0, 0};

// data-ok: retail's bytes at 0X2D93C0
void *D_002D93C0[48] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001142C0, 0, (void *)InitLoop__FP4LOOPP4SAAF, 0, (void *)UpdateLoop__FP4LOOPf, 0, (void *)UCompleteLoop__FP4LOOP, 0, (void *)FMatchesSaaOid, 0, 0, 0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001142B0, 0, (void *)InitSaa, 0, (void *)func_001EDA50, 0, (void *)UCompleteSaa__FP3SAA, 0, (void *)FMatchesSaaOid, 0, 0};

// data-ok: retail's bytes at 0X2D9480
void *D_002D9480[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001143C0, 0, (void *)func_001EEF68, 0, (void *)func_001EEF70, 0, (void *)Goal_Deactivate, 0, (void *)func_001EEF98, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D9500
void *D_002D9500[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114020, 0, (void *)InitSo, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)CSo_LoadFromBrx, 0, (void *)func_001EF850, 0, (void *)bevy_gfx_screen_C2d9500_v15, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbSoWkr, 0, 0};

// data-ok: retail's bytes at 0X2D9768
void *D_002D9768[16] = {0, 0, 0, (void *)Sma_AddRef, 0, (void *)Sma_Release, 0, (void *)PostScriptMessage, 0, (void *)SendSmaMessage, 0, (void *)HandleSmaMessage, 0, (void *)func_00114290, 0, 0};

// data-ok: retail's bytes at 0X2D97A8
void *D_002D97A8[116] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114100, 0, (void *)InitSm, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetLoParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)CSm_LoadFromBrx, 0, (void *)PostSmLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)RemoveAloHierarchy, 0, (void *)func_001A6178, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)func_001A6110, 0, (void *)func_001A6118, 0, (void *)LO_PmatWorld, 0, (void *)func_001A6B30, 0, (void *)func_001A6120, 0, (void *)func_001A6138, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)bevy_world_loads_b5_apply_xform, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CLo_Clone, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, 0, 0, 0, 0, (void *)PartHandle_AddRef, 0, (void *)Sm_Release, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114350, 0, 0};

// data-ok: retail's bytes at 0X2D9978
void *D_002D9978[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113D10, 0, (void *)InitSo, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)CSo_LoadFromBrx, 0, (void *)PostSoLoad, 0, (void *)UpdateSo, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_001CB518, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CSo_Clone, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbSoWkr, 0, 0};
