typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0019E950 {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ char pad30[0x20];
};                                                  /* size = 0x50 */
#define sp0 (*(s128 *)(sp + 0x00))
s128 ConvertAloPos(s8 *, M2C_UNK, s128);          /* extern */
M2C_UNK GetPathPosFromS(s32, s8 *, s128 *, f32);  /* extern */
void func_0019E950(s8 *arg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s128 sp10;
    s128 sp20;
    s128 temp_v0;
    s8 *temp_t2;
    s8 *temp_v0_2;
    GetPathPosFromS(M2C_FIELD(arg0, s32 *, 0xC), sp, &sp10, M2C_FIELD(arg0, f32 *, 0x10));
    temp_v0 = ConvertAloPos(M2C_FIELD(arg0, s8 **, 0), 0, M2C_FIELD(arg0, s128 *, 0x30));
    temp_t2 = M2C_FIELD(arg0, s8 **, 0);
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(temp_v0));
    vu_1;
    sp20 = temp_v0;
    temp_v0_2 = M2C_FIELD(temp_t2, s8 **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK, s32, s128), 0x294)(temp_t2 + M2C_FIELD(temp_v0_2, s16 *, 0x290), 7, M2C_FIELD(arg0, s32 *, 0xC), sp0);
}
}
