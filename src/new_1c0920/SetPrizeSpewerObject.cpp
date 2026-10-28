/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct VT48 { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct VT260 { char pad[0x260]; short delta; short index; void (*fn)(void *, int); };
struct PLO { char pad[0xC]; void *vptr; };
struct SO { char pad[0x150]; void *pxf; void *ploTemplate; void *ploPrize; };
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void *PloLeaseCloneObject(void *, int);
extern "C" void SelectCoinLootDef(void *, int);
extern "C" void *func_001F4C58(void *, int, int);
int SetPrizeSpewerObject(SO *pso, void *pobject, int idLoot, int oidSpawn)
{
    if (pso->ploPrize != 0)
        return 0;
    pso->ploTemplate = 0;
    if (FIsBasicDerivedFrom(pobject, 6) != 0) {
        pso->ploTemplate = pobject;
        void *ploClone = PloLeaseCloneObject(pobject, 0);
        pso->ploPrize = ploClone;
        if (ploClone == 0) {
            pso->ploTemplate = 0;
            return 1;
        }
    } else {
        if (FIsBasicDerivedFrom(pobject, 0x30) == 0)
            return 2;
        pso->ploPrize = pobject;
    }
    if (FIsBasicDerivedFrom(pso->ploPrize, 0x5E) != 0)
        SelectCoinLootDef(pso->ploPrize, idLoot);
    if (FIsBasicDerivedFrom(pso->ploPrize, 0x5A) != 0) {
        PLO *pplo = (PLO *)pso->ploPrize;
        VT260 *vtable = (VT260 *)pplo->vptr;
        vtable->fn((char *)pplo + vtable->delta, 2);
    } else {
        PLO *pplo = (PLO *)pso->ploPrize;
        VT48 *vtable = (VT48 *)pplo->vptr;
        vtable->fn((char *)pplo + vtable->delta);
    }
    pso->pxf = func_001F4C58(pso, oidSpawn, 0xD);
    return 3;
}
