// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct RIDER {
    char pad[0x2C];
    float field2C;
    float field30;
    float field34;
    float field38;
    char pad2[0x44 - 0x3C];
    float field44;
    float field48;
    char pad3[0x60 - 0x4C];
    RIDER *pnext;
};
struct GROUP {
    char pad[0xC];
    int alive;
    RIDER *pfirst;
    char pad2[0x20 - 0x14];
    float gap;
    int crv;
    float target;
};
extern "C" float SMaxCrv(int);
static inline float GClamp(float value, float lower, float upper)
{
    if (value < lower)
        return lower;
    if (upper < value)
        return upper;
    return value;
}

// Retail computes the lerp as (1 - t) * field2C + t * field30 (the 1 - t product is the
// first operand of the add.s), and keeps the clamped value and the midpoint
// (field2C + field30) * 0.5 in the same register ($f3): the source reuses one local for
// both; a separate midpoint local gets its own register (score 14).
extern "C" void SwarmGroup_UpdateTargets(void *pswarm, GROUP *pgroup)
{
    float sCurve = SMaxCrv(pgroup->crv);
    float gapMax = (sCurve * 0.5f) / (float)pgroup->alive;
    float gap = pgroup->gap < gapMax ? pgroup->gap : gapMax;
    int index = 0;
    for (RIDER *prider = pgroup->pfirst; prider; prider = prider->pnext) {
        int remaining = pgroup->alive - index - 1;
        float fraction = (pgroup->target - prider->field34) / (prider->field38 - prider->field34);
        fraction = GClamp(fraction, 0.0f, 1.0f);
        float value = (1.0f - fraction) * prider->field2C + fraction * prider->field30;
        float lower = ((float)index + (float)index + 1.0f) * gap;
        float upper = sCurve - (((float)remaining + (float)remaining) + 1.0f) * gap;
        value = GClamp(value, lower, upper);
        prider->field44 = value;
        value = (prider->field2C + prider->field30) * 0.5f;
        prider->field48 = -fabsf(value - pgroup->target);
        index++;
    }
}
