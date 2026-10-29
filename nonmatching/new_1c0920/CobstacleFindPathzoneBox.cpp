#include "sly2.h"
struct SapQuery {
    unsigned agrfX[4];
    unsigned agrfY[4];
    int stamp;
    int iepMinX, iepMaxX, iepMinY, iepMaxY;
    char pad[0xC];
};
struct Pathzone {
    char pad0[0xFC];
    int cslot;
    int cep;
    void *aepX;
    void *aepY;
    void **aslot;
    char pad1[0x114 - 0x110];
    int stamp;
};
extern "C" {
void ResetPathzoneQuery(Pathzone *, SapQuery *);
void SweepPathzoneAxis(float, float, void *, int *, int *, unsigned *);
}
extern "C" int CobstacleFindPathzoneBox(Pathzone *pathzone, SapQuery *pquery, QW posA, QW posB, int cobstacleMax, void **apobstacle)
{
    struct { SapQuery queryLocal; unsigned agrfBoth[4]; QW junk; } l;
    if (pathzone->cep == 0)
        return 0;
    int stampQuery;
    if (pquery == 0) {
        l.queryLocal.stamp = -1;
        pquery = &l.queryLocal;
    }
    if (pquery->stamp != pathzone->stamp)
        ResetPathzoneQuery(pathzone, pquery);
    QW maxes, mins;
    int chain;
    asm("lqc2 vf1, %1" : "=r" (chain) : "m" (posA));
    asm("lqc2 vf2, %1" : "+r" (chain) : "m" (posB));
    asm("vmax.xyz vf1, vf1, vf2" : "+r" (chain));
    asm("qmfc2.ni %0, vf1" : "=r" (maxes) : "r" (chain));
    asm("lqc2 vf1, %1" : "+r" (chain) : "m" (posA));
    asm("vmini.xyz vf1, vf1, vf2" : "+r" (chain));
    asm("qmfc2.ni %0, vf1" : "=r" (mins) : "r" (chain));
    float minX, maxX, minY, maxY;
    QW tmp;
    asm("mtc1 %1, %0" : "=f" (maxX) : "r" (maxes));
    asm("mtc1 %1, %0" : "=f" (minX) : "r" (mins));
    SweepPathzoneAxis(minX, maxX, pathzone->aepX, &pquery->iepMinX, &pquery->iepMaxX, pquery->agrfX);
    asm("prot3w %0, %2\n\tmtc1 %0, %1" : "=r" (tmp), "=f" (minY) : "r" (mins));
    asm("prot3w %0, %2\n\tmtc1 %0, %1" : "=r" (tmp), "=f" (maxY) : "r" (maxes));
    SweepPathzoneAxis(minY, maxY, pathzone->aepY, &pquery->iepMinY, &pquery->iepMaxY, pquery->agrfY);
    QW anded;
    asm("pand %0, %1, %2" : "=r" (anded) : "r" (*(QW *)pquery->agrfX), "r" (*(QW *)pquery->agrfY));
    l.junk = anded;
    *(QW *)l.agrfBoth = anded;
    unsigned *agrfBoth = l.agrfBoth;
    int islot = 0;
    int cobstacle = 0;
    void **pout = apobstacle;
    for (; islot < pathzone->cslot; islot++) {
        if ((agrfBoth[islot / 32] & (1 << islot)) == 0)
            continue;
        if (cobstacleMax < cobstacle)
            break;
        *pout++ = pathzone->aslot[islot];
        cobstacle++;
    }
    pquery->stamp = pathzone->stamp;
    return cobstacle;
}
