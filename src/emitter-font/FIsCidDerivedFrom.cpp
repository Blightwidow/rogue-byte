// SPDX-License-Identifier: GPL-3.0-or-later
struct CLSDEF_15E988 { CLSDEF_15E988 *pclsdefBase; int cid; char pad[0xC]; };
extern CLSDEF_15E988 D_002BAAE8[];
extern "C" int FIsCidDerivedFrom(int cid, int cidBase)
{
    for (CLSDEF_15E988 *pclsdef = &D_002BAAE8[cid]; pclsdef != 0; pclsdef = pclsdef->pclsdefBase) {
        if (pclsdef->cid == cidBase)
            return 1;
    }
    return 0;
}
