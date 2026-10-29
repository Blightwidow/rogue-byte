typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_001EC718(s8 *);                      /* extern */
extern s8 *B_003E159C;

void FlushSaaUnpacks(void) {
    s8 *var_s0;
    s8 *var_s1;

    var_s1 = B_003E159C;
    if (var_s1 != NULL) {
        do {
            if (M2C_FIELD(var_s1, s32 *, 0x2C) != 0) {
                var_s0 = M2C_FIELD(var_s1, s8 **, 0x34);
                M2C_FIELD(var_s1, s32 *, 0x2C) = 0;
                if (var_s0 != NULL) {
                    do {
                        func_001EC718(var_s0);
                        var_s0 = M2C_FIELD(var_s0, s8 **, 0x10);
                    } while (var_s0 != NULL);
                }
            }
            var_s1 = M2C_FIELD(var_s1, s8 **, 0x40);
        } while (var_s1 != NULL);
    }
}

}
