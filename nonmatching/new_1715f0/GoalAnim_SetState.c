#include "m2c_macros.h"

s32 FIsGuardInSgs(void *, M2C_UNK);                 /* extern */
M2C_UNK StartAnimref(void *, void *, s32, f32);     /* extern */
M2C_UNK StopAnimref(void *);                        /* extern */
M2C_UNK func_001EF038(void *);                      /* extern */
M2C_UNK func_00209788(void *, void *);              /* extern */
M2C_UNK func_00209790(void *, void *);              /* extern */
extern f32 g_2dded0;

void GoalAnim_SetState(void *arg0, s32 arg1) {
    f32 var_f12;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x30) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x30) = arg1;
        M2C_FIELD(arg0, f32 *, 0x34) = (f32) g_2dded0;
        switch (arg1) {                             /* irregular */
        case 0:
            func_00209788(M2C_FIELD(arg0, void **, 0x10) + 0xFD0, arg0);
            if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s32 *, 0) == 0) && (FIsGuardInSgs(M2C_FIELD(arg0, void **, 0x10), 9) != 0) && (temp_v1 = M2C_FIELD(arg0, void **, 0x10), (g_2dded0 == M2C_FIELD(temp_v1, f32 *, 0xFF4)))) {
                var_f12 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 4), f32 *, 0x74) * M2C_FIELD(temp_v1, f32 *, 0xFF0);
            } else {
                var_f12 = 0.0f;
            }
            StartAnimref(M2C_FIELD(arg0, void **, 0x40), M2C_FIELD(arg0, void **, 0x10), M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s32 *, 0xC) | 1, var_f12);
            return;
        case 1:
            func_001EF038(arg0);
            temp_v0 = M2C_FIELD(arg0, void **, 0x40);
            if (temp_v0 != NULL) {
                if ((M2C_FIELD(temp_v0, s32 *, 0) == 0) && (FIsGuardInSgs(M2C_FIELD(arg0, void **, 0x10), 9) != 0)) {
                    temp_v0_2 = M2C_FIELD(arg0, void **, 0x40);
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), f32 *, 0xFF0) = (f32) (M2C_FIELD(M2C_FIELD(temp_v0_2, void **, 8), f32 *, 0x1C) / M2C_FIELD(M2C_FIELD(temp_v0_2, void **, 4), f32 *, 0x74));
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), f32 *, 0xFF4) = (f32) g_2dded0;
                }
                StopAnimref(M2C_FIELD(arg0, void **, 0x40));
                M2C_FIELD(arg0, void **, 0x40) = NULL;
                func_00209790(M2C_FIELD(arg0, void **, 0x10) + 0xFD0, arg0);
            }
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x1A4) = 0;
            break;
        }
    }
}
