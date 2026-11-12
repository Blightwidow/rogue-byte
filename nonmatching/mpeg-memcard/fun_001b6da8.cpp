// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
union VU_SCALE { QW q; VECTOR v; };
struct MQ;
struct VTE { short delta; short pad; };
struct HALF { int f0; int f4; void *powner; int fC; QW f10; char pad20[0x10]; QW f30; };
struct PAIR { HALF half[2]; char pad[0x2C]; PAIR *pnext; };
struct ABS_1B6DA8 { void *powner; int a4; int a8; int c; int d; char pad14[0xC]; QW q20; QW q30; char pad40[0x20]; };
struct VT {
    char pad0[0x108]; short d108; short p10A; QW (*f10C)(void *); char pad110[8]; short d118; short p11A; void (*f11C)(void *, QW);
};
struct ACTOR {
    char pad0[0xC]; VT *pvt;
    char pad10[0x180]; int a190; int a194; int a198;
    char pad19C[0x1244 - 0x19C]; int pad;
};
struct OBJ {
    char pad0[0xC]; VT *pvt;
    char pad10[0x180]; int a190; int a194; int a198;
    char pad19C[0x1030 - 0x19C]; char *pasega;
    char pad1034[0x131C - 0x1034]; float t131C;
    char pad1320[0x13D8 - 0x1320]; int state; float tState; int pad13E0; PAIR *ppair; char pad13E8[0x24];
};
extern "C" {
void FreeSwMqList__FP2SWP2MQ(void *, PAIR *);
int PaloFindWkrAbsorber(void *, int);
void PaloAbsorbWkr(ABS_1B6DA8 *);
float *PeaFindAsegLabel(void *, int);
void RetractAsega(void *, int);
void SeekAsega(void *, int, float, float);
}
extern char B_003DD490;
extern int D_002C09A8;
extern QW g_2a2dc0;
extern float g_2dded0;

static inline void SetScalar(VU_SCALE *pscale, u32 word)
{
    pscale->q = VectorFromWord(word);
}

extern "C" void func_001B6DA8(OBJ *self, int state)
{
    VU_SCALE scale;
    ABS_1B6DA8 absorb;
    if (self->state == state)
        return;
    if (self->state == -1) {
        int *pclear = &self->a190;
        pclear[2] = 0;
        pclear[1] = 0;
        self->a190 = 0;
    }
    self->state = state;
    self->tState = g_2dded0;
    switch (state) {
    case 0:
        break;
    case -1:
        FreeSwMqList__FP2SWP2MQ(&B_003DD490, self->ppair);
        self->ppair = 0;
        break;
    case 1: {
        VT *pvt = self->pvt;
        QW velocity = pvt->f10C((char *)self + pvt->d108);
        QW axis = g_2a2dc0;
        QW dot = DotProduct(velocity, axis);
        QW rest = VectorSub(velocity, VectorScaleX(axis, dot));
        pvt = self->pvt;
        scale.q = VectorFromWord(D_002C09A8);
        QW target = ScaleAddX(rest, axis, scale.q);
        pvt->f11C((char *)self + pvt->d118, target);
        self->t131C = g_2dded0;
        break;
    }
    case 2: {
        int *pclear = &self->a190;
        pclear[2] = 0;
        pclear[1] = 0;
        self->a190 = 0;
        for (PAIR *ppair = self->ppair; ppair; ppair = ppair->pnext) {
            int fOther = ppair->half[0].powner != self;
            HALF *phalfA = &ppair->half[1 - fOther];
            HALF *phalfB = &ppair->half[fOther];
            int pwkr = PaloFindWkrAbsorber((void *)phalfA->fC, 4);
            if (pwkr) {
                memset(&absorb, 0, 0x60);
                absorb.powner = self;
                absorb.a4 = phalfB->f0;
                absorb.a8 = pwkr;
                absorb.c = 4;
                absorb.d = -0x14;
                absorb.q20 = phalfA->f10;
                absorb.q30 = phalfB->f30;
                PaloAbsorbWkr(&absorb);
            }
        }
        FreeSwMqList__FP2SWP2MQ(&B_003DD490, self->ppair);
        self->ppair = 0;
        float *pg = PeaFindAsegLabel(*(void **)((char *)self->pasega + 0x14), 0x1A5);
        if (pg)
            SeekAsega(self->pasega, 0, *pg, 1.0f);
        else
            RetractAsega(self->pasega, 0);
        break;
    }
    }
}
