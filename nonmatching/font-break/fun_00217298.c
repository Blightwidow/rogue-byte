#include "m2c_macros.h"

void *OnGameLoad__FP4GAME(s32, M2C_UNK *, M2C_UNK, s32); /* extern */
extern M2C_UNK g_2dea28;

void func_00217298(void *arg0, s32 arg1, s32 arg3, f32 fparg0) {
    s32 temp_a0_3;
    s32 var_a3;
    s32 var_v1;
    s64 *temp_a0;
    s64 *temp_a0_2;
    s64 *temp_s0;
    s64 *temp_v0;
    s64 *temp_v1;
    s64 *var_a0;
    s64 *var_a0_2;
    u32 var_v0;
    void *temp_v0_2;

    var_a3 = arg3;
    temp_s0 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    M2C_FIELD(temp_s0, s64 *, 0) = 0x10000000;
    temp_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (temp_a0 + 0x10);
    switch (arg1) {                                 /* switch 1; irregular */
    default:                                        /* switch 1 */
        var_a3 = 0x13000000;
        switch (arg1) {                             /* switch 2; irregular */
        case 3:                                     /* switch 2 */
            M2C_FIELD(temp_a0, s32 *, 0x10) = 0x13000000;
            var_v1 = (0x100U >> 3) | 0x14000000;
            var_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
            var_v0 = 0x60;
block_11:
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = var_a0;
            M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s32 *, 4) = var_v1;
            temp_a0_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (temp_a0_2 + 4);
            M2C_FIELD(temp_a0_2, s32 *, 4) = (s32) ((var_v0 >> 3) | 0x14000000);
            temp_v1 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (temp_v1 + 4);
            M2C_FIELD(temp_v1, s32 *, 4) = 0x13000000;
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4);
            break;
        case 4:                                     /* switch 2 */
            M2C_FIELD(temp_a0, s32 *, 0x10) = 0x13000000;
            var_v1 = (0x100U >> 3) | 0x14000000;
            var_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
            var_v0 = 0x90;
            goto block_11;
        }
        break;
    case 1:                                         /* switch 1 */
        var_a3 = 0x13000000;
        M2C_FIELD(temp_a0, s32 *, 0x10) = 0x13000000;
        var_v1 = (0U >> 3) | 0x14000000;
        var_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
        var_v0 = 0xC0;
        goto block_11;
    case 2:                                         /* switch 1 */
        var_a3 = 0x13000000;
        M2C_FIELD(temp_a0, s32 *, 0x10) = 0x13000000;
        var_v1 = (0x30U >> 3) | 0x14000000;
        var_a0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
        var_v0 = 0xC0;
        goto block_11;
    }
    var_a0_2 = M2C_FIELD(&g_2dea28, s64 **, 0xC);
    if ((s32) var_a0_2 & 0xF) {
        do {
            *var_a0_2 = 0;
            temp_v0 = M2C_FIELD(&g_2dea28, s64 **, 0xC) + 4;
            var_a0_2 = temp_v0;
            M2C_FIELD(&g_2dea28, s64 **, 0xC) = temp_v0;
        } while ((s32) var_a0_2 & 0xF);
    }
    temp_a0_3 = M2C_FIELD(temp_s0, s32 *, 0) | (((s32) (M2C_FIELD(&g_2dea28, s64 **, 0xC) - temp_s0) >> 4) - 1);
    M2C_FIELD(temp_s0, s32 *, 0) = temp_a0_3;
    M2C_FIELD(M2C_FIELD(&g_2dea28, s64 **, 0xC), s64 *, 0) = 0x60000000;
    M2C_FIELD(&g_2dea28, s64 **, 0xC) = (s64 *) (M2C_FIELD(&g_2dea28, s64 **, 0xC) + 0x10);
    temp_v0_2 = OnGameLoad__FP4GAME(temp_a0_3, &g_2dea28, 0x60000000, var_a3);
    M2C_FIELD(temp_v0_2, s32 *, 0) = 0x15;
    M2C_FIELD(temp_v0_2, s32 *, 8) = (s32) ((s32) temp_s0 & 0x0FFFFFFF);
    M2C_FIELD(temp_v0_2, s32 *, 0xC) = 0;
    M2C_FIELD(temp_v0_2, f32 *, 4) = (f32) (fparg0 + (f32) (M2C_FIELD(arg0, s32 *, 0xA4) << 0x12));
}
