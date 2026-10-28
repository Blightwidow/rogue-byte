#include "sly2.h"
struct M4 { QW row[4]; };
struct L { QW side; QW normal; QW dpos; M4 mat; QW junk; };
extern "C" {
void func_001A5EE8(void *, M4 *, float, float);
M4 *__as__6VECTORG9VU_VECTOR(M4 *, QW);
}
extern char B_002DDF40[];
static inline float LaneNop(QW q) { float f; asm volatile("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }
extern "C" void func_001A5FB8(void *plo, QW posA, QW posB, float width, float g)
{
    L l;
    QW bits;
    register QW v1 asm("vf1");
    register QW v2 asm("vf2");
    register QW v3 asm("vf3");
    register QW v4 asm("vf4");
    register QW v5 asm("vf5");
    register QW v6 asm("vf6");
    register QW v7 asm("vf7");
    register QW v8 asm("vf8");
    asm("qmtc2.ni %1, vf8" : "=j" (v8) : "r" (posA));
    asm("qmtc2.ni %1, vf1" : "=j" (v1) : "r" (posB));
    asm("vsub.xyzw vf7, vf1, vf8" : "=j" (v7) : "j" (v1), "j" (v8));
    float eps = 0.01f;
    asm("lqc2 vf1, %1" : "=j" (v1) : "m" (*(QW *)(B_002DDF40 + 0x90)), "j" (v7));
    asm volatile("vsub.xyzw vf1, vf8, vf1\n\tvopmula.xyz ACC, vf1, vf7\n\tvopmsub.xyz vf6, vf7, vf1\n\tvmul.xyz vf1, vf6, vf6\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "+j" (v1), "=j" (v2), "=j" (v6) : "j" (v7), "j" (v8));
    asm volatile("sqc2 vf6, %0" : "=m" (l.normal) : "j" (v6));
    asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (bits) : "j" (v1));
    float norm = LaneNop(bits);
    if (eps < norm) {
        asm volatile("nop\n\tnop");
        float scale = width / norm;
        asm volatile("vopmula.xyz ACC, vf6, vf7\n\tvopmsub.xyz vf1, vf7, vf6\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z" : "=j" (v1), "+j" (v2), "=j" (v4) : "j" (v6), "j" (v7));
        M4 *pm;
        asm volatile("" : "=r" (pm) : "0" (&l.mat));
        asm volatile("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf1, Q" : "+j" (v2) : "j" (v1));
        asm volatile("sqc2 vf2, %0" : "=m" (l.side) : "j" (v2));
        int sbits;
        asm volatile("mfc1 %0, %1" : "=r" (sbits) : "f" (scale));
        asm volatile("qmtc2.ni %1, vf3" : "=j" (v3) : "r" (sbits));
        asm volatile("mfc1 %0, %1" : "=r" (sbits) : "f" (eps));
        asm volatile("vmulx.xyzw vf4, vf6, vf3x" : "=j" (v4) : "j" (v6), "j" (v3));
        asm volatile("qmtc2.ni %1, vf5" : "=j" (v5) : "r" (sbits));
        asm volatile("sqc2 vf3, %0" : "=m" (l.junk) : "j" (v3));
        asm volatile("vmulx.xyzw vf1, vf7, vf5x" : "=j" (v1) : "j" (v7), "j" (v5));
        asm volatile("sqc2 vf4, %0" : "=m" (l.normal) : "j" (v4));
        asm volatile("sqc2 vf1, %0" : "=m" (l.dpos) : "j" (v1));
        __as__6VECTORG9VU_VECTOR((M4 *)&l.mat.row[3], posA);
        asm volatile("sqc2 vf5, %0" : "=m" (l.junk) : "j" (v5));
        l.mat.row[0] = l.side;
        pm->row[1] = l.normal;
        pm->row[2] = l.dpos;
        ((int *)&l.mat.row[2])[3] = 0;
        ((int *)&l.mat.row[1])[3] = 0;
        ((int *)&l.mat.row[0])[3] = 0;
        ((float *)&pm->row[3])[3] = 1.0f;
        func_001A5EE8(plo, pm, g, g);
    }
}
