#include "m2c_macros.h"

M2C_UNK AppendDlEntry(s32, void *);                 /* extern */
s32 FFindDlEntry(M2C_UNK *, void *);                /* extern */
M2C_UNK Obstacle_RemoveFromPathzone(void *);        /* extern */
M2C_UNK RemoveDlEntry(M2C_UNK *, void *);           /* extern */
extern M2C_UNK B_003E1A4C;

void Obstacle_JoinGroup(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x1D8) = arg1;
    AppendDlEntry(arg1 + 0x1C4, arg0);
    Obstacle_RemoveFromPathzone(arg0);
    if (FFindDlEntry(&B_003E1A4C, arg0) != 0) {
        RemoveDlEntry(&B_003E1A4C, arg0);
    }
}
