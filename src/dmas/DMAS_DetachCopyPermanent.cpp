#include "sly2.h"
struct DMAS;
extern char g_2dd590[];
extern "C" void DMAS_DetachCopy(DMAS *, char *, int *, int *, unsigned *);
extern "C" void DMAS_DetachCopyPermanent(DMAS *dmas, int *count, int *start, unsigned *copy)
{
    DMAS_DetachCopy(dmas, g_2dd590, count, start, copy);
}
