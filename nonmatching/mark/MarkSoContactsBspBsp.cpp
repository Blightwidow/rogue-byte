#include "sly2.h"
struct LSG {
    QW pos0;
    QW pos1;
    QW normal0;
    QW normal1;
    float u0;
    float u1;
    int unk48;
    void *pv0;
    void *pv1;
    unsigned short *aipos;
    int iipos;
    LSG *plsgNext;
};
struct SOX { char pad[0x70]; QW posPlane; };
struct SOGEOM { SOX *pso; char pad[0x94 - 4]; QW *apos; char pad2[4]; char *asurf; };
struct XP { char pad[0x9C]; int kind; void *pv0; void *pv1; char pad2[4]; XP *pxpNext; };
struct SW;
struct BSP;
extern VECTOR g_2a2dc0;
extern "C" int ClsgClipSoAllEdges(SW *, SOGEOM *, SOGEOM *, BSP *, int, LSG *);
extern "C" int ClsgClipSoBspEdges(SW *, SOGEOM *, SOGEOM *, BSP *, BSP *, int, LSG *);
void CategorizeAlsg(int, LSG *, int *, int *, LSG **, LSG **);
extern "C" void MarkSoEmbeddedContacts(SW *, SOGEOM *, SOGEOM *, int, int *, LSG **, XP **);
int CplsgFindEdgePath(SOGEOM *, int, int, LSG *, LSG **);
extern "C" void func_0011EA60(QW, QW, QW, QW, float *, QW *);
extern "C" void func_002564B8(QW *);
extern "C" XP *PxpAdd(SW *, SOGEOM *, SOGEOM *, QW, QW, int, void *, void *, float, XP **);

/* Closest points pos0 + (pos1 - pos0) * u on both segments and their distance, VU0. */
static inline float GDistLerp(QW *pa0, QW *pa1, QW *pb0, QW *pb1, float u, float v, QW *ppa)
{
    float g;
    float uInv = 1.0f - u;
    float vInv = 1.0f - v;
    asm("qmtc2.ni %2, vf5\n\tqmtc2.ni %3, vf8\n\tlqc2 vf1, %7\n\tlqc2 vf4, %5\n\tqmtc2.ni %8, vf2\n\tqmtc2.ni %9, vf6\n\t"
        "lqc2 vf7, %6\n\tlqc2 vf3, %4\n\tvmulax.xyzw ACC, vf4, vf2x\n\tvmaddx.xyzw vf4, vf7, vf5x\n\t"
        "vmulax.xyzw ACC, vf3, vf6x\n\tvmaddx.xyzw vf3, vf1, vf8x\n\tvsub.xyzw vf1, vf4, vf3\n\t"
        "vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tsqc2 vf4, %1\n\t"
        "vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1"
        : "=r" (g), "=m" (*ppa)
        : "r" (u), "r" (v), "m" (*pb0), "m" (*pa0), "m" (*pa1), "m" (*pb1), "r" (uInv), "r" (vInv));
    return g;
}

/* Signed distance of pos from plane (xyz normal, w offset), VU0. */
static inline float GPlaneDist(QW *ppos, QW *pplane, QW *ptmp, QW *ptmpOne)
{
    float g;
    asm("lqc2 vf1, %3\n\tlqc2 vf3, %4\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\t"
        "vmaddaz.x ACC, vf2, vf1z\n\tvmsubw.x vf1, vf2, vf1w\n\tsqc2 vf2, %2\n\tsqc2 vf1, %1\n\tqmfc2.ni %0, vf1"
        : "=r" (g), "=m" (*ptmp), "=m" (*ptmpOne) : "m" (*ppos), "m" (*pplane));
    return g;
}

void MarkSoContactsBspBsp(SW *psw, SOGEOM *pgeomA, SOGEOM *pgeomB, BSP *pbspA, BSP *pbspB, BSP *pbsp, XP **ppxp)
{
    int aclsg[2];
    LSG aalsg[2][0x80];
    int acpos[2];
    int aapos[2][0x80];
    LSG *aaplsg[2][0x80];
    LSG *aplsgFree[2];
    LSG *aplsgPath[0x20];
    float au[4];
    QW normal;
    QW posA;
    QW tmpA, tmpB, tmpC, tmpD;
    QW posPlaneA, posPlaneB;
    QW posEdge, posPlane;
    XP *pxpFirst = *ppxp;
    aclsg[0] = ClsgClipSoAllEdges(psw, pgeomB, pgeomA, pbsp, 0x80, aalsg[0]);
    aclsg[1] = ClsgClipSoBspEdges(psw, pgeomA, pgeomB, pbspA, pbspB, 0x80, aalsg[1]);
    if (aclsg[0] == 0 && aclsg[1] == 0)
        return;
    int i;
    for (i = 0; i < 2; i++)
        CategorizeAlsg(aclsg[i], aalsg[i], &acpos[i], aapos[i], aaplsg[i], &aplsgFree[i]);
    MarkSoEmbeddedContacts(psw, pgeomA, pgeomB, acpos[0], aapos[0], aaplsg[0], ppxp);
    MarkSoEmbeddedContacts(psw, pgeomB, pgeomA, acpos[1], aapos[1], aaplsg[1], ppxp);
    for (LSG *plsg = aplsgFree[0]; plsg; plsg = plsg->plsgNext) {
        if (!plsg->pv0 || !plsg->pv1)
            continue;
        int cplsg = CplsgFindEdgePath(pgeomB, ((char *)plsg->pv0 - pgeomB->asurf) >> 5, ((char *)plsg->pv1 - pgeomB->asurf) >> 5,
                                      aplsgFree[1], aplsgPath);
        if (cplsg > 0) {
            for (int iplsg = 0; iplsg < cplsg; iplsg++) {
                LSG *plsgOther = aplsgPath[iplsg];
                QW posA0 = pgeomA->apos[plsg->aipos[0]];
                QW posA1 = pgeomA->apos[plsg->aipos[1]];
                QW posB0 = pgeomB->apos[plsgOther->aipos[0]];
                QW posB1 = pgeomB->apos[plsgOther->aipos[1]];
                func_0011EA60(posA0, posA1, posB0, posB1, au, &normal);
                float g = GDistLerp(&posA0, &posA1, &posB0, &posB1, au[0], au[1], &posA);
                PxpAdd(psw, pgeomA, pgeomB, posA, normal, 3, plsg->aipos, plsgOther->aipos, -g, ppxp);
            }
            continue;
        }
        {
            int ilsg;
            char *pvA = pgeomA->asurf + plsg->aipos[2] * 0x20;
            char *pvB = pgeomA->asurf + plsg->aipos[3] * 0x20;
            for (ilsg = 0; ilsg < aclsg[1]; ilsg++) {
                LSG *plsgT = &aalsg[1][ilsg];
                if (plsgT->pv0 == pvA || plsgT->pv0 == pvB || plsgT->pv1 == pvA || plsgT->pv1 == pvB)
                    break;
            }
            if (ilsg < aclsg[1])
                continue;
        }
        posPlaneA = pgeomA->pso->posPlane;
        func_002564B8(&tmpA);
        func_002564B8(&tmpB);
        float g0 = GPlaneDist(&plsg->normal0, &posPlaneA, &tmpB, &tmpA);
        posPlaneB = pgeomA->pso->posPlane;
        func_002564B8(&tmpC);
        func_002564B8(&tmpD);
        float g1 = GPlaneDist(&plsg->normal1, &posPlaneB, &tmpD, &tmpC);
        QW *pplane;
        int iipos;
        if (g1 < g0) {
            iipos = 1 - plsg->iipos;
            pplane = (QW *)plsg->pv0;
        } else {
            iipos = plsg->iipos;
            pplane = (QW *)plsg->pv1;
        }
        QW *ppos = &pgeomA->apos[plsg->aipos[iipos]];
        XP *pxp;
        for (pxp = *ppxp; pxp; pxp = pxp->pxpNext) {
            if (pxp->kind == 1 && pxp->pv0 == ppos && pxp->pv1 == pplane)
                break;
        }
        if (pxp)
            continue;
        posEdge = *ppos;
        posPlane = *pplane;
        func_002564B8(&tmpA);
        func_002564B8(&tmpB);
        float g = GPlaneDist(&posEdge, &posPlane, &tmpA, &tmpB);
        PxpAdd(psw, pgeomA, pgeomB, posEdge, posPlane, 1, ppos, pplane, g, ppxp);
    }
    if (*ppxp != pxpFirst)
        return;
    if (aclsg[0] != 0 && aclsg[1] != 0)
        return;
    PxpAdd(psw, pgeomA, pgeomB, pgeomA->pso->posPlane, *(QW *)&g_2a2dc0, 0xD, 0, 0, 0.0f, ppxp);
}
