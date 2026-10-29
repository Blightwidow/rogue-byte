typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 GrfsgsFromRef(s32);                             /* extern */
s8 *PguardanimEnsure(s32, s32);                   /* extern */
M2C_UNK func_0020BD78(s32 *);                       /* extern */
s32 *func_0020C010(M2C_UNK);                        /* extern */

void func_00207D98(s32 arg0, s32 arg1, s32 arg2) {
    s32 *temp_v0_2;
    s8 *temp_v0;

    temp_v0 = PguardanimEnsure(arg0, GrfsgsFromRef(arg1));
    M2C_FIELD(temp_v0, s32 *, 0) = 2;
    temp_v0_2 = func_0020C010(0x40);
    M2C_FIELD(temp_v0, s32 **, 4) = temp_v0_2;
    func_0020BD78(temp_v0_2);
    *M2C_FIELD(temp_v0, s32 **, 4) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0xC) = 0;
}

}
