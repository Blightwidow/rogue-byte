// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2AC880-0X2BAAE8 (piece data/brx), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void AddSensorLo();
extern "C" void AddSpawnerOffset();
extern "C" void AddStgActionShow();
extern "C" void CHitClingingGuard();
extern "C" void CidGetBasic();
extern "C" void FAsegaGone();
extern "C" void FEndTaskComplete();
extern "C" void FGadgetObjCanStick();
extern "C" void FGadgetObjKept();
extern "C" void FGetVolbtnPushObjectsWithinList();
extern "C" void FHitFxGone();
extern "C" void FIsCurrentJob();
extern "C" void FIsCurrentTask();
extern "C" void FIsJsgActive();
extern "C" void FIsPoSwFocus();
extern "C" void FIsPoSwFocusBase();
extern "C" void FPausedEmitter__FP7EMITTER();
extern "C" void FReconTargetDone();
extern "C" void FSwHandsOff();
extern "C" void FTaskComplete();
extern "C" void GetEmitterBlipmk();
extern "C" void GetEmitterRipt();
extern "C" void GetJtPower();
extern "C" void GetLoEulerDegrees();
extern "C" void GetPoVjoyMode();
extern "C" void GetSmaCur();
extern "C" void GetSmaGoal();
extern "C" void GetSoDvGravity();
extern "C" void GetSoNoXpsAll();
extern "C" void GetWrWavelength__FP2WRPf();
extern "C" void InferExpl();
extern "C" void LootId();
extern "C" void PattachCrv();
extern "C" void PemitbEnsureEmitter();
extern "C" void PemitblipEnsureEmitter();
extern "C" void PemitripEnsureEmitter();
extern "C" void PloLeased();
extern "C" void PmatLoWorld();
extern "C" void PosLoWorld();
extern "C" void PpoSwFocus();
extern "C" void PpoSwFocusBase();
extern "C" void PpoolFromLoClone();
extern "C" void Proxy_PsndDefault();
extern "C" void PsfxEnsureExpls();
extern "C" void PwreGetWrBend__FP2WR4ENSK();
extern "C" void PwreGetWrCircle__FP2WR4ENSK();
extern "C" void RefAddBrkTouchObject();
extern "C" void RefAddDancerMove();
extern "C" void RefAddGuardPost();
extern "C" void RefAddHubEntry();
extern "C" void RefAddJsgEvent1F();
extern "C" void RefAddJsgEvent20();
extern "C" void RefAddJsgEvent21();
extern "C" void RefAddJsgEvent24_Flag();
extern "C" void RefAddJsgEvent24_NoFlag();
extern "C" void RefAddJsgEvent25();
extern "C" void RefAddJsgEvent26();
extern "C" void RefAddJsgEvent27();
extern "C" void RefAddJsgEvent28();
extern "C" void RefAddJsgEvent2B();
extern "C" void RefAddRhythmCrowd();
extern "C" void RefAddVehicleAxle();
extern "C" void RefAddVehicleGun();
extern "C" void RefAddVehicleWheel();
extern "C" void RefAddWaypointNode();
extern "C" void RefAddWrBendNoise();
extern "C" void RefAddWrBendWarp();
extern "C" void RefAddWrCircleWarp();
extern "C" void RefCAmmoVehicle();
extern "C" void RefCall1800D8();
extern "C" void RefCall180478();
extern "C" void RefCallAddBarrierClass();
extern "C" void RefCallAddBarrierObject();
extern "C" void RefCallAddBeam();
extern "C" void RefCallAddGeom();
extern "C" void RefCallAddGuardAimOid();
extern "C" void RefCallAddGuardAimOidResolve();
extern "C" void RefCallAddJobAnim();
extern "C" void RefCallAddJobCompleteEvent();
extern "C" void RefCallAddJobFailEvent();
extern "C" void RefCallAddJobToggle();
extern "C" void RefCallAddJsgContext();
extern "C" void RefCallAddJsgKind43();
extern "C" void RefCallAddJsgKind44();
extern "C" void RefCallAddJsgKind46();
extern "C" void RefCallAddLootDef();
extern "C" void RefCallAddLootDefGlob();
extern "C" void RefCallAddObject();
extern "C" void RefCallAddPhys();
extern "C" void RefCallAddScriptAseg();
extern "C" void RefCallAddScriptGoto();
extern "C" void RefCallAddScriptJump();
extern "C" void RefCallAddScriptLabel();
extern "C" void RefCallAddSeqRecord57();
extern "C" void RefCallAddSeqRecord58();
extern "C" void RefCallAddSeqRecord59();
extern "C" void RefCallAddSeqRecord5a();
extern "C" void RefCallAddSeqSignal();
extern "C" void RefCallAddStgActionDisablePart();
extern "C" void RefCallAddStgActionEnablePart();
extern "C" void RefCallAddStgActionHide();
extern "C" void RefCallAddStgActionHideGlob();
extern "C" void RefCallAddStgActionPostJob();
extern "C" void RefCallAddStgActionRumble();
extern "C" void RefCallAddStgActionShake();
extern "C" void RefCallAddStgActionShowGlob();
extern "C" void RefCallAddStgActionSound();
extern "C" void RefCallAddStgSwitchClass();
extern "C" void RefCallAddStgSwitchStage();
extern "C" void RefCallAddTaskAnim();
extern "C" void RefCallAddTaskRequest();
extern "C" void RefCallAddTaskToggle();
extern "C" void RefCallAddWrSwivelNoise();
extern "C" void RefCallApplyMusic();
extern "C" void RefCallApplyWithFilter();
extern "C" void RefCallAttachLo();
extern "C" void RefCallAttachPtAddRsmg();
extern "C" void RefCallAttachPtAddTaskStateRequest();
extern "C" void RefCallBinocAnchor();
extern "C" void RefCallBinocCut();
extern "C" void RefCallBinocFocus();
extern "C" void RefCallBinocPos();
extern "C" void RefCallBinocZoom();
extern "C" void RefCallCallAnimation();
extern "C" void RefCallCallSequence();
extern "C" void RefCallCallSplice();
extern "C" void RefCallCatch();
extern "C" void RefCallCheckSphere();
extern "C" void RefCallClearAloSelectedOid();
extern "C" void RefCallClearGuardAimObjects();
extern "C" void RefCallClearJsg();
extern "C" void RefCallClearLootDef();
extern "C" void RefCallClearSeqSignal();
extern "C" void RefCallClearSignals();
extern "C" void RefCallClimb();
extern "C" void RefCallCompleteJob();
extern "C" void RefCallConfrontCamera();
extern "C" void RefCallContinueAmb();
extern "C" void RefCallCrawl();
extern "C" void RefCallCrfodbSetLootId();
extern "C" void RefCallCut();
extern "C" void RefCallCutCamera();
extern "C" void RefCallDamage();
extern "C" void RefCallDanceInterlude();
extern "C" void RefCallDanceMove();
extern "C" void RefCallDecrementCounter();
extern "C" void RefCallDecrementCounterB();
extern "C" void RefCallDeferLoRemove();
extern "C" void RefCallDequeueStream();
extern "C" void RefCallDestroyThread();
extern "C" void RefCallDetonateGadgetObj();
extern "C" void RefCallDisableAloPart();
extern "C" void RefCallDropBomb();
extern "C" void RefCallDtStream();
extern "C" void RefCallEnableAloPart();
extern "C" void RefCallEndConfrontCamera();
extern "C" void RefCallEndGesture();
extern "C" void RefCallEndThread();
extern "C" void RefCallEnsureLeasedObject();
extern "C" void RefCallEnsureOptionBasicNull();
extern "C" void RefCallEnsureOptionBool();
extern "C" void RefCallEnsureOptionClq();
extern "C" void RefCallEnsureOptionFloat();
extern "C" void RefCallEnsureOptionInt();
extern "C" void RefCallEnsureOptionInt_132d88();
extern "C" void RefCallEnsureOptionLm();
extern "C" void RefCallEnsureOptionVector();
extern "C" void RefCallExplode();
extern "C" void RefCallExplodeOvr();
extern "C" void RefCallFCanLease();
extern "C" void RefCallFIsBasicDerivedFrom();
extern "C" void RefCallFLoHasOid();
extern "C" void RefCallFSeqSignal();
extern "C" void RefCallFStateAccepted();
extern "C" void RefCallFStreamPlaying();
extern "C" void RefCallFVjoyButtonHeld();
extern "C" void RefCallFVjoyButtonPressed();
extern "C" void RefCallFadeAloIn();
extern "C" void RefCallFadeAloOut();
extern "C" void RefCallFailJob();
extern "C" void RefCallForceTaskActive();
extern "C" void RefCallForceTaskLocked();
extern "C" void RefCallForceTaskState();
extern "C" void RefCallGesture();
extern "C" void RefCallGrficFromAlo();
extern "C" void RefCallHandsOff();
extern "C" void RefCallHideAloGlob();
extern "C" void RefCallHideBinoc();
extern "C" void RefCallHideBrief();
extern "C" void RefCallHideSwf();
extern "C" void RefCallHitFxRemove();
extern "C" void RefCallIncrementCounter();
extern "C" void RefCallIncrementCounterB();
extern "C" void RefCallInitStgSwitchPreStage();
extern "C" void RefCallJobBlotAddOptionalJob();
extern "C" void RefCallJobBlotAddRequiredJob();
extern "C" void RefCallJolt();
extern "C" void RefCallJoltCm();
extern "C" void RefCallJump();
extern "C" void RefCallLabel();
extern "C" void RefCallLift();
extern "C" void RefCallLockLeaseOfPlo();
extern "C" void RefCallPasegaApplyAseg();
extern "C" void RefCallPasegaEnsureAseg();
extern "C" void RefCallPasegaFindAlo();
extern "C" void RefCallPause();
extern "C" void RefCallPauseAmb();
extern "C" void RefCallPauseForever();
extern "C" void RefCallPhandleNewAloEmitter();
extern "C" void RefCallPhandleNewAloPart();
extern "C" void RefCallPhitfxSpawn();
extern "C" void RefCallPlayGuardScript();
extern "C" void RefCallPloLeaseCloneObject();
extern "C" void RefCallPosClosestOnCrv();
extern "C" void RefCallPrime();
extern "C" void RefCallPsaaFindAlo();
extern "C" void RefCallPsmaFindAlo();
extern "C" void RefCallQueueStream();
extern "C" void RefCallReach();
extern "C" void RefCallRemoveGeom();
extern "C" void RefCallRemoveObject();
extern "C" void RefCallRemovePhys();
extern "C" void RefCallRequestTaskState();
extern "C" void RefCallResetJob();
extern "C" void RefCallResetMurrayGoalStack();
extern "C" void RefCallRestartJob();
extern "C" void RefCallRetractAsega();
extern "C" void RefCallRetractGuardScript();
extern "C" void RefCallRetractMusic();
extern "C" void RefCallRevokeConfrontCamera();
extern "C" void RefCallRewindBlotLabel();
extern "C" void RefCallRtAloHide();
extern "C" void RefCallRtAloShow();
extern "C" void RefCallRumble();
extern "C" void RefCallSeek();
extern "C" void RefCallSeekAsega();
extern "C" void RefCallSeekBlotLabel();
extern "C" void RefCallSeekBlotLabelTime();
extern "C" void RefCallSendLoSpliceEvent5();
extern "C" void RefCallSendLoSpliceEvent6();
extern "C" void RefCallSendTaskTimeLimit();
extern "C" void RefCallSetActor();
extern "C" void RefCallSetAloInteract();
extern "C" void RefCallSetAloPartGrftak();
extern "C" void RefCallSetAloScrollingMasterSpeeds();
extern "C" void RefCallSetAloScrollingOffsets();
extern "C" void RefCallSetAmbRange();
extern "C" void RefCallSetAsegaPriority();
extern "C" void RefCallSetBlotLabelListFromRef();
extern "C" void RefCallSetClockSpeed();
extern "C" void RefCallSetContext();
extern "C" void RefCallSetDanceState();
extern "C" void RefCallSetEyes();
extern "C" void RefCallSetFocus();
extern "C" void RefCallSetGuardScriptCommand();
extern "C" void RefCallSetJobCompleteAseg();
extern "C" void RefCallSetJtAttach5();
extern "C" void RefCallSetJtAttach9();
extern "C" void RefCallSetJtAttachC_1424e0();
extern "C" void RefCallSetJtScriptGoal();
extern "C" void RefCallSetMurrayStateF();
extern "C" void RefCallSetPlayer();
extern "C" void RefCallSetResetFlag();
extern "C" void RefCallSetScrollerMasterSpeeds();
extern "C" void RefCallSetSlotSoSlot();
extern "C" void RefCallSetSmGoal();
extern "C" void RefCallSetSndbankMasterVolume();
extern "C" void RefCallSetSndbankVolumeFactor();
extern "C" void RefCallSetStgSwitchHitter();
extern "C" void RefCallSetStgSwitchStageHits();
extern "C" void RefCallSetTunnel();
extern "C" void RefCallShowAloGlob();
extern "C" void RefCallShowBinoc();
extern "C" void RefCallShowBrief();
extern "C" void RefCallShowSwf();
extern "C" void RefCallSignalSequence();
extern "C" void RefCallSlot290();
extern "C" void RefCallSlot298();
extern "C" void RefCallSlot2D0();
extern "C" void RefCallSnapAsega();
extern "C" void RefCallSoundEffect();
extern "C" void RefCallStartBlotLabel();
extern "C" void RefCallStartFade();
extern "C" void RefCallStartJsg();
extern "C" void RefCallStartJsgFocus();
extern "C" void RefCallStartJtCarry();
extern "C" void RefCallStartMurrayFlop();
extern "C" void RefCallStartMurrayLift();
extern "C" void RefCallStartMurrayThrow();
extern "C" void RefCallStartStream();
extern "C" void RefCallStartWipe();
extern "C" void RefCallStepStgSwitch();
extern "C" void RefCallStickGadgetObj();
extern "C" void RefCallStopAmb();
extern "C" void RefCallStopJsg();
extern "C" void RefCallStopSoundEffect();
extern "C" void RefCallStopStream();
extern "C" void RefCallSync();
extern "C" void RefCallTFindAsegLabel();
extern "C" void RefCallTakeOutBomb();
extern "C" void RefCallTimeToGoal();
extern "C" void RefCallToss();
extern "C" void RefCallUnhide();
extern "C" void RefCallUnlockLeaseOfPlo();
extern "C" void RefCallUnpause();
extern "C" void RefCallUntriggerSequence();
extern "C" void RefCallUseGuardAnimation();
extern "C" void RefCallUseGuardAnimationImmediate();
extern "C" void RefCallVirtual198();
extern "C" void RefCallVoice();
extern "C" void RefCallWait();
extern "C" void RefCallWaitForButton();
extern "C" void RefCallWaitForMusic();
extern "C" void RefCallWaitForVoice();
extern "C" void RefCallXfRefSetGoalEulerWorld();
extern "C" void RefCallXfRefSetGoalPointWorld();
extern "C" void RefCallXfRefSetGoalRange();
extern "C" void RefCallXfRefSetKind16Params();
extern "C" void RefChaser_SetStateAngleRanges();
extern "C" void RefChaser_SetStateAnim();
extern "C" void RefChaser_SetStateDistanceRanges();
extern "C" void RefClearHandsOff();
extern "C" void RefClearHudLabel();
extern "C" void RefDeliverJtLoot();
extern "C" void RefDropJtLoot();
extern "C" void RefEquipJtGadget();
extern "C" void RefForceTaskClosed();
extern "C" void RefForceTaskComplete();
extern "C" void RefGiveJtLoot();
extern "C" void RefGrab_FAddRsmg();
extern "C" void RefGrab_ReleasePlayer();
extern "C" void RefGrab_SetStateAnim();
extern "C" void RefGrab_Trigger();
extern "C" void RefIslotJtGadget();
extern "C" void RefJumpGuardScript();
extern "C" void RefPchzFriendlyFromWid();
extern "C" void RefPchzFriendlyFromWidOwner();
extern "C" void RefPgunFindVehicleGun();
extern "C" void RefPosAimAtPlayer();
extern "C" void RefPsmaApplySm();
extern "C" void RefReleaseJtLookHold();
extern "C" void RefResetRhythmScore();
extern "C" void RefSendGuardNoticeMessage();
extern "C" void RefSetHandsOff();
extern "C" void RefSetHubAllowedStates();
extern "C" void RefSetJtLookLimits();
extern "C" void RefSetJtLookTargetHeld();
extern "C" void RefSetJtPipeHandFoot();
extern "C" void RefSetJtRideOffset();
extern "C" void RefSetVehicleAmmo();
extern "C" void RefSetVehicleAmmoType();
extern "C" void RefShowHudLabel();
extern "C" void RefSpendVehicleGunAmmo();
extern "C" void RefStartKeypad();
extern "C" void RefSwarm_AddGroup();
extern "C" void RefSwitchCurrentTask();
extern "C" void RefUseStepguardDeathAnimation();
extern "C" void RefWarpStart();
extern "C" void RemoveSensorLo();
extern "C" void SelectCoinLootDef();
extern "C" void SelectLootDef();
extern "C" void SetAloAlpha();
extern "C" void SetAloFadeRate();
extern "C" void SetAloSelectedOid();
extern "C" void SetAmbPan();
extern "C" void SetAmbPitch();
extern "C" void SetAmbPos();
extern "C" void SetAmbVolume();
extern "C" void SetAsegaHandsOff();
extern "C" void SetAsegaMasterSpeed();
extern "C" void SetAsegaSpeed();
extern "C" void SetAsegsvtMaster();
extern "C" void SetButtonButtons();
extern "C" void SetCmFarClip();
extern "C" void SetCmFarFog();
extern "C" void SetCmFov();
extern "C" void SetCmMrdRatio();
extern "C" void SetCmNearFog();
extern "C" void SetCmRgbaFog__FP2CMP4RGBA();
extern "C" void SetCmUFogMax();
extern "C" void SetCrvRopeLength();
extern "C" void SetCrvRopeMode();
extern "C" void SetEmitterBlipmk();
extern "C" void SetEmitterEmitok();
extern "C" void SetEmitterEnabled__FP7EMITTERi();
extern "C" void SetEmitterRipt();
extern "C" void SetEmitterUnpositioned();
extern "C" void SetEyesClosed__FP4EYESf();
extern "C" void SetJtHealth();
extern "C" void SetJtPower();
extern "C" void SetLightDynamic();
extern "C" void SetLightFExcludeDynamicObjects();
extern "C" void SetLightFallOff();
extern "C" void SetLightHighlightColor();
extern "C" void SetLightKind();
extern "C" void SetRhythmState();
extern "C" void SetSlotSoSmp();
extern "C" void SetSlotSoState();
extern "C" void SetSmaGoal__FP3SMA3OID();
extern "C" void SetSmaMask();
extern "C" void SetSmaSvt();
extern "C" void SetSoCnstrForce();
extern "C" void SetSoCnstrTorque();
extern "C" void SetSoDvGravity();
extern "C" void SetSoNoXpsAll();
extern "C" void SetStepGravityRatio__FP4STEPf();
extern "C" void SetStepRadTarget_thunk();
extern "C" void SetStepSpinRatio__FP4STEPf();
extern "C" void SetSuvSuvgk();
extern "C" void SetSuvSuvs();
extern "C" void SetSwFocusOverride();
extern "C" void SetSwFogHsv();
extern "C" void SetTnTnsOverride();
extern "C" void SetVehicleState();
extern "C" void SetVolbtnButtons();
extern "C" void SetWrWavelength__FP2WRf();
extern "C" void TStream();
extern "C" void Warp_SetState();
extern "C" void bevy_camera_cm_14f478();
extern "C" void bevy_camera_cm_14f630();
extern "C" void bevy_classes_c2cf880_105d58();
extern "C" void bevy_game_fields_104bf8();
extern "C" void bevy_game_methods_cls_10b028();
extern "C" void bevy_player_p15_binoc_active();
extern "C" void bevy_player_p4_144068();
extern "C" void func_00100A00();
extern "C" void func_00100A90();
extern "C" void func_00100B88();
extern "C" void func_00100C80();
extern "C" void func_00101608();
extern "C" void func_00101768();
extern "C" void func_00101848();
extern "C" void func_001019D0();
extern "C" void func_00102538();
extern "C" void func_001027E0();
extern "C" void func_00102858();
extern "C" void func_00102C38();
extern "C" void func_00102D30();
extern "C" void func_00102E28();
extern "C" void func_00102F38();
extern "C" void func_00103048();
extern "C" void func_00103100();
extern "C" void func_001031B8();
extern "C" void func_00103270();
extern "C" void func_00103328();
extern "C" void func_001033E0();
extern "C" void func_00103498();
extern "C" void func_00103520();
extern "C" void func_001035A8();
extern "C" void func_00103630();
extern "C" void func_001036A8();
extern "C" void func_00103730();
extern "C" void func_001037A8();
extern "C" void func_00103830();
extern "C" void func_001038B8();
extern "C" void func_00103930();
extern "C" void func_001039B8();
extern "C" void func_00103A40();
extern "C" void func_00103AB8();
extern "C" void func_00103B38();
extern "C" void func_00103C18();
extern "C" void func_00103CA0();
extern "C" void func_00103D28();
extern "C" void func_00103DB0();
extern "C" void func_00103E38();
extern "C" void func_00103EC0();
extern "C" void func_00103F40();
extern "C" void func_00103FE8();
extern "C" void func_00104060();
extern "C" void func_00104188();
extern "C" void func_00104228();
extern "C" void func_00104350();
extern "C" void func_00104408();
extern "C" void func_001044B0();
extern "C" void func_00104558();
extern "C" void func_00104638();
extern "C" void func_00104718();
extern "C" void func_001049B0();
extern "C" void func_00104A68();
extern "C" void func_00104B70();
extern "C" void func_00104CF8();
extern "C" void func_00104D70();
extern "C" void func_00104DF8();
extern "C" void func_00104E80();
extern "C" void func_00104F40();
extern "C" void func_00104FE8();
extern "C" void func_00105090();
extern "C" void func_00105158();
extern "C" void func_00105200();
extern "C" void func_00105278();
extern "C" void func_001052F0();
extern "C" void func_00105398();
extern "C" void func_00105440();
extern "C" void func_00105508();
extern "C" void func_001055B0();
extern "C" void func_00105628();
extern "C" void func_001058F0();
extern "C" void func_00105978();
extern "C" void func_00105AF0();
extern "C" void func_00105B68();
extern "C" void func_00105CD0();
extern "C" void func_00105DE0();
extern "C" void func_00105E70();
extern "C" void func_00105F00();
extern "C" void func_00105F88();
extern "C" void func_00106010();
extern "C" void func_00106098();
extern "C" void func_001063A0();
extern "C" void func_00106448();
extern "C" void func_001064C0();
extern "C" void func_00106538();
extern "C" void func_001065E0();
extern "C" void func_00107728();
extern "C" void func_0010A790();
extern "C" void func_0010A8D0();
extern "C" void func_0010AA90();
extern "C" void func_0010AB88();
extern "C" void func_0010ABF8();
extern "C" void func_0010AC80();
extern "C" void func_0010ADB8();
extern "C" void func_0010B230();
extern "C" void func_0010B510();
extern "C" void func_0010B598();
extern "C" void func_0010B618();
extern "C" void func_0010B760();
extern "C" void func_0010B850();
extern "C" void func_0010B8F8();
extern "C" void func_0010B970();
extern "C" void func_0010B9E8();
extern "C" void func_0010BA70();
extern "C" void func_0010BB38();
extern "C" void func_0010BC88();
extern "C" void func_0010BD10();
extern "C" void func_0010BDC8();
extern "C" void func_0010BE70();
extern "C" void func_0010BEE8();
extern "C" void func_0010BF70();
extern "C" void func_0010BFF8();
extern "C" void func_0010C0A8();
extern "C" void func_0010C120();
extern "C" void func_0010C2E8();
extern "C" void func_0010CC70();
extern "C" void func_0010CD80();
extern "C" void func_0010CF18();
extern "C" void func_0010D028();
extern "C" void func_0010DAF0();
extern "C" void func_0010DB78();
extern "C" void func_00132ED0();
extern "C" void func_0013C4D8();
extern "C" void func_001443E8();
extern "C" void func_001443F8();
extern "C" void func_00144408();
extern "C" void func_00149220();
extern "C" void func_00149248();
extern "C" void func_001497B8();
extern "C" void func_001497E0();
extern "C" void func_0014F4E0();
extern "C" void func_0014F5F8();
extern "C" void func_00159A08();
extern "C" void func_0015A2B0();
extern "C" void func_001628B0();
extern "C" void func_00164098();
extern "C" void func_001732E0();
extern "C" void func_00173318();
extern "C" void func_00173358();
extern "C" void func_00173398();
extern "C" void func_001813C0();
extern "C" void func_001813F0();
extern "C" void func_00184028();
extern "C" void func_00184040();
extern "C" void func_001A3610();
extern "C" void func_001A3630();
extern "C" void func_001A6260();
extern "C" void func_001A63B0();
extern "C" void func_001A6C90();
extern "C" void func_001A6CA8();
extern "C" void func_001A6E38();
extern "C" void func_001A6E70();
extern "C" void func_001BBA60();
extern "C" void func_001BBA90();
extern "C" void func_001BBB50();
extern "C" void func_001BEAA8();
extern "C" void func_001BEAD0();
extern "C" void func_001C20E8();
extern "C" void func_001C2148();
extern "C" void func_001C3C08();
extern "C" void func_001C4098();
extern "C" void func_001C4130();
extern "C" void func_001C7A40();
extern "C" void func_001C7B10();
extern "C" void func_001CB360();
extern "C" void func_001DE3B0();
extern "C" void func_001DE3D8();
extern "C" void func_001E0128();
extern "C" void func_001E0158();
extern "C" void func_001E01C8();
extern "C" void func_001E7930();
extern "C" void func_001E7968();
extern "C" void func_001E79A0();
extern "C" void func_001E7FF0();
extern "C" void func_001F0808();
extern "C" void func_001F1EB8();
extern "C" void func_001F2688();
extern "C" void func_001F2718();
extern "C" void func_001F2740();
extern "C" void func_001F2758();
extern "C" void func_001F2768();
extern "C" void func_001F4848();
extern "C" void func_001F4870();
extern "C" void func_001F4898();
extern "C" void func_001F4930();
extern "C" void func_001F6918();
extern "C" void func_001F6960();
extern "C" void func_001F7A68();
extern "C" void func_001F7B40();
extern "C" void func_001F7B58();
extern "C" void func_001F7B68();
extern "C" void func_001F7B78();
extern "C" void func_001F7B88();
extern "C" void func_001F7B98();
extern "C" void func_001F7BF0();
extern "C" void func_001F7EC8();
extern "C" void func_001F7EF0();
extern "C" void func_001F7F08();
extern "C" void func_001F7F20();
extern "C" void func_001F7F48();
extern "C" void func_001F83B0();
extern "C" void func_001F83E0();
extern "C" void func_001F8410();
extern "C" void func_001F8440();
extern "C" void func_001F8470();
extern "C" void func_001F84A0();
extern "C" void func_001F84D0();
extern "C" void func_001F8500();
extern "C" void func_001F8668();
extern "C" void func_001F87A0();
extern "C" void func_001F87C8();
extern "C" void func_001F8808();
extern "C" void func_001F8830();
extern "C" void func_001F8870();
extern "C" void func_001F8898();
extern "C" void func_001F88D8();
extern "C" void func_00203FA0();
extern "C" void func_00206378();
extern "C" void func_00206458();
extern "C" void func_00206488();
extern "C" void func_002064A0();
extern "C" void func_002064C0();
extern "C" void func_00208538();
extern "C" void func_00209A88();
extern "C" void func_0020A518();
extern "C" void func_0020A540();
extern "C" void func_0020A9C0();
extern "C" void func_0020AF08();
extern "C" void func_0020F2D8();
extern "C" void func_0020F2F8();
extern "C" void func_00210978();
extern "C" void func_00221818();
extern "C" void func_00221948();
extern "C" void func_00221958();
extern "C" void func_00221960();
extern "C" void func_00221980();
extern "C" void func_00226370();
extern "C" void func_00228518();
extern "C" void func_00256298();
extern "C" void func_002562A0();
extern "C" void func_002562B8();
extern "C" void func_002562E0();
extern "C" void func_002562F0();
extern "C" void func_00256318();
extern "C" void func_00256328();
extern "C" void func_00256350();
extern "C" void func_00258280();
extern "C" void func_002589A8();
extern "C" void func_002589F0();
extern "C" void func_00258AB8();
extern "C" void func_00258AC8();
extern "C" void func_00258B00();
extern "C" void func_00258B38();
extern "C" void func_00258C60();
extern "C" void func_00258CC8();
extern "C" void func_00258D30();
extern "C" void func_00258E60();
extern "C" void func_00258EC8();
extern "C" void func_002590F0();
extern "C" void func_00259330();
extern "C" void func_002593B8();
extern "C" void func_00259488();
extern "C" void func_00259550();
extern "C" void func_00259560();
extern "C" void func_00259598();
extern "C" void func_002595D0();
extern "C" void func_00259608();
extern "C" void func_002596D8();
extern "C" void func_002596F8();
extern "C" void func_00259760();
extern "C" void func_002597C8();
extern "C" void func_00259830();
extern "C" void func_002598D8();
extern "C" void func_002598F8();
extern "C" void func_00259960();
extern "C" void func_002599F8();
extern "C" void func_00259A08();
extern "C" void func_00259A18();
extern "C" void func_00259A28();
extern "C" void func_00259A38();
extern "C" void func_00259A48();
extern "C" void func_00259A78();
extern "C" void func_00259B00();
extern "C" void func_00259B10();
extern "C" void func_00259C10();
extern "C" void func_00259D38();
extern "C" void func_00259D48();
extern "C" void func_00259D70();
extern char forward_D_002B0000[] asm("D_002B0000");

// data-ok: retail's bytes at 0X2AC880
void *D_002AC880[10] = {(void *)7, (void *)4, (void *)0xffff0000, (void *)CidGetBasic, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AC8A8
void *D_002AC8A8[10] = {(void *)0x2000, (void *)4, (void *)0xffff0000, (void *)func_00132ED0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AC8D0
void *D_002AC8D0[10] = {0, (void *)1, 0, 0, (void *)RefCallFIsBasicDerivedFrom, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AC8F8
void *D_002AC8F8[10] = {(void *)18, (void *)0x401, (void *)RefCallEnsureOptionBool, 0, (void *)RefCallEnsureOptionBool, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AC920
void *D_002AC920[10] = {(void *)18, (void *)0x401, (void *)RefCallEnsureOptionInt, 0, (void *)RefCallEnsureOptionInt, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AC948
void *D_002AC948[10] = {(void *)18, (void *)0x401, (void *)RefCallEnsureOptionFloat, 0, (void *)RefCallEnsureOptionFloat, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AC970
void *D_002AC970[10] = {(void *)18, (void *)0x401, (void *)RefCallEnsureOptionClq, 0, (void *)RefCallEnsureOptionClq, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AC998
void *D_002AC998[10] = {(void *)18, (void *)0x401, (void *)RefCallEnsureOptionLm, 0, (void *)RefCallEnsureOptionLm, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AC9C0
void *D_002AC9C0[10] = {(void *)18, (void *)0x401, (void *)RefCallEnsureOptionInt_132d88, 0, (void *)RefCallEnsureOptionInt_132d88, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AC9E8
void *D_002AC9E8[10] = {(void *)18, (void *)0x401, (void *)RefCallEnsureOptionVector, 0, (void *)RefCallEnsureOptionVector, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACA10
void *D_002ACA10[10] = {(void *)18, (void *)0x401, (void *)RefCallEnsureOptionBasicNull, 0, (void *)RefCallEnsureOptionBasicNull, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACA38
void *D_002ACA38[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSendLoSpliceEvent5, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACA60
void *D_002ACA60[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSendLoSpliceEvent6, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACA88
void *D_002ACA88[10] = {(void *)1, (void *)0x122, (void *)56, 0, (void *)forward_D_002B0000, (void *)12, (void *)forward_D_002B0000, (void *)12, 0, 0};

// data-ok: retail's bytes at 0X2ACAB0
void *D_002ACAB0[10] = {(void *)0x1008, (void *)0x124, (void *)0xffff0000, (void *)func_001A6C90, (void *)0xffff0000, (void *)func_001A6CA8, (void *)0xffff0000, (void *)func_001A6CA8, 0, 0};

// data-ok: retail's bytes at 0X2ACAD8
unsigned int D_002ACAD8[10] = {6, 2, 24, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACB00
void *D_002ACB00[10] = {(void *)6, (void *)4, (void *)0xffff0000, (void *)func_001A6260, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACB28
void *D_002ACB28[10] = {0, (void *)1, 0, 0, (void *)RefCallFLoHasOid, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACB50
void *D_002ACB50[10] = {(void *)0x2006, (void *)4, (void *)0xffff0000, (void *)PpoolFromLoClone, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACB78
struct {
    char m0[4];
    unsigned int m1[9];
} D_002ACB78 = {
    "0 ",
    {2, 16, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2ACBA0
void *D_002ACBA0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallAttachLo, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACBC8
void *D_002ACBC8[10] = {(void *)2, (void *)36, (void *)0xffff0000, (void *)PosLoWorld, (void *)0x1e0000, (void *)12, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACBF0
void *D_002ACBF0[10] = {(void *)4, (void *)36, (void *)0xffff0000, (void *)PmatLoWorld, (void *)0x1f0000, (void *)12, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACC18
void *D_002ACC18[10] = {(void *)2, (void *)36, (void *)0xffff0000, (void *)GetLoEulerDegrees, (void *)0xffff0000, (void *)func_001A63B0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACC40
void *D_002ACC40[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00100A00, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACC68
void *D_002ACC68[10] = {(void *)18, (void *)0x4401, (void *)func_00100A90, 0, (void *)func_00100A90, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACC90
void *D_002ACC90[10] = {(void *)18, (void *)0x4401, (void *)RefCallDeferLoRemove, 0, (void *)func_00100B88, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACCB8
unsigned int D_002ACCB8[10] = {0, 4, 0xffff0000, 0x259ae8, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACCE0
unsigned int D_002ACCE0[10] = {6, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACD08
unsigned int D_002ACD08[10] = {2, 0x124, 0x220000, 12, 0x240000, 12, 0x240000, 12, 0, 0};

// data-ok: retail's bytes at 0X2ACD30
unsigned int D_002ACD30[10] = {2, 0x124, 0x230000, 12, 0x250000, 12, 0x250000, 12, 0, 0};

// data-ok: retail's bytes at 0X2ACD58
unsigned int D_002ACD58[10] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACD80
void *D_002ACD80[10] = {0, (void *)0x104, (void *)0xffff0000, (void *)func_001A6E70, 0, 0, (void *)0xffff0000, (void *)func_001A6E38, 0, 0};

// data-ok: retail's bytes at 0X2ACDA8
void *D_002ACDA8[10] = {(void *)0x1001, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)SetSoCnstrForce, (void *)0xffff0000, (void *)SetSoCnstrForce, 0, 0};

// data-ok: retail's bytes at 0X2ACDD0
void *D_002ACDD0[10] = {(void *)0x1001, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)SetSoCnstrTorque, (void *)0xffff0000, (void *)SetSoCnstrTorque, 0, 0};

// data-ok: retail's bytes at 0X2ACDF8
void *D_002ACDF8[10] = {(void *)2, (void *)0x124, (void *)0xffff0000, (void *)GetSoDvGravity, (void *)0xffff0000, (void *)SetSoDvGravity, (void *)0xffff0000, (void *)SetSoDvGravity, 0, 0};

// data-ok: retail's bytes at 0X2ACE20
void *D_002ACE20[10] = {(void *)1, (void *)162, (void *)0x13c, 0, (void *)0xffff0000, (void *)func_001F2688, (void *)0x13c, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACE48
void *D_002ACE48[10] = {0, (void *)0x124, (void *)0xffff0000, (void *)func_001F6960, (void *)0xffff0000, (void *)func_001F6918, (void *)0xffff0000, (void *)func_001F6918, 0, 0};

// data-ok: retail's bytes at 0X2ACE70
void *D_002ACE70[10] = {0, (void *)36, (void *)0xffff0000, (void *)GetSoNoXpsAll, (void *)0xffff0000, (void *)SetSoNoXpsAll, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACE98
void *D_002ACE98[10] = {0, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_001F7F48, (void *)0xffff0000, (void *)func_001F7F48, 0, 0};

// data-ok: retail's bytes at 0X2ACEC0
void *D_002ACEC0[10] = {0, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001F8668, 0, 0};

// data-ok: retail's bytes at 0X2ACEE8
void *D_002ACEE8[10] = {(void *)6, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)SetAloSelectedOid, (void *)0xffff0000, (void *)SetAloSelectedOid, 0, 0};

// data-ok: retail's bytes at 0X2ACF10
void *D_002ACF10[10] = {(void *)18, (void *)0x401, (void *)RefCallClearAloSelectedOid, 0, (void *)RefCallClearAloSelectedOid, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACF38
void *D_002ACF38[10] = {0, (void *)1, 0, 0, (void *)func_00100C80, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACF60
void *D_002ACF60[10] = {(void *)18, (void *)0x401, (void *)RefCallShowAloGlob, 0, (void *)RefCallShowAloGlob, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACF88
void *D_002ACF88[10] = {(void *)18, (void *)0x401, (void *)RefCallHideAloGlob, 0, (void *)RefCallHideAloGlob, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACFB0
void *D_002ACFB0[10] = {(void *)18, (void *)0x401, (void *)RefCallEnableAloPart, 0, (void *)RefCallEnableAloPart, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ACFD8
void *D_002ACFD8[10] = {(void *)18, (void *)0x401, (void *)RefCallDisableAloPart, 0, (void *)RefCallDisableAloPart, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD000
void *D_002AD000[10] = {(void *)18, (void *)0x401, (void *)RefCallSetAloPartGrftak, 0, (void *)RefCallSetAloPartGrftak, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD028
void *D_002AD028[10] = {(void *)0x1011, (void *)0x2092, (void *)232, 0, (void *)232, 0, (void *)232, 0, (void *)0xffff0000, (void *)func_001F7B98};

// data-ok: retail's bytes at 0X2AD050
void *D_002AD050[10] = {(void *)1, (void *)0x2092, (void *)236, 0, (void *)236, 0, (void *)236, 0, (void *)0xffff0000, (void *)func_001F7B98};

// data-ok: retail's bytes at 0X2AD078
void *D_002AD078[10] = {0, (void *)0x2092, (void *)240, 0, (void *)240, 0, (void *)240, 0, (void *)0xffff0000, (void *)func_001F7B98};

// data-ok: retail's bytes at 0X2AD0A0
void *D_002AD0A0[10] = {0, (void *)0x124, (void *)0xffff0000, (void *)func_001F8500, (void *)0xffff0000, (void *)func_001F84D0, (void *)0xffff0000, (void *)func_001F84D0, 0, 0};

// data-ok: retail's bytes at 0X2AD0C8
void *D_002AD0C8[10] = {(void *)18, (void *)0x401, (void *)RefCallSetAloInteract, 0, (void *)RefCallSetAloInteract, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD0F0
void *D_002AD0F0[10] = {(void *)5, (void *)1, 0, 0, (void *)RefCallGrficFromAlo, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD118
void *D_002AD118[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallFadeAloOut, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD140
void *D_002AD140[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallFadeAloIn, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD168
void *D_002AD168[10] = {(void *)1, (void *)0x122, (void *)0x12c, 0, (void *)0xffff0000, (void *)SetAloAlpha, (void *)0xffff0000, (void *)SetAloAlpha, 0, 0};

// data-ok: retail's bytes at 0X2AD190
void *D_002AD190[10] = {(void *)1, (void *)0x122, (void *)0x130, 0, (void *)0xffff0000, (void *)SetAloFadeRate, (void *)0xffff0000, (void *)SetAloFadeRate, 0, 0};

// data-ok: retail's bytes at 0X2AD1B8
void *D_002AD1B8[10] = {(void *)1, (void *)0x2092, (void *)212, 0, (void *)212, 0, (void *)212, 0, (void *)0xffff0000, (void *)func_001F7BF0};

// data-ok: retail's bytes at 0X2AD1E0
void *D_002AD1E0[10] = {(void *)1, (void *)0x2092, (void *)216, 0, (void *)216, 0, (void *)216, 0, (void *)0xffff0000, (void *)func_001F7BF0};

// data-ok: retail's bytes at 0X2AD208
void *D_002AD208[10] = {(void *)0x1032, (void *)0x124, (void *)0xffff0000, (void *)func_001F7EF0, (void *)0xffff0000, (void *)func_001F7EC8, (void *)0xffff0000, (void *)func_001F7EC8, 0, 0};

// data-ok: retail's bytes at 0X2AD230
void *D_002AD230[10] = {(void *)0x103d, (void *)0x104, (void *)0xffff0000, (void *)func_001F2740, 0, 0, (void *)0xffff0000, (void *)func_001F2718, 0, 0};

// data-ok: retail's bytes at 0X2AD258
void *D_002AD258[10] = {0, (void *)0x124, (void *)0xffff0000, (void *)func_001F7F08, (void *)0xffff0000, (void *)func_001F7F20, (void *)0xffff0000, (void *)func_001F7F20, 0, 0};

// data-ok: retail's bytes at 0X2AD280
void *D_002AD280[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetAloScrollingMasterSpeeds, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD2A8
void *D_002AD2A8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetAloScrollingOffsets, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD2D0
void *D_002AD2D0[10] = {(void *)0x208a, (void *)1, 0, 0, (void *)RefCallPsaaFindAlo, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD2F8
unsigned int D_002AD2F8[10] = {1, 146, 160, 0, 160, 0, 160, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD320
unsigned int D_002AD320[10] = {2, 146, 144, 0, 144, 0, 144, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD348
void *D_002AD348[10] = {0, (void *)0x124, (void *)0xffff0000, (void *)func_001F2758, (void *)0xffff0000, (void *)func_001F2768, (void *)0xffff0000, (void *)func_001F2768, 0, 0};

// data-ok: retail's bytes at 0X2AD370
void *D_002AD370[10] = {(void *)0x1040, (void *)0x124, (void *)0xffff0000, (void *)func_001F7B40, (void *)0xffff0000, (void *)func_001F7A68, (void *)0xffff0000, (void *)func_001F7A68, 0, 0};

// data-ok: retail's bytes at 0X2AD398
void *D_002AD398[10] = {(void *)5, (void *)0x124, (void *)0xffff0000, (void *)func_001F7B68, (void *)0xffff0000, (void *)func_001F7B58, (void *)0xffff0000, (void *)func_001F7B58, 0, 0};

// data-ok: retail's bytes at 0X2AD3C0
void *D_002AD3C0[10] = {(void *)5, (void *)0x124, (void *)0xffff0000, (void *)func_001F7B88, (void *)0xffff0000, (void *)func_001F7B78, (void *)0xffff0000, (void *)func_001F7B78, 0, 0};

// data-ok: retail's bytes at 0X2AD3E8
void *D_002AD3E8[10] = {(void *)0x2086, (void *)1, 0, 0, (void *)RefCallPasegaFindAlo, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD410
void *D_002AD410[10] = {(void *)0x2088, (void *)1, 0, 0, (void *)RefCallPsmaFindAlo, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD438
void *D_002AD438[10] = {(void *)2, (void *)0x124, (void *)0xffff0000, (void *)func_001F4848, (void *)0xffff0000, (void *)func_001F4898, (void *)0xffff0000, (void *)func_001F4898, 0, 0};

// data-ok: retail's bytes at 0X2AD460
void *D_002AD460[10] = {(void *)2, (void *)0x124, (void *)0xffff0000, (void *)func_001F4870, (void *)0xffff0000, (void *)func_001F4930, (void *)0xffff0000, (void *)func_001F4930, 0, 0};

// data-ok: retail's bytes at 0X2AD488
void *D_002AD488[10] = {(void *)0x2095, (void *)1, 0, 0, (void *)RefCallPhandleNewAloEmitter, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD4B0
void *D_002AD4B0[10] = {(void *)0x2096, (void *)1, 0, 0, (void *)RefCallPhandleNewAloPart, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD4D8
void *D_002AD4D8[10] = {(void *)18, (void *)0x401, (void *)func_00101608, 0, (void *)func_00101608, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD500
void *D_002AD500[10] = {(void *)1, (void *)0x124, (void *)0xffff0000, (void *)func_001F83E0, (void *)0xffff0000, (void *)func_001F83B0, (void *)0xffff0000, (void *)func_001F83B0, 0, 0};

// data-ok: retail's bytes at 0X2AD528
void *D_002AD528[10] = {(void *)1, (void *)0x124, (void *)0xffff0000, (void *)func_001F8440, (void *)0xffff0000, (void *)func_001F8410, (void *)0xffff0000, (void *)func_001F8410, 0, 0};

// data-ok: retail's bytes at 0X2AD550
void *D_002AD550[10] = {(void *)1, (void *)0x124, (void *)0xffff0000, (void *)func_001F84A0, (void *)0xffff0000, (void *)func_001F8470, (void *)0xffff0000, (void *)func_001F8470, 0, 0};

// data-ok: retail's bytes at 0X2AD578
unsigned int D_002AD578[10] = {0x2011, 4, 0xffff0000, 0x259b20, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD5A0
unsigned int D_002AD5A0[10] = {1, 4, 0xa0000, 12, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD5C8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AD5C8 = {
    "\012",
    {18, 80, 0, 80, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AD5F0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AD5F0 = {
    "\012",
    {18, 88, 0, 88, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AD618
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AD618 = {
    "\012",
    {18, 80, 0, 80, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AD640
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AD640 = {
    "\012",
    {18, 88, 0, 88, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AD668
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AD668 = {
    "\012",
    {18, 80, 0, 80, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AD690
unsigned int D_002AD690[10] = {1, 18, 80, 0, 80, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD6B8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AD6B8 = {
    "\012",
    {18, 84, 0, 84, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AD6E0
unsigned int D_002AD6E0[10] = {1, 18, 92, 0, 92, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD708
void *D_002AD708[10] = {(void *)1, (void *)34, (void *)120, 0, (void *)0xffff0000, (void *)SetEyesClosed__FP4EYESf, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD730
void *D_002AD730[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetScrollerMasterSpeeds, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD758
unsigned int D_002AD758[10] = {1, 18, 80, 0, 80, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD780
unsigned int D_002AD780[10] = {1, 18, 84, 0, 84, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD7A8
unsigned int D_002AD7A8[10] = {1, 18, 88, 0, 88, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD7D0
unsigned int D_002AD7D0[10] = {1, 18, 92, 0, 92, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD7F8
void *D_002AD7F8[10] = {(void *)18, (void *)0x400, (void *)func_00101768, 0, 0, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD820
void *D_002AD820[10] = {(void *)18, (void *)0x400, (void *)func_00101848, 0, 0, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD848
void *D_002AD848[10] = {(void *)14, (void *)0x2080, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)Proxy_PsndDefault};

// data-ok: retail's bytes at 0X2AD870
void *D_002AD870[10] = {(void *)1, (void *)0x2080, 0, 0, 0, 0, (void *)4, 0, (void *)0xffff0000, (void *)Proxy_PsndDefault};

// data-ok: retail's bytes at 0X2AD898
void *D_002AD898[10] = {(void *)1, (void *)0x2080, 0, 0, 0, 0, (void *)8, 0, (void *)0xffff0000, (void *)Proxy_PsndDefault};

// data-ok: retail's bytes at 0X2AD8C0
void *D_002AD8C0[10] = {(void *)1, (void *)0x2080, 0, 0, 0, 0, (void *)12, 0, (void *)0xffff0000, (void *)Proxy_PsndDefault};

// data-ok: retail's bytes at 0X2AD8E8
void *D_002AD8E8[10] = {(void *)1, (void *)0x2080, 0, 0, 0, 0, (void *)16, 0, (void *)0xffff0000, (void *)Proxy_PsndDefault};

// data-ok: retail's bytes at 0X2AD910
void *D_002AD910[10] = {(void *)0x2086, (void *)1, 0, 0, (void *)RefCallPasegaApplyAseg, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD938
void *D_002AD938[10] = {(void *)18, (void *)0x400, (void *)func_001019D0, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD960
void *D_002AD960[10] = {(void *)0x2086, (void *)1, 0, 0, (void *)RefCallPasegaEnsureAseg, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD988
void *D_002AD988[10] = {(void *)1, (void *)162, (void *)120, 0, (void *)0xffff0000, (void *)SetAsegsvtMaster, (void *)120, 0, 0, 0};

// data-ok: retail's bytes at 0X2AD9B0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AD9B0 = {
    "\011",
    {130, 128, 0, 0, 0, 128, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AD9D8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AD9D8 = {
    "\012",
    {130, 144, 0, 0, 0, 144, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2ADA00
unsigned int D_002ADA00[10] = {5, 146, 108, 0, 108, 0, 108, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADA28
unsigned int D_002ADA28[10] = {0, 146, 112, 0, 112, 0, 112, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADA50
unsigned int D_002ADA50[10] = {1, 2, 116, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADA78
void *D_002ADA78[10] = {(void *)1, (void *)1, 0, 0, (void *)RefCallTFindAsegLabel, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADAA0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002ADAA0 = {
    "m ",
    {2, 20, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2ADAC8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002ADAC8 = {
    "0 ",
    {2, 24, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2ADAF0
unsigned int D_002ADAF0[10] = {1, 2, 28, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADB18
void *D_002ADB18[10] = {(void *)1, (void *)34, (void *)68, 0, (void *)0xffff0000, (void *)SetAsegaSpeed, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADB40
void *D_002ADB40[10] = {(void *)1, (void *)34, (void *)72, 0, (void *)0xffff0000, (void *)SetAsegaMasterSpeed, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADB68
void *D_002ADB68[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetAsegaPriority, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADB90
void *D_002ADB90[10] = {0, (void *)34, (void *)88, 0, (void *)0xffff0000, (void *)SetAsegaHandsOff, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADBB8
void *D_002ADBB8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSeekAsega, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADBE0
void *D_002ADBE0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallRetractAsega, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADC08
void *D_002ADC08[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSnapAsega, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADC30
void *D_002ADC30[10] = {0, (void *)4, (void *)0xffff0000, (void *)FAsegaGone, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADC58
void *D_002ADC58[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallPauseAmb, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADC80
void *D_002ADC80[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallContinueAmb, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADCA8
void *D_002ADCA8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStopAmb, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADCD0
void *D_002ADCD0[10] = {(void *)1, (void *)34, (void *)16, 0, (void *)0xffff0000, (void *)SetAmbVolume, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADCF8
void *D_002ADCF8[10] = {(void *)5, (void *)34, (void *)20, 0, (void *)0xffff0000, (void *)SetAmbPan, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADD20
void *D_002ADD20[10] = {(void *)1, (void *)34, (void *)24, 0, (void *)0xffff0000, (void *)SetAmbPitch, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADD48
void *D_002ADD48[10] = {(void *)0x2002, (void *)34, (void *)28, 0, (void *)0xffff0000, (void *)SetEmitterUnpositioned, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADD70
void *D_002ADD70[10] = {(void *)2, (void *)34, (void *)32, 0, (void *)0xffff0000, (void *)SetAmbPos, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADD98
void *D_002ADD98[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetAmbRange, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADDC0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002ADDC0 = {
    "\012",
    {2, 48, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2ADDE8
void *D_002ADDE8[10] = {(void *)0x2097, (void *)1, 0, 0, (void *)RefCallStartStream, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADE10
void *D_002ADE10[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStopStream, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADE38
void *D_002ADE38[10] = {0, (void *)1, 0, 0, (void *)RefCallFStreamPlaying, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADE60
void *D_002ADE60[10] = {(void *)1, (void *)4, (void *)0xffff0000, (void *)TStream, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADE88
void *D_002ADE88[10] = {(void *)1, (void *)1, 0, 0, (void *)RefCallDtStream, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADEB0
void *D_002ADEB0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallIncrementCounter, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADED8
void *D_002ADED8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallDecrementCounter, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADF00
void *D_002ADF00[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallIncrementCounterB, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADF28
void *D_002ADF28[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallDecrementCounterB, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADF50
void *D_002ADF50[10] = {(void *)0x2097, (void *)1, 0, 0, (void *)RefCallQueueStream, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADF78
void *D_002ADF78[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallDequeueStream, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADFA0
void *D_002ADFA0[10] = {(void *)1, (void *)1, 0, 0, (void *)func_00102538, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADFC8
void *D_002ADFC8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetSndbankMasterVolume, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2ADFF0
void *D_002ADFF0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetSndbankVolumeFactor, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE018
void *D_002AE018[10] = {(void *)0x1007, (void *)0x122, (void *)224, 0, (void *)0xffff0000, (void *)SetLightKind, (void *)0xffff0000, (void *)SetLightKind, 0, 0};

// data-ok: retail's bytes at 0X2AE040
void *D_002AE040[10] = {(void *)2, (void *)162, (void *)240, 0, (void *)0xffff0000, (void *)SetLightHighlightColor, (void *)240, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE068
void *D_002AE068[10] = {(void *)1, (void *)162, (void *)0x150, 0, (void *)0xffff0000, (void *)func_001A3610, (void *)0x150, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE090
void *D_002AE090[10] = {(void *)1, (void *)162, (void *)0x154, 0, (void *)0xffff0000, (void *)func_001A3630, (void *)0x154, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE0B8
struct {
    char m0[4];
    void *m1[9];
} D_002AE0B8 = {
    "\012",
    {(void *)162, (void *)0x164, 0, (void *)0xffff0000, (void *)SetLightFallOff, (void *)0x164, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AE0E0
unsigned int D_002AE0E0[10] = {0, 146, 0x158, 0, 0x158, 0, 0x158, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE108
void *D_002AE108[10] = {0, (void *)162, (void *)0x15c, 0, (void *)0xffff0000, (void *)SetLightFExcludeDynamicObjects, (void *)0x15c, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE130
void *D_002AE130[10] = {0, (void *)162, (void *)0x160, 0, (void *)0xffff0000, (void *)SetLightDynamic, (void *)0x160, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE158
void *D_002AE158[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallJoltCm, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE180
void *D_002AE180[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)RefCallSetResetFlag, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE1A8
void *D_002AE1A8[10] = {(void *)1, (void *)0x122, (void *)32, 0, (void *)0xffff0000, (void *)SetCmFov, (void *)0xffff0000, (void *)SetCmFov, 0, 0};

// data-ok: retail's bytes at 0X2AE1D0
void *D_002AE1D0[10] = {(void *)1, (void *)0x122, (void *)36, 0, (void *)0xffff0000, (void *)func_0014F5F8, (void *)0xffff0000, (void *)func_0014F5F8, 0, 0};

// data-ok: retail's bytes at 0X2AE1F8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AE1F8 = {
    "\014",
    {146, 44, 0, 44, 0, 44, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AE220
void *D_002AE220[10] = {(void *)1, (void *)0x122, (void *)76, 0, (void *)0xffff0000, (void *)bevy_camera_cm_14f630, (void *)0xffff0000, (void *)bevy_camera_cm_14f630, 0, 0};

// data-ok: retail's bytes at 0X2AE248
void *D_002AE248[10] = {(void *)1, (void *)0x122, (void *)80, 0, (void *)0xffff0000, (void *)SetCmFarClip, (void *)0xffff0000, (void *)SetCmFarClip, 0, 0};

// data-ok: retail's bytes at 0X2AE270
void *D_002AE270[10] = {(void *)1, (void *)0x122, (void *)0x240, 0, (void *)0xffff0000, (void *)SetCmNearFog, (void *)0xffff0000, (void *)SetCmNearFog, 0, 0};

// data-ok: retail's bytes at 0X2AE298
void *D_002AE298[10] = {(void *)1, (void *)0x122, (void *)0x244, 0, (void *)0xffff0000, (void *)SetCmFarFog, (void *)0xffff0000, (void *)SetCmFarFog, 0, 0};

// data-ok: retail's bytes at 0X2AE2C0
struct {
    char m0[4];
    void *m1[9];
} D_002AE2C0 = {
    "\015",
    {(void *)162, (void *)0x24c, 0, (void *)0xffff0000, (void *)SetCmRgbaFog__FP2CMP4RGBA, (void *)0x24c, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AE2E8
void *D_002AE2E8[10] = {(void *)1, (void *)0x122, (void *)0x248, 0, (void *)0xffff0000, (void *)SetCmUFogMax, (void *)0xffff0000, (void *)SetCmUFogMax, 0, 0};

// data-ok: retail's bytes at 0X2AE310
void *D_002AE310[10] = {(void *)1, (void *)0x122, (void *)24, 0, (void *)0xffff0000, (void *)SetCmMrdRatio, (void *)0xffff0000, (void *)SetCmMrdRatio, 0, 0};

// data-ok: retail's bytes at 0X2AE338
void *D_002AE338[10] = {(void *)2, (void *)36, (void *)0xffff0000, (void *)func_00256298, (void *)0xffff0000, (void *)0x14f3c8, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE360
void *D_002AE360[10] = {(void *)4, (void *)36, (void *)0xffff0000, (void *)func_002562A0, (void *)0xffff0000, (void *)0x256278, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE388
void *D_002AE388[10] = {(void *)2, (void *)36, (void *)0xffff0000, (void *)bevy_camera_cm_14f478, (void *)0xffff0000, (void *)func_0014F4E0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE3B0
unsigned int D_002AE3B0[10] = {1, 146, 0x620, 0, 0x624, 0, 0x624, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE3D8
unsigned int D_002AE3D8[10] = {5, 146, 228, 0, 228, 0, 228, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE400
void *D_002AE400[10] = {(void *)7, (void *)0x124, (void *)0xffff0000, (void *)func_00221948, (void *)0xffff0000, (void *)func_00221818, (void *)0xffff0000, (void *)func_00221818, 0, 0};

// data-ok: retail's bytes at 0X2AE428
void *D_002AE428[10] = {(void *)18, (void *)0x400, (void *)func_001027E0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE450
void *D_002AE450[10] = {(void *)1, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00221958};

// data-ok: retail's bytes at 0X2AE478
struct {
    char m0[4];
    void *m1[9];
} D_002AE478 = {
    "\011",
    {(void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00221958}
};

// data-ok: retail's bytes at 0X2AE4A0
struct {
    char m0[4];
    void *m1[9];
} D_002AE4A0 = {
    "\012",
    {(void *)0x2092, (void *)64, 0, (void *)64, 0, (void *)64, 0, (void *)0xffff0000, (void *)func_00221958}
};

// data-ok: retail's bytes at 0X2AE4C8
struct {
    char m0[4];
    void *m1[9];
} D_002AE4C8 = {
    "\011",
    {(void *)0x2092, (void *)32, 0, (void *)32, 0, (void *)32, 0, (void *)0xffff0000, (void *)func_00221958}
};

// data-ok: retail's bytes at 0X2AE4F0
struct {
    char m0[4];
    void *m1[9];
} D_002AE4F0 = {
    "\012",
    {(void *)0x2092, (void *)72, 0, (void *)72, 0, (void *)72, 0, (void *)0xffff0000, (void *)func_00221958}
};

// data-ok: retail's bytes at 0X2AE518
struct {
    char m0[4];
    void *m1[9];
} D_002AE518 = {
    "\011",
    {(void *)0x2092, (void *)48, 0, (void *)48, 0, (void *)48, 0, (void *)0xffff0000, (void *)func_00221958}
};

// data-ok: retail's bytes at 0X2AE540
struct {
    char m0[4];
    void *m1[9];
} D_002AE540 = {
    "\012",
    {(void *)0x2092, (void *)80, 0, (void *)80, 0, (void *)80, 0, (void *)0xffff0000, (void *)func_00221958}
};

// data-ok: retail's bytes at 0X2AE568
void *D_002AE568[10] = {(void *)1, (void *)0x2092, (void *)88, 0, (void *)88, 0, (void *)88, 0, (void *)0xffff0000, (void *)func_00221958};

// data-ok: retail's bytes at 0X2AE590
void *D_002AE590[10] = {(void *)1, (void *)0x2092, (void *)92, 0, (void *)92, 0, (void *)92, 0, (void *)0xffff0000, (void *)func_00221958};

// data-ok: retail's bytes at 0X2AE5B8
void *D_002AE5B8[10] = {(void *)1, (void *)0x2092, (void *)96, 0, (void *)96, 0, (void *)96, 0, (void *)0xffff0000, (void *)func_00221958};

// data-ok: retail's bytes at 0X2AE5E0
void *D_002AE5E0[10] = {(void *)1, (void *)0x2092, (void *)100, 0, (void *)100, 0, (void *)100, 0, (void *)0xffff0000, (void *)func_00221958};

// data-ok: retail's bytes at 0X2AE608
void *D_002AE608[10] = {(void *)1, (void *)0x2092, (void *)104, 0, (void *)104, 0, (void *)104, 0, (void *)0xffff0000, (void *)func_00221958};

// data-ok: retail's bytes at 0X2AE630
void *D_002AE630[10] = {(void *)1, (void *)0x124, (void *)0xffff0000, (void *)func_00221980, (void *)0xffff0000, (void *)func_00221960, (void *)0xffff0000, (void *)func_00221960, 0, 0};

// data-ok: retail's bytes at 0X2AE658
void *D_002AE658[10] = {(void *)2, (void *)0x2092, (void *)112, 0, (void *)112, 0, (void *)112, 0, (void *)0xffff0000, (void *)func_00221958};

// data-ok: retail's bytes at 0X2AE680
void *D_002AE680[10] = {(void *)1, (void *)0x2092, (void *)128, 0, (void *)128, 0, (void *)128, 0, (void *)0xffff0000, (void *)func_00221958};

// data-ok: retail's bytes at 0X2AE6A8
void *D_002AE6A8[10] = {(void *)1, (void *)0x2092, (void *)132, 0, (void *)132, 0, (void *)132, 0, (void *)0xffff0000, (void *)func_00221958};

// data-ok: retail's bytes at 0X2AE6D0
struct {
    char m0[4];
    void *m1[9];
} D_002AE6D0 = {
    "\012",
    {(void *)0x2092, (void *)136, 0, (void *)136, 0, (void *)136, 0, (void *)0xffff0000, (void *)func_00221958}
};

// data-ok: retail's bytes at 0X2AE6F8
unsigned int D_002AE6F8[10] = {1, 146, 0x130, 0, 0x130, 0, 0x130, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE720
unsigned int D_002AE720[10] = {0, 146, 0x120, 0, 0x120, 0, 0x120, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE748
unsigned int D_002AE748[10] = {0x100e, 146, 0x164, 0, 0x164, 0, 0x164, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE770
unsigned int D_002AE770[10] = {0, 146, 0x168, 0, 0x168, 0, 0x168, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE798
unsigned int D_002AE798[10] = {0, 146, 0x16c, 0, 0x16c, 0, 0x16c, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE7C0
unsigned int D_002AE7C0[10] = {5, 146, 0x128, 0, 0x128, 0, 0x128, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE7E8
unsigned int D_002AE7E8[10] = {0, 146, 0x124, 0, 0x124, 0, 0x124, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE810
unsigned int D_002AE810[10] = {0x100a, 146, 0x180, 0, 0x180, 0, 0x180, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE838
unsigned int D_002AE838[10] = {1, 146, 0x170, 0, 0x170, 0, 0x170, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE860
unsigned int D_002AE860[10] = {1, 146, 0x174, 0, 0x174, 0, 0x174, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE888
unsigned int D_002AE888[10] = {1, 146, 0x178, 0, 0x178, 0, 0x178, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE8B0
unsigned int D_002AE8B0[10] = {1, 146, 0x17c, 0, 0x17c, 0, 0x17c, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE8D8
unsigned int D_002AE8D8[10] = {0, 146, 0x184, 0, 0x184, 0, 0x184, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE900
unsigned int D_002AE900[10] = {1, 146, 0x188, 0, 0x188, 0, 0x188, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE928
unsigned int D_002AE928[10] = {0, 146, 0x18c, 0, 0x18c, 0, 0x18c, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE950
unsigned int D_002AE950[10] = {0x2002, 146, 0x190, 0, 0x190, 0, 0x190, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE978
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AE978 = {
    "\011",
    {146, 0x1a0, 0, 0x1a0, 0, 0x1a0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AE9A0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AE9A0 = {
    "\012",
    {146, 0x1b0, 0, 0x1b0, 0, 0x1b0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AE9C8
unsigned int D_002AE9C8[10] = {0x100f, 2, 0x134, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AE9F0
void *D_002AE9F0[10] = {(void *)0x100f, (void *)162, (void *)0x13c, 0, (void *)0xffff0000, (void *)SetTnTnsOverride, (void *)0x13c, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEA18
unsigned int D_002AEA18[10] = {0x1011, 146, 232, 0, 232, 0, 232, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEA40
unsigned int D_002AEA40[10] = {1, 146, 236, 0, 236, 0, 236, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEA68
unsigned int D_002AEA68[10] = {0, 146, 240, 0, 240, 0, 240, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEA90
unsigned int D_002AEA90[10] = {6, 146, 244, 0, 244, 0, 244, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEAB8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AEAB8 = {
    "\012",
    {146, 236, 0, 236, 0, 236, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AEAE0
unsigned int D_002AEAE0[10] = {1, 146, 232, 0, 232, 0, 232, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEB08
unsigned int D_002AEB08[10] = {0x1053, 146, 244, 0, 244, 0, 244, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEB30
unsigned int D_002AEB30[10] = {2, 146, 0x240, 0, 0x240, 0, 0x240, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEB58
unsigned int D_002AEB58[10] = {1, 146, 0x220, 0, 0x220, 0, 0x220, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEB80
void *D_002AEB80[10] = {(void *)1, (void *)0x122, (void *)0x1f0, 0, (void *)0xffff0000, (void *)SetStepSpinRatio__FP4STEPf, (void *)0xffff0000, (void *)SetStepSpinRatio__FP4STEPf, 0, 0};

// data-ok: retail's bytes at 0X2AEBA8
void *D_002AEBA8[10] = {(void *)1, (void *)0x122, (void *)0x260, 0, (void *)0xffff0000, (void *)SetStepGravityRatio__FP4STEPf, (void *)0xffff0000, (void *)SetStepGravityRatio__FP4STEPf, 0, 0};

// data-ok: retail's bytes at 0X2AEBD0
unsigned int D_002AEBD0[10] = {6, 128, 0, 0, 0, 0, 0x264, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEBF8
void *D_002AEBF8[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00102858, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEC20
void *D_002AEC20[10] = {0, (void *)162, (void *)0x204, 0, (void *)0xffff0000, (void *)func_00203FA0, (void *)0x204, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEC48
void *D_002AEC48[10] = {(void *)1, (void *)34, (void *)0x1a8, 0, (void *)0xffff0000, (void *)SetStepRadTarget_thunk, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEC70
unsigned int D_002AEC70[10] = {2, 18, 0x190, 0, 0x190, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEC98
unsigned int D_002AEC98[10] = {0, 146, 0x298, 0, 0x298, 0, 0x298, 0, 0, 0};

// data-ok: retail's bytes at 0X2AECC0
unsigned int D_002AECC0[10] = {0, 146, 0x29c, 0, 0x29c, 0, 0x29c, 0, 0, 0};

// data-ok: retail's bytes at 0X2AECE8
void *D_002AECE8[10] = {(void *)18, (void *)0x401, (void *)RefCallAddGuardAimOid, 0, (void *)RefCallAddGuardAimOidResolve, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AED10
void *D_002AED10[10] = {(void *)18, (void *)0x401, (void *)RefCallClearGuardAimObjects, 0, (void *)RefCallClearGuardAimObjects, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AED38
struct {
    char m0[4];
    void *m1[9];
} D_002AED38 = {
    "\012",
    {(void *)0x2092, (void *)80, 0, (void *)80, 0, (void *)80, 0, (void *)0xffff0000, (void *)func_0020A9C0}
};

// data-ok: retail's bytes at 0X2AED60
struct {
    char m0[4];
    void *m1[9];
} D_002AED60 = {
    "\012",
    {(void *)0x2092, (void *)88, 0, (void *)88, 0, (void *)88, 0, (void *)0xffff0000, (void *)func_0020A9C0}
};

// data-ok: retail's bytes at 0X2AED88
struct {
    char m0[4];
    void *m1[9];
} D_002AED88 = {
    "\012",
    {(void *)0x2092, (void *)96, 0, (void *)96, 0, (void *)96, 0, (void *)0xffff0000, (void *)func_0020A9C0}
};

// data-ok: retail's bytes at 0X2AEDB0
void *D_002AEDB0[10] = {(void *)1, (void *)0x2120, 0, 0, (void *)0xffff0000, (void *)func_0020AF08, (void *)0xffff0000, (void *)func_0020AF08, (void *)0xffff0000, (void *)func_0020A9C0};

// data-ok: retail's bytes at 0X2AEDD8
void *D_002AEDD8[10] = {(void *)1, (void *)0x2092, (void *)104, 0, (void *)104, 0, (void *)104, 0, (void *)0xffff0000, (void *)func_0020A9C0};

// data-ok: retail's bytes at 0X2AEE00
void *D_002AEE00[10] = {0, (void *)0x2092, (void *)120, 0, (void *)120, 0, (void *)120, 0, (void *)0xffff0000, (void *)func_0020A9C0};

// data-ok: retail's bytes at 0X2AEE28
void *D_002AEE28[10] = {0, (void *)0x2092, (void *)112, 0, (void *)112, 0, (void *)112, 0, (void *)0xffff0000, (void *)func_0020A9C0};

// data-ok: retail's bytes at 0X2AEE50
void *D_002AEE50[10] = {0, (void *)0x2092, (void *)168, 0, (void *)168, 0, (void *)168, 0, (void *)0xffff0000, (void *)func_0020A9C0};

// data-ok: retail's bytes at 0X2AEE78
void *D_002AEE78[10] = {(void *)18, (void *)0x401, (void *)RefCallUseGuardAnimation, 0, (void *)RefCallUseGuardAnimationImmediate, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEEA0
void *D_002AEEA0[10] = {(void *)18, (void *)0x401, (void *)func_00102C38, 0, (void *)func_00102D30, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEEC8
void *D_002AEEC8[10] = {(void *)18, (void *)0x401, (void *)func_00102E28, 0, (void *)func_00102F38, 0, (void *)6, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEEF0
void *D_002AEEF0[10] = {(void *)18, (void *)0x401, (void *)func_00103048, 0, (void *)func_00103100, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEF18
void *D_002AEF18[10] = {(void *)18, (void *)0x401, (void *)func_001031B8, 0, (void *)func_00103270, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEF40
void *D_002AEF40[10] = {(void *)18, (void *)0x401, (void *)func_00103328, 0, (void *)func_001033E0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEF68
unsigned int D_002AEF68[10] = {0x1011, 146, 0x350, 0, 0x350, 0, 0x350, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEF90
unsigned int D_002AEF90[10] = {0x1011, 146, 0x354, 0, 0x354, 0, 0x354, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEFB8
unsigned int D_002AEFB8[10] = {0x1011, 146, 0x358, 0, 0x358, 0, 0x358, 0, 0, 0};

// data-ok: retail's bytes at 0X2AEFE0
void *D_002AEFE0[10] = {(void *)5, (void *)0x124, (void *)0xffff0000, (void *)func_00206458, (void *)0xffff0000, (void *)func_00206488, (void *)0xffff0000, (void *)func_00206488, 0, 0};

// data-ok: retail's bytes at 0X2AF008
void *D_002AF008[10] = {(void *)5, (void *)0x124, (void *)0xffff0000, (void *)func_002064A0, (void *)0xffff0000, (void *)func_002064C0, (void *)0xffff0000, (void *)func_002064C0, 0, 0};

// data-ok: retail's bytes at 0X2AF030
unsigned int D_002AF030[10] = {5, 146, 0x338, 0, 0x338, 0, 0x338, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF058
unsigned int D_002AF058[10] = {5, 146, 0x33c, 0, 0x33c, 0, 0x33c, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF080
unsigned int D_002AF080[10] = {5, 146, 0x340, 0, 0x340, 0, 0x340, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF0A8
unsigned int D_002AF0A8[10] = {5, 146, 0x340, 0, 0x340, 0, 0x340, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF0D0
unsigned int D_002AF0D0[10] = {5, 146, 0x344, 0, 0x344, 0, 0x344, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF0F8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF0F8 = {
    "m ",
    {146, 0x348, 0, 0x348, 0, 0x348, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF120
void *D_002AF120[10] = {(void *)0x2002, (void *)34, (void *)0x38c, 0, (void *)0xffff0000, (void *)func_00208538, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF148
void *D_002AF148[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00103498, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF170
void *D_002AF170[10] = {(void *)18, (void *)0x401, (void *)func_00103520, 0, (void *)func_00103520, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF198
void *D_002AF198[10] = {(void *)18, (void *)0x401, (void *)func_001035A8, 0, (void *)func_001035A8, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF1C0
void *D_002AF1C0[10] = {(void *)18, (void *)0x401, (void *)func_00103630, 0, (void *)func_00103630, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF1E8
void *D_002AF1E8[10] = {(void *)18, (void *)1, 0, 0, (void *)func_001036A8, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF210
void *D_002AF210[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00103730, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF238
void *D_002AF238[10] = {(void *)18, (void *)0x401, (void *)func_001037A8, 0, (void *)func_001037A8, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF260
void *D_002AF260[10] = {(void *)18, (void *)0x401, (void *)func_00103830, 0, (void *)func_00103830, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF288
void *D_002AF288[10] = {(void *)18, (void *)0x401, (void *)func_001038B8, 0, (void *)func_001038B8, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF2B0
void *D_002AF2B0[10] = {(void *)18, (void *)0x401, (void *)func_00103930, 0, (void *)func_00103930, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF2D8
void *D_002AF2D8[10] = {(void *)18, (void *)0x401, (void *)func_001039B8, 0, (void *)func_001039B8, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF300
void *D_002AF300[10] = {(void *)18, (void *)0x401, (void *)func_00103A40, 0, (void *)func_00103A40, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF328
struct {
    char m0[4];
    void *m1[9];
} D_002AF328 = {
    "q ",
    {(void *)162, (void *)0x2e8, 0, (void *)0xffff0000, (void *)func_0020A540, (void *)0x2e8, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF350
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF350 = {
    "\012",
    {146, 0x2cc, 0, 0x2cc, 0, 0x2cc, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF378
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF378 = {
    "\012",
    {146, 0x2d4, 0, 0x2d4, 0, 0x2d4, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF3A0
unsigned int D_002AF3A0[10] = {5, 146, 0x3d8, 0, 0x3d8, 0, 0x3d8, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF3C8
unsigned int D_002AF3C8[10] = {2, 146, 0x3e0, 0, 0x3e0, 0, 0x3e0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF3F0
void *D_002AF3F0[10] = {(void *)0x9010, (void *)4, (void *)0xffff0000, (void *)func_00209A88, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF418
void *D_002AF418[10] = {0, (void *)1, 0, 0, (void *)func_00103AB8, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF440
unsigned int D_002AF440[10] = {0, 146, 0xf38, 0, 0xf38, 0, 0xf38, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF468
unsigned int D_002AF468[10] = {0, 146, 0xe64, 0, 0xe64, 0, 0xe64, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF490
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF490 = {
    "u ",
    {146, 0xe60, 0, 0xe60, 0, 0xe60, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF4B8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF4B8 = {
    "\012",
    {146, 0xe7c, 0, 0xe7c, 0, 0xe7c, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF4E0
unsigned int D_002AF4E0[10] = {0, 146, 0x364, 0, 0x364, 0, 0x364, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF508
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF508 = {
    "\012",
    {146, 0x370, 0, 0x370, 0, 0x370, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF530
unsigned int D_002AF530[10] = {1, 146, 0x378, 0, 0x378, 0, 0x378, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF558
unsigned int D_002AF558[10] = {0, 146, 0x37c, 0, 0x37c, 0, 0x37c, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF580
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF580 = {
    "\012",
    {146, 0x380, 0, 0x380, 0, 0x380, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF5A8
unsigned int D_002AF5A8[10] = {1, 146, 0x388, 0, 0x388, 0, 0x388, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF5D0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF5D0 = {
    "\012",
    {146, 0x368, 0, 0x368, 0, 0x368, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF5F8
unsigned int D_002AF5F8[10] = {0, 18, 0x4a0, 0, 0x4a0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF620
unsigned int D_002AF620[10] = {1, 146, 0x314, 0, 0x314, 0, 0x314, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF648
unsigned int D_002AF648[10] = {1, 146, 0x318, 0, 0x318, 0, 0x318, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF670
unsigned int D_002AF670[10] = {5, 146, 0xe84, 0, 0xe84, 0, 0xe84, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF698
unsigned int D_002AF698[10] = {5, 146, 0xe88, 0, 0xe88, 0, 0xe88, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF6C0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF6C0 = {
    "\012",
    {146, 0x31c, 0, 0x31c, 0, 0x31c, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF6E8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF6E8 = {
    "\012",
    {146, 0x324, 0, 0x324, 0, 0x324, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF710
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF710 = {
    "\012",
    {146, 0xf48, 0, 0xf48, 0, 0xf48, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF738
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF738 = {
    "\012",
    {146, 0xf50, 0, 0xf50, 0, 0xf50, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF760
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF760 = {
    "\012",
    {146, 0xf58, 0, 0xf58, 0, 0xf58, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF788
void *D_002AF788[10] = {(void *)0x2011, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_0020A518, (void *)0xffff0000, (void *)func_0020A518, 0, 0};

// data-ok: retail's bytes at 0X2AF7B0
void *D_002AF7B0[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00103B38, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF7D8
unsigned int D_002AF7D8[10] = {0x2016, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF800
unsigned int D_002AF800[10] = {0x2016, 146, 0x3f4, 0, 0x3f4, 0, 0x3f4, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF828
unsigned int D_002AF828[10] = {0x2016, 146, 0x3f8, 0, 0x3f8, 0, 0x3f8, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF850
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AF850 = {
    "c ",
    {146, 0x494, 0, 0x494, 0, 0x494, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AF878
unsigned int D_002AF878[10] = {0, 146, 0x490, 0, 0x490, 0, 0x490, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF8A0
void *D_002AF8A0[10] = {(void *)18, (void *)0x401, (void *)func_00103C18, 0, (void *)func_00103C18, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF8C8
void *D_002AF8C8[10] = {(void *)18, (void *)0x401, (void *)func_00103CA0, 0, (void *)func_00103CA0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF8F0
void *D_002AF8F0[10] = {(void *)18, (void *)0x401, (void *)func_00103D28, 0, (void *)func_00103D28, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF918
void *D_002AF918[10] = {(void *)0x8006, (void *)4, (void *)0xffff0000, (void *)func_001F1EB8, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AF940
void *D_002AF940[10] = {(void *)0x1016, (void *)0x2092, (void *)248, 0, (void *)248, 0, (void *)248, 0, (void *)0xffff0000, (void *)func_00206378};

// data-ok: retail's bytes at 0X2AF968
void *D_002AF968[10] = {0, (void *)0x2092, (void *)240, 0, (void *)240, 0, (void *)240, 0, (void *)0xffff0000, (void *)func_00206378};

// data-ok: retail's bytes at 0X2AF990
void *D_002AF990[10] = {0, (void *)0x2092, (void *)244, 0, (void *)244, 0, (void *)244, 0, (void *)0xffff0000, (void *)func_00206378};

// data-ok: retail's bytes at 0X2AF9B8
void *D_002AF9B8[10] = {(void *)0x2016, (void *)0x124, (void *)0xffff0000, (void *)0x259d60, (void *)0xffff0000, (void *)func_00259D38, (void *)0xffff0000, (void *)func_00259D38, 0, 0};

// data-ok: retail's bytes at 0X2AF9E0
void *D_002AF9E0[10] = {(void *)0x2016, (void *)0x124, (void *)0xffff0000, (void *)func_00259D70, (void *)0xffff0000, (void *)func_00259D48, (void *)0xffff0000, (void *)func_00259D48, 0, 0};

// data-ok: retail's bytes at 0X2AFA08
void *D_002AFA08[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00103DB0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFA30
void *D_002AFA30[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00103E38, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFA58
void *D_002AFA58[10] = {0, (void *)1, 0, 0, (void *)func_00103EC0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFA80
unsigned int D_002AFA80[10] = {0, 146, 0xf30, 0, 0xf30, 0, 0xf30, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFAA8
unsigned int D_002AFAA8[10] = {0, 146, 0xf34, 0, 0xf34, 0, 0xf34, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFAD0
void *D_002AFAD0[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00103F40, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFAF8
unsigned int D_002AFAF8[10] = {0x1047, 146, 0xe68, 0, 0xe68, 0, 0xe68, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFB20
unsigned int D_002AFB20[10] = {0, 146, 0xf40, 0, 0xf40, 0, 0xf40, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFB48
unsigned int D_002AFB48[10] = {0x2003, 146, 0xf90, 0, 0xf90, 0, 0xf90, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFB70
void *D_002AFB70[10] = {(void *)5, (void *)4, (void *)0xffff0000, (void *)CHitClingingGuard, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFB98
unsigned int D_002AFB98[10] = {0x2003, 146, 0xe74, 0, 0xe74, 0, 0xe74, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFBC0
unsigned int D_002AFBC0[10] = {0x1062, 146, 0xe78, 0, 0xe78, 0, 0xe78, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFBE8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AFBE8 = {
    "\012",
    {146, 0xe6c, 0, 0xe6c, 0, 0xe6c, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AFC10
void *D_002AFC10[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00103FE8, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFC38
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AFC38 = {
    "$ ",
    {146, 0xfec, 0, 0xfec, 0, 0xfec, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AFC60
unsigned int D_002AFC60[10] = {0, 146, 0x334, 0, 0x334, 0, 0x334, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFC88
unsigned int D_002AFC88[10] = {0, 146, 0x3d0, 0, 0x3d0, 0, 0x3d0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFCB0
void *D_002AFCB0[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00104060, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFCD8
void *D_002AFCD8[10] = {(void *)0x106b, (void *)1, 0, 0, (void *)RefPchzFriendlyFromWidOwner, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFD00
unsigned int D_002AFD00[10] = {0, 18, 0xfc8, 0, 0xfc8, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFD28
unsigned int D_002AFD28[10] = {0x2002, 18, 0xfcc, 0, 0xfcc, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFD50
unsigned int D_002AFD50[10] = {0, 146, 0x4a4, 0, 0x4a4, 0, 0x4a4, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFD78
unsigned int D_002AFD78[10] = {5, 146, 0x3f0, 0, 0x3f0, 0, 0x3f0, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFDA0
unsigned int D_002AFDA0[10] = {0, 146, 0x3d4, 0, 0x3d4, 0, 0x3d4, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFDC8
unsigned int D_002AFDC8[10] = {0x106f, 146, 0x1000, 0, 0x1000, 0, 0x1000, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFDF0
unsigned int D_002AFDF0[10] = {0x1016, 146, 248, 0, 248, 0, 248, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFE18
unsigned int D_002AFE18[10] = {0, 146, 240, 0, 240, 0, 240, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFE40
unsigned int D_002AFE40[10] = {0, 146, 244, 0, 244, 0, 244, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFE68
unsigned int D_002AFE68[10] = {0x2016, 146, 232, 0, 232, 0, 232, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFE90
unsigned int D_002AFE90[10] = {0x2016, 146, 236, 0, 236, 0, 236, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFEB8
void *D_002AFEB8[10] = {(void *)0x106b, (void *)1, 0, 0, (void *)func_00104188, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFEE0
unsigned int D_002AFEE0[10] = {0x2002, 146, 224, 0, 224, 0, 224, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFF08
void *D_002AFF08[10] = {(void *)0x2002, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)AddSensorLo, (void *)0xffff0000, (void *)AddSensorLo, 0, 0};

// data-ok: retail's bytes at 0X2AFF30
void *D_002AFF30[10] = {(void *)0x2002, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)RemoveSensorLo, (void *)0xffff0000, (void *)RemoveSensorLo, 0, 0};

// data-ok: retail's bytes at 0X2AFF58
void *D_002AFF58[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00104228, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFF80
void *D_002AFF80[10] = {(void *)0x106b, (void *)1, 0, 0, (void *)RefPchzFriendlyFromWid, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2AFFA8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AFFA8 = {
    "\012",
    {146, 80, 0, 80, 0, 80, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AFFD0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002AFFD0 = {
    "\012",
    {146, 88, 0, 88, 0, 88, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2AFFF8
struct {
    char m0[4];
    unsigned int m1;
} D_002AFFF8 = {
    "\012",
    146
};

// data-ok: retail's bytes at 0X2B0000
struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
    char m4[4];
    char m5[4];
    char m6[4];
    char m7[4];
} D_002B0000 = {
    "`",
    "",
    "`",
    "",
    "`",
    "",
    "",
    ""
};

// data-ok: retail's bytes at 0X2B0020
void *D_002B0020[10] = {(void *)1, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_0020AF08, (void *)0xffff0000, (void *)func_0020AF08, 0, 0};

// data-ok: retail's bytes at 0X2B0048
unsigned int D_002B0048[10] = {1, 146, 104, 0, 104, 0, 104, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0070
unsigned int D_002B0070[10] = {0, 146, 120, 0, 120, 0, 120, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0098
unsigned int D_002B0098[10] = {0, 146, 112, 0, 112, 0, 112, 0, 0, 0};

// data-ok: retail's bytes at 0X2B00C0
unsigned int D_002B00C0[10] = {1, 146, 108, 0, 108, 0, 108, 0, 0, 0};

// data-ok: retail's bytes at 0X2B00E8
unsigned int D_002B00E8[10] = {0, 146, 116, 0, 116, 0, 116, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0110
void *D_002B0110[10] = {(void *)18, (void *)0x401, (void *)func_00104350, 0, (void *)func_00104350, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0138
unsigned int D_002B0138[10] = {0, 146, 168, 0, 168, 0, 168, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0160
void *D_002B0160[10] = {(void *)18, (void *)0x401, (void *)func_00104408, 0, (void *)func_001044B0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0188
void *D_002B0188[10] = {(void *)18, (void *)0x401, (void *)func_00104558, 0, (void *)func_00104638, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2B01B0
void *D_002B01B0[10] = {0, (void *)1, 0, 0, (void *)func_00104718, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B01D8
void *D_002B01D8[10] = {0, (void *)1, 0, 0, (void *)RefCallCheckSphere, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0200
void *D_002B0200[10] = {(void *)0x2088, (void *)1, 0, 0, (void *)RefPsmaApplySm, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0228
void *D_002B0228[10] = {(void *)0x2088, (void *)1, 0, 0, (void *)RefCallApplyWithFilter, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0250
void *D_002B0250[10] = {(void *)18, (void *)0x400, (void *)func_001049B0, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0278
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B0278 = {
    "0 ",
    {2, 40, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B02A0
void *D_002B02A0[10] = {(void *)6, (void *)36, (void *)0xffff0000, (void *)GetSmaGoal, (void *)0xffff0000, (void *)SetSmaGoal__FP3SMA3OID, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B02C8
void *D_002B02C8[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00104A68, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B02F0
void *D_002B02F0[10] = {(void *)1, (void *)1, 0, 0, (void *)RefCallTimeToGoal, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0318
void *D_002B0318[10] = {(void *)6, (void *)4, (void *)0xffff0000, (void *)GetSmaCur, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0340
void *D_002B0340[10] = {(void *)6, (void *)4, (void *)0xffff0000, (void *)func_001F0808, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0368
void *D_002B0368[10] = {(void *)1, (void *)34, (void *)68, 0, (void *)0xffff0000, (void *)SetSmaSvt, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0390
unsigned int D_002B0390[10] = {0x2086, 2, 48, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B03B8
void *D_002B03B8[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00104B70, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B03E0
void *D_002B03E0[10] = {(void *)18, (void *)1, 0, 0, (void *)bevy_game_fields_104bf8, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0408
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B0408 = {
    "o ",
    {2, 36, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B0430
void *D_002B0430[10] = {(void *)0x1054, (void *)34, (void *)72, 0, (void *)0xffff0000, (void *)SetSmaMask, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0458
unsigned int D_002B0458[10] = {1, 146, 0x15c, 0, 0x15c, 0, 0x15c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0480
unsigned int D_002B0480[10] = {1, 146, 0x160, 0, 0x160, 0, 0x160, 0, 0, 0};

// data-ok: retail's bytes at 0X2B04A8
unsigned int D_002B04A8[10] = {0x1018, 146, 0x150, 0, 0x150, 0, 0x150, 0, 0, 0};

// data-ok: retail's bytes at 0X2B04D0
unsigned int D_002B04D0[10] = {0x1019, 146, 0x170, 0, 0x170, 0, 0x170, 0, 0, 0};

// data-ok: retail's bytes at 0X2B04F8
unsigned int D_002B04F8[10] = {0, 146, 0x164, 0, 0x164, 0, 0x164, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0520
unsigned int D_002B0520[10] = {1, 146, 0x16c, 0, 0x16c, 0, 0x16c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0548
void *D_002B0548[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallPrime, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0570
void *D_002B0570[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)func_00104CF8, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0598
unsigned int D_002B0598[10] = {0x1011, 146, 0x1ec, 0, 0x1ec, 0, 0x1ec, 0, 0, 0};

// data-ok: retail's bytes at 0X2B05C0
unsigned int D_002B05C0[10] = {1, 146, 0x158, 0, 0x158, 0, 0x158, 0, 0, 0};

// data-ok: retail's bytes at 0X2B05E8
unsigned int D_002B05E8[10] = {0, 130, 0x1f4, 0, 0, 0, 0x1f4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0610
unsigned int D_002B0610[10] = {0x201e, 146, 0x168, 0, 0x168, 0, 0x168, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0638
unsigned int D_002B0638[10] = {5, 146, 0x1f0, 0, 0x1f0, 0, 0x1f0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0660
unsigned int D_002B0660[10] = {0, 146, 0x1e0, 0, 0x1e0, 0, 0x1e0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0688
void *D_002B0688[10] = {(void *)0x2002, (void *)34, (void *)0x200, 0, (void *)0xffff0000, (void *)InferExpl, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B06B0
unsigned int D_002B06B0[10] = {0, 146, 0x1e4, 0, 0x1e4, 0, 0x1e4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B06D8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B06D8 = {
    "0 ",
    {2, 0x1e8, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B0700
unsigned int D_002B0700[10] = {0x2002, 18, 0x210, 0, 0x210, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0728
unsigned int D_002B0728[10] = {2, 18, 0x220, 0, 0x220, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0750
unsigned int D_002B0750[10] = {0, 146, 0x264, 0, 0x264, 0, 0x264, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0778
void *D_002B0778[10] = {(void *)18, (void *)0x400, (void *)func_00104D70, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B07A0
void *D_002B07A0[10] = {(void *)18, (void *)0x400, (void *)func_00104DF8, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B07C8
void *D_002B07C8[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00104E80, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B07F0
unsigned int D_002B07F0[10] = {1, 146, 0x260, 0, 0x260, 0, 0x260, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0818
unsigned int D_002B0818[10] = {1, 146, 0x26c, 0, 0x26c, 0, 0x26c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0840
unsigned int D_002B0840[10] = {1, 146, 0x274, 0, 0x274, 0, 0x274, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0868
unsigned int D_002B0868[10] = {1, 146, 0x270, 0, 0x270, 0, 0x270, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0890
unsigned int D_002B0890[10] = {1, 146, 0x270, 0, 0x270, 0, 0x270, 0, 0, 0};

// data-ok: retail's bytes at 0X2B08B8
unsigned int D_002B08B8[10] = {1, 146, 0x274, 0, 0x274, 0, 0x274, 0, 0, 0};

// data-ok: retail's bytes at 0X2B08E0
unsigned int D_002B08E0[10] = {2, 146, 0x280, 0, 0x280, 0, 0x280, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0908
unsigned int D_002B0908[10] = {0x101a, 130, 0x2a8, 0, 0, 0, 0x2a8, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0930
unsigned int D_002B0930[10] = {0x2013, 146, 0x2f4, 0, 0x2f4, 0, 0x2f4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0958
void *D_002B0958[10] = {(void *)18, (void *)0x400, (void *)func_00104F40, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0980
void *D_002B0980[10] = {(void *)18, (void *)0x400, (void *)func_00104FE8, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B09A8
struct {
    char m0[4];
    void *m1[9];
} D_002B09A8 = {
    "0 ",
    {(void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_00149220, (void *)0xffff0000, (void *)func_00149220, 0, 0}
};

// data-ok: retail's bytes at 0X2B09D0
void *D_002B09D0[10] = {(void *)7, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_00149248, (void *)0xffff0000, (void *)func_00149248, 0, 0};

// data-ok: retail's bytes at 0X2B09F8
unsigned int D_002B09F8[10] = {1, 146, 0x1e8, 0, 0x1e8, 0, 0x1e8, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0A20
unsigned int D_002B0A20[10] = {1, 146, 0x1dc, 0, 0x1dc, 0, 0x1dc, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0A48
unsigned int D_002B0A48[10] = {0, 146, 0x1ec, 0, 0x1ec, 0, 0x1ec, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0A70
unsigned int D_002B0A70[10] = {0, 146, 0x1f0, 0, 0x1f0, 0, 0x1f0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0A98
unsigned int D_002B0A98[10] = {0, 146, 0x1f4, 0, 0x1f4, 0, 0x1f4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0AC0
void *D_002B0AC0[10] = {(void *)18, (void *)0x401, (void *)func_00105090, 0, (void *)func_00105090, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0AE8
void *D_002B0AE8[10] = {(void *)18, (void *)0x401, (void *)func_00105158, 0, (void *)func_00105158, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0B10
void *D_002B0B10[10] = {(void *)0x101b, (void *)34, (void *)0x1e0, 0, (void *)0xffff0000, (void *)SetButtonButtons, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0B38
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B0B38 = {
    "0 ",
    {2, 0x2f8, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B0B60
void *D_002B0B60[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)func_00105200, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0B88
void *D_002B0B88[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)func_00105278, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0BB0
void *D_002B0BB0[10] = {(void *)18, (void *)0x400, (void *)func_001052F0, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0BD8
void *D_002B0BD8[10] = {(void *)18, (void *)0x400, (void *)func_00105398, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0C00
void *D_002B0C00[10] = {(void *)0x2002, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_001497B8, (void *)0xffff0000, (void *)func_001497B8, 0, 0};

// data-ok: retail's bytes at 0X2B0C28
void *D_002B0C28[10] = {(void *)7, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_001497E0, (void *)0xffff0000, (void *)func_001497E0, 0, 0};

// data-ok: retail's bytes at 0X2B0C50
unsigned int D_002B0C50[10] = {1, 146, 0x1c8, 0, 0x1c8, 0, 0x1c8, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0C78
unsigned int D_002B0C78[10] = {1, 146, 0x1bc, 0, 0x1bc, 0, 0x1bc, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0CA0
unsigned int D_002B0CA0[10] = {0, 146, 0x1cc, 0, 0x1cc, 0, 0x1cc, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0CC8
unsigned int D_002B0CC8[10] = {0, 146, 0x1d0, 0, 0x1d0, 0, 0x1d0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0CF0
unsigned int D_002B0CF0[10] = {0, 146, 0x1d4, 0, 0x1d4, 0, 0x1d4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0D18
void *D_002B0D18[10] = {(void *)18, (void *)0x401, (void *)func_00105440, 0, (void *)func_00105440, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0D40
void *D_002B0D40[10] = {(void *)18, (void *)0x401, (void *)func_00105508, 0, (void *)func_00105508, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0D68
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B0D68 = {
    "r ",
    {146, 0x1dc, 0, 0x1dc, 0, 0x1dc, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B0D90
void *D_002B0D90[10] = {(void *)0x101b, (void *)34, (void *)0x1c0, 0, (void *)0xffff0000, (void *)SetVolbtnButtons, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0DB8
unsigned int D_002B0DB8[10] = {0, 130, 0x2c8, 0, 0, 0, 0x2c8, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0DE0
void *D_002B0DE0[10] = {(void *)0xa002, (void *)4, (void *)0xffff0000, (void *)FGetVolbtnPushObjectsWithinList, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0E08
void *D_002B0E08[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)func_001055B0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0E30
void *D_002B0E30[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)func_00105628, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0E58
unsigned int D_002B0E58[10] = {0x2002, 2, 0x1d8, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0E80
void *D_002B0E80[10] = {(void *)6, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001DE3D8, 0, 0};

// data-ok: retail's bytes at 0X2B0EA8
void *D_002B0EA8[10] = {(void *)7, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001DE3B0, 0, 0};

// data-ok: retail's bytes at 0X2B0ED0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B0ED0 = {
    "0 ",
    {146, 0x190, 0, 0x190, 0, 0x190, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B0EF8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B0EF8 = {
    "0 ",
    {146, 0x194, 0, 0x194, 0, 0x194, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B0F20
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B0F20 = {
    "0 ",
    {146, 0x1a0, 0, 0x1a0, 0, 0x1a0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B0F48
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B0F48 = {
    "0 ",
    {146, 0x1b0, 0, 0x1b0, 0, 0x1b0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B0F70
unsigned int D_002B0F70[10] = {1, 146, 0x1c0, 0, 0x1c0, 0, 0x1c0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0F98
void *D_002B0F98[10] = {(void *)18, (void *)0x400, (void *)RefCallAddBeam, 0, 0, 0, (void *)10, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0FC0
void *D_002B0FC0[10] = {(void *)18, (void *)0x400, (void *)RefCallAddBarrierObject, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B0FE8
void *D_002B0FE8[10] = {(void *)18, (void *)0x400, (void *)RefCallAddBarrierClass, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1010
unsigned int D_002B1010[10] = {0, 130, 0x178, 0, 0, 0, 0x178, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1038
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B1038 = {
    "0 ",
    {2, 0x17c, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B1060
unsigned int D_002B1060[10] = {0x2002, 146, 96, 0, 96, 0, 96, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1088
unsigned int D_002B1088[10] = {2, 146, 80, 0, 80, 0, 80, 0, 0, 0};

// data-ok: retail's bytes at 0X2B10B0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B10B0 = {
    "\011",
    {146, 112, 0, 112, 0, 112, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B10D8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B10D8 = {
    "\012",
    {146, 128, 0, 128, 0, 128, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B1100
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B1100 = {
    "\011",
    {146, 144, 0, 144, 0, 144, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B1128
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B1128 = {
    "\012",
    {146, 160, 0, 160, 0, 160, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B1150
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B1150 = {
    "\012",
    {146, 168, 0, 168, 0, 168, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B1178
unsigned int D_002B1178[10] = {1, 146, 176, 0, 176, 0, 176, 0, 0, 0};

// data-ok: retail's bytes at 0X2B11A0
void *D_002B11A0[10] = {(void *)18, (void *)1, 0, 0, (void *)func_001058F0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B11C8
void *D_002B11C8[10] = {(void *)5, (void *)0x122, (void *)244, 0, (void *)0xffff0000, (void *)SetEmitterEnabled__FP7EMITTERi, (void *)0xffff0000, (void *)SetEmitterEnabled__FP7EMITTERi, 0, 0};

// data-ok: retail's bytes at 0X2B11F0
void *D_002B11F0[10] = {0, (void *)0x122, (void *)0x114, 0, (void *)0xffff0000, (void *)func_0015A2B0, (void *)0xffff0000, (void *)func_0015A2B0, 0, 0};

// data-ok: retail's bytes at 0X2B1218
void *D_002B1218[10] = {(void *)0x1025, (void *)0x2092, (void *)240, 0, (void *)240, 0, (void *)240, 0, (void *)0xffff0000, (void *)func_00159A08};

// data-ok: retail's bytes at 0X2B1240
struct {
    char m0[4];
    void *m1[9];
} D_002B1240 = {
    "\012",
    {(void *)0x2092, (void *)248, 0, (void *)248, 0, (void *)248, 0, (void *)0xffff0000, (void *)func_00159A08}
};

// data-ok: retail's bytes at 0X2B1268
void *D_002B1268[10] = {(void *)1, (void *)0x2092, (void *)0x110, 0, (void *)0x110, 0, (void *)0x110, 0, (void *)0xffff0000, (void *)func_00159A08};

// data-ok: retail's bytes at 0X2B1290
void *D_002B1290[10] = {(void *)1, (void *)0x2092, (void *)0x104, 0, (void *)0x104, 0, (void *)0x104, 0, (void *)0xffff0000, (void *)func_00159A08};

// data-ok: retail's bytes at 0X2B12B8
struct {
    char m0[4];
    void *m1[9];
} D_002B12B8 = {
    "\012",
    {(void *)0x2092, (void *)0x108, 0, (void *)0x108, 0, (void *)0x108, 0, (void *)0xffff0000, (void *)func_00159A08}
};

// data-ok: retail's bytes at 0X2B12E0
unsigned int D_002B12E0[10] = {0, 130, 0x100, 0, 0, 0, 0x100, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1308
unsigned int D_002B1308[10] = {6, 130, 0x118, 0, 0, 0, 0x118, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1330
void *D_002B1330[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00105978, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1358
void *D_002B1358[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallPauseForever, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1380
void *D_002B1380[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallUnpause, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B13A8
void *D_002B13A8[10] = {0, (void *)4, (void *)0xffff0000, (void *)FPausedEmitter__FP7EMITTER, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B13D0
void *D_002B13D0[10] = {(void *)0x1021, (void *)0x104, (void *)0xffff0000, (void *)func_002589F0, 0, 0, (void *)0xffff0000, (void *)func_002589A8, 0, 0};

// data-ok: retail's bytes at 0X2B13F8
void *D_002B13F8[10] = {(void *)0x1022, (void *)0x104, (void *)0xffff0000, (void *)func_00258AB8, 0, 0, (void *)0xffff0000, (void *)SetEmitterEmitok, 0, 0};

// data-ok: retail's bytes at 0X2B1420
void *D_002B1420[10] = {(void *)2, (void *)0x2082, (void *)32, 0, 0, 0, (void *)32, 0, (void *)0xffff0000, (void *)func_00258AC8};

// data-ok: retail's bytes at 0X2B1448
void *D_002B1448[10] = {(void *)2, (void *)0x2082, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00258B00};

// data-ok: retail's bytes at 0X2B1470
void *D_002B1470[10] = {(void *)2, (void *)0x2082, (void *)16, 0, 0, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00258B00};

// data-ok: retail's bytes at 0X2B1498
void *D_002B1498[10] = {(void *)6, (void *)0x2082, (void *)32, 0, 0, 0, (void *)32, 0, (void *)0xffff0000, (void *)func_00258B38};

// data-ok: retail's bytes at 0X2B14C0
void *D_002B14C0[10] = {(void *)6, (void *)0x2082, (void *)32, 0, 0, 0, (void *)32, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B14E8
void *D_002B14E8[10] = {(void *)18, (void *)0x400, (void *)func_00105AF0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1510
void *D_002B1510[10] = {(void *)0x1023, (void *)0x2082, (void *)20, 0, 0, 0, (void *)20, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B1538
void *D_002B1538[10] = {(void *)2, (void *)0x2092, (void *)64, 0, (void *)64, 0, (void *)64, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B1560
void *D_002B1560[10] = {(void *)2, (void *)0x2092, (void *)64, 0, (void *)64, 0, (void *)64, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B1588
void *D_002B1588[10] = {(void *)2, (void *)0x2092, (void *)64, 0, (void *)64, 0, (void *)64, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B15B0
struct {
    char m0[4];
    void *m1[9];
} D_002B15B0 = {
    "\012",
    {(void *)0x2092, (void *)36, 0, (void *)36, 0, (void *)36, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter}
};

// data-ok: retail's bytes at 0X2B15D8
void *D_002B15D8[10] = {(void *)0x1024, (void *)0x2092, (void *)24, 0, (void *)24, 0, (void *)24, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B1600
struct {
    char m0[4];
    void *m1[9];
} D_002B1600 = {
    "\012",
    {(void *)0x2092, (void *)80, 0, (void *)80, 0, (void *)80, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter}
};

// data-ok: retail's bytes at 0X2B1628
void *D_002B1628[10] = {(void *)1, (void *)0x2092, (void *)92, 0, (void *)92, 0, (void *)92, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B1650
void *D_002B1650[10] = {(void *)2, (void *)0x2092, (void *)96, 0, (void *)96, 0, (void *)96, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B1678
void *D_002B1678[10] = {(void *)1, (void *)0x2092, (void *)88, 0, (void *)88, 0, (void *)88, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B16A0
void *D_002B16A0[10] = {(void *)1, (void *)0x2092, (void *)128, 0, (void *)128, 0, (void *)128, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B16C8
void *D_002B16C8[10] = {(void *)2, (void *)0x2092, (void *)112, 0, (void *)112, 0, (void *)112, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B16F0
struct {
    char m0[4];
    void *m1[9];
} D_002B16F0 = {
    "\012",
    {(void *)0x2092, (void *)144, 0, (void *)144, 0, (void *)144, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter}
};

// data-ok: retail's bytes at 0X2B1718
void *D_002B1718[10] = {(void *)5, (void *)0x2092, (void *)132, 0, (void *)132, 0, (void *)132, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B1740
void *D_002B1740[10] = {(void *)1, (void *)0x2092, (void *)136, 0, (void *)136, 0, (void *)136, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B1768
void *D_002B1768[10] = {(void *)1, (void *)0x2092, (void *)140, 0, (void *)140, 0, (void *)140, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter};

// data-ok: retail's bytes at 0X2B1790
struct {
    char m0[4];
    void *m1[9];
} D_002B1790 = {
    "\012",
    {(void *)0x2092, (void *)152, 0, (void *)152, 0, (void *)152, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter}
};

// data-ok: retail's bytes at 0X2B17B8
struct {
    char m0[4];
    void *m1[9];
} D_002B17B8 = {
    "\012",
    {(void *)0x2092, (void *)160, 0, (void *)160, 0, (void *)160, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter}
};

// data-ok: retail's bytes at 0X2B17E0
struct {
    char m0[4];
    void *m1[9];
} D_002B17E0 = {
    "\011",
    {(void *)0x2092, (void *)176, 0, (void *)176, 0, (void *)176, 0, (void *)0xffff0000, (void *)PemitbEnsureEmitter}
};

// data-ok: retail's bytes at 0X2B1808
void *D_002B1808[10] = {(void *)0x101c, (void *)0x104, (void *)0xffff0000, (void *)GetEmitterRipt, 0, 0, (void *)0xffff0000, (void *)SetEmitterRipt, 0, 0};

// data-ok: retail's bytes at 0X2B1830
void *D_002B1830[10] = {(void *)0x101d, (void *)0x2082, (void *)4, 0, 0, 0, (void *)4, 0, (void *)0xffff0000, (void *)PemitripEnsureEmitter};

// data-ok: retail's bytes at 0X2B1858
void *D_002B1858[10] = {(void *)6, (void *)0x2082, (void *)8, 0, 0, 0, (void *)8, 0, (void *)0xffff0000, (void *)PemitripEnsureEmitter};

// data-ok: retail's bytes at 0X2B1880
void *D_002B1880[10] = {(void *)6, (void *)0x2082, (void *)12, 0, 0, 0, (void *)12, 0, (void *)0xffff0000, (void *)PemitripEnsureEmitter};

// data-ok: retail's bytes at 0X2B18A8
void *D_002B18A8[10] = {(void *)6, (void *)0x2082, (void *)16, 0, 0, 0, (void *)16, 0, (void *)0xffff0000, (void *)PemitripEnsureEmitter};

// data-ok: retail's bytes at 0X2B18D0
void *D_002B18D0[10] = {(void *)1, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)PemitripEnsureEmitter};

// data-ok: retail's bytes at 0X2B18F8
struct {
    char m0[4];
    void *m1[9];
} D_002B18F8 = {
    "\012",
    {(void *)0x2092, (void *)24, 0, (void *)24, 0, (void *)24, 0, (void *)0xffff0000, (void *)PemitripEnsureEmitter}
};

// data-ok: retail's bytes at 0X2B1920
struct {
    char m0[4];
    void *m1[9];
} D_002B1920 = {
    "\011",
    {(void *)0x2092, (void *)32, 0, (void *)32, 0, (void *)32, 0, (void *)0xffff0000, (void *)PemitripEnsureEmitter}
};

// data-ok: retail's bytes at 0X2B1948
void *D_002B1948[10] = {(void *)6, (void *)0x2082, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00258C60};

// data-ok: retail's bytes at 0X2B1970
void *D_002B1970[10] = {(void *)1, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00258C60};

// data-ok: retail's bytes at 0X2B1998
void *D_002B1998[10] = {0, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00258CC8};

// data-ok: retail's bytes at 0X2B19C0
void *D_002B19C0[10] = {(void *)1, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00258D30};

// data-ok: retail's bytes at 0X2B19E8
void *D_002B19E8[10] = {(void *)1, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00258D30};

// data-ok: retail's bytes at 0X2B1A10
void *D_002B1A10[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00258D30};

// data-ok: retail's bytes at 0X2B1A38
void *D_002B1A38[10] = {(void *)0x101f, (void *)0x124, (void *)0xffff0000, (void *)GetEmitterBlipmk, (void *)0xffff0000, (void *)SetEmitterBlipmk, (void *)0xffff0000, (void *)SetEmitterBlipmk, 0, 0};

// data-ok: retail's bytes at 0X2B1A60
void *D_002B1A60[10] = {(void *)0x101e, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)PemitblipEnsureEmitter};

// data-ok: retail's bytes at 0X2B1A88
void *D_002B1A88[10] = {0, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)PemitblipEnsureEmitter};

// data-ok: retail's bytes at 0X2B1AB0
void *D_002B1AB0[10] = {(void *)6, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)PemitblipEnsureEmitter};

// data-ok: retail's bytes at 0X2B1AD8
void *D_002B1AD8[10] = {(void *)6, (void *)0x2082, (void *)20, 0, 0, 0, (void *)20, 0, (void *)0xffff0000, (void *)PemitblipEnsureEmitter};

// data-ok: retail's bytes at 0X2B1B00
void *D_002B1B00[10] = {(void *)1, (void *)0x2092, (void *)24, 0, (void *)24, 0, (void *)24, 0, (void *)0xffff0000, (void *)PemitblipEnsureEmitter};

// data-ok: retail's bytes at 0X2B1B28
struct {
    char m0[4];
    void *m1[9];
} D_002B1B28 = {
    "\011",
    {(void *)0x2092, (void *)32, 0, (void *)32, 0, (void *)32, 0, (void *)0xffff0000, (void *)PemitblipEnsureEmitter}
};

// data-ok: retail's bytes at 0X2B1B50
void *D_002B1B50[10] = {(void *)0x1020, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00258E60};

// data-ok: retail's bytes at 0X2B1B78
void *D_002B1B78[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00258E60};

// data-ok: retail's bytes at 0X2B1BA0
struct {
    char m0[4];
    void *m1[9];
} D_002B1BA0 = {
    "\012",
    {(void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00258E60}
};

// data-ok: retail's bytes at 0X2B1BC8
void *D_002B1BC8[10] = {(void *)1, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00258EC8};

// data-ok: retail's bytes at 0X2B1BF0
void *D_002B1BF0[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)func_00105B68, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1C18
void *D_002B1C18[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallExplodeOvr, 0, (void *)6, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1C40
void *D_002B1C40[10] = {(void *)0x1022, (void *)0x104, (void *)0xffff0000, (void *)func_00259550, 0, 0, (void *)0xffff0000, (void *)SetSuvSuvs, 0, 0};

// data-ok: retail's bytes at 0X2B1C68
void *D_002B1C68[10] = {(void *)2, (void *)0x2082, (void *)32, 0, 0, 0, (void *)32, 0, (void *)0xffff0000, (void *)func_00259560};

// data-ok: retail's bytes at 0X2B1C90
void *D_002B1C90[10] = {(void *)2, (void *)0x2082, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259598};

// data-ok: retail's bytes at 0X2B1CB8
void *D_002B1CB8[10] = {(void *)2, (void *)0x2082, (void *)16, 0, 0, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259598};

// data-ok: retail's bytes at 0X2B1CE0
void *D_002B1CE0[10] = {(void *)6, (void *)0x2082, (void *)32, 0, 0, 0, (void *)32, 0, (void *)0xffff0000, (void *)func_002595D0};

// data-ok: retail's bytes at 0X2B1D08
void *D_002B1D08[10] = {(void *)6, (void *)0x2082, (void *)32, 0, 0, 0, (void *)32, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B1D30
void *D_002B1D30[10] = {(void *)0x1023, (void *)0x2082, (void *)20, 0, 0, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B1D58
void *D_002B1D58[10] = {(void *)2, (void *)0x2092, (void *)64, 0, (void *)64, 0, (void *)64, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B1D80
void *D_002B1D80[10] = {(void *)2, (void *)0x2092, (void *)64, 0, (void *)64, 0, (void *)64, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B1DA8
void *D_002B1DA8[10] = {(void *)2, (void *)0x2092, (void *)64, 0, (void *)64, 0, (void *)64, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B1DD0
struct {
    char m0[4];
    void *m1[9];
} D_002B1DD0 = {
    "\012",
    {(void *)0x2092, (void *)36, 0, (void *)36, 0, (void *)36, 0, (void *)0xffff0000, (void *)func_002590F0}
};

// data-ok: retail's bytes at 0X2B1DF8
void *D_002B1DF8[10] = {(void *)0x1024, (void *)0x2092, (void *)24, 0, (void *)24, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B1E20
struct {
    char m0[4];
    void *m1[9];
} D_002B1E20 = {
    "\012",
    {(void *)0x2092, (void *)80, 0, (void *)80, 0, (void *)80, 0, (void *)0xffff0000, (void *)func_002590F0}
};

// data-ok: retail's bytes at 0X2B1E48
void *D_002B1E48[10] = {(void *)1, (void *)0x2092, (void *)92, 0, (void *)92, 0, (void *)92, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B1E70
struct {
    char m0[4];
    void *m1[9];
} D_002B1E70 = {
    "\012",
    {(void *)0x2092, (void *)144, 0, (void *)144, 0, (void *)144, 0, (void *)0xffff0000, (void *)func_002590F0}
};

// data-ok: retail's bytes at 0X2B1E98
void *D_002B1E98[10] = {(void *)5, (void *)0x2092, (void *)132, 0, (void *)132, 0, (void *)132, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B1EC0
void *D_002B1EC0[10] = {(void *)1, (void *)0x2092, (void *)136, 0, (void *)136, 0, (void *)136, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B1EE8
struct {
    char m0[4];
    void *m1[9];
} D_002B1EE8 = {
    "\012",
    {(void *)0x2092, (void *)152, 0, (void *)152, 0, (void *)152, 0, (void *)0xffff0000, (void *)func_002590F0}
};

// data-ok: retail's bytes at 0X2B1F10
void *D_002B1F10[10] = {(void *)0x101c, (void *)0x104, (void *)0xffff0000, (void *)func_002596D8, 0, 0, (void *)0xffff0000, (void *)func_00259608, 0, 0};

// data-ok: retail's bytes at 0X2B1F38
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B1F38 = {
    "\012",
    {146, 244, 0, 244, 0, 244, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B1F60
unsigned int D_002B1F60[10] = {0, 146, 252, 0, 252, 0, 252, 0, 0, 0};

// data-ok: retail's bytes at 0X2B1F88
void *D_002B1F88[10] = {(void *)0x1021, (void *)0x104, (void *)0xffff0000, (void *)func_00259488, 0, 0, (void *)0xffff0000, (void *)SetSuvSuvgk, 0, 0};

// data-ok: retail's bytes at 0X2B1FB0
void *D_002B1FB0[10] = {(void *)2, (void *)0x2092, (void *)96, 0, (void *)96, 0, (void *)96, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B1FD8
void *D_002B1FD8[10] = {(void *)1, (void *)0x2092, (void *)88, 0, (void *)88, 0, (void *)88, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B2000
void *D_002B2000[10] = {(void *)1, (void *)0x2092, (void *)128, 0, (void *)128, 0, (void *)128, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B2028
void *D_002B2028[10] = {(void *)2, (void *)0x2092, (void *)112, 0, (void *)112, 0, (void *)112, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B2050
void *D_002B2050[10] = {(void *)1, (void *)0x2092, (void *)140, 0, (void *)140, 0, (void *)140, 0, (void *)0xffff0000, (void *)func_002590F0};

// data-ok: retail's bytes at 0X2B2078
struct {
    char m0[4];
    void *m1[9];
} D_002B2078 = {
    "\012",
    {(void *)0x2092, (void *)160, 0, (void *)160, 0, (void *)160, 0, (void *)0xffff0000, (void *)func_002590F0}
};

// data-ok: retail's bytes at 0X2B20A0
struct {
    char m0[4];
    void *m1[9];
} D_002B20A0 = {
    "\011",
    {(void *)0x2092, (void *)176, 0, (void *)176, 0, (void *)176, 0, (void *)0xffff0000, (void *)func_002590F0}
};

// data-ok: retail's bytes at 0X2B20C8
void *D_002B20C8[10] = {(void *)0x101d, (void *)0x2082, (void *)4, 0, 0, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_002593B8};

// data-ok: retail's bytes at 0X2B20F0
void *D_002B20F0[10] = {(void *)6, (void *)0x2082, (void *)8, 0, 0, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_002593B8};

// data-ok: retail's bytes at 0X2B2118
void *D_002B2118[10] = {(void *)6, (void *)0x2082, (void *)12, 0, 0, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_002593B8};

// data-ok: retail's bytes at 0X2B2140
void *D_002B2140[10] = {(void *)6, (void *)0x2082, (void *)16, 0, 0, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_002593B8};

// data-ok: retail's bytes at 0X2B2168
void *D_002B2168[10] = {(void *)1, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_002593B8};

// data-ok: retail's bytes at 0X2B2190
struct {
    char m0[4];
    void *m1[9];
} D_002B2190 = {
    "\012",
    {(void *)0x2092, (void *)24, 0, (void *)24, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_002593B8}
};

// data-ok: retail's bytes at 0X2B21B8
struct {
    char m0[4];
    void *m1[9];
} D_002B21B8 = {
    "\011",
    {(void *)0x2092, (void *)32, 0, (void *)32, 0, (void *)32, 0, (void *)0xffff0000, (void *)func_002593B8}
};

// data-ok: retail's bytes at 0X2B21E0
void *D_002B21E0[10] = {(void *)6, (void *)0x2082, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_002596F8};

// data-ok: retail's bytes at 0X2B2208
void *D_002B2208[10] = {(void *)1, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_002596F8};

// data-ok: retail's bytes at 0X2B2230
void *D_002B2230[10] = {0, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259760};

// data-ok: retail's bytes at 0X2B2258
void *D_002B2258[10] = {(void *)1, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_002597C8};

// data-ok: retail's bytes at 0X2B2280
void *D_002B2280[10] = {(void *)1, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_002597C8};

// data-ok: retail's bytes at 0X2B22A8
void *D_002B22A8[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_002597C8};

// data-ok: retail's bytes at 0X2B22D0
void *D_002B22D0[10] = {(void *)0x101f, (void *)0x124, (void *)0xffff0000, (void *)func_002598D8, (void *)0xffff0000, (void *)func_00259830, (void *)0xffff0000, (void *)func_00259830, 0, 0};

// data-ok: retail's bytes at 0X2B22F8
void *D_002B22F8[10] = {(void *)0x101e, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00259330};

// data-ok: retail's bytes at 0X2B2320
void *D_002B2320[10] = {0, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00259330};

// data-ok: retail's bytes at 0X2B2348
void *D_002B2348[10] = {(void *)6, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259330};

// data-ok: retail's bytes at 0X2B2370
void *D_002B2370[10] = {(void *)6, (void *)0x2082, (void *)20, 0, 0, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_00259330};

// data-ok: retail's bytes at 0X2B2398
void *D_002B2398[10] = {(void *)1, (void *)0x2092, (void *)24, 0, (void *)24, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_00259330};

// data-ok: retail's bytes at 0X2B23C0
struct {
    char m0[4];
    void *m1[9];
} D_002B23C0 = {
    "\011",
    {(void *)0x2092, (void *)32, 0, (void *)32, 0, (void *)32, 0, (void *)0xffff0000, (void *)func_00259330}
};

// data-ok: retail's bytes at 0X2B23E8
void *D_002B23E8[10] = {(void *)0x1020, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_002598F8};

// data-ok: retail's bytes at 0X2B2410
void *D_002B2410[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_002598F8};

// data-ok: retail's bytes at 0X2B2438
struct {
    char m0[4];
    void *m1[9];
} D_002B2438 = {
    "\012",
    {(void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_002598F8}
};

// data-ok: retail's bytes at 0X2B2460
void *D_002B2460[10] = {(void *)1, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259960};

// data-ok: retail's bytes at 0X2B2488
void *D_002B2488[10] = {(void *)14, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)PsfxEnsureExpls};

// data-ok: retail's bytes at 0X2B24B0
void *D_002B24B0[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)PsfxEnsureExpls};

// data-ok: retail's bytes at 0X2B24D8
void *D_002B24D8[10] = {(void *)1, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)PsfxEnsureExpls};

// data-ok: retail's bytes at 0X2B2500
void *D_002B2500[10] = {(void *)1, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)PsfxEnsureExpls};

// data-ok: retail's bytes at 0X2B2528
void *D_002B2528[10] = {(void *)1, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)PsfxEnsureExpls};

// data-ok: retail's bytes at 0X2B2550
void *D_002B2550[10] = {(void *)18, (void *)1, 0, 0, (void *)func_00105CD0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2578
void *D_002B2578[10] = {(void *)18, (void *)0x401, (void *)bevy_classes_c2cf880_105d58, 0, (void *)bevy_classes_c2cf880_105d58, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B25A0
void *D_002B25A0[10] = {(void *)18, (void *)0x401, (void *)func_00105DE0, 0, (void *)func_00105DE0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B25C8
void *D_002B25C8[10] = {(void *)18, (void *)0x401, (void *)func_00105E70, 0, (void *)func_00105E70, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B25F0
void *D_002B25F0[10] = {(void *)18, (void *)0x401, (void *)func_00105F00, 0, (void *)func_00105F00, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2618
void *D_002B2618[10] = {(void *)18, (void *)0x401, (void *)func_00105F88, 0, (void *)func_00105F88, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2640
void *D_002B2640[10] = {(void *)18, (void *)0x401, (void *)func_00106010, 0, (void *)func_00106010, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2668
void *D_002B2668[10] = {(void *)18, (void *)0x401, (void *)func_00106098, 0, (void *)func_00106098, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2690
void *D_002B2690[10] = {(void *)18, (void *)0x401, (void *)RefCallAddScriptGoto, 0, (void *)RefCallAddScriptGoto, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B26B8
void *D_002B26B8[10] = {(void *)18, (void *)0x401, (void *)RefCallAddScriptAseg, 0, (void *)RefCallAddScriptAseg, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B26E0
void *D_002B26E0[10] = {(void *)18, (void *)0x401, (void *)RefCallAddScriptLabel, 0, (void *)RefCallAddScriptLabel, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2708
void *D_002B2708[10] = {(void *)18, (void *)0x401, (void *)RefCallAddScriptJump, 0, (void *)RefCallAddScriptJump, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2730
void *D_002B2730[10] = {(void *)18, (void *)0x401, (void *)func_001063A0, 0, (void *)func_001063A0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2758
void *D_002B2758[10] = {(void *)18, (void *)0x401, (void *)func_00106448, 0, (void *)func_00106448, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2780
void *D_002B2780[10] = {(void *)18, (void *)0x401, (void *)func_001064C0, 0, (void *)func_001064C0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B27A8
unsigned int D_002B27A8[10] = {18, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B27D0
unsigned int D_002B27D0[10] = {18, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B27F8
void *D_002B27F8[10] = {(void *)18, (void *)0x401, (void *)func_00106538, 0, (void *)func_00106538, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2820
void *D_002B2820[10] = {(void *)18, (void *)0x401, (void *)func_001065E0, 0, (void *)func_001065E0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2848
void *D_002B2848[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStartJsg, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2870
void *D_002B2870[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)RefCallStartJsgFocus, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2898
void *D_002B2898[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStopJsg, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B28C0
void *D_002B28C0[10] = {0, (void *)4, (void *)0xffff0000, (void *)FIsJsgActive, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B28E8
void *D_002B28E8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallAddSeqSignal, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2910
void *D_002B2910[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallClearSeqSignal, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2938
void *D_002B2938[10] = {0, (void *)1, 0, 0, (void *)RefCallFSeqSignal, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2960
unsigned int D_002B2960[10] = {0x2002, 2, 108, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2988
void *D_002B2988[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallClearSignals, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B29B0
void *D_002B29B0[10] = {(void *)5, (void *)0x102, (void *)88, 0, 0, 0, (void *)0xffff0000, (void *)func_001E01C8, 0, 0};

// data-ok: retail's bytes at 0X2B29D8
void *D_002B29D8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallClearJsg, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2A00
void *D_002B2A00[10] = {(void *)0x2002, (void *)36, (void *)0xffff0000, (void *)func_001E0128, (void *)0xffff0000, (void *)func_001E0158, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2A28
void *D_002B2A28[10] = {(void *)18, (void *)0x401, (void *)RefCallAddJsgContext, 0, (void *)RefCallAddJsgContext, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2A50
void *D_002B2A50[10] = {(void *)18, (void *)0x401, (void *)RefCallEndThread, 0, (void *)RefCallEndThread, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2A78
void *D_002B2A78[10] = {(void *)18, (void *)0x401, (void *)RefCallDestroyThread, 0, (void *)RefCallDestroyThread, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2AA0
void *D_002B2AA0[10] = {(void *)18, (void *)0x401, (void *)RefCallSync, 0, (void *)RefCallSync, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2AC8
void *D_002B2AC8[10] = {(void *)18, (void *)0x401, (void *)RefCallWait, 0, (void *)RefCallWait, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2AF0
void *D_002B2AF0[10] = {(void *)18, (void *)0x401, (void *)RefCallSignalSequence, 0, (void *)RefCallSignalSequence, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2B18
void *D_002B2B18[10] = {(void *)18, (void *)0x401, (void *)RefCallUntriggerSequence, 0, (void *)RefCallUntriggerSequence, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2B40
void *D_002B2B40[10] = {(void *)18, (void *)0x401, (void *)RefCallSetPlayer, 0, (void *)RefCallSetPlayer, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2B68
void *D_002B2B68[10] = {(void *)18, (void *)0x401, (void *)RefCallSetActor, 0, (void *)RefCallSetActor, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2B90
void *D_002B2B90[10] = {(void *)18, (void *)0x401, (void *)RefCallCallSplice, 0, (void *)RefCallCallSplice, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2BB8
void *D_002B2BB8[10] = {(void *)18, (void *)0x401, (void *)RefCallCallAnimation, 0, (void *)RefCallCallAnimation, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2BE0
void *D_002B2BE0[10] = {(void *)18, (void *)0x401, (void *)RefCallCallSequence, 0, (void *)RefCallCallSequence, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2C08
void *D_002B2C08[10] = {(void *)18, (void *)0x401, (void *)RefCallSetContext, 0, (void *)RefCallSetContext, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2C30
void *D_002B2C30[10] = {(void *)18, (void *)0x401, (void *)RefCallSetSmGoal, 0, (void *)RefCallSetSmGoal, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2C58
void *D_002B2C58[10] = {(void *)18, (void *)0x401, (void *)RefCallShowSwf, 0, (void *)RefCallShowSwf, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2C80
void *D_002B2C80[10] = {(void *)18, (void *)0x401, (void *)RefCallHideSwf, 0, (void *)RefCallHideSwf, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2CA8
void *D_002B2CA8[10] = {(void *)18, (void *)0x401, (void *)RefCallSetClockSpeed, 0, (void *)RefCallSetClockSpeed, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2CD0
void *D_002B2CD0[10] = {(void *)18, (void *)0x401, (void *)RefCallAddTaskRequest, 0, (void *)RefCallAddTaskRequest, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2CF8
void *D_002B2CF8[10] = {(void *)18, (void *)0x401, (void *)RefCallHandsOff, 0, (void *)RefCallHandsOff, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2D20
void *D_002B2D20[10] = {(void *)18, (void *)0x401, (void *)RefCallLabel, 0, (void *)RefCallLabel, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2D48
void *D_002B2D48[10] = {(void *)18, (void *)0x401, (void *)RefCallSeek, 0, (void *)RefCallSeek, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2D70
void *D_002B2D70[10] = {(void *)18, (void *)0x401, (void *)func_00107728, 0, (void *)func_00107728, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2D98
void *D_002B2D98[10] = {(void *)18, (void *)0x401, (void *)RefCallCut, 0, (void *)RefCallCut, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2DC0
void *D_002B2DC0[10] = {(void *)18, (void *)0x401, (void *)RefCallCutCamera, 0, (void *)RefCallCutCamera, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2DE8
void *D_002B2DE8[10] = {(void *)18, (void *)0x401, (void *)RefCallSetTunnel, 0, (void *)RefCallSetTunnel, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2E10
void *D_002B2E10[10] = {(void *)18, (void *)0x401, (void *)RefCallSetFocus, 0, (void *)RefCallSetFocus, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2E38
void *D_002B2E38[10] = {(void *)18, (void *)0x401, (void *)RefCallClimb, 0, (void *)RefCallClimb, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2E60
void *D_002B2E60[10] = {(void *)18, (void *)0x401, (void *)RefCallUnhide, 0, (void *)RefCallUnhide, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2E88
void *D_002B2E88[10] = {(void *)18, (void *)0x401, (void *)RefCallDamage, 0, (void *)RefCallDamage, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2EB0
void *D_002B2EB0[10] = {(void *)18, (void *)0x401, (void *)RefCallReach, 0, (void *)RefCallReach, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2ED8
void *D_002B2ED8[10] = {(void *)18, (void *)0x401, (void *)RefCallToss, 0, (void *)RefCallToss, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2F00
void *D_002B2F00[10] = {(void *)18, (void *)0x401, (void *)RefAddJsgEvent1F, 0, (void *)RefAddJsgEvent1F, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2F28
void *D_002B2F28[10] = {(void *)18, (void *)0x401, (void *)RefAddJsgEvent20, 0, (void *)RefAddJsgEvent20, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2F50
void *D_002B2F50[10] = {(void *)18, (void *)0x401, (void *)RefAddJsgEvent21, 0, (void *)RefAddJsgEvent21, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2F78
void *D_002B2F78[10] = {(void *)18, (void *)0x401, (void *)RefCallCatch, 0, (void *)RefCallCatch, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2FA0
void *D_002B2FA0[10] = {(void *)18, (void *)0x401, (void *)RefCallPause, 0, (void *)RefCallPause, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2FC8
void *D_002B2FC8[10] = {(void *)18, (void *)0x401, (void *)RefAddJsgEvent24_Flag, 0, (void *)RefAddJsgEvent24_Flag, 0, (void *)6, 0, 0, 0};

// data-ok: retail's bytes at 0X2B2FF0
void *D_002B2FF0[10] = {(void *)18, (void *)0x401, (void *)RefAddJsgEvent24_NoFlag, 0, (void *)RefAddJsgEvent24_NoFlag, 0, (void *)6, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3018
void *D_002B3018[10] = {(void *)18, (void *)0x401, (void *)RefAddJsgEvent25, 0, (void *)RefAddJsgEvent25, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3040
void *D_002B3040[10] = {(void *)18, (void *)0x401, (void *)RefAddJsgEvent26, 0, (void *)RefAddJsgEvent26, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3068
void *D_002B3068[10] = {(void *)18, (void *)0x401, (void *)RefAddJsgEvent27, 0, (void *)RefAddJsgEvent27, 0, (void *)6, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3090
void *D_002B3090[10] = {(void *)18, (void *)0x401, (void *)RefAddJsgEvent28, 0, (void *)RefAddJsgEvent28, 0, (void *)6, 0, 0, 0};

// data-ok: retail's bytes at 0X2B30B8
void *D_002B30B8[10] = {(void *)18, (void *)0x401, (void *)RefCallCrawl, 0, (void *)RefCallCrawl, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2B30E0
void *D_002B30E0[10] = {(void *)18, (void *)0x401, (void *)RefCallJump, 0, (void *)RefCallJump, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3108
void *D_002B3108[10] = {(void *)18, (void *)0x401, (void *)RefAddJsgEvent2B, 0, (void *)RefAddJsgEvent2B, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3130
void *D_002B3130[10] = {(void *)18, (void *)0x401, (void *)RefCallAddObject, 0, (void *)RefCallAddObject, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3158
void *D_002B3158[10] = {(void *)18, (void *)0x401, (void *)RefCallRemoveObject, 0, (void *)RefCallRemoveObject, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3180
void *D_002B3180[10] = {(void *)18, (void *)0x401, (void *)RefCallAddGeom, 0, (void *)RefCallAddGeom, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B31A8
void *D_002B31A8[10] = {(void *)18, (void *)0x401, (void *)RefCallRemoveGeom, 0, (void *)RefCallRemoveGeom, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B31D0
void *D_002B31D0[10] = {(void *)18, (void *)0x401, (void *)RefCallAddPhys, 0, (void *)RefCallAddPhys, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B31F8
void *D_002B31F8[10] = {(void *)18, (void *)0x401, (void *)RefCallRemovePhys, 0, (void *)RefCallRemovePhys, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3220
void *D_002B3220[10] = {(void *)18, (void *)0x401, (void *)RefCallJolt, 0, (void *)RefCallJolt, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3248
void *D_002B3248[10] = {(void *)18, (void *)0x401, (void *)RefCallRumble, 0, (void *)RefCallRumble, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3270
void *D_002B3270[10] = {(void *)18, (void *)0x401, (void *)RefCallExplode, 0, (void *)RefCallExplode, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3298
void *D_002B3298[10] = {(void *)18, (void *)0x401, (void *)RefCallSetEyes, 0, (void *)RefCallSetEyes, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B32C0
void *D_002B32C0[10] = {(void *)18, (void *)0x401, (void *)RefCallSoundEffect, 0, (void *)RefCallSoundEffect, 0, (void *)7, 0, 0, 0};

// data-ok: retail's bytes at 0X2B32E8
void *D_002B32E8[10] = {(void *)18, (void *)0x401, (void *)RefCallStopSoundEffect, 0, (void *)RefCallStopSoundEffect, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3310
void *D_002B3310[10] = {(void *)18, (void *)0x401, (void *)RefCallConfrontCamera, 0, (void *)RefCallConfrontCamera, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3338
void *D_002B3338[10] = {(void *)18, (void *)0x401, (void *)RefCallEndConfrontCamera, 0, (void *)RefCallEndConfrontCamera, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3360
void *D_002B3360[10] = {(void *)18, (void *)0x401, (void *)RefCallRevokeConfrontCamera, 0, (void *)RefCallRevokeConfrontCamera, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3388
void *D_002B3388[10] = {(void *)18, (void *)0x401, (void *)RefCallShowBinoc, 0, (void *)RefCallShowBinoc, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B33B0
void *D_002B33B0[10] = {(void *)18, (void *)0x401, (void *)RefCallHideBinoc, 0, (void *)RefCallHideBinoc, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B33D8
void *D_002B33D8[10] = {(void *)18, (void *)0x401, (void *)RefCallBinocAnchor, 0, (void *)RefCallBinocAnchor, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3400
void *D_002B3400[10] = {(void *)18, (void *)0x401, (void *)RefCallBinocFocus, 0, (void *)RefCallBinocFocus, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3428
void *D_002B3428[10] = {(void *)18, (void *)0x401, (void *)RefCallBinocPos, 0, (void *)RefCallBinocPos, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3450
void *D_002B3450[10] = {(void *)18, (void *)0x401, (void *)RefCallBinocZoom, 0, (void *)RefCallBinocZoom, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3478
void *D_002B3478[10] = {(void *)18, (void *)0x401, (void *)RefCallBinocCut, 0, (void *)RefCallBinocCut, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B34A0
void *D_002B34A0[10] = {(void *)18, (void *)0x401, (void *)RefCallWaitForButton, 0, (void *)RefCallWaitForButton, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B34C8
void *D_002B34C8[10] = {(void *)18, (void *)0x401, (void *)RefCallAddJsgKind43, 0, (void *)RefCallAddJsgKind43, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B34F0
void *D_002B34F0[10] = {(void *)18, (void *)0x401, (void *)RefCallAddJsgKind44, 0, (void *)RefCallAddJsgKind44, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3518
void *D_002B3518[10] = {(void *)18, (void *)0x401, (void *)RefCallVoice, 0, (void *)RefCallVoice, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3540
void *D_002B3540[10] = {(void *)18, (void *)0x401, (void *)RefCallAddJsgKind46, 0, (void *)RefCallAddJsgKind46, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3568
void *D_002B3568[10] = {(void *)18, (void *)0x401, (void *)RefCallGesture, 0, (void *)RefCallGesture, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3590
void *D_002B3590[10] = {(void *)18, (void *)0x401, (void *)RefCallEndGesture, 0, (void *)RefCallEndGesture, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B35B8
void *D_002B35B8[10] = {(void *)18, (void *)0x401, (void *)RefCallSetDanceState, 0, (void *)RefCallSetDanceState, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B35E0
void *D_002B35E0[10] = {(void *)18, (void *)0x401, (void *)RefCallDanceMove, 0, (void *)RefCallDanceMove, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3608
void *D_002B3608[10] = {(void *)18, (void *)0x401, (void *)RefCallDanceInterlude, 0, (void *)RefCallDanceInterlude, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3630
void *D_002B3630[10] = {(void *)18, (void *)0x401, (void *)RefCallApplyMusic, 0, (void *)RefCallApplyMusic, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3658
void *D_002B3658[10] = {(void *)18, (void *)0x401, (void *)RefCallRetractMusic, 0, (void *)RefCallRetractMusic, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3680
void *D_002B3680[10] = {(void *)18, (void *)0x401, (void *)RefCallWaitForMusic, 0, (void *)RefCallWaitForMusic, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B36A8
void *D_002B36A8[10] = {(void *)18, (void *)0x401, (void *)RefCallLift, 0, (void *)RefCallLift, 0, (void *)6, 0, 0, 0};

// data-ok: retail's bytes at 0X2B36D0
void *D_002B36D0[10] = {(void *)18, (void *)0x401, (void *)RefCallTakeOutBomb, 0, (void *)RefCallTakeOutBomb, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B36F8
void *D_002B36F8[10] = {(void *)18, (void *)0x401, (void *)RefCallDropBomb, 0, (void *)RefCallDropBomb, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3720
void *D_002B3720[10] = {(void *)18, (void *)0x401, (void *)RefCallWaitForVoice, 0, (void *)RefCallWaitForVoice, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3748
void *D_002B3748[10] = {(void *)18, (void *)0x401, (void *)RefCallShowBrief, 0, (void *)RefCallShowBrief, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3770
void *D_002B3770[10] = {(void *)18, (void *)0x401, (void *)RefCallHideBrief, 0, (void *)RefCallHideBrief, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3798
void *D_002B3798[10] = {(void *)18, (void *)0x401, (void *)RefCallPlayGuardScript, 0, (void *)RefCallPlayGuardScript, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B37C0
void *D_002B37C0[10] = {(void *)18, (void *)0x401, (void *)RefCallRetractGuardScript, 0, (void *)RefCallRetractGuardScript, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B37E8
void *D_002B37E8[10] = {(void *)18, (void *)0x401, (void *)RefCallAddSeqRecord57, 0, (void *)RefCallAddSeqRecord57, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3810
void *D_002B3810[10] = {(void *)18, (void *)0x401, (void *)RefCallAddSeqRecord58, 0, (void *)RefCallAddSeqRecord58, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3838
void *D_002B3838[10] = {(void *)18, (void *)0x401, (void *)RefCallAddSeqRecord59, 0, (void *)RefCallAddSeqRecord59, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3860
void *D_002B3860[10] = {(void *)18, (void *)0x401, (void *)RefCallAddSeqRecord5a, 0, (void *)RefCallAddSeqRecord5a, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3888
unsigned int D_002B3888[10] = {0x2002, 146, 0x420, 0, 0x420, 0, 0x420, 0, 0, 0};

// data-ok: retail's bytes at 0X2B38B0
unsigned int D_002B38B0[10] = {1, 146, 0x424, 0, 0x424, 0, 0x424, 0, 0, 0};

// data-ok: retail's bytes at 0X2B38D8
unsigned int D_002B38D8[10] = {1, 146, 0x103c, 0, 0x103c, 0, 0x103c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3900
unsigned int D_002B3900[10] = {2, 146, 0x3b0, 0, 0x3b0, 0, 0x3b0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3928
unsigned int D_002B3928[10] = {1, 146, 0x3c8, 0, 0x3c8, 0, 0x3c8, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3950
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B3950 = {
    "\012",
    {146, 0x3cc, 0, 0x3cc, 0, 0x3cc, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B3978
unsigned int D_002B3978[10] = {1, 146, 0x3d4, 0, 0x3d4, 0, 0x3d4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B39A0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B39A0 = {
    "\012",
    {146, 0x3d8, 0, 0x3d8, 0, 0x3d8, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B39C8
unsigned int D_002B39C8[10] = {0, 146, 0x10f0, 0, 0x10f0, 0, 0x10f0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B39F0
unsigned int D_002B39F0[10] = {5, 146, 0xdfc, 0, 0xdfc, 0, 0xdfc, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3A18
void *D_002B3A18[10] = {(void *)5, (void *)36, (void *)0xffff0000, (void *)func_00258280, (void *)0xffff0000, (void *)SetJtHealth, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3A40
unsigned int D_002B3A40[10] = {5, 146, 0x1300, 0, 0x1300, 0, 0x1300, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3A68
void *D_002B3A68[10] = {(void *)5, (void *)36, (void *)0xffff0000, (void *)GetJtPower, (void *)0xffff0000, (void *)SetJtPower, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3A90
void *D_002B3A90[10] = {(void *)18, (void *)1, 0, 0, (void *)func_0010A790, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3AB8
void *D_002B3AB8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetJtAttach5, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3AE0
void *D_002B3AE0[10] = {0, (void *)1, 0, 0, (void *)func_0010A8D0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3B08
void *D_002B3B08[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetJtScriptGoal, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3B30
void *D_002B3B30[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStartJtCarry, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3B58
void *D_002B3B58[10] = {0, (void *)1, 0, 0, (void *)func_0010AA90, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3B80
void *D_002B3B80[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetJtAttach9, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3BA8
void *D_002B3BA8[10] = {0, (void *)1, 0, 0, (void *)func_0010AB88, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3BD0
void *D_002B3BD0[10] = {(void *)18, (void *)1, 0, 0, (void *)func_0010ABF8, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3BF8
void *D_002B3BF8[10] = {(void *)18, (void *)1, 0, 0, (void *)func_0010AC80, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3C20
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B3C20 = {
    "0 ",
    {2, 0x9a0, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B3C48
void *D_002B3C48[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetJtAttachC_1424e0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3C70
void *D_002B3C70[10] = {0, (void *)1, 0, 0, (void *)func_0010ADB8, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3C98
void *D_002B3C98[10] = {(void *)18, (void *)1, 0, 0, (void *)RefSetJtLookLimits, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3CC0
void *D_002B3CC0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefSetJtLookTargetHeld, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3CE8
void *D_002B3CE8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefReleaseJtLookHold, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3D10
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B3D10 = {
    "\012",
    {146, 0x1138, 0, 0x1138, 0, 0x1138, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B3D38
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B3D38 = {
    "\012",
    {146, 0x1140, 0, 0x1140, 0, 0x1140, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B3D60
unsigned int D_002B3D60[10] = {0, 18, 0x1104, 0, 0x1104, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3D88
unsigned int D_002B3D88[10] = {2, 18, 0x1110, 0, 0x1110, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3DB0
void *D_002B3DB0[10] = {(void *)18, (void *)1, 0, 0, (void *)bevy_game_methods_cls_10b028, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3DD8
unsigned int D_002B3DD8[10] = {0x1057, 4, 0x5a0000, 12, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3E00
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B3E00 = {
    "g ",
    {2, 0x11a8, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B3E28
void *D_002B3E28[10] = {(void *)18, (void *)1, 0, 0, (void *)RefGiveJtLoot, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3E50
void *D_002B3E50[10] = {(void *)18, (void *)1, 0, 0, (void *)RefDropJtLoot, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3E78
void *D_002B3E78[10] = {(void *)18, (void *)1, 0, 0, (void *)RefDeliverJtLoot, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3EA0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B3EA0 = {
    "8 ",
    {2, 0x10dc, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B3EC8
unsigned int D_002B3EC8[10] = {0x1053, 2, 0x10e4, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3EF0
unsigned int D_002B3EF0[10] = {0, 146, 0x11ac, 0, 0x11ac, 0, 0x11ac, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3F18
void *D_002B3F18[10] = {0, (void *)4, (void *)0xffff0000, (void *)bevy_player_p4_144068, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3F40
void *D_002B3F40[10] = {(void *)18, (void *)0x401, (void *)func_0010B230, 0, (void *)func_0010B230, 0, (void *)7, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3F68
unsigned int D_002B3F68[10] = {0, 146, 0x12f0, 0, 0x12f0, 0, 0x12f0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3F90
void *D_002B3F90[10] = {0, (void *)4, (void *)0xffff0000, (void *)bevy_player_p15_binoc_active, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3FB8
void *D_002B3FB8[10] = {0, (void *)4, (void *)0xffff0000, (void *)func_001443E8, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B3FE0
void *D_002B3FE0[10] = {0, (void *)4, (void *)0xffff0000, (void *)func_001443F8, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4008
void *D_002B4008[10] = {0, (void *)4, (void *)0xffff0000, (void *)func_00144408, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4030
void *D_002B4030[10] = {(void *)18, (void *)0x401, (void *)RefSetJtPipeHandFoot, 0, (void *)RefSetJtPipeHandFoot, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4058
void *D_002B4058[10] = {(void *)18, (void *)1, 0, 0, (void *)RefEquipJtGadget, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4080
void *D_002B4080[10] = {(void *)5, (void *)1, 0, 0, (void *)RefIslotJtGadget, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B40A8
void *D_002B40A8[10] = {(void *)18, (void *)1, 0, 0, (void *)func_0010B510, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B40D0
void *D_002B40D0[10] = {(void *)18, (void *)1, 0, 0, (void *)func_0010B598, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B40F8
void *D_002B40F8[10] = {(void *)18, (void *)0x401, (void *)func_0010B618, 0, (void *)func_0010B618, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4120
void *D_002B4120[10] = {(void *)18, (void *)0x401, (void *)RefSetJtRideOffset, 0, (void *)RefSetJtRideOffset, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4148
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B4148 = {
    "0 ",
    {2, 0x1bcc, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B4170
unsigned int D_002B4170[10] = {0x105c, 146, 0x16d8, 0, 0x16d8, 0, 0x16d8, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4198
unsigned int D_002B4198[10] = {0, 146, 0x1818, 0, 0x1818, 0, 0x1818, 0, 0, 0};

// data-ok: retail's bytes at 0X2B41C0
unsigned int D_002B41C0[10] = {0, 146, 0x181c, 0, 0x181c, 0, 0x181c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B41E8
unsigned int D_002B41E8[10] = {0x1049, 146, 0x1870, 0, 0x1870, 0, 0x1870, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4210
void *D_002B4210[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)func_0010B760, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4238
unsigned int D_002B4238[10] = {6, 146, 0x150, 0, 0x150, 0, 0x150, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4260
unsigned int D_002B4260[10] = {6, 146, 0x154, 0, 0x154, 0, 0x154, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4288
unsigned int D_002B4288[10] = {1, 146, 0x15c, 0, 0x15c, 0, 0x15c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B42B0
unsigned int D_002B42B0[10] = {0, 146, 0x130, 0, 0x130, 0, 0x130, 0, 0, 0};

// data-ok: retail's bytes at 0X2B42D8
unsigned int D_002B42D8[10] = {0, 146, 0x134, 0, 0x134, 0, 0x134, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4300
unsigned int D_002B4300[10] = {0, 146, 0x138, 0, 0x138, 0, 0x138, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4328
unsigned int D_002B4328[10] = {1, 146, 0x160, 0, 0x160, 0, 0x160, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4350
void *D_002B4350[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)RefWarpStart, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4378
void *D_002B4378[10] = {(void *)0x1033, (void *)34, (void *)0x13c, 0, (void *)0xffff0000, (void *)Warp_SetState, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B43A0
void *D_002B43A0[10] = {(void *)18, (void *)0x400, (void *)func_0010B850, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B43C8
void *D_002B43C8[10] = {(void *)15, (void *)4, (void *)0xffff0000, (void *)func_00228518, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B43F0
void *D_002B43F0[10] = {(void *)18, (void *)0x400, (void *)func_0010B8F8, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4418
void *D_002B4418[10] = {(void *)18, (void *)0x400, (void *)func_0010B970, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4440
void *D_002B4440[10] = {(void *)18, (void *)0x400, (void *)func_0010B9E8, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4468
void *D_002B4468[10] = {(void *)18, (void *)0x400, (void *)func_0010BA70, 0, 0, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4490
void *D_002B4490[10] = {(void *)18, (void *)0x400, (void *)func_0010BB38, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B44B8
void *D_002B44B8[10] = {(void *)18, (void *)0x400, (void *)RefAddBrkTouchObject, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B44E0
unsigned int D_002B44E0[10] = {1, 146, 0x10c, 0, 0x10c, 0, 0x10c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4508
unsigned int D_002B4508[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4530
void *D_002B4530[10] = {(void *)0x200f, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259A08};

// data-ok: retail's bytes at 0X2B4558
void *D_002B4558[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00259A08};

// data-ok: retail's bytes at 0X2B4580
void *D_002B4580[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00259A08};

// data-ok: retail's bytes at 0X2B45A8
void *D_002B45A8[10] = {0, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_00259A08};

// data-ok: retail's bytes at 0X2B45D0
void *D_002B45D0[10] = {(void *)0x106a, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259A08};

// data-ok: retail's bytes at 0X2B45F8
void *D_002B45F8[10] = {(void *)16, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_00259A08};

// data-ok: retail's bytes at 0X2B4620
void *D_002B4620[10] = {(void *)0x2002, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_00259A08};

// data-ok: retail's bytes at 0X2B4648
void *D_002B4648[10] = {(void *)0x106c, (void *)0x2092, (void *)28, 0, (void *)28, 0, (void *)28, 0, (void *)0xffff0000, (void *)func_00259A08};

// data-ok: retail's bytes at 0X2B4670
unsigned int D_002B4670[10] = {0x1031, 146, 0x1bc, 0, 0x1bc, 0, 0x1bc, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4698
unsigned int D_002B4698[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B46C0
void *D_002B46C0[10] = {(void *)0x200f, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_002599F8};

// data-ok: retail's bytes at 0X2B46E8
void *D_002B46E8[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_002599F8};

// data-ok: retail's bytes at 0X2B4710
void *D_002B4710[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_002599F8};

// data-ok: retail's bytes at 0X2B4738
void *D_002B4738[10] = {0, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_002599F8};

// data-ok: retail's bytes at 0X2B4760
void *D_002B4760[10] = {(void *)0x106a, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_002599F8};

// data-ok: retail's bytes at 0X2B4788
void *D_002B4788[10] = {(void *)16, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_002599F8};

// data-ok: retail's bytes at 0X2B47B0
void *D_002B47B0[10] = {(void *)0x2002, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_002599F8};

// data-ok: retail's bytes at 0X2B47D8
void *D_002B47D8[10] = {(void *)0x106c, (void *)0x2092, (void *)28, 0, (void *)28, 0, (void *)28, 0, (void *)0xffff0000, (void *)func_002599F8};

// data-ok: retail's bytes at 0X2B4800
unsigned int D_002B4800[10] = {0x102c, 146, 0x10c, 0, 0x10c, 0, 0x10c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4828
unsigned int D_002B4828[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4850
void *D_002B4850[10] = {(void *)0x200f, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259A18};

// data-ok: retail's bytes at 0X2B4878
void *D_002B4878[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00259A18};

// data-ok: retail's bytes at 0X2B48A0
void *D_002B48A0[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00259A18};

// data-ok: retail's bytes at 0X2B48C8
void *D_002B48C8[10] = {0, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_00259A18};

// data-ok: retail's bytes at 0X2B48F0
void *D_002B48F0[10] = {(void *)0x106a, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259A18};

// data-ok: retail's bytes at 0X2B4918
void *D_002B4918[10] = {(void *)16, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_00259A18};

// data-ok: retail's bytes at 0X2B4940
void *D_002B4940[10] = {(void *)0x2002, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_00259A18};

// data-ok: retail's bytes at 0X2B4968
void *D_002B4968[10] = {(void *)0x106c, (void *)0x2092, (void *)28, 0, (void *)28, 0, (void *)28, 0, (void *)0xffff0000, (void *)func_00259A18};

// data-ok: retail's bytes at 0X2B4990
unsigned int D_002B4990[10] = {1, 146, 0x184, 0, 0x184, 0, 0x184, 0, 0, 0};

// data-ok: retail's bytes at 0X2B49B8
unsigned int D_002B49B8[10] = {5, 146, 0x188, 0, 0x188, 0, 0x188, 0, 0, 0};

// data-ok: retail's bytes at 0X2B49E0
unsigned int D_002B49E0[10] = {0, 146, 0x18c, 0, 0x18c, 0, 0x18c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4A08
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B4A08 = {
    "4 ",
    {2, 0x190, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B4A30
void *D_002B4A30[10] = {(void *)0x200f, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259A28};

// data-ok: retail's bytes at 0X2B4A58
void *D_002B4A58[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00259A28};

// data-ok: retail's bytes at 0X2B4A80
void *D_002B4A80[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00259A28};

// data-ok: retail's bytes at 0X2B4AA8
void *D_002B4AA8[10] = {0, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_00259A28};

// data-ok: retail's bytes at 0X2B4AD0
void *D_002B4AD0[10] = {(void *)0x106a, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259A28};

// data-ok: retail's bytes at 0X2B4AF8
void *D_002B4AF8[10] = {(void *)16, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_00259A28};

// data-ok: retail's bytes at 0X2B4B20
void *D_002B4B20[10] = {(void *)0x2002, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_00259A28};

// data-ok: retail's bytes at 0X2B4B48
void *D_002B4B48[10] = {(void *)0x106c, (void *)0x2092, (void *)28, 0, (void *)28, 0, (void *)28, 0, (void *)0xffff0000, (void *)func_00259A28};

// data-ok: retail's bytes at 0X2B4B70
unsigned int D_002B4B70[10] = {2, 146, 0x1c0, 0, 0x1c0, 0, 0x1c0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4B98
unsigned int D_002B4B98[10] = {14, 146, 0x1d0, 0, 0x1d0, 0, 0x1d0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4BC0
unsigned int D_002B4BC0[10] = {14, 146, 0x1d4, 0, 0x1d4, 0, 0x1d4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4BE8
void *D_002B4BE8[10] = {0, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_001C3C08, (void *)0xffff0000, (void *)func_001C3C08, 0, 0};

// data-ok: retail's bytes at 0X2B4C10
void *D_002B4C10[10] = {(void *)0x200f, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259B00};

// data-ok: retail's bytes at 0X2B4C38
void *D_002B4C38[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00259B00};

// data-ok: retail's bytes at 0X2B4C60
void *D_002B4C60[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00259B00};

// data-ok: retail's bytes at 0X2B4C88
void *D_002B4C88[10] = {0, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_00259B00};

// data-ok: retail's bytes at 0X2B4CB0
void *D_002B4CB0[10] = {(void *)0x106a, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259B00};

// data-ok: retail's bytes at 0X2B4CD8
void *D_002B4CD8[10] = {(void *)16, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_00259B00};

// data-ok: retail's bytes at 0X2B4D00
void *D_002B4D00[10] = {(void *)0x2002, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_00259B00};

// data-ok: retail's bytes at 0X2B4D28
void *D_002B4D28[10] = {(void *)0x106c, (void *)0x2092, (void *)28, 0, (void *)28, 0, (void *)28, 0, (void *)0xffff0000, (void *)func_00259B00};

// data-ok: retail's bytes at 0X2B4D50
void *D_002B4D50[10] = {(void *)0x200f, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259C10};

// data-ok: retail's bytes at 0X2B4D78
void *D_002B4D78[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00259C10};

// data-ok: retail's bytes at 0X2B4DA0
void *D_002B4DA0[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00259C10};

// data-ok: retail's bytes at 0X2B4DC8
void *D_002B4DC8[10] = {0, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_00259C10};

// data-ok: retail's bytes at 0X2B4DF0
void *D_002B4DF0[10] = {(void *)0x106a, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259C10};

// data-ok: retail's bytes at 0X2B4E18
void *D_002B4E18[10] = {(void *)16, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_00259C10};

// data-ok: retail's bytes at 0X2B4E40
void *D_002B4E40[10] = {(void *)0x2002, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_00259C10};

// data-ok: retail's bytes at 0X2B4E68
void *D_002B4E68[10] = {(void *)0x106c, (void *)0x2092, (void *)28, 0, (void *)28, 0, (void *)28, 0, (void *)0xffff0000, (void *)func_00259C10};

// data-ok: retail's bytes at 0X2B4E90
unsigned int D_002B4E90[10] = {0, 146, 0x1bc, 0, 0x1bc, 0, 0x1bc, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4EB8
unsigned int D_002B4EB8[10] = {1, 146, 0x1c0, 0, 0x1c0, 0, 0x1c0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4EE0
unsigned int D_002B4EE0[10] = {1, 146, 0x1c4, 0, 0x1c4, 0, 0x1c4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4F08
unsigned int D_002B4F08[10] = {6, 146, 0x1c8, 0, 0x1c8, 0, 0x1c8, 0, 0, 0};

// data-ok: retail's bytes at 0X2B4F30
void *D_002B4F30[10] = {(void *)0x200f, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259B10};

// data-ok: retail's bytes at 0X2B4F58
void *D_002B4F58[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00259B10};

// data-ok: retail's bytes at 0X2B4F80
void *D_002B4F80[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00259B10};

// data-ok: retail's bytes at 0X2B4FA8
void *D_002B4FA8[10] = {0, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_00259B10};

// data-ok: retail's bytes at 0X2B4FD0
void *D_002B4FD0[10] = {(void *)0x106a, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259B10};

// data-ok: retail's bytes at 0X2B4FF8
void *D_002B4FF8[10] = {(void *)16, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_00259B10};

// data-ok: retail's bytes at 0X2B5020
void *D_002B5020[10] = {(void *)0x2002, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_00259B10};

// data-ok: retail's bytes at 0X2B5048
void *D_002B5048[10] = {(void *)0x106c, (void *)0x2092, (void *)28, 0, (void *)28, 0, (void *)28, 0, (void *)0xffff0000, (void *)func_00259B10};

// data-ok: retail's bytes at 0X2B5070
unsigned int D_002B5070[10] = {1, 146, 232, 0, 232, 0, 232, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5098
unsigned int D_002B5098[10] = {1, 146, 0x108, 0, 0x108, 0, 0x108, 0, 0, 0};

// data-ok: retail's bytes at 0X2B50C0
unsigned int D_002B50C0[10] = {0, 146, 0x10c, 0, 0x10c, 0, 0x10c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B50E8
unsigned int D_002B50E8[10] = {0x200f, 146, 0x110, 0, 0x110, 0, 0x110, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5110
unsigned int D_002B5110[10] = {0x201e, 146, 0x170, 0, 0x170, 0, 0x170, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5138
unsigned int D_002B5138[10] = {0x201e, 146, 0x174, 0, 0x174, 0, 0x174, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5160
unsigned int D_002B5160[10] = {5, 146, 0x184, 0, 0x184, 0, 0x184, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5188
unsigned int D_002B5188[10] = {0x1011, 146, 0x188, 0, 0x188, 0, 0x188, 0, 0, 0};

// data-ok: retail's bytes at 0X2B51B0
unsigned int D_002B51B0[10] = {2, 146, 0x160, 0, 0x160, 0, 0x160, 0, 0, 0};

// data-ok: retail's bytes at 0X2B51D8
unsigned int D_002B51D8[10] = {0, 146, 0x180, 0, 0x180, 0, 0x180, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5200
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B5200 = {
    "0 ",
    {146, 0x178, 0, 0x178, 0, 0x178, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B5228
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B5228 = {
    "0 ",
    {146, 0x17c, 0, 0x17c, 0, 0x17c, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B5250
void *D_002B5250[10] = {0, (void *)1, 0, 0, (void *)func_0010BC88, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5278
unsigned int D_002B5278[10] = {0x102d, 4, 0x4e0000, 12, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B52A0
void *D_002B52A0[10] = {(void *)0x1037, (void *)36, (void *)0xffff0000, (void *)GetPoVjoyMode, (void *)0x500000, (void *)12, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B52C8
void *D_002B52C8[10] = {0, (void *)4, (void *)0xffff0000, (void *)func_001C4098, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B52F0
void *D_002B52F0[10] = {0, (void *)4, (void *)0xffff0000, (void *)FIsPoSwFocusBase, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5318
void *D_002B5318[10] = {0, (void *)4, (void *)0xffff0000, (void *)FIsPoSwFocus, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5340
unsigned int D_002B5340[10] = {0x2089, 2, 0x150, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5368
unsigned int D_002B5368[10] = {0x103c, 146, 0x154, 0, 0x154, 0, 0x154, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5390
void *D_002B5390[10] = {(void *)0x200f, (void *)0x122, (void *)0x16c, 0, (void *)0xffff0000, (void *)func_001C4130, (void *)0xffff0000, (void *)func_001C4130, 0, 0};

// data-ok: retail's bytes at 0X2B53B8
unsigned int D_002B53B8[10] = {6, 130, 0x204, 0, 0, 0, 0x204, 0, 0, 0};

// data-ok: retail's bytes at 0X2B53E0
unsigned int D_002B53E0[10] = {6, 130, 0x20c, 0, 0, 0, 0x20c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5408
unsigned int D_002B5408[10] = {6, 130, 0x214, 0, 0, 0, 0x214, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5430
void *D_002B5430[10] = {(void *)18, (void *)0x400, (void *)func_0010BD10, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5458
unsigned int D_002B5458[10] = {6, 146, 0x15c, 0, 0x15c, 0, 0x15c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5480
unsigned int D_002B5480[10] = {1, 146, 0x160, 0, 0x160, 0, 0x160, 0, 0, 0};

// data-ok: retail's bytes at 0X2B54A8
unsigned int D_002B54A8[10] = {0x1034, 34, 0x150, 0, 0x4d0000, 12, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B54D0
unsigned int D_002B54D0[10] = {0x1034, 146, 0x158, 0, 0x158, 0, 0x158, 0, 0, 0};

// data-ok: retail's bytes at 0X2B54F8
unsigned int D_002B54F8[10] = {1, 146, 0x21c, 0, 0x21c, 0, 0x21c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5520
unsigned int D_002B5520[10] = {0, 146, 0x1c8, 0, 0x1c8, 0, 0x1c8, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5548
unsigned int D_002B5548[10] = {16, 146, 0x224, 0, 0x224, 0, 0x224, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5570
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B5570 = {
    "\012",
    {146, 0x230, 0, 0x230, 0, 0x230, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B5598
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B5598 = {
    "\012",
    {146, 0x230, 0, 0x230, 0, 0x230, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B55C0
unsigned int D_002B55C0[10] = {5, 146, 0x23c, 0, 0x23c, 0, 0x23c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B55E8
unsigned int D_002B55E8[10] = {5, 146, 0x240, 0, 0x240, 0, 0x240, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5610
unsigned int D_002B5610[10] = {0x2085, 146, 0x230, 0, 0x230, 0, 0x230, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5638
void *D_002B5638[10] = {(void *)18, (void *)0x400, (void *)func_0010BDC8, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5660
void *D_002B5660[10] = {(void *)18, (void *)0x400, (void *)func_0010BE70, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5688
void *D_002B5688[10] = {(void *)18, (void *)0x400, (void *)func_0010BEE8, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B56B0
void *D_002B56B0[10] = {(void *)6, (void *)36, (void *)0xffff0000, (void *)func_001C7A40, (void *)0xffff0000, (void *)SelectCoinLootDef, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B56D8
void *D_002B56D8[10] = {(void *)6, (void *)0x2002, (void *)4, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001C7B10};

// data-ok: retail's bytes at 0X2B5700
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B5700 = {
    "\012",
    {146, 0x230, 0, 0x230, 0, 0x230, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B5728
unsigned int D_002B5728[10] = {15, 146, 0x3c80, 0, 0x3c80, 0, 0x3c80, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5750
void *D_002B5750[10] = {(void *)2, (void *)162, (void *)0x3e10, 0, (void *)0xffff0000, (void *)SetSwFogHsv, (void *)0x3e10, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5778
void *D_002B5778[10] = {(void *)1, (void *)162, (void *)0x3e24, 0, (void *)0xffff0000, (void *)func_0020F2D8, (void *)0x3e24, 0, 0, 0};

// data-ok: retail's bytes at 0X2B57A0
void *D_002B57A0[10] = {(void *)1, (void *)162, (void *)0x3e20, 0, (void *)0xffff0000, (void *)func_0020F2F8, (void *)0x3e20, 0, 0, 0};

// data-ok: retail's bytes at 0X2B57C8
void *D_002B57C8[10] = {(void *)2, (void *)0x2092, (void *)0x3e70, 0, (void *)0x3e70, 0, (void *)0x3e70, 0, (void *)0xffff0000, (void *)func_00210978};

// data-ok: retail's bytes at 0X2B57F0
void *D_002B57F0[10] = {(void *)1, (void *)0x2092, (void *)0x3e64, 0, (void *)0x3e64, 0, (void *)0x3e64, 0, (void *)0xffff0000, (void *)func_00210978};

// data-ok: retail's bytes at 0X2B5818
void *D_002B5818[10] = {(void *)2, (void *)0x2092, (void *)0x3e80, 0, (void *)0x3e80, 0, (void *)0x3e80, 0, (void *)0xffff0000, (void *)func_00210978};

// data-ok: retail's bytes at 0X2B5840
void *D_002B5840[10] = {(void *)1, (void *)0x2092, (void *)0x3e68, 0, (void *)0x3e68, 0, (void *)0x3e68, 0, (void *)0xffff0000, (void *)func_00210978};

// data-ok: retail's bytes at 0X2B5868
void *D_002B5868[10] = {(void *)2, (void *)0x2092, (void *)0x3e90, 0, (void *)0x3e90, 0, (void *)0x3e90, 0, (void *)0xffff0000, (void *)func_00210978};

// data-ok: retail's bytes at 0X2B5890
void *D_002B5890[10] = {(void *)1, (void *)0x2092, (void *)0x3e6c, 0, (void *)0x3e6c, 0, (void *)0x3e6c, 0, (void *)0xffff0000, (void *)func_00210978};

// data-ok: retail's bytes at 0X2B58B8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B58B8 = {
    "\015",
    {146, 0x3e00, 0, 0x3e00, 0, 0x3e00, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B58E0
unsigned int D_002B58E0[10] = {0, 130, 0x3e38, 0, 0, 0, 0x3e38, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5908
unsigned int D_002B5908[10] = {0, 146, 0x3e3c, 0, 0x3e3c, 0, 0x3e3c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5930
struct {
    char m0[4];
    void *m1[9];
} D_002B5930 = {
    "2 ",
    {(void *)4, (void *)0xffff0000, (void *)PpoSwFocusBase, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B5958
struct {
    char m0[4];
    void *m1[9];
} D_002B5958 = {
    "2 ",
    {(void *)4, (void *)0xffff0000, (void *)PpoSwFocus, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B5980
struct {
    char m0[4];
    char m1[4];
    void *m2[8];
} D_002B5980 = {
    "2 ",
    "\042",
    {(void *)0x3f00, 0, (void *)0xffff0000, (void *)SetSwFocusOverride, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B59A8
struct {
    char m0[4];
    void *m1[9];
} D_002B59A8 = {
    "2 ",
    {(void *)1, 0, 0, (void *)func_0010BF70, 0, (void *)1, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B59D0
unsigned int D_002B59D0[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B59F8
struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
    char m4[4];
    char m5[4];
    char m6[4];
    char m7[4];
    char m8[4];
    char m9[4];
} D_002B59F8 = {
    "\012",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
};

// data-ok: retail's bytes at 0X2B5A20
void *D_002B5A20[10] = {(void *)0x2093, (void *)1, 0, 0, (void *)func_0010BFF8, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5A48
void *D_002B5A48[10] = {(void *)18, (void *)1, 0, 0, (void *)func_0010C0A8, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5A70
void *D_002B5A70[10] = {(void *)18, (void *)0x400, (void *)func_0010C120, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5A98
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B5A98 = {
    "\011",
    {146, 0x45d0, 0, 0x45d0, 0, 0x45d0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B5AC0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B5AC0 = {
    "\012",
    {146, 0x45e0, 0, 0x45e0, 0, 0x45e0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B5AE8
unsigned int D_002B5AE8[10] = {6, 18, 0x3c88, 0, 0x3c88, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5B10
unsigned int D_002B5B10[10] = {6, 18, 0x3c8c, 0, 0x3c8c, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5B38
void *D_002B5B38[10] = {(void *)18, (void *)1, 0, 0, (void *)RefSetHandsOff, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5B60
void *D_002B5B60[10] = {(void *)18, (void *)1, 0, 0, (void *)RefClearHandsOff, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5B88
void *D_002B5B88[10] = {0, (void *)4, (void *)0xffff0000, (void *)FSwHandsOff, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5BB0
void *D_002B5BB0[10] = {(void *)18, (void *)1, 0, 0, (void *)func_0010C2E8, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5BD8
unsigned int D_002B5BD8[10] = {5, 2, 0x4768, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5C00
unsigned int D_002B5C00[10] = {5, 2, 0x4764, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5C28
void *D_002B5C28[10] = {(void *)18, (void *)0x400, (void *)RefAddWrCircleWarp, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5C50
void *D_002B5C50[10] = {(void *)18, (void *)0x400, (void *)RefAddWrBendWarp, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5C78
void *D_002B5C78[10] = {(void *)2, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)PwreGetWrCircle__FP2WR4ENSK};

// data-ok: retail's bytes at 0X2B5CA0
void *D_002B5CA0[10] = {(void *)1, (void *)0x124, (void *)0xffff0000, (void *)GetWrWavelength__FP2WRPf, (void *)0xffff0000, (void *)SetWrWavelength__FP2WRf, (void *)0xffff0000, (void *)SetWrWavelength__FP2WRf, 0, 0};

// data-ok: retail's bytes at 0X2B5CC8
void *D_002B5CC8[10] = {(void *)1, (void *)0x2092, (void *)104, 0, (void *)104, 0, (void *)104, 0, (void *)0xffff0000, (void *)PwreGetWrCircle__FP2WR4ENSK};

// data-ok: retail's bytes at 0X2B5CF0
void *D_002B5CF0[10] = {(void *)1, (void *)0x2092, (void *)108, 0, (void *)108, 0, (void *)108, 0, (void *)0xffff0000, (void *)PwreGetWrCircle__FP2WR4ENSK};

// data-ok: retail's bytes at 0X2B5D18
void *D_002B5D18[10] = {(void *)2, (void *)0x2092, (void *)32, 0, (void *)32, 0, (void *)32, 0, (void *)0xffff0000, (void *)PwreGetWrCircle__FP2WR4ENSK};

// data-ok: retail's bytes at 0X2B5D40
void *D_002B5D40[10] = {(void *)2, (void *)0x2092, (void *)64, 0, (void *)64, 0, (void *)64, 0, (void *)0xffff0000, (void *)PwreGetWrCircle__FP2WR4ENSK};

// data-ok: retail's bytes at 0X2B5D68
struct {
    char m0[4];
    void *m1[9];
} D_002B5D68 = {
    "\012",
    {(void *)0x2092, (void *)48, 0, (void *)48, 0, (void *)48, 0, (void *)0xffff0000, (void *)PwreGetWrCircle__FP2WR4ENSK}
};

// data-ok: retail's bytes at 0X2B5D90
struct {
    char m0[4];
    void *m1[9];
} D_002B5D90 = {
    "\012",
    {(void *)0x2092, (void *)80, 0, (void *)80, 0, (void *)80, 0, (void *)0xffff0000, (void *)PwreGetWrCircle__FP2WR4ENSK}
};

// data-ok: retail's bytes at 0X2B5DB8
void *D_002B5DB8[10] = {(void *)2, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)PwreGetWrBend__FP2WR4ENSK};

// data-ok: retail's bytes at 0X2B5DE0
struct {
    char m0[4];
    void *m1[9];
} D_002B5DE0 = {
    "\012",
    {(void *)0x2092, (void *)48, 0, (void *)48, 0, (void *)48, 0, (void *)0xffff0000, (void *)PwreGetWrBend__FP2WR4ENSK}
};

// data-ok: retail's bytes at 0X2B5E08
void *D_002B5E08[10] = {(void *)1, (void *)0x2092, (void *)56, 0, (void *)56, 0, (void *)56, 0, (void *)0xffff0000, (void *)PwreGetWrBend__FP2WR4ENSK};

// data-ok: retail's bytes at 0X2B5E30
void *D_002B5E30[10] = {(void *)18, (void *)0x400, (void *)RefAddWrBendNoise, 0, 0, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5E58
void *D_002B5E58[10] = {(void *)2, (void *)0x2092, (void *)32, 0, (void *)32, 0, (void *)32, 0, (void *)0xffff0000, (void *)PwreGetWrBend__FP2WR4ENSK};

// data-ok: retail's bytes at 0X2B5E80
struct {
    char m0[4];
    void *m1[9];
} D_002B5E80 = {
    "\012",
    {(void *)0x2092, (void *)128, 0, (void *)128, 0, (void *)128, 0, (void *)0xffff0000, (void *)PwreGetWrBend__FP2WR4ENSK}
};

// data-ok: retail's bytes at 0X2B5EA8
void *D_002B5EA8[10] = {(void *)1, (void *)0x2092, (void *)136, 0, (void *)136, 0, (void *)136, 0, (void *)0xffff0000, (void *)PwreGetWrBend__FP2WR4ENSK};

// data-ok: retail's bytes at 0X2B5ED0
void *D_002B5ED0[10] = {(void *)18, (void *)0x400, (void *)RefCallAddWrSwivelNoise, 0, 0, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5EF8
unsigned int D_002B5EF8[10] = {5, 2, 84, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5F20
unsigned int D_002B5F20[10] = {5, 18, 0x6e0, 0, 0x6e0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5F48
void *D_002B5F48[10] = {(void *)18, (void *)0x400, (void *)RefCallSetSlotSoSlot, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5F70
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B5F70 = {
    "\012 ",
    {146, 0x16c, 0, 0x16c, 0, 0x16c, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B5F98
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B5F98 = {
    "\012 ",
    {146, 0x170, 0, 0x170, 0, 0x170, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B5FC0
unsigned int D_002B5FC0[10] = {0x201e, 146, 0x1c8, 0, 0x1c8, 0, 0x1c8, 0, 0, 0};

// data-ok: retail's bytes at 0X2B5FE8
unsigned int D_002B5FE8[10] = {1, 146, 0x150, 0, 0x150, 0, 0x150, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6010
unsigned int D_002B6010[10] = {1, 146, 0x154, 0, 0x154, 0, 0x154, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6038
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B6038 = {
    "\012",
    {146, 0x158, 0, 0x158, 0, 0x158, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B6060
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B6060 = {
    "\012",
    {146, 0x160, 0, 0x160, 0, 0x160, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B6088
unsigned int D_002B6088[10] = {1, 146, 0x168, 0, 0x168, 0, 0x168, 0, 0, 0};

// data-ok: retail's bytes at 0X2B60B0
void *D_002B60B0[10] = {(void *)1, (void *)0x122, (void *)0x21c, 0, (void *)0xffff0000, (void *)SetSlotSoSmp, (void *)0xffff0000, (void *)SetSlotSoSmp, 0, 0};

// data-ok: retail's bytes at 0X2B60D8
void *D_002B60D8[10] = {(void *)0x1036, (void *)34, (void *)0x220, 0, (void *)0xffff0000, (void *)SetSlotSoState, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6100
unsigned int D_002B6100[10] = {5, 146, 0x230, 0, 0x230, 0, 0x230, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6128
unsigned int D_002B6128[10] = {2, 146, 0x240, 0, 0x240, 0, 0x240, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6150
unsigned int D_002B6150[10] = {0, 146, 0x150, 0, 0x150, 0, 0x150, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6178
void *D_002B6178[10] = {(void *)18, (void *)0x4401, (void *)RefCallStartFade, 0, (void *)RefCallStartFade, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B61A0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B61A0 = {
    "\015",
    {146, 80, 0, 80, 0, 80, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B61C8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B61C8 = {
    "\015",
    {146, 84, 0, 84, 0, 84, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B61F0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B61F0 = {
    "\015",
    {146, 88, 0, 88, 0, 88, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B6218
unsigned int D_002B6218[10] = {1, 146, 92, 0, 92, 0, 92, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6240
unsigned int D_002B6240[10] = {1, 146, 100, 0, 100, 0, 100, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6268
unsigned int D_002B6268[10] = {1, 146, 96, 0, 96, 0, 96, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6290
unsigned int D_002B6290[10] = {0x103b, 146, 108, 0, 108, 0, 108, 0, 0, 0};

// data-ok: retail's bytes at 0X2B62B8
unsigned int D_002B62B8[10] = {1, 2, 16, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B62E0
unsigned int D_002B62E0[10] = {1, 2, 20, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6308
unsigned int D_002B6308[10] = {1, 2, 24, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6330
unsigned int D_002B6330[10] = {1, 2, 28, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6358
unsigned int D_002B6358[10] = {1, 2, 32, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6380
unsigned int D_002B6380[10] = {1, 2, 36, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B63A8
unsigned int D_002B63A8[10] = {1, 2, 40, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B63D0
unsigned int D_002B63D0[10] = {1, 2, 44, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B63F8
void *D_002B63F8[10] = {0, (void *)1, 0, 0, (void *)RefCallFVjoyButtonPressed, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6420
void *D_002B6420[10] = {0, (void *)1, 0, 0, (void *)RefCallFVjoyButtonHeld, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6448
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B6448 = {
    "0 ",
    {146, 0x180, 0, 0x180, 0, 0x180, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B6470
unsigned int D_002B6470[10] = {0, 146, 0x188, 0, 0x188, 0, 0x188, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6498
unsigned int D_002B6498[10] = {0, 146, 0x184, 0, 0x184, 0, 0x184, 0, 0, 0};

// data-ok: retail's bytes at 0X2B64C0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B64C0 = {
    "\012",
    {146, 0x19c, 0, 0x19c, 0, 0x19c, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B64E8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B64E8 = {
    "\012",
    {146, 0x1a4, 0, 0x1a4, 0, 0x1a4, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B6510
unsigned int D_002B6510[10] = {0x2006, 146, 0x1c0, 0, 0x1c0, 0, 0x1c0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6538
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B6538 = {
    "p ",
    {146, 0x1c4, 0, 0x1c4, 0, 0x1c4, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B6560
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B6560 = {
    "0 ",
    {2, 0x1c8, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B6588
unsigned int D_002B6588[10] = {1, 146, 0x18c, 0, 0x18c, 0, 0x18c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B65B0
unsigned int D_002B65B0[10] = {1, 146, 0x190, 0, 0x190, 0, 0x190, 0, 0, 0};

// data-ok: retail's bytes at 0X2B65D8
void *D_002B65D8[10] = {0, (void *)162, (void *)0x1cc, 0, (void *)0xffff0000, (void *)func_00226370, (void *)0x1cc, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6600
unsigned int D_002B6600[10] = {0x2002, 146, 0x1d0, 0, 0x1d0, 0, 0x1d0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6628
unsigned int D_002B6628[10] = {0, 146, 0x1d4, 0, 0x1d4, 0, 0x1d4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6650
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B6650 = {
    "\012",
    {146, 0x1ac, 0, 0x1ac, 0, 0x1ac, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B6678
unsigned int D_002B6678[10] = {0x1030, 130, 0x124, 0, 0, 0, 0x124, 0, 0, 0};

// data-ok: retail's bytes at 0X2B66A0
unsigned int D_002B66A0[10] = {1, 146, 0x128, 0, 0x128, 0, 0x128, 0, 0, 0};

// data-ok: retail's bytes at 0X2B66C8
unsigned int D_002B66C8[10] = {14, 146, 0x12c, 0, 0x12c, 0, 0x12c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B66F0
unsigned int D_002B66F0[10] = {14, 146, 0x130, 0, 0x130, 0, 0x130, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6718
unsigned int D_002B6718[10] = {1, 146, 0x134, 0, 0x134, 0, 0x134, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6740
unsigned int D_002B6740[10] = {0x2002, 146, 0x138, 0, 0x138, 0, 0x138, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6768
void *D_002B6768[10] = {(void *)0x200f, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259A78};

// data-ok: retail's bytes at 0X2B6790
void *D_002B6790[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00259A78};

// data-ok: retail's bytes at 0X2B67B8
void *D_002B67B8[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00259A78};

// data-ok: retail's bytes at 0X2B67E0
void *D_002B67E0[10] = {0, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_00259A78};

// data-ok: retail's bytes at 0X2B6808
void *D_002B6808[10] = {(void *)0x106a, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259A78};

// data-ok: retail's bytes at 0X2B6830
void *D_002B6830[10] = {(void *)16, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_00259A78};

// data-ok: retail's bytes at 0X2B6858
void *D_002B6858[10] = {(void *)0x2002, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_00259A78};

// data-ok: retail's bytes at 0X2B6880
void *D_002B6880[10] = {(void *)0x106c, (void *)0x2092, (void *)28, 0, (void *)28, 0, (void *)28, 0, (void *)0xffff0000, (void *)func_00259A78};

// data-ok: retail's bytes at 0X2B68A8
void *D_002B68A8[10] = {(void *)18, (void *)0x400, (void *)RefCallAddStgSwitchClass, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B68D0
unsigned int D_002B68D0[10] = {18, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B68F8
unsigned int D_002B68F8[10] = {18, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6920
unsigned int D_002B6920[10] = {0x2002, 2, 0x16c, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6948
unsigned int D_002B6948[10] = {0x1011, 2, 0x170, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6970
void *D_002B6970[10] = {(void *)18, (void *)0x400, (void *)RefCallAddStgSwitchStage, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6998
void *D_002B6998[10] = {(void *)18, (void *)0x400, (void *)RefCallInitStgSwitchPreStage, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B69C0
void *D_002B69C0[10] = {(void *)18, (void *)0x400, (void *)RefCallSetStgSwitchStageHits, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B69E8
void *D_002B69E8[10] = {(void *)6, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001BBA60, 0, 0};

// data-ok: retail's bytes at 0X2B6A10
void *D_002B6A10[10] = {(void *)6, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001BBA90, 0, 0};

// data-ok: retail's bytes at 0X2B6A38
void *D_002B6A38[10] = {(void *)18, (void *)0x400, (void *)RefCallAddStgActionShake, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6A60
void *D_002B6A60[10] = {(void *)18, (void *)0x400, (void *)RefCallAddStgActionRumble, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6A88
void *D_002B6A88[10] = {(void *)18, (void *)0x400, (void *)RefCallAddStgActionSound, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6AB0
void *D_002B6AB0[10] = {(void *)6, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001BBB50, 0, 0};

// data-ok: retail's bytes at 0X2B6AD8
void *D_002B6AD8[10] = {(void *)6, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)AddStgActionShow, 0, 0};

// data-ok: retail's bytes at 0X2B6B00
void *D_002B6B00[10] = {(void *)18, (void *)0x401, (void *)RefCallAddStgActionShowGlob, 0, (void *)func_0010CC70, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6B28
void *D_002B6B28[10] = {(void *)18, (void *)0x401, (void *)RefCallAddStgActionEnablePart, 0, (void *)func_0010CD80, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6B50
void *D_002B6B50[10] = {(void *)18, (void *)0x400, (void *)RefCallAddStgActionHide, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6B78
void *D_002B6B78[10] = {(void *)18, (void *)0x401, (void *)RefCallAddStgActionHideGlob, 0, (void *)func_0010CF18, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6BA0
void *D_002B6BA0[10] = {(void *)18, (void *)0x401, (void *)RefCallAddStgActionDisablePart, 0, (void *)func_0010D028, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6BC8
void *D_002B6BC8[10] = {(void *)18, (void *)0x400, (void *)RefCallAddStgActionPostJob, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6BF0
unsigned int D_002B6BF0[10] = {0x104a, 18, 0x168, 0, 0x168, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6C18
void *D_002B6C18[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)RefCallSetStgSwitchHitter, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6C40
void *D_002B6C40[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStepStgSwitch, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6C68
void *D_002B6C68[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStartMurrayLift, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6C90
void *D_002B6C90[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStartMurrayThrow, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6CB8
void *D_002B6CB8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetMurrayStateF, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6CE0
void *D_002B6CE0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallResetMurrayGoalStack, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6D08
void *D_002B6D08[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStartMurrayFlop, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6D30
unsigned int D_002B6D30[10] = {1, 130, 0x130, 0, 0, 0, 0x130, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6D58
unsigned int D_002B6D58[10] = {0x2002, 146, 224, 0, 224, 0, 224, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6D80
unsigned int D_002B6D80[10] = {2, 146, 240, 0, 240, 0, 240, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6DA8
unsigned int D_002B6DA8[10] = {2, 146, 0x100, 0, 0x100, 0, 0x100, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6DD0
unsigned int D_002B6DD0[10] = {2, 146, 0x110, 0, 0x110, 0, 0x110, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6DF8
unsigned int D_002B6DF8[10] = {0, 146, 0x120, 0, 0x120, 0, 0x120, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6E20
unsigned int D_002B6E20[10] = {1, 130, 0x11c, 0, 0, 0, 0x11c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6E48
unsigned int D_002B6E48[10] = {1, 130, 0x120, 0, 0, 0, 0x120, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6E70
unsigned int D_002B6E70[10] = {1, 130, 0x124, 0, 0, 0, 0x124, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6E98
unsigned int D_002B6E98[10] = {0x2002, 146, 0x118, 0, 0x118, 0, 0x118, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6EC0
struct {
    char m0[4];
    void *m1[9];
} D_002B6EC0 = {
    "0 ",
    {(void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001BEAA8, 0, 0}
};

// data-ok: retail's bytes at 0X2B6EE8
void *D_002B6EE8[10] = {(void *)0x2004, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001BEAD0, 0, 0};

// data-ok: retail's bytes at 0X2B6F10
void *D_002B6F10[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)RefCallRtAloShow, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6F38
void *D_002B6F38[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)RefCallRtAloHide, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6F60
unsigned int D_002B6F60[10] = {0x2002, 146, 0x10c, 0, 0x10c, 0, 0x10c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6F88
unsigned int D_002B6F88[10] = {1, 146, 0x110, 0, 0x110, 0, 0x110, 0, 0, 0};

// data-ok: retail's bytes at 0X2B6FB0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B6FB0 = {
    "r ",
    {146, 0x114, 0, 0x114, 0, 0x114, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B6FD8
void *D_002B6FD8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallVirtual198, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7000
void *D_002B7000[10] = {0, (void *)1, 0, 0, (void *)RefCallFStateAccepted, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7028
void *D_002B7028[10] = {(void *)0x2002, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_00184028, (void *)0xffff0000, (void *)func_00184028, 0, 0};

// data-ok: retail's bytes at 0X2B7050
void *D_002B7050[10] = {(void *)7, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_00184040, (void *)0xffff0000, (void *)func_00184040, 0, 0};

// data-ok: retail's bytes at 0X2B7078
void *D_002B7078[10] = {(void *)18, (void *)0x401, (void *)RefCallAttachPtAddRsmg, 0, (void *)RefCallAttachPtAddRsmg, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B70A0
void *D_002B70A0[10] = {(void *)18, (void *)0x401, (void *)RefCallAttachPtAddTaskStateRequest, 0, (void *)RefCallAttachPtAddTaskStateRequest, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B70C8
void *D_002B70C8[10] = {(void *)0x200f, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259A38};

// data-ok: retail's bytes at 0X2B70F0
void *D_002B70F0[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00259A38};

// data-ok: retail's bytes at 0X2B7118
void *D_002B7118[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00259A38};

// data-ok: retail's bytes at 0X2B7140
void *D_002B7140[10] = {0, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_00259A38};

// data-ok: retail's bytes at 0X2B7168
void *D_002B7168[10] = {(void *)0x106a, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259A38};

// data-ok: retail's bytes at 0X2B7190
void *D_002B7190[10] = {(void *)16, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_00259A38};

// data-ok: retail's bytes at 0X2B71B8
void *D_002B71B8[10] = {(void *)0x2002, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_00259A38};

// data-ok: retail's bytes at 0X2B71E0
void *D_002B71E0[10] = {(void *)0x106c, (void *)0x2092, (void *)28, 0, (void *)28, 0, (void *)28, 0, (void *)0xffff0000, (void *)func_00259A38};

// data-ok: retail's bytes at 0X2B7208
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B7208 = {
    "0 ",
    {146, 0x180, 0, 0x180, 0, 0x180, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B7230
unsigned int D_002B7230[10] = {6, 128, 0, 0, 0, 0, 0x184, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7258
unsigned int D_002B7258[10] = {6, 128, 0, 0, 0, 0, 0x18c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7280
unsigned int D_002B7280[10] = {6, 128, 0, 0, 0, 0, 0x194, 0, 0, 0};

// data-ok: retail's bytes at 0X2B72A8
unsigned int D_002B72A8[10] = {6, 146, 0x19c, 0, 0x19c, 0, 0x19c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B72D0
unsigned int D_002B72D0[10] = {0x1046, 146, 80, 0, 80, 0, 80, 0, 0, 0};

// data-ok: retail's bytes at 0X2B72F8
unsigned int D_002B72F8[10] = {1, 146, 84, 0, 84, 0, 84, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7320
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B7320 = {
    "\012",
    {146, 88, 0, 88, 0, 88, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B7348
unsigned int D_002B7348[10] = {1, 146, 96, 0, 96, 0, 96, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7370
unsigned int D_002B7370[10] = {0x1047, 146, 100, 0, 100, 0, 100, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7398
void *D_002B7398[10] = {(void *)0x2093, (void *)1, 0, 0, (void *)RefCallPhitfxSpawn, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B73C0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B73C0 = {
    "u ",
    {2, 20, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B73E8
unsigned int D_002B73E8[10] = {2, 18, 32, 0, 32, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7410
unsigned int D_002B7410[10] = {2, 18, 48, 0, 48, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7438
unsigned int D_002B7438[10] = {0x1047, 18, 84, 0, 84, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7460
void *D_002B7460[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallHitFxRemove, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7488
void *D_002B7488[10] = {0, (void *)4, (void *)0xffff0000, (void *)FHitFxGone, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B74B0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B74B0 = {
    "o ",
    {146, 0x164, 0, 0x164, 0, 0x164, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B74D8
unsigned int D_002B74D8[10] = {0x2088, 2, 0x168, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7500
unsigned int D_002B7500[10] = {0x1049, 146, 0x15c, 0, 0x15c, 0, 0x15c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7528
void *D_002B7528[10] = {0, (void *)4, (void *)0xffff0000, (void *)FGadgetObjKept, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7550
void *D_002B7550[10] = {0, (void *)4, (void *)0xffff0000, (void *)FGadgetObjCanStick, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7578
unsigned int D_002B7578[10] = {0x1011, 146, 0x174, 0, 0x174, 0, 0x174, 0, 0, 0};

// data-ok: retail's bytes at 0X2B75A0
unsigned int D_002B75A0[10] = {5, 146, 0x178, 0, 0x178, 0, 0x178, 0, 0, 0};

// data-ok: retail's bytes at 0X2B75C8
void *D_002B75C8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStickGadgetObj, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B75F0
void *D_002B75F0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallDetonateGadgetObj, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7618
unsigned int D_002B7618[10] = {0x2002, 146, 0x16c, 0, 0x16c, 0, 0x16c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7640
unsigned int D_002B7640[10] = {1, 146, 0x170, 0, 0x170, 0, 0x170, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7668
unsigned int D_002B7668[10] = {0x2002, 146, 0x1b0, 0, 0x1b0, 0, 0x1b0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7690
unsigned int D_002B7690[10] = {0x2016, 146, 0x1010, 0, 0x1010, 0, 0x1010, 0, 0, 0};

// data-ok: retail's bytes at 0X2B76B8
unsigned int D_002B76B8[10] = {0x2016, 146, 0x1014, 0, 0x1014, 0, 0x1014, 0, 0, 0};

// data-ok: retail's bytes at 0X2B76E0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B76E0 = {
    "0 ",
    {146, 0x1050, 0, 0x1050, 0, 0x1050, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B7708
void *D_002B7708[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetGuardScriptCommand, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7730
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B7730 = {
    "m ",
    {146, 0x1064, 0, 0x1064, 0, 0x1064, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B7758
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B7758 = {
    "\011",
    {146, 0x1070, 0, 0x1070, 0, 0x1070, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B7780
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B7780 = {
    "\012",
    {146, 0x1080, 0, 0x1080, 0, 0x1080, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B77A8
unsigned int D_002B77A8[10] = {1, 146, 0x1088, 0, 0x1088, 0, 0x1088, 0, 0, 0};

// data-ok: retail's bytes at 0X2B77D0
unsigned int D_002B77D0[10] = {0, 144, 0, 0, 109, 0, 109, 0, 0, 0};

// data-ok: retail's bytes at 0X2B77F8
unsigned int D_002B77F8[10] = {0x1068, 130, 164, 0, 0, 0, 164, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7820
unsigned int D_002B7820[10] = {0, 130, 172, 0, 0, 0, 172, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7848
unsigned int D_002B7848[10] = {1, 146, 140, 0, 140, 0, 140, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7870
void *D_002B7870[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)func_0010DAF0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7898
void *D_002B7898[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)func_0010DB78, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B78C0
void *D_002B78C0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStartBlotLabel, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B78E8
void *D_002B78E8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallRewindBlotLabel, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7910
void *D_002B7910[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSeekBlotLabel, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7938
void *D_002B7938[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSeekBlotLabelTime, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7960
void *D_002B7960[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSetBlotLabelListFromRef, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7988
unsigned int D_002B7988[10] = {16, 146, 204, 0, 204, 0, 204, 0, 0, 0};

// data-ok: retail's bytes at 0X2B79B0
unsigned int D_002B79B0[10] = {16, 146, 208, 0, 208, 0, 208, 0, 0, 0};

// data-ok: retail's bytes at 0X2B79D8
unsigned int D_002B79D8[10] = {16, 146, 212, 0, 212, 0, 212, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7A00
unsigned int D_002B7A00[10] = {16, 146, 216, 0, 216, 0, 216, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7A28
unsigned int D_002B7A28[10] = {16, 146, 220, 0, 220, 0, 220, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7A50
unsigned int D_002B7A50[10] = {16, 146, 224, 0, 224, 0, 224, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7A78
unsigned int D_002B7A78[10] = {16, 146, 228, 0, 228, 0, 228, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7AA0
unsigned int D_002B7AA0[10] = {16, 146, 232, 0, 232, 0, 232, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7AC8
unsigned int D_002B7AC8[10] = {16, 146, 236, 0, 236, 0, 236, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7AF0
unsigned int D_002B7AF0[10] = {16, 146, 240, 0, 240, 0, 240, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7B18
unsigned int D_002B7B18[10] = {16, 146, 0x110, 0, 0x110, 0, 0x110, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7B40
unsigned int D_002B7B40[10] = {16, 146, 0x114, 0, 0x114, 0, 0x114, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7B68
unsigned int D_002B7B68[10] = {16, 146, 0x118, 0, 0x118, 0, 0x118, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7B90
unsigned int D_002B7B90[10] = {16, 146, 0x11c, 0, 0x11c, 0, 0x11c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7BB8
unsigned int D_002B7BB8[10] = {16, 146, 0x120, 0, 0x120, 0, 0x120, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7BE0
unsigned int D_002B7BE0[10] = {0, 2, 0x110, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7C08
unsigned int D_002B7C08[10] = {0, 146, 0x114, 0, 0x114, 0, 0x114, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7C30
void *D_002B7C30[10] = {(void *)18, (void *)0x400, (void *)RefCallJobBlotAddOptionalJob, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7C58
void *D_002B7C58[10] = {(void *)18, (void *)0x400, (void *)RefCallJobBlotAddRequiredJob, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7C80
void *D_002B7C80[10] = {(void *)18, (void *)0x400, (void *)RefCallAddLootDef, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7CA8
void *D_002B7CA8[10] = {(void *)18, (void *)0x400, (void *)RefCallClearLootDef, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7CD0
void *D_002B7CD0[10] = {(void *)18, (void *)0x400, (void *)RefCallAddLootDefGlob, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7CF8
void *D_002B7CF8[10] = {(void *)6, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_0013C4D8};

// data-ok: retail's bytes at 0X2B7D20
unsigned int D_002B7D20[10] = {0x201e, 146, 0x164, 0, 0x164, 0, 0x164, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7D48
unsigned int D_002B7D48[10] = {2, 146, 0x170, 0, 0x170, 0, 0x170, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7D70
void *D_002B7D70[10] = {(void *)6, (void *)36, (void *)0xffff0000, (void *)LootId, (void *)0xffff0000, (void *)SelectLootDef, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7D98
void *D_002B7D98[10] = {(void *)6, (void *)0x2002, (void *)20, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_0013C4D8};

// data-ok: retail's bytes at 0X2B7DC0
void *D_002B7DC0[10] = {(void *)6, (void *)0x2002, (void *)4, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_0013C4D8};

// data-ok: retail's bytes at 0X2B7DE8
void *D_002B7DE8[10] = {0, (void *)0x2080, 0, 0, 0, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_0013C4D8};

// data-ok: retail's bytes at 0X2B7E10
void *D_002B7E10[10] = {0, (void *)0x2080, 0, 0, 0, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_0013C4D8};

// data-ok: retail's bytes at 0X2B7E38
void *D_002B7E38[10] = {0, (void *)0x2080, 0, 0, 0, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_0013C4D8};

// data-ok: retail's bytes at 0X2B7E60
unsigned int D_002B7E60[10] = {0x1042, 2, 0x184, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7E88
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B7E88 = {
    "% ",
    {2, 0x15c, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B7EB0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B7EB0 = {
    "4 ",
    {2, 0x160, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B7ED8
unsigned int D_002B7ED8[10] = {6, 130, 0x184, 0, 0, 0, 0x184, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7F00
void *D_002B7F00[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallCrfodbSetLootId, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7F28
unsigned int D_002B7F28[10] = {0, 146, 0x190, 0, 0x190, 0, 0x190, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7F50
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B7F50 = {
    "g ",
    {2, 0x194, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B7F78
unsigned int D_002B7F78[10] = {6, 146, 0x188, 0, 0x188, 0, 0x188, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7FA0
unsigned int D_002B7FA0[10] = {6, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7FC8
unsigned int D_002B7FC8[10] = {1, 146, 0x18c, 0, 0x18c, 0, 0x18c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B7FF0
void *D_002B7FF0[10] = {0, (void *)1, 0, 0, (void *)RefCallFCanLease, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8018
void *D_002B8018[10] = {(void *)0x2002, (void *)1, 0, 0, (void *)RefCallPloLeaseCloneObject, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8040
void *D_002B8040[10] = {(void *)0x2002, (void *)4, (void *)0xffff0000, (void *)PloLeased, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8068
void *D_002B8068[10] = {(void *)0x2002, (void *)1, 0, 0, (void *)RefCallEnsureLeasedObject, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8090
unsigned int D_002B8090[10] = {0, 146, 228, 0, 228, 0, 228, 0, 0, 0};

// data-ok: retail's bytes at 0X2B80B8
void *D_002B80B8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallLockLeaseOfPlo, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B80E0
void *D_002B80E0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallUnlockLeaseOfPlo, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8108
void *D_002B8108[10] = {(void *)0xa002, (void *)4, (void *)0xffff0000, (void *)func_001CB360, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8130
unsigned int D_002B8130[10] = {0x2003, 146, 0x15c, 0, 0x15c, 0, 0x15c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8158
void *D_002B8158[10] = {(void *)0x200f, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00259A48};

// data-ok: retail's bytes at 0X2B8180
void *D_002B8180[10] = {0, (void *)0x2092, (void *)4, 0, (void *)4, 0, (void *)4, 0, (void *)0xffff0000, (void *)func_00259A48};

// data-ok: retail's bytes at 0X2B81A8
void *D_002B81A8[10] = {(void *)1, (void *)0x2092, (void *)8, 0, (void *)8, 0, (void *)8, 0, (void *)0xffff0000, (void *)func_00259A48};

// data-ok: retail's bytes at 0X2B81D0
void *D_002B81D0[10] = {0, (void *)0x2092, (void *)12, 0, (void *)12, 0, (void *)12, 0, (void *)0xffff0000, (void *)func_00259A48};

// data-ok: retail's bytes at 0X2B81F8
void *D_002B81F8[10] = {(void *)0x106a, (void *)0x2092, (void *)16, 0, (void *)16, 0, (void *)16, 0, (void *)0xffff0000, (void *)func_00259A48};

// data-ok: retail's bytes at 0X2B8220
void *D_002B8220[10] = {(void *)16, (void *)0x2092, (void *)20, 0, (void *)20, 0, (void *)20, 0, (void *)0xffff0000, (void *)func_00259A48};

// data-ok: retail's bytes at 0X2B8248
void *D_002B8248[10] = {(void *)0x2002, (void *)0x2080, 0, 0, 0, 0, (void *)24, 0, (void *)0xffff0000, (void *)func_00259A48};

// data-ok: retail's bytes at 0X2B8270
void *D_002B8270[10] = {(void *)0x106c, (void *)0x2092, (void *)28, 0, (void *)28, 0, (void *)28, 0, (void *)0xffff0000, (void *)func_00259A48};

// data-ok: retail's bytes at 0X2B8298
unsigned int D_002B8298[10] = {1, 130, 80, 0, 0, 0, 80, 0, 0, 0};

// data-ok: retail's bytes at 0X2B82C0
unsigned int D_002B82C0[10] = {1, 130, 84, 0, 0, 0, 84, 0, 0, 0};

// data-ok: retail's bytes at 0X2B82E8
unsigned int D_002B82E8[10] = {1, 130, 88, 0, 0, 0, 88, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8310
unsigned int D_002B8310[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8338
unsigned int D_002B8338[10] = {1, 146, 224, 0, 224, 0, 224, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8360
unsigned int D_002B8360[10] = {1, 146, 228, 0, 228, 0, 228, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8388
unsigned int D_002B8388[10] = {1, 146, 232, 0, 232, 0, 232, 0, 0, 0};

// data-ok: retail's bytes at 0X2B83B0
unsigned int D_002B83B0[10] = {16, 146, 244, 0, 244, 0, 244, 0, 0, 0};

// data-ok: retail's bytes at 0X2B83D8
unsigned int D_002B83D8[10] = {16, 146, 248, 0, 248, 0, 248, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8400
unsigned int D_002B8400[10] = {16, 146, 252, 0, 252, 0, 252, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8428
unsigned int D_002B8428[10] = {0x2085, 146, 236, 0, 236, 0, 236, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8450
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B8450 = {
    "k ",
    {146, 0x100, 0, 0x100, 0, 0x100, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B8478
unsigned int D_002B8478[10] = {1, 146, 0x104, 0, 0x104, 0, 0x104, 0, 0, 0};

// data-ok: retail's bytes at 0X2B84A0
void *D_002B84A0[10] = {0, (void *)4, (void *)0xffff0000, (void *)FReconTargetDone, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B84C8
unsigned int D_002B84C8[10] = {0, 146, 0x10c, 0, 0x10c, 0, 0x10c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B84F0
unsigned int D_002B84F0[10] = {16, 146, 0x110, 0, 0x110, 0, 0x110, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8518
void *D_002B8518[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallStartWipe, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8540
void *D_002B8540[10] = {(void *)0x2002, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_001E7930, (void *)0xffff0000, (void *)func_001E7930, 0, 0};

// data-ok: retail's bytes at 0X2B8568
void *D_002B8568[10] = {(void *)0x2002, (void *)0x120, 0, 0, (void *)0xffff0000, (void *)func_001E7968, (void *)0xffff0000, (void *)func_001E7968, 0, 0};

// data-ok: retail's bytes at 0X2B8590
void *D_002B8590[10] = {(void *)1, (void *)0x124, (void *)0xffff0000, (void *)func_001E79A0, (void *)0xffff0000, (void *)SetCrvRopeLength, (void *)0xffff0000, (void *)SetCrvRopeLength, 0, 0};

// data-ok: retail's bytes at 0X2B85B8
void *D_002B85B8[10] = {(void *)2, (void *)0x2092, 0, 0, 0, 0, 0, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B85E0
void *D_002B85E0[10] = {(void *)0x104b, (void *)0x124, (void *)0xffff0000, (void *)func_001E7FF0, (void *)0xffff0000, (void *)SetCrvRopeMode, (void *)0xffff0000, (void *)SetCrvRopeMode, 0, 0};

// data-ok: retail's bytes at 0X2B8608
void *D_002B8608[10] = {(void *)1, (void *)0x2092, (void *)100, 0, (void *)100, 0, (void *)100, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B8630
void *D_002B8630[10] = {(void *)1, (void *)0x2092, (void *)108, 0, (void *)108, 0, (void *)108, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B8658
void *D_002B8658[10] = {(void *)1, (void *)0x2092, (void *)116, 0, (void *)116, 0, (void *)116, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B8680
void *D_002B8680[10] = {(void *)1, (void *)0x2092, (void *)124, 0, (void *)124, 0, (void *)124, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B86A8
void *D_002B86A8[10] = {(void *)1, (void *)0x2092, (void *)96, 0, (void *)96, 0, (void *)96, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B86D0
void *D_002B86D0[10] = {(void *)1, (void *)0x2092, (void *)104, 0, (void *)104, 0, (void *)104, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B86F8
void *D_002B86F8[10] = {(void *)1, (void *)0x2092, (void *)112, 0, (void *)112, 0, (void *)112, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B8720
void *D_002B8720[10] = {(void *)1, (void *)0x2092, (void *)120, 0, (void *)120, 0, (void *)120, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B8748
void *D_002B8748[10] = {(void *)1, (void *)0x2092, (void *)128, 0, (void *)128, 0, (void *)128, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B8770
void *D_002B8770[10] = {(void *)1, (void *)0x2092, (void *)136, 0, (void *)136, 0, (void *)136, 0, (void *)0xffff0000, (void *)PattachCrv};

// data-ok: retail's bytes at 0X2B8798
void *D_002B8798[10] = {(void *)2, (void *)1, 0, 0, (void *)RefCallPosClosestOnCrv, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B87C0
void *D_002B87C0[10] = {(void *)1, (void *)36, (void *)0xffff0000, (void *)func_001F87A0, (void *)0xffff0000, (void *)func_001F87C8, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B87E8
void *D_002B87E8[10] = {(void *)1, (void *)36, (void *)0xffff0000, (void *)func_001F8808, (void *)0xffff0000, (void *)func_001F8830, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8810
void *D_002B8810[10] = {(void *)1, (void *)36, (void *)0xffff0000, (void *)func_001F8870, (void *)0xffff0000, (void *)func_001F8898, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8838
void *D_002B8838[10] = {(void *)1, (void *)0x2012, (void *)168, 0, (void *)168, 0, 0, 0, (void *)0xffff0000, (void *)func_001F88D8};

// data-ok: retail's bytes at 0X2B8860
void *D_002B8860[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallXfRefSetGoalPointWorld, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8888
void *D_002B8888[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallXfRefSetGoalEulerWorld, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B88B0
void *D_002B88B0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallXfRefSetGoalRange, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B88D8
void *D_002B88D8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallXfRefSetKind16Params, 0, (void *)6, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8900
void *D_002B8900[10] = {(void *)0x1011, (void *)36, (void *)0xffff0000, (void *)func_00256350, (void *)0xffff0000, (void *)func_00256328, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8928
void *D_002B8928[10] = {(void *)5, (void *)36, (void *)0xffff0000, (void *)func_00256318, (void *)0xffff0000, (void *)func_002562F0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8950
void *D_002B8950[10] = {(void *)1, (void *)36, (void *)0xffff0000, (void *)func_002562E0, (void *)0xffff0000, (void *)func_002562B8, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8978
void *D_002B8978[10] = {0, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001628B0, 0, 0};

// data-ok: retail's bytes at 0X2B89A0
void *D_002B89A0[10] = {(void *)18, (void *)0x400, (void *)RefCallAddJobFailEvent, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B89C8
void *D_002B89C8[10] = {(void *)18, (void *)0x400, (void *)RefCallAddJobCompleteEvent, 0, 0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B89F0
void *D_002B89F0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallFailJob, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8A18
void *D_002B8A18[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallRestartJob, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8A40
void *D_002B8A40[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallCompleteJob, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8A68
unsigned int D_002B8A68[10] = {0, 146, 116, 0, 116, 0, 116, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8A90
unsigned int D_002B8A90[10] = {0, 146, 120, 0, 120, 0, 120, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8AB8
unsigned int D_002B8AB8[10] = {0x2085, 146, 100, 0, 100, 0, 100, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8AE0
unsigned int D_002B8AE0[10] = {0x2085, 146, 104, 0, 104, 0, 104, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8B08
unsigned int D_002B8B08[10] = {16, 146, 108, 0, 108, 0, 108, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8B30
unsigned int D_002B8B30[10] = {16, 146, 112, 0, 112, 0, 112, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8B58
unsigned int D_002B8B58[10] = {18, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8B80
unsigned int D_002B8B80[10] = {18, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8BA8
unsigned int D_002B8BA8[10] = {5, 2, 124, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8BD0
void *D_002B8BD0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallResetJob, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8BF8
void *D_002B8BF8[10] = {0, (void *)4, (void *)0xffff0000, (void *)FEndTaskComplete, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8C20
void *D_002B8C20[10] = {0, (void *)4, (void *)0xffff0000, (void *)FIsCurrentJob, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8C48
unsigned int D_002B8C48[10] = {0x1051, 2, 240, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8C70
unsigned int D_002B8C70[10] = {0x2002, 2, 244, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8C98
void *D_002B8C98[10] = {(void *)18, (void *)0x400, (void *)RefCallAddJobToggle, 0, 0, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8CC0
void *D_002B8CC0[10] = {(void *)18, (void *)0x400, (void *)RefCallAddJobAnim, 0, 0, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8CE8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B8CE8 = {
    "\012",
    {128, 0, 0, 0, 0, 156, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B8D10
void *D_002B8D10[10] = {(void *)18, (void *)0x400, (void *)RefCallSetJobCompleteAseg, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8D38
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B8D38 = {
    "\032 ",
    {0x8092, 204, 0, 204, 0, 204, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B8D60
unsigned int D_002B8D60[10] = {22, 128, 0, 0, 0, 0, 224, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8D88
unsigned int D_002B8D88[10] = {22, 128, 0, 0, 0, 0, 232, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8DB0
unsigned int D_002B8DB0[10] = {22, 128, 0, 0, 0, 0, 208, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8DD8
unsigned int D_002B8DD8[10] = {22, 128, 0, 0, 0, 0, 216, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8E00
unsigned int D_002B8E00[10] = {0x2084, 146, 124, 0, 124, 0, 124, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8E28
unsigned int D_002B8E28[10] = {16, 146, 92, 0, 92, 0, 92, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8E50
unsigned int D_002B8E50[10] = {0, 146, 96, 0, 96, 0, 96, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8E78
unsigned int D_002B8E78[10] = {5, 2, 100, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8EA0
void *D_002B8EA0[10] = {0, (void *)4, (void *)0xffff0000, (void *)FTaskComplete, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8EC8
void *D_002B8EC8[10] = {0, (void *)4, (void *)0xffff0000, (void *)FIsCurrentTask, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8EF0
void *D_002B8EF0[10] = {(void *)6, (void *)4, (void *)0xffff0000, (void *)func_00164098, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8F18
unsigned int D_002B8F18[10] = {0, 146, 108, 0, 108, 0, 108, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8F40
unsigned int D_002B8F40[10] = {0, 146, 112, 0, 112, 0, 112, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8F68
unsigned int D_002B8F68[10] = {0, 146, 116, 0, 116, 0, 116, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8F90
unsigned int D_002B8F90[10] = {6, 146, 184, 0, 184, 0, 184, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8FB8
unsigned int D_002B8FB8[10] = {15, 146, 188, 0, 188, 0, 188, 0, 0, 0};

// data-ok: retail's bytes at 0X2B8FE0
unsigned int D_002B8FE0[10] = {6, 146, 192, 0, 192, 0, 192, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9008
unsigned int D_002B9008[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9030
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9030 = {
    "\032 ",
    {0x8092, 196, 0, 196, 0, 196, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9058
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9058 = {
    "k ",
    {0x8092, 128, 0, 128, 0, 128, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9080
void *D_002B9080[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallRequestTaskState, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B90A8
void *D_002B90A8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallForceTaskState, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B90D0
unsigned int D_002B90D0[10] = {0x1051, 2, 244, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B90F8
unsigned int D_002B90F8[10] = {0x2002, 2, 248, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9120
void *D_002B9120[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSendTaskTimeLimit, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9148
unsigned int D_002B9148[10] = {1, 146, 120, 0, 120, 0, 120, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9170
unsigned int D_002B9170[10] = {0x104f, 2, 84, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9198
void *D_002B9198[10] = {(void *)18, (void *)0x400, (void *)RefCallAddTaskToggle, 0, 0, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B91C0
void *D_002B91C0[10] = {(void *)18, (void *)0x400, (void *)RefCallAddTaskAnim, 0, 0, 0, (void *)6, 0, 0, 0};

// data-ok: retail's bytes at 0X2B91E8
unsigned int D_002B91E8[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9210
void *D_002B9210[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallForceTaskLocked, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9238
void *D_002B9238[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)RefCallForceTaskActive, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9260
void *D_002B9260[10] = {(void *)18, (void *)0x4001, 0, 0, (void *)RefForceTaskComplete, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9288
void *D_002B9288[10] = {(void *)18, (void *)1, 0, 0, (void *)RefForceTaskClosed, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B92B0
void *D_002B92B0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefSwitchCurrentTask, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B92D8
unsigned int D_002B92D8[10] = {22, 128, 0, 0, 0, 0, 200, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9300
unsigned int D_002B9300[10] = {22, 128, 0, 0, 0, 0, 208, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9328
unsigned int D_002B9328[10] = {22, 128, 0, 0, 0, 0, 216, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9350
unsigned int D_002B9350[10] = {22, 128, 0, 0, 0, 0, 224, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9378
unsigned int D_002B9378[10] = {22, 128, 0, 0, 0, 0, 232, 0, 0, 0};

// data-ok: retail's bytes at 0X2B93A0
void *D_002B93A0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefShowHudLabel, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B93C8
void *D_002B93C8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefClearHudLabel, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B93F0
unsigned int D_002B93F0[10] = {16, 2, 24, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9418
unsigned int D_002B9418[10] = {16, 2, 32, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9440
unsigned int D_002B9440[10] = {1, 130, 0x150, 0, 0, 0, 0x150, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9468
unsigned int D_002B9468[10] = {5, 130, 0x158, 0, 0, 0, 0x158, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9490
unsigned int D_002B9490[10] = {0, 130, 0x154, 0, 0, 0, 0x154, 0, 0, 0};

// data-ok: retail's bytes at 0X2B94B8
unsigned int D_002B94B8[10] = {2, 146, 0x170, 0, 0x170, 0, 0x170, 0, 0, 0};

// data-ok: retail's bytes at 0X2B94E0
unsigned int D_002B94E0[10] = {1, 146, 0x168, 0, 0x168, 0, 0x168, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9508
unsigned int D_002B9508[10] = {0x2003, 146, 0x180, 0, 0x180, 0, 0x180, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9530
unsigned int D_002B9530[10] = {1, 146, 0x184, 0, 0x184, 0, 0x184, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9558
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9558 = {
    "\012 ",
    {130, 0x150, 0, 0, 0, 0x150, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9580
unsigned int D_002B9580[10] = {6, 130, 0x110, 0, 0, 0, 0x110, 0, 0, 0};

// data-ok: retail's bytes at 0X2B95A8
unsigned int D_002B95A8[10] = {7, 146, 0x154, 0, 0x154, 0, 0x154, 0, 0, 0};

// data-ok: retail's bytes at 0X2B95D0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B95D0 = {
    "\012",
    {146, 0x158, 0, 0x158, 0, 0x158, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B95F8
unsigned int D_002B95F8[10] = {0x2085, 146, 0x160, 0, 0x160, 0, 0x160, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9620
unsigned int D_002B9620[10] = {0x1055, 146, 0x150, 0, 0x150, 0, 0x150, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9648
unsigned int D_002B9648[10] = {0x2003, 130, 0x168, 0, 0, 0, 0x168, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9670
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9670 = {
    "0 ",
    {130, 0x16c, 0, 0, 0, 0x16c, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9698
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9698 = {
    "0 ",
    {130, 0x170, 0, 0, 0, 0x170, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B96C0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B96C0 = {
    "0 ",
    {130, 0x174, 0, 0, 0, 0x174, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B96E8
unsigned int D_002B96E8[10] = {18, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9710
unsigned int D_002B9710[10] = {0x2084, 130, 0x188, 0, 0, 0, 0x188, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9738
unsigned int D_002B9738[10] = {0x1049, 130, 0x184, 0, 0, 0, 0x184, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9760
void *D_002B9760[10] = {(void *)6, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001732E0, 0, 0};

// data-ok: retail's bytes at 0X2B9788
void *D_002B9788[10] = {(void *)6, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00173318, 0, 0};

// data-ok: retail's bytes at 0X2B97B0
void *D_002B97B0[10] = {(void *)6, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00173358, 0, 0};

// data-ok: retail's bytes at 0X2B97D8
unsigned int D_002B97D8[10] = {5, 146, 92, 0, 92, 0, 92, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9800
void *D_002B9800[10] = {(void *)0x2006, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_00173398, 0, 0};

// data-ok: retail's bytes at 0X2B9828
unsigned int D_002B9828[10] = {0, 146, 132, 0, 132, 0, 132, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9850
unsigned int D_002B9850[10] = {0, 146, 136, 0, 136, 0, 136, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9878
unsigned int D_002B9878[10] = {0, 146, 140, 0, 140, 0, 140, 0, 0, 0};

// data-ok: retail's bytes at 0X2B98A0
unsigned int D_002B98A0[10] = {1, 146, 128, 0, 128, 0, 128, 0, 0, 0};

// data-ok: retail's bytes at 0X2B98C8
void *D_002B98C8[10] = {(void *)2, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)AddSpawnerOffset, 0, 0};

// data-ok: retail's bytes at 0X2B98F0
unsigned int D_002B98F0[10] = {1, 146, 160, 0, 160, 0, 160, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9918
unsigned int D_002B9918[10] = {1, 146, 164, 0, 164, 0, 164, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9940
unsigned int D_002B9940[10] = {0x1067, 146, 172, 0, 172, 0, 172, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9968
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9968 = {
    "o ",
    {146, 0x184, 0, 0x184, 0, 0x184, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9990
void *D_002B9990[10] = {(void *)18, (void *)0x400, (void *)RefAddHubEntry, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B99B8
void *D_002B99B8[10] = {(void *)18, (void *)0x401, (void *)RefSetHubAllowedStates, 0, (void *)RefSetHubAllowedStates, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B99E0
void *D_002B99E0[10] = {(void *)18, (void *)0x400, (void *)RefAddGuardPost, 0, 0, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9A08
void *D_002B9A08[10] = {(void *)2, (void *)1, 0, 0, (void *)RefPosAimAtPlayer, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9A30
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9A30 = {
    "m ",
    {146, 0x2c0, 0, 0x2c0, 0, 0x2c0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9A58
void *D_002B9A58[10] = {(void *)18, (void *)0x400, (void *)RefAddDancerMove, 0, 0, 0, (void *)5, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9A80
unsigned int D_002B9A80[10] = {1, 146, 88, 0, 88, 0, 88, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9AA8
unsigned int D_002B9AA8[10] = {1, 146, 92, 0, 92, 0, 92, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9AD0
void *D_002B9AD0[10] = {(void *)18, (void *)0x400, (void *)RefAddRhythmCrowd, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9AF8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9AF8 = {
    "\012",
    {130, 0x234, 0, 0, 0, 0x234, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9B20
unsigned int D_002B9B20[10] = {5, 146, 0x280, 0, 0x280, 0, 0x280, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9B48
unsigned int D_002B9B48[10] = {11, 146, 0x28c, 0, 0x28c, 0, 0x28c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9B70
unsigned int D_002B9B70[10] = {1, 146, 0x298, 0, 0x298, 0, 0x298, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9B98
unsigned int D_002B9B98[10] = {1, 146, 0x29c, 0, 0x29c, 0, 0x29c, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9BC0
unsigned int D_002B9BC0[10] = {1, 146, 0x2a0, 0, 0x2a0, 0, 0x2a0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9BE8
unsigned int D_002B9BE8[10] = {1, 146, 0x2a4, 0, 0x2a4, 0, 0x2a4, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9C10
void *D_002B9C10[10] = {(void *)0x1059, (void *)0x122, (void *)80, 0, (void *)0xffff0000, (void *)SetRhythmState, (void *)0xffff0000, (void *)SetRhythmState, 0, 0};

// data-ok: retail's bytes at 0X2B9C38
unsigned int D_002B9C38[10] = {1, 2, 0x284, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9C60
void *D_002B9C60[10] = {(void *)18, (void *)1, 0, 0, (void *)RefResetRhythmScore, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9C88
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9C88 = {
    "3 ",
    {2, 16, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9CB0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9CB0 = {
    "q ",
    {2, 48, 0, 0, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9CD8
void *D_002B9CD8[10] = {(void *)18, (void *)1, 0, 0, (void *)RefJumpGuardScript, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9D00
void *D_002B9D00[10] = {(void *)18, (void *)1, 0, 0, (void *)RefSendGuardNoticeMessage, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9D28
unsigned int D_002B9D28[10] = {0x105a, 146, 80, 0, 80, 0, 80, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9D50
void *D_002B9D50[10] = {(void *)18, (void *)0x400, (void *)RefAddWaypointNode, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9D78
unsigned int D_002B9D78[10] = {5, 146, 0x180, 0, 0x180, 0, 0x180, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9DA0
unsigned int D_002B9DA0[10] = {5, 146, 0x184, 0, 0x184, 0, 0x184, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9DC8
unsigned int D_002B9DC8[10] = {5, 146, 0x188, 0, 0x188, 0, 0x188, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9DF0
unsigned int D_002B9DF0[10] = {0x201e, 146, 0x190, 0, 0x190, 0, 0x190, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9E18
void *D_002B9E18[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSlot290, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9E40
void *D_002B9E40[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSlot298, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9E68
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9E68 = {
    "\011",
    {146, 0x1a0, 0, 0x1a0, 0, 0x1a0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9E90
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9E90 = {
    "\012",
    {146, 0x1b0, 0, 0x1b0, 0, 0x1b0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9EB8
void *D_002B9EB8[10] = {(void *)18, (void *)0x400, (void *)RefUseStepguardDeathAnimation, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9EE0
void *D_002B9EE0[10] = {(void *)18, (void *)0x400, (void *)RefCall1800D8, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9F08
struct {
    char m0[4];
    unsigned int m1[9];
} D_002B9F08 = {
    "~ ",
    {146, 0x2a0, 0, 0x2a0, 0, 0x2a0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2B9F30
unsigned int D_002B9F30[10] = {14, 146, 0x2a8, 0, 0x2a8, 0, 0x2a8, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9F58
void *D_002B9F58[10] = {(void *)18, (void *)0x400, (void *)RefChaser_SetStateAnim, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9F80
void *D_002B9F80[10] = {(void *)1, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001813C0, 0, 0};

// data-ok: retail's bytes at 0X2B9FA8
void *D_002B9FA8[10] = {(void *)1, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001813F0, 0, 0};

// data-ok: retail's bytes at 0X2B9FD0
unsigned int D_002B9FD0[10] = {0x2011, 146, 0x1d0, 0, 0x1d0, 0, 0x1d0, 0, 0, 0};

// data-ok: retail's bytes at 0X2B9FF8
unsigned int D_002B9FF8[10] = {0x2002, 146, 0x1d4, 0, 0x1d4, 0, 0x1d4, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA020
void *D_002BA020[10] = {(void *)18, (void *)0x401, (void *)RefChaser_SetStateDistanceRanges, 0, (void *)RefChaser_SetStateDistanceRanges, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA048
void *D_002BA048[10] = {(void *)18, (void *)0x401, (void *)RefChaser_SetStateAngleRanges, 0, (void *)RefChaser_SetStateAngleRanges, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA070
unsigned int D_002BA070[10] = {1, 146, 0x338, 0, 0x338, 0, 0x338, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA098
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA098 = {
    "\011",
    {146, 0x340, 0, 0x340, 0, 0x340, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA0C0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA0C0 = {
    "\011",
    {146, 0x350, 0, 0x350, 0, 0x350, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA0E8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA0E8 = {
    "\011",
    {146, 0x360, 0, 0x360, 0, 0x360, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA110
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA110 = {
    "\012",
    {146, 0x370, 0, 0x370, 0, 0x370, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA138
void *D_002BA138[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCall180478, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA160
unsigned int D_002BA160[10] = {0, 146, 0x1cc, 0, 0x1cc, 0, 0x1cc, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA188
unsigned int D_002BA188[10] = {1, 146, 0x1c4, 0, 0x1c4, 0, 0x1c4, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA1B0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA1B0 = {
    "0 ",
    {146, 0x1d0, 0, 0x1d0, 0, 0x1d0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA1D8
unsigned int D_002BA1D8[10] = {1, 146, 0x1d4, 0, 0x1d4, 0, 0x1d4, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA200
void *D_002BA200[10] = {(void *)18, (void *)0x400, (void *)RefGrab_SetStateAnim, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA228
void *D_002BA228[10] = {(void *)18, (void *)0x400, (void *)RefGrab_FAddRsmg, 0, 0, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA250
unsigned int D_002BA250[10] = {0x2003, 146, 0x1cc, 0, 0x1cc, 0, 0x1cc, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA278
void *D_002BA278[10] = {(void *)18, (void *)1, 0, 0, (void *)RefGrab_ReleasePlayer, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA2A0
void *D_002BA2A0[10] = {(void *)18, (void *)1, 0, 0, (void *)RefGrab_Trigger, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA2C8
unsigned int D_002BA2C8[10] = {0x2002, 146, 0x1c0, 0, 0x1c0, 0, 0x1c0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA2F0
void *D_002BA2F0[10] = {(void *)18, (void *)0x400, (void *)RefSwarm_AddGroup, 0, 0, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA318
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA318 = {
    "0 ",
    {146, 0x1c4, 0, 0x1c4, 0, 0x1c4, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA340
unsigned int D_002BA340[10] = {0x103c, 18, 36, 0, 36, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA368
unsigned int D_002BA368[10] = {0x103c, 18, 40, 0, 40, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA390
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA390 = {
    "\012",
    {18, 64, 0, 64, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA3B8
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA3B8 = {
    "\011",
    {18, 80, 0, 80, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA3E0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA3E0 = {
    "\012",
    {18, 96, 0, 96, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA408
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA408 = {
    "\012",
    {18, 72, 0, 72, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA430
unsigned int D_002BA430[10] = {1, 18, 104, 0, 104, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA458
unsigned int D_002BA458[10] = {1, 2, 116, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA480
unsigned int D_002BA480[10] = {1, 2, 120, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA4A8
unsigned int D_002BA4A8[10] = {0x1064, 18, 128, 0, 128, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA4D0
unsigned int D_002BA4D0[10] = {1, 18, 124, 0, 124, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA4F8
unsigned int D_002BA4F8[10] = {0x2016, 18, 132, 0, 132, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA520
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA520 = {
    "\012",
    {18, 136, 0, 136, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA548
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA548 = {
    "\012",
    {18, 144, 0, 144, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA570
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA570 = {
    "\012",
    {18, 152, 0, 152, 0, 0, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA598
unsigned int D_002BA598[10] = {0, 2, 160, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA5C0
unsigned int D_002BA5C0[10] = {0x1065, 18, 108, 0, 108, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA5E8
unsigned int D_002BA5E8[10] = {5, 18, 112, 0, 112, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA610
void *D_002BA610[10] = {(void *)18, (void *)1, 0, 0, (void *)RefSpendVehicleGunAmmo, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA638
void *D_002BA638[10] = {(void *)18, (void *)0x400, (void *)RefAddVehicleWheel, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA660
void *D_002BA660[10] = {(void *)18, (void *)0x400, (void *)RefAddVehicleGun, 0, 0, 0, (void *)4, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA688
void *D_002BA688[10] = {(void *)18, (void *)0x400, (void *)RefAddVehicleAxle, 0, 0, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA6B0
void *D_002BA6B0[10] = {(void *)0x2099, (void *)1, 0, 0, (void *)RefPgunFindVehicleGun, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA6D8
unsigned int D_002BA6D8[10] = {0x2002, 146, 0x5a4, 0, 0x5a4, 0, 0x5a4, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA700
unsigned int D_002BA700[10] = {0x2011, 146, 0x5a8, 0, 0x5a8, 0, 0x5a8, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA728
void *D_002BA728[10] = {(void *)0x1063, (void *)34, (void *)0x180, 0, (void *)0xffff0000, (void *)SetVehicleState, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA750
unsigned int D_002BA750[10] = {5, 130, 0x55c, 0, 0, 0, 0x55c, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA778
unsigned int D_002BA778[10] = {5, 2, 0x560, 0, 0, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA7A0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA7A0 = {
    "~ ",
    {146, 0x568, 0, 0x568, 0, 0x568, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA7C8
unsigned int D_002BA7C8[10] = {0, 146, 0x564, 0, 0x564, 0, 0x564, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA7F0
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA7F0 = {
    "o ",
    {146, 0x56c, 0, 0x56c, 0, 0x56c, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA818
void *D_002BA818[10] = {(void *)5, (void *)1, 0, 0, (void *)RefCAmmoVehicle, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA840
void *D_002BA840[10] = {(void *)18, (void *)1, 0, 0, (void *)RefSetVehicleAmmo, 0, (void *)2, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA868
void *D_002BA868[10] = {(void *)18, (void *)0x400, (void *)RefSetVehicleAmmoType, 0, 0, 0, (void *)3, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA890
unsigned int D_002BA890[10] = {14, 146, 0x59c, 0, 0x59c, 0, 0x59c, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA8B8
unsigned int D_002BA8B8[10] = {0x1065, 146, 0x158, 0, 0x158, 0, 0x158, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA8E0
unsigned int D_002BA8E0[10] = {5, 146, 0x15c, 0, 0x15c, 0, 0x15c, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA908
struct {
    char m0[4];
    unsigned int m1[9];
} D_002BA908 = {
    "o ",
    {146, 0x160, 0, 0x160, 0, 0x160, 0, 0, 0}
};

// data-ok: retail's bytes at 0X2BA930
void *D_002BA930[10] = {(void *)18, (void *)1, 0, 0, (void *)RefCallSlot2D0, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA958
unsigned int D_002BA958[10] = {5, 146, 0x1f0, 0, 0x1f0, 0, 0x1f0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA980
unsigned int D_002BA980[10] = {16, 146, 0x1f4, 0, 0x1f4, 0, 0x1f4, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA9A8
unsigned int D_002BA9A8[10] = {16, 146, 0x1f8, 0, 0x1f8, 0, 0x1f8, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA9D0
unsigned int D_002BA9D0[10] = {0x1049, 146, 0x200, 0, 0x200, 0, 0x200, 0, 0, 0};

// data-ok: retail's bytes at 0X2BA9F8
unsigned int D_002BA9F8[10] = {16, 146, 0x1fc, 0, 0x1fc, 0, 0x1fc, 0, 0, 0};

// data-ok: retail's bytes at 0X2BAA20
void *D_002BAA20[10] = {(void *)18, (void *)1, 0, 0, (void *)RefStartKeypad, 0, (void *)1, 0, 0, 0};

// data-ok: retail's bytes at 0X2BAA48
unsigned int D_002BAA48[10] = {0x106c, 146, 224, 0, 224, 0, 224, 0, 0, 0};

// data-ok: retail's bytes at 0X2BAA70
unsigned int D_002BAA70[10] = {0x106e, 146, 0x120, 0, 0x120, 0, 0x120, 0, 0, 0};

// data-ok: retail's bytes at 0X2BAA98
void *D_002BAA98[10] = {(void *)0x2002, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001C20E8, 0, 0};

// data-ok: retail's bytes at 0X2BAAC0
void *D_002BAAC0[10] = {(void *)2, (void *)0x100, 0, 0, 0, 0, (void *)0xffff0000, (void *)func_001C2148, 0, 0};
