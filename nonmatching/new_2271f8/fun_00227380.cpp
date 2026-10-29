typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00227380 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */

M2C_UNK CBinaryInputStream_ReadBspc(s32, s32, s8 *); /* extern */
M2C_UNK CBinaryInputStream_ReadGeom(s32, s32);      /* extern */
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(s8 *, s32); /* extern */
M2C_UNK LoadXfmBaseFromBrx();                       /* extern */
s32 U32Read__18CBinaryInputStream(s32);             /* extern */

void func_00227380(s8 *arg0, s32 arg1) {
    s32 temp_s2;

    temp_s2 = (s32)(arg0 + 0xF8);
    LoadXfmBaseFromBrx();
    CBinaryInputStream_ReadGeom(arg1, temp_s2);
    CBinaryInputStream_ReadBspc(arg1, temp_s2, arg0 + 0xE8);
    M2C_FIELD(arg0, s32 *, 0xE0) = U32Read__18CBinaryInputStream(arg1);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(arg0, arg1);
    return;
}

}
