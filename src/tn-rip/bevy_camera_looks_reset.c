#include "m2c_macros.h"

M2C_UNK VirtualRefPtr_Assign(s32, M2C_UNK);         /* extern */

void bevy_camera_looks_reset(s32 arg0) {
    VirtualRefPtr_Assign(arg0 + 0x38, 0);
    VirtualRefPtr_Assign(arg0 + 0x34, 0);
}
