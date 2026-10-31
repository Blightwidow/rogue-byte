typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_TranslateXfmToPos {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 ConvertXfPos(void);            /* extern */
M2C_UNK InvalidateXfmMatWorld(s8 *);              /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(void);  /* extern */
void TranslateXfmToPos(s8 *arg0, s32 arg1) {
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg1));
    s64 vu_2;
    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(ConvertXfPos()));
    __as__6VECTORG9VU_VECTOR();
    M2C_FIELD((arg0 + 0x60), f32 *, 0x3C) = 1.0f;
    InvalidateXfmMatWorld(arg0);
}
}
