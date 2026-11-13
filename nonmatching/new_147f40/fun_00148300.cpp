// SPDX-License-Identifier: GPL-3.0-or-later
#include "ps2inline.h"
#include "vu0inline.h"
#include "dl.h"

struct ROOTOBJ;
struct ROOTVT { u8 unknown_0x0[0xB0]; s16 dlRemove; u8 pad[2]; void (*pfnRemove)(void *); s16 dlAppend; u8 pad2[2]; void (*pfnAppend)(void *); };
#define VCALL(pobj, which) ((pobj)->vt->pfn##which((u8 *)(pobj) + (pobj)->vt->dl##which))
struct ROOTOBJ {
    u8 unknown_0x0[0xC];
    ROOTVT *vt;
    u8 unknown_0x10[4];
    void *pvDle;
    u8 unknown_0x18[0x10];
    s64 grfPacked;
    u8 unknown_0x30[0xD];
};
struct ROOTSW { u8 unknown_0x0[0x2C]; DL dl; };

struct FOCUSG { u8 unknown_0x0[0x14]; s32 grfMask; u8 unknown_0x18[0x78]; QW pos; };
extern FOCUSG B_002DDF40;
extern s32 B_003E0E70;

extern "C" {
void *PpoSwFocusBase();
QW PosLoWorld(void *);
int FFindDlEntry(DL *, void *);
void AppendDlEntry(DL *, void *);
void RemoveDlEntry(DL *, void *);
}

void func_00148300(ROOTSW *psw, ROOTOBJ *pobj)
{
    if (B_003E0E70 != 0)
        return;
    int grfMask = B_002DDF40.grfMask;
    QW pos[2];
    pos[0] = B_002DDF40.pos;
    void *pvBase = PpoSwFocusBase();
    pos[1] = pvBase ? PosLoWorld(pvBase) : pos[0];
    void *pvDle = pobj->pvDle;
    int fActive;  // retail leaves it unset for types 4..15
    switch ((pobj->grfPacked << 8) >> 60) {
    case 0:
        if (grfMask & *(u8 *)((u8 *)pobj + 0x2D)) {
            float radius = *(float *)((u8 *)pobj + 0x38);
            fActive = 1;
            radius = radius * radius;
            QW here = PosLoWorld(pobj);
            QW delta = VectorSub(here, pos[0]);
            if (LaneX(SquaredLength(delta)) < radius)
                break;
        }
        fActive = 0;
        break;
    case 1:
        fActive = 1;
        break;
    case 3:
        if (grfMask & *(u8 *)((u8 *)pobj + 0x2D)) {
            float radius = *(float *)((u8 *)pobj + 0x38);
            fActive = 1;
            radius = radius * radius;
            QW here = PosLoWorld(pobj);
            QW delta = VectorSub(here, pos[1]);
            if (LaneX(SquaredLength(delta)) < radius)
                break;
        }
        fActive = 0;
        break;
    case 2:
        fActive = 0;
        break;
    default:
        break;
    }
    DL *pdl = &psw->dl;
    if (fActive != FFindDlEntry(pdl, pvDle)) {
        if (fActive != 0) {
            AppendDlEntry(pdl, pvDle);
            VCALL(pobj, Append);
        } else {
            VCALL(pobj, Remove);
            RemoveDlEntry(pdl, pvDle);
        }
    }
}
