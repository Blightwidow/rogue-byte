#include "sly2.h"
struct SMP { float a, b, c; };
struct RH {
    char pad0[0x40]; unsigned *grf;
    char pad1[0x58 - 0x44]; float dtEarly, dtLate;
    char pad2[0x234 - 0x60]; float lmLo, lmHi;
    char pad3[0x280 - 0x23C]; int cWin;
    char pad4[0x28C - 0x284]; SMP smp; float gA, gWrong, gTwice, gEarly;
};
extern RH *B_002DE570;
extern "C" void InitLo(RH*);
extern "C" void func_001A6CA8(RH*, int);
static inline void InitSmp(SMP* s, float lo, float hi)
{
    s->a = __builtin_fabsf(hi - lo) * 0.33333334f;
    s->b = 0.0f;
    s->c = 5.0f;
}
extern "C" void InitRhythm(RH* p)
{
    InitLo(p);
    B_002DE570 = p;
    float lo = -1.5f, hi = 1.0f;
    asm("" : "+f"(lo), "+f"(hi));
    p->lmLo = lo;
    p->lmHi = hi;
    p->dtLate = 0.4f;
    p->cWin = 8;
    p->dtEarly = 0.4f;
    InitSmp(&p->smp, lo, hi);
    p->gWrong = -0.8f;
    p->gTwice = -0.2f;
    p->gEarly = lo;
    p->gA = lo;
    func_001A6CA8(p, 1);
    unsigned g = (unsigned)p->grf;
    if (!(g & 1)) *p->grf |= 10; else p->grf = (unsigned*)(g | 10);
}
