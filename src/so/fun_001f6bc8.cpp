typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001F6BC8 {};                 /* size 0x0 */

void func_001F6BC8(s8 *arg0, s32 arg1, s32 arg2) {
    struct E { u8 pad[0xC]; s32 id; u8 pad2[8]; s32 value; u8 pad3[0xB0 - 0x1C]; };
    for (s32 i = 0; i < M2C_FIELD(arg0, s32 *, 0xE0); i++) {
        E *pe = &M2C_FIELD(arg0, E **, 0xE4)[i];
        if (pe->id == arg1) {
            pe->value = arg2;
        }
    }
}

}
