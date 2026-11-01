// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct RIDER { char pad[0x2C]; float a; float b; float sa; float sb; char pad2[0x44 - 0x3C]; float out; float score; char pad3[0x60 - 0x4C]; RIDER *pnext; };
struct GROUP { char pad[0xC]; int alive; RIDER *pfirst; char pad2[0x20 - 0x14]; float gap; int crv; float target; };
extern "C" float SMaxCrv(int);
extern "C" void SwarmGroup_UpdateTargets(void *pswarm, GROUP *pgroup)
{
    float sCurve = SMaxCrv(pgroup->crv);
    float gapMax = (sCurve * 0.5f) / (float)pgroup->alive;
    float gap = pgroup->gap < gapMax ? pgroup->gap : gapMax;
    int index = 0;
    for (RIDER *prider = pgroup->pfirst; prider; prider = prider->pnext) {
        int remaining = pgroup->alive - index - 1;
        float t = (pgroup->target - prider->sa) / (prider->sb - prider->sa);
        if (t < 0.0f)
            t = 0.0f;
        else if (t > 1.0f)
            t = 1.0f;
        float value = (1.0f - t) * prider->a + t * prider->b;
        float lo = ((float)index + (float)index + 1.0f) * gap;
        float hi = sCurve - (((float)remaining + (float)remaining) + 1.0f) * gap;
        if (value < lo)
            value = lo;
        else if (hi < value)
            value = hi;
        prider->out = value;
        float mid = (prider->a + prider->b) * 0.5f;
        float dist = mid - pgroup->target;
        prider->score = -(dist < 0.0f ? -dist : dist);
        index++;
    }
}
