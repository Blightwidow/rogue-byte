typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitCloneSets {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0xBC];
};                                                  /* size = 0xD0 */
s32 MakeCloneId(s32, s32);                          /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(s8 *, s128); /* extern */
s8 *PmatLoWorld(s32);                             /* extern */
s128 PosLoWorld(s32, s32, s32);                     /* extern */
s32 PvAllocSwClearImpl__Fi(...); /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
void InitCloneSets(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    s128 temp_a1_2;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_s0_2;
    s32 temp_s1_2;
    s32 temp_s5;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_s0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_v0;
    s8 *temp_s0;
    s8 *temp_s0_3;
    s8 *temp_s0_4;
    s8 *temp_s1;
    s8 *temp_s4;
    s8 *temp_v0;
    s8 *temp_v0_3;
    var_s0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x3F04) > 0) {
        do {
            sp10 = var_s0 + 1;
            temp_s4 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x3F08) + (var_s0 * 0x6C));
            temp_a1 = M2C_FIELD(temp_s4, s32 *, 0xC);
            if (temp_a1 < M2C_FIELD(temp_s4, s32 *, 8)) {
                var_s2 = temp_a1;
                do {
                    var_s3 = 0;
                    temp_s5 = MakeCloneId(var_s0, var_s2);
                    *(s32 *)((var_s2 * 4) + M2C_FIELD(temp_s4, s32 *, 0x18)) = M2C_FIELD(temp_s4, s32 *, 0x14);
                    temp_v1 = M2C_FIELD(temp_s4, s32 *, 0);
                    if (temp_v1 > 0) {
                        var_v0 = var_s2 * temp_v1;
                        do {
                            temp_v1_3 = (var_v0 + var_s3) * 4;
                            var_s3 += 1;
                            temp_s1 = (s8 *)(*(s32 *)(temp_v1_3 + M2C_FIELD(temp_s4, s32 *, 4)));
                            temp_v0 = M2C_FIELD(temp_s1, s8 **, 0xC);
                            M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s32, M2C_UNK), 0xCC)(temp_s1 + M2C_FIELD(temp_v0, s16 *, 0xC8), temp_s5, 1);
                            M2C_FIELD(M2C_FIELD(temp_s1, s8 **, 0x3C), s32 *, 0x24) = 1;
                            temp_v1_2 = M2C_FIELD(temp_s4, s32 *, 0);
                            var_v0 = var_s2 * temp_v1_2;
                        } while (var_s3 < temp_v1_2);
                    }
                    var_s2 += 1;
                } while (var_s2 < M2C_FIELD(temp_s4, s32 *, 8));
                var_s3_2 = 0;
                M2C_FIELD(temp_s4, s32 *, 0x64) = PvAllocSwClearImpl__Fi(sp, M2C_FIELD(temp_s4, s32 *, 0) << 6, 0x10);
                if (M2C_FIELD(temp_s4, s32 *, 0) > 0) {
                    do {
                        temp_a2 = M2C_FIELD(temp_s4, s32 *, 0xC) * M2C_FIELD(temp_s4, s32 *, 0);
                        temp_s0 = (s8 *)(M2C_FIELD(temp_s4, s32 *, 0x64) + (var_s3_2 << 6));
                        temp_v0_2 = (temp_a2 + var_s3_2) * 4;
                        var_s3_2 += 1;
                        temp_s1_2 = *(s32 *)(temp_v0_2 + M2C_FIELD(temp_s4, s32 *, 4));
                        M2C_FIELD(temp_s0, s128 *, 0) = PosLoWorld(temp_s1_2, M2C_FIELD(temp_s4, s32 *, 0), temp_a2);
                        temp_v0_3 = PmatLoWorld(temp_s1_2);
                        M2C_FIELD(temp_s0, s128 *, 0x10) = (s128) M2C_FIELD(temp_v0_3, s128 *, 0);
                        temp_a1_2 = M2C_FIELD(temp_v0_3, s128 *, 0x10);
                        M2C_FIELD(temp_s0, s128 *, 0x20) = temp_a1_2;
                        M2C_FIELD(temp_s0, s128 *, 0x30) = (s128) M2C_FIELD(temp_v0_3, s128 *, 0x20);
                        NormalizeRotateMatrix3__FP7MATRIX3(temp_s0 + 0x10, temp_a1_2);
                    } while (var_s3_2 < M2C_FIELD(temp_s4, s32 *, 0));
                }
                var_s2_2 = M2C_FIELD(temp_s4, s32 *, 0xC);
                M2C_FIELD(temp_s4, s32 *, 0x68) = PvAllocSwClearImpl__Fi(sp, 0x50, 0x10, (M2C_FIELD(temp_s4, s32 *, 8) - M2C_FIELD(temp_s4, s32 *, 0xC)) * 0x50, 0x10);
                if (var_s2_2 < M2C_FIELD(temp_s4, s32 *, 8)) {
                    do {
                        temp_s0_2 = (var_s2_2 - M2C_FIELD(temp_s4, s32 *, 0xC)) * 0x50;
                        var_s2_2 += 1;
                        temp_s0_3 = (s8 *)(temp_s0_2 + M2C_FIELD(temp_s4, s32 *, 0x68));
                        temp_s0_4 = temp_s0_3 + 0x10;
                        memset(temp_s0_4, 0, 0x40);
                        M2C_FIELD(temp_s0_3, f32 *, 0x10) = 1.0f;
                        M2C_FIELD(temp_s0_4, f32 *, 0x3C) = 1.0f;
                        M2C_FIELD(temp_s0_4, f32 *, 0x28) = 1.0f;
                        M2C_FIELD(temp_s0_4, f32 *, 0x14) = 1.0f;
                    } while (var_s2_2 < M2C_FIELD(temp_s4, s32 *, 8));
                }
            }
            var_s0 = sp10;
        } while (var_s0 < M2C_FIELD(arg0, s32 *, 0x3F04));
    }
}
}
