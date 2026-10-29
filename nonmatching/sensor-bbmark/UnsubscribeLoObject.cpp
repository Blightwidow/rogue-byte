typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UnsubscribeLoObject {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */

M2C_UNK FreeSlotheapPv(M2C_UNK *, s8 *, s32);     /* extern */
extern M2C_UNK B_003E1144;

void UnsubscribeLoObject(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s8 **var_v1;
    s8 *temp_a1;

    var_v1 = (s8 **)(arg0 + 8);
loop_1:
    temp_a1 = *var_v1;
    if (temp_a1 != NULL) {
        if (M2C_FIELD(temp_a1, s32 *, 0) != arg1) {
            var_v1 = (s8 **)(temp_a1 + 8);
            goto loop_1;
        }
        temp_v0 = M2C_FIELD(temp_a1, s32 *, 4) - 1;
        M2C_FIELD(temp_a1, s32 *, 4) = temp_v0;
        if (temp_v0 <= 0) {
            *var_v1 = M2C_FIELD(temp_a1, s8 **, 8);
            FreeSlotheapPv(&B_003E1144, temp_a1, arg1);
        }
    }
}

}
