#include "sly2.h"
struct LO;
extern "C" void *PcgtPointInCgQuick(void *, QW);
extern "C" int CobstacleFindPathzoneBox(LO *, void *, QW, QW, int, LO **);
extern "C" int FObstacleContainsPos(LO *, QW);

int FPosFreeInPathzone(LO *zone, QW pos)
{
    LO *obstacles[128];
    if (!PcgtPointInCgQuick((char *)zone + 0xE0, pos))
        return 0;
    int count = CobstacleFindPathzoneBox(zone, 0, pos, pos, 0x80, obstacles);
    for (int index = 0; index < count; index++) {
        if (FObstacleContainsPos(obstacles[index], pos))
            return 0;
    }
    return 1;
}
