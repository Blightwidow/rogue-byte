typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PumpCd__18CBinaryInputStream {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
M2C_UNK ReadCdDirect__FUiUiPv(s32, s32, s32, M2C_UNK); /* extern */
s32 sceCdGetError();                                /* extern */
s32 sceCdGetReadPos();                              /* extern */
s32 sceCdSync(M2C_UNK, s32);                        /* extern */
void PumpCd__18CBinaryInputStream(s8 *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a3;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_lo;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a3;
    s32 var_v0;
    temp_lo = (s32) M2C_FIELD(arg0, s32 *, 0x34) / (s32) M2C_FIELD(arg0, s32 *, 0x54);
    temp_a1 = M2C_FIELD(arg0, s32 *, 0x14);
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + temp_a1);
    var_v0 = -0x800;
    if (temp_lo > 0x8000) {
        var_v0 = -0x8000;
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x58);
    temp_s1 = temp_lo & var_v0;
    if (temp_a0 > 0) {
        temp_a2 = M2C_FIELD(arg0, s32 *, 0x38);
        temp_a1_2 = M2C_FIELD(arg0, s32 *, 0x5C) + 1;
        if (M2C_FIELD(arg0, s32 *, 0x10) == (temp_a2 + (temp_a1_2 * temp_s1))) {
            temp_hi = temp_a1_2 % (s32) M2C_FIELD(arg0, s32 *, 0x54);
            M2C_FIELD(arg0, s32 *, 0x58) = (s32) (temp_a0 - 1);
            M2C_FIELD(arg0, s32 *, 0x5C) = temp_hi;
            M2C_FIELD(arg0, s32 *, 0x10) = (s32) ((temp_hi * temp_s1) + temp_a2);
        }
    }
loop_9:
    if (M2C_FIELD(arg0, s32 *, 0x44) > 0) {
        temp_a1_3 = M2C_FIELD(arg0, s32 *, 0x44);
        temp_v0 = sceCdGetReadPos() + M2C_FIELD(arg0, s32 *, 0x4C);
        temp_v0_2 = (temp_v0 >= temp_a1_3) ? temp_a1_3 : temp_v0;
        if (M2C_FIELD(arg0, s32 *, 0x40) < temp_v0_2) {
            M2C_FIELD(arg0, s32 *, 0x40) = temp_v0_2;
        } else if (sceCdSync(1, temp_a1_3) == 0) {
            if (sceCdGetError() != 0) {
                temp_v1 = M2C_FIELD(arg0, s32 *, 0x40);
                M2C_FIELD(arg0, s32 *, 0x4C) = temp_v1;
                ReadCdDirect__FUiUiPv(M2C_FIELD(arg0, s32 *, 0x50) + ((s32) ((temp_v1 > -1) ? temp_v1 : (temp_v1 + 0x7FF)) >> 0xB), (s32) (((M2C_FIELD(arg0, s32 *, 0x44) - temp_v1) + 0x7FF) & ~0x7FF) >> 0xB, M2C_FIELD(arg0, s32 *, 0x38) + (M2C_FIELD(arg0, s32 *, 0x60) * temp_s1) + temp_v1, 0);
            } else {
                temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x44);
                M2C_FIELD(arg0, s32 *, 0x40) = temp_a0_2;
                M2C_FIELD(arg0, s32 *, 0x50) = (s32) (M2C_FIELD(arg0, s32 *, 0x50) + ((s32) ((temp_a0_2 > -1) ? temp_a0_2 : (temp_a0_2 + 0x7FF)) >> 0xB));
                M2C_FIELD(arg0, s32 *, 0x48) = (s32) (M2C_FIELD(arg0, s32 *, 0x48) - temp_a0_2);
                M2C_FIELD(arg0, s32 *, 0x44) = 0;
                M2C_FIELD(arg0, s32 *, 0x4C) = 0;
            }
        }
    }
    temp_a3 = M2C_FIELD(arg0, s32 *, 0x58);
    temp_a2_2 = M2C_FIELD(arg0, s32 *, 0x54);
    if ((temp_a3 < temp_a2_2) && (M2C_FIELD(arg0, s32 *, 0x44) == 0)) {
        temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x48);
        if (temp_a0_3 > 0) {
            M2C_FIELD(arg0, s32 *, 0x40) = 0;
            temp_a1_4 = (temp_a0_3 >= temp_s1) ? temp_s1 : temp_a0_3;
            temp_hi_2 = (s32) (M2C_FIELD(arg0, s32 *, 0x60) + 1) % temp_a2_2;
            M2C_FIELD(arg0, s32 *, 0x44) = temp_a1_4;
            M2C_FIELD(arg0, s32 *, 0x58) = (s32) (temp_a3 + 1);
            M2C_FIELD(arg0, s32 *, 0x60) = temp_hi_2;
            ReadCdDirect__FUiUiPv(M2C_FIELD(arg0, s32 *, 0x50), (s32) ((temp_a1_4 + 0x7FF) & ~0x7FF) >> 0xB, M2C_FIELD(arg0, s32 *, 0x38) + (temp_hi_2 * temp_s1), 0);
        }
    }
    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x58);
    if (temp_v0_3 == 0) {
        M2C_FIELD(arg0, s32 *, 0x14) = 0;
    } else {
        var_a3 = temp_s1;
        if (temp_v0_3 == 1) {
            var_a3 = M2C_FIELD(arg0, s32 *, 0x40);
        }
        temp_v0_4 = var_a3 - (M2C_FIELD(arg0, s32 *, 0x10) - (M2C_FIELD(arg0, s32 *, 0x38) + (M2C_FIELD(arg0, s32 *, 0x5C) * temp_s1)));
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) ((temp_v0_4 <= 0xFFF) ? temp_v0_4 : 0x1000);
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) == 0) {
        if (M2C_FIELD(arg0, s32 *, 0x48) > 0) {
            goto loop_9;
        }
    }
}
}
