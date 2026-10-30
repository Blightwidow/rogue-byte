typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadGlobsetFromBrx {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x100];
    /* 0x110 */ s8 *sp110;                        /* inferred */
    /* 0x114 */ s32 sp114;                          /* inferred */
    /* 0x118 */ M2C_UNK *sp118;                     /* inferred */
    /* 0x11C */ char pad11C[0xB4];
};                                                  /* size = 0x1D0 */
void CBinaryInputStream_Read_thunk(s32, s32, M2C_UNK *);
void CBinaryInputStream_Skip(s32, s32);
f32 F32Read__18CBinaryInputStream(s32);
void LoadGlobFromBrx(s8 *, s8 *, s8 *, s8 *);
void LoadGlobIndexedFromBrx(s8 *, s8 *, s8 *, s8 *);
void LoadGlobSkinnedFromBrx(s8 *, s8 *, s8 *, s8 *);
void LoadGlobStreamedFromBrx(s8 *, s8 *, s8 *, s8 *);
void LoadGlobsetBndTreeFromBrx(s8 *, s32);
s32 PvAllocSwClearImpl__Fi(...);
void ReadVector__18CBinaryInputStreamP6VECTOR(s32, s8 *);
s32 S16Read__18CBinaryInputStream(s32);
s32 S32Read__18CBinaryInputStream(...);
s32 S8Read__18CBinaryInputStream(...);
s32 U16Read__18CBinaryInputStream(s32);
s32 U32Read__18CBinaryInputStream(s32);
s32 U8Read__18CBinaryInputStream(s32);
s32 func_0013FAD0(s32, M2C_UNK *);
s32 func_001ED7A8(M2C_UNK, s32);
s32 memset(s8 *, M2C_UNK, M2C_UNK);
void LoadGlobsetFromBrx(s8 *arg0, s8 *arg1, s32 arg2) {
    s8 sp[0x110] __attribute__((aligned(16)));
    M2C_UNK sp10;
    s8 *sp110;
    s32 sp114;
    M2C_UNK *sp118;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f0;
    f32 var_f0_2;
    s32 temp_fp;
    s32 temp_s1;
    s32 temp_t0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s7;
    s32 var_s7_2;
    s8 temp_v1_3;
    s8 temp_v1_6;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s1_2;
    s8 *temp_s3;
    s8 *temp_s5;
    s8 *var_s6;
    sp110 = arg1;
    var_s0 = 0;
    M2C_FIELD(arg0, s8 **, 0) = arg1;
    sp114 = S8Read__18CBinaryInputStream(arg0, arg1, arg2);
    ReadVector__18CBinaryInputStreamP6VECTOR(arg2, arg0 + 0x10);
    M2C_FIELD(arg0, f32 *, 0x20) = F32Read__18CBinaryInputStream(arg2);
    temp_v0 = U8Read__18CBinaryInputStream(arg2);
    M2C_FIELD(arg0, s32 *, 0x24) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0x28) = PvAllocSwClearImpl__Fi(sp, temp_v0 * 4, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0x24) > 0) {
        do {
            temp_v1 = var_s0 * 4;
            var_s0 += 1;
            *(s32 *)(temp_v1 + M2C_FIELD(arg0, s32 *, 0x28)) = func_001ED7A8(1, arg2);
        } while (var_s0 < M2C_FIELD(arg0, s32 *, 0x24));
    }
    var_s0_2 = 0;
    temp_v0_2 = U8Read__18CBinaryInputStream(arg2);
    M2C_FIELD(arg0, s32 *, 0x2C) = temp_v0_2;
    M2C_FIELD(arg0, s32 *, 0x30) = PvAllocSwClearImpl__Fi(sp, temp_v0_2 * 4, 0x10);
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    if (M2C_FIELD(arg0, s32 *, 0x2C) > 0) {
        do {
            temp_v1_2 = var_s0_2 * 4;
            var_s0_2 += 1;
            *(s32 *)(temp_v1_2 + M2C_FIELD(arg0, s32 *, 0x30)) = S32Read__18CBinaryInputStream(arg0, arg2);
        } while (var_s0_2 < M2C_FIELD(arg0, s32 *, 0x2C));
    }
    temp_v0_3 = S16Read__18CBinaryInputStream(arg2);
    M2C_FIELD(arg0, s32 *, 0x38) = temp_v0_3;
    M2C_FIELD(arg0, s32 *, 0x3C) = PvAllocSwClearImpl__Fi(sp, temp_v0_3 * 0x14, 0x10);
    M2C_FIELD(arg0, s32 *, 0x40) = PvAllocSwClearImpl__Fi(sp, 0x28, M2C_FIELD(arg0, s32 *, 0x38) * 0x28, 0x10);
    if (sp114 == 0) {
        M2C_FIELD(arg0, s32 *, 0x44) = PvAllocSwClearImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0x38) * 0x18, 0x10);
    }
    var_s7 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x38) > 0) {
        sp118 = &sp10;
        do {
            temp_t0 = M2C_FIELD(arg0, s32 *, 0x44);
            temp_s3 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x3C) + (var_s7 * 0x14));
            temp_s5 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x40) + (var_s7 * 0x28));
            if (temp_t0 != 0) {
                var_s6 = (s8 *)((var_s7 * 0x18) + temp_t0);
            } else {
                var_s6 = NULL;
            }
            memset(sp, 0, 0xC);
            temp_v0_4 = S8Read__18CBinaryInputStream(arg0, arg1, arg2);
            if ((temp_v0_4 != 0) && (CBinaryInputStream_Read_thunk(arg2, temp_v0_4 * 2, sp118), temp_s1 = S32Read__18CBinaryInputStream(arg0, arg2), (func_0013FAD0(temp_v0_4, sp118) == 0))) {
                CBinaryInputStream_Skip(arg2, temp_s1);
                var_s7_2 = var_s7 - 1;
                M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) - 1);
            } else {
                M2C_FIELD(temp_s3, s8 *, 3) = S8Read__18CBinaryInputStream(arg0, arg1, arg2);
                temp_fp = U16Read__18CBinaryInputStream(arg2);
                temp_s0 = M2C_FIELD(sp110, s8 **, 0xC);
                temp_s0_2 = temp_s0 + 0x198;
                temp_s1_2 = sp110 + M2C_FIELD(temp_s0, s16 *, 0x198);
                M2C_FIELD(temp_s5, s32 *, 4) = M2C_FIELD(temp_s0_2, s32 (**)(s8 *, s32), 4)(temp_s1_2, S16Read__18CBinaryInputStream(arg2));
                M2C_FIELD(temp_s3, s8 *, 0) = S8Read__18CBinaryInputStream(arg0, arg1, arg2);
                temp_f0 = F32Read__18CBinaryInputStream(arg2);
                var_f0 = 3.4028235e38f;
                if (temp_f0 != 3.4028235e38f) {
                    var_f0 = temp_f0 * fabsf(temp_f0);
                }
                M2C_FIELD(temp_s3, f32 *, 4) = var_f0;
                M2C_FIELD(temp_s5, s32 *, 0) = S32Read__18CBinaryInputStream(arg0, arg2, F32Read__18CBinaryInputStream(arg2));
                M2C_FIELD(temp_s5, s32 *, 0xC) = (s32) ((M2C_FIELD(temp_s5, s32 *, 0xC) & ~0x800) | ((S8Read__18CBinaryInputStream(arg0, arg1, arg2, S8Read__18CBinaryInputStream(arg0, arg1, arg2)) & 1) << 0xB));
                if (sp114 == 0) {
                    ReadVector__18CBinaryInputStreamP6VECTOR(arg2, var_s6);
                    M2C_FIELD(var_s6, f32 *, 0xC) = F32Read__18CBinaryInputStream(arg2);
                    M2C_FIELD(var_s6, s32 *, 0x14) = U32Read__18CBinaryInputStream(arg2);
                    temp_f0_2 = F32Read__18CBinaryInputStream(arg2);
                    M2C_FIELD(var_s6, f32 *, 0x10) = temp_f0_2;
                    if (temp_f0_2 == 3.4028235e38f) {
                        temp_v1_3 = M2C_FIELD(temp_s3, s8 *, 3);
                        switch (temp_v1_3) {        /* switch 1; irregular */
                        default:                    /* switch 1 */
                        case 0:                     /* switch 1 */
                            var_f0_2 = 1e10f;
block_27:
                            M2C_FIELD(var_s6, f32 *, 0x10) = var_f0_2;
                            break;
                        case 1:                     /* switch 1 */
                            var_f0_2 = 2000.0f;
                            goto block_27;
                        }
                    }
                }
                temp_v1_4 = (M2C_FIELD(temp_s5, s32 *, 0xC) & ~7) | (M2C_FIELD(temp_s3, s8 *, 3) & 7);
                M2C_FIELD(temp_s5, s32 *, 0xC) = temp_v1_4;
                temp_v1_5 = (temp_v1_4 & ~0xF8) | ((M2C_FIELD(temp_s3, s8 *, 0) & 0x1F) * 8);
                M2C_FIELD(temp_s5, s32 *, 0xC) = temp_v1_5;
                if (M2C_FIELD(temp_s3, f32 *, 4) != 3.4028235e38f) {
                    M2C_FIELD(temp_s5, s32 *, 0xC) = (s32) (temp_v1_5 | 0x400);
                }
                temp_v1_6 = M2C_FIELD(temp_s3, s8 *, 3);
                switch (temp_v1_6) {                /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    LoadGlobFromBrx(arg0, temp_s3, temp_s5, sp);
                    break;
                case 1:                             /* switch 2 */
                    LoadGlobSkinnedFromBrx(arg0, temp_s3, temp_s5, sp);
                    break;
                case 2:                             /* switch 2 */
                    LoadGlobStreamedFromBrx(arg0, temp_s3, temp_s5, sp);
                    break;
                case 3:                             /* switch 2 */
                    LoadGlobIndexedFromBrx(arg0, temp_s3, temp_s5, sp);
                    break;
                }
                var_s7_2 = var_s7 + temp_fp;
            }
            var_s7 = var_s7_2 + 1;
        } while (var_s7 < M2C_FIELD(arg0, s32 *, 0x38));
    }
    LoadGlobsetBndTreeFromBrx(arg0, arg2);
}
}
