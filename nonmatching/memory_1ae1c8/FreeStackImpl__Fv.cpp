typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK LeaveCritSect__FP8CRITSECT(M2C_UNK *, s32, s32 *, s32 *); /* extern */
extern M2C_UNK B_002F6390;
extern M2C_UNK B_002F63A0;
extern s32 g_2f6388;
extern s32 g_2f639c;

void FreeStackImpl__Fv(void) {
    s32 temp_a1;
    s32 temp_v1;

    temp_a1 = g_2f639c - 1;
    temp_v1 = *((g_2f639c * 4) + &B_002F63A0);
    g_2f639c = temp_a1;
    g_2f6388 = temp_v1;
    LeaveCritSect__FP8CRITSECT(&B_002F6390, temp_a1, &g_2f639c, &g_2f6388);
}

}
