typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RemoveAloFromRenderTree {};       /* size 0x0 */
void RemoveAloFromRenderTree(s8 *arg0) {
    s32 temp_a0;
    s8 *temp_a1;
    temp_a1 = M2C_FIELD(arg0, s8 **, 0x144);
    if (temp_a1 != NULL) {
        M2C_FIELD(temp_a1, s64 *, 0x10) = (s64) (M2C_FIELD(temp_a1, s64 *, 0x10) | (0xF000 << 0x14));
        M2C_FIELD(arg0, s32 *, 0x140) = -1;
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x40);
        M2C_FIELD(arg0, s8 **, 0x144) = NULL;
        if ((temp_a0 ^ 1) & 1) {
            *(s32 *)temp_a0 = (s32) (*(s32 *)temp_a0 & ~0x80);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) (temp_a0 & ~0x80);
    }
}
}
