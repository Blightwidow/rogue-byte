#include "sly2.h"
struct MAT_1F4A80 { QW row[4]; };
struct VT_1F4A80 { char pad[0x118]; short delta; short index; void (*fn)(void *, QW); short delta2; short index2; void (*fn2)(void *, QW); };
struct SO_1F4A80 { char pad[0xC]; VT_1F4A80 *vptr; char pad10[0xE8 - 0x10]; int phys; };
extern "C" void SetLoPosMatFromXf(SO_1F4A80 *, void *);
extern "C" void func_0022D148(MAT_1F4A80 *, void *, int);

// lanes 0 and 1 of a QW from two floats: mfc1, mfc1, pextlw
static inline QW PairLow_1F4A80(float lane0, float lane1) { QW r; QW t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0" : "=r" (r), "=r" (t) : "f" (lane0), "f" (lane1)); return r; }
// lane 2 of a QW from a float: mfc1, then pcpyld into the upper doubleword
static inline QW WithLane2_1F4A80(QW low, float lane2) { QW t; asm("mfc1 %1, %2\n\tpcpyld %0, %1, %0" : "+r" (low), "=r" (t) : "f" (lane2)); return low; }

extern "C" void func_001F4A80(SO_1F4A80 *so, char *xf)
{
    SetLoPosMatFromXf(so, xf);
    if (so->phys) {
        MAT_1F4A80 copy;
        union { MAT_1F4A80 rate; QW spill; } u;
        func_0022D148(&u.rate, xf, 0);
        asm volatile("lqc2 vf5, %0" : : "m"(u.rate.row[0]));
        asm volatile("lqc2 vf4, %0" : : "m"(u.rate.row[1]));
        asm volatile("lqc2 vf3, %0" : : "m"(u.rate.row[2]));
        asm volatile("lqc2 vf2, %0" : : "m"(u.rate.row[3]));
        asm volatile("sqc2 vf5, %0" : "=m"(copy.row[0]));
        asm volatile("sqc2 vf4, %0" : "=m"(copy.row[1]));
        asm volatile("sqc2 vf3, %0" : "=m"(copy.row[2]));
        asm volatile("sqc2 vf2, %0" : "=m"(copy.row[3]));
        float *cf = (float *)&copy;
        QW w = PairLow_1F4A80(cf[6], cf[8]);
        VT_1F4A80 *vt = so->vptr;
        short delta = vt->delta;
        w = WithLane2_1F4A80(w, cf[1]);
        asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(xf));
        void (*fn)(void *, QW) = vt->fn;
        asm volatile("vmulax.xyz ACC, vf5, vf1x\n\tvmadday.xyz ACC, vf4, vf1y\n\tvmaddaz.xyz ACC, vf3, vf1z\n\tvmaddw.xyz vf6, vf2, vf0w");
        char *self = (char *)so + delta;
        QW v;
        asm volatile("qmfc2.ni %0, vf6" : "=r"(v));
        u.spill = w; // provisional: dead sq of w through the escaped union (retail's sq in the jalr delay slot)
        fn(self, v);
        VT_1F4A80 *vt2 = so->vptr;
        vt2->fn2((char *)so + vt2->delta2, w);
    }
}
