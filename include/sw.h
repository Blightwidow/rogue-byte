/* SPDX-License-Identifier: GPL-3.0-or-later */
/* SW, the world: class 1 of retail's class table (0x2BAAE8, config/recovered/class_diff.tsv), 0x4790 bytes, derived from the
   root class (include/lo.h BASIC). The game keeps one, a static global at 0x3DD490 (B_003DD490), and passes its address to the
   *Sw* functions. Sly 1's SW derives from LO; Sly 2's does not, and its layout is its own: every field below comes from Sly 2's
   matched code (docs/ROADMAP.md "Next", item 1).

   A field is here when a matched function reads it at that offset through the global or a *Sw* function's argument (the
   class is then certain, so one reader is enough) and no matched function reads the offset as another type; the readers are
   listed. The save paths are named after the strings retail passes to PsavepathNew for each (CreateSwSavePaths). C++ only. */
#ifndef SLY2_SW_H
#define SLY2_SW_H
#include "lo.h"
#include "dl.h"

struct BLOCK;
struct TIMEDCALL;
struct JOB;
struct TASK;
struct OBR;
struct PO;
struct CLONESET;
struct PRIPG;
struct BSPNODE;
struct TARGET;
struct SAVEPATH;
struct CB;
struct SWNODE;
struct PZGRAPH;

/* A level load request (SetSwLoadRequest copies one, 0x4C bytes, into the world). func_00165280 and func_0020E180 test and set
   bits 4 and 8 of its first word; func_00165280 also writes 0x44 and 0x48. */
struct LOADREQ {
    /* 0x00 */ s32 grf;      /* signed: func_00165280 clears bit 8 with an addiu of -9 */
    u8 unknown_0x4[0x40];
    /* 0x44 */ s32 field_0x44;
    /* 0x48 */ s32 field_0x48;
};

/* An entry of the world's table at 0x3F14: flags and an object (AddSwGrfEntry adds one; SolveSw and func_001CDA80 walk them and
   call LO slots 17 and 19 on the object). */
struct GRFENTRY {
    u32 grf;
    struct LO *plo;
};

/* A slot heap: a pool of same-sized slots (Sly 1's name, sly1 include/slotheap.h, CC0). Sly 2's is 0x18 bytes: the world keeps
   pairs of them back to back (slotheapRipg 0x403C and slotheapRip 0x4054, PripgNew and PripNewRipg), and a field follows
   each one 0x18 bytes on (pcbFirst after the callbacks' heap at 0x3C90, dlWkr after slotheapWkr). PblipgNew reads two fields
   of the blip groups' heap before it allocates: no free slot and a fixed size means no new group. */
struct SLOTHEAP {
    u8 unknown_0x0[0xC];
    /* 0x0C */ void *pslotFree;       /* PblipgNew */
    u8 unknown_0x10[0x4];
    /* 0x14 */ s32 cslotMax;          /* PblipgNew: nonzero when the heap may not grow */
};

struct SW : BASIC {
    u8 unknown_0x10[0x140];
    /* 0x150 */ s32 state; /* FUpdateSwDuringWipe */
    u8 unknown_0x154[0x3894];
    /* 0x39E8 */ struct BLOCK *pblockCur; /* func_001FFA40 */
    u8 unknown_0x39EC[0x4];
    /* 0x39F0 */ struct TIMEDCALL *ptimedcallFirst; /* the pending timed calls, func_00133130 */
    u8 unknown_0x39F4[0x8];
    /* 0x39FC */ SLOTHEAP slotheapTimedcall; /* their slot heap, func_00133130 */
    u8 unknown_0x3A14[0xE8];
    /* 0x3AFC */ s32 ctask; /* objects of class 0x85: func_00161660, func_001620B0, func_00162250, func_00165C98 */
    u8 unknown_0x3B00[0xC];
    /* 0x3B0C */ struct JOB *pjobCurrent; /* SetSwCurrentJob; func_001619A0, func_001649D0, func_0019D948 */
    /* 0x3B10 */ struct TASK *ptaskCurrent; /* SetSwCurrentTask, func_00163C28 */
    /* 0x3B14 */ struct TASK *ptaskRestart; /* SetSwRestartTask, func_00162A60 */
    u8 unknown_0x3B18[0x4];
    /* 0x3B1C */ struct SAVEPATH *psavepathDt; /* save path "dt" (CreateSwSavePaths; the paths are PsavepathNew handles, passed on as int) */
    /* 0x3B20 */ struct SAVEPATH *psavepathCcoin; /* "loot/ccoin" */
    /* 0x3B24 */ struct SAVEPATH *psavepathWidCurrent; /* "widCurrent" */
    /* 0x3B28 */ struct SAVEPATH *psavepathEpisodeCurrent; /* "episodeCurrent" */
    /* 0x3B2C */ struct SAVEPATH *psavepathLang; /* "flags/lang"; ApplyOptionsFromSave reads 0x3B2C to 0x3B44 as the options */
    /* 0x3B30 */ struct SAVEPATH *psavepathMixerMode; /* "flags/nMixerMode" */
    /* 0x3B34 */ struct SAVEPATH *psavepathMusicVolume; /* "flags/uMusicVolume" */
    /* 0x3B38 */ struct SAVEPATH *psavepathEffectsVolume; /* "flags/uEffectsVolume" */
    /* 0x3B3C */ struct SAVEPATH *psavepathUseHeadset; /* "flags/fUseHeadset" */
    /* 0x3B40 */ struct SAVEPATH *psavepathDxScreenCenter; /* "flags/dxScreenCenter" */
    /* 0x3B44 */ struct SAVEPATH *psavepathDyScreenCenter; /* "flags/dyScreenCenter" */
    /* 0x3B48 */ struct SAVEPATH *psavepathNoVibration; /* "flags/fNoVibration" */
    /* 0x3B4C */ struct SAVEPATH *psavepathReverseLookAround; /* "flags/fReverseLookAround" */
    /* 0x3B50 */ struct SAVEPATH *psavepathReverseAim; /* "flags/fReverseAim" */
    /* 0x3B54 */ struct SAVEPATH *psavepathAutosaveWarned; /* "flags/fAutosaveWarned" */
    /* 0x3B58 */ struct SAVEPATH *apsavepathEpisodeDt[9]; /* "episode/<name>/dt" per episode */
    /* 0x3B7C */ struct SAVEPATH *apsavepathEpisodePercent[9]; /* "episode/<name>/percent_complete" per episode */
    u8 unknown_0x3BA0[0x4C];
    /* 0x3BEC */ s32 cblotActive; /* SetBlotBlots counts the blots of 16 frames or more that enter state 2 and up */
    /* 0x3BF0 */ s32 fLoadPending; /* SetSwLoadRequest sets it with the request */
    /* 0x3BF4 */ LOADREQ loadreq; /* SetSwLoadRequest copies one in whole */
    u8 unknown_0x3C40[0x48];
    /* 0x3C88 */ s32 field_0x3C88; /* func_00162A60 sets it to 0x189 when it restarts a task */
    /* 0x3C8C */ s32 field_0x3C8C; /* func_00162A60 sets it to -1 with 0x3C88 */
    /* 0x3C90 */ SLOTHEAP slotheapCb; /* the callbacks, func_00149B58 */
    /* 0x3CA8 */ struct CB *pcbFirst; /* func_00149B58 */
    /* 0x3CAC */ struct CB *pcbLast; /* func_00149B58 */
    u8 unknown_0x3CB0[0x1C];
    /* 0x3CCC */ s32 fAaoxDirty; /* UpdateSwAaox: tested and cleared before it sorts the object table */
    /* 0x3CD0 */ s32 cobr; /* PoxaAllocSw */
    /* 0x3CD4 */ struct OBR *aobr[3]; /* one per axis, PoxaAllocSw */
    u8 unknown_0x3CE0[0x3C];
    /* 0x3D1C */ struct SWNODE *pnodeFirst; /* func_001F8F80 and IntersectSwBoundingSphere walk the list through SWNODE::pnext (0x40) */
    u8 unknown_0x3D20[0x20];
    /* 0x3D40 */ SLOTHEAP slotheapMq; /* CloneMqList */
    /* 0x3D58 */ s32 generation; /* func_00190D10 increments it */
    /* 0x3D5C */ s32 frame; /* func_001CD9E0 compares an SO stamp with it */
    /* 0x3D60 */ s32 field_0x3D60; /* func_001CDA80 counts its runs */
    /* 0x3D64 */ s32 frameLast; /* func_001CDA80 copies frame here when the two differ */
    /* 0x3D68 */ s32 idHitfxLast; /* func_00156548 increments it for each new hit effect */
    u8 unknown_0x3D6C[0x4];
    /* 0x3D70 */ s32 stamp; /* func_001C1968 */
    u8 unknown_0x3D74[0x14];
    /* 0x3D88 */ DL dlAsega; /* UpdateSw walks it with UpdateAsega; Sw_Construct initialises it with ibDle 0x24 */
    u8 unknown_0x3D94[0xA4];
    /* 0x3E38 */ s32 field_0x3E38; /* AllocSwBuffers sets it when the load request has bit 0x20; UpdateCmLast, RestartAtTask test it */
    u8 unknown_0x3E3C[0x64];
    /* 0x3EA0 */ u64 gs; /* a GS register value, func_001EA9F0 */
    u8 unknown_0x3EA8[0x4];
    /* 0x3EAC */ void *pvjoyFirst; /* a list linked at 0x84: UpdateSw calls UpdateVjoy on each; Sw_Construct's InitSl gives the link */
    u8 unknown_0x3EB0[0x8];
    /* 0x3EB8 */ s32 clo; /* func_001C4AF8 */
    /* 0x3EBC */ struct LO *aplo[16]; /* func_001C4AF8; at most 16 (the focus follows at 0x3EFC) */
    /* 0x3EFC */ struct PO *ppoFocusBase; /* SetSwFocusBase, SetSwFocusOverride */
    /* 0x3F00 */ struct PO *ppoFocusOverride; /* SetSwFocusBase, SetSwFocusOverride */
    /* 0x3F04 */ s32 ccloneset; /* InitCloneSets */
    /* 0x3F08 */ struct CLONESET *acloneset; /* InitCloneSets, InstantiateClone */
    /* 0x3F0C */ struct SCOPE *pscopeDefault; /* used when the context object has none: RefOpFindObject, func_001241E8, func_00124578, RefOpFindNearestObject; AllocSwBuffers allocates it */
    /* 0x3F10 */ s32 field_0x3F10; /* Sw_Construct sets it to -2 */
    /* 0x3F14 */ s32 cgrfentry; /* AddSwGrfEntry, SolveSw, func_001CDA80 */
    /* 0x3F18 */ s32 cgrfentryDead; /* AddSwGrfEntry compacts the table when they pass a tenth */
    /* 0x3F1C */ s32 *pigrfentryRunning; /* the loop index of the walk in progress, which AddSwGrfEntry fixes up (SolveSw, func_001CDA80) */
    /* 0x3F20 */ GRFENTRY *agrfentry; /* AddSwGrfEntry, SolveSw, func_001CDA80 */
    u8 unknown_0x3F24[0xD8];
    /* 0x3FFC */ DL dlHitfx; /* func_00156548 */
    /* 0x4008 */ SLOTHEAP slotheapHitfx; /* func_00156548 */
    /* 0x4020 */ struct BASIC *phitfxdef; /* func_0017A7F8 hands it to PhitfxSpawn, whose Splice binding passes a BASIC */
    u8 unknown_0x4024[0x18];
    /* 0x403C */ SLOTHEAP slotheapRipg; /* PripgNew */
    /* 0x4054 */ SLOTHEAP slotheapRip; /* PripNewRipg */
    /* 0x406C */ struct PRIPG *pripgCached; /* PripgNew */
    /* 0x4070 */ SLOTHEAP slotheapBlipg; /* PblipgNew */
    u8 unknown_0x4088[0x90];
    /* 0x4118 */ SLOTHEAP slotheapWkr; /* ExpireSwWkrs */
    /* 0x4130 */ DL dlWkr; /* ExpireSwWkrs */
    u8 unknown_0x413C[0x41C];
    /* 0x4558 */ s32 cbspnode; /* func_0013E0E0 */
    /* 0x455C */ struct BSPNODE *abspnode; /* func_0013E0E0 */
    /* 0x4560 */ s32 cregion; /* func_0013E0E0 */
    /* 0x4564 */ void *aregion; /* func_0013E0E0 (0x20-byte elements) */
    u8 unknown_0x4568[0x64];
    /* 0x45CC */ struct PZGRAPH *ppzgraph; /* AddSoLoHierarchy */
    u8 unknown_0x45D0[0x68];
    /* 0x4638 */ void *ppool; /* func_0013CF38 */
    u8 unknown_0x463C[0x4];
    /* 0x4640 */ s32 field_0x4640; /* func_00210BE0, func_00211EC0 test it */
    u8 unknown_0x4644[0x104];
    /* 0x4748 */ s32 fGuardsFrozen; /* SetSwGuardsFrozen */
    /* 0x474C */ f32 tGuardsFrozen; /* SetSwGuardsFrozen */
    u8 unknown_0x4750[0x4];
    /* 0x4754 */ f32 tL3; /* func_00140338 */
    u8 unknown_0x4758[0x4];
    /* 0x475C */ f32 sTimeScale; /* StartSwAmbSfx adds it to the pitch */
    u8 unknown_0x4760[0x14];
    /* 0x4774 */ struct TARGET *ptarget; /* func_0015DA88 */
    u8 unknown_0x4778[0x18];
};

#if defined(__mips__)
SLY2_SIZE_CHECK(SLOTHEAP, 0x18);
SLY2_SIZE_CHECK(LOADREQ, 0x4C);
SLY2_SIZE_CHECK(GRFENTRY, 0x8);
SLY2_SIZE_CHECK(SW, 0x4790);
SLY2_OFFSET_CHECK(SW, state, 0x150);
SLY2_OFFSET_CHECK(SW, pblockCur, 0x39E8);
SLY2_OFFSET_CHECK(SW, fAaoxDirty, 0x3CCC);
SLY2_OFFSET_CHECK(SW, ptimedcallFirst, 0x39F0);
SLY2_OFFSET_CHECK(SW, slotheapTimedcall, 0x39FC);
SLY2_OFFSET_CHECK(SW, ctask, 0x3AFC);
SLY2_OFFSET_CHECK(SW, pjobCurrent, 0x3B0C);
SLY2_OFFSET_CHECK(SW, ptaskCurrent, 0x3B10);
SLY2_OFFSET_CHECK(SW, ptaskRestart, 0x3B14);
SLY2_OFFSET_CHECK(SW, psavepathDt, 0x3B1C);
SLY2_OFFSET_CHECK(SW, psavepathCcoin, 0x3B20);
SLY2_OFFSET_CHECK(SW, psavepathWidCurrent, 0x3B24);
SLY2_OFFSET_CHECK(SW, psavepathEpisodeCurrent, 0x3B28);
SLY2_OFFSET_CHECK(SW, psavepathLang, 0x3B2C);
SLY2_OFFSET_CHECK(SW, psavepathMixerMode, 0x3B30);
SLY2_OFFSET_CHECK(SW, psavepathMusicVolume, 0x3B34);
SLY2_OFFSET_CHECK(SW, psavepathEffectsVolume, 0x3B38);
SLY2_OFFSET_CHECK(SW, psavepathUseHeadset, 0x3B3C);
SLY2_OFFSET_CHECK(SW, psavepathDxScreenCenter, 0x3B40);
SLY2_OFFSET_CHECK(SW, psavepathDyScreenCenter, 0x3B44);
SLY2_OFFSET_CHECK(SW, psavepathNoVibration, 0x3B48);
SLY2_OFFSET_CHECK(SW, psavepathReverseLookAround, 0x3B4C);
SLY2_OFFSET_CHECK(SW, psavepathReverseAim, 0x3B50);
SLY2_OFFSET_CHECK(SW, psavepathAutosaveWarned, 0x3B54);
SLY2_OFFSET_CHECK(SW, apsavepathEpisodeDt, 0x3B58);
SLY2_OFFSET_CHECK(SW, apsavepathEpisodePercent, 0x3B7C);
SLY2_OFFSET_CHECK(SW, cblotActive, 0x3BEC);
SLY2_OFFSET_CHECK(SW, fLoadPending, 0x3BF0);
SLY2_OFFSET_CHECK(SW, loadreq, 0x3BF4);
SLY2_OFFSET_CHECK(SW, field_0x3C88, 0x3C88);
SLY2_OFFSET_CHECK(SW, field_0x3C8C, 0x3C8C);
SLY2_OFFSET_CHECK(SW, slotheapCb, 0x3C90);
SLY2_OFFSET_CHECK(SW, pcbFirst, 0x3CA8);
SLY2_OFFSET_CHECK(SW, pcbLast, 0x3CAC);
SLY2_OFFSET_CHECK(SW, cobr, 0x3CD0);
SLY2_OFFSET_CHECK(SW, aobr, 0x3CD4);
SLY2_OFFSET_CHECK(SW, pnodeFirst, 0x3D1C);
SLY2_OFFSET_CHECK(SW, slotheapMq, 0x3D40);
SLY2_OFFSET_CHECK(SW, generation, 0x3D58);
SLY2_OFFSET_CHECK(SW, frame, 0x3D5C);
SLY2_OFFSET_CHECK(SW, field_0x3D60, 0x3D60);
SLY2_OFFSET_CHECK(SW, frameLast, 0x3D64);
SLY2_OFFSET_CHECK(SW, idHitfxLast, 0x3D68);
SLY2_OFFSET_CHECK(SW, stamp, 0x3D70);
SLY2_OFFSET_CHECK(SW, field_0x3E38, 0x3E38);
SLY2_OFFSET_CHECK(SW, dlAsega, 0x3D88);
SLY2_OFFSET_CHECK(SW, gs, 0x3EA0);
SLY2_OFFSET_CHECK(SW, pvjoyFirst, 0x3EAC);
SLY2_OFFSET_CHECK(SW, clo, 0x3EB8);
SLY2_OFFSET_CHECK(SW, aplo, 0x3EBC);
SLY2_OFFSET_CHECK(SW, ppoFocusBase, 0x3EFC);
SLY2_OFFSET_CHECK(SW, ppoFocusOverride, 0x3F00);
SLY2_OFFSET_CHECK(SW, ccloneset, 0x3F04);
SLY2_OFFSET_CHECK(SW, acloneset, 0x3F08);
SLY2_OFFSET_CHECK(SW, pscopeDefault, 0x3F0C);
SLY2_OFFSET_CHECK(SW, field_0x3F10, 0x3F10);
SLY2_OFFSET_CHECK(SW, cgrfentry, 0x3F14);
SLY2_OFFSET_CHECK(SW, cgrfentryDead, 0x3F18);
SLY2_OFFSET_CHECK(SW, pigrfentryRunning, 0x3F1C);
SLY2_OFFSET_CHECK(SW, agrfentry, 0x3F20);
SLY2_OFFSET_CHECK(SW, dlHitfx, 0x3FFC);
SLY2_OFFSET_CHECK(SW, slotheapHitfx, 0x4008);
SLY2_OFFSET_CHECK(SW, phitfxdef, 0x4020);
SLY2_OFFSET_CHECK(SW, slotheapRipg, 0x403C);
SLY2_OFFSET_CHECK(SW, slotheapRip, 0x4054);
SLY2_OFFSET_CHECK(SW, pripgCached, 0x406C);
SLY2_OFFSET_CHECK(SW, slotheapBlipg, 0x4070);
SLY2_OFFSET_CHECK(SW, slotheapWkr, 0x4118);
SLY2_OFFSET_CHECK(SW, dlWkr, 0x4130);
SLY2_OFFSET_CHECK(SW, cbspnode, 0x4558);
SLY2_OFFSET_CHECK(SW, abspnode, 0x455C);
SLY2_OFFSET_CHECK(SW, cregion, 0x4560);
SLY2_OFFSET_CHECK(SW, aregion, 0x4564);
SLY2_OFFSET_CHECK(SW, ppzgraph, 0x45CC);
SLY2_OFFSET_CHECK(SW, ppool, 0x4638);
SLY2_OFFSET_CHECK(SW, field_0x4640, 0x4640);
SLY2_OFFSET_CHECK(SW, fGuardsFrozen, 0x4748);
SLY2_OFFSET_CHECK(SW, tGuardsFrozen, 0x474C);
SLY2_OFFSET_CHECK(SW, tL3, 0x4754);
SLY2_OFFSET_CHECK(SW, sTimeScale, 0x475C);
SLY2_OFFSET_CHECK(SW, ptarget, 0x4774);
#endif
#endif
