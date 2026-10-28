#include "m2c_macros.h"

s32 FLookatInList();                                /* extern */
M2C_UNK RemoveXfAct(s32, s32, void *);              /* extern */

void RemoveLookat(void *arg0) {
    if (FLookatInList() != 0) {
        RemoveXfAct(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8), arg0);
    }
}
