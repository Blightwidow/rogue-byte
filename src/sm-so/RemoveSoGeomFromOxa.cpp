#include "sly2.h"
struct SOVT { char pad[0x1F0]; short thisAdjust; short slotIndex; int (*function)(void *); };
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

// Retail: the geometry scan is not rotated (bltz at the loop top, the back branch is the
// FFindDlEntry test with igeom-- in its delay slot), the "none found" store falls into the
// virtual call and the "found" exit jumps there. A for(;;) whose body tests igeom >= 0 first
// and keeps the clear-poxa exit in the else arm gives that layout; a for/while with the
// count in its condition is rotated by jump.c. The element address is written as integer
// arithmetic (index * size + base): retail adds the strength-reduced offset first
// (addu a1, s1, a1); &ageom[igeom] and ageom + igeom put the base first.
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
        int igeom = pso->cgeom;
        for (;;) {
            igeom--;
            if (igeom >= 0) {
                if (FFindDlEntry(pso->poxa->dl, (GEOM *)(igeom * sizeof(GEOM) + (unsigned int)pso->ageom)) == 0)
                    continue;
                break;
            } else {
                pso->poxa = 0;
                break;
            }
        }
    }
    if (pso->vt->function((char *)pso + pso->vt->thisAdjust) == 0)
        func_001F5078(pso);
}
