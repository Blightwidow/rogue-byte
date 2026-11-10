#include "types.h"
extern "C" {
struct OBSTACLE {
    char pad0[0x1D8];
    s32 field_0x1D8;
};

void AppendDlEntry(s32, OBSTACLE *);
s32 FFindDlEntry(s32 *, OBSTACLE *);
void Obstacle_RemoveFromPathzone(OBSTACLE *);
void RemoveDlEntry(s32 *, OBSTACLE *);
extern s32 B_003E1A4C;

void Obstacle_JoinGroup(OBSTACLE *obstacle, s32 group) {
    obstacle->field_0x1D8 = group;
    AppendDlEntry(group + 0x1C4, obstacle);
    Obstacle_RemoveFromPathzone(obstacle);
    if (FFindDlEntry(&B_003E1A4C, obstacle) != 0) {
        RemoveDlEntry(&B_003E1A4C, obstacle);
    }
}

}
