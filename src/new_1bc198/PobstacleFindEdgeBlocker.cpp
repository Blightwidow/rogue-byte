#include "sly2.h"
struct OBS;
struct LO;
struct SAPQUERY;
struct LSG { char pad[0x40]; float u1; float u2; char pad2[0x18]; };
extern "C" int CobstacleFindPathzoneBox(LO *, SAPQUERY *, QW, QW, int, OBS **);
extern "C" int ClsgClipEdgeToObstacle(OBS *, QW, QW, int, LSG *);
OBS *PobstacleFindEdgeBlocker(LO *pathzone, SAPQUERY *query, QW posA, QW posB)
{
    OBS *apobstacle[0x80];
    LSG alsg[2];
    int count = CobstacleFindPathzoneBox(pathzone, query, posA, posB, 0x80, apobstacle);
    float uBest = 1.0f;
    OBS *best = 0;
    for (int index = 0; index < count; index++) {
        OBS *obstacle = apobstacle[index];
        if (!ClsgClipEdgeToObstacle(obstacle, posA, posB, 2, alsg) || alsg[0].u1 != 0.0f) {
            best = obstacle;
            break;
        }
        float uEnter = alsg[0].u2;
        if (uBest <= uEnter)
            continue;
        uBest = uEnter;
        best = obstacle;
    }
    return best;
}
