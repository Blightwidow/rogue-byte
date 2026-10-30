#include "sly2.h"
struct M4 { QW row[4]; };
struct SOGEOM { char *pxf; char pad[0x0C]; void **plvo; char pad2[0x64]; int cpos; QW *apos; };
struct STEP { char pad[0x258]; SOGEOM *hull; SOGEOM *src; };
extern "C" {
void InvertMatrix4Affine(M4 *, const M4 *);
void __ml__FRC7MATRIX4T0(M4 *, const M4 &, const M4 &);
void func_001F4BF8(STEP *);
}
extern "C" void func_00203D00(STEP *pstep, SOGEOM *src, int recompute)
{
    pstep->src = src;
    if (recompute != 0) {
        struct { M4 copy; M4 product; M4 inverse; } l;
        M4 *pinverse = &l.inverse;
        M4 *pproduct = &l.product;
        InvertMatrix4Affine(pinverse, (const M4 *)(pstep->hull->pxf + 0x40));
        __ml__FRC7MATRIX4T0(pproduct, *pinverse, *(const M4 *)(pstep->src->pxf + 0x40));
        l.copy = l.product;
        SOGEOM *psrc = pstep->src;
        SOGEOM *phull = pstep->hull;
        QW *dst = phull->apos;
        QW *pos = psrc->apos;
        int count = psrc->cpos;
        count--;
        while (count >= 0) {
            asm("lqc2 vf5, %0" : : "m" (*pos));
            count--;
            asm("lqc2 vf2, %0" : : "m" (l.copy.row[0]));
            pos++;
            asm("lqc2 vf4, %0" : : "m" (l.copy.row[1]));
            asm("lqc2 vf3, %0" : : "m" (l.copy.row[2]));
            asm("lqc2 vf1, %0" : : "m" (l.copy.row[3]));
            asm("vmulax.xyz ACC, vf2, vf5x\n\tvmadday.xyz ACC, vf4, vf5y\n\tvmaddaz.xyz ACC, vf3, vf5z\n\tvmaddw.xyz vf2, vf1, vf0w");
            asm("sqc2 vf2, %0" : "=m" (*dst));
            dst++;
        }
        SOGEOM *hull = pstep->hull;
        memset(*(void **)hull->plvo, 0, hull->cpos << 4);
        func_001F4BF8(pstep);
    }
}
