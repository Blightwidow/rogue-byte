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
    register QW c0 asm("$3");
    register QW c1 asm("$6");
    register QW c2 asm("$7");
    register int csurf asm("$9");
    asm volatile("lq $8, %4\n\tlq $7, %5\n\tlq $2, %6\n\tpextlw $6, $7, $8\n\tpextuw $5, $7, $8\n\tpextlw $4, $0, $2\n\tpextuw $3, $0, $2\n\tlw $9, 8(%7)\n\tpcpyld $2, $4, $6\n\tpcpyud $8, $6, $4\n\tpcpyld $7, $3, $5\n\tpor $3, $0, $2\n\tpor $6, $0, $8"
                 : "=r" (c0), "=r" (c1), "=r" (c2), "=r" (csurf) : "m" (l.inv.row[0]), "m" (l.inv.row[1]), "m" (l.inv.row[2]), "r" (psrc) : "$2", "$4", "$5", "$8");
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
        register QW t2 asm("$18");
        register QW t3 asm("$19");
        SURF *surf = psrc->asurf;
        asm("qmtc2.ni %0, vf1" : : "r" (c0));
        QW *aposFirst = pdst->apos;
        asm("qmtc2.ni %0, vf2" : : "r" (c1));
        int ivertex = surf->ivertex;
        register SURF *out asm("$6") = pdst->asurf;
        asm("qmtc2.ni %0, vf3" : : "r" (c2));
        asm("lqc2 vf5, %0" : : "m" (surf->plane));
        asm("lqc2 vf4, %0" : : "m" (aposFirst[ivertex]));
        register SURF *last asm("$4") = out + csurf - 1;
        surf++;
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
        asm volatile("cfc2.i $2, $vi0" : : : "$2");
        asm("sqc2 vf5, 0(%0)" : : "r" (out) : "memory");
        if (out != last)
            goto top;
    }
}
