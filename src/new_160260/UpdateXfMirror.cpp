#include "sly2.h"
struct M4 { QW row[4]; };
struct M3 { QW row[3]; };
struct XF { char pad0[0xA0]; XF *pxfParent; int generation; };
struct XFMIRROR { XF *pxfSource; XF *pxfTarget; int fPosition; int fRotation; };
struct SW { char pad[0x3D58]; int generation; };
extern SW B_003DD490;
static inline int NextGeneration(SW *psw) { return ++psw->generation; }
extern "C" void InvertMatrix4Affine(M4 *, void *);
extern "C" void InvertMatrix3(M3 *, void *);
extern "C" void NormalizeRotateMatrix3__FP7MATRIX3(M3 *);
extern "C" void __as__6VECTORG9VU_VECTOR(void *, QW);
/* rotate vector by the 3x3 matrix whose rows are row0..row2 */
static inline QW Rotate(QW row0, QW row1, QW row2, QW vector)
{
    QW result;
    asm("vmulax.xyz ACC, %1, %4x\n\tvmadday.xyz ACC, %2, %4y\n\tvmaddz.xyz %0, %3, %4z" : "=j"(result) : "j"(row0), "j"(row1), "j"(row2), "j"(vector));
    return result;
}
extern "C" void UpdateXfMirror(void *pv, XFMIRROR *pmirror)
{
    M3 local;
    if (pmirror->fPosition != 0) {
        M4 inv;
        InvertMatrix4Affine(&inv, (char *)pmirror->pxfTarget->pxfParent + 0x40);
        XF *pxfSource = pmirror->pxfSource;
        XF *pxfTarget = pmirror->pxfTarget;
        QW pos = *(QW *)((char *)pxfSource + 0x70);
        QW vec;
        asm("vmulax.xyz ACC, %1, %5x\n\tvmadday.xyz ACC, %2, %5y\n\tvmaddaz.xyz ACC, %3, %5z\n\tvmaddw.xyz %0, %4, vf0w"
            : "=j"(vec) : "j"(inv.row[0]), "j"(inv.row[1]), "j"(inv.row[2]), "j"(inv.row[3]), "j"(pos));
        __as__6VECTORG9VU_VECTOR((char *)pxfTarget + 0x30, vec);
        *(float *)((char *)pxfTarget + 0x3C) = 1.0f;
    }
    if (pmirror->fRotation != 0) {
        M4 a;
        M3 inv;
        M3 b;
        InvertMatrix3(&inv, (char *)pmirror->pxfTarget->pxfParent + 0x40);
        QW *src = (QW *)((char *)pmirror->pxfSource + 0x40);
        QW row0 = Rotate(inv.row[0], inv.row[1], inv.row[2], src[0]);
        a.row[0] = row0;
        b.row[0] = row0;
        QW row1 = Rotate(inv.row[0], inv.row[1], inv.row[2], src[1]);
        a.row[1] = row1;
        b.row[1] = row1;
        QW row2 = Rotate(inv.row[0], inv.row[1], inv.row[2], src[2]);
        local.row[0] = row0;
        local.row[1] = row1;
        b.row[2] = row2;
        a.row[2] = row2;
        local.row[2] = row2;
        NormalizeRotateMatrix3__FP7MATRIX3(&local);
        XF *pxfTarget = pmirror->pxfTarget;
        ((QW *)pxfTarget)[0] = local.row[0];
        ((QW *)pxfTarget)[1] = local.row[1];
        ((QW *)pxfTarget)[2] = local.row[2];
        ((int *)pxfTarget)[3] = 0;
        ((int *)pxfTarget)[7] = 0;
        ((int *)pxfTarget)[0xB] = 0;
    }
    pmirror->pxfTarget->generation = NextGeneration(&B_003DD490);
}
