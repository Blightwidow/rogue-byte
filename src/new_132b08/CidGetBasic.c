#include "types.h"

struct VTBLENTRY {
    char pad[0x30];
    s16 delta;
    char pad2[2];
    char *(*pfn)(char *, s16);
};

struct BASICOBJ {
    char pad[0xC];
    struct VTBLENTRY *pvtbl;
};

s32 CidGetBasic(struct BASICOBJ *pbasic) {
    struct VTBLENTRY *pvtbl;
    s16 delta;

    pvtbl = pbasic->pvtbl;
    delta = pvtbl->delta;
    return *(s32 *)(pvtbl->pfn((char *)pbasic + delta, delta) + 4);
}
