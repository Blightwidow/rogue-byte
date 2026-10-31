typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s8 *bevy_splice_bif_ref_op_eqv(s8 *arg0, s8 * unused_arg1, s8 *arg2, s32 arg3) {
    s32 var_a3;
    u32 temp_v1;

    var_a3 = arg3;
    temp_v1 = M2C_FIELD(arg2, u32 *, 0);
    if (temp_v1 != M2C_FIELD(arg2, s32 *, 8)) {
        var_a3 = 0;
    } else {
        switch (temp_v1) {
        case 21:
        case 23:
        case 24:
        case 25:
        case 31:
        case 32:
        case 33:
        case 34:
            var_a3 = M2C_FIELD(arg2, s32 *, 4) == M2C_FIELD((arg2 + 8), s32 *, 4);
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 36:
            var_a3 = 1;
            break;
        }
    }
    M2C_FIELD(arg0, s32 *, 4) = var_a3;
    M2C_FIELD(arg0, s32 *, 0) = 0x17;
    return arg0;
}

}
