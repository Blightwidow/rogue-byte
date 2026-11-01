// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT1C5E48 { char pad[0x260]; short delta; short index; void (*fn)(void *, int); };
struct LO1C5E48 { char pad[0xC]; VT1C5E48 *vt; };
struct DPRIZE1C5E48 {
    char pad0[0xC]; VT1C5E48 *vt; char pad1[0x150 - 0x10];
    unsigned state; float startTime; char pad2[0x188 - 0x158];
    float timer; char pad3[0x1C4 - 0x18C];
    int flag;
};
extern "C" {
void UpdateSo(DPRIZE1C5E48 *);
void func_001C6308(DPRIZE1C5E48 *);
void CheckDprizeBounce(DPRIZE1C5E48 *);
void CheckDprizeCollect(DPRIZE1C5E48 *);
extern float D_FLT_002C0D50;
extern float g_2dded0;
void UpdateDprize(DPRIZE1C5E48 *dprize)
{
    UpdateSo(dprize);
    func_001C6308(dprize);
    int arg;
    switch (dprize->state) {
    case 0: {
        float lengthSquared;
        asm volatile("lqc2 vf1, 0x180(%0)" : : "r"(dprize));
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("qmfc2.ni $2, vf1\n\tmtc1 $2, %0" : "=f"(lengthSquared) : : "$2");
        if (10000.0f < lengthSquared)
            CheckDprizeBounce(dprize);
    }
    case 5:
        CheckDprizeCollect(dprize);
        return;
    case 1:
    case 2:
    case 6:
        return;
    case 3:
        if (dprize->timer < 0.0f) {
            arg = 4;
            goto call;
        }
        return;
    case 4:
        if (dprize->flag != 0 && dprize->timer < 25.0f) {
            dprize->flag = 0;
            arg = 0;
            goto call;
        }
        arg = 2;
        if (D_FLT_002C0D50 < g_2dded0 - dprize->startTime)
            goto call;
        CheckDprizeBounce(dprize);
        CheckDprizeCollect(dprize);
        return;
    default:
        return;
    }
call:
    dprize->vt->fn((char *)dprize + dprize->vt->delta, arg);
}
}
