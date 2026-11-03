#include "sly2.h"
struct OBJ {
    int pad0[3]; virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7(); virtual void p8(); virtual void p9(); virtual void p10(); virtual void p11(); virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15(); virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19(); virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23(); virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27(); virtual void V28(QW); virtual void V29(void *); virtual QW *V30(); virtual void p31(); virtual void p32(); virtual void p33(); virtual void V34(QW); virtual void V35(QW);
};
extern "C" {
int FIsBasicDerivedFrom(void *, int);
void MatchSoOtherObject(void *, void *);
extern QW g_2a2dc0;
extern QW g_2a2dd0;
}
static inline QW Word(float f) { QW r; asm volatile("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" void func_002052E0(OBJ *a, OBJ *b)
{
    QW sp[5];
    if (b == 0)
        return;
    if (FIsBasicDerivedFrom(b, 3)) {
    QW *pm = b->V30();
    asm volatile("lqc2 vf5, 0(%0)" : : "r"(pm));
    asm volatile("sqc2 vf5, %0" : "=m"(sp[0]));
    QW minusOne = Word(-1.0f);
    asm volatile("qmtc2.ni %0, vf6" : : "r"(minusOne));
    asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(pm));
    asm volatile("lqc2 vf2, 0x240(%0)" : : "r"(a));
    asm volatile("vmulx.xyzw vf2, vf2, vf6x");
    asm volatile("sqc2 vf4, %0" : "=m"(sp[1]));
    asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(pm));
    asm volatile("sqc2 vf3, %0" : "=m"(sp[2]));
    asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(pm));
    asm volatile("vmulax.xyz ACC, vf5, vf2x");
    asm volatile("vmadday.xyz ACC, vf4, vf2y");
    asm volatile("vmaddaz.xyz ACC, vf3, vf2z");
    asm volatile("vmaddw.xyz vf7, vf1, vf0w");
    QW pos;
    asm volatile("qmfc2.ni %0, vf7" : "=r"(pos));
    asm volatile("sqc2 vf1, %0" : "=m"(sp[3]));
    asm volatile("sqc2 vf6, %0" : "=m"(sp[4]));
    a->V28(pos);
    a->V29(sp);
    if (FIsBasicDerivedFrom(a, 0x34)) {
        asm volatile("qmtc2.ni %0, vf3" : : "r"(*(int *)((char *)a + 0x1048)));
        asm volatile("lqc2 vf2, 0(%0)" : : "r"(&g_2a2dc0));
        asm volatile("lqc2 vf1, %0" : : "m"(sp[3]));
        asm volatile("vadda.xyzw ACC, vf0, vf1");
        asm volatile("vmaddx.xyzw vf1, vf2, vf3x");
        asm volatile("sqc2 vf3, %0" : "=m"(sp[4]));
        asm volatile("sqc2 vf1, 0x1060(%0)" : : "r"(a));
    }
    a->V34(g_2a2dd0);
    a->V35(g_2a2dd0);
    *(int *)((char *)a + 0x208) = 0;
    } else {
        MatchSoOtherObject(a, b);
    }
}
