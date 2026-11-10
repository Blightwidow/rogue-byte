#include "types.h"

typedef struct OBSTACLE {
    char pad0[0x1DC];
    s32 field_0x1DC;
} OBSTACLE;

void RemovePathzoneObstacle(s32, OBSTACLE *);

void Obstacle_RemoveFromPathzone(OBSTACLE *obstacle) {
    s32 pathzone;

    pathzone = obstacle->field_0x1DC;
    if (pathzone != 0) {
        RemovePathzoneObstacle(pathzone, obstacle);
        obstacle->field_0x1DC = 0;
    }
}
