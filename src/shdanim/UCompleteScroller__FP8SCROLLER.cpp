// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SCR { char pad0[0x24]; short a, b; char pad1[0x28]; float su, sv, du, dv; };
extern "C" float UCompleteScroller__FP8SCROLLER(SCR *s)
{
    float u = 0.0f;
    if (s->su != 0.0f) u += ((float)s->a * 0.00024414062f / s->du) * 0.5f;
    else u += 0.5f;
    if (s->sv != 0.0f) u += ((float)s->b * 0.00024414062f / s->dv) * 0.5f;
    else u += 0.5f;
    return u;
}
