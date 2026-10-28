#include "sly2.h"
struct VT { char pad[0x100]; short delta; short index; void *(*fn)(void *, MATRIX4 *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct MISSILE { char pad[0x210]; OBJ *paloTarget; char pad2[0xC]; VECTOR posTarget; };
extern "C" void *PredictXfTransform(void *, int, float, MATRIX4 *, int);
VECTOR PosPredictMissileTarget(MISSILE *pmissile, float dtPredict)
{
    VECTOR result;
    QW matLocal[4];
    QW matWorld[4];
    OBJ *palo = pmissile->paloTarget;
    if (palo != 0) {
        VT *vt = palo->vt;
        void *pxf = vt->fn((char *)palo + vt->delta, (MATRIX4 *)matLocal);
        PredictXfTransform(pxf, 0, dtPredict, (MATRIX4 *)matWorld, 0);
        asm("lqc2 vf6, %0\n\tlqc2 vf5, %1\n\tlqc2 vf3, %2\n\tlqc2 vf1, %3\n\tlqc2 vf4, %4\n\t"
            "vmulax.xyz ACC, vf4, vf6x\n\tvmadday.xyz ACC, vf5, vf6y\n\tvmaddaz.xyz ACC, vf3, vf6z\n\tvmaddw.xyz vf4, vf1, vf0w\n\t"
            "lqc2 vf2, %5\n\tlqc2 vf5, %6\n\tlqc2 vf3, %7\n\tlqc2 vf1, %8\n\t"
            "vmulax.xyz ACC, vf2, vf4x\n\tvmadday.xyz ACC, vf5, vf4y\n\tvmaddaz.xyz ACC, vf3, vf4z\n\tvmaddw.xyz vf2, vf1, vf0w"
            : : "m" (pmissile->posTarget), "m" (matLocal[1]), "m" (matLocal[2]), "m" (matLocal[3]), "m" (matLocal[0]),
              "m" (matWorld[0]), "m" (matWorld[1]), "m" (matWorld[2]), "m" (matWorld[3]));
        asm("sqc2 vf2, %0" : "=m" (result));
    } else {
        result = pmissile->posTarget;
    }
    return result;
}
