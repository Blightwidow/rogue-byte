/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct XF_1F9410 { char pad[0x98]; short kind; };
struct VTE_1F9410 { short delta; short index; void (*fn)(void *); };
struct VT_1F9410 { char pad[0x208]; VTE_1F9410 slot[3]; };
struct SO { char pad0[0xC]; VT_1F9410 *vt; char pad1[0x58 - 0x10]; XF_1F9410 *pxfLin; XF_1F9410 *pxfAng; char pad2[0xE8 - 0x60]; char *pphys; };
struct XP { char pad[0x80]; QW v80; char pad90[0x90 - 0x90]; float g90; char pad94[0x98 - 0x94]; float gRestitution; int kind; float gA0; float gA4; };
struct DZ_1F9410 { int dzk; float gMin; float gMax; int pad; float gTarget; char pad2[0x28 - 0x14]; };
struct XPD_1F9410 { char pad0[0x40]; QW v; XP *pxp; char pad54[0x60 - 0x54]; };
struct DZG_1F9410 { char pad0[8]; DZ_1F9410 *adz; char pad1[0x60 - 0x0C]; XPD_1F9410 *axpd; char pad2[0x70 - 0x64]; };
struct SW;
extern "C" const float RO_FLT_002A8280;
extern "C" const float RO_FLT_002A8284;
extern "C" float g_2dded0[2];
extern "C" char B_003DD490[];
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void InitDzg(DZG_1F9410 *, int, XP **, int, SO **);
extern "C" void AppendDzgDz__FP3DZGP2DZ(DZG_1F9410 *, DZ_1F9410 *);
extern "C" void SolveDzg__FP3DZGiiPP2XPPiPPP2SO(DZG_1F9410 *, int);
extern "C" void SolveDzgFric__FP3DZGiiPP2XPPiPPP2SOf(DZG_1F9410 *, int);
extern "C" void ApplyDzg(DZG_1F9410 *, float, float);
extern "C" void ClearDzgSolution__FP3DZG(DZG_1F9410 *);
extern "C" void RecalcSwXpPos(void *, int, XP **);
extern "C" void RecalcSwXpMovement(void *, int, XP **);
extern "C" float GRandInRange(float, float);
extern "C" void SleepSo(SO *);

static inline float FloatFromBits_1F9410(int bits) { return *(float *)&bits; }
/* dot(+0x80, +0xB0) of a record */
static inline int DotAB_1F9410(XP *p)
{
    int r;
    asm volatile("lqc2 vf1, 0x80(%1)\n\tlqc2 vf2, 0xB0(%1)\n\tvmul.xyz vf2, vf2, vf1\n\tvaddw.x vf3, vf0, vf0w\n\t"
        "vadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tqmfc2.ni %0, vf2" : "=r" (r) : "r" (p));
    return r;
}
/* dot(a->+0xB0, b->+0xB0), the product left in vf2 */
static inline void DotXfXf_1F9410(XF_1F9410 *pxfA, XF_1F9410 *pxfB)
{
    asm volatile("lqc2 vf2, 0xB0(%0)\n\tlqc2 vf1, 0xB0(%1)\n\tvmul.xyz vf2, vf2, vf1\n\tvaddw.x vf3, vf0, vf0w\n\t"
        "vadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z" : : "r" (pxfA), "r" (pxfB));
}
static inline int DotBB_1F9410(char *p, int off)
{
    int r;
    asm volatile("lqc2 vf1, %2(%1)\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\t"
        "vadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (r) : "r" (p), "i" (off));
    return r;
}

void SolveSwGroup(SW *psw, int grf, int cso, SO **apso, int cxp, XP **axp)
{
    struct { char frame[0x10]; DZG_1F9410 dzg; } l;
    XP *pxp;
    DZ_1F9410 *pdz;
    int ixp;
    int iso;
    float gMax;
    CStackFrame_Construct(l.frame);
    InitDzg(&l.dzg, cxp, axp, cso, apso);
    if (cxp > 0) {
        float lo = RO_FLT_002A8280;
        float hi = RO_FLT_002A8284;
        float zero = 0.0f;
        for (ixp = 0; ixp < cxp; ixp++) {
            XPD_1F9410 *pxpd = &l.dzg.axpd[ixp];
            pxp = axp[ixp];
            pdz = &l.dzg.adz[ixp];
            pxpd->pxp = pxp;
            pxpd->v = pxp->v80;
            switch (pxp->kind) {
            case 0xB:
                pdz->dzk = 1;
                pdz->gMin = lo;
                pdz->gMax = hi;
                break;
            case 0xE:
                if (grf & 1) {
                    pdz->gMin = pxp->gA0 * g_2dded0[1];
                    pdz->gMax = pxp->gA4 * g_2dded0[1];
                    pdz->dzk = pxp->gA0 < zero ? 1 : 0;
                } else {
                    pdz->gMin = 0.0f;
                    pdz->gMax = hi;
                    pdz->dzk = 0;
                }
                break;
            default:
                pdz->dzk = 0;
                pdz->gMin = 0.0f;
                pdz->gMax = hi;
                break;
            }
            AppendDzgDz__FP3DZGP2DZ(&l.dzg, pdz);
        }
    }
    if (grf & 4) {
        gMax = 0.0f;
        for (ixp = 0; ixp < cxp; ixp++) {
            pdz = &l.dzg.adz[ixp];
            pxp = axp[ixp];
            if (pdz->dzk == 1)
                pdz->gTarget = pxp->g90;
            else
                pdz->gTarget = pxp->g90 + 1.0f;
            float mag = __builtin_fabsf(pxp->g90);
            if (gMax < mag)
                gMax = mag;
        }
        SolveDzg__FP3DZGiiPP2XPPiPPP2SO(&l.dzg, 4);
        ApplyDzg(&l.dzg, gMax + gMax, 6.2831855f);
        for (iso = 0; iso < cso; iso++)
            ;
        for (iso = 0; iso < cso; iso++) {
            SO *pso = apso[iso];
            pso->vt->slot[2].fn((char *)pso + pso->vt->slot[2].delta);
        }
        if (grf == 4) {
            CStackFrame_Destructor(l.frame, 2);
            return;
        }
        ClearDzgSolution__FP3DZG(&l.dzg);
    }
    gMax = 0.0f;
    int fResting = grf & 1;
    if (fResting) {
        RecalcSwXpPos(psw, cxp, axp);
        RecalcSwXpMovement(psw, cxp, axp);
        for (ixp = 0; ixp < cxp; ixp++) {
            pxp = axp[ixp];
            pdz = &l.dzg.adz[ixp];
            *(int *)&pdz->gTarget = DotAB_1F9410(pxp);
            float len = FloatFromBits_1F9410(DotBB_1F9410((char *)pxp, 0xB0));
            if (gMax < len)
                gMax = len;
        }
    } else {
        for (ixp = 0; ixp < cxp; ixp++) {
            pdz = &l.dzg.adz[ixp];
            pxp = axp[ixp];
            float rnd = GRandInRange(0.9f, 1.1f);
            float rest = pxp->gRestitution * rnd;
            float dot = FloatFromBits_1F9410(DotAB_1F9410(pxp));
            pdz->gTarget = dot * (rest + 1.0f);
            float len = FloatFromBits_1F9410(DotBB_1F9410((char *)pxp, 0xB0));
            if (gMax < len)
                gMax = len;
        }
    }
    SolveDzgFric__FP3DZGiiPP2XPPiPPP2SOf(&l.dzg, grf);
    float root = __builtin_sqrtf(gMax);
    ApplyDzg(&l.dzg, root + root, 50.0f);
    for (iso = 0; iso < cso; iso++)
        ;
    if (fResting) {
        for (iso = 0; iso < cso; iso++) {
            SO *pso = apso[iso];
            pso->vt->slot[0].fn((char *)pso + pso->vt->slot[0].delta);
        }
        for (iso = 0; iso < cso; iso++) {
            SO *pso = apso[iso];
            XF_1F9410 *pxfLin = pso->pxfLin;
            if (pxfLin->kind == 2)
                break;
            XF_1F9410 *pxfAng = pso->pxfAng;
            if (pxfAng->kind == 2)
                break;
            char *pphys = pso->pphys;
            int fMoving = 0;
            if (25.0f < FloatFromBits_1F9410(DotBB_1F9410((char *)pso->pxfLin, 0xB0)))
                fMoving = 1;
            else {
                DotXfXf_1F9410(pxfAng, pso->pxfAng);
                int bits;
                asm volatile("qmfc2.ni %0, vf2" : "=r" (bits));
                if (0.00250000018f < FloatFromBits_1F9410(bits))
                    fMoving = 1;
                else if (25.0f < FloatFromBits_1F9410(DotBB_1F9410(pphys, 0x60)))
                    fMoving = 1;
                else if (0.00250000018f < FloatFromBits_1F9410(DotBB_1F9410(pphys, 0x70)))
                    fMoving = 1;
            }
            if (fMoving)
                break;
        }
        if (iso >= cso) {
            for (iso = 0; iso < cso; iso++)
                SleepSo(apso[iso]);
            RecalcSwXpPos(B_003DD490, cxp, axp);
            RecalcSwXpMovement(B_003DD490, cxp, axp);
        }
    } else {
        for (iso = 0; iso < cso; iso++) {
            SO *pso = apso[iso];
            pso->vt->slot[1].fn((char *)pso + pso->vt->slot[1].delta);
        }
    }
    CStackFrame_Destructor(l.frame, 2);
}
