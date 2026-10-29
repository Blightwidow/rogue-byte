typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ResolveSlotSoAsegs {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */

s32 func_001B1B98(s32, s32);                        /* extern */

void ResolveSlotSoAsegs(s32 arg0) {
    s32 temp_a1;
    s32 var_s1;
    s8 *var_s0;

    var_s0 = (s8 *)(arg0 + 0x17C);
    var_s1 = 5;
    do {
        temp_a1 = M2C_FIELD(var_s0, s32 *, 0);
        if (temp_a1 != -1) {
            M2C_FIELD(var_s0, s32 *, 4) = func_001B1B98(arg0, temp_a1);
            M2C_FIELD(var_s0, s32 *, 0) = -1;
        }
        var_s1 -= 1;
        var_s0 += 0xC;
    } while (var_s1 >= 0);
}

}
