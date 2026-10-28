#include "m2c_macros.h"

M2C_UNK ClearSle(s32);                              /* extern */
s32 IinstFindFreeSprite(void *);                    /* extern */
M2C_UNK StartSpriteInstance(void *, s32, s32, s32, M2C_UNK, s32); /* extern */
M2C_UNK StopSpriteInstance(void *, s32);            /* extern */

s32 FStartSpriteLabelInstance(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp10;
    s32 sp20;
    s32 sp24;
    s32 temp_a1;
    s32 temp_s5;
    s32 temp_v1_2;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s7;
    s32 var_v0;
    void *temp_v1;
    void *var_s0;

    var_s7 = arg3;
    sp20 = arg2;
    if (M2C_ERROR(/* Read from unset register $t0 */) == 0) {
        var_s7 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x84), void **, 8), s32 *, 0);
    }
    var_s3 = 0;
    if (var_s7 > 0) {
        temp_s5 = arg1 * 0x30;
        sp24 = 0xFFFFFFFF;
        var_s0 = M2C_ERROR(/* Read from unset register $t0 */);
        var_s4 = M2C_ERROR(/* Read from unset register $t0 */) + 0x10;
        var_s2 = M2C_ERROR(/* Read from unset register $t0 */) + 0x68;
loop_4:
        temp_v1 = M2C_FIELD(var_s0, void **, 0x30);
        if ((temp_v1 != NULL) && (M2C_FIELD(temp_v1, s32 *, 4) == 4)) {
            temp_v1_2 = M2C_FIELD(temp_v1, s32 *, 0x10);
            temp_a1 = M2C_FIELD(var_s0, s32 *, 0x58);
            if (temp_v1_2 == arg1) {
                StopSpriteInstance(M2C_FIELD(arg0, void **, 0x84) + temp_s5, temp_a1);
                ClearSle(var_s2);
                M2C_FIELD(var_s0, s32 *, 0x58) = IinstFindFreeSprite(M2C_FIELD(arg0, void **, 0x84) + temp_s5);
                sp10 = sp24;
                StartSpriteInstance(M2C_FIELD(arg0, void **, 0x84) + temp_s5, sp20, M2C_FIELD(var_s0, s32 *, 0x58), var_s4, 0, 0x7F7F7F7F);
                return 1;
            }
            var_v0 = 1;
            if (FStartSpriteLabelInstance(arg0, arg1, sp20, M2C_FIELD(((temp_a1 * 0x18) + M2C_FIELD(((temp_v1_2 * 0x30) + M2C_FIELD(arg0, void **, 0x84)), s32 *, 8)), s32 *, 0)) == 0) {
                goto block_9;
            }
            /* Duplicate return node #11. Try simplifying control flow for better match */
            return var_v0;
        }
block_9:
        var_s3 += 1;
        var_s4 += 0x70;
        var_s2 += 0x70;
        var_s0 += 0x70;
        if (var_s3 >= var_s7) {
            goto block_10;
        }
        goto loop_4;
    }
block_10:
    var_v0 = 0;
    return var_v0;
}
