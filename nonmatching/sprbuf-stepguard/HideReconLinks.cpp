typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_HideReconLinks {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */

void HideReconLinks(s8 *arg0) {
    s32 var_s1;
    s8 **var_s0;
    s8 *temp_a1;
    s8 *temp_v0;

    var_s1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x30) > 0) {
        var_s0 = (s8 **)(arg0 + 0x34);
        do {
            temp_a1 = M2C_FIELD(*var_s0, s8 **, 0x100);
            if (temp_a1 != NULL) {
                temp_v0 = M2C_FIELD(temp_a1, s8 **, 0xC);
                M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x48), temp_a1);
            }
            var_s1 += 1;
            var_s0 += 4;
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 0x30));
    }
}

}
