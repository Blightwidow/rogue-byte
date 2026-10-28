#include "sly2.h"
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct MAT { QW row[4]; };
struct VT { char pad[0x118]; short delta; short index; void (*fn)(void *, QW); short delta2; short index2; void (*fn2)(void *, QW); };
struct SO { char pad[0xC]; VT *vptr; char pad10[0xE8 - 0x10]; int phys; };
extern "C" void SetLoPosMatFromXf(SO *, void *);
extern "C" void func_0022D148(MAT *, void *, int);

void func_001F4A80(SO *so, char *xf)
{
    SetLoPosMatFromXf(so, xf);
    if (so->phys) {
        MAT copy;
        union { MAT rate; QW spill; } u;
#define rate u.rate
        func_0022D148(&rate, xf, 0);
        asm volatile("lqc2 vf5, %0" : : "m"(rate.row[0]));
        asm volatile("lqc2 vf4, %0" : : "m"(rate.row[1]));
        asm volatile("lqc2 vf3, %0" : : "m"(rate.row[2]));
        asm volatile("lqc2 vf2, %0" : : "m"(rate.row[3]));
        asm volatile("sqc2 vf5, %0" : "=m"(copy.row[0]));
        asm volatile("sqc2 vf4, %0" : "=m"(copy.row[1]));
        asm volatile("sqc2 vf3, %0" : "=m"(copy.row[2]));
        asm volatile("sqc2 vf2, %0" : "=m"(copy.row[3]));
        VT *vtable = so->vptr;
        float *cf = (float *)&copy;
        QW w = __builtin_pcpyld(Word(cf[1]), __builtin_pextlw(Word(cf[8]), Word(cf[6])));
        QW v;
        asm volatile("lqc2 vf1, 0x70(%1)\n\tvmulax.xyz ACC, vf5, vf1x\n\tvmadday.xyz ACC, vf4, vf1y\n\tvmaddaz.xyz ACC, vf3, vf1z\n\tvmaddw.xyz vf6, vf2, vf0w\n\tqmfc2.ni %0, vf6" : "=r"(v) : "r"(xf));
        *(volatile QW *)&u.spill = w;
        vtable->fn((char *)so + vtable->delta, v);
        vtable = so->vptr;
        vtable->fn2((char *)so + vtable->delta2, w);
    }
}
