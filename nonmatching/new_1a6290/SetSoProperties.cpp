#include "sly2.h"
struct XF { char pad0[0x9C]; int id; char pad1[0x60]; };
struct SO { char pad0[0x50]; int cxf; XF *axf; };
struct LOREF { unsigned grf; int key; int ibField; };
struct LO { char pad[0xC]; void **vptr; };
extern "C" {
void *PpartFindAlo(SO *, int);
void func_001F2AD0(SO *);
void *func_001F5FF8(SO *, int);
void func_001F69F8(SO *, int);
LO *PloFindSwObject_thunk(void *, int, int, SO *);
extern char B_003DD490[];
}
struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };

void SetSoProperties(SO *pso, int cref, const LOREF *aref)
{
    for (int iref = 0; iref < cref;) {
        const LOREF *pref = &aref[iref];
        if (pref->grf & 0x10) {
            iref++;
            int ixf = pso->cxf;
            while (--ixf >= 0) {
                XF *pxf = &pso->axf[ixf];
                if (pxf->id == pref->key) {
                    *(XF **)((char *)pso + pref->ibField) = pxf;
                    break;
                }
            }
        } else if (pref->grf & 0x20) {
            void *pgeom = PpartFindAlo(pso, pref->key);
            iref++;
            if (pgeom) {
                *(void **)((char *)pso + pref->ibField) = pgeom;
                if (pref->grf & 0x200)
                    func_001F2AD0(pso);
            }
        } else if (pref->grf & 0x40) {
            void *pglob = func_001F5FF8(pso, pref->key);
            iref++;
            if (pglob) {
                *(void **)((char *)pso + pref->ibField) = pglob;
                if (pref->grf & 0x200)
                    func_001F69F8(pso, pref->key);
            }
        } else {
            int grffso = 4;
            if ((pref->grf & 2) == 0)
                grffso = (pref->grf & 1) ? 5 : 1;
            if (pref->grf & 0x400)
                grffso |= 0x400;
            LO *plo = PloFindSwObject_thunk(B_003DD490, grffso, pref->key, pso);
            if (plo == 0) {
                iref++;
            } else {
                if (pref->grf & 0x200) {
                    VT *vt = (VT *)plo->vptr;
                    vt->fn((char *)plo + vt->delta);
                }
                iref++;
                *(LO **)((char *)pso + pref->ibField) = plo;
            }
        }
    }
}
