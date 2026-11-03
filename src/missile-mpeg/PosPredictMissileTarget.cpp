#include "sly2.h"
struct VT { char pad[0x100]; short delta; short index; void *(*fn)(void *, MATRIX4 *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct MISSILE { char pad[0x210]; OBJ *paloTarget; char pad2[0xC]; QW posTarget; };
struct M4 { QW row[4]; };
extern "C" void *PredictXfTransform(void *, int, float, MATRIX4 *, int);

// m.row[0] * v.x + m.row[1] * v.y + m.row[2] * v.z + m.row[3]
static inline QW XformPoint(const M4 &m, QW v)
{
    QW result;
    asm("vmulax.xyz ACC, %1, %5x\n\tvmadday.xyz ACC, %2, %5y\n\tvmaddaz.xyz ACC, %3, %5z\n\tvmaddw.xyz %0, %4, vf0w"
        : "=j"(result) : "j"(m.row[0]), "j"(m.row[1]), "j"(m.row[2]), "j"(m.row[3]), "j"(v));
    return result;
}

VECTOR PosPredictMissileTarget(MISSILE *pmissile, float dtPredict)
{
    VECTOR result;
    M4 matLocal;
    M4 matWorld;
    OBJ *palo = pmissile->paloTarget;
    if (palo != 0) {
        VT *vt = palo->vt;
        void *pxf = vt->fn((char *)palo + vt->delta, (MATRIX4 *)&matLocal);
        PredictXfTransform(pxf, 0, dtPredict, (MATRIX4 *)&matWorld, 0);
        *(QW *)&result = XformPoint(matWorld, XformPoint(matLocal, pmissile->posTarget));
    } else {
        *(QW *)&result = pmissile->posTarget;
    }
    return result;
}
