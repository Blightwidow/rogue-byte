#include "sly2.h"
struct PATH { int csym; short *asymid; };
extern "C" void *PvAllocStackImpl__Fi(void *);
extern "C" void CopyAb__FPvT0Ui(void *, void *, unsigned);
extern "C" PATH *PpathConcatStack(PATH *a, PATH *b)
{
    int req[2];
    req[0] = 8;
    req[1] = 0x10;
    PATH *result = (PATH *)PvAllocStackImpl__Fi(req);
    result->csym = a->csym + b->csym;
    req[0] = result->csym * 2;
    req[1] = 0x10;
    result->asymid = (short *)PvAllocStackImpl__Fi(req);
    CopyAb__FPvT0Ui(result->asymid, a->asymid, a->csym * 2);
    CopyAb__FPvT0Ui((char *)result->asymid + a->csym * 2, b->asymid, b->csym * 2);
    return result;
}
