typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void CRef_Destruct(s8 *);

s8 *CRef_SetBasic(s8 *arg0, s8 *arg1) {
    s8 *temp_v0;

    if (arg1 != NULL) {
        temp_v0 = M2C_FIELD(arg1, s8 **, 0xC);
        ((void (*)(s8 *))M2C_FIELD(temp_v0, void **, 0xC))(arg1 + M2C_FIELD(temp_v0, s16 *, 8));
    }
    CRef_Destruct(arg0);
    M2C_FIELD(arg0, s8 **, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0) = 0x21;
    return arg0;
}

}
