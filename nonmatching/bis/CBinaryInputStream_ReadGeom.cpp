typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CBinaryInputStream_ReadGeom {
    /* 0x00 */ s32 sp0;                             /* inferred */
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ s32 sp8;                             /* inferred */
    /* 0x0C */ char padC[0xA4];
};                                                  /* size = 0xB0 */
void BuildPlane(s8 *, s128, s128, s128, s128 *);
f32 F32Read__18CBinaryInputStream(s32);
s32 *PvAllocSwClearImpl__Fi(s8 *);
s32 PvAllocSwImpl__Fi(s8 *);
void ReadVector__18CBinaryInputStreamP6VECTOR(s32, s32);
s32 U16Read__18CBinaryInputStream(...);
s32 U8Read__18CBinaryInputStream(s32);
void CBinaryInputStream_ReadGeom(s32 arg0, s8 *arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp0;
    s32 sp4;
    s32 sp8;
    s128 *temp_a4;
    s16 var_s6;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s8 *temp_s0;
    s8 *temp_s5;
    s8 *temp_v0_4;
    s8 *temp_v1_3;
    s8 *var_s7;
    var_s0 = 0;
    temp_v0 = U16Read__18CBinaryInputStream();
    temp_a0 = temp_v0 * 0x10;
    sp4 = 0x10;
    sp0 = temp_a0;
    M2C_FIELD(arg1, s32 *, 0) = temp_v0;
    M2C_FIELD(arg1, s32 *, 4) = PvAllocSwImpl__Fi(sp);
    if (M2C_FIELD(arg1, s32 *, 0) > 0) {
        do {
            temp_a1 = var_s0 * 0x10;
            var_s0 += 1;
            ReadVector__18CBinaryInputStreamP6VECTOR(arg0, M2C_FIELD(arg1, s32 *, 4) + temp_a1);
        } while (var_s0 < M2C_FIELD(arg1, s32 *, 0));
    }
    temp_v0_2 = U16Read__18CBinaryInputStream(arg0);
    var_s6 = 0;
    temp_v1 = temp_v0_2 << 5;
    sp4 = 0x10;
    sp0 = temp_v1;
    M2C_FIELD(arg1, s32 *, 8) = temp_v0_2;
    M2C_FIELD(arg1, s8 **, 0xC) = (s8 *)(PvAllocSwClearImpl__Fi(sp));
    temp_v0_3 = U16Read__18CBinaryInputStream(arg0);
    sp4 = 0x10;
    M2C_FIELD(arg1, s32 *, 0x10) = temp_v0_3;
    sp0 = temp_v0_3 * 0x10;
    temp_v0_4 = (s8 *)(PvAllocSwClearImpl__Fi(sp));
    var_s7 = temp_v0_4;
    M2C_FIELD(arg1, s8 **, 0x14) = temp_v0_4;
    if (M2C_FIELD(arg1, s32 *, 8) > 0) {
loop_4:
        temp_s5 = M2C_FIELD(arg1, s8 **, 0xC) + (var_s6 << 5);
        var_s0_2 = 3;
        temp_v0_5 = U16Read__18CBinaryInputStream(arg0);
        sp0 = temp_v0_5;
        sp4 = U16Read__18CBinaryInputStream(arg0);
        temp_v0_6 = U16Read__18CBinaryInputStream(arg0);
        temp_v1_2 = M2C_FIELD(arg1, s32 *, 4);
        sp8 = temp_v0_6;
        temp_a4 = (s128 *)((temp_v0_6 * 0x10) + temp_v1_2);
        BuildPlane(temp_s5, *(s32 *)((sp0 * 0x10) + temp_v1_2), *(s32 *)((sp4 * 0x10) + temp_v1_2), *temp_a4, temp_a4);
        M2C_FIELD(temp_s5, s32 *, 0x1C) = temp_v0_5;
        do {
            var_s0_2 -= 1;
            F32Read__18CBinaryInputStream(arg0);
        } while (var_s0_2 >= 0);
        var_s1 = 0;
        temp_v0_7 = U8Read__18CBinaryInputStream(arg0);
        if (temp_v0_7 > 0) {
            do {
                temp_s0 = var_s7;
                var_s7 = temp_s0 + 0x10;
                M2C_FIELD(temp_s0, s16 *, 0) = U16Read__18CBinaryInputStream(arg0);
                temp_v0_8 = U16Read__18CBinaryInputStream(arg0);
                M2C_FIELD(temp_s0, s16 *, 4) = var_s6;
                M2C_FIELD(temp_s0, s16 *, 2) = (s16) temp_v0_8;
                M2C_FIELD(temp_s0, u16 *, 6) = U16Read__18CBinaryInputStream(arg0);
                if (var_s1 == 0) {
                    M2C_FIELD(temp_s5, s8 **, 0x10) = temp_s0;
                } else {
                    M2C_FIELD(temp_s0, s8 **, -8) = temp_s0;
                }
                var_s1 += 1;
                temp_v1_3 = M2C_FIELD(arg1, s8 **, 0xC) + (M2C_FIELD(temp_s0, u16 *, 6) << 5);
                M2C_FIELD(temp_s0, s8 **, 0xC) = (s8 *) M2C_FIELD(temp_v1_3, s8 **, 0x14);
                M2C_FIELD(temp_v1_3, s8 **, 0x14) = temp_s0;
            } while (var_s1 < temp_v0_7);
        }
        var_s6 += 1;
        if (var_s6 < M2C_FIELD(arg1, s32 *, 8)) {
            goto loop_4;
        }
    }
}
}
