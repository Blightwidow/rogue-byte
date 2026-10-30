typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001CCA40 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK B_003DD490;

s8 *func_001CCA40(s8 *arg0, s32 arg1) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s32 temp_v0;
    s32 var_a2;
    s8 **var_a1;
    s8 *temp_v1;
    s8 *var_v0;

    temp_v0 = CploFindSwObjectsByClass(&B_003DD490, 0x401, 0x14, arg1);
    var_a2 = 0;
    if (temp_v0 > 0) {
        var_a1 = (s8 **)(sp);
loop_2:
        temp_v1 = *var_a1;
        var_v0 = temp_v1;
        if (!(M2C_FIELD(temp_v1, s32 *, 0xE0) & M2C_FIELD(arg0, s32 *, 0x1000))) {
            var_a2 += 1;
            var_a1 += 1;
            if (var_a2 >= temp_v0) {
                goto block_4;
            }
            goto loop_2;
        }
    } else {
block_4:
        var_v0 = NULL;
    }
    return var_v0;
}

}
