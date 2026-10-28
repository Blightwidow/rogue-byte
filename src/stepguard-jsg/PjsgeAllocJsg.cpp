#include "sly2.h"
struct JSGE { int jsgek; int fAsync; char pad[0x48]; };
struct JSG { char pad0[0x50]; int cjsge; JSGE *ajsge; int cjsgeMax; };
extern JSGE B_003DA740;
extern "C" JSGE *PjsgeAllocJsg(JSG *pjsg, int jsgek, int fAsync)
{
    int cjsge = pjsg->cjsge;
    int cjsgeMax = pjsg->cjsgeMax;
    if (cjsgeMax < 0)
        cjsgeMax = 0x200;
    if (cjsge >= cjsgeMax)
        return &B_003DA740;
    pjsg->cjsge = cjsge + 1;
    JSGE *pjsge = &pjsg->ajsge[cjsge];
    memset(pjsge, 0, 0x50);
    pjsge->jsgek = jsgek;
    pjsge->fAsync = fAsync;
    return pjsge;
}
