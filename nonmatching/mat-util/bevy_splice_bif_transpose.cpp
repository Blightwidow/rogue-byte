typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_bevy_splice_bif_transpose {};     /* size 0x0 */

void bevy_splice_bif_transpose(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 *var_v0;
    f32 *var_v1;
    f32 temp_f0;
    s32 var_t0;
    s32 var_t0_2;

    var_t0 = 0;
    if (arg1 > 0) {
        do {
            if (arg1 > 0) {
                var_v0 = (f32 *)((var_t0 * 4) + arg3);
                var_t0_2 = arg1;
                var_v1 = (f32 *)((var_t0 * arg0 * 4) + arg2);
                do {
                    temp_f0 = *var_v1;
                    var_t0_2 -= 1;
                    var_v1 += 1;
                    *var_v0 = temp_f0;
                    var_v0 += arg0 * 4;
                } while (var_t0_2 != 0);
            }
            var_t0 += 1;
        } while (var_t0 < arg1);
    }
}

}
