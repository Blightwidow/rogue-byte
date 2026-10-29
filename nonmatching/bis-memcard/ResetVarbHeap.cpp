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
extern s32 B_002DD290;
extern s32 B_002DD294;
extern s32 B_002DD298;
extern s32 B_002DD29C;
extern M2C_UNK B_004520D0;

void ResetVarbHeap(void) {
    B_002DD290 = 0;
    B_002DD298 = 0;
    B_002DD29C = 0;
    B_002DD294 = 0;
    ResetSlotheap(&B_004520D0, &B_002DD29C, &B_002DD294);
}

}
