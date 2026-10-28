/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct XF { char pad[0x98]; short kind; };
struct VT { char pad[0x208]; struct { short delta; short index; void (*fn)(void *); } slot[3]; };
struct SO { char pad0[0xC]; VT *vt; char pad1[0x58 - 0x10]; XF *pxfLin; XF *pxfAng; char pad2[0xE8 - 0x60]; char *pphys; };
struct XP { char pad[0x80]; QW v80; char pad2[0x90 - 0x90]; float g90; };
struct DZ { int dzk; float gMin; float gMax; int pad; float gTarget; char pad2[0x28 - 0x14]; };
struct DZG { char pad0[8]; DZ *adz; char pad1[0x60 - 0x0C]; char *axpd; char pad2[0x70 - 0x64]; };
struct SW;
extern "C" const float RO_FLT_002A8280;
extern "C" const float RO_FLT_002A8284;
extern "C" float g_2dded0[2];
extern "C" char B_003DD490[];
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void InitDzg(DZG *, int, XP **, int, SO **);
extern "C" void AppendDzgDz__FP3DZGP2DZ(DZG *, DZ *);
extern "C" void SolveDzg__FP3DZGiiPP2XPPiPPP2SO(DZG *, int);
extern "C" void SolveDzgFric__FP3DZGiiPP2XPPiPPP2SOf(DZG *, int);
extern "C" void ApplyDzg(DZG *, float, float);
extern "C" void ClearDzgSolution__FP3DZG(DZG *);
extern "C" void RecalcSwXpPos(void *, int, XP **);
extern "C" void RecalcSwXpMovement(void *, int, XP **);
extern "C" float GRandInRange(float, float);
extern "C" void SleepSo(SO *);

static inline float Lane(int q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
/* dot(+0x80, +0xB0) of a record */
static inline int DotAB(XP *p)
{
    int r;
    asm volatile("lqc2 vf1, 0x80(%1)\n\tlqc2 vf2, 0xB0(%1)\n\tvmul.xyz vf2, vf2, vf1\n\tvaddw.x vf3, vf0, vf0w\n\t"
        "vadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tqmfc2.ni %0, vf2" : "=r" (r) : "r" (p));
    return r;
}
static inline int DotBB(char *p, int off)
{
    int r;
    asm volatile("lqc2 vf1, %2(%1)\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\t"
        "vadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (r) : "r" (p), "i" (off));
    return r;
}

void SolveSwGroup(SW *psw, int grf, int cso, SO **apso, int cxp, XP **axp)
{
    struct { char frame[0x10]; DZG dzg; } l;
    CStackFrame_Construct(l.frame);
    InitDzg(&l.dzg, cxp, axp, cso, apso);
    if (cxp > 0) {
        float lo = RO_FLT_002A8280;
        float hi = RO_FLT_002A8284;
        float zero = 0.0f;
        for (int ixp = 0; ixp < cxp; ixp++) {
            XP *pxp = axp[ixp];
            char *pxpd = l.dzg.axpd + ixp * 0x60;
            DZ *pdz = &l.dzg.adz[ixp];
            *(XP **)(pxpd + 0x50) = pxp;
            *(QW *)(pxpd + 0x40) = pxp->v80;
            int kind = *(int *)((char *)pxp + 0x9C);
            switch (kind) {
            case 0xB:
                pdz->dzk = 1;
                pdz->gMin = lo;
                pdz->gMax = hi;
                break;
            case 0xE:
                if ((grf & 1) == 0) {
                    pdz->gMin = 0.0f;
                    pdz->dzk = 0;
                    pdz->gMax = hi;
                } else {
                    pdz->gMin = *(float *)((char *)pxp + 0xA0) * g_2dded0[1];
                    pdz->gMax = *(float *)((char *)pxp + 0xA4) * g_2dded0[1];
                    pdz->dzk = *(float *)((char *)pxp + 0xA0) < zero ? 1 : 0;
                }
                break;
            default:
                pdz->dzk = 0;
                pdz->gMin = 0.0f;
                pdz->gMax = hi;
            }
            AppendDzgDz__FP3DZGP2DZ(&l.dzg, pdz);
            asm volatile("" : : "r" (pxp), "r" (pdz));
        }
    }
    if ((grf & 4) != 0) {
        float gMax = 0.0f;
        if (cxp > 0) {
            int off = 0;
            XP **pp = axp;
            for (int count = cxp; count != 0; count--, pp++) {
                XP *pxp = *pp;
                DZ *pdz = (DZ *)((char *)l.dzg.adz + off);
                if (pdz->dzk == 1)
                    pdz->gTarget = pxp->g90;
                else
                    pdz->gTarget = pxp->g90 + 1.0f;
                float mag = __builtin_fabsf(pxp->g90);
                if (gMax < mag)
                    gMax = mag;
                off += 0x28;
            }
        }
        SolveDzg__FP3DZGiiPP2XPPiPPP2SO(&l.dzg, 4);
        ApplyDzg(&l.dzg, gMax + gMax, 6.2831855f);
        for (int index = 0; index < cso; index++)
            asm volatile("nop\n\tnop\n\tnop\n\tnop");
        for (int index = 0; index < cso; index++) {
            SO *pso = apso[index];
            pso->vt->slot[2].fn((char *)pso + pso->vt->slot[2].delta);
        }
        if (grf == 4) {
            CStackFrame_Destructor(l.frame, 2);
            return;
        }
        ClearDzgSolution__FP3DZG(&l.dzg);
    }
    int fResting = grf & 1;
    float gMaxLen = 0.0f;
    if (fResting != 0) {
        RecalcSwXpPos(psw, cxp, axp);
        RecalcSwXpMovement(psw, cxp, axp);
        if (cxp > 0) {
            int off = 0;
            XP **pp = axp;
            for (int count = cxp; count != 0; count--, pp++) {
                XP *pxp = *pp;
                DZ *pdz = (DZ *)((char *)l.dzg.adz + off);
                *(int *)&pdz->gTarget = DotAB(pxp);
                float len = Lane(DotBB((char *)pxp, 0xB0));
                if (gMaxLen < len)
                    gMaxLen = len;
                off += 0x28;
            }
        }
    } else if (0 < cxp) {
        float one = 1.0f;
        int off = 0;
        XP **pp = axp;
        for (int count = cxp; count != 0; count--, pp++) {
            DZ *pdz = (DZ *)((char *)l.dzg.adz + off);
            float rnd = GRandInRange(0.9f, 1.1f);
            XP *pxp = *pp;
            float rest = *(float *)((char *)pxp + 0x98) * rnd;
            int dot = DotAB(pxp);
            pdz->gTarget = Lane(dot) * (rest + one);
            float len = Lane(DotBB((char *)pxp, 0xB0));
            if (gMaxLen < len)
                gMaxLen = len;
            off += 0x28;
        }
    }
    SolveDzgFric__FP3DZGiiPP2XPPiPPP2SOf(&l.dzg, grf);
    float root = __builtin_sqrtf(gMaxLen);
    ApplyDzg(&l.dzg, root + root, 50.0f);
    for (int index = 0; index < cso; index++)
        asm volatile("nop\n\tnop\n\tnop\n\tnop");
    if (fResting == 0) {
        for (int index = 0; index < cso; index++) {
            SO *pso = apso[index];
            pso->vt->slot[1].fn((char *)pso + pso->vt->slot[1].delta);
        }
    } else {
        for (int index = 0; index < cso; index++) {
            SO *pso = apso[index];
            pso->vt->slot[0].fn((char *)pso + pso->vt->slot[0].delta);
        }
        int index = 0;
        for (; index < cso; index++) {
            SO *pso = apso[index];
            XF *pxfLin = pso->pxfLin;
            if (pxfLin->kind == 2)
                break;
            XF *pxfAng = pso->pxfAng;
            if (pxfAng->kind == 2)
                break;
            char *pphys = pso->pphys;
            int fMoving = 0;
            if (25.0f < Lane(DotBB((char *)pxfLin, 0xB0)))
                fMoving = 1;
            else if (0.0025f < Lane(DotBB((char *)pxfAng, 0xB0)))
                fMoving = 1;
            else if (25.0f < Lane(DotBB(pphys, 0x60)))
                fMoving = 1;
            else if (0.0025f < Lane(DotBB(pphys, 0x70)))
                fMoving = 1;
            if (fMoving)
                break;
        }
        if (index >= cso) {
            for (int sleepIndex = 0; sleepIndex < cso; sleepIndex++)
                SleepSo(apso[sleepIndex]);
            RecalcSwXpPos(B_003DD490, cxp, axp);
            RecalcSwXpMovement(B_003DD490, cxp, axp);
        }
    }
    CStackFrame_Destructor(l.frame, 2);
}
