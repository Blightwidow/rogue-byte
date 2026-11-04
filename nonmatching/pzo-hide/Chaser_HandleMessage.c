#include "m2c_macros.h"

M2C_UNK HandlePoMessage();                          /* extern */
M2C_UNK LoadRotateMatrixRad(s128 *, s128, f32);     /* extern */
M2C_UNK func_00204E38(void *, s32, s128, f32, s128, s128, s128); /* extern */
extern s128 g_2a2dc0;

void Chaser_HandleMessage(void *arg0, s32 arg1, void *arg2) {
    M2C_UNK sp40;
    M2C_UNK sp50;
    s128 sp30;
    s32 temp_v1;
    s32 temp_v1_2;
    void *temp_v0;
    void *temp_v1_3;

    HandlePoMessage();
    if (arg1 == 9) {
        temp_v1 = M2C_FIELD(arg2, s32 *, 0);
        if ((temp_v1 == M2C_FIELD(arg0, s32 *, 0x194)) || ((temp_v0 = M2C_FIELD(arg0, void **, 0x198), (temp_v0 != NULL)) && (temp_v1 == M2C_FIELD(temp_v0, s32 *, 0x30)))) {
            temp_v1_2 = M2C_FIELD(arg2, s32 *, 8);
            switch (temp_v1_2) {                    /* irregular */
            case 0x15E:
                LoadRotateMatrixRad(&sp30, g_2a2dc0, M2C_FIELD(arg0, f32 *, 0x204));
                func_00204E38(arg0, M2C_FIELD(arg2, s32 *, 0), sp30, M2C_FIELD(arg2, f32 *, 4), sp30, sp40, sp50);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf5 */);
                temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf5x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf1, $vf5z */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x210($s1) */);
                M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
                break;
            case 0x25:
                M2C_FIELD(arg0, s32 *, 0x1C8) = 1;
                break;
            case 0x26:
                M2C_FIELD(arg0, s32 *, 0x1C8) = 0;
                break;
            case 0x27:
                M2C_FIELD(arg0, s32 *, 0x1CC) = 1;
                break;
            case 0x28:
                M2C_FIELD(arg0, s32 *, 0x1CC) = 0;
                break;
            }
        }
    }
}
