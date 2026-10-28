#include "sly2.h"
struct Inst { char pad[0x10]; QW q10; };
struct Animref { int kind; int pv; Inst *pinst; };
struct Guard { char pad[0x190]; QW vel; char pad2[0x40]; QW angvel; char pad3[0xFC4 - 0x1F0]; char *pscale; };
extern "C" {
extern QW g_2a2dd0;
void UpdateJumper(void *);
QW func_00204E38(void *, void *, float);
QW func_00204ED8(void *, void *, float);
}
struct Locals { QW tmp; QW vel; };
struct Inst2 { char pad[0x10]; int phase; char pad2[0x24]; void *inner; };
struct Inner { char pad[0x1C]; float f1c; };
struct Inst1 { char pad[0x30]; Inner *anim; };

void func_00209618(Animref *ref, Guard *guard)
{
    Locals l;
    int kind = ref->kind;
    l.vel = g_2a2dd0;
    QW ang;
    asm("lq %0, %1" : "=r" (ang) : "m" (l.vel));
    Inner *anim;
    switch (kind) {
    case 0:
    case 1:
        if (kind == 0) anim = (Inner *)ref->pinst;
        else anim = ((Inst1 *)ref->pinst)->anim;
        if (anim != 0) {
            l.vel = func_00204E38(guard, anim, anim->f1c);
            ang = func_00204ED8(guard, anim, anim->f1c);
        }
        break;
    case 2: {
        UpdateJumper(ref->pinst);
        Inst2 *inst = (Inst2 *)ref->pinst;
        int phase = inst->phase;
        if (phase > 0) {
            if (phase < 3) break;
            if (phase == 4) break;
        }
        Inner *inner = (Inner *)inst->inner;
        l.vel = func_00204E38(guard, inner, inner->f1c);
        break;
    }
    case 3:
        l.vel = ref->pinst->q10;
        break;
    }
    char *pscale = guard->pscale;
    asm volatile("lqc2 vf2, %0" : : "m" (l.vel));
    if (pscale != 0) {
        int bits = **(int **)(pscale + 8);
        asm("qmtc2.ni %1, vf1\n\tvmulx.xyzw vf2, vf2, vf1x\n\tsqc2 vf1, %0" : "=m" (l.tmp) : "r" (bits));
        asm("sqc2 vf2, %0" : "=m" (l.vel));
    }
    guard->angvel = ang;
    float mone = -1.0f;
    int bits2;
    asm("mfc1 %0, %1" : "=r" (bits2) : "f" (mone));
    asm("qmtc2.ni %2, vf1\n\tlqc2 vf3, %3\n\tvmulx.xyzw vf2, vf3, vf1x\n\tsqc2 vf1, %0\n\tsqc2 vf2, %1" : "=m" (l.tmp), "=m" (guard->vel) : "r" (bits2), "m" (l.vel));
}
