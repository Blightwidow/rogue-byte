typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Decompress__18CBinaryInputStream {
    /* 0x00 */ char pad0[0x90];
};                                                  /* size = 0x90 */
M2C_UNK memcpy(s32, s32, s32);                      /* extern */
void Decompress__18CBinaryInputStream(s8 *arg0) {
    s32 temp_a2;
    s32 temp_s3;
    s32 temp_s5;
    s32 temp_v0_2;
    s32 temp_v0_5;
    s32 temp_v0_8;
    s32 var_a1;
    s32 var_a2;
    s32 var_s1;
    s32 var_s4;
    s32 var_s6;
    u8 *temp_a0;
    u8 *temp_v0_9;
    u8 *var_s2;
    u8 temp_s3_2;
    u8 temp_v0_3;
    u8 temp_v0_7;
    s8 *temp_v0;
    s8 *temp_v0_4;
    s8 *temp_v0_6;
    var_s4 = 0;
    temp_a2 = M2C_FIELD(arg0, s32 *, 0x1C);
    temp_s5 = M2C_FIELD(arg0, s32 *, 0x24);
    var_s1 = M2C_FIELD(arg0, s32 *, 0x14);
    var_s2 = M2C_FIELD(arg0, u8 **, 0x10);
    var_s6 = M2C_FIELD(arg0, s32 *, 0x18);
    if (temp_a2 > 0) {
        memcpy(temp_s5, temp_s5 + 0x2000, temp_a2);
        var_s4 = M2C_FIELD(arg0, s32 *, 0x1C);
    }
loop_14:
    temp_s3 = var_s4 < 0x2000;
    if (temp_s3 != 0) {
        var_s6 = var_s6 >> 1;
        var_s1 -= 1;
        if (!(var_s6 & 0x100)) {
            if (var_s1 < 0) {
                temp_v0 = M2C_FIELD(arg0, s8 **, 0x30);
                M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8));
                temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x14);
                if (temp_v0_2 > 0) {
                    var_s2 = M2C_FIELD(arg0, u8 **, 0x10);
                    var_s1 = temp_v0_2 - 1;
                    goto block_4;
                }
            } else {
block_4:
                temp_v0_3 = *var_s2;
                var_s2 += 1;
                var_s6 = temp_v0_3 + 0xFF00;
                var_s1 -= 1;
                goto block_5;
            }
        } else {
block_5:
            if (var_s1 < 0) {
                temp_v0_4 = M2C_FIELD(arg0, s8 **, 0x30);
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *), 0xC)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 8));
                temp_v0_5 = M2C_FIELD(arg0, s32 *, 0x14);
                if (temp_v0_5 > 0) {
                    var_s2 = M2C_FIELD(arg0, u8 **, 0x10);
                    var_s1 = temp_v0_5 - 1;
                    goto block_8;
                }
            } else {
block_8:
                temp_s3_2 = *var_s2;
                var_s2 += 1;
                if (var_s6 & 1) {
                    *(s32 *)(temp_s5 + var_s4) = temp_s3_2;
                    var_s4 += 1;
                } else {
                    var_s1 -= 1;
                    if (var_s1 < 0) {
                        temp_v0_6 = M2C_FIELD(arg0, s8 **, 0x30);
                        M2C_FIELD(temp_v0_6, M2C_UNK (**)(s8 *), 0xC)(arg0 + M2C_FIELD(temp_v0_6, s16 *, 8));
                        var_s2 = M2C_FIELD(arg0, u8 **, 0x10);
                        var_s1 = M2C_FIELD(arg0, s32 *, 0x14) - 1;
                    }
                    temp_v0_7 = *var_s2;
                    var_s2 += 1;
                    temp_v0_8 = temp_s3_2 + (temp_v0_7 << 8);
                    var_a1 = (temp_v0_8 >> 0xD) + 2;
                    var_a2 = temp_v0_8 & 0x1FFF;
                    if (var_a1 >= 0) {
                        do {
                            temp_a0 = (u8 *)(temp_s5 + var_s4);
                            temp_v0_9 = (u8 *)(temp_s5 + (var_a2 & 0x1FFF));
                            var_a2 += 1;
                            var_s4 += 1;
                            var_a1 -= 1;
                            *temp_a0 = *temp_v0_9;
                        } while (var_a1 >= 0);
                    }
                }
                goto loop_14;
            }
        }
    }
    M2C_FIELD(arg0, s32 *, 4) = temp_s5;
    if (temp_s3 == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0x2000;
        M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (var_s4 - 0x2000);
    } else {
        M2C_FIELD(arg0, s32 *, 8) = var_s4;
        M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x18) = var_s6;
    M2C_FIELD(arg0, u8 **, 0x10) = var_s2;
    M2C_FIELD(arg0, s32 *, 0x14) = var_s1;
}
}
