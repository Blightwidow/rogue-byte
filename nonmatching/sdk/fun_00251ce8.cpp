typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00251CE8 {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
void func_0024FA90(s8 *, M2C_UNK *, s16);
s32 func_00251FC8(s8 *);
s32 func_00252230(s8 *, M2C_UNK, s64);
void func_00252358(s8 *);
void func_00252390(s8 *, M2C_UNK);
extern M2C_UNK RO_002AC640;
s32 func_00251CE8(s8 *arg0) {
    s16 temp_v0;
    s32 temp_v1;
    s32 var_s2;
    s32 var_v0;
    s64 temp_a0;
    s64 temp_a2;
    var_s2 = 0;
loop_1:
    func_00252358(arg0);
    *(s32 *)0x10002000 = 0x30000000;
    M2C_FIELD(arg0, s32 *, 0x82C) = 0x30000000;
    M2C_FIELD(arg0, s32 *, 0x828) = 0;
    temp_a2 = func_00251FC8(arg0);
    temp_a0 = *(s64 *)0x10002030;
    M2C_FIELD(arg0, s32 *, 0x848) = (s32) ((s64) (temp_a0 << 0x20) >> 0x20);
    if (temp_a0 < 0) {
        M2C_FIELD(arg0, s32 *, 0x84C) = (s32) ((0x20 - (*(s32 *)0x10002020 & 0x1F)) & 0x1F);
    } else {
        M2C_FIELD(arg0, s32 *, 0x84C) = 0x20;
    }
    temp_v0 = temp_a2 & 0xFFFF;
    M2C_FIELD(arg0, s32 *, 0x12C) = (s32) (((s64) (temp_a2 << 0x20) >> 0x20) == 0);
    if (temp_v0 != 0x22) {
        if ((u32) temp_v0 < 0x23U) {
            if (temp_v0 != 0) {
                var_s2 += temp_v0;
                goto block_18;
            }
            temp_v1 = func_00252230(arg0, 0xB, temp_a2);
            if (M2C_FIELD(arg0, s32 *, 0x858) != 0) {
                if (temp_v1 == 0xF) {
                    func_00252390(arg0, 0xB);
                    goto block_15;
                }
                goto block_17;
            }
block_17:
            func_0024FA90(arg0, &RO_002AC640, temp_v0);
            M2C_FIELD(arg0, s32 *, 0x12C) = 1;
            return 1;
        }
        if (temp_v0 != 0x23) {
            var_s2 += temp_v0;
block_18:
            var_v0 = 0;
        } else {
            var_v0 = 1;
            var_s2 += 0x21;
        }
        goto block_19;
    }
block_15:
    var_v0 = 1;
block_19:
    if (var_v0 == 0) {
        return var_s2;
    }
    goto loop_1;
}
}
