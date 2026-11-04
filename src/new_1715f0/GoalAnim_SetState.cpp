#include "m2c_macros.h"
extern "C" {

s32 FIsGuardInSgs(s8 *, M2C_UNK);                 /* extern */
M2C_UNK StartAnimref(s8 *, s8 *, s32, f32);     /* extern */
M2C_UNK StopAnimref(s8 *);                        /* extern */
M2C_UNK func_001EF038(s8 *);                      /* extern */
M2C_UNK func_00209788(s8 *, s8 *);              /* extern */
M2C_UNK func_00209790(s8 *, s8 *);              /* extern */
extern f32 g_2dded0;

void GoalAnim_SetState(s8 *arg0, s32 arg1) {
    f32 var_f12;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s32 temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x30) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x30) = arg1;
        M2C_FIELD(arg0, f32 *, 0x34) = (f32) g_2dded0;
        switch (arg1) {                             /* irregular */
        case 0:
            func_00209788(M2C_FIELD(arg0, s8 **, 0x10) + 0xFD0, arg0);
            temp_v0 = M2C_FIELD(arg0, s8 **, 0x40);
            if (((temp_v1 = M2C_FIELD(temp_v0, s32 *, 0)) == 0) && (FIsGuardInSgs(M2C_FIELD(arg0, s8 **, 0x10), 9) != 0) && (temp_v1 = (s32) M2C_FIELD(arg0, s8 **, 0x10), (g_2dded0 == M2C_FIELD(temp_v1, f32 *, 0xFF4)))) {
                var_f12 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x40), s8 **, 4), f32 *, 0x74) * M2C_FIELD(temp_v1, f32 *, 0xFF0);
            } else {
                var_f12 = 0.0f;
            }
            StartAnimref(M2C_FIELD(arg0, s8 **, 0x40), M2C_FIELD(arg0, s8 **, 0x10), M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x40), s32 *, 0xC) | 1, var_f12);
            return;
        case 1:
            func_001EF038(arg0);
            temp_v0 = M2C_FIELD(arg0, s8 **, 0x40);
            if (temp_v0 != NULL) {
                if ((M2C_FIELD(temp_v0, s32 *, 0) == 0) && (FIsGuardInSgs(M2C_FIELD(arg0, s8 **, 0x10), 9) != 0)) {
                    temp_v0_2 = M2C_FIELD(arg0, s8 **, 0x40);
                    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), f32 *, 0xFF0) = (f32) (M2C_FIELD(M2C_FIELD(temp_v0_2, s8 **, 8), f32 *, 0x1C) / M2C_FIELD(M2C_FIELD(temp_v0_2, s8 **, 4), f32 *, 0x74));
                    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), f32 *, 0xFF4) = (f32) g_2dded0;
                }
                StopAnimref(M2C_FIELD(arg0, s8 **, 0x40));
                M2C_FIELD(arg0, s32 *, 0x40) = 0;
                func_00209790(M2C_FIELD(arg0, s8 **, 0x10) + 0xFD0, arg0);
            }
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0x1A4) = 0;
            break;
        }
    }
}
}
