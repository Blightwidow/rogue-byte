typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetAloSelectedOid {};             /* size 0x0 */
void SetAloSelectedOid(s8 *arg0, s32 arg1) {
    s32 *var_a2;
    s32 temp_v0;
    s32 var_v1;
    if (arg1 != -1) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0xAC);
        var_v1 = 0;
        if (temp_v0 > 0) {
            var_a2 = M2C_FIELD(arg0, s32 **, 0xB0);
loop_7:
            if (arg1 != *var_a2) {
                var_v1 += 1;
                var_a2 += 4;
                if (var_v1 >= temp_v0) {
                    /* Duplicate return node #3. Try simplifying control flow for better match */
                    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
                    return;
                }
                goto loop_7;
            }
            M2C_FIELD(arg0, s32 *, 0xB4) = (s32) -(var_v1 + 3);
            return;
        }
        /* Duplicate return node #3. Try simplifying control flow for better match */
        M2C_FIELD(arg0, s32 *, 0xB4) = 0;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
}
}
