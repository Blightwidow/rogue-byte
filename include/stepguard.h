/* SPDX-License-Identifier: GPL-3.0-or-later */
/* STEPGUARD, a guard: class 56 of retail's class table, 0x1010 bytes, derived from STEP (include/step.h). Like JT it has no vtable
   of its own in the table; its eleven subclasses (57 to 67, 0x1010 to 0x10A0 bytes) share its methods: HandleStepguardMessage (5),
   func_002064D8 (12), PostGuardLoad (15), UpdateGuard (16), RemoveStepguardHierarchy (22), AddStepguardHierarchy (23),
   OnGuardAdd (26), OnGuardRemove (27), CloneGuard (41), func_00206380 (61), FAbsorbGuardWkr (75), FIsGuardInvulnerable (76),
   NGuardAlertLevel (77), GrfGuardCustomXps (85), FIsGuardWkrLethal (86), func_001F1F38 (87), and two slots of its own (88, 89).
   Sly 1 names the class STEPGUARD (sly1 include/stepguard.h, CC0), and so do the names recovered from it. A field here is read or set by one of those methods (slot given) or by
   two other readers that agree. C++ only. */
#ifndef SLY2_STEPGUARD_H
#define SLY2_STEPGUARD_H
#include "step.h"

struct HOME;
struct SENSOR;
struct RIGOBJ;

struct STEPGUARD : STEP {
    virtual void Slot88();              /* 88: func_002082D0 */
    virtual void Slot89();              /* 89: func_00208BE0 */
    /* 0x2C0 */ u64 grfsgs; /* GrfGuardCustomXps (85); NGuardAlertLevel (77), func_001F1900 */
    u8 unknown_0x2C8[0x20];
    /* 0x2E8 */ s32 field_0x2E8; /* OnGuardRemove (27) */
    /* 0x2EC */ struct LO *field_0x2EC; /* PostGuardLoad (15) */
    /* 0x2F0 */ struct HOME *phome; /* OnGuardAdd (26), PostGuardLoad (15) */
    u8 unknown_0x2F4[0xC];
    /* 0x300 */ QW posHome; /* OnGuardAdd (26) */
    /* 0x310 */ f32 radHome; /* OnGuardAdd (26) */
    u8 unknown_0x314[0x1C];
    /* 0x330 */ s32 field_0x330; /* OnGuardRemove (27) */
    u8 unknown_0x334[0x4];
    /* 0x338 */ s32 field_0x338; /* OnGuardAdd (26); FIsGuardWkrLethal (86) */
    /* 0x33C */ s32 field_0x33C; /* OnGuardAdd (26) */
    /* 0x340 */ s32 field_0x340; /* OnGuardAdd (26) */
    /* 0x344 */ s32 field_0x344; /* OnGuardAdd (26) */
    u8 unknown_0x348[0x18];
    /* 0x360 */ f32 field_0x360; /* OnGuardRemove (27) */
    u8 unknown_0x364[0x2C];
    /* 0x390 */ s32 field_0x390; /* OnGuardRemove (27) */
    u8 unknown_0x394[0x60];
    /* 0x3F4 */ struct LO *field_0x3F4; /* PostGuardLoad (15) */
    /* 0x3F8 */ struct LO *field_0x3F8; /* PostGuardLoad (15) */
    u8 unknown_0x3FC[0x88];
    /* 0x484 */ s32 cguardact; /* func_001F1900 and func_001F1CF8 (two readers) */
    u8 unknown_0x488[0xC];
    /* 0x494 */ struct RIGOBJ *prig; /* OnGuardAdd (26); func_001F1900, func_001F1CF8, func_001F17F8 */
    /* 0x498 */ void *field_0x498; /* PostGuardLoad (15), OnGuardAdd (26) */
    /* 0x49C */ void *field_0x49C; /* PostGuardLoad (15), OnGuardAdd (26), HandleStepguardMessage (5) */
    u8 unknown_0x4A0[0x9C8];
    /* 0xE68 */ s32 field_0xE68; /* func_00208BE0 (89) */
    u8 unknown_0xE6C[0xC];
    /* 0xE78 */ s32 field_0xE78; /* OnGuardAdd (26) */
    u8 unknown_0xE7C[0x8];
    /* 0xE84 */ s32 field_0xE84; /* OnGuardAdd (26) */
    /* 0xE88 */ s32 field_0xE88; /* OnGuardAdd (26) */
    u8 unknown_0xE8C[0xD8];
    /* 0xF64 */ struct SENSOR *psensor; /* OnGuardAdd (26), func_00208BE0 (89), CloneGuard (41) */
    u8 unknown_0xF68[0x5C];
    /* 0xFC4 */ void *field_0xFC4; /* PostGuardLoad (15) */
    u8 unknown_0xFC8[0x8];
    /* 0xFD0 */ void *field_0xFD0; /* GrfGuardCustomXps (85); OnGuardAdd passes its address */
    u8 unknown_0xFD4[0x14];
    /* 0xFE8 */ u32 grf; /* OnGuardAdd (26); func_0017D450, func_0017D6C8 */
    /* 0xFEC */ struct LO *field_0xFEC; /* OnGuardAdd (26) */
    u8 unknown_0xFF0[0x8];
    /* 0xFF8 */ f32 field_0xFF8; /* AddStepguardHierarchy (23), RemoveStepguardHierarchy (22) */
    u8 unknown_0xFFC[0x14];
};

#if defined(__mips__)
SLY2_SIZE_CHECK(STEPGUARD, 0x1010);
SLY2_OFFSET_CHECK(STEPGUARD, grfsgs, 0x2C0);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x2E8, 0x2E8);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x2EC, 0x2EC);
SLY2_OFFSET_CHECK(STEPGUARD, phome, 0x2F0);
SLY2_OFFSET_CHECK(STEPGUARD, posHome, 0x300);
SLY2_OFFSET_CHECK(STEPGUARD, radHome, 0x310);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x330, 0x330);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x338, 0x338);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x33C, 0x33C);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x340, 0x340);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x344, 0x344);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x360, 0x360);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x390, 0x390);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x3F4, 0x3F4);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x3F8, 0x3F8);
SLY2_OFFSET_CHECK(STEPGUARD, cguardact, 0x484);
SLY2_OFFSET_CHECK(STEPGUARD, prig, 0x494);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x498, 0x498);
SLY2_OFFSET_CHECK(STEPGUARD, field_0x49C, 0x49C);
SLY2_OFFSET_CHECK(STEPGUARD, field_0xE68, 0xE68);
SLY2_OFFSET_CHECK(STEPGUARD, field_0xE78, 0xE78);
SLY2_OFFSET_CHECK(STEPGUARD, field_0xE84, 0xE84);
SLY2_OFFSET_CHECK(STEPGUARD, field_0xE88, 0xE88);
SLY2_OFFSET_CHECK(STEPGUARD, psensor, 0xF64);
SLY2_OFFSET_CHECK(STEPGUARD, field_0xFC4, 0xFC4);
SLY2_OFFSET_CHECK(STEPGUARD, field_0xFD0, 0xFD0);
SLY2_OFFSET_CHECK(STEPGUARD, grf, 0xFE8);
SLY2_OFFSET_CHECK(STEPGUARD, field_0xFEC, 0xFEC);
SLY2_OFFSET_CHECK(STEPGUARD, field_0xFF8, 0xFF8);
#endif
#endif
