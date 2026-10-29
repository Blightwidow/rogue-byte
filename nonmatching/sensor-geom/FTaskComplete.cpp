typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FTaskComplete {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x28];
};                                                  /* size = 0x30 */
#define sp4 (*(s32 *)(sp + 0x04))
M2C_UNK CRef_Destruct(s8 *);                      /* extern */
M2C_UNK RefGetGameSaveValue(s8 *, s8 *, M2C_UNK *); /* extern */
extern M2C_UNK B_003D4A60;
s32 FTaskComplete(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 temp_v0;
    s32 var_v0;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x54);
    var_v0 = temp_v0 < 2;
    if (temp_v0 == -1) {
        if (M2C_FIELD(arg0, s32 *, 0xD8) != 0) {
            RefGetGameSaveValue(sp, arg0 + 0xD8, &B_003D4A60);
            CRef_Destruct(sp);
            return sp4;
        }
        var_v0 = M2C_FIELD(arg0, s32 *, 0x54) < 2;
        goto block_4;
    }
block_4:
    return var_v0 ^ 1;
}
}
