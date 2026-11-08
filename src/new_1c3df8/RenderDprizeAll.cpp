// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct MATRIX44 { float mat[4][4]; } __attribute__((aligned(16)));
struct ROWS3 { VECTOR row[3]; };
struct PD;
struct CVT { char pad[0x18]; short delta; short idx; void (*fn)(void *, float *, int, float, float); };
struct CHNO { CVT *vt; };
struct ENTRY { int u0; CHNO *pchn; };
struct ASEGA { char pad[0x14]; int pa14; char pad2[0x1C - 0x18]; float t; char pad3[0x40 - 0x20]; float u; };
struct SMA { char pad[0x30]; ASEGA *paseg; };
struct PD { char pad[0x12C]; float fade; char pad2[0x150 - 0x130]; int dprizes; char pad3[0x168 - 0x154]; SMA *psma; };
extern "C" void func_001F3C70(PD *);
extern "C" void func_001A5EE8(PD *, MATRIX44 *, float, float);
extern "C" void LoadMatrixFromPosRotScale(MATRIX44 *, QW, ROWS3 *, float *);
extern "C" ENTRY *PchnFindAseg(int, PD *, int, int);
extern "C" QW PosLoWorld(PD *);
extern "C" ROWS3 *PmatLoWorld(PD *);
// Retail's virtual call through the chain object passes a0 (object adjusted by the vtable delta at +0x18), a1 = the
// scale buffer, a2 = 0, f12 and f13 only: $a3 merely holds the object pseudo (a free argument register), as in SnapAsega,
// so the method takes (float *, int, float, float) and no fourth integer argument. The 0x90-byte frame buffer (scale
// at 0, matrix copy at 0x10, built matrix at 0x50) has the same layout and copy as the matched RenderLoot.
extern "C" void RenderDprizeAll(PD *pdprize)
{
    char buf[0x90] __attribute__((aligned(16)));
    if (pdprize->dprizes != 2) {
        SMA *psma = pdprize->psma;
        ASEGA *paseg;
        if (psma != 0 && (paseg = psma->paseg) != 0) {
            ENTRY *pentry = PchnFindAseg(paseg->pa14, pdprize, 0xC, 1);
            if (pentry != 0) {
                CHNO *pchn = pentry->pchn;
                CVT *vt = pchn->vt;
                vt->fn((char *)pchn + vt->delta, (float *)buf, 0, paseg->t, paseg->u);
                MATRIX44 *pmat = (MATRIX44 *)(buf + 0x50);
                QW pos = PosLoWorld(pdprize);
                LoadMatrixFromPosRotScale(pmat, pos, PmatLoWorld(pdprize), (float *)buf);
                *(MATRIX44 *)(buf + 0x10) = *(MATRIX44 *)(buf + 0x50);
                func_001A5EE8(pdprize, (MATRIX44 *)(buf + 0x10), pdprize->fade, pdprize->fade);
            } else {
                func_001F3C70(pdprize);
            }
        } else {
            func_001F3C70(pdprize);
        }
    }
}
