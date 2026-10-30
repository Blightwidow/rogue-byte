typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001A5D58 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
s8 *PdcbAllocSw(M2C_UNK *);                       /* extern */
extern M2C_UNK B_003DD490;
void func_001A5D58(s8 *arg0) {
    s8 *temp_v0;
    temp_v0 = PdcbAllocSw(&B_003DD490);
    M2C_FIELD(temp_v0, s8 **, 8) = (s8 *) M2C_FIELD(arg0, s8 **, 0x34);
    M2C_FIELD(arg0, s8 **, 0x34) = temp_v0;
}
}
