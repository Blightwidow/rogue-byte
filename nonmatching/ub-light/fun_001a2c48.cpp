typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001A2C48 {};                 /* size 0x0 */

extern u32 B_002E1E58;
extern M2C_UNK D_002BFBD0;

void func_001A2C48(s32 *arg0, s32 *arg1) {
    s8 *temp_v1;

    if ((u32) B_002E1E58 >= 7U) {
        B_002E1E58 = 0;
    }
    temp_v1 = (s8 *)((B_002E1E58 * 8) + &D_002BFBD0);
    if (arg0 != NULL) {
        *arg0 = M2C_FIELD(temp_v1, s32 *, 0);
    }
    if (arg1 != NULL) {
        *arg1 = M2C_FIELD(temp_v1, s32 *, 4);
    }
}

}
