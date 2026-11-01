#include "sly2.h"
struct CHN { int unk0; void *panim; };
struct VTA { char pad[0x18]; short delta; short index; void (*fn)(void *, int, float, float, void *); };
struct VTB { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct VTC { char pad[0x118]; short delta; short index; void (*fn)(void *, QW); };
struct Locals1375D0 { QW dead; QW junk; QW scale; };
extern "C" {
extern float g_2dded0;
extern float D_002BC9B8;
void func_002046F0(void *, void *);
CHN *PchnFindAseg(void *, void *, int, int);
void RetractSmaRef(void *);
void ApplyAsegToHandle(void *, void *, int, void *, float, float);
}
// an FP value into lane 0 of a QW
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" void bevy_player_p25_1375d0(char *porbit, int side)
{
    if (side == *(int *)(porbit + 4))
        return;
    *(int *)(porbit + 4) = side;
    void *paseg = 0;
    *(float *)(porbit + 8) = g_2dded0;
    if (side == -1) {
        Locals1375D0 l;
        QW wordBits;
        asm("lw %0, %1" : "=r" (wordBits) : "m" (D_002BC9B8));
        l.scale = wordBits;
        char *pjt = *(char **)porbit;
        VTB *vtb = *(VTB **)(pjt + 0xC);
        l.dead = l.scale;
        QW (*getVelocity)(void *) = vtb->fn;
        QW velocity = getVelocity(pjt + vtb->delta);
        char *pjt2 = *(char **)porbit;
        asm("qmtc2.ni %0, vf2" : : "r" (velocity));
        asm("lqc2 vf1, %0" : : "m" (l.scale));
        VTC *vtc = *(VTC **)(pjt2 + 0xC);
        asm("vmulx.xyzw vf1, vf2, vf1x");
        QW product;
        asm("qmfc2.ni %0, vf1" : "=r" (product));
        void (*setVelocity)(void *, QW) = vtc->fn;
        setVelocity(pjt2 + vtc->delta, product);
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
        asm("lqc2 vf4, %0" : : "m" (vecRoot[0]));
        VTC *vtc = *(VTC **)(pj + 0xC);
        QW *prow = (QW *)(pj + 0x1B0);
        asm("lqc2 vf2, %0" : : "m" (prow[0]));
        asm("lqc2 vf1, %0" : : "m" (prow[1]));
        asm("lqc2 vf3, %0" : : "m" (prow[2]));
        asm("vmulax.xyz ACC, vf2, vf4x");
        asm("vmadday.xyz ACC, vf1, vf4y");
        asm("vmaddz.xyz vf5, vf3, vf4z");
        QW velocity;
        asm("qmfc2.ni %0, vf5" : "=r" (velocity));
        void (*setVelocity)(void *, QW) = vtc->fn;
        setVelocity(pj + vtc->delta, velocity);
        asm("lqc2 vf1, %0" : : "m" (vecRoot[0]));
        asm("qmtc2.ni %0, vf2" : : "r" (Word(-1.0f)));
        char *pj2 = *(char **)porbit;
        asm("vmulx.xyzw vf1, vf1, vf2x");
        asm("sqc2 vf2, %0" : "=m" (junk[0]));
        asm("sqc2 vf1, 0x190(%0)" : : "r" (pj2) : "memory");
        *(int *)(porbit + 0xC) = side;
    }
    }
    char *pjt3 = *(char **)porbit;
    RetractSmaRef(pjt3 + 0x1034);
    char *pjt4 = *(char **)porbit;
    ApplyAsegToHandle(paseg, pjt4, 1, pjt4 + 0x1030, 0.0f, 1.0f);
}
