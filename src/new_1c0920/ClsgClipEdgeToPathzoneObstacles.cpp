/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct LO;
struct LSG { char pad[0x60]; };
extern "C" int ClsgClipEdgeToPathzone(LO *, QW, QW, int, LSG *, int);
extern "C" int CobstacleFindPathzoneBox(LO *, void *, QW, QW, int, LO **);
extern "C" int ClsgClipEdgeToObstacle(LO *, QW, QW, int, LSG *);
extern "C" int ClsgMergeAlsg(int, LSG *, int, LSG *, int, LSG *, int);
int ClsgClipEdgeToPathzoneObstacles(LO *ppathzone, QW pos1, QW pos2, int clsgMax, LSG *alsg)
{
    LO *apobstacle[128];
    LSG alsgObstacle[2];
    int clsg = ClsgClipEdgeToPathzone(ppathzone, pos1, pos2, clsgMax, alsg, 2);
    if (clsg == 0)
        return 0;
    int cobstacle = CobstacleFindPathzoneBox(ppathzone, 0, pos1, pos2, 0x80, apobstacle);
    for (int iobstacle = 0; iobstacle < cobstacle; iobstacle++) {
        int clsgBlocked = ClsgClipEdgeToObstacle(apobstacle[iobstacle], pos1, pos2, 2, alsgObstacle);
        clsg = ClsgMergeAlsg(clsg, alsg, clsgBlocked, alsgObstacle, clsgMax, alsg, 1);
        if (clsg == 0)
            goto done;
    }
done:
    return clsg;
}
