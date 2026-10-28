#include "m2c_macros.h"

M2C_UNK SetHubState(s32, M2C_UNK);                  /* extern */
M2C_UNK SetPoPlayable();                            /* extern */

void SetHubPlayable(s32 arg0, s32 arg1) {
    SetPoPlayable();
    switch (arg1) {                                 /* irregular */
    case 0:
        SetHubState(arg0, 0);
        return;
    case 1:
        SetHubState(arg0, 1);
        break;
    }
}
