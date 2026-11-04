#include "m2c_macros.h"

s128 ConvertXfPos(M2C_UNK, s32, s128);              /* extern */
void *PvAllocSlotheapImpl(s32, M2C_UNK);            /* extern */
M2C_UNK RecalcSwXpMovement(s32, M2C_UNK, void **);  /* extern */
extern f32 D_FLT_002BFD30;
extern f32 D_FLT_002BFD34;

void PxpAdd(s32 arg0, void *arg1, void *arg2, f32 fparg0, void **arg_sp0) {
    void *sp10;
    s128 sp20;
    s32 var_s1;
    s32 var_s1_2;
    void *temp_a0;
    void *temp_a3;
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *var_v1;

    sp20 = M2C_ERROR(/* Read from unset register $t0 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
    var_s1 = 0;
    temp_v0 = PvAllocSlotheapImpl(arg0 + 0x3D40, M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf2 */));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
    sp10 = temp_v0;
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf3, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($v0) */);
    M2C_FIELD(temp_v0, s128 *, 0x80) = (s128) M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf3 */);
    do {
        temp_s0 = sp10 + (var_s1 << 6);
        if (var_s1 == 0) {
            M2C_FIELD(temp_s0, void **, 0) = arg1;
        } else {
            M2C_FIELD(temp_s0, void **, 0) = arg2;
        }
        temp_v1 = M2C_FIELD(temp_s0, void **, 0);
        if (temp_v1 != NULL) {
            M2C_FIELD(temp_s0, s32 *, 4) = (s32) M2C_FIELD(temp_v1, s32 *, 0);
            temp_a0 = M2C_FIELD(temp_v1, void **, 4);
            M2C_FIELD(temp_s0, void **, 0xC) = temp_a0;
            M2C_FIELD(temp_s0, s32 *, 8) = (s32) M2C_FIELD(M2C_FIELD(temp_a0, void **, 0xEC), s32 *, 0x60);
        }
        var_s1 += 1;
        M2C_FIELD(temp_s0, s128 *, 0x20) = ConvertXfPos(0, M2C_FIELD(temp_s0, s32 *, 4), M2C_FIELD(temp_s0, s128 *, 0x10));
    } while (var_s1 < 2);
    var_s1_2 = 0;
    M2C_FIELD(sp10, s32 *, 0xA4) = (s32) M2C_ERROR(/* Read from unset register $t3 */);
    M2C_FIELD(sp10, f32 *, 0x90) = fparg0;
    M2C_FIELD(sp10, s32 *, 0x9C) = (s32) M2C_ERROR(/* Read from unset register $t1 */);
    M2C_FIELD(sp10, f32 *, 0x94) = (f32) D_FLT_002BFD30;
    M2C_FIELD(sp10, f32 *, 0x98) = (f32) D_FLT_002BFD34;
    M2C_FIELD(sp10, s32 *, 0xA0) = (s32) M2C_ERROR(/* Read from unset register $t2 */);
    do {
        temp_a3 = M2C_FIELD((sp10 + (var_s1_2 << 6)), void **, 0xC);
        if (temp_a3 != NULL) {
            temp_v0_2 = M2C_FIELD(temp_a3, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *, s32, void *), 0x1BC)(temp_a3 + M2C_FIELD(temp_v0_2, s16 *, 0x1B8), sp10, var_s1_2, temp_a3);
        }
        var_s1_2 += 1;
    } while (var_s1_2 < 2);
    RecalcSwXpMovement(arg0, 1, &sp10);
    var_v1 = sp10;
    if (M2C_FIELD(var_v1, void **, 0xAC) != NULL) {
        var_v1 = M2C_FIELD(var_v1, void **, 0xAC);
loop_13:
        if (M2C_FIELD(var_v1, void **, 0xAC) != NULL) {
            var_v1 = M2C_FIELD(var_v1, void **, 0xAC);
            goto loop_13;
        }
    }
    M2C_FIELD(var_v1, void **, 0xAC) = (void *) *arg_sp0;
    *arg_sp0 = sp10;
}
