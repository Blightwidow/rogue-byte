// SPDX-License-Identifier: GPL-3.0-or-later
struct Vtbl_133E30 { char pad0[0x188]; short oThis; char pad1[2]; void (*pfnVirt)(void *); };
struct Obj_133E30 { char pad0[0xC]; Vtbl_133E30 *pvtbl; };
struct Holder_133E30 { char pad0[0x60]; Obj_133E30 *pobj; };
struct Owner_133E30 { char pad0[0x3D28]; Holder_133E30 *pholder; };

extern "C" void func_00133E30(Owner_133E30 *powner)
{
    Holder_133E30 *pholder = powner->pholder;
    while (pholder != 0) {
        Obj_133E30 *pobj = pholder->pobj;
        Vtbl_133E30 *pvtbl = pobj->pvtbl;
        pvtbl->pfnVirt((char *)pobj + pvtbl->oThis);
        pholder = powner->pholder;
    }
}
