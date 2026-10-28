#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct BSPN { BSPN *neg; BSPN *pos; int psurf; };
struct GEOM { int cbsp; int cbspFull; int pad; BSPN *absn; };
struct BSPC { int pad[3]; int *plane; };
void *PvAllocSwImpl(int);
extern "C" char D_002BBAF0[];
void CloneBspc(GEOM *src, BSPC *srcBspc, GEOM *dst, BSPC *dstBspc)
{
    ALLOCREQ req;
    dst->cbsp = src->cbsp;
    req.cbAlign = 0x10;
    dst->cbspFull = src->cbspFull;
    req.cb = src->cbsp * 12;
    dst->absn = (BSPN *)PvAllocSwImpl((int)&req);
    for (int i = 0; i < dst->cbsp; i++) {
        BSPN *s = (BSPN *)((char *)src->absn + i * 12);
        BSPN *d = (BSPN *)((char *)dst->absn + i * 12);
        if ((char *)s->psurf == D_002BBAF0)
            d->psurf = s->psurf;
        else
            d->psurf = (int)((char *)dstBspc->plane + ((char *)s->psurf - (char *)srcBspc->plane));
        d->neg = s->neg == 0 ? 0 : (BSPN *)((char *)dst->absn + ((char *)s->neg - (char *)src->absn));
        d->pos = s->pos == 0 ? 0 : (BSPN *)((char *)dst->absn + ((char *)s->pos - (char *)src->absn));
    }
}
