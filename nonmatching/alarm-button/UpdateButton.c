#include "m2c_macros.h"

s32 FCheckButtonObject(void *, s32);                /* extern */
M2C_UNK QueueSwCallbackOnce(M2C_UNK *, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetButtonButtons(void *, u32);              /* extern */
M2C_UNK UpdateSo();                                 /* extern */
extern M2C_UNK B_003DD490;
extern f32 g_2dded0;
extern void *g_2e1e40;

void UpdateButton(void *arg0) {
    f32 temp_f2;
    s32 temp_a0;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 var_v0;
    u32 temp_v1;
    u32 var_a1;
    u32 var_s4;
    void *var_s0;
    void *var_s2;

    UpdateSo();
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x1E0);
    switch (temp_v1) {                              /* switch 1 */
    case 2:                                         /* switch 1 */
        if ((g_2e1e40 != NULL) && (M2C_FIELD(g_2e1e40, s32 *, 0x18C8) == 3) && (M2C_FIELD(g_2e1e40, s32 *, 0x18C4) == M2C_FIELD(arg0, s32 *, 0x2F4))) {
            M2C_FIELD(arg0, f32 *, 0x1E4) = (f32) g_2dded0;
        }
        temp_f2 = M2C_FIELD(arg0, f32 *, 0x1E8);
        if ((temp_f2 >= 0.0f) && (temp_f2 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x1E4)))) {
            SetButtonButtons(arg0, 4U);
        }
    default:                                        /* switch 1 */
        break;
    case 4:                                         /* switch 1 */
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x2A8);
        var_a1 = -1U;
        switch (temp_v1_2) {                        /* switch 2; irregular */
        default:                                    /* switch 2 */
        case 0:                                     /* switch 2 */
            var_a1 = 1;
            break;
        case 1:                                     /* switch 2 */
            var_a1 = 0;
            break;
        }
        if (var_a1 != -1U) {
            SetButtonButtons(arg0, var_a1);
        }
        break;
    case 0:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x2A8);
        var_s4 = M2C_FIELD(arg0, u32 *, 0x1E0);
        switch (temp_a0) {                          /* switch 3; irregular */
        case 3:                                     /* switch 3 */
            var_s4 = 0;
            if (g_2e1e40 != NULL) {
                if (M2C_FIELD(g_2e1e40, s32 *, 0x18C8) == temp_a0) {
                    var_s4 = M2C_FIELD(g_2e1e40, s32 *, 0x18C4) == M2C_FIELD(arg0, s32 *, 0x2F4);
                }
            }
            break;
        case 0:                                     /* switch 3 */
            var_s2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void **, 0x64);
            var_s4 = 0;
            if (var_s2 != NULL) {
loop_29:
                var_s0 = M2C_FIELD(var_s2, void **, 0);
                if (var_s0 != NULL) {
                    var_v0 = M2C_FIELD(var_s0, s32 *, 0x9C);
loop_31:
                    if ((var_v0 == 0xA) || (temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), s32 *, 0x60) != M2C_FIELD(var_s0, s32 *, 8), temp_s1 = M2C_FIELD((var_s0 + ((1 - temp_v0) << 6)), s32 *, 8), (M2C_FIELD((var_s0 + (temp_v0 << 6)), s32 *, 0xC) != arg0)) || (FCheckButtonObject(arg0, temp_s1) == 0)) {
                        var_s0 = M2C_FIELD(var_s0, void **, 0xAC);
                        if (var_s0 != NULL) {
                            var_v0 = M2C_FIELD(var_s0, s32 *, 0x9C);
                            goto loop_31;
                        }
                        goto block_37;
                    }
                    M2C_FIELD(arg0, s32 *, 0x2F8) = temp_s1;
                    M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A4E87)($v0) */);
                    QueueSwCallbackOnce(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A4E80)($v0) */), 0);
                    var_s4 = M2C_FIELD(arg0, u32 *, 0x1E0);
                } else {
block_37:
                    var_s2 = M2C_FIELD(var_s2, void **, 4);
                    if (var_s2 != NULL) {
                        goto loop_29;
                    }
                }
            }
            break;
        }
        SetButtonButtons(arg0, var_s4);
        break;
    }
}
