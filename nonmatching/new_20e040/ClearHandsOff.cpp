typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK DecrementSwBinocCount(s8 *);              /* extern */
M2C_UNK DecrementSwShowCount(s8 *);               /* extern */
M2C_UNK RemoveGrfusr__Fi(M2C_UNK);                  /* extern */
M2C_UNK func_00187E08(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK B_002DFC00;

void ClearHandsOff(s8 *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x3D78) - 1;
    M2C_FIELD(arg0, s32 *, 0x3D78) = temp_v0;
    if (temp_v0 == 0) {
        RemoveGrfusr__Fi(2);
        func_00187E08(&B_002DFC00, 8);
    }
    var_v0 = arg1 & 2;
    if (arg1 & 1) {
        DecrementSwShowCount(arg0);
        var_v0 = arg1 & 2;
    }
    if (var_v0 != 0) {
        DecrementSwBinocCount(arg0);
    }
}

}
