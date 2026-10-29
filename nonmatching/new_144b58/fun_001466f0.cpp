typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_00146E18(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_001EEF70();                            /* extern */

void func_001466F0(s8 *arg0) {
    s8 *temp_a0;
    s8 *temp_t1;
    s8 *temp_v0;

    func_001EEF70();
    func_00146E18(arg0, 0);
    temp_t1 = M2C_FIELD(arg0, s8 **, 0x10);
    temp_v0 = M2C_FIELD(temp_t1, s8 **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK, s32, M2C_UNK), 0x2FC)(temp_t1 + M2C_FIELD(temp_v0, s16 *, 0x2F8), 4, M2C_FIELD(arg0, s32 *, 0x38), 4);
    temp_a0 = M2C_FIELD(arg0, s8 **, 0x10);
    M2C_FIELD(temp_a0, s32 *, 0x10E0) = (s32) (M2C_FIELD(temp_a0, s32 *, 0x10E0) | 1);
}

}
