#include "m2c_macros.h"

M2C_UNK PhitfxSpawn_156548(s32, M2C_UNK, void *, M2C_UNK); /* extern */
M2C_UNK PosLoWorld(void *, M2C_UNK);                /* extern */
s32 func_001409E8();                                /* extern */
extern f32 D_FLT_002BCC74;
extern f32 D_FLT_002BCC78;
extern f32 g_2dded4;

void func_00140750(void *arg0) {
    f32 temp_f1;
    f32 var_f0;
    f32 var_f2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a0;
    void *temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x10C4) != 0) {
        temp_v0 = func_001409E8();
        switch (temp_v0) {                          /* switch 1; irregular */
        case 2:                                     /* switch 1 */
            M2C_FIELD(arg0, f32 *, 0x10CC) = 0.0f;
            break;
        case 1:                                     /* switch 1 */
            var_f0 = M2C_ERROR(/* unknown instruction: min.s $f0, $f0, $f2 */);
block_11:
            M2C_FIELD(arg0, f32 *, 0x10CC) = var_f0;
            break;
        case 0:                                     /* switch 1 */
            var_f0 = M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f2 */);
            goto block_11;
        }
        if (M2C_FIELD(arg0, s32 *, 0xDF4) != -1) {
            M2C_FIELD(arg0, s32 *, 0x10C8) = -1;
        } else {
            temp_f1 = M2C_FIELD(arg0, f32 *, 0x10CC);
            if (temp_f1 == 0.0f) {
                M2C_FIELD(arg0, s32 *, 0x10C8) = -1;
            } else if (temp_f1 != 1.0f) {
                if (M2C_FIELD(arg0, s32 *, 0x10C8) != 1) {
                    M2C_FIELD(arg0, s32 *, 0x10C8) = 0;
                } else if (!(temp_f1 > 0.0f)) {
                    M2C_FIELD(arg0, s32 *, 0x10C8) = 0;
                } else {
                    goto block_24;
                }
            } else {
block_24:
                M2C_FIELD(arg0, s32 *, 0x10C8) = 1;
            }
        }
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        temp_v0_2 = M2C_FIELD(temp_v1, s32 (**)(void *), 0x314)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x310));
        var_a0 = temp_v0_2;
        if (M2C_FIELD(arg0, s32 *, 0x10C8) != 1) {
            var_a0 = ((var_a0 ^ 1) != 0) ? temp_v0_2 : 2;
        }
        switch (var_a0) {                           /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            M2C_FIELD(arg0, f32 *, 0x10D0) = 0.0f;
            break;
        case 1:                                     /* switch 2 */
            var_f2 = M2C_FIELD(arg0, f32 *, 0x10D0) + (D_FLT_002BCC74 * g_2dded4);
            if (var_f2 < 0.0f) {
                var_f2 = 0.0f;
            } else {
block_42:
                if (var_f2 > 1.0f) {
                    var_f2 = 1.0f;
                }
            }
block_44:
            M2C_FIELD(arg0, f32 *, 0x10D0) = var_f2;
            break;
        case 2:                                     /* switch 2 */
        case -1:                                    /* switch 2 */
            var_f2 = M2C_FIELD(arg0, f32 *, 0x10D0) + (D_FLT_002BCC78 * g_2dded4);
            if (var_f2 < 0.0f) {
                var_f2 = 0.0f;
            } else {
                goto block_42;
            }
            goto block_44;
        }
        if (M2C_FIELD(arg0, f32 *, 0x10D0) == 1.0f) {
            PosLoWorld(arg0, 1);
            PhitfxSpawn_156548(M2C_FIELD(arg0, s32 *, 0x10C4), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), arg0, 0);
        }
    }
}
