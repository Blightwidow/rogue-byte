typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PactAddStgAction {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

s8 *PstageStgSwitchCur(M2C_UNK *);                /* extern */
extern M2C_UNK RO_002A76C0;

s32 *PactAddStgAction(s32 arg1) {
    s32 *temp_v0;
    s32 temp_a0;
    s8 *temp_v0_2;

    temp_v0_2 = PstageStgSwitchCur(&RO_002A76C0);
    if (temp_v0_2 != NULL) {
        temp_a0 = M2C_FIELD(temp_v0_2, s32 *, 8);
        if (temp_a0 < 0x40) {
            temp_v0 = (s32 *)(M2C_FIELD(temp_v0_2, s32 *, 0xC) + (temp_a0 * 8));
            M2C_FIELD(temp_v0_2, s32 *, 8) = (s32) (temp_a0 + 1);
            *temp_v0 = arg1;
            return temp_v0;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return NULL;
    }
    return NULL;
}

}
