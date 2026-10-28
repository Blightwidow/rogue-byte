#include "sly2.h"
struct VT {
    char pad[0x1C0];
    short delta0; short index0; void (*fn0)(void *, void *, int);
    short delta1; short index1; void (*fn1)(void *, void *, int);
};
struct SO { char pad[0xC]; VT *vt; };
struct XPD { int unk0; void *pxf; int unk8; SO *pso; QW pos; QW unk20; QW vel; };
struct XP { XPD xpd[2]; QW pad80[3]; QW velRel; };
struct SW;
extern "C" QW VelocityXfAtPos(void *, int, QW);
void RecalcSwXpMovement(SW *psw, int cpxp, XP **apxp) {
    int ixpd;
    for (int ipxp = 0; ipxp < cpxp; ipxp++) {
        XP *pxp = apxp[ipxp];
        XPD *pxpd = pxp->xpd;
        ixpd = 0;
        do {
            if (pxpd->pxf) {
                pxpd->vel = VelocityXfAtPos(pxpd->pxf, 0, pxpd->pos);
                SO *pso = pxpd->pso;
                pso->vt->fn0((char *)pso + pso->vt->delta0, pxp, ixpd);
            }
            ixpd++;
            pxpd++;
        } while (ixpd < 2);
        ixpd = 0;
        pxpd = pxp->xpd;
        SO **ppso = &pxpd->pso;
        do {
            SO *pso = *ppso;
            if (pso) pso->vt->fn1((char *)pso + pso->vt->delta1, pxp, ixpd);
            ixpd++;
            ppso += 0x10;
        } while (ixpd < 2);
        register QW va asm("vf1") = pxp->xpd[0].vel;
        register QW vb asm("vf2") = pxp->xpd[1].vel;
        asm("vsub.xyzw vf1, vf1, vf2" : "=j"(va) : "j"(va), "j"(vb));
        pxp->velRel = va;
    }
}
