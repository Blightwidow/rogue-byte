#include "m2c_macros.h"

M2C_UNK AppendDlEntry(s32, s32);                    /* extern */
s32 FFindDlEntry(s32, s32);                         /* extern */
s128 PosLoWorld(void *);                            /* extern */
void *PpoSwFocusBase();                             /* extern */
M2C_UNK RemoveDlEntry(s32, s32);                    /* extern */
extern M2C_UNK B_002DDF40;
extern s32 B_003E0E70;

void func_00148300(s32 arg0, void *arg1) {
    M2C_UNK saved_reg_s2;
    s128 sp0;
    s128 sp10;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 var_f20;
    s128 var_v0;
    s32 temp_s0;
    s32 temp_s3;
    s32 var_s0;
    s32 var_s2;
    s64 temp_a0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    var_s2 = saved_reg_s2;
    if (B_003E0E70 == 0) {
        temp_s0 = M2C_FIELD(&B_002DDF40, s32 *, 0x14);
        sp0 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
        temp_v0 = PpoSwFocusBase();
        if (temp_v0 == NULL) {
            var_v0 = sp0;
        } else {
            var_v0 = PosLoWorld(temp_v0);
        }
        sp10 = var_v0;
        temp_a0 = (s64) (M2C_FIELD(arg1, s64 *, 0x28) << 8) >> 0x3C;
        temp_s3 = M2C_FIELD(arg1, s32 *, 0x14);
        switch (temp_a0) {                          /* irregular */
        case 0:
            if (temp_s0 & M2C_FIELD(arg1, u8 *, 0x2D)) {
                temp_f20 = M2C_FIELD(arg1, f32 *, 0x38);
                var_s2 = 1;
                var_f20 = temp_f20 * temp_f20;
                PosLoWorld(arg1);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
block_21:
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                var_s0 = arg0 + 0x2C;
                if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < var_f20)) {
                    goto block_22;
                }
            } else {
            case 2:
block_22:
                var_s2 = 0;
            default:
block_23:
                var_s0 = arg0 + 0x2C;
            }
            break;
        case 3:
            if (temp_s0 & M2C_FIELD(arg1, u8 *, 0x2D)) {
                temp_f20_2 = M2C_FIELD(arg1, f32 *, 0x38);
                var_s2 = 1;
                var_f20 = temp_f20_2 * temp_f20_2;
                PosLoWorld(arg1);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
                goto block_21;
            }
            goto block_22;
        case 1:
            var_s2 = 1;
            goto block_23;
        }
        if (var_s2 != FFindDlEntry(var_s0, temp_s3)) {
            if (var_s2 == 0) {
                temp_v0_2 = M2C_FIELD(arg1, void **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0xB4)(arg1 + M2C_FIELD(temp_v0_2, s16 *, 0xB0));
                RemoveDlEntry(var_s0, temp_s3);
            } else {
                AppendDlEntry(var_s0, temp_s3);
                temp_v0_3 = M2C_FIELD(arg1, void **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *), 0xBC)(arg1 + M2C_FIELD(temp_v0_3, s16 *, 0xB8));
            }
        }
    }
}
