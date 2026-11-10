#include "types.h"

struct LOVTBL {
    char pad[0xF8];
    s16 deltaMat;
    char pad2[2];
    s32 (*pfnMat)(char *);
};

struct LOOBJ {
    char pad[0xC];
    struct LOVTBL *pvtbl;
};

s32 SetLoPosMat(s32, s32);                      /* extern */

void SetLoPosMatFromLo(s32 arg0, struct LOOBJ *plo) {
    struct LOVTBL *pvtbl;

    pvtbl = plo->pvtbl;
    SetLoPosMat(arg0, pvtbl->pfnMat((char *)plo + pvtbl->deltaMat));
}
