#include "m2c_macros.h"

M2C_UNK HandleLoMessage();                          /* extern */

void HandleDirAnimMessage(void *arg0, s32 arg1, void *arg2) {
    s32 temp_v1;

    if (arg1 == 9) {
        temp_v1 = M2C_FIELD(arg2, s32 *, 8);
        switch (temp_v1) {                          /* irregular */
        case 0x180:
            M2C_FIELD(arg0, s32 *, 0x38) = 0;
            break;
        case 0x17D:
            M2C_FIELD(arg0, s32 *, 0x34) = 1;
            break;
        case 0x17E:
            M2C_FIELD(arg0, s32 *, 0x34) = 0;
            break;
        case 0x17F:
            M2C_FIELD(arg0, s32 *, 0x38) = 1;
            break;
        }
    }
    HandleLoMessage();
}
