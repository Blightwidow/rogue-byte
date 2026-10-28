#include "m2c_macros.h"

M2C_UNK Mount_SetState(void *, M2C_UNK);            /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
M2C_UNK func_0017F4C0(void *, void *);              /* extern */
M2C_UNK func_00181728();                            /* extern */
extern M2C_UNK B_002DEB30;
extern f32 g_2dded0;

void func_001815E8(void *arg0, s32 arg1) {
    s32 temp_v1;
    void *var_a1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x1C0);
    if (temp_v1 != arg1) {
        if ((temp_v1 == 1) && (M2C_FIELD(arg0, void **, 0x1C8) != NULL)) {
            func_00181728();
        }
        M2C_FIELD(arg0, s32 *, 0x1C0) = arg1;
        M2C_FIELD(arg0, f32 *, 0x1C4) = (f32) g_2dded0;
        switch (arg1) {                             /* irregular */
        case 1:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C8), s32 *, 0x294) = (s32) M2C_FIELD(arg0, s32 *, 0x1CC);
            Mount_SetState(M2C_FIELD(arg0, void **, 0x1C8), 3);
            break;
        case 2:
            bevy_camera_follow_activity(&B_002DEB30, 0x39, arg0);
            break;
        }
        if (arg1 != -1) {
            var_a1 = arg0 + ((arg1 * 0x10) + 0x1D0);
        } else {
            var_a1 = NULL;
        }
        func_0017F4C0(arg0, var_a1);
    }
}
