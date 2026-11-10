/* SPDX-License-Identifier: GPL-3.0-or-later */
/* GOAL, one step of an actor's behaviour: class 155 of retail's class table, 0x30 bytes, derived from the root BASIC
   (include/lo.h), the other branch beside LO. Its vtable (0x2D9480) adds slots 7 to 14; about fifty classes derive from it
   (156 GoalBrain, 157 GoalAnim, 160 GoalHit and others, 0x30 to 0xE0 bytes). The slots are named after what the subclasses put
   there (GoalBrain_Init, GoalHit_Activate, Goal_Deactivate, GoalBrain_Update, Goal_FHandleMessage, Goal_FillVjoy). A field here
   is read or set by one of GOAL's own methods or by two other readers that agree. C++ only. */
#ifndef SLY2_GOAL_H
#define SLY2_GOAL_H
#include "lo.h"

struct STEP;

struct GOAL : BASIC {
    virtual void Init();                /*  7: func_001EEF68 (empty); GoalBrain_Init */
    virtual void Activate();            /*  8: func_001EEF70 (empty); GoalBrain_Activate, GoalHit_Activate */
    virtual void Deactivate();          /*  9: Goal_Deactivate */
    virtual void Update();              /* 10: func_001EEF98 (empty); GoalBrain_Update, GoalHit_Update */
    virtual void Slot11();              /* 11: func_001EEFB8 (empty) */
    virtual void Slot12();              /* 12: func_001EEFA0 */
    virtual void FHandleMessage();      /* 13: Goal_FHandleMessage */
    virtual void FillVjoy();            /* 14: Goal_FillVjoy */
    /* 0x10 */ struct STEP *pstep;      /* the actor: Goal_FillVjoy (14) reads its heading (STEP 0x1A8), func_001EEFA0 (12) its 0x204 */
    u8 unknown_0x14[0x4];
    /* 0x18 */ struct GOAL *pgoalChild; /* Goal_Deactivate (9) pops it; GoalGotoPos_SetPos and others read it */
    u8 unknown_0x1C[0x14];
};

#if defined(__mips__)
SLY2_SIZE_CHECK(GOAL, 0x30);
SLY2_OFFSET_CHECK(GOAL, pstep, 0x10);
SLY2_OFFSET_CHECK(GOAL, pgoalChild, 0x18);
#endif
#endif
