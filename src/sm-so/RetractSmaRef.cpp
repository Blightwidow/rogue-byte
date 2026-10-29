// SPDX-License-Identifier: GPL-3.0-or-later
struct Vtbl_1F15B8 { char pad0[0x10]; short oThis; char pad1[2]; void (*pfnRetract)(void *); };
struct Obj_1F15B8 { char pad0[0xC]; Vtbl_1F15B8 *pvtbl; };
struct SmaRef_1F15B8 { Obj_1F15B8 *pobj; };
extern "C" void RetractSma(void *);

extern "C" void RetractSmaRef(SmaRef_1F15B8 *pref)
{
    if (pref->pobj != 0) {
        RetractSma(pref->pobj);
        Obj_1F15B8 *pobj = pref->pobj;
        Vtbl_1F15B8 *pvtbl = pobj->pvtbl;
        pvtbl->pfnRetract((char *)pobj + pvtbl->oThis);
        pref->pobj = 0;
    }
}
