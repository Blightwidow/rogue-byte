#include "m2c_macros.h"

f32 GRandInRange(f32, f32);                         /* extern */
extern f32 g_2dded0;

void SetEyesEyess__FP4EYES5EYESS(void *arg0, s32 arg1) {
    f32 temp_f3;
    s32 temp_v0;
    s32 temp_v1;

    if (arg1 != M2C_FIELD(arg0, s32 *, 0x64)) {
        switch (arg1) {                             /* irregular */
        case 1:
            break;
        case 0:
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x1C);
            temp_f3 = M2C_FIELD(arg0, f32 *, 0x78);
            M2C_FIELD(arg0, f32 *, 0x74) = (f32) ((f32) (temp_v1 - 1) * temp_f3);
            M2C_FIELD(arg0, f32 *, 0x70) = (f32) (((f32) (temp_v1 * 2) * (1.0f - temp_f3)) / M2C_FIELD(arg0, f32 *, 0x50));
            if (!(GRandInRange(0.0f, 1.0f) < M2C_FIELD(arg0, f32 *, 0x5C))) {
                M2C_FIELD(arg0, f32 *, 0x6C) = GRandInRange(M2C_FIELD(arg0, f32 *, 0x54), M2C_FIELD(arg0, f32 *, 0x58));
            } else {
                M2C_FIELD(arg0, f32 *, 0x6C) = 0.0f;
            }
            break;
        case 2:
            temp_v0 = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
            if (M2C_ERROR(/* Read from unset register $f1 */) != temp_v0) {
                M2C_FIELD(arg0, f32 *, 0x74) = (f32) temp_v0;
            }
            break;
        }
        M2C_FIELD(arg0, s32 *, 0x64) = arg1;
        M2C_FIELD(arg0, f32 *, 0x68) = (f32) g_2dded0;
    }
}
