typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 func_00165C28(s8 **arg0, s8 **arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v1;
    s8 *temp_a0;
    s8 *temp_a1;
    s8 *temp_a2;
    s8 *temp_v1_2;

    temp_a0 = *arg0;
    temp_a1 = *arg1;
    var_v0 = M2C_FIELD(temp_a0, s32 *, 0x104);
    var_v1 = M2C_FIELD(temp_a1, s32 *, 0x104);
    if (var_v0 == var_v1) {
        temp_v1_2 = M2C_FIELD(temp_a0, s8 **, 0x7C);
        var_v0 = -1;
        if (temp_v1_2 != NULL) {
            var_v0 = M2C_FIELD(temp_v1_2, s32 *, 0x18);
        }
        temp_a2 = M2C_FIELD(temp_a1, s8 **, 0x7C);
        var_v1 = -1;
        if (temp_a2 != NULL) {
            var_v1 = M2C_FIELD(temp_a2, s32 *, 0x18);
        }
        if (var_v0 == var_v1) {
            temp_v0 = M2C_FIELD(temp_a0, s32 *, 0x100);
            temp_v1 = M2C_FIELD(temp_a1, s32 *, 0x100);
            if (temp_v0 == temp_v1) {
                return M2C_FIELD(temp_a0, s32 *, 0x18) - M2C_FIELD(temp_a1, s32 *, 0x18);
            }
            return temp_v0 - temp_v1;
        }
        /* Duplicate return node #3. Try simplifying control flow for better match */
        return var_v0 - var_v1;
    }
    return var_v0 - var_v1;
}

}
