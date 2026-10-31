#include "sly2.h"
extern float g_2c0ac4;
extern char B_003DD020[];
extern "C" {
float SWrapCrv(void *, float);
void GetPathPosFromS(void *, float, QW *, void *);
void *PobstacleFindEdgeBlocker(void *, void *, QW, QW);
void FindCrvClosestPointAll(void *, QW, void *, int, int, int, float *);
int func_001BD560(void *, void *, float, int, QW *, int);
int func_001BCCE0(void *, void *, float *, int, float);
}
struct Locals { QW posTarget; QW posExit; float sPos; float sFar; };

extern "C" int func_001BD718(float sNow, QW pos, void *ppathzone, void *pquery, void *pcrv, int fForward, void **ppobstacle, float *psExit)
{
    Locals l;
    float sWrapped;
    if (fForward != 0)
        sWrapped = SWrapCrv(pcrv, sNow + g_2c0ac4);
    else
        sWrapped = SWrapCrv(pcrv, sNow - g_2c0ac4);
    GetPathPosFromS(pcrv, sWrapped, &l.posTarget, 0);
    void *pobstacle = PobstacleFindEdgeBlocker(ppathzone, pquery, pos, l.posTarget);
    if (ppobstacle != 0)
        *ppobstacle = pobstacle;
    if (pobstacle == 0)
        return 0;
    int nWalk = func_001BD560(pobstacle, pcrv, sWrapped, fForward, &l.posExit, 0);
    if (nWalk != -1)
        return nWalk;
    FindCrvClosestPointAll(pobstacle, pos, B_003DD020, 0, 0, 0, &l.sPos);
    FindCrvClosestPointAll(pobstacle, l.posExit, B_003DD020, 0, 0, 0, &l.sFar);
    if (psExit != 0)
        *psExit = l.sFar;
    else
        psExit = &l.sFar;
    return func_001BCCE0(pobstacle, ppathzone, psExit, -1, l.sPos);
}
