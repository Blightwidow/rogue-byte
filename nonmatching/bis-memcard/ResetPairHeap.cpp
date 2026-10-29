typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void ResetSlotheap(M2C_UNK *, s32 *, s32 *);
extern s32 B_002DD280;
extern s32 B_002DD284;
extern s32 B_002DD288;
extern s32 B_002DD28C;
extern M2C_UNK B_004520A8;

void ResetPairHeap(void) {
    B_002DD280 = 0;
    B_002DD288 = 0;
    B_002DD28C = 0;
    B_002DD284 = 0;
    ResetSlotheap(&B_004520A8, &B_002DD28C, &B_002DD284);
}

}
