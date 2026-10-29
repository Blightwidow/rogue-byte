typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001FD028 {};                 /* size 0x0 */
s32 func_001FD028(s8 *arg0, s32 arg1) {
    s32 temp_v0;
    if (arg1 >= 0) {
        if (arg1 < M2C_FIELD(arg0, s32 *, 0x18)) {
            temp_v0 = *(s32 *)((arg1 * 4) + M2C_FIELD(arg0, s32 *, 0x100));
            if (temp_v0 >= 0) {
                return M2C_FIELD(arg0, s32 *, 0xFC) + (temp_v0 * 4);
            }
            return 0;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
}
