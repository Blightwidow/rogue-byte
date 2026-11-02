#include "sly2.h"
struct EDGE { unsigned short ipos0; unsigned short ipos1; EDGE *pedgeNext0; EDGE *pedgeNext1; };
struct VTX { char pad[8]; float gCos; char pad2[4]; EDGE *pedgeFirst0; EDGE *pedgeFirst1; };
struct BSP;
struct WORLD { char pad[0x74]; BSP *pbsp; };
struct LOJ { char pad[0x258]; WORLD *pworld; };
struct JT { LOJ *plo; };
struct SOGEOM { int unk90; QW *apos; };
struct SO { char pad[0x68]; int geomCam; char pad2[0x90 - 0x6C]; SOGEOM geom; };
struct LSG { char pad[0x60]; };
extern VECTOR g_2a2dd0;
extern VECTOR g_2a2da0;
extern "C" int CedgeFindAtPos(SOGEOM *, void *, int, int, EDGE **);
int FCheckJtSingleEdge(JT *, SO *, EDGE *, VECTOR *);
int FCheckJtEdgeNormal(JT *, QW, QW);
extern "C" int ClsgClipEdgeToBsp(BSP *, int, QW, QW, int, LSG *);

static inline void AddVector(VECTOR *psum, VECTOR *pv)
{
    asm("lqc2 vf3, %0\n\tlqc2 vf1, %1\n\tvadd.xyzw vf3, vf3, vf1\n\tsqc2 vf3, %0" : "+m" (*psum) : "m" (*pv));
}

/* *pnormal = sum normalized, or the default axis when sum is about zero. */
static inline void NormalizeSum(VECTOR *psum, VECTOR *pnormal)
{
    float g;
    asm("lqc2 vf4, %1\n\tvmul.xyz vf1, vf4, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\t"
        "vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (g) : "m" (*psum));
    if (g < 0.0001f) {
        *pnormal = g_2a2da0;
    } else {
        asm("lqc2 vf2, %1\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf2, Q\n\tsqc2 vf1, %0" : "=m" (*pnormal) : "m" (*psum));
    }
}

int FCheckJtEdgeGrab(JT *pjt, SO *pso, QW pos, int kind, void *pv, VECTOR *pnormal)
{
    /* retail's frame shares the edge list (kind 1) with the clip buffers (kind 2) */
    union {
        EDGE *apedge[0x40];
        struct {
            VECTOR normalEdge;
            LSG alsg[2];
        } clip;
    } u;
    VECTOR normalEdge;
    VECTOR sum;
    int fFound;
    switch (kind) {
    case 1: {
        sum = g_2a2dd0;
        fFound = 0;
        int cedge = CedgeFindAtPos(&pso->geom, &pso->geomCam, ((QW *)pv - pso->geom.apos), 0x40, u.apedge);
        for (int iedge = 0; iedge < cedge; iedge++) {
            if (FCheckJtSingleEdge(pjt, pso, u.apedge[iedge], &normalEdge)) {
                fFound = 1;
                AddVector(&sum, &normalEdge);
            }
        }
        if (!fFound)
            return 0;
        NormalizeSum(&sum, pnormal);
        break;
    }
    case 2: {
        VTX *pvtx = (VTX *)pv;
        if (pvtx->gCos < 0.7f)
            return 0;
        sum = g_2a2dd0;
        fFound = 0;
        EDGE *pedge;
        for (pedge = pvtx->pedgeFirst0; pedge; pedge = pedge->pedgeNext0) {
            if (FCheckJtSingleEdge(pjt, pso, pedge, &u.clip.normalEdge)) {
                QW *apos = pso->geom.apos;
                if (ClsgClipEdgeToBsp(pjt->plo->pworld->pbsp, 0x7FFFFFFF, apos[pedge->ipos0], apos[pedge->ipos1], 2, u.clip.alsg) > 0) {
                    fFound = 1;
                    AddVector(&sum, &u.clip.normalEdge);
                }
            }
        }
        for (pedge = pvtx->pedgeFirst1; pedge; pedge = pedge->pedgeNext1) {
            if (FCheckJtSingleEdge(pjt, pso, pedge, &u.clip.normalEdge)) {
                QW *apos = pso->geom.apos;
                if (ClsgClipEdgeToBsp(pjt->plo->pworld->pbsp, 0x7FFFFFFF, apos[pedge->ipos0], apos[pedge->ipos1], 2, u.clip.alsg) > 0) {
                    fFound = 1;
                    AddVector(&sum, &u.clip.normalEdge);
                }
            }
        }
        if (!fFound)
            return 0;
        NormalizeSum(&sum, pnormal);
        break;
    }
    case 3:
        if (!FCheckJtSingleEdge(pjt, pso, (EDGE *)pv, pnormal))
            return 0;
        break;
    }
    return FCheckJtEdgeNormal(pjt, pos, *(QW *)pnormal);
}
