// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D00A0-0X2D2918 (piece data/new_100008_2cf520), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ALO_SetCloneId();
extern "C" void AddLo();
extern "C" void AddLoHierarchy();
extern "C" void AddSoGravityAcceleration();
extern "C" void AddSoLoHierarchy();
extern "C" void AddSoWaterAcceleration();
extern "C" void AdjustSoXpVelocity();
extern "C" void ApplyXfmProxy();
extern "C" void AttachCrv_Clone();
extern "C" void AttachCrv_FGetWrapRange();
extern "C" void AttachCrv_GetParam();
extern "C" void AttachCrv_GetPosFromParam();
extern "C" void AttachCrv_GetRandomPos();
extern "C" void AttachCrv_Init();
extern "C" void AttachCrv_OnAdd();
extern "C" void AttachCrv_OnRemove();
extern "C" void AttachCrv_PostLoad();
extern "C" void AttachCyl_Clone();
extern "C" void AttachCyl_GetParam();
extern "C" void AttachCyl_GetPosFromParam();
extern "C" void AttachCyl_GetRandomPos();
extern "C" void AttachCyl_Init();
extern "C" void AttachCyl_OnAdd();
extern "C" void AttachCyl_OnRemove();
extern "C" void AttachCyl_PostLoad();
extern "C" void AttachFlat_Clone();
extern "C" void AttachFlat_GetPosFromParam();
extern "C" void AttachFlat_Init();
extern "C" void AttachFlat_OnAdd();
extern "C" void AttachFlat_OnRemove();
extern "C" void AttachFlat_PostLoad();
extern "C" void AttachPt_GetAimPos();
extern "C" void AttachPt_OnAdd();
extern "C" void AttachPt_OnRemove();
extern "C" void AttachZone_GetAimPos();
extern "C" void AttachZone_GetRandomPos();
extern "C" void AttachZone_OnAdd();
extern "C" void AttachZone_OnRemove();
extern "C" void CReturnZeroLo();
extern "C" void CSo_LoadFromBrx();
extern "C" void Chaser_AccelToward();
extern "C" void Chaser_AdjustNewXp();
extern "C" void Chaser_FTakeHit();
extern "C" void Chaser_HandleMessage();
extern "C" void Chaser_Init();
extern "C" void Chaser_OnAdd();
extern "C" void Chaser_PostLoad();
extern "C" void Chaser_Reset();
extern "C" void Chaser_ResetToNone();
extern "C" void Chaser_Update();
extern "C" void ClearLoGrfField();
extern "C" void CloneAloHierarchy();
extern "C" void CloneHbsk__FP4HBSKT0();
extern "C" void CloneLoVirtual();
extern "C" void ClonePo();
extern "C" void CloneXfm();
extern "C" void FAbsorbHbskWkr();
extern "C" void FIgnoreHbskIntersection();
extern "C" void FIgnoreSoIntersection();
extern "C" void FInvulnerablePo();
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
extern "C" void GoalAnimLeap_Deactivate();
extern "C" void GoalAnimLeap_FHandleMessage();
extern "C" void GoalAnimLeap_Update();
extern "C" void GoalAnim_FHandleMessage();
extern "C" void GoalAnim_Update();
extern "C" void GoalBrain_Activate();
extern "C" void GoalBrain_FHandleMessage();
extern "C" void GoalBrain_Init();
extern "C" void GoalBrain_Update();
extern "C" void GoalFollowCrvAnim_Init();
extern "C" void GoalFollowCrvAnim_SetState();
extern "C" void GoalFollowCrvAnim_Update();
extern "C" void GoalFollowCrv_Activate();
extern "C" void GoalFollowCrv_Init();
extern "C" void GoalFollowCrv_SetState();
extern "C" void GoalFollowCrv_Update();
extern "C" void GoalGrab_Activate();
extern "C" void GoalGrab_Init();
extern "C" void GoalHit_Activate();
extern "C" void GoalHit_Deactivate();
extern "C" void GoalHit_Update();
extern "C" void GoalIdle_Activate();
extern "C" void GoalIdle_Deactivate();
extern "C" void GoalIdle_Init();
extern "C" void GoalIdle_Update();
extern "C" void GoalJump_Activate();
extern "C" void GoalKnockDown_Activate();
extern "C" void GoalNotice_Update();
extern "C" void Goal_Deactivate();
extern "C" void Goal_FHandleMessage();
extern "C" void Goal_FillVjoy();
extern "C" void HandleLoMessage();
extern "C" void HandleLoSpliceEvent();
extern "C" void HandlePoMessage();
extern "C" void InitHbsk__FP4HBSK();
extern "C" void LO_SetCloneId();
extern "C" void LiftPt_OnGrab();
extern "C" void LoadCrvFromBrx();
extern "C" void LoadPoFromBrx();
extern "C" void LoadVolumeFromBrx();
extern "C" void LoadXfmFromBrx();
extern "C" void MatchSoOtherObject();
extern "C" void Member_FGetWrapRange();
extern "C" void Member_GetParam();
extern "C" void Member_GetPosFromParam();
extern "C" void Member_GetRandomPos();
extern "C" void Mount_AccelToward();
extern "C" void Mount_FTakeHit();
extern "C" void Mount_Init();
extern "C" void Mount_OnPoActive();
extern "C" void Mount_PostLoad();
extern "C" void Mount_Reset();
extern "C" void Mount_ResetState();
extern "C" void Mount_Update();
extern "C" void OnHbskAdd();
extern "C" void OnHbskPoolClaim();
extern "C" void OnHbskRemove();
extern "C" void OnLoAdd__FP2LO();
extern "C" void OnPoActive();
extern "C" void PmatWorldSo();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void PostSoLoad();
extern "C" void PoxaAllocSo();
extern "C" void PresetHbskAccel__FP4HBSKf();
extern "C" void ProjectSoTransform();
extern "C" void PvtGetCidB1();
extern "C" void PvtGetCidB2();
extern "C" void PvtGetCidB3();
extern "C" void PvtGetCidB7();
extern "C" void PxfFromAloRef();
extern "C" void RemoveLo();
extern "C" void RemoveLoHierarchy();
extern "C" void RemoveSoLoHierarchy();
extern "C" void RotateSoToMat();
extern "C" void RotateXfmToMat();
extern "C" void SetLoGrfField();
extern "C" void SetLoPosMatFromLo();
extern "C" void SetLoPosMatFromXf();
extern "C" void SetPoPlayable();
extern "C" void SetSoAngularVelocityVec();
extern "C" void SetSoParent();
extern "C" void SetSoVelocityVec();
extern "C" void SetXfmParent();
extern "C" void SoHit_Kill();
extern "C" void Swarm_AbsorbTouch();
extern "C" void Swarm_AddSoCustomXps();
extern "C" void Swarm_AdjustNewXp();
extern "C" void Swarm_FTakeHit();
extern "C" void Swarm_Init();
extern "C" void Swarm_PostLoad();
extern "C" void Swarm_Render();
extern "C" void Swarm_Reset();
extern "C" void Swarm_Update();
extern "C" void Swarm_UpdateBounds();
extern "C" void TranslateSoToPos();
extern "C" void TranslateXfmToPos();
extern "C" void UntriggerDialog__FP6DIALOG();
extern "C" void UpdateAloXfWorldHierarchy();
extern "C" void UpdateLo();
extern "C" void UpdateSo();
extern "C" void UpdateSoBounds();
extern "C" void UpdateSoRoot();
extern "C" void bevy_physics_driver_1f9e70();
extern "C" void func_00113AD0();
extern "C" void func_00113BC0();
extern "C" void func_00113C30();
extern "C" void func_00113C40();
extern "C" void func_00113C50();
extern "C" void func_00113C70();
extern "C" void func_00113E80();
extern "C" void func_00113E90();
extern "C" void func_00113EA0();
extern "C" void func_00113EB0();
extern "C" void func_00113EC0();
extern "C" void func_00113ED0();
extern "C" void func_00113F90();
extern "C" void func_001143D0();
extern "C" void func_001143E0();
extern "C" void func_001143F0();
extern "C" void func_00114400();
extern "C" void func_00114410();
extern "C" void func_00114420();
extern "C" void func_00114430();
extern "C" void func_00114440();
extern "C" void func_00114450();
extern "C" void func_00114460();
extern "C" void func_00114470();
extern "C" void func_00114480();
extern "C" void func_001144B0();
extern "C" void func_001144D0();
extern "C" void func_001144E0();
extern "C" void func_00114500();
extern "C" void func_00114510();
extern "C" void func_00132B08();
extern "C" void func_00174920();
extern "C" void func_00174950();
extern "C" void func_00174B28();
extern "C" void func_00174EA0();
extern "C" void func_00174F08();
extern "C" void func_00174FC8();
extern "C" void func_00174FF8();
extern "C" void func_00175090();
extern "C" void func_001750E0();
extern "C" void func_001751C0();
extern "C" void func_001751F0();
extern "C" void func_00175258();
extern "C" void func_001752C0();
extern "C" void func_001752F0();
extern "C" void func_001753D8();
extern "C" void func_00175410();
extern "C" void func_00175448();
extern "C" void func_00175600();
extern "C" void func_001756C0();
extern "C" void func_00175758();
extern "C" void func_00175790();
extern "C" void func_001757D0();
extern "C" void func_001796A0();
extern "C" void func_001796D0();
extern "C" void func_00179750();
extern "C" void func_00179780();
extern "C" void func_00179820();
extern "C" void func_00179868();
extern "C" void func_00179A20();
extern "C" void func_00179F70();
extern "C" void func_0017A3D0();
extern "C" void func_0017A400();
extern "C" void func_0017A4B0();
extern "C" void func_0017A4E8();
extern "C" void func_0017A558();
extern "C" void func_0017A670();
extern "C" void func_0017A6F8();
extern "C" void func_0017A730();
extern "C" void func_0017A7B8();
extern "C" void func_0017A7F8();
extern "C" void func_0017B578();
extern "C" void func_0017B590();
extern "C" void func_0017B5C0();
extern "C" void func_0017B5F0();
extern "C" void func_0017B620();
extern "C" void func_0017B690();
extern "C" void func_0017B808();
extern "C" void func_0017B840();
extern "C" void func_0017B870();
extern "C" void func_0017BD78();
extern "C" void func_0017BED0();
extern "C" void func_0017BF08();
extern "C" void func_0017BFB8();
extern "C" void func_0017C3E8();
extern "C" void func_0017C638();
extern "C" void func_0017C670();
extern "C" void func_0017C6A0();
extern "C" void func_0017C6D0();
extern "C" void func_0017F090();
extern "C" void func_0017F110();
extern "C" void func_0017F138();
extern "C" void func_0017F170();
extern "C" void func_0017F1A0();
extern "C" void func_0017F1D0();
extern "C" void func_0017F6B0();
extern "C" void func_00180188();
extern "C" void func_001801B8();
extern "C" void func_001803E0();
extern "C" void func_00181408();
extern "C" void func_00181440();
extern "C" void func_00181478();
extern "C" void func_00181598();
extern "C" void func_00182778();
extern "C" void func_00182D70();
extern "C" void func_00182E78();
extern "C" void func_00183498();
extern "C" void func_00183F08();
extern "C" void func_00183F50();
extern "C" void func_00184130();
extern "C" void func_00184238();
extern "C" void func_00184268();
extern "C" void func_001842B0();
extern "C" void func_001843C0();
extern "C" void func_001843F0();
extern "C" void func_001A5B80();
extern "C" void func_001A5E80();
extern "C" void func_001A5ED8();
extern "C" void func_001A5EE0();
extern "C" void func_001A6130();
extern "C" void func_001A6148();
extern "C" void func_001A6C48();
extern "C" void func_001A6DC0();
extern "C" void func_001A6DC8();
extern "C" void func_001A6E80();
extern "C" void func_001A6EF0();
extern "C" void func_001A6EF8();
extern "C" void func_001C3ED0();
extern "C" void func_001C41B8();
extern "C" void func_001C4228();
extern "C" void func_001CB4E0();
extern "C" void func_001CB5C8();
extern "C" void func_001CB5D0();
extern "C" void func_001E6340();
extern "C" void func_001EEFA0();
extern "C" void func_001EEFB8();
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
extern "C" void func_002599F0();
extern "C" void func_00259A00();
extern "C" void func_00259A10();
extern "C" void func_00259A20();
extern "C" void func_00259A30();
extern "C" void func_00259A40();

// data-ok: retail's bytes at 0X2D00A0
void *D_002D00A0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidB7, 0, (void *)func_0017C638, 0, (void *)func_0017C6A0, 0, (void *)func_0017C670, 0, (void *)func_0017C6D0, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0120
void *D_002D0120[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidB3, 0, (void *)func_0017BED0, 0, (void *)func_0017BF08, 0, (void *)func_0017BFB8, 0, (void *)func_0017C3E8, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D01A0
void *D_002D01A0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidB2, 0, (void *)func_0017B808, 0, (void *)func_0017B840, 0, (void *)func_0017B870, 0, (void *)func_0017BD78, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0220
void *D_002D0220[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001144E0, 0, (void *)func_0017B590, 0, (void *)func_0017B5C0, 0, (void *)func_0017B5F0, 0, (void *)func_0017B620, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)func_0017B690, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D02A0
void *D_002D02A0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114500, 0, (void *)func_0017A4B0, 0, (void *)func_0017A4E8, 0, (void *)func_0017A558, 0, (void *)func_0017A670, 0, (void *)func_00174F08, 0, (void *)func_00174EA0, 0, (void *)GoalAnim_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0320
void *D_002D0320[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001144D0, 0, (void *)func_00179F70, 0, (void *)GoalJump_Activate, 0, (void *)func_0017A3D0, 0, (void *)func_0017A400, 0, (void *)func_00174F08, 0, (void *)func_00174EA0, 0, (void *)GoalAnim_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D03A0
void *D_002D03A0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)PvtGetCidB1, 0, (void *)GoalGrab_Init, 0, (void *)GoalGrab_Activate, 0, (void *)GoalAnimLeap_Deactivate, 0, (void *)GoalAnimLeap_Update, 0, (void *)func_00174F08, 0, (void *)func_0017B578, 0, (void *)GoalAnimLeap_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0420
void *D_002D0420[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114510, 0, (void *)func_0017A6F8, 0, (void *)func_0017A730, 0, (void *)func_0017A7B8, 0, (void *)func_0017A7F8, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D04A0
void *D_002D04A0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001143D0, 0, (void *)GoalBrain_Init, 0, (void *)GoalBrain_Activate, 0, (void *)Goal_Deactivate, 0, (void *)GoalBrain_Update, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)GoalBrain_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0520
void *D_002D0520[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001144B0, 0, (void *)GoalIdle_Init, 0, (void *)GoalIdle_Activate, 0, (void *)GoalIdle_Deactivate, 0, (void *)GoalIdle_Update, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D05A0
void *D_002D05A0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114460, 0, (void *)func_00175758, 0, (void *)func_00175790, 0, (void *)func_001757D0, 0, (void *)GoalNotice_Update, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0620
void *D_002D0620[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114450, 0, (void *)func_001753D8, 0, (void *)func_00175410, 0, (void *)func_00175448, 0, (void *)func_00175600, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)func_001756C0, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D06A0
void *D_002D06A0[34] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114480, 0, (void *)GoalFollowCrvAnim_Init, 0, (void *)GoalFollowCrv_Activate, 0, (void *)Goal_Deactivate, 0, (void *)GoalFollowCrvAnim_Update, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, (void *)GoalFollowCrvAnim_SetState, 0, 0};

// data-ok: retail's bytes at 0X2D0728
void *D_002D0728[34] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114470, 0, (void *)GoalFollowCrv_Init, 0, (void *)GoalFollowCrv_Activate, 0, (void *)Goal_Deactivate, 0, (void *)GoalFollowCrv_Update, 0, (void *)func_001EEFB8, 0, (void *)func_001EEFA0, 0, (void *)Goal_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, (void *)GoalFollowCrv_SetState, 0, 0};

// data-ok: retail's bytes at 0X2D07B0
void *D_002D07B0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114400, 0, (void *)func_001751C0, 0, (void *)func_001751F0, 0, (void *)func_001752C0, 0, (void *)func_00175258, 0, (void *)func_00174F08, 0, (void *)func_00174EA0, 0, (void *)func_001752F0, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0830
void *D_002D0830[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114430, 0, (void *)func_00179750, 0, (void *)func_00179780, 0, (void *)func_00179820, 0, (void *)GoalHit_Update, 0, (void *)func_00174F08, 0, (void *)func_00174EA0, 0, (void *)GoalAnim_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D08B0
void *D_002D08B0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114440, 0, (void *)func_00179868, 0, (void *)GoalKnockDown_Activate, 0, (void *)func_00179A20, 0, (void *)GoalHit_Update, 0, (void *)func_00174F08, 0, (void *)func_00174EA0, 0, (void *)GoalAnim_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0930
void *D_002D0930[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114420, 0, (void *)func_001796A0, 0, (void *)func_001796D0, 0, (void *)GoalHit_Deactivate, 0, (void *)GoalHit_Update, 0, (void *)func_00174F08, 0, (void *)func_00174EA0, 0, (void *)GoalAnim_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D09B0
void *D_002D09B0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114410, 0, (void *)func_00174920, 0, (void *)GoalHit_Activate, 0, (void *)GoalHit_Deactivate, 0, (void *)GoalHit_Update, 0, (void *)func_00174F08, 0, (void *)func_00174EA0, 0, (void *)GoalAnim_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0A30
void *D_002D0A30[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001143F0, 0, (void *)func_00174FC8, 0, (void *)func_00174FF8, 0, (void *)func_00175090, 0, (void *)GoalAnim_Update, 0, (void *)func_00174F08, 0, (void *)func_00174EA0, 0, (void *)func_001750E0, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0AB0
void *D_002D0AB0[32] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_001143E0, 0, (void *)func_00174920, 0, (void *)func_00174950, 0, (void *)func_00174B28, 0, (void *)GoalAnim_Update, 0, (void *)func_00174F08, 0, (void *)func_00174EA0, 0, (void *)GoalAnim_FHandleMessage, 0, (void *)Goal_FillVjoy, 0, 0};

// data-ok: retail's bytes at 0X2D0B30
void *D_002D0B30[170] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandlePoMessage, 0, (void *)func_00113ED0, 0, (void *)Swarm_Init, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_0017F110, 0, (void *)UpdateSoRoot, 0, (void *)LoadPoFromBrx, 0, (void *)Swarm_PostLoad, 0, (void *)Swarm_Update, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)Swarm_Render, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_0017F170, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)ClonePo, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)Swarm_UpdateBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)Swarm_AdjustNewXp, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)Swarm_AddSoCustomXps, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_00182778, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)Swarm_FTakeHit, 0, (void *)FInvulnerablePo, 0, (void *)func_001C3ED0, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, (void *)Swarm_AbsorbTouch, 0, (void *)Swarm_Reset, 0, 0};

// data-ok: retail's bytes at 0X2D0DD8
void *D_002D0DD8[170] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandlePoMessage, 0, (void *)func_00113EC0, 0, (void *)func_00181408, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_0017F110, 0, (void *)UpdateSoRoot, 0, (void *)LoadPoFromBrx, 0, (void *)func_00181440, 0, (void *)func_00181478, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_0017F170, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)ClonePo, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_0017F1A0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)func_0017F1D0, 0, (void *)FInvulnerablePo, 0, (void *)func_001C3ED0, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, (void *)SoHit_Kill, 0, (void *)func_00181598, 0, 0};

// data-ok: retail's bytes at 0X2D1080
void *D_002D1080[170] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)Chaser_HandleMessage, 0, (void *)func_00113EA0, 0, (void *)Chaser_Init, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)Chaser_ResetToNone, 0, (void *)UpdateSoRoot, 0, (void *)LoadPoFromBrx, 0, (void *)Chaser_PostLoad, 0, (void *)Chaser_Update, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)Chaser_OnAdd, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)ClonePo, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)Chaser_AdjustNewXp, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)Chaser_AccelToward, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)Chaser_FTakeHit, 0, (void *)FInvulnerablePo, 0, (void *)func_001C3ED0, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, (void *)SoHit_Kill, 0, (void *)Chaser_Reset, 0, 0};

// data-ok: retail's bytes at 0X2D1328
void *D_002D1328[170] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandlePoMessage, 0, (void *)func_00113EB0, 0, (void *)func_00180188, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_0017F110, 0, (void *)UpdateSoRoot, 0, (void *)LoadPoFromBrx, 0, (void *)func_0017F138, 0, (void *)func_001801B8, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_0017F170, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)ClonePo, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001803E0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)UntriggerDialog__FP6DIALOG, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)func_0017F1D0, 0, (void *)FInvulnerablePo, 0, (void *)func_001C3ED0, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, (void *)SoHit_Kill, 0, (void *)func_0017F6B0, 0, 0};

// data-ok: retail's bytes at 0X2D15D0
void *D_002D15D0[170] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandlePoMessage, 0, (void *)func_00113E90, 0, (void *)Mount_Init, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)Mount_Reset, 0, (void *)UpdateSoRoot, 0, (void *)LoadPoFromBrx, 0, (void *)Mount_PostLoad, 0, (void *)Mount_Update, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_0017F170, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)ClonePo, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_0017F1A0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)Mount_AccelToward, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)Mount_FTakeHit, 0, (void *)FInvulnerablePo, 0, (void *)func_001C3ED0, 0, (void *)Mount_OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, (void *)SoHit_Kill, 0, (void *)Mount_ResetState, 0, 0};

// data-ok: retail's bytes at 0X2D1878
void *D_002D1878[170] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandlePoMessage, 0, (void *)func_00113E80, 0, (void *)func_0017F090, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)func_0017F110, 0, (void *)UpdateSoRoot, 0, (void *)LoadPoFromBrx, 0, (void *)func_0017F138, 0, (void *)UpdateSo, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)func_001F3E00, 0, (void *)func_001F3EA8, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)func_0017F170, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)ClonePo, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_0017F1A0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreSoIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)AddSoGravityAcceleration, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)func_0017F1D0, 0, (void *)FInvulnerablePo, 0, (void *)func_001C3ED0, 0, (void *)OnPoActive, 0, (void *)SetPoPlayable, 0, (void *)func_001C41B8, 0, (void *)func_001C4228, 0, (void *)SoHit_Kill, 0, (void *)func_0017F6B0, 0, 0};

// data-ok: retail's bytes at 0X2D1B20
void *D_002D1B20[16] = {(void *)0xfed0, 0, 0, (void *)Member_FGetWrapRange, 0, (void *)Member_GetParam, (void *)0xfed0, (void *)AttachZone_GetAimPos, 0, (void *)func_00182D70, (void *)0xfed0, (void *)AttachZone_GetRandomPos, (void *)0xfed0, (void *)func_00259A40, 0, 0};

// data-ok: retail's bytes at 0X2D1B60
void *D_002D1B60[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113BC0, 0, (void *)func_001843C0, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadVolumeFromBrx, 0, (void *)func_001843F0, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)AttachZone_OnRemove, 0, (void *)AttachZone_OnAdd, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D1D00
void *D_002D1D00[106] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113C50, 0, (void *)func_00184268, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadXfmFromBrx, 0, (void *)func_001842B0, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)AttachPt_OnRemove, 0, (void *)AttachPt_OnAdd, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, (void *)LiftPt_OnGrab, 0, 0};

// data-ok: retail's bytes at 0X2D1EA8
void *D_002D1EA8[16] = {(void *)0xff20, 0, 0, (void *)Member_FGetWrapRange, 0, (void *)Member_GetParam, (void *)0xff20, (void *)AttachPt_GetAimPos, (void *)0xff20, (void *)func_00184238, 0, (void *)Member_GetRandomPos, (void *)0xff20, (void *)func_00259A30, 0, 0};

// data-ok: retail's bytes at 0X2D1EE8
void *D_002D1EE8[106] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113C40, 0, (void *)func_00183F08, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadXfmFromBrx, 0, (void *)func_00183F50, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)AttachPt_OnRemove, 0, (void *)AttachPt_OnAdd, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)CloneXfm, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, (void *)func_00184130, 0, 0};

// data-ok: retail's bytes at 0X2D2090
void *D_002D2090[16] = {(void *)0xfeb0, 0, 0, (void *)Member_FGetWrapRange, 0, (void *)Member_GetParam, 0, (void *)Member_GetPosFromParam, 0, (void *)func_00182D70, 0, (void *)Member_GetRandomPos, (void *)0xfeb0, (void *)func_00259A20, 0, 0};

// data-ok: retail's bytes at 0X2D20D0
void *D_002D20D0[154] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113F90, 0, (void *)InitHbsk__FP4HBSK, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetSoParent, 0, (void *)AddSoLoHierarchy, 0, (void *)RemoveSoLoHierarchy, 0, (void *)UpdateSoRoot, 0, (void *)CSo_LoadFromBrx, 0, (void *)PostSoLoad, 0, (void *)UpdateSo, 0, (void *)ProjectSoTransform, 0, (void *)UpdateAloXfWorldHierarchy, 0, (void *)func_001F3C70, 0, (void *)func_001F3CC8, 0, (void *)func_001F3B28, 0, (void *)OnHbskRemove, 0, (void *)OnHbskAdd, 0, (void *)func_00210330, 0, (void *)ALO_SetCloneId, 0, (void *)OnHbskPoolClaim, 0, (void *)func_001CB5D0, 0, (void *)CReturnZeroLo, 0, (void *)TranslateSoToPos, 0, (void *)RotateSoToMat, 0, (void *)PmatWorldSo, 0, (void *)func_001F3FB0, 0, (void *)GetSoVelocityVec, 0, (void *)GetSoAngularVelocityVec, 0, (void *)SetSoVelocityVec, 0, (void *)SetSoAngularVelocityVec, 0, (void *)func_001F4010, 0, (void *)MatchSoOtherObject, 0, (void *)func_001F4A80, 0, (void *)CloneAloHierarchy, 0, (void *)CloneHbsk__FP4HBSKT0, 0, (void *)func_001F3118, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC8, 0, (void *)func_001F2FE0, 0, (void *)func_001F3078, 0, (void *)UpdateSoBounds, 0, (void *)GetSoCpdefi__FP2SOfP6CPDEFI, 0, (void *)PxfFromAloRef, 0, (void *)func_001F4CA0, 0, (void *)PoxaAllocSo, 0, (void *)func_001F5988, 0, (void *)func_001F4FB0, 0, (void *)func_001F4FB8, 0, (void *)func_001F4FC0, 0, (void *)func_001F4F10, 0, (void *)func_001F4FA8, 0, (void *)func_001F5990, 0, (void *)FIgnoreHbskIntersection, 0, (void *)FIsSoLocked, 0, (void *)func_001F5998, 0, (void *)func_001F3590, 0, (void *)bevy_physics_driver_1f9e70, 0, (void *)func_001FA328, 0, (void *)func_001FA528, 0, (void *)AdjustSoXpVelocity, 0, (void *)func_001FADD0, 0, (void *)PresetHbskAccel__FP4HBSKf, 0, (void *)func_002297F0, 0, (void *)AddSoWaterAcceleration, 0, (void *)FPointInAloParts, 0, (void *)func_001F7410, 0, (void *)FAbsorbHbskWkr, 0, 0};

// data-ok: retail's bytes at 0X2D2338
void *D_002D2338[16] = {(void *)0xff20, 0, 0, (void *)Member_FGetWrapRange, 0, (void *)Member_GetParam, (void *)0xff20, (void *)AttachFlat_GetPosFromParam, 0, (void *)func_00182D70, 0, (void *)Member_GetRandomPos, (void *)0xff20, (void *)func_00259A10, 0, 0};

// data-ok: retail's bytes at 0X2D2378
void *D_002D2378[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113C70, 0, (void *)AttachFlat_Init, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadXfmFromBrx, 0, (void *)AttachFlat_PostLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)AttachFlat_OnRemove, 0, (void *)AttachFlat_OnAdd, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)AttachFlat_Clone, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D2518
void *D_002D2518[16] = {(void *)0xff20, 0, (void *)0xff20, (void *)func_00183498, (void *)0xff20, (void *)AttachCyl_GetParam, (void *)0xff20, (void *)AttachCyl_GetPosFromParam, 0, (void *)func_00182D70, (void *)0xff20, (void *)AttachCyl_GetRandomPos, (void *)0xff20, (void *)func_00259A00, 0, 0};

// data-ok: retail's bytes at 0X2D2558
void *D_002D2558[104] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113C30, 0, (void *)AttachCyl_Init, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadXfmFromBrx, 0, (void *)AttachCyl_PostLoad, 0, (void *)UpdateLo, 0, (void *)func_001A5E80, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)AttachCyl_OnRemove, 0, (void *)AttachCyl_OnAdd, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)AttachCyl_Clone, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0};

// data-ok: retail's bytes at 0X2D26F8
void *D_002D26F8[16] = {(void *)0xfe70, 0, (void *)0xfe70, (void *)AttachCrv_FGetWrapRange, (void *)0xfe70, (void *)AttachCrv_GetParam, (void *)0xfe70, (void *)AttachCrv_GetPosFromParam, 0, (void *)func_00182D70, (void *)0xfe70, (void *)AttachCrv_GetRandomPos, (void *)0xfe70, (void *)func_002599F0, 0, 0};

// data-ok: retail's bytes at 0X2D2738
void *D_002D2738[120] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)HandleLoSpliceEvent, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00113AD0, 0, (void *)AttachCrv_Init, 0, (void *)AddLo, 0, (void *)RemoveLo, 0, (void *)SetXfmParent, 0, (void *)AddLoHierarchy, 0, (void *)RemoveLoHierarchy, 0, (void *)func_001A5B80, 0, (void *)LoadCrvFromBrx, 0, (void *)AttachCrv_PostLoad, 0, (void *)UpdateLo, 0, (void *)func_001E6340, 0, (void *)func_0022FBD8, 0, (void *)func_001A5ED8, 0, (void *)func_001A5EE0, 0, (void *)func_001A6E80, 0, (void *)AttachCrv_OnRemove, 0, (void *)AttachCrv_OnAdd, 0, (void *)func_00210330, 0, (void *)LO_SetCloneId, 0, (void *)func_001CB4E0, 0, (void *)func_001CB5C8, 0, (void *)CReturnZeroLo, 0, (void *)TranslateXfmToPos, 0, (void *)RotateXfmToMat, 0, (void *)GetXfmMatWorld, 0, (void *)func_00231550, 0, (void *)GetXfmVelocity, 0, (void *)GetXfmAngularVelocity, 0, (void *)func_001A6130, 0, (void *)func_001A6148, 0, (void *)ApplyXfmProxy, 0, (void *)SetLoPosMatFromLo, 0, (void *)SetLoPosMatFromXf, 0, (void *)CloneLoVirtual, 0, (void *)AttachCrv_Clone, 0, (void *)func_001A6C48, 0, (void *)FReturnFalseLo, 0, (void *)func_001A6EF0, 0, (void *)func_001A6EF8, 0, (void *)func_001A6DC0, 0, (void *)SetLoGrfField, 0, (void *)ClearLoGrfField, 0, (void *)FUN_0012a860, 0, (void *)func_00231220, 0, 0, 0, 0, 0, (void *)Member_FGetWrapRange, 0, (void *)Member_GetParam, 0, (void *)Member_GetPosFromParam, 0, (void *)func_00182D70, 0, (void *)Member_GetRandomPos, 0, (void *)func_00182E78, 0, 0};
