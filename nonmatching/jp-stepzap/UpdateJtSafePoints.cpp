// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct LIST;
struct SURF { char pad[0x40]; void *pgeom; char pad2[0x1C]; QW pos; char pad3[0x8]; float nz; };
struct OWNER { char pad[0x148]; unsigned long grfso; };
struct SURF2 { char pad[0x40]; void *pgeom; int u44; int u48; OWNER *powner; char pad2[0x10]; QW pos; char pad3[0x18]; float nz; };
struct MEMBER { char pad[0x10C]; int flag; };
struct JT {
    char pad0[0x4C0]; char look[0x4C0 - 0x4C0 + 1];
};
struct JT2 {
    char pad[0x208]; SURF2 *psurface;
};
extern QW g_2a2dd0;
extern "C" {
void AddSafePointOnGeom(void *, void *, QW);
void AddSafePointOnMember(void *, void *, float);
void func_001942F0(void *);
void UpdateJtPipeLook(void *);
}
struct JTX {
    char pad0[0x208];
    SURF2 *psurface;
    char pad1[0x4C0 - 0x20C];
    char look[0x9E0 - 0x4C0];
    char list[0xF50 - 0x9E0];
    char pipe[0x108C - 0xF50];
    int flag108c;
    char pad2[0x18C4 - 0x1090];
    MEMBER *pmember;
    int jts;
};
void UpdateJtSafePoints(JTX *pjt)
{
    volatile QW vecZero = g_2a2dd0;
    switch (pjt->jts) {
    case 0: case 1: case 5: case 6: case 9: case 10: case 0xb: case 0xc:
    case 0xf: case 0x10: case 0x11: case 0x14: case 0x17: case 0x18: {
        SURF2 *psurf = pjt->psurface;
        if (psurf != 0) {
            float k;
            asm("lui $1,0x3F33\n\tori $1,$1,0x3333\n\tmtc1 $1,%0\n\tnop" : "=f"(k) : : "$1");
            if (k < psurf->nz) {
                if ((psurf->powner->grfso & 0x20000000) == 0) {
                    if (pjt->flag108c == 0)
                        AddSafePointOnGeom(pjt->list, psurf->pgeom, psurf->pos);
                }
            }
        }
        break;
    }
    case 3:
    case 0x16: {
        MEMBER *pmember = pjt->pmember;
        if (pmember->flag == 0)
            AddSafePointOnMember(pjt->list, pmember ? (char *)pmember + 0x100 : 0, 0.0f);
        break;
    }
    case 7:
        func_001942F0(pjt->look);
        break;
    case 8:
        UpdateJtPipeLook(pjt->pipe);
        break;
    }
}
