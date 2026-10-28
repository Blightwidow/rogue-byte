#include "m2c_macros.h"

M2C_UNK RemovePathzoneObstacle(s32, void *);        /* extern */

void Obstacle_RemoveFromPathzone(void *arg0) {
    s32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x1DC);
    if (temp_a0 != 0) {
        RemovePathzoneObstacle(temp_a0, arg0);
        M2C_FIELD(arg0, s32 *, 0x1DC) = 0;
    }
}
