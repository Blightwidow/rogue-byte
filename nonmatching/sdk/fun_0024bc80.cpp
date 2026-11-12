typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0024BC80 {
    /* 0x000 */ char pad0[0x190];
};                                                  /* size = 0x190 */
s64 __muldi3(s64, s64);                             /* extern */
M2C_UNK func_00236918(s8 *, M2C_UNK, M2C_UNK *, s32, s32); /* extern */
M2C_UNK func_0024B9F0(s8 *, s8 *);              /* extern */
M2C_UNK func_0024C670(s8 *, s8 *);              /* extern */
M2C_UNK func_0024FA38(s8 *, s8 *);              /* extern */
extern M2C_UNK D_002C8398;
extern M2C_UNK RO_002AC438;
void func_0024BC80(s8 *arg0, s8 *arg1) {
    s8 sp[0x100] __attribute__((aligned(16)));
    s32 temp_a1_2;
    s32 temp_s1;
    s32 var_s0;
    s32 var_v0;
    s64 *temp_s5;
    s64 *temp_s6;
    s64 *temp_s7;
    s64 temp_a0;
    s64 temp_a1;
    s64 temp_s0;
    s64 temp_v0;
    s8 *var_s4;
    var_s4 = M2C_FIELD(arg0, s8 **, 0x868);
    temp_s5 = (s64 *)(var_s4 + 0x10);
    temp_s6 = (s64 *)(var_s4 + 0x18);
    temp_s7 = (s64 *)(var_s4 + 0x20);
    if (M2C_FIELD(arg0, s32 *, 0x8C) != 0) {
        if ((M2C_FIELD(arg1, s64 *, 0x18) < 0) && (M2C_FIELD(arg0, s32 *, 0x98) >= 0)) {
            temp_a1 = (s64) (M2C_FIELD(arg0, s64 *, 0xA0) << 0x20) >> 0x20;
            temp_a0 = M2C_FIELD(arg0, s64 *, 0x90);
            temp_s1 = temp_a1 & 1;
            temp_s0 = (s64) ((temp_s1 & (M2C_FIELD(arg0, s32 *, 0x9C) & 1) & (temp_a0 & 1)) << 0x20) >> 0x20;
            M2C_FIELD(var_s4, s64 *, 0x10) = (s64) (M2C_FIELD(arg0, s32 *, 0x98) + (((s64) (__muldi3(temp_a0, temp_a1) << 0x1F) >> 0x20) + temp_s0));
            var_s4 = M2C_FIELD(arg0, s8 **, 0x868);
            if (temp_s1 & M2C_FIELD(arg0, s64 *, 0x90)) {
                M2C_FIELD(arg0, s32 *, 0x9C) = (s32) (M2C_FIELD(arg0, s32 *, 0x9C) + 1);
            }
        } else {
            goto block_6;
        }
    } else {
block_6:
        M2C_FIELD(var_s4, s64 *, 0x10) = M2C_FIELD(arg1, s64 *, 0x18);
    }
    if (M2C_FIELD(arg0, s32 *, 0x108) == 2) {
        temp_v0 = M2C_FIELD(arg0, s64 *, 0x100);
        if (temp_v0 >= 0) {
            *temp_s5 = temp_v0;
            M2C_FIELD(arg0, s32 *, 0x108) = 0;
            M2C_FIELD(arg0, s64 *, 0x100) = -1;
        }
    }
    *temp_s6 = M2C_FIELD(arg1, s64 *, 0x20);
    *temp_s7 = ((s64) M2C_FIELD(arg1, s32 *, 0x34) << 8) | M2C_FIELD(arg1, s32 *, 0x2C) | (((s64) M2C_FIELD(arg1, s32 *, 0x40) << 5) | ((s64) M2C_FIELD(arg1, s32 *, 0x3C) << 6)) | (((s64) M2C_FIELD(arg1, s32 *, 0x38) << 7) | ((s64) M2C_FIELD(arg1, s32 *, 0x30) * 8));
    temp_a1_2 = M2C_FIELD(arg0, s32 *, 0xF4);
    M2C_FIELD(arg0, s32 *, 0x98) = (s32) M2C_FIELD(var_s4, s32 *, 0x10);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) M2C_FIELD(arg1, s32 *, 0x5C);
    M2C_FIELD(arg0, s64 *, 0xA0) = (s64) *(((((s64) (M2C_FIELD(var_s4, s64 *, 0x20) << 0x1B) >> 0x20) & 0xF) * 4) + &D_002C8398);
    M2C_FIELD(arg0, s32 *, 0xE4) = (s32) M2C_FIELD(arg1, s32 *, 0x60);
    M2C_FIELD(arg0, s32 *, 0xC8) = (s32) M2C_FIELD(arg1, s32 *, 0x44);
    M2C_FIELD(arg0, s32 *, 0xCC) = (s32) M2C_FIELD(arg1, s32 *, 0x48);
    M2C_FIELD(arg0, s32 *, 0xD0) = (s32) M2C_FIELD(arg1, s32 *, 0x4C);
    M2C_FIELD(arg0, s32 *, 0xD4) = (s32) M2C_FIELD(arg1, s32 *, 0x50);
    M2C_FIELD(arg0, s32 *, 0xD8) = (s32) M2C_FIELD(arg1, s32 *, 0x54);
    M2C_FIELD(arg0, s32 *, 0xDC) = (s32) M2C_FIELD(arg1, s32 *, 0x58);
    if (temp_a1_2 != 0) {
        var_s0 = 0;
        if (M2C_FIELD(arg0, s32 *, 0xF0) >= M2C_FIELD(arg1, s32 *, 4)) {
            var_v0 = temp_a1_2 < M2C_FIELD(arg1, s32 *, 8);
            goto block_14;
        }
    } else {
        var_v0 = M2C_FIELD(arg0, s32 *, 0xF8) < (M2C_FIELD(arg1, s32 *, 0xC) * M2C_FIELD(arg1, s32 *, 0x10));
block_14:
        var_s0 = var_v0 ^ 1;
    }
    if (((var_s0 != 0) || (func_00236918(sp, 0x100, &RO_002AC438, M2C_FIELD(arg1, s32 *, 4), M2C_FIELD(arg1, s32 *, 8)), func_0024FA38(arg0, sp), (var_s0 != 0))) && (M2C_FIELD(arg1, s32 *, 0x28) == 1)) {
        if (M2C_FIELD(arg0, s32 *, 0xC4) != 0) {
            func_0024C670(arg0, arg1);
        } else {
            func_0024B9F0(arg0, arg1);
        }
        if (M2C_FIELD(arg0, s32 *, 8) != 2) {
            M2C_FIELD(arg0, s32 *, 8) = 2;
            M2C_FIELD(arg0, s32 *, 0xC0) = (s32) M2C_FIELD(arg0, s32 *, 0x128);
        }
        M2C_FIELD(arg0, s32 *, 0x834) = 1;
    }
}
}
