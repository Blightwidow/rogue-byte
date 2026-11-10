#include "types.h"

struct LOMATRIX {
    char pad[0x30];
    s128 pos;
};

struct LOVTBL {
    char pad[0xF8];
    s16 deltaMat;
    char pad2[2];
    struct LOMATRIX *(*pfnMat)(char *, s16);
};

struct LOOBJ {
    char pad[0xC];
    struct LOVTBL *pvtbl;
};

s128 PosLoWorld(struct LOOBJ *plo) {
    s16 delta;
    struct LOVTBL *pvtbl;

    pvtbl = plo->pvtbl;
    delta = pvtbl->deltaMat;
    return pvtbl->pfnMat((char *)plo + delta, delta)->pos;
}
