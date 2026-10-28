#include "m2c_macros.h"

M2C_UNK VirtualRefPtr_Assign(s32, M2C_UNK);         /* extern */

void bevy_classes_k30_cam_reset(s32 arg0) {
    VirtualRefPtr_Assign(arg0 + 0xC4, 0);
    VirtualRefPtr_Assign(arg0 + 0xC0, 0);
}
