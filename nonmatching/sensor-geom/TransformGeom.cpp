// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Rows { QW row[3]; };
struct SURF { QW plane; char pad[0x0C]; int ivertex; };
struct GEOM { int cpos; QW *apos; int csurf; SURF *asurf; };
extern "C" void TransformPoints(void *, int, QW *, QW *);
extern "C" Rows *InvertMatrix3(Rows *, void *);
struct Locals { Rows a; Rows b; Rows inv; Rows d; };
extern "C" void TransformGeom(void *pmat, GEOM *psrc, GEOM *pdst)
{
    Locals l;
    if (psrc->apos == pdst->apos)
        return;
    TransformPoints(pmat, psrc->cpos, psrc->apos, pdst->apos);
    InvertMatrix3(&l.inv, pmat);
    QW r0 = l.inv.row[0];
    QW r1 = l.inv.row[1];
    QW r2 = l.inv.row[2];
    QW lo0, hi0, lo2, hi2, c0, c1, c2;
    asm("pextlw %0, %1, %2" : "=r" (lo0) : "r" (r1), "r" (r0));
    asm("pextuw %0, %1, %2" : "=r" (hi0) : "r" (r1), "r" (r0));
    asm("pextlw %0, $0, %1" : "=r" (lo2) : "r" (r2));
    asm("pextuw %0, $0, %1" : "=r" (hi2) : "r" (r2));
    int csurf = psrc->csurf;
    asm("pcpyld %0, %1, %2" : "=r" (c0) : "r" (lo2), "r" (lo0));
    asm("pcpyud %0, %1, %2" : "=r" (c1) : "r" (lo0), "r" (lo2));
    asm("pcpyld %0, %1, %2" : "=r" (c2) : "r" (hi2), "r" (hi0));
    l.d.row[0] = c0;
    l.b.row[0] = c0;
    l.d.row[1] = c1;
    l.b.row[1] = c1;
    l.d.row[2] = c2;
    l.b.row[2] = c2;
    l.a.row[0] = c0;
    l.a.row[1] = c1;
    l.a.row[2] = c2;
    if (csurf > 0) {
        SURF *surf = psrc->asurf;
        asm("qmtc2.ni %0, vf1" : : "r" (c0));
        QW *aposFirst = pdst->apos;
        asm("qmtc2.ni %0, vf2" : : "r" (c1));
        int ivertex = surf->ivertex;
        SURF *out = pdst->asurf;
        asm("qmtc2.ni %0, vf3" : : "r" (c2));
        asm("lqc2 vf5, %0" : : "m" (surf->plane));
        asm("lqc2 vf4, %0" : : "m" (aposFirst[ivertex]));
        SURF *last = out + csurf - 1;
        surf++;
        QW t2, t3;
        goto entry;
    top:
        asm("qmtc2.ni %0, vf4" : : "r" (t2));
        out++;
        asm("qmtc2.ni %0, vf5" : : "r" (t3));
    entry:
        asm("vcallms 0x150");
        if (out < last) {
            t3 = surf->plane;
            t2 = pdst->apos[surf->ivertex];
            surf++;
        }
        asm("cfc2.i $2, $vi0" : : : "$2");
        asm("sqc2 vf5, 0(%0)" : : "r" (out) : "memory");
        if (out != last)
            goto top;
    }
}
