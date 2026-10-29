typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s8 *PentryAddBootQueue(M2C_UNK);                  /* extern */

void AddBootQueueLevel(s8 *arg1, s32 arg2, s32 arg3) {
    s32 var_v0;
    s8 *temp_v0;

    var_v0 = 0;
    if (arg1 != NULL) {
        var_v0 = M2C_FIELD(arg1, s32 *, 4) != M2C_FIELD(arg1, s32 *, 0x3C);
    }
    if (var_v0 != 0) {
        temp_v0 = PentryAddBootQueue(2);
        M2C_FIELD(temp_v0, s32 *, 0x10) = arg3;
        M2C_FIELD(temp_v0, s32 *, 0xC) = arg2;
        M2C_FIELD(temp_v0, s8 **, 8) = arg1;
    }
}

}
