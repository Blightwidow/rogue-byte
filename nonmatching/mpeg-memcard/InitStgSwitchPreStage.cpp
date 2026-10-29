typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitStgSwitchPreStage {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

s32 PvAllocStackImpl__Fi(s8 *, M2C_UNK, s32, s32); /* extern */

void InitStgSwitchPreStage(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s8 *temp_s0;
    s8 *temp_v0;

    M2C_FIELD(arg0, s32 *, 0x15C) = -1;
    temp_v0 = M2C_FIELD(arg0, s8 **, 0x164);
    M2C_FIELD(temp_v0, s32 *, -0x10) = -1;
    temp_s0 = temp_v0 - 0x10;
    M2C_FIELD(temp_s0, s32 *, 4) = 1;
    if (M2C_FIELD(temp_s0, s32 *, 0xC) == 0) {
        M2C_FIELD(temp_s0, s32 *, 0xC) = PvAllocStackImpl__Fi(sp, 1, 0x200, 0x10);
    }
}

}
