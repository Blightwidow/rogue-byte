typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PentryAddBootQueue {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

M2C_UNK memset(s32 *, M2C_UNK, M2C_UNK);            /* extern */
extern s32 B_002E1E68;

s32 *PentryAddBootQueue(u32 *arg0, s32 arg1) {
    s32 * result;
    s32 *temp_s0;
    u32 temp_v1;

    temp_v1 = *arg0;
    if (temp_v1 < 0x10U) {
        *arg0 = temp_v1 + 1;
        temp_s0 = (s32 *)(arg0 + ((temp_v1 * 0x1C) + 4));
        memset(temp_s0, 0, 0x1C);
        *temp_s0 = arg1;
        { result = temp_s0; goto done; }
    }
    { result = &B_002E1E68; goto done; }
done:
    return result;
}

}
