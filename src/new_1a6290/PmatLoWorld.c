#include "types.h"

struct LOVTBL {
    char pad[0xF8];
    s16 deltaMat;
    char pad2[2];
    s32 (*pfnMat)(char *, s16);
};

struct LOOBJ {
    char pad[0xC];
    struct LOVTBL *pvtbl;
};

void PmatLoWorld(struct LOOBJ *plo) {
    s16 delta;
    struct LOVTBL *pvtbl;

    pvtbl = plo->pvtbl;
    delta = pvtbl->deltaMat;
    pvtbl->pfnMat((char *)plo + delta, delta);
}
