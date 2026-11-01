// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
extern "C" const float D_FLT_002C0AB0;
extern "C" int OrientXy(QW a, QW b, QW c)
{
    float bx, by, cx, cy, ax, ay;
    asm("prot3w $2, %2\n\tmtc1 %2, %0\n\tmtc1 $2, %1" : "=f"(bx), "=f"(by) : "r"(b) : "$2");
    asm("mtc1 %1, %0" : "=f"(cx) : "r"(c));
    asm("prot3w $2, %2\n\tmtc1 %2, %0\n\tmtc1 $2, %1" : "=f"(ax), "=f"(ay) : "r"(a) : "$2");
    asm("prot3w $2, %1\n\tmtc1 $2, %0" : "=f"(cy) : "r"(c) : "$2");
    float cross = (ax - bx) * (by - cy) - (ay - by) * (bx - cx);
    if (cross < -D_FLT_002C0AB0) return -1;
    if (D_FLT_002C0AB0 < cross) return 1;
    return 0;
}
