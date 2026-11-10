#include "types.h"
extern "C" {
struct OBSTACLE {
    char pad0[0x1D8];
    s32 field_0x1D8;
};

s32 FFindDlEntry(s32 *, OBSTACLE *);
void ObstacleGroup_Dissolve(s32);
void Obstacle_RemoveFromPathzone(OBSTACLE *);
void RemoveDlEntry(s32 *, OBSTACLE *);
void RemoveLoHierarchy();
extern s32 B_003E1A4C;

void Obstacle_RemoveLoHierarchy(OBSTACLE *obstacle) {
    s32 group;

    RemoveLoHierarchy();
    group = obstacle->field_0x1D8;
    if (group != 0) {
        ObstacleGroup_Dissolve(group);
    }
    Obstacle_RemoveFromPathzone(obstacle);
    if (FFindDlEntry(&B_003E1A4C, obstacle) != 0) {
        RemoveDlEntry(&B_003E1A4C, obstacle);
    }
}

}
