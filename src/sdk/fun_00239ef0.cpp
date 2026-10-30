typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00239EF0 {};                 /* size 0x0 */
extern s8 *D_002C5A48;
s8 *func_00239EF0(s8 *arg0) {
    s8 **temp_v0;
    s8 *temp_v1;
    temp_v0 = M2C_FIELD(arg0, s8 ***, 4);
    temp_v1 = M2C_FIELD(arg0, s8 **, 0);
    if (temp_v0 != NULL) {
        *temp_v0 = temp_v1;
    } else {
        D_002C5A48 = temp_v1;
    }
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, s8 ***, 4) = (s8 **) M2C_FIELD(arg0, s8 ***, 4);
    }
    M2C_FIELD(arg0, s8 ***, 4) = NULL;
    return temp_v1;
}
}
