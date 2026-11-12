// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
struct LO;
struct LSG { QW pos1; QW pos2; char pad[0x40]; };
struct OBSTACLE { char pad0[0xE8]; int cpos; char padEC[8]; QW *apos; };
extern "C" {
void *PcgtPointInCgQuick(void *, QW, int);
QW PosClosestOnCgt(void *, QW);
int CobstacleFindPathzoneBox(LO *, void *, QW, QW, int, OBSTACLE **);
int FObstacleContainsPos(OBSTACLE *, QW);
QW ConvertAloPos(OBSTACLE *, int, QW);
int ClsgClipEdgeToPathzone(LO *, QW, QW, int, LSG *, int);
void ClosestPointOnSegment(QW, QW, QW, QW *, int, float *);
int FFindPathzoneClosestPoint(LO *, QW, QW *, int);
}
extern "C" float D_002A76DC;
int func_001C0B50(LO *ppathzone, QW pos, QW *pposOut)
{
    OBSTACLE *apobstacle[128];
    VECTOR posPrev;
    VECTOR posNext;
    VECTOR posBest;
    LSG alsg[1];
    VECTOR posSeg;
    float d;
    void *pcgt = PcgtPointInCgQuick((char *)ppathzone + 0xE0, pos, 1);
    if (pcgt == 0)
        return 0;
    QW posClosest = PosClosestOnCgt(pcgt, pos);
    int cobstacle = CobstacleFindPathzoneBox(ppathzone, 0, posClosest, posClosest, 0x80, apobstacle);
    OBSTACLE *pobstacle = 0;
    for (int iobstacle = 0; iobstacle < cobstacle; iobstacle++) {
        if (FObstacleContainsPos(apobstacle[iobstacle], pos)) {
            pobstacle = apobstacle[iobstacle];
            break;
        }
    }
    if (pobstacle == 0) {
        *pposOut = posClosest;
        return 1;
    }
    posBest.z = 0.0f;
    posBest.y = 0.0f;
    posBest.x = 0.0f;
    float dBest = D_002A76DC;
    *(QW *)&posPrev = ConvertAloPos(pobstacle, 0, pobstacle->apos[0]);
    posPrev.z = FloatFromWord(LaneWordZ(posClosest));
    float zClosest = posPrev.z;
    int ipos = 1;
    while (ipos < pobstacle->cpos) {
        *(QW *)&posNext = ConvertAloPos(pobstacle, 0, pobstacle->apos[ipos]);
        posNext.z = zClosest;
        int clsg = ClsgClipEdgeToPathzone(ppathzone, *(QW *)&posPrev, *(QW *)&posNext, 1, alsg, 2);
        for (int ilsg = 0; ilsg < clsg; ilsg++) { LSG *plsg = &alsg[ilsg];
            ClosestPointOnSegment(posClosest, plsg->pos1, plsg->pos2, (QW *)&posSeg, 0, &d);
            if (d < dBest) {
                dBest = d;
                posBest = posSeg;
            }
        }
        posPrev = posNext;
        ipos++;
    }
    FFindPathzoneClosestPoint(ppathzone, *(QW *)&posBest, pposOut, 0);
    return 1;
}
