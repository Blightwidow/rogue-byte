#include "types.h"

struct XFVTBL {
    char pad[0x190];
    s16 delta;
    char pad2[2];
    s32 (*pfnSetXf)(char *, void *, char *);
};

struct XFOBJ {
    char pad[0xC];
    struct XFVTBL *pvtbl;
    char pad2[0x40];
    char xf[1];
};

s32 CLo_Clone();                                  /* extern */
s32 InvalidateXfmMatWorld(void *);              /* extern */

void CloneXfm(struct XFOBJ *pxfoNew, struct XFOBJ *pxfoSrc) {
    struct XFVTBL *pvtbl;
    struct XFVTBL *pvtblNew;

    CLo_Clone();
    pvtbl = pxfoSrc->pvtbl;
    pvtbl->pfnSetXf((char *)pxfoSrc + pvtbl->delta, pxfoSrc, pxfoSrc->xf);
    pvtblNew = pxfoNew->pvtbl;
    pvtblNew->pfnSetXf((char *)pxfoNew + pvtblNew->delta, pxfoSrc, pxfoNew->xf);
    InvalidateXfmMatWorld(pxfoNew);
}
