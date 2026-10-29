typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PostBtnLoad {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */

M2C_UNK PostAshLoad(s32, s32);                      /* extern */

void PostBtnLoad(s32 *arg0) {
    s32 temp_a0;
    s32 var_s0;
    u32 var_s2;

    var_s0 = (s32)(arg0 + 4);
    var_s2 = 0;
loop_1:
    temp_a0 = var_s0;
    var_s2 += 1;
    var_s0 += 0x44;
    PostAshLoad(temp_a0, *arg0);
    if (var_s2 < 2U) {
        goto loop_1;
    }
}

}
