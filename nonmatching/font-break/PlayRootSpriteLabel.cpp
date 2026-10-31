typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PlayRootSpriteLabel {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK PlayRootSpriteLabelIndex(s8 *, s32, s32);    /* extern */
void PlayRootSpriteLabel(s8 *arg0, s32 arg1, u16 arg3) {
    s32 *var_v1;
    s32 var_a1;
    u16 temp_v0;
    u16 var_a3;
    s8 *temp_v1;
    var_a3 = arg3;
    if (M2C_FIELD(arg0, s32 *, 0x28) != 0) {
        var_a1 = 0;
        if (arg1 != 0x314) {
            temp_v0 = M2C_FIELD(arg0, u16 *, 0);
            if (temp_v0 != 0) {
                temp_v1 = M2C_FIELD(arg0, s8 **, 4);
                var_v1 = (s32 *)(temp_v1 + 0x14);
                if (arg1 != M2C_FIELD(temp_v1, s32 *, 0x14)) {
                    var_a3 = temp_v0;
                    var_a1 = 1;
loop_5:
                    var_v1 += 0x18;
                    if (var_a1 < (s32) var_a3) {
                        if (arg1 != *var_v1) {
                            var_a1 += 1;
                            goto loop_5;
                        }
                    }
                }
            }
            var_a1 = (var_a1 >= (s32) temp_v0) ? 0 : var_a1;
        }
        PlayRootSpriteLabelIndex(arg0, var_a1, arg1);
    }
}
}
