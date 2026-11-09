// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
extern "C" {
struct Jt { char pad0[0x1308]; f32 powerFraction; };
int GetJtPower(f32);
void SetJtPower(Jt *, s32);
extern f32 g_2dded4;
void DrainJtPower(Jt *jt, f32 amount) {
    f32 scaled = amount * g_2dded4;
    f32 total = jt->powerFraction + scaled;
    s32 whole = (s32)total;
    jt->powerFraction = total;
    if (whole != 0) {
        jt->powerFraction = total - (f32)whole;
        s32 remaining = GetJtPower(scaled) - whole;
        SetJtPower(jt, (remaining > -1) ? remaining : 0);
    }
}
}
