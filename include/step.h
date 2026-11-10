/* SPDX-License-Identifier: GPL-3.0-or-later */
/* STEP, a walking object: class 51 of retail's class table, 0x2C0 bytes, derived from PO (include/po.h). Its vtable adds slots
   82 to 87 and holds InitStep (7), LoadStepFromBrx (14), UpdateStep (16), TranslateStepToPos (29), CloneStep (41),
   AdjustStepNewXp (55), PresetStepAccel (70). Named after those functions and Sly 1's STEP (sly1 include/step.h, CC0). Its fields
   are read by methods of JT (include/jt.h), which derives from it, or by two other readers. C++ only. */
#ifndef SLY2_STEP_H
#define SLY2_STEP_H
#include "po.h"

struct STEP : PO {
    virtual void Slot82();              /* 82: func_00205008, func_00140C30 (JT) */
    virtual void RetainSmKinds();       /* 83: RetainAloSmKinds, JT_RetainSmKinds */
    virtual void ReleaseSmKinds();      /* 84: ReleaseAloSmKinds, JT_ReleaseSmKinds */
    virtual void Slot85();              /* 85: func_002040F8, func_00143C78 (JT) */
    virtual void FLethalHit();          /* 86: func_00205D08, JT_FLethalHit */
    virtual void Slot87();              /* 87: func_00205D10 */
    u8 unknown_0x180[0x28];
    /* 0x1A8 */ f32 radHeading; /* ChooseJtSweepTarget, UpdateBinocHud (two readers) */
    u8 unknown_0x1AC[0x58];
    /* 0x204 */ s32 field_0x204; /* func_00143C78 (JT slot 85) */
    /* 0x208 */ struct SO *psoSurface; /* what it stands on: func_00141588 (JT slot 97), UpdateJtStand */
    u8 unknown_0x20C[0x2C];
    /* 0x238 */ f32 field_0x238; /* func_00141588 */
    u8 unknown_0x23C[0xC];
    /* 0x248 */ f32 field_0x248; /* func_00141588 */
    u8 unknown_0x24C[0x24];
    /* 0x270 */ s32 field_0x270; /* UpdateJt (JT slot 16) */
    u8 unknown_0x274[0x4C];
};

#if defined(__mips__)
SLY2_SIZE_CHECK(STEP, 0x2C0);
SLY2_OFFSET_CHECK(STEP, radHeading, 0x1A8);
SLY2_OFFSET_CHECK(STEP, field_0x204, 0x204);
SLY2_OFFSET_CHECK(STEP, psoSurface, 0x208);
SLY2_OFFSET_CHECK(STEP, field_0x238, 0x238);
SLY2_OFFSET_CHECK(STEP, field_0x248, 0x248);
SLY2_OFFSET_CHECK(STEP, field_0x270, 0x270);
#endif
#endif
