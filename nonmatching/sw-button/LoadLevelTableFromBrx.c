#include "m2c_macros.h"

s32 PvAllocSwClearImpl__Fi();       /* extern */
s32 PvAllocSwImpl__Fi();     /* extern */
s16 U16Read__18CBinaryInputStream();             /* extern */
s32 U32Read__18CBinaryInputStream();             /* extern */
s32 U8Read__18CBinaryInputStream();              /* extern */
M2C_UNK func_00118458();                    /* extern */
extern s32 B_003E1C38;
extern s32 B_003E1C3C;
extern s32 B_003E1C40;
extern s32 B_003E1C44;
extern s32 B_003E1C48;
extern s32 B_003E1C4C;
extern s32 B_003E1C50;

void LoadLevelTableFromBrx(s32 arg0, s32 arg1) {
    char sp[0x400];
    s32 temp_a1;
    u8 *temp_s0;
    s32 temp_v0;
    u8 *temp_v1;
    s32 var_s0;
    s32 var_s1;
    void *temp_s1;

    B_003E1C38 = U32Read__18CBinaryInputStream(arg1);
    B_003E1C3C = U32Read__18CBinaryInputStream(arg1);
    B_003E1C40 = PvAllocSwImpl__Fi(sp, &B_003E1C3C, B_003E1C38 << 6, 0x10);
    B_003E1C44 = PvAllocSwImpl__Fi(sp, (s32 *) (B_003E1C38 * 4), 0x10);
    B_003E1C48 = PvAllocSwImpl__Fi(sp, (s32 *) (B_003E1C38 * 4), 0x10);
    var_s1 = 0;
    B_003E1C4C = PvAllocSwImpl__Fi(sp, (s32 *) (B_003E1C38 * 8), 0x10);
    B_003E1C50 = PvAllocSwClearImpl__Fi(sp, 0x240, 0x10);
    if (B_003E1C38 > 0) {
        temp_a1 = B_003E1C40;
        do {
            temp_s0 = var_s1 * 4;
            func_00118458(arg1, temp_a1 + (var_s1 << 6));
            *(temp_s0 + B_003E1C44) = U8Read__18CBinaryInputStream(arg1);
            *(temp_s0 + B_003E1C48) = U8Read__18CBinaryInputStream(arg1);
            if (U8Read__18CBinaryInputStream(arg1) != 0) {
                M2C_ERROR(/* unknown instruction: ldl $a1, 0x7($a0) */);
                M2C_ERROR(/* unknown instruction: ldr $a1, ($a0) */);
                M2C_ERROR(/* unknown instruction: ldl $a2, 0xf($a0) */);
                M2C_ERROR(/* unknown instruction: ldr $a2, 0x8($a0) */);
                M2C_ERROR(/* unknown instruction: ldl $a3, 0x17($a0) */);
                M2C_ERROR(/* unknown instruction: ldr $a3, 0x10($a0) */);
                M2C_ERROR(/* unknown instruction: ldl $v1, 0x1f($a0) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, 0x18($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $a1, 0x7($v0) */);
                M2C_ERROR(/* unknown instruction: sdr $a1, ($v0) */);
                M2C_ERROR(/* unknown instruction: sdl $a2, 0xf($v0) */);
                M2C_ERROR(/* unknown instruction: sdr $a2, 0x8($v0) */);
                M2C_ERROR(/* unknown instruction: sdl $a3, 0x17($v0) */);
                M2C_ERROR(/* unknown instruction: sdr $a3, 0x10($v0) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0x1f($v0) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, 0x18($v0) */);
                M2C_ERROR(/* unknown instruction: ldl $a1, 0x27($a0) */);
                M2C_ERROR(/* unknown instruction: ldr $a1, 0x20($a0) */);
                M2C_ERROR(/* unknown instruction: ldl $a2, 0x2f($a0) */);
                M2C_ERROR(/* unknown instruction: ldr $a2, 0x28($a0) */);
                M2C_ERROR(/* unknown instruction: ldl $a3, 0x37($a0) */);
                M2C_ERROR(/* unknown instruction: ldr $a3, 0x30($a0) */);
                M2C_ERROR(/* unknown instruction: ldl $v1, 0x3f($a0) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, 0x38($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $a1, 0x27($v0) */);
                M2C_ERROR(/* unknown instruction: sdr $a1, 0x20($v0) */);
                M2C_ERROR(/* unknown instruction: sdl $a2, 0x2f($v0) */);
                M2C_ERROR(/* unknown instruction: sdr $a2, 0x28($v0) */);
                M2C_ERROR(/* unknown instruction: sdl $a3, 0x37($v0) */);
                M2C_ERROR(/* unknown instruction: sdr $a3, 0x30($v0) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0x3f($v0) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, 0x38($v0) */);
            }
            var_s0 = 0;
            temp_s1 = B_003E1C4C + (var_s1 * 8);
            temp_v0 = U8Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s1, s32 *, 0) = temp_v0;
            M2C_FIELD(temp_s1, s32 *, 4) = PvAllocSwImpl__Fi(sp, (s32 *) (temp_v0 * 2), 0x10);
            if (M2C_FIELD(temp_s1, s32 *, 0) > 0) {
                do {
                    temp_v1 = var_s0 * 2;
                    var_s0 += 1;
                    *(temp_v1 + M2C_FIELD(temp_s1, s32 *, 4)) = U16Read__18CBinaryInputStream(arg1);
                } while (var_s0 < M2C_FIELD(temp_s1, s32 *, 0));
            }
            var_s1 += 1;
        } while (var_s1 < B_003E1C38);
    }
}
