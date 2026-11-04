// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct MAT3_15B1B0 { QW r0, r1, r2; };
struct LO_15B1B0;
struct EMITREF_15B1B0 { LO_15B1B0 *plo; int pad4; int unk8; int padC; int unk10; };
struct EMITB { int unk0; int emitpk; EMITREF_15B1B0 *pemitref; char pad0[0xB0 - 0xC]; QW vec; int ript; int ripgt; char pad1[0xD8 - 0xC8]; float gMin; float gMax; char pad2[0xE4 - 0xE0]; float fE4; float fE8; };
struct RIPG_15B1B0;
struct EMITG { int unk0; RIPG_15B1B0 **ppripg; LO_15B1B0 *plo; };
struct RVTE1_15B1B0 { short delta; short index; void (*fn)(char *, QW, float, int); };
struct RVTE2_15B1B0 { short delta; short index; void (*fn)(char *, EMITB *); };
struct RVT_15B1B0 { char pad[8]; RVTE1_15B1B0 init; RVTE2_15B1B0 post; };
struct EMITDV_15B1B0 { char pad[1]; };
struct RIP_15B1B0 {
    char pad0[0x14]; float tc; float td; int unk1C; char pad1[0x24 - 0x20]; float fE4; float fE8; char pad2[0x30 - 0x2C];
    QW vec; MAT3_15B1B0 mat; char pad3[0x90 - 0x70]; QW v; EMITDV_15B1B0 emitdv[0x4C]; RVT_15B1B0 *vt;
};
struct GVT_15B1B0 { char pad[0x48]; short delta; short index; void (*fn)(char *); };
struct DL_15B1B0 { int a; };
struct RIPG_15B1B0 { char pad0[0xC]; GVT_15B1B0 *vt; char pad1[0x15C - 0x10]; DL_15B1B0 dlRip; };
struct SWX_15B1B0 { char pad[1]; };
extern SWX_15B1B0 B_003DD490;
extern "C" {
RIPG_15B1B0 *PripgNew(SWX_15B1B0 *, int);
RIP_15B1B0 *PripNewRipg(SWX_15B1B0 *, int, RIPG_15B1B0 *);
void SetRipgEmitb__FP4RIPGP5EMITB(RIPG_15B1B0 *, EMITB *);
void SubscribeLoObject(RIPG_15B1B0 *, LO_15B1B0 *);
float GRandInRange(float, float);
void SetEmitdvEmitb__FP6EMITDVP5EMITB(EMITDV_15B1B0 *, EMITB *);
MAT3_15B1B0 *PmatLoWorld(LO_15B1B0 *);
int FIsDlEmpty__FP2DL(DL_15B1B0 *);
}

void EmitRips(EMITB *pemitb, EMITG *pemitg, int crip, VECTOR *apos, VECTOR *av, float *atc, float *atd)
{
    RIPG_15B1B0 *pripg = 0;
    if (pemitg != 0 && pemitg->ppripg != 0)
        pripg = *pemitg->ppripg;
    if (pripg == 0) {
        pripg = PripgNew(&B_003DD490, pemitb->ripgt);
        if (pripg == 0)
            return;
        if (pemitg != 0 && pemitg->ppripg != 0)
            *pemitg->ppripg = pripg;
        SetRipgEmitb__FP4RIPGP5EMITB(pripg, pemitb);
        if (pemitg != 0 && pemitg->plo != 0)
            SubscribeLoObject(pripg, pemitg->plo);
        if (pripg == 0)
            return;
    }
    for (int irip = 0; irip < crip; irip++) {
        RIP_15B1B0 *prip = PripNewRipg(&B_003DD490, pemitb->ript, pripg);
        if (prip == 0)
            break;
        RVTE1_15B1B0 *pinit = &prip->vt->init;
        pinit->fn((char *)prip + pinit->delta, *(QW *)&apos[irip], GRandInRange(pemitb->gMin, pemitb->gMax), pemitb->pemitref->unk10);
        if (pemitb->fE4 != 0.0f || pemitb->fE8 != 0.0f) {
            prip->fE4 = pemitb->fE4;
            prip->fE8 = pemitb->fE8;
        }
        prip->v = *(QW *)&av[irip];
        prip->tc = atc[irip];
        prip->td = atd[irip] - atc[irip];
        prip->vec = pemitb->vec;
        SetEmitdvEmitb__FP6EMITDVP5EMITB(prip->emitdv, pemitb);
        prip->unk1C = pemitb->pemitref->unk8;
        if (pemitb->pemitref->plo != 0)
            prip->mat = *PmatLoWorld(pemitb->pemitref->plo);
        prip->vt->post.fn((char *)prip + prip->vt->post.delta, pemitb);
    }
    if (FIsDlEmpty__FP2DL(&pripg->dlRip))
        pripg->vt->fn((char *)pripg + pripg->vt->delta);
}
