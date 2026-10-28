#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Read_thunk(); /* extern */
f32 F32Read__18CBinaryInputStream();             /* extern */
s32 NewStreamAmb();               /* extern */
M2C_UNK *PvAllocSwClearImpl__Fi();    /* extern */
s32 *PvAllocSwImpl__Fi();             /* extern */
s32 S16Read__18CBinaryInputStream();             /* extern */
s32 S32Read__18CBinaryInputStream();             /* extern */
s32 S8Read__18CBinaryInputStream();              /* extern */
s32 U8Read__18CBinaryInputStream();              /* extern */
M2C_UNK func_00118458();              /* extern */
M2C_UNK func_00259B48();                 /* extern */
M2C_UNK memset();                /* extern */
s32 snd_FlushSoundCommands();                       /* extern */
M2C_UNK snd_UnloadBank();               /* extern */
extern s32 B_002E1E54;

void LoadSndFromBrx(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp38;
    M2C_UNK sp8;
    s32 sp40;
    s32 sp44;
    M2C_UNK sp50;
    s32 sp90;
    M2C_UNK *sp94;
    M2C_UNK *temp_v0_7;
    M2C_UNK *var_s0_4;
    f32 temp_f0;
    s32 *temp_s2;
    s32 *temp_v0_10;
    s32 *temp_v0_5;
    s32 *var_s0_2;
    s32 temp_a0;
    s32 temp_s2_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 var_fp;
    s32 var_s0;
    s32 var_s0_3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_v1;
    void *temp_s0;
    void *temp_v0;

    func_00118458(arg1, sp);
    temp_v0 = arg0 + 0xA8;
    var_v1 = 1;
    if (sp != temp_v0) {
        if (temp_v0 != NULL) {
            var_v1 = (sp8 ^ sp38) == (M2C_FIELD(temp_v0, s32 *, 8) ^ M2C_FIELD(temp_v0, s32 *, 0x38));
        } else {
            var_v1 = 0;
        }
    }
    temp_s2 = arg0 + 0x1D4;
    if (var_v1 == 0) {
        M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $v0, ($sp) */);
        M2C_ERROR(/* unknown instruction: ldl $v1, 0xf($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, 0x8($sp) */);
        M2C_ERROR(/* unknown instruction: ldl $a0, 0x17($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $a0, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: ldl $a1, 0x1f($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $a1, 0x18($sp) */);
        M2C_ERROR(/* unknown instruction: sdl $v0, 0xaf($s4) */);
        M2C_ERROR(/* unknown instruction: sdr $v0, 0xa8($s4) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0xb7($s4) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, 0xb0($s4) */);
        M2C_ERROR(/* unknown instruction: sdl $a0, 0xbf($s4) */);
        M2C_ERROR(/* unknown instruction: sdr $a0, 0xb8($s4) */);
        M2C_ERROR(/* unknown instruction: sdl $a1, 0xc7($s4) */);
        M2C_ERROR(/* unknown instruction: sdr $a1, 0xc0($s4) */);
        M2C_ERROR(/* unknown instruction: ldl $v0, 0x27($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $v0, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: ldl $v1, 0x2f($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, 0x28($sp) */);
        M2C_ERROR(/* unknown instruction: ldl $a0, 0x37($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $a0, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: ldl $a1, 0x3f($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $a1, 0x38($sp) */);
        M2C_ERROR(/* unknown instruction: sdl $v0, 0xcf($s4) */);
        M2C_ERROR(/* unknown instruction: sdr $v0, 0xc8($s4) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0xd7($s4) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, 0xd0($s4) */);
        M2C_ERROR(/* unknown instruction: sdl $a0, 0xdf($s4) */);
        M2C_ERROR(/* unknown instruction: sdr $a0, 0xd8($s4) */);
        M2C_ERROR(/* unknown instruction: sdl $a1, 0xe7($s4) */);
        temp_a0 = M2C_FIELD(arg0, s32 *, 0xE8);
        if (temp_a0 != 0) {
            snd_UnloadBank(temp_a0, M2C_ERROR(/* unknown instruction: sdr $a1, 0xe0($s4) */));
            do {

            } while (snd_FlushSoundCommands() != 0);
            M2C_FIELD(arg0, s32 *, 0xE8) = 0;
        }
    }
    var_s1 = 0;
    temp_v0_2 = S16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0xF8) = temp_v0_2;
    sp40 = temp_v0_2 * 4;
    M2C_FIELD(&sp40, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, M2C_UNK **, 0xFC) = PvAllocSwClearImpl__Fi(&sp40, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0xF8) > 0) {
loop_13:
        temp_v0_3 = var_s1 * 4;
        var_s1 += 1;
        *(M2C_FIELD(arg0, M2C_UNK **, 0xFC) + temp_v0_3) = S8Read__18CBinaryInputStream(arg1);
        if (var_s1 < M2C_FIELD(arg0, s32 *, 0xF8)) {
            goto loop_13;
        }
    }
    var_s0 = 0;
    temp_v0_4 = S16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0x18) = temp_v0_4;
    sp40 = temp_v0_4 * 4;
    M2C_FIELD(&sp40, s32 *, 4) = 0x10;
    temp_v0_5 = PvAllocSwImpl__Fi(&sp40, 0x10);
    M2C_FIELD(arg0, s32 **, 0x100) = temp_v0_5;
    memset(temp_v0_5, -1, M2C_FIELD(arg0, s32 *, 0x18) * 4);
    if (M2C_FIELD(arg0, s32 *, 0xF8) > 0) {
        do {
            M2C_FIELD(arg0, s32 **, 0x100)[S16Read__18CBinaryInputStream(arg1)] = var_s0;
            var_s0 += 1;
        } while (var_s0 < M2C_FIELD(arg0, s32 *, 0xF8));
    }
    temp_v0_6 = S16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0x1D0) = temp_v0_6;
    if (temp_v0_6 > 0) {
        sp40 = 0x40;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        temp_v0_7 = PvAllocSwClearImpl__Fi(&sp40);
        M2C_FIELD(arg0, M2C_UNK **, 0xF4) = temp_v0_7;
        func_00118458(arg1, temp_v0_7);
        func_00259B48(arg0 + 0x228, NewStreamAmb(M2C_FIELD(arg0, M2C_UNK **, 0xF4), 4));
    }
    var_s1_2 = 0;
    memset(temp_s2, -1, 0x18);
    var_s0_2 = temp_s2;
    if (M2C_FIELD(arg0, s32 *, 0x1D0) > 0) {
        do {
            var_s1_2 += 1;
            *var_s0_2 = S16Read__18CBinaryInputStream(arg1);
            var_s0_2 += 4;
        } while (var_s1_2 < M2C_FIELD(arg0, s32 *, 0x1D0));
    }
    var_s0_3 = 0;
    temp_v0_8 = U8Read__18CBinaryInputStream(arg1);
    var_fp = 0;
    if (temp_v0_8 > 0) {
        do {
            var_fp = ((U8Read__18CBinaryInputStream(arg1) ^ B_002E1E54) == 0) ? var_s0_3 : var_fp;
            var_s0_3 += 1;
        } while (var_s0_3 < temp_v0_8);
    }
    var_s1_3 = 0;
    sp90 = S32Read__18CBinaryInputStream(arg1);
    sp40 = sp90 * 0x5C;
    M2C_FIELD(&sp40, s32 *, 4) = 0x10;
    sp94 = PvAllocSwClearImpl__Fi(&sp40);
    if (sp90 > 0) {
        do {
            temp_s0 = sp94 + (var_s1_3 * 0x5C);
            var_s1_4 = 0;
            M2C_FIELD(temp_s0, s32 *, 0x40) = S16Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s0, s32 *, 0x48) = S16Read__18CBinaryInputStream(arg1);
            if (temp_v0_8 > 0) {
                do {
                    func_00118458(arg1, &sp50);
                    temp_s2_2 = S8Read__18CBinaryInputStream(arg1);
                    temp_f0 = F32Read__18CBinaryInputStream(arg1);
                    var_s1_4 += 1;
                    if (var_s1_4 == var_fp) {
                        M2C_ERROR(/* unknown instruction: ldl $v1, 0x57($sp) */);
                        M2C_ERROR(/* unknown instruction: ldr $v1, 0x50($sp) */);
                        M2C_ERROR(/* unknown instruction: ldl $a0, 0x5f($sp) */);
                        M2C_ERROR(/* unknown instruction: ldr $a0, 0x58($sp) */);
                        M2C_ERROR(/* unknown instruction: ldl $a1, 0x67($sp) */);
                        M2C_ERROR(/* unknown instruction: ldr $a1, 0x60($sp) */);
                        M2C_ERROR(/* unknown instruction: ldl $v0, 0x6f($sp) */);
                        M2C_ERROR(/* unknown instruction: ldr $v0, 0x68($sp) */);
                        M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($s0) */);
                        M2C_ERROR(/* unknown instruction: sdr $v1, ($s0) */);
                        M2C_ERROR(/* unknown instruction: sdl $a0, 0xf($s0) */);
                        M2C_ERROR(/* unknown instruction: sdr $a0, 0x8($s0) */);
                        M2C_ERROR(/* unknown instruction: sdl $a1, 0x17($s0) */);
                        M2C_ERROR(/* unknown instruction: sdr $a1, 0x10($s0) */);
                        M2C_ERROR(/* unknown instruction: sdl $v0, 0x1f($s0) */);
                        M2C_ERROR(/* unknown instruction: sdr $v0, 0x18($s0) */);
                        M2C_ERROR(/* unknown instruction: ldl $v1, 0x77($sp) */);
                        M2C_ERROR(/* unknown instruction: ldr $v1, 0x70($sp) */);
                        M2C_ERROR(/* unknown instruction: ldl $a0, 0x7f($sp) */);
                        M2C_ERROR(/* unknown instruction: ldr $a0, 0x78($sp) */);
                        M2C_ERROR(/* unknown instruction: ldl $a1, 0x87($sp) */);
                        M2C_ERROR(/* unknown instruction: ldr $a1, 0x80($sp) */);
                        M2C_ERROR(/* unknown instruction: ldl $v0, 0x8f($sp) */);
                        M2C_ERROR(/* unknown instruction: ldr $v0, 0x88($sp) */);
                        M2C_ERROR(/* unknown instruction: sdl $v1, 0x27($s0) */);
                        M2C_ERROR(/* unknown instruction: sdr $v1, 0x20($s0) */);
                        M2C_ERROR(/* unknown instruction: sdl $a0, 0x2f($s0) */);
                        M2C_ERROR(/* unknown instruction: sdr $a0, 0x28($s0) */);
                        M2C_ERROR(/* unknown instruction: sdl $a1, 0x37($s0) */);
                        M2C_ERROR(/* unknown instruction: sdr $a1, 0x30($s0) */);
                        M2C_ERROR(/* unknown instruction: sdl $v0, 0x3f($s0) */);
                        M2C_ERROR(/* unknown instruction: sdr $v0, 0x38($s0) */);
                        M2C_FIELD(temp_s0, s32 *, 0x4C) = temp_s2_2;
                        M2C_FIELD(temp_s0, f32 *, 0x50) = temp_f0;
                    }
                } while (var_s1_4 < temp_v0_8);
            }
            var_s1_3 += 1;
            temp_v0_9 = S32Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s0, s32 *, 0x54) = temp_v0_9;
            sp40 = temp_v0_9 * 8;
            sp44 = 0x10;
            temp_v0_10 = PvAllocSwImpl__Fi(&sp40);
            M2C_FIELD(temp_s0, s32 **, 0x58) = temp_v0_10;
            CBinaryInputStream_Read_thunk(arg1, M2C_FIELD(temp_s0, s32 *, 0x54) * 8, temp_v0_10);
            M2C_FIELD(temp_s0, void **, 0x44) = (void *) M2C_FIELD(arg0, void **, 0xEC);
            M2C_FIELD(arg0, void **, 0xEC) = temp_s0;
        } while (var_s1_3 < sp90);
    }
    var_s1_5 = S32Read__18CBinaryInputStream(arg1);
    sp40 = var_s1_5 * 0x48;
    M2C_FIELD(&sp40, s32 *, 4) = 0x10;
    var_s0_4 = PvAllocSwClearImpl__Fi(&sp40);
    if (var_s1_5 > 0) {
        do {
            var_s1_5 -= 1;
            M2C_FIELD(var_s0_4, s32 *, 0x40) = S16Read__18CBinaryInputStream(arg1);
            func_00118458(arg1, var_s0_4);
            M2C_FIELD(var_s0_4, M2C_UNK **, 0x44) = (M2C_UNK *) M2C_FIELD(arg0, M2C_UNK **, 0xF0);
            M2C_FIELD(arg0, M2C_UNK **, 0xF0) = var_s0_4;
            var_s0_4 += 0x48;
        } while (var_s1_5 != 0);
    }
}
