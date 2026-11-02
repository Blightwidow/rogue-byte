// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct OBJ1B90B8 { char pad0[0x180]; float scale; char pad1[0xC]; QW vec; char pad2[0x16A0 - 0x1A0]; char pad3[0]; };
extern "C" QW func_00204E38(void *, void *, float);
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" void func_001B90B8(char *obj)
{
    QW junk;
    int mode = *(int *)(obj + 0x1840);
    if (mode == 1 || mode == 3) {
        char *target = *(char **)(obj + 0x1030);
        QW dist = func_00204E38(obj, target, *(float *)(target + 0x1C));
        int t1, t2;
        QW minus = Word(-1.0f);
        asm("qmtc2.ni %1, vf3" : "=r" (t1) : "r" (dist));
        asm("qmtc2.ni %1, vf1" : "=r" (t2) : "r" (minus), "r" (t1));
        asm("sqc2 vf1, %0" : "=m" (junk) : "r" (t2));
        asm("vmulx.xyzw vf2, vf3, vf1x\n\tsqc2 vf2, %0" : "=m" (*(QW *)(obj + 0x190)) : "r" (t2));
        *(float *)(obj + 0x180) = 1.0f;
    }
}
