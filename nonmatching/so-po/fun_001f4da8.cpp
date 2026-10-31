typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001F4DA8 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

M2C_UNK FreeSwMqList__FP2SWP2MQ(M2C_UNK *, s8 *); /* extern */
M2C_UNK func_001F5078(void);             /* extern */
extern M2C_UNK B_003DD490;

void func_001F4DA8(s32 arg0, s32 arg1, s8 **arg2) {
    s8 **var_a2;
    s8 *temp_a3;
    s8 *var_s0;

    var_a2 = arg2;
    var_s0 = NULL;
loop_1:
    temp_a3 = *var_a2;
    if (temp_a3 != NULL) {
        if (M2C_FIELD((temp_a3 + ((M2C_FIELD(temp_a3, s32 *, 8) == arg0) << 6)), s32 *, 8) != arg1) {
            var_a2 = (s8 **)(temp_a3 + 0xAC);
        } else {
            *var_a2 = M2C_FIELD(temp_a3, s8 **, 0xAC);
            M2C_FIELD(temp_a3, s8 **, 0xAC) = var_s0;
            var_s0 = temp_a3;
        }
        goto loop_1;
    }
    if (var_s0 != NULL) {
        func_001F5078();
        FreeSwMqList__FP2SWP2MQ(&B_003DD490, var_s0);
    }
}

}
