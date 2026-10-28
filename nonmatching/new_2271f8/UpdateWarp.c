#include "m2c_macros.h"

s128 ConvertAloPos();       /* extern */
s32 PcgtPointInCbspQuick__FP4CBSPP6VECTOR(); /* extern */
M2C_UNK PosLoWorld();                            /* extern */
s32 PpoSwFocusBase();                      /* extern */
M2C_UNK QueueMovie();                 /* extern */
M2C_UNK RequestTransition(); /* extern */
M2C_UNK UpdateLo();                                 /* extern */
M2C_UNK Warp_SetState();             /* extern */
M2C_UNK Warp_Start();                         /* extern */
extern M2C_UNK B_002F66B0;
extern M2C_UNK B_003DD490;
extern f32 g_2dded0;

void UpdateWarp(void *arg0) {
    f32 temp_f1;
    s32 temp_a0;
    u8 *temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    u32 temp_v1;
    u32 temp_v1_2;

    UpdateLo();
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x13C);
    switch (temp_v1) {                              /* switch 1 */
    case 4:                                         /* switch 1 */
        temp_f1 = M2C_FIELD(arg0, f32 *, 0x158);
        if (temp_f1 > 0.0f) {
            if (temp_f1 <= g_2dded0) {
                var_s0 = 0;
                if (M2C_FIELD(arg0, s32 *, 0x148) > 0) {
                    do {
                        temp_v0 = var_s0 * 4;
                        var_s0 += 1;
                        QueueMovie(&B_002F66B0, *(temp_v0 + M2C_FIELD(arg0, s32 *, 0x14C)));
                    } while (var_s0 < M2C_FIELD(arg0, s32 *, 0x148));
                }
                RequestTransition(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x144), M2C_FIELD(arg0, s32 *, 0x150), -1);
                M2C_FIELD(arg0, f32 *, 0x158) = 0.0f;
            }
        } else {
        default:                                    /* switch 1 */
        }
        return;
    case 0:                                         /* switch 1 */
    case 1:                                         /* switch 1 */
    case 3:                                         /* switch 1 */
        temp_v0_2 = PpoSwFocusBase(&B_003DD490);
        if (temp_v0_2 != 0) {
            PosLoWorld(temp_v0_2);
            temp_a0 = PcgtPointInCbspQuick__FP4CBSPP6VECTOR(M2C_FIELD(arg0, s32 *, 0xEC), 0x7FFFFFFF, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), ConvertAloPos(0, arg0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */))) != 0;
            temp_v1_2 = M2C_FIELD(arg0, u32 *, 0x13C);
            switch (temp_v1_2) {                    /* switch 2; irregular */
            case 3:                                 /* switch 2 */
                if (temp_a0 != 0) {
                    Warp_Start(arg0);
                }
                break;
            case 1:                                 /* switch 2 */
                if (temp_a0 != 0) {
                    Warp_SetState(arg0, 0);
                } else if (M2C_FIELD(arg0, f32 *, 0x15C) < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x140))) {
                    Warp_SetState(arg0, 3);
                }
                break;
            case 0:                                 /* switch 2 */
                if (temp_a0 == 0) {
                    Warp_SetState(arg0, 1);
                }
                break;
            }
        }
        break;
    }
}
