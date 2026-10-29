typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FActDrivesXf(s8 *);
void SetXfKind(s32, s8 *, M2C_UNK);

void func_00131A90(s8 *arg0, f32 fparg0) {
    s8 *temp_a1;
    s8 *var_s0;

    var_s0 = M2C_FIELD(arg0, s8 **, 0x34);
    if (var_s0 != NULL) {
        do {
            if (FActDrivesXf(var_s0) != 0) {
                temp_a1 = M2C_FIELD(var_s0, s8 **, 8);
                if (M2C_FIELD(temp_a1, s16 *, 0x98) == 7) {
                    SetXfKind(M2C_FIELD(var_s0, s32 *, 4), temp_a1, 9);
                    M2C_FIELD(M2C_FIELD(var_s0, s8 **, 8), f32 *, 0xA8) = fparg0;
                }
            }
            var_s0 = M2C_FIELD(var_s0, s8 **, 0x28);
        } while (var_s0 != NULL);
    }
}

}
