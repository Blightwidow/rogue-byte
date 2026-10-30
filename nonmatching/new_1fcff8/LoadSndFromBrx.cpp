typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadSndFromBrx {
    /* 0x000 */ char pad0[8];
    /* 0x008 */ s32 sp8;                            /* inferred */
    /* 0x00C */ char padC[0x2C];                    /* maybe part of sp8[0xC]? */
    /* 0x038 */ s32 sp38;                           /* inferred */
    /* 0x03C */ char pad3C[4];
    /* 0x040 */ s32 sp40;                           /* inferred */
    /* 0x044 */ s32 sp44;                           /* inferred */
    /* 0x048 */ char pad48[8];                      /* maybe part of sp44[3]? */
    /* 0x050 */ M2C_UNK sp50;                       /* inferred */
    /* 0x050 */ char pad50[0x40];
    /* 0x090 */ s32 sp90;                           /* inferred */
    /* 0x094 */ M2C_UNK *sp94;                      /* inferred */
    /* 0x098 */ char pad98[0xA8];
};                                                  /* size = 0x140 */
#define sp8 (*(s32 *)(sp + 0x008))
#define sp38 (*(s32 *)(sp + 0x038))
void CBinaryInputStream_Read_thunk(s32, s32, s32 *);
f32 F32Read__18CBinaryInputStream(s32);
s32 NewStreamAmb(M2C_UNK *, M2C_UNK);
s32 *PvAllocSwClearImpl__Fi(...);
s32 *PvAllocSwImpl__Fi(...);
s32 S16Read__18CBinaryInputStream(s32);
s32 S32Read__18CBinaryInputStream(s32);
s32 S8Read__18CBinaryInputStream(s32);
s32 U8Read__18CBinaryInputStream(s32);
void func_00118458(s32, M2C_UNK *);
void func_00259B48(s8 *, s32);
s32 memset(s32 *, M2C_UNK, s32);
s32 snd_FlushSoundCommands();
void snd_UnloadBank(s32, M2C_UNK);
extern s32 B_002E1E54;
void LoadSndFromBrx(s8 *arg0, s32 arg1) {
    s8 sp[0x90] __attribute__((aligned(16)));
    s32 sp40;
    s32 sp44;
    M2C_UNK sp50;
    s32 sp90;
    M2C_UNK *sp94;
    M2C_UNK *temp_v0_9;
    M2C_UNK *var_s0_4;
    M2C_UNK temp_a0;
    M2C_UNK temp_a0_2;
    M2C_UNK temp_a0_4;
    M2C_UNK temp_a0_5;
    M2C_UNK temp_a1;
    M2C_UNK temp_a1_2;
    M2C_UNK temp_a1_3;
    M2C_UNK temp_a1_4;
    M2C_UNK temp_v0_11;
    M2C_UNK temp_v0_12;
    M2C_UNK temp_v0_2;
    M2C_UNK temp_v0_3;
    M2C_UNK temp_v1;
    M2C_UNK temp_v1_2;
    M2C_UNK temp_v1_3;
    M2C_UNK temp_v1_4;
    f32 temp_f0;
    s32 *temp_s2;
    s32 *temp_v0_14;
    s32 *temp_v0_7;
    s32 *var_s0_2;
    s32 temp_a0_3;
    s32 temp_s2_2;
    s32 temp_v0_10;
    s32 temp_v0_13;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_8;
    s32 var_fp;
    s32 var_s0;
    s32 var_s0_3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_v1;
    s8 *temp_s0;
    s8 *temp_v0;
    func_00118458(arg1, (M2C_UNK *)(sp));
    temp_v0 = arg0 + 0xA8;
    var_v1 = 1;
    if (sp != temp_v0) {
        if (temp_v0 != NULL) {
            var_v1 = (sp8 ^ sp38) == (M2C_FIELD(temp_v0, s32 *, 8) ^ M2C_FIELD(temp_v0, s32 *, 0x38));
        } else {
            var_v1 = 0;
        }
    }
    temp_s2 = (s32 *)(arg0 + 0x1D4);
    if (var_v1 == 0) {
        s32 vu_1;
        asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_1) : "r"(sp));
        s32 vu_2;
        asm volatile("ldr %0, (%1)" : "=r"(vu_2) : "r"(sp), "0"(vu_1));
        temp_v0_2 = vu_2;
        s32 vu_3;
        asm volatile("ldl %0, 0xf(%1)" : "=r"(vu_3) : "r"(sp));
        s32 vu_4;
        asm volatile("ldr %0, 0x8(%1)" : "=r"(vu_4) : "r"(sp), "0"(vu_3));
        temp_v1 = vu_4;
        s32 vu_5;
        asm volatile("ldl %0, 0x17(%1)" : "=r"(vu_5) : "r"(sp));
        s32 vu_6;
        asm volatile("ldr %0, 0x10(%1)" : "=r"(vu_6) : "r"(sp), "0"(vu_5));
        temp_a0 = vu_6;
        s32 vu_7;
        asm volatile("ldl %0, 0x1f(%1)" : "=r"(vu_7) : "r"(sp));
        s32 vu_8;
        asm volatile("ldr %0, 0x18(%1)" : "=r"(vu_8) : "r"(sp), "0"(vu_7));
        temp_a1 = vu_8;
        asm volatile("sdl %0, 0xaf(%1)" : : "r"(temp_v0_2), "r"(arg0));
        asm volatile("sdr %0, 0xa8(%1)" : : "r"(temp_v0_2), "r"(arg0));
        asm volatile("sdl %0, 0xb7(%1)" : : "r"(temp_v1), "r"(arg0));
        asm volatile("sdr %0, 0xb0(%1)" : : "r"(temp_v1), "r"(arg0));
        asm volatile("sdl %0, 0xbf(%1)" : : "r"(temp_a0), "r"(arg0));
        asm volatile("sdr %0, 0xb8(%1)" : : "r"(temp_a0), "r"(arg0));
        asm volatile("sdl %0, 0xc7(%1)" : : "r"(temp_a1), "r"(arg0));
        asm volatile("sdr %0, 0xc0(%1)" : : "r"(temp_a1), "r"(arg0));
        s32 vu_9;
        asm volatile("ldl %0, 0x27(%1)" : "=r"(vu_9) : "r"(sp));
        s32 vu_10;
        asm volatile("ldr %0, 0x20(%1)" : "=r"(vu_10) : "r"(sp), "0"(vu_9));
        temp_v0_3 = vu_10;
        s32 vu_11;
        asm volatile("ldl %0, 0x2f(%1)" : "=r"(vu_11) : "r"(sp));
        s32 vu_12;
        asm volatile("ldr %0, 0x28(%1)" : "=r"(vu_12) : "r"(sp), "0"(vu_11));
        temp_v1_2 = vu_12;
        s32 vu_13;
        asm volatile("ldl %0, 0x37(%1)" : "=r"(vu_13) : "r"(sp));
        s32 vu_14;
        asm volatile("ldr %0, 0x30(%1)" : "=r"(vu_14) : "r"(sp), "0"(vu_13));
        temp_a0_2 = vu_14;
        s32 vu_15;
        asm volatile("ldl %0, 0x3f(%1)" : "=r"(vu_15) : "r"(sp));
        s32 vu_16;
        asm volatile("ldr %0, 0x38(%1)" : "=r"(vu_16) : "r"(sp), "0"(vu_15));
        temp_a1_2 = vu_16;
        asm volatile("sdl %0, 0xcf(%1)" : : "r"(temp_v0_3), "r"(arg0));
        asm volatile("sdr %0, 0xc8(%1)" : : "r"(temp_v0_3), "r"(arg0));
        asm volatile("sdl %0, 0xd7(%1)" : : "r"(temp_v1_2), "r"(arg0));
        asm volatile("sdr %0, 0xd0(%1)" : : "r"(temp_v1_2), "r"(arg0));
        asm volatile("sdl %0, 0xdf(%1)" : : "r"(temp_a0_2), "r"(arg0));
        asm volatile("sdr %0, 0xd8(%1)" : : "r"(temp_a0_2), "r"(arg0));
        asm volatile("sdl %0, 0xe7(%1)" : : "r"(temp_a1_2), "r"(arg0));
        asm volatile("sdr %0, 0xe0(%1)" : : "r"(temp_a1_2), "r"(arg0));
        temp_a0_3 = M2C_FIELD(arg0, s32 *, 0xE8);
        if (temp_a0_3 != 0) {
            snd_UnloadBank(temp_a0_3, temp_a1_2);
            do {
            } while (snd_FlushSoundCommands() != 0);
            M2C_FIELD(arg0, s32 *, 0xE8) = 0;
        }
    }
    var_s1 = 0;
    temp_v0_4 = S16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0xF8) = temp_v0_4;
    sp40 = temp_v0_4 * 4;
    M2C_FIELD(&sp40, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, M2C_UNK **, 0xFC) = PvAllocSwClearImpl__Fi(&sp40, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0xF8) > 0) {
loop_13:
        temp_v0_5 = var_s1 * 4;
        var_s1 += 1;
        *(M2C_FIELD(arg0, M2C_UNK **, 0xFC) + temp_v0_5) = S8Read__18CBinaryInputStream(arg1);
        if (var_s1 < M2C_FIELD(arg0, s32 *, 0xF8)) {
            goto loop_13;
        }
    }
    var_s0 = 0;
    temp_v0_6 = S16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0x18) = temp_v0_6;
    sp40 = temp_v0_6 * 4;
    M2C_FIELD(&sp40, s32 *, 4) = 0x10;
    temp_v0_7 = PvAllocSwImpl__Fi(arg0, &sp40, 0x10);
    M2C_FIELD(arg0, s32 **, 0x100) = temp_v0_7;
    memset(temp_v0_7, -1, M2C_FIELD(arg0, s32 *, 0x18) * 4);
    if (M2C_FIELD(arg0, s32 *, 0xF8) > 0) {
        do {
            M2C_FIELD(arg0, s32 **, 0x100)[S16Read__18CBinaryInputStream(arg1)] = var_s0;
            var_s0 += 1;
        } while (var_s0 < M2C_FIELD(arg0, s32 *, 0xF8));
    }
    temp_v0_8 = S16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0x1D0) = temp_v0_8;
    if (temp_v0_8 > 0) {
        sp40 = 0x40;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        temp_v0_9 = PvAllocSwClearImpl__Fi(&sp40);
        M2C_FIELD(arg0, M2C_UNK **, 0xF4) = temp_v0_9;
        func_00118458(arg1, temp_v0_9);
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
    temp_v0_10 = U8Read__18CBinaryInputStream(arg1);
    var_fp = 0;
    if (temp_v0_10 > 0) {
        do {
            var_fp = ((U8Read__18CBinaryInputStream(arg1) ^ B_002E1E54) == 0) ? var_s0_3 : var_fp;
            var_s0_3 += 1;
        } while (var_s0_3 < temp_v0_10);
    }
    var_s1_3 = 0;
    sp90 = S32Read__18CBinaryInputStream(arg1);
    sp40 = sp90 * 0x5C;
    M2C_FIELD(&sp40, s32 *, 4) = 0x10;
    sp94 = PvAllocSwClearImpl__Fi(&sp40);
    if (sp90 > 0) {
        do {
            temp_s0 = (s8 *)(sp94 + (var_s1_3 * 0x5C));
            var_s1_4 = 0;
            M2C_FIELD(temp_s0, s32 *, 0x40) = S16Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s0, s32 *, 0x48) = S16Read__18CBinaryInputStream(arg1);
            if (temp_v0_10 > 0) {
                do {
                    func_00118458(arg1, &sp50);
                    temp_s2_2 = S8Read__18CBinaryInputStream(arg1);
                    temp_f0 = F32Read__18CBinaryInputStream(arg1);
                    var_s1_4 += 1;
                    if (var_s1_4 == var_fp) {
                        s32 vu_17;
                        asm volatile("ldl %0, 0x57(%1)" : "=r"(vu_17) : "r"(sp));
                        s32 vu_18;
                        asm volatile("ldr %0, 0x50(%1)" : "=r"(vu_18) : "r"(sp), "0"(vu_17));
                        temp_v1_3 = vu_18;
                        s32 vu_19;
                        asm volatile("ldl %0, 0x5f(%1)" : "=r"(vu_19) : "r"(sp));
                        s32 vu_20;
                        asm volatile("ldr %0, 0x58(%1)" : "=r"(vu_20) : "r"(sp), "0"(vu_19));
                        temp_a0_4 = vu_20;
                        s32 vu_21;
                        asm volatile("ldl %0, 0x67(%1)" : "=r"(vu_21) : "r"(sp));
                        s32 vu_22;
                        asm volatile("ldr %0, 0x60(%1)" : "=r"(vu_22) : "r"(sp), "0"(vu_21));
                        temp_a1_3 = vu_22;
                        s32 vu_23;
                        asm volatile("ldl %0, 0x6f(%1)" : "=r"(vu_23) : "r"(sp));
                        s32 vu_24;
                        asm volatile("ldr %0, 0x68(%1)" : "=r"(vu_24) : "r"(sp), "0"(vu_23));
                        temp_v0_11 = vu_24;
                        asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_v1_3), "r"(temp_s0));
                        asm volatile("sdr %0, (%1)" : : "r"(temp_v1_3), "r"(temp_s0));
                        asm volatile("sdl %0, 0xf(%1)" : : "r"(temp_a0_4), "r"(temp_s0));
                        asm volatile("sdr %0, 0x8(%1)" : : "r"(temp_a0_4), "r"(temp_s0));
                        asm volatile("sdl %0, 0x17(%1)" : : "r"(temp_a1_3), "r"(temp_s0));
                        asm volatile("sdr %0, 0x10(%1)" : : "r"(temp_a1_3), "r"(temp_s0));
                        asm volatile("sdl %0, 0x1f(%1)" : : "r"(temp_v0_11), "r"(temp_s0));
                        asm volatile("sdr %0, 0x18(%1)" : : "r"(temp_v0_11), "r"(temp_s0));
                        s32 vu_25;
                        asm volatile("ldl %0, 0x77(%1)" : "=r"(vu_25) : "r"(sp));
                        s32 vu_26;
                        asm volatile("ldr %0, 0x70(%1)" : "=r"(vu_26) : "r"(sp), "0"(vu_25));
                        temp_v1_4 = vu_26;
                        s32 vu_27;
                        asm volatile("ldl %0, 0x7f(%1)" : "=r"(vu_27) : "r"(sp));
                        s32 vu_28;
                        asm volatile("ldr %0, 0x78(%1)" : "=r"(vu_28) : "r"(sp), "0"(vu_27));
                        temp_a0_5 = vu_28;
                        s32 vu_29;
                        asm volatile("ldl %0, 0x87(%1)" : "=r"(vu_29) : "r"(sp));
                        s32 vu_30;
                        asm volatile("ldr %0, 0x80(%1)" : "=r"(vu_30) : "r"(sp), "0"(vu_29));
                        temp_a1_4 = vu_30;
                        s32 vu_31;
                        asm volatile("ldl %0, 0x8f(%1)" : "=r"(vu_31) : "r"(sp));
                        s32 vu_32;
                        asm volatile("ldr %0, 0x88(%1)" : "=r"(vu_32) : "r"(sp), "0"(vu_31));
                        temp_v0_12 = vu_32;
                        asm volatile("sdl %0, 0x27(%1)" : : "r"(temp_v1_4), "r"(temp_s0));
                        asm volatile("sdr %0, 0x20(%1)" : : "r"(temp_v1_4), "r"(temp_s0));
                        asm volatile("sdl %0, 0x2f(%1)" : : "r"(temp_a0_5), "r"(temp_s0));
                        asm volatile("sdr %0, 0x28(%1)" : : "r"(temp_a0_5), "r"(temp_s0));
                        asm volatile("sdl %0, 0x37(%1)" : : "r"(temp_a1_4), "r"(temp_s0));
                        asm volatile("sdr %0, 0x30(%1)" : : "r"(temp_a1_4), "r"(temp_s0));
                        asm volatile("sdl %0, 0x3f(%1)" : : "r"(temp_v0_12), "r"(temp_s0));
                        asm volatile("sdr %0, 0x38(%1)" : : "r"(temp_v0_12), "r"(temp_s0));
                        M2C_FIELD(temp_s0, s32 *, 0x4C) = temp_s2_2;
                        M2C_FIELD(temp_s0, f32 *, 0x50) = temp_f0;
                    }
                } while (var_s1_4 < temp_v0_10);
            }
            var_s1_3 += 1;
            temp_v0_13 = S32Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s0, s32 *, 0x54) = temp_v0_13;
            sp40 = temp_v0_13 * 8;
            sp44 = 0x10;
            temp_v0_14 = PvAllocSwImpl__Fi(arg0, &sp40);
            M2C_FIELD(temp_s0, s32 **, 0x58) = temp_v0_14;
            CBinaryInputStream_Read_thunk(arg1, M2C_FIELD(temp_s0, s32 *, 0x54) * 8, temp_v0_14);
            M2C_FIELD(temp_s0, s8 **, 0x44) = (s8 *) M2C_FIELD(arg0, s8 **, 0xEC);
            M2C_FIELD(arg0, s8 **, 0xEC) = temp_s0;
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
}
