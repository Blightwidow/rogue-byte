typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Align__4VIFSi {};                 /* size 0x0 */
void Align__4VIFSi(s8 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a2;
    u32 var_v0;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0xC);
    var_v0 = (u32) (temp_v0 & 0xC) >> 2;
    var_a2 = temp_v0;
    if (var_v0 != arg1) {
        do {
            temp_a0 = var_v0 + 1;
            *(s32 *)var_a2 = 0;
            var_v0 = temp_a0 - (((s32) ((temp_a0 > -1) ? temp_a0 : (var_v0 + 4)) >> 2) * 4);
            var_a2 += 4;
        } while (var_v0 != arg1);
    }
    M2C_FIELD(arg0, s32 *, 0xC) = var_a2;
}
}
