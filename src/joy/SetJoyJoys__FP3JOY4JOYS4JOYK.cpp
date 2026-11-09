// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"

struct RANGE {
    f32 min; // 0x0
    f32 max; // 0x4
};

struct RUMBLE;

struct JOY {
    char pad0[0x1000];
    s32 port;              // 0x1000
    s32 slot;              // 0x1004
    s32 field1008;         // 0x1008
    s32 joys;              // 0x100C
    s32 joyk;              // 0x1010
    f32 tJoys;             // 0x1014
    s32 field1018;         // 0x1018
    char pad101C[0x8];
    s32 field1024;         // 0x1024
    s32 field1028;         // 0x1028
    char pad102C[0x10];
    f32 field103C;         // 0x103C
    f32 field1040;         // 0x1040
    f32 field1044;         // 0x1044
    char pad1048[0x4];
    s32 field104C;         // 0x104C
    RANGE rangeLeft[4];    // 0x1050
    f32 field1070;         // 0x1070
    f32 field1074;         // 0x1074
    f32 field1078;         // 0x1078
    char pad107C[0x4];
    s32 field1080;         // 0x1080
    RANGE rangeRight[4];   // 0x1084
    f32 field10A4;         // 0x10A4
    f32 field10A8;         // 0x10A8
    f32 field10AC;         // 0x10AC
    f32 field10B0;         // 0x10B0
    s32 field10B4;         // 0x10B4
    s32 field10B8;         // 0x10B8
    s32 field10BC;         // 0x10BC
    char pressure[0xC];    // 0x10C0
    char rumble[0x1C];     // 0x10CC
};

struct CLOCK {
    char pad[0x3C];
    f32 tReal; // 0x3C
};

extern "C" {
void InitRumble__FP6RUMBLEii(RUMBLE *, int, int);
void *memset(void *, int, unsigned int);
extern CLOCK g_2dded0;
}

// Retail: the four running pointers of the reset loop (0x1084, 0x1050, 0x1088, 0x1054, stride 8) are set up after the
// hoisted `lui %hi(g_2dded0)`, i.e. they come from loop.c strength reduction of an indexed loop over two arrays of
// {min, max} pairs, not from pointers in the source; the counter stays (`sltiu`, unsigned) for the exit test.
// The float zeros are `swc1` of one `mtc1 $zero` register, not `sw $zero`: chained assignments (the value of each
// inner assignment feeds the next store) give that; separate `= 0.0f` stores become `sw $zero`.
extern "C" void SetJoyJoys__FP3JOY4JOYS4JOYK(JOY *pjoy, s32 joys, s32 joyk)
{
    if (joys == pjoy->joys && joyk == pjoy->joyk)
        return;
    if (joyk == 0) {
        pjoy->field1008 = 0;
        joys = 1;
    }
    if (pjoy->joyk < 3 && joyk >= 3)
        InitRumble__FP6RUMBLEii((RUMBLE *)pjoy->rumble, pjoy->port, pjoy->slot);
    if ((pjoy->joyk == 4) ? (joyk != 4) : (joyk == 4))
        memset(pjoy->pressure, 0, sizeof(pjoy->pressure));
    if ((pjoy->joys == 3) ? (joys != 3) : (joys == 3)) {
        pjoy->field1018 = 0;
        pjoy->field1080 = 0;
        pjoy->field104C = 0;
        pjoy->field10B8 = 0;
        pjoy->field10B4 = 0;
        pjoy->field10BC = 0xFFFF;
        memset(pjoy->pressure, 0, sizeof(pjoy->pressure));
        pjoy->field1028 = 0;
        pjoy->field103C = pjoy->field1040 = pjoy->field1044 = 0.0f;
        pjoy->field1070 = pjoy->field1074 = pjoy->field1078 = 0.0f;
        pjoy->field10A4 = pjoy->field10A8 = 0.0f;
        pjoy->field10AC = pjoy->field10B0 = 0.0f;
        pjoy->field1024 = 0;
        for (unsigned int iAxis = 0; iAxis < 4; iAxis++) {
            pjoy->rangeRight[iAxis].min = -0.75f;
            pjoy->rangeLeft[iAxis].min = -0.75f;
            pjoy->rangeRight[iAxis].max = 0.75f;
            pjoy->rangeLeft[iAxis].max = 0.75f;
        }
    }
    pjoy->joys = joys;
    pjoy->joyk = joyk;
    pjoy->tJoys = g_2dded0.tReal;
}
