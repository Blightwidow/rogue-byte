typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RemoveTn {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
void CancelSwCallbacks(M2C_UNK *, M2C_UNK, s32, M2C_UNK);
void RemoveLoHierarchy();
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A96EF;
void RemoveTn(s32 arg0) {
    RemoveLoHierarchy();
    s32 vu_1;
    asm volatile("ldl %0, %%lo(RO_002A96EF)(%1)" : "=r"(vu_1) : "r"(&RO_002A96EF));
    s32 vu_2;
    asm volatile("ldr %0, %%lo(RO_002A96E8)(%1)" : "=r"(vu_2) : "r"(&RO_002A96EF), "0"(vu_1));
    CancelSwCallbacks(&B_003DD490, 1, arg0, vu_2);
}
}
