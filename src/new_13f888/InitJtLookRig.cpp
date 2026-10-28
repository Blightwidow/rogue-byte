#include "sly2.h"
struct Rows3 { QW row[3]; };
struct Xf { char pad[0x40]; QW row[3]; };
struct Jt { char pad0[0x60]; Xf *pxfRoot; char pad1[0x1150 - 0x64]; Rows3 rest; };
extern "C" {
Xf *func_001F4C58(Jt *, int, int);
void InvertMatrix3(Rows3 *, void *);
QW DecomposeRotateMatrixEuler(Rows3 *);
void *func_0012DC18(Jt *, Xf *, int, int, int, QW);
void RemoveLookat(void *);
}
struct Locals { Rows3 a; Rows3 inv; Rows3 b; };
void InitJtLookRig(Jt *pjt, int oid)
{
    Locals l;
    Xf *pxf = func_001F4C58(pjt, oid, 6);
    if (pxf) {
        InvertMatrix3(&l.inv, (char *)pjt->pxfRoot + 0x40);
        asm("lqc2 vf5, %0" : : "m" (pxf->row[0]));
        Rows3 *pm = (Rows3 *)((char *)pxf + 0x40);
        asm("lqc2 vf3, %0" : : "m" (l.inv.row[0]));
        Rows3 *prest = &pjt->rest;
        asm("lqc2 vf6, %0" : : "m" (l.inv.row[1]));
        asm("lqc2 vf4, %0" : : "m" (l.inv.row[2]));
        asm("vmulax.xyz ACC, vf3, vf5x\n\tvmadday.xyz ACC, vf6, vf5y\n\tvmaddz.xyz vf5, vf4, vf5z");
        asm("sqc2 vf5, %0\n\tsqc2 vf5, %1" : "=m" (l.a.row[0]), "=m" (l.b.row[0]));
        asm("lqc2 vf2, %0" : : "m" (pm->row[1]));
        asm("vmulax.xyz ACC, vf3, vf2x\n\tvmadday.xyz ACC, vf6, vf2y\n\tvmaddz.xyz vf2, vf4, vf2z");
        asm("sqc2 vf2, %0\n\tsqc2 vf2, %1" : "=m" (l.a.row[1]), "=m" (l.b.row[1]));
        asm("lqc2 vf1, %0" : : "m" (pm->row[2]));
        asm("vmulax.xyz ACC, vf3, vf1x\n\tvmadday.xyz ACC, vf6, vf1y\n\tvmaddz.xyz vf3, vf4, vf1z");
        asm("sqc2 vf5, %0\n\tsqc2 vf2, %1\n\tsqc2 vf3, %2\n\tsqc2 vf3, %3" : "=m" (pjt->rest.row[0]), "=m" (pjt->rest.row[1]), "=m" (pjt->rest.row[2]), "=m" (l.b.row[2]));
        asm volatile("sqc2 vf3, %0" : "=m" (l.a.row[2]));
        QW euler = DecomposeRotateMatrixEuler(prest);
        void *pact = func_0012DC18(pjt, pxf, 3, 7, 2, euler);
        *(void **)((char *)pjt + 0x10F4) = pact;
        RemoveLookat(pact);
    }
}
