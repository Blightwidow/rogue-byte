typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void sprintf(s8 *, M2C_UNK *, s32);                    /* extern */
extern M2C_UNK B_003DA150;
extern M2C_UNK D_002C3288;
extern M2C_UNK RO_002A79A0;

void GetLootRowPrice(s8 *arg0, s32 arg1) {
    s32 var_a2;
    u32 temp_a1;

    temp_a1 = M2C_FIELD((&B_003DA150 + ((M2C_FIELD(&B_003DA150, s32 *, 0x250) + arg1) * 8)), u32 *, 0x4C);
    var_a2 = 0;
    if (temp_a1 < 0x40U) {
        var_a2 = *((temp_a1 * 0xC) + &D_002C3288);
    }
    if (var_a2 != 0) {
        sprintf(arg0, &RO_002A79A0, var_a2);
        return;
    }
    *arg0 = 0;
}

}
