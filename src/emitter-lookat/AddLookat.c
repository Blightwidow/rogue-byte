#include "m2c_macros.h"

s32 FLookatInList();                                /* extern */
M2C_UNK InsertXfAct(s32, s32, void *);              /* extern */

void AddLookat(void *arg0) {
    if (FLookatInList() == 0) {
        InsertXfAct(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8), arg0);
    }
}
