#include "sly2.h"
struct CHN { int unk0; void *panim; };
struct VTA { char pad[0x18]; short delta; short index; void (*fn)(void *, int, float, float, void *); };
struct VTB { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct VTC { char pad[0x118]; short delta; short index; void (*fn)(void *, QW); };
extern "C" {
extern float g_2dded0;
extern float D_002BC9B8;
void func_002046F0(void *, void *);
CHN *PchnFindAseg(void *, void *, int, int);
void RetractSmaRef(void *);
void ApplyAsegToHandle(void *, void *, int, void *, float, float);
}
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" void bevy_player_p25_1375d0(char *porbit, int side)
{
    if (side == *(int *)(porbit + 4))
        return;
    *(int *)(porbit + 4) = side;
    void *paseg = 0;
    *(float *)(porbit + 8) = g_2dded0;
    if (side == -1) {
        char *pjt = *(char **)porbit;
        QW scaleCopy[1];
        QW padA[1];
        QW scaleBits[1];
        register QW wordBits asm("$3");
        asm("lw %0, %1" : "=r" (wordBits) : "m" (D_002BC9B8));
        scaleBits[0] = wordBits;
        VTB *vtb = *(VTB **)(pjt + 0xC);
        asm volatile("" : : : "memory");
        scaleCopy[0] = scaleBits[0];
        asm("" : : "m" (scaleCopy[0]), "m" (padA[0]));
        QW (*getVelocity)(void *) = vtb->fn;
        int delta;
        asm volatile("lh %0, 0x108(%1)" : "=&r" (delta) : "r" (vtb));
        QW velocity = getVelocity(pjt + delta);
        register QW v1 asm("vf1");
        register QW v2 asm("vf2");
        QW product;
        char *pjt2 = *(char **)porbit;
        asm("qmtc2.ni %1, vf2" : "=j" (v2) : "r" (velocity));
        asm("lqc2 vf1, %1" : "=j" (v1) : "m" (scaleBits[0]));
        asm("vmulx.xyzw vf1, vf2, vf1x\n\tqmfc2.ni %0, vf1" : "=r" (product) : "j" (v1), "j" (v2));
        VTC *vtc = *(VTC **)(pjt2 + 0xC);
        vtc->fn(pjt2 + vtc->delta, product);
        return;
    }
    if (side >= -1) {
    if (side < 2) {
        if (side == 0)
            paseg = *(void **)(porbit + 0x10);
        else
            paseg = *(void **)(porbit + 0x14);
        char *pjt = *(char **)porbit;
        func_002046F0(pjt, *(void **)(pjt + 0x10DC));
        pjt = *(char **)porbit;
        CHN *pchn = PchnFindAseg(paseg, pjt, 1, 1);
        QW vecRoot[1];
        QW junk[1];
        void *panim = pchn->panim;
        VTA *vta = *(VTA **)panim;
        vta->fn((char *)panim + vta->delta, 0, 0.0f, *(float *)((char *)paseg + 0x78), vecRoot);
        char *pj = *(char **)porbit;
        register QW f1 asm("vf1");
        register QW f2 asm("vf2");
        register QW f3 asm("vf3");
        register QW f4 asm("vf4");
        register QW f5 asm("vf5");
        asm volatile("lqc2 vf4, %1" : "=j" (f4) : "m" (vecRoot[0]));
        register VTC *vtc asm("$2") = *(VTC **)(pj + 0xC);
        register QW *prow asm("$5");
        asm volatile("addiu %0, %1, 0x1B0" : "=r" (prow) : "r" (pj));
        asm volatile("lqc2 vf2, %1" : "=j" (f2) : "m" (*(QW *)(pj + 0x1B0)));
        asm volatile("lqc2 vf1, %1" : "=j" (f1) : "m" (prow[1]));
        asm volatile("lqc2 vf3, %1" : "=j" (f3) : "m" (prow[2]));
        register int delta asm("$3");
        asm volatile("lh %0, 0x118(%1)" : "=&r" (delta) : "r" (vtc));
        asm volatile("vmulax.xyz ACC, vf2, vf4x\n\tvmadday.xyz ACC, vf1, vf4y\n\tvmaddz.xyz vf5, vf3, vf4z" : "=j" (f5) : "j" (f1), "j" (f2), "j" (f3), "j" (f4));
        register void (*setVelocity)(void *, QW) asm("$6") = vtc->fn;
        QW velocity;
        asm volatile("qmfc2.ni %0, vf5" : "=r" (velocity) : "j" (f5));
        setVelocity(pj + delta, velocity);
        float minusOne = -1.0f;
        register QW g1 asm("vf1");
        register QW g2 asm("vf2");
        asm volatile("lqc2 vf1, %1" : "=j" (g1) : "m" (vecRoot[0]));
        asm volatile("qmtc2.ni %1, vf2" : "=j" (g2) : "r" (Word(minusOne)));
        register char *pj2 asm("$2") = *(char **)porbit;
        asm volatile("vmulx.xyzw vf1, vf1, vf2x\n\tsqc2 vf2, %0\n\tsqc2 vf1, 0x190(%1)" : "=m" (junk[0]) : "r" (pj2), "j" (g1), "j" (g2) : "memory");
        *(int *)(porbit + 0xC) = side;
    }
    }
    char *pjt3 = *(char **)porbit;
    RetractSmaRef(pjt3 + 0x1034);
    char *pjt4 = *(char **)porbit;
    ApplyAsegToHandle(paseg, pjt4, 1, pjt4 + 0x1030, 0.0f, 1.0f);
}
