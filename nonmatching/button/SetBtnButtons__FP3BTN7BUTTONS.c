#include "m2c_macros.h"

M2C_UNK TriggerBtn(void *);                         /* extern */
M2C_UNK UntriggerBtn(void *);                       /* extern */
extern f32 g_2dded0;

void SetBtnButtons__FP3BTN7BUTTONS(void *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_a0;
    s32 var_s1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x90);
    if (temp_v1 != arg1) {
        var_a0 = 0;
        if (temp_v1 == 0) {
            var_a0 = arg1 == 1;
        }
        var_s1 = 0;
        if (temp_v1 != -1) {
            var_s1 = arg1 == 0;
        }
        M2C_FIELD(arg0, s32 *, 0x90) = arg1;
        M2C_FIELD(arg0, f32 *, 0x94) = (f32) g_2dded0;
        if (var_a0 != 0) {
            TriggerBtn(arg0);
        }
        if (var_s1 != 0) {
            UntriggerBtn(arg0);
        }
    }
}
