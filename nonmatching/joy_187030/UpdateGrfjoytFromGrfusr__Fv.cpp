typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern s32 B_002DFBC4;
extern s32 B_002E0CBC;
extern s32 g_2dfbc0;

void UpdateGrfjoytFromGrfusr__Fv(void) {
    s32 var_v0;

    if (B_002DFBC4 & 0x10) {
        var_v0 = 5;
        goto block_8;
    }
    if (B_002DFBC4 & 0xC) {
        g_2dfbc0 = 0;
    } else {
        if (B_002DFBC4 & 1) {
            var_v0 = 5;
        } else {
            var_v0 = 4;
            if (!(B_002DFBC4 & 2)) {
                var_v0 = 7;
            }
        }
block_8:
        g_2dfbc0 = var_v0;
    }
    if (!(g_2dfbc0 & 2)) {
        B_002E0CBC = 0xFFFF;
    }
}

}
