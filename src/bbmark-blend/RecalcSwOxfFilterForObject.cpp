typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RecalcSwOxfFilterForObject {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
M2C_UNK UpdateSwPox(s8 *, s32, s8 *, M2C_UNK);  /* extern */
M2C_UNK func_001F4BF8(s8 *);                      /* extern */
void RecalcSwOxfFilterForObject(s8 *arg0, s8 *arg1) {
    if (M2C_FIELD(arg1, s32 *, 0xEC) != 0) {
        func_001F4BF8(arg1);
        for (s8 *node = M2C_FIELD(arg0, s8 **, 0x3D10); node != NULL; node = M2C_FIELD(node, s8 **, 0x48)) {
            if ((s32)node != M2C_FIELD(arg1, s32 *, 0xEC)) {
                UpdateSwPox(arg0, M2C_FIELD(arg1, s32 *, 0xEC), node, 0);
            }
        }
    }
}
}
