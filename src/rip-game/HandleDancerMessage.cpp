#include "sly2.h"
extern "C" {
void HandlePoMessage(char *, int, int *);
QW func_00204E38(char *, int, float);
}
struct VT { char pad[0x118]; short delta; short index; void (*fn)(char *, QW); };
void HandleDancerMessage(char *dancer, int msg, int *pmsg)
{
    QW junk;
    asm("" : "=m" (junk));
    HandlePoMessage(dancer, msg, pmsg);
    if (msg == 9) {
        int sender = pmsg[0];
        char *owner = *(char **)(sender + 0x18);
        if (owner == dancer) {
            switch (pmsg[2]) {
            case 0x27:
                *(int *)(owner + 0x40C) = 1;
                break;
            case 0x28:
                *(int *)(owner + 0x40C) = 0;
                break;
            case 0x15E: {
                QW vel = func_00204E38(owner, sender, *(float *)(pmsg + 1));
                float scale = -1.0f;
                QW world;
                int chain;
                asm volatile("qmtc2.ni %1, vf4" : "=r" (chain) : "r" (vel));
                register VT *vtable asm("$5") = *(VT **)(owner + 0xC);
                asm volatile("qmtc2.ni %1, vf1" : "=r" (chain) : "r" (scale), "r" (chain));
                asm volatile("sqc2 vf1, %0" : "=m" (junk) : "r" (chain));
                asm volatile("vmulx.xyzw vf2, vf4, vf1x" : "=r" (chain) : "r" (chain));
                asm volatile("sqc2 vf2, %0" : "=m" (*(QW *)(owner + 0x190)) : "r" (chain));
                QW *rows = (QW *)(owner + 0x1B0);
                asm volatile("lqc2 vf3, %1" : "=r" (chain) : "m" (*(QW *)(owner + 0x1B0)));
                int delta = vtable->delta;
                asm volatile("lqc2 vf2, 0x20(%1)\n\tlqc2 vf1, 0x10(%1)" : "=r" (chain) : "r" (rows), "r" (chain));
                void (*fn)(char *, QW) = vtable->fn;
                char *self = owner + delta;
                asm volatile("vmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf1, vf4y\n\tvmaddz.xyz vf5, vf2, vf4z\n\tqmfc2.ni %0, vf5" : "=r" (world) : "r" (chain));
                asm volatile("" : : "r" (rows));
                fn(self, world);
                break;
            }
            }
        }
    }
}
