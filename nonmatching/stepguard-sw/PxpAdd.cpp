// SPDX-License-Identifier: GPL-3.0-or-later
#include "vu0inline.h"
#include "ps2inline.h"
#include "types.h"
struct SW;
struct XP;
struct XPSOVT { char pad[0x1B8]; short delta; short index; void (*fn)(void *, XP *, int, void *); };
struct XPSO { char pad[0xC]; XPSOVT *vt; };
struct XPSEC { char pad[0x60]; int unk60; };
struct XPOWN { char pad[0xEC]; XPSEC *psec; };
struct XPOBJ { int unk0; XPOWN *powner; };
struct XPD { XPOBJ *pobj; int unk4; int unk8; XPSO *pso; QW pos; QW posConv; QW vel; };
struct XP {
    XPD xpd[2];
    QW velBase;
    float gA; float gB; float gC; int n9C; int nA0; int nA4; int unkA8; XP *pxpNext;
};
union VU_SCALE { QW q; float g[4]; };
extern "C" {
void *PvAllocSlotheapImpl(void *);
QW ConvertXfPos(int, int, QW);
void RecalcSwXpMovement(SW *, int, XP **);
extern float D_FLT_002BFD30;
extern float D_FLT_002BFD34;
void PxpAdd(char *psw, void *pobjA, void *pobjB, QW pos, QW vel, int arg5, int arg6, int arg7, float gScale, XP **ppxpHead)
{
    VU_SCALE scale;
    XP *pxp;
    XPD *pxpd;
    XP *pxpNew = (XP *)PvAllocSlotheapImpl(psw + 0x3D40);
    pxp = pxpNew;
    pxpNew->xpd[0].pos = pos;
    scale.q = VectorFromFloat(-gScale);
    pxpNew->xpd[1].pos = ScaleAddX(pos, vel, scale.q);
    pxpNew->velBase = vel;
    int ixpd = 0;
    do {
        pxpd = &pxp->xpd[ixpd];
        if (ixpd == 0)
            pxpd->pobj = (XPOBJ *)pobjA;
        else
            pxpd->pobj = (XPOBJ *)pobjB;
        XPOBJ *pobj = pxpd->pobj;
        if (pobj) {
            pxpd->unk4 = pobj->unk0;
            XPOWN *powner = pobj->powner;
            pxpd->pso = (XPSO *)powner;
            pxpd->unk8 = powner->psec->unk60;
        }
        ixpd++;
        pxpd->posConv = ConvertXfPos(0, pxpd->unk4, pxpd->pos);
    } while (ixpd < 2);
    pxp->nA0 = arg6;
    pxp->nA4 = arg7;
    pxp->gA = gScale;
    pxp->n9C = arg5;
    pxp->gB = D_FLT_002BFD30;
    pxp->gC = D_FLT_002BFD34;
    ixpd = 0;
    do {
        pxpd = &pxp->xpd[ixpd];
        XPSO *pso = pxpd->pso;
        if (pso)
            pso->vt->fn((char *)pso + pso->vt->delta, pxp, ixpd, pso);
        ixpd++;
    } while (ixpd < 2);
    RecalcSwXpMovement((SW *)psw, 1, &pxp);
    XP *pxpLast = pxp;
    while (pxpLast->pxpNext)
        pxpLast = pxpLast->pxpNext;
    pxpLast->pxpNext = *ppxpHead;
    *ppxpHead = pxp;
}
}
