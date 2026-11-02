#include "sly2.h"
struct OBS { char pad[0xE8]; int cplane; char pad2[0x1EC - 0xEC]; QW *aplane; };
struct LSG { QW pos0; QW pos1; QW normal0; QW normal1; float u0; float u1; int unk48; OBS *pobs1; OBS *pobs0; char pad[0xC]; };
extern float D_002C0AB4;
extern "C" void Obstacle_UpdatePlanes(OBS *);
extern "C" void func_002564B8(QW *);

/* Signed distance of pos from plane (xyz normal, w offset), VU0; the dot product also lands in *ptmp, vf1 (x = 1) in *ptmpOne. */
static inline float GPlaneDist(QW *pplane, QW *ppos, QW *ptmp, QW *ptmpOne)
{
    float g;
    asm("lqc2 vf3, %3\n\tlqc2 vf4, %4\n\tvmul.xyz vf2, vf3, vf4\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\t"
        "vmaddaz.x ACC, vf1, vf2z\n\tvmsubw.x vf2, vf1, vf3w\n\tqmfc2.ni %0, vf2\n\tsqc2 vf1, %2\n\tsqc2 vf2, %1"
        : "=r" (g), "=m" (*ptmp), "=m" (*ptmpOne) : "m" (*pplane), "m" (*ppos));
    return g;
}

/* pos0 * (1 - u) + pos1 * u, VU0. */
static inline QW PosLerp(QW *ppos0, QW *ppos1, float u, QW *ptmp)
{
    QW pos;
    float uInv = 1.0f - u;
    asm("qmtc2.ni %3, vf2\n\tqmtc2.ni %4, vf1\n\tlqc2 vf4, %5\n\tlqc2 vf5, %6\n\tsqc2 vf1, %1\n\tsqc2 vf2, %1\n\t"
        "vmulax.xyzw ACC, vf4, vf1x\n\tvmaddx.xyzw vf1, vf5, vf2x\n\tqmfc2.ni %0, vf1"
        : "=r" (pos), "=m" (*ptmp) : "r" (u), "r" (u), "r" (uInv), "m" (*ppos0), "m" (*ppos1));
    return pos;
}

static inline QW NegateQw(QW *pv)
{
    QW v;
    asm("lqc2 vf1, %1\n\tvsub.xyzw vf3, vf0, vf0\n\tvsub.xyzw vf3, vf3, vf1\n\tqmfc2.ni %0, vf3" : "=r" (v) : "m" (*pv));
    return v;
}

static inline QW QwZero(void)
{
    QW v;
    asm("vsub.xyzw vf1, vf0, vf0\n\tqmfc2.ni %0, vf1" : "=r" (v));
    return v;
}

int ClsgClipEdgeToObstacle(OBS *pobs, QW pos0, QW pos1, int clsgMax, LSG *alsg)
{
    QW tmpScratch;
    QW tmp10, tmp20, tmp30, tmp40;
    QW planeEnter;
    QW planeExit;
    QW plane;
    QW posA = pos0;
    QW posB = pos1;
    int iplane = 0;
    int clsg;
    Obstacle_UpdatePlanes(pobs);
    float uEnter = 0.0f;
    float uExit = 1.0f;
    planeEnter = QwZero();
    planeExit = planeEnter;
    for (; iplane < pobs->cplane - 1; iplane++) {
        plane = pobs->aplane[iplane];
        func_002564B8(&tmp10);
        func_002564B8(&tmp20);
        float g0 = GPlaneDist(&plane, &posA, &tmp10, &tmp20);
        func_002564B8(&tmp30);
        func_002564B8(&tmp40);
        float eps = D_002C0AB4;
        g0 += eps;
        float g1 = GPlaneDist(&plane, &posB, &tmp30, &tmp40) + eps;
        if (g0 < 0.0f && g1 < 0.0f)
            continue;
        if (0.0f < g0 && 0.0f < g1) {
            uExit = 0.0f;
            uEnter = 0.0f;
            break;
        }
        float u = g0 / (g0 - g1);
        if (g0 < 0.0f) {
            uExit = u < uExit ? u : uExit;
            planeExit = plane;
        } else {
            planeEnter = plane;
            uEnter = u > uEnter ? u : uEnter;
        }
        if (uExit <= uEnter)
            break;
    }
    clsg = 0;
    if (uExit <= uEnter && clsgMax > 0) {
        LSG *plsg = alsg;
        memset(plsg, 0, sizeof(LSG));
        clsg = 1;
        plsg->pos0 = posA;
        plsg->u1 = 1.0f;
        plsg->u0 = 0.0f;
        plsg->pos1 = posB;
        return clsg;
    }
    if (0.0f < uEnter && clsgMax > 0) {
        LSG *plsg = &alsg[clsg];
        clsg = 1;
        memset(plsg, 0, sizeof(LSG));
        plsg->pos0 = posA;
        plsg->pos1 = PosLerp(&posA, &posB, uEnter, &tmpScratch);
        plsg->normal1 = NegateQw(&planeEnter);
        plsg->u0 = 0.0f;
        plsg->u1 = uEnter;
        plsg->pobs0 = pobs;
    }
    if (uExit < 1.0f && clsg < clsgMax) {
        LSG *plsg = &alsg[clsg++];
        memset(plsg, 0, sizeof(LSG));
        plsg->pobs1 = pobs;
        plsg->pos0 = PosLerp(&posA, &posB, uExit, &tmpScratch);
        plsg->normal0 = NegateQw(&planeExit);
        plsg->pos1 = posB;
        plsg->u0 = uExit;
        plsg->u1 = 1.0f;
    }
    return clsg;
}
