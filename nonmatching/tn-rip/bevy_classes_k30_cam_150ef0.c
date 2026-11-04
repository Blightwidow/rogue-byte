#include "m2c_macros.h"

s128 bevy_classes_k30_cam_150780();                 /* extern */
s128 bevy_classes_k30_cam_1507f8(void *);           /* extern */

void bevy_classes_k30_cam_150ef0(void *arg0) {
    f32 temp_f1;

    M2C_FIELD(arg0, s128 *, 0x20) = bevy_classes_k30_cam_150780();
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x18);
    M2C_FIELD(arg0, s128 *, 0x30) = bevy_classes_k30_cam_1507f8(arg0);
    if (temp_f1 >= 0.0f) {
        M2C_FIELD(arg0, f32 *, 0xAC) = temp_f1;
    }
    M2C_FIELD(arg0, s128 *, 0x50) = (s128) M2C_FIELD(arg0, s128 *, 0x80);
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) M2C_FIELD(arg0, f32 *, 0xA0);
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_FIELD(arg0, s128 *, 0x90);
}
