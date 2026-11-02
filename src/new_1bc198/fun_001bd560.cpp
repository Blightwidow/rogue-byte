#include "sly2.h"
struct OBS;
struct LSG { VECTOR pos; char pad[0x50]; };
struct CRV { char pad[0xE4]; int fClosed; };
extern float D_002C0AC0;
extern "C" void GetPathPosFromS(CRV *, float, VECTOR *, int);
extern "C" float SWrapCrv(CRV *, float);
extern "C" float SMinCrv(CRV *);
extern "C" float SMaxCrv(CRV *);
extern "C" int ClsgClipEdgeToObstacle(OBS *, QW, QW, int, LSG *);

int func_001BD560(OBS *pobs, CRV *pcrv, int fForward, VECTOR *pposHit, float *psHit, float s)
{
    VECTOR posPrev;
    VECTOR pos;
    LSG alsg[2];
    GetPathPosFromS(pcrv, s, &pos, 0);
    float ds = D_002C0AC0;
    if (!fForward)
        ds = -ds;
    int fWrapped = 0;
    for (;;) {
        posPrev = pos;
        s += ds;
        if (s <= SMinCrv(pcrv)) {
            if (fWrapped)
                break;
            fWrapped = 1;
            if (pcrv->fClosed)
                s = SWrapCrv(pcrv, s);
            else
                s = SMinCrv(pcrv);
        } else if (SMaxCrv(pcrv) <= s) {
            if (fWrapped)
                break;
            fWrapped = 1;
            if (pcrv->fClosed)
                s = SWrapCrv(pcrv, s);
            else
                s = SMaxCrv(pcrv);
        }
        GetPathPosFromS(pcrv, s, &pos, 0);
        int clsg = ClsgClipEdgeToObstacle(pobs, *(QW *)&posPrev, *(QW *)&pos, 2, alsg);
        if (clsg > 0) {
            if (psHit)
                *psHit = s;
            if (pposHit)
                *pposHit = alsg[clsg - 1].pos;
            return -1;
        }
    }
    return 3;
}
