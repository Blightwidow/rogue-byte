typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001AE168 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK InitCritSect__FP8CRITSECT(M2C_UNK *, s32 *, s32 *, s32 *); /* extern */
extern s32 B_002F638C;
extern M2C_UNK B_002F6390;
extern M2C_UNK D_0047220F;
extern s32 g_2f6380;
extern s32 g_2f6384;
extern s32 g_2f6388;
extern s32 g_2f639c;
void func_001AE168(void) {
    s32 temp_v0;
    temp_v0 = (s32) &D_0047220F & ~0xF;
    g_2f6380 = temp_v0;
    g_2f6388 = 0x02000000;
    g_2f639c = -1;
    g_2f6384 = temp_v0;
    B_002F638C = 0x02000000;
    InitCritSect__FP8CRITSECT(&B_002F6390, &g_2f639c, &g_2f6380, &g_2f6388);
}
}
