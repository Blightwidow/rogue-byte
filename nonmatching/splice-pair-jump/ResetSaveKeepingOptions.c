#include "m2c_macros.h"

M2C_UNK CRef_CopyConstruct(s32 *, s32 *);           /* extern */
M2C_UNK CRef_Destruct(s32 *);                       /* extern */
M2C_UNK CStackFrame_Construct(void *);              /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK);    /* extern */
s32 FSaveDataMatchesLayout(M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK RefGetSaveValue(s32 *, M2C_UNK *, s32, s32); /* extern */
M2C_UNK RefSetGameSaveValue(s32 *, s32, s32 *, s32); /* extern */
M2C_UNK StoreAudioModeInSave();                     /* extern */
M2C_UNK __as__4CRefRC4CRef(s32 *, s32 *);           /* extern */
M2C_UNK memset(s32, M2C_UNK, M2C_UNK);              /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK B_003E0EA8;

void ResetSaveKeepingOptions(s32 arg0, s32 arg1) {
    char sp[0x400];
    s32 sp10;
    s32 sp38;
    s32 sp40;
    s32 sp44;
    s32 sp48;
    s32 sp4C;
    s32 sp50;
    s32 sp54;
    s32 sp58;
    s32 sp5C;
    s32 sp60;
    s32 sp64;
    s32 sp68;
    s32 sp70;
    M2C_UNK spC8;
    s32 *temp_s6;
    s32 *var_a1;
    s32 *var_s0;
    s32 *var_s0_2;
    s32 *var_s0_3;
    s32 *var_s1;
    s32 *var_s1_2;
    s32 *var_t6;
    s32 var_s4;
    s32 var_t7;
    u32 var_s3;
    u32 var_s3_2;

    var_s4 = arg1;
    CStackFrame_Construct(sp);
    var_t6 = &sp70;
    temp_s6 = var_t6;
    var_t7 = 0xA;
    sp40 = M2C_FIELD(&B_003DD490, s32 *, 0x3B2C);
    sp44 = M2C_FIELD(&B_003DD490, s32 *, 0x3B48);
    sp48 = M2C_FIELD(&B_003DD490, s32 *, 0x3B54);
    sp4C = M2C_FIELD(&B_003DD490, s32 *, 0x3B4C);
    sp50 = M2C_FIELD(&B_003DD490, s32 *, 0x3B50);
    sp54 = M2C_FIELD(&B_003DD490, s32 *, 0x3B30);
    sp58 = M2C_FIELD(&B_003DD490, s32 *, 0x3B34);
    sp5C = M2C_FIELD(&B_003DD490, s32 *, 0x3B38);
    sp60 = M2C_FIELD(&B_003DD490, s32 *, 0x3B3C);
    sp64 = M2C_FIELD(&B_003DD490, s32 *, 0x3B40);
    sp68 = M2C_FIELD(&B_003DD490, s32 *, 0x3B44);
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x47($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: ldl $v1, 0x4f($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $v1, 0x48($sp) */);
    M2C_ERROR(/* unknown instruction: ldl $a0, 0x57($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $a0, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: ldl $a1, 0x5f($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $a1, 0x58($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x17($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v1, 0x1f($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v1, 0x18($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $a0, 0x27($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $a0, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $a1, 0x2f($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $a1, 0x28($sp) */);
    M2C_ERROR(/* unknown instruction: ldl $v0, 0x67($sp) */);
    M2C_ERROR(/* unknown instruction: ldr $v0, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: sdl $v0, 0x37($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v0, 0x30($sp) */);
    sp38 = sp68;
    do {
        *var_t6 = -1;
        var_t7 -= 1;
        var_t6 += 8;
    } while (var_t7 != -1);
    if (var_s4 != 0) {
        var_s4 = (FSaveDataMatchesLayout(&B_003E0EA8, arg0, M2C_FIELD(&B_003DD490, s32 *, 0x3B50), M2C_FIELD(&B_003DD490, s32 *, 0x3B30)) == 0) ? 0 : var_s4;
        if (var_s4 != 0) {
            var_s3 = 0;
            var_s1 = &sp10;
            var_s0 = temp_s6;
            do {
                RefGetSaveValue(&sp40, &B_003E0EA8, *var_s1, arg0);
                var_s3 += 1;
                __as__4CRefRC4CRef(var_s0, &sp40);
                var_s1 += 4;
                var_s0 += 8;
                CRef_Destruct(&sp40);
            } while (var_s3 < 0xBU);
        }
    }
    memset(arg0, 0, 0x5400);
    StoreAudioModeInSave();
    var_s0_2 = temp_s6;
    if (var_s4 != 0) {
        var_s3_2 = 0;
        var_s1_2 = &sp10;
        var_a1 = var_s0_2;
        do {
            CRef_CopyConstruct(&sp40, var_a1);
            var_s3_2 += 1;
            RefSetGameSaveValue(&sp50, *var_s1_2, &sp40, arg0);
            var_s1_2 += 4;
            var_s0_2 += 8;
            CRef_Destruct(&sp50);
            CRef_Destruct(&sp40);
            var_a1 = var_s0_2;
        } while (var_s3_2 < 0xBU);
    }
    if (temp_s6 != &spC8) {
        var_s0_3 = &spC8 - 8;
        do {
            CRef_Destruct(var_s0_3);
            var_s0_3 -= 8;
        } while (temp_s6 != var_s0_3);
    }
    CStackFrame_Destructor(sp, 2);
}
