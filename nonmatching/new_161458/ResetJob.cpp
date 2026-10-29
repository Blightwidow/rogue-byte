typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK SaveJobVariables(s8 *);                   /* extern */
M2C_UNK SaveTaskVariables(s8 *);                  /* extern */

void ResetJob(s8 *arg0) {
    s8 *var_s0;

    var_s0 = M2C_FIELD(arg0, s8 **, 0x80);
    if (var_s0 != NULL) {
        M2C_FIELD(var_s0, s32 *, 0x64) = 0;
loop_2:
        var_s0 = M2C_FIELD(var_s0, s8 **, 0x84);
        SaveTaskVariables(var_s0);
        if (var_s0 != NULL) {
            M2C_FIELD(var_s0, s32 *, 0x64) = 0;
            goto loop_2;
        }
    }
    M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    SaveJobVariables(arg0);
}

}
