typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UntriggerBtn {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK RunBtnAsegs(s8 **, M2C_UNK);              /* extern */
void UntriggerBtn(s8 **arg0) {
    s8 *temp_a3;
    s8 *temp_a6;
    s8 *temp_v0;
    s8 *temp_v0_2;
    temp_a6 = *arg0;
    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s8 *), 0x1C)(temp_a6 + M2C_FIELD(temp_v0, s16 *, 0x18), 6, 0, 0, 0, 0, temp_a6);
    temp_v0 = M2C_FIELD(temp_a6, s8 **, 0xC);
    RunBtnAsegs(arg0, 1);
    temp_a3 = *arg0;
    temp_v0_2 = M2C_FIELD(temp_a3, s8 **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK, s8 **, s8 *), 0x24)(temp_a3 + M2C_FIELD(temp_v0_2, s16 *, 0x20), 7, arg0, temp_a3);
}
}
