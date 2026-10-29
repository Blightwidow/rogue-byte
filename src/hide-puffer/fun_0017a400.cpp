typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void GoalAnim_Update();
s32 func_00209840(s32, s8 *);

void func_0017A400(s8 *arg0) {
    GoalAnim_Update();
    if ((M2C_FIELD(arg0, s32 *, 0x6C) != 0) && (M2C_FIELD(arg0, s32 *, 0x30) == 0) && (M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x40), s8 **, 8), s32 *, 0x10) >= 2)) {
        func_00209840(M2C_FIELD(arg0, s32 *, 0x10) + 0xFD0, arg0 + 0x70);
    }
}

}
