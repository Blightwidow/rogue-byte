typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00244110 {};                 /* size 0x0 */
M2C_UNK iSignalSema(s32, s32);          /* extern */
void func_00244110(s32 arg0, s32 arg2, s32 arg3) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    u8 temp_v1;
    u8 temp_v1_3;
    var_a3 = arg3;
    var_a2 = arg2;
    temp_a0 = arg0 | 0x20000000;
    temp_v0 = M2C_FIELD(temp_a0, s32 *, 0);
    var_a1 = 0;
    if ((temp_v0 != 0) && (var_a2 = M2C_FIELD(temp_a0, s32 *, 8), var_a3 = var_a2 | 0x20000000, (temp_v0 > 0))) {
        do {
            temp_v1 = *(s32 *)(temp_a0 + 0x10 + var_a1);
            var_a1 += 1;
            *(s32 *)var_a2 = temp_v1;
            *(s32 *)var_a3 = temp_v1;
            var_a2 += 1;
            var_a3 += 1;
        } while (var_a1 < M2C_FIELD(temp_a0, s32 *, 0));
    }
    temp_v1_2 = M2C_FIELD(temp_a0, s32 *, 4);
    if (temp_v1_2 != 0) {
        var_a2 = M2C_FIELD(temp_a0, s32 *, 0xC);
        var_a1 = 0;
        var_a3 = var_a2 | 0x20000000;
        if (temp_v1_2 > 0) {
            do {
                temp_v1_3 = *(s32 *)(temp_a0 + 0x50 + var_a1);
                var_a1 += 1;
                *(s32 *)var_a2 = temp_v1_3;
                *(s32 *)var_a3 = temp_v1_3;
                var_a2 += 1;
                var_a3 += 1;
            } while (var_a1 < M2C_FIELD(temp_a0, s32 *, 4));
        }
    }
    iSignalSema(temp_a0, var_a1);
}
}
