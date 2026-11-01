#include "sly2.h"
struct M4 { QW row[4]; };
struct L { QW side; QW normal; QW dpos; M4 mat; QW junk; };
extern "C" {
void func_001A5EE8(void *, M4 *, float, float);
M4 *__as__6VECTORG9VU_VECTOR(M4 *, QW);
}
extern char B_002DDF40[];
/* lane 0 of a QW to a float: mtc1 plus the hazard nop retail has */
static inline float LaneNop(QW q) { float f; asm volatile("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }
extern "C" void func_001A5FB8(void *plo, QW posA, QW posB, float width, float g)
{
    L l;
    QW bits;
    asm volatile("qmtc2.ni %0, vf8" : : "r" (posA));
    asm volatile("qmtc2.ni %0, vf1" : : "r" (posB));
    asm volatile("vsub.xyzw vf7, vf1, vf8");
    float eps = 0.01f;
    asm volatile("lqc2 vf1, 0x90(%0)" : : "r" (B_002DDF40));
    asm volatile("vsub.xyzw vf1, vf8, vf1\n\tvopmula.xyz ACC, vf1, vf7\n\tvopmsub.xyz vf6, vf7, vf1\n\tvmul.xyz vf1, vf6, vf6\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
    asm volatile("sqc2 vf6, %0" : "=m" (l.normal));
    asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (bits));
    float norm = LaneNop(bits);
    if (eps < norm) {
        asm volatile("nop\n\tnop");
        float scale = width / norm;
        asm volatile("vopmula.xyz ACC, vf6, vf7\n\tvopmsub.xyz vf1, vf7, vf6\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z");
        M4 *pm = &l.mat;
        asm volatile("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf1, Q");
        asm volatile("sqc2 vf2, %0" : "=m" (l.side));
        QW sbits;
        asm volatile("mfc1 %0, %1\n qmtc2.ni %0, vf3" : "=r" (sbits) : "f" (scale));
        asm volatile("vmulx.xyzw vf4, vf6, vf3x");
        asm volatile("mfc1 %0, %1\n qmtc2.ni %0, vf5" : "=r" (sbits) : "f" (eps));
        asm volatile("sqc2 vf3, %0" : "=m" (l.junk));
        asm volatile("vmulx.xyzw vf1, vf7, vf5x");
        asm volatile("sqc2 vf4, %0" : "=m" (l.normal));
        asm volatile("sqc2 vf1, %0" : "=m" (l.dpos));
        __as__6VECTORG9VU_VECTOR((M4 *)&l.mat.row[3], posA);
        asm volatile("sqc2 vf5, %0" : "=m" (l.junk));
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
