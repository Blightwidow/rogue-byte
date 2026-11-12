// SPDX-License-Identifier: GPL-3.0-or-later
#include "ps2inline.h"
#include "vu0inline.h"
#include "jt.h"
#include "sw.h"

struct FOCUSWATCH : SO {
    /* 0x150 */ s32 mode;
    /* 0x154 */ s32 clsid;
    /* 0x158 */ f32 gNear;
    /* 0x15C */ f32 gFar;
    u8 unknown_0x160[0x4];
    /* 0x164 */ s32 fActive;
};

extern SW B_003DD490;

extern "C" {
void UpdateSo(void *);
PO *PpoSwFocusBase(SW *);
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(void *);
}

extern "C" void func_0022A060(FOCUSWATCH *pwatch)
{
    QW posFocus;
    f32 gRange;
    s32 fActive;
    UpdateSo(pwatch);
    PO *ppo = PpoSwFocusBase(&B_003DD490);
    if (ppo == 0) {
        fActive = 0;
    } else if (!FIsBasicDerivedFrom(ppo, pwatch->clsid)) {
        fActive = 0;
    } else {
        gRange = pwatch->fActive ? pwatch->gFar : pwatch->gNear;
        fActive = 1;
        posFocus = PosLoWorld(ppo);
        if (LaneX(SqrtX(SquaredLength(VectorSub(posFocus, PosLoWorld(pwatch))))) < gRange) {
        } else
            fActive = 0;
    }
    s32 mode = pwatch->mode;
    if (mode == 0 || mode == 2) {
        fActive = (B_003DD490.pjobCurrent != 0) ? 0 : fActive;
    }
    if (fActive != 0 && FIsBasicDerivedFrom(ppo, 0x34) && (((JT *)ppo)->jmpState != -1 || ppo->NAlertLevel() == 2)) {
        fActive = pwatch->fActive;
    }
    if (fActive != pwatch->fActive) {
        pwatch->fActive = fActive;
        if (fActive != 0)
            pwatch->HandleSpliceEvent(5, 0, 0, 0, 0);
        else
            pwatch->HandleSpliceEvent(6, 0, 0, 0, 0);
    }
}
