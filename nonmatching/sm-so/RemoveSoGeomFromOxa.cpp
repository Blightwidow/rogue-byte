#include "sly2.h"
struct SOVT { char pad[0x1F0]; short d; short i; int (*fn)(void *); };
struct SO;
struct GEOM { char pad[0x10]; unsigned long grf; char pad2[0xB0 - 0x18]; };
struct OXA { char pad[0x34]; char dl[0x2C]; SO *powner; };
struct SO { char pad[0xC]; SOVT *vt; char pad2[0xE0 - 0x10]; int cgeom; GEOM *ageom; int unkE8; OXA *poxa; };
extern "C" int FFindDlEntry(void *, void *);
extern "C" void RemoveDlEntry(void *, void *);
extern "C" int FIsDlEmpty__FP2DL(void *);
extern "C" void RemoveSafePointsOfLo(void *, int, GEOM *);
extern "C" void DiscardSoXps(SO *);
extern "C" void FreeSwPoxa(void *, OXA *);
extern "C" void func_001F5078(SO *);
extern "C" char B_003DD490;

void RemoveSoGeomFromOxa(SO *pso, GEOM *pgeom)
{
    if (pso->poxa == 0 || FFindDlEntry(pso->poxa->dl, pgeom) == 0)
        return;
    RemoveDlEntry(pso->poxa->dl, pgeom);
    if (pgeom->grf & (0x8000UL << 36))
        RemoveSafePointsOfLo(&B_003DD490, 0, pgeom);
    DiscardSoXps(pso);
    if (FIsDlEmpty__FP2DL(pso->poxa->dl) != 0) {
        OXA *poxa = pso->poxa;
        poxa->powner->poxa = 0;
        pso->poxa = 0;
        FreeSwPoxa(&B_003DD490, poxa);
    } else if (pso->poxa->powner != pso) {
        for (int igeom = pso->cgeom - 1; igeom >= 0; igeom--) {
            if (FFindDlEntry(pso->poxa->dl, (__typeof__(&(pso->ageom)[0]))((igeom) * sizeof((pso->ageom)[0]) + (unsigned)(pso->ageom))) != 0)
                goto vcall;
        }
        pso->poxa = 0;
    }
vcall:
    if (pso->vt->fn((char *)pso + pso->vt->d) == 0)
        func_001F5078(pso);
}
