#include "sly2.h"
typedef int QW_1F2870 __attribute__((mode(TI)));
struct SOVT { char pad[0x1F0]; short delta; int (*fn)(void *); };
struct SO { char pad[0xC]; SOVT *vt; char pad2[0xEC - 0x10]; char *poxa; };
struct SRC { char pad[0x40]; QW_1F2870 s40; QW_1F2870 s50; QW_1F2870 s60; QW_1F2870 s70; char pad2[0xA4 - 0x80]; int sA4; };
struct GEOM { SRC *psrc; char pad[0x1C]; QW_1F2870 a20; QW_1F2870 a30; QW_1F2870 a40; QW_1F2870 a50; char pad2[0xA8 - 0x60]; int flagA8; int valAC; };
extern "C" {
void EnsureSoOxa(SO *);
int FFindDlEntry(void *, GEOM *);
void AppendDlEntry(void *, GEOM *);
void func_001F4BF8(SO *);
void func_001F38A8(GEOM *);
void func_001F5078(SO *);
}

extern "C" void AddSoGeomToOxa(SO *pso, GEOM *pgeom)
{
    EnsureSoOxa(pso);
    if (FFindDlEntry(pso->poxa + 0x34, pgeom)) {
        return;
    }
    AppendDlEntry(pso->poxa + 0x34, pgeom);
    pgeom->flagA8 = -1;
    SRC *psrc = pgeom->psrc;
    pgeom->a20 = psrc->s40;
    pgeom->a30 = psrc->s50;
    pgeom->a40 = psrc->s60;
    pgeom->a50 = psrc->s70;
    pgeom->valAC = psrc->sA4;
    func_001F4BF8(pso);
    func_001F38A8(pgeom);
    if (!pso->vt->fn((char *)pso + pso->vt->delta)) {
        func_001F5078(pso);
    }
}
