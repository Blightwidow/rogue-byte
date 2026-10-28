#include "m2c_macros.h"

s32 FFindDlEntry(M2C_UNK *, void *);                /* extern */
M2C_UNK ObstacleGroup_Dissolve(s32);                /* extern */
M2C_UNK Obstacle_RemoveFromPathzone(void *);        /* extern */
M2C_UNK RemoveDlEntry(M2C_UNK *, void *);           /* extern */
M2C_UNK RemoveLoHierarchy();                        /* extern */
extern M2C_UNK B_003E1A4C;

void Obstacle_RemoveLoHierarchy(void *arg0) {
    s32 temp_a0;

    RemoveLoHierarchy();
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x1D8);
    if (temp_a0 != 0) {
        ObstacleGroup_Dissolve(temp_a0);
    }
    Obstacle_RemoveFromPathzone(arg0);
    if (FFindDlEntry(&B_003E1A4C, arg0) != 0) {
        RemoveDlEntry(&B_003E1A4C, arg0);
    }
}
