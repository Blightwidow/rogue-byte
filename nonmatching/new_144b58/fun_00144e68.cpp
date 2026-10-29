typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK GoalGotoPos_SetPos(s8 *, s128);           /* extern */
M2C_UNK func_001EEF70();                            /* extern */
s8 *func_00205438(s32, M2C_UNK);                  /* extern */

void func_00144E68(s8 *arg0) {
    s8 *temp_v0;
    s8 *temp_v0_2;

    func_001EEF70();
    temp_v0 = func_00205438(M2C_FIELD(arg0, s32 *, 0x10), 0xA8);
    M2C_FIELD(temp_v0, s32 *, 0x40) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(temp_v0, f32 *, 0x64) = (f32) M2C_FIELD(arg0, f32 *, 0x34);
    M2C_FIELD(temp_v0, s32 *, 0xCC) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(temp_v0, f32 *, 0xD0) = (f32) M2C_FIELD(arg0, f32 *, 0x3C);
    GoalGotoPos_SetPos(arg0, M2C_FIELD(arg0, s128 *, 0x40));
    temp_v0_2 = M2C_FIELD(temp_v0, s8 **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *), 0x44)(temp_v0 + M2C_FIELD(temp_v0_2, s16 *, 0x40));
}

}
