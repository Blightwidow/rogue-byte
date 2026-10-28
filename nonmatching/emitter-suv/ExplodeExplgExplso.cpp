#include "sly2.h"
struct M4 { QW row[4]; };
struct XFR { QW pos; QW mat[3]; QW v40; QW v50; };
struct EXPLSO { unsigned flags; void *pref; char pad[0x2C]; XFR *pxf; int pad2[3]; };
struct EXPLSOQ { QW q[4]; };
union LOC { EXPLSOQ q; EXPLSO s; };
struct VT { char pad[0x198]; short delta; short index; void (*fn)(void *, EXPLSO *); };
struct EXPL { char pad[0xC]; VT *vptr; char pad2[0x50]; M4 mat; };
struct EXPLG { char pad[0x60]; M4 mat; char pad2[0x40]; int count; EXPL **items; };
extern "C" void InvertMatrix4Affine(M4 *, M4 *);
extern "C" void __ml__FRC7MATRIX4T0(M4 *, const M4 &, const M4 &);
#define rel (*(M4 *)(fr + 0xA0))
#define localu (*(LOC *)(fr))
#define xfr (*(XFR *)(fr + 0x40))
#define tmp (*(M4 *)(fr + 0xE0))
#define inv (*(M4 *)(fr + 0x120))
extern "C" void ExplodeExplgExplso(EXPLG *pexplg, EXPLSO *pexplso)
{
    char fr[0x160] __attribute__((aligned(16)));
    localu.q = *(EXPLSOQ *)pexplso;
    unsigned flags = localu.s.flags;
    localu.s.flags = flags | 0x40;
    localu.s.pxf = &xfr;
    if ((localu.s.flags & 1) == 0) {
        localu.s.flags = flags | 0x41;
        localu.s.pref = pexplg;
    }
    if (pexplg->count > 0) {
        int index = 0;
        M4 *prel = (M4 *)(fr + 0xA0);
        do {
            EXPL **items = pexplg->items;
            asm("" : "+r" (pexplg), "+r" (index));
            asm("" : "+r" (index));
            asm("" : "+r" (index));
            EXPL *pexpl = items[index];
            asm("" : "+r" (pexpl));
            asm("" : "+r" (pexpl));
            asm("" : "+r" (pexpl));
            InvertMatrix4Affine(&inv, &pexplg->mat);
            __ml__FRC7MATRIX4T0(&tmp, inv, pexpl->mat);
            asm volatile("lqc2 vf1, %0\n\tlqc2 vf7, %1" : : "m" (tmp.row[0]), "m" (tmp.row[3]));
            unsigned useParent = pexplso->flags & 0x40;
            rel.row[1] = tmp.row[1];
            rel.row[2] = tmp.row[2];
            asm volatile("sqc2 vf1, %0" : "=m" (rel.row[0]));
            asm volatile("sqc2 vf7, %0" : "=m" (rel.row[3]));
            if (useParent) {
                XFR *pxfp = pexplso->pxf;
                QW *pm = pxfp->mat;
                asm volatile("lqc2 vf3, %2\n\tlqc2 vf4, %3\n\tlqc2 vf6, %4\n\tvmulax.xyz ACC, vf3, vf1x\n\tvmadday.xyz ACC, vf6, vf1y\n\tvmaddz.xyz vf5, vf4, vf1z\n\tsqc2 vf5, %0\n\tsqc2 vf5, %1"
                    : "=m" (tmp.row[0]), "=m" (tmp.row[3]) : "m" (pxfp->mat[0]), "m" (pm[2]), "m" (pm[1]));
                asm volatile("lqc2 vf2, %2\n\tvmulax.xyz ACC, vf3, vf2x\n\tvmadday.xyz ACC, vf6, vf2y\n\tvmaddz.xyz vf2, vf4, vf2z\n\tsqc2 vf2, %0\n\tsqc2 vf2, %1"
                    : "=m" (tmp.row[1]), "=m" (inv.row[0]) : "m" (prel->row[1]));
                asm volatile("lqc2 vf1, %5\n\tvmulax.xyz ACC, vf3, vf1x\n\tvmadday.xyz ACC, vf6, vf1y\n\tvmaddz.xyz vf3, vf4, vf1z\n\tsqc2 vf5, %0\n\tsqc2 vf2, %1\n\tsqc2 vf3, %2\n\tsqc2 vf3, %3\n\tsqc2 vf3, %4"
                    : "=m" (xfr.mat[0]), "=m" (xfr.mat[1]), "=m" (xfr.mat[2]), "=m" (tmp.row[2]), "=m" (inv.row[1]) : "m" (prel->row[2]));
                asm volatile("lqc2 vf3, %1\n\tlqc2 vf4, %2\n\tlqc2 vf2, %3\n\tlqc2 vf1, %4\n\tvmulax.xyz ACC, vf3, vf7x\n\tvmadday.xyz ACC, vf2, vf7y\n\tvmaddz.xyz vf3, vf4, vf7z\n\tvadd.xyzw vf1, vf1, vf3\n\tsqc2 vf1, %0"
                    : "=m" (xfr.pos) : "m" (pxfp->mat[0]), "m" (pm[2]), "m" (pm[1]), "m" (pxfp->pos));
                xfr.v40 = pxfp->v40;
                xfr.v50 = pxfp->v50;
            } else {
                asm volatile("sqc2 vf1, %0" : "=m" (xfr.mat[0]));
                xfr.mat[1] = prel->row[1];
                QW row2 = prel->row[2];
                asm volatile("sqc2 vf7, %0" : "=m" (xfr.pos));
                xfr.mat[2] = row2;
                ((int *)&xfr.v40)[2] = 0; ((int *)&xfr.v40)[1] = 0; ((int *)&xfr.v40)[0] = 0;
                ((int *)&xfr.v50)[2] = 0; ((int *)&xfr.v50)[1] = 0; ((int *)&xfr.v50)[0] = 0;
            }
            pexpl->vptr->fn((char *)pexpl + pexpl->vptr->delta, &localu.s);
            index++;
        } while (index < pexplg->count);
    }
}
