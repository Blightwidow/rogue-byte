#include "sly2.h"
struct XF2 { char pad0[0x40]; QW m[4]; char pad1[0x24]; int gen; };
struct SOVT { char pad[0x1F0]; short d; short i; int (*fn)(void *); };
struct OXA { char pad[0x34]; };
struct SO { char pad[0xC]; SOVT *vt; char pad2[0xEC - 0x10]; OXA *poxa; };
struct GEOM { XF2 *pxf; char pad[0x1C]; QW m[4]; char pad2[0x48]; int bg; int mg; };
extern "C" void EnsureSoOxa(SO *);
extern "C" int FFindDlEntry(void *, void *);
extern "C" void AppendDlEntry(void *, void *);
extern "C" void func_001F4BF8(SO *, XF2 *);
extern "C" void func_001F38A8(GEOM *);
extern "C" void func_001F5078(SO *);
void AddSoGeomToOxa(SO *pso, GEOM *pgeom)
{
    EnsureSoOxa(pso);
    void *dl = (char *)pso->poxa + 0x34;
    if (!FFindDlEntry(dl, pgeom)) {
        AppendDlEntry((char *)pso->poxa + 0x34, pgeom);
        pgeom->bg = -1;
        register XF2 *pxf asm("$5") = pgeom->pxf;
        pgeom->m[0] = pxf->m[0];
        pgeom->m[1] = pxf->m[1];
        pgeom->m[2] = pxf->m[2];
        pgeom->m[3] = pxf->m[3];
        pgeom->mg = pxf->gen;
        func_001F4BF8(pso, pxf);
        func_001F38A8(pgeom);
        if (!pso->vt->fn((char *)pso + pso->vt->d))
            func_001F5078(pso);
    }
}
