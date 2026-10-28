#include "sly2.h"
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct MURRAY { char pad0[0xC]; VT *vt; char pad1[0xE8 - 0x10]; char *pphys; char pad2[0x190 - 0xEC]; QW goal; char pad3[0x13D8 - 0x1A0]; int flops; };
extern "C" void AddSoAcceleration(void *, QW);
extern QW g_2a2dc0;
extern int D_002C09A4;

void func_001B6CC0(MURRAY *self)
{
    QW junk;
    int flops = self->flops;
    if (flops != 1) {
        if (flops >= 2)
            return;
        if (flops != 0)
            return;
        char *pphys = self->pphys;
        float negone = -1.0f;
        int bits;
        QW arg;
        asm("lqc2 vf2, 0x80(%3)\n\tmfc1 %0, %4\n\tqmtc2.ni %0, vf1\n\tvmulx.xyzw vf3, vf2, vf1x\n\tsqc2 vf1, %2\n\tqmfc2.ni %1, vf3" : "=r" (bits), "=r" (arg), "=m" (junk) : "r" (pphys), "f" (negone));
        AddSoAcceleration(self, arg);
    }
    QW current = self->vt->fn((char *)self + self->vt->delta);
    float negone2 = -1.0f;
    int bits2;
    QW arg2;
    asm("qmtc2.ni %0, vf2" : : "r" (current));
    asm("lqc2 vf1, 0x190(%0)" : : "r" (self));
    QW *pup = &g_2a2dc0;
    asm("mfc1 %0, %1" : "=r" (bits2) : "f" (negone2));
    asm("qmtc2.ni %0, vf5" : : "r" (bits2));
    int damp = D_002C09A4;
    asm("vmulx.xyzw vf1, vf1, vf5x");
    asm("vsub.xyzw vf1, vf1, vf2");
    asm("lqc2 vf2, 0(%0)" : : "r" (pup));
    asm("vmul.xyz vf3, vf1, vf2\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf3, vf3y\n\tvmaddz.x vf3, vf4, vf3z\n\tvmulx.xyzw vf3, vf2, vf3x");
    asm("qmtc2.ni %0, vf4" : : "r" (damp));
    asm("vsub.xyzw vf1, vf1, vf3");
    asm("sqc2 vf4, %0" : "=m" (junk));
    asm("vmulx.xyzw vf3, vf1, vf4x");
    asm("sqc2 vf5, %0" : "=m" (junk));
    asm("qmfc2.ni %0, vf3" : "=r" (arg2));
    AddSoAcceleration(self, arg2);
}
