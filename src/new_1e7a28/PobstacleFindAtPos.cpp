#include "sly2.h"
extern "C" void *PpathzoneFindPos(QW, int);
extern "C" int CobstacleFindPathzoneBox(void *, int, QW, QW, int, void **);
extern "C" int FObstacleContainsPos(void *, QW);
extern "C" void *PobstacleFindAtPos(QW pos)
{
    void *apobstacle[0x40];
    void *zone = PpathzoneFindPos(pos, 0);
    if (zone == 0) return 0;
    int count = CobstacleFindPathzoneBox(zone, 0, pos, pos, 0x40, apobstacle);
    for (int index = 0; index < count; index++) {
        void *obstacle = apobstacle[index];
        if (FObstacleContainsPos(obstacle, pos)) return obstacle;
    }
    return 0;
}
