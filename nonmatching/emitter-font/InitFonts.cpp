typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitFonts {
    /* 0x000 */ char pad0[0x670];
};                                                  /* size = 0x670 */

M2C_UNK InitZpr__FP3ZPR3ZPKP2LO(s8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0015F710(M2C_UNK *, s32, s8 *);      /* extern */
extern M2C_UNK B_002DE770;
extern s32 D_002BE320;

void InitFonts(void) {
    s8 sp[0x670] __attribute__((aligned(16)));
    M2C_UNK *temp_a0;
    M2C_UNK *var_s1;
    s32 *var_s0;
    s32 var_s2;

    var_s2 = 1;
    InitZpr__FP3ZPR3ZPKP2LO(sp, 0x1000, 0x1800);
    var_s1 = &B_002DE770;
    var_s0 = &D_002BE320;
    do {
        temp_a0 = var_s1;
        var_s1 += 0x140;
        func_0015F710(temp_a0, *var_s0, sp);
        var_s2 -= 1;
        var_s0 += 1;
    } while (var_s2 >= 0);
}

}
