typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CBomb_PostLoad {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

void PostSoLoad();
s32 PvAllocSwImpl__Fi(s8 *, s32, s32);

void CBomb_PostLoad(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    PostSoLoad();
    if (M2C_FIELD(arg0, s32 *, 0x1F4) != 0) {
        M2C_FIELD(arg0, s32 *, 0x1FC) = PvAllocSwImpl__Fi(sp, 0xC0, 0x10);
    }
}

}
