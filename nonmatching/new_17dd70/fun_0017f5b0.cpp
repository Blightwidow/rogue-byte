typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0017F5B0 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK QueueSwCallback(M2C_UNK *, s8 *, M2C_UNK, s32); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A5637;
void func_0017F5B0(s8 *arg0, s32 arg1) {
    M2C_UNK temp_a2;
    if (M2C_FIELD(arg0, s32 *, 0x18C) == 0) {
        s32 vu_1;
        asm volatile("ldl %0, %%lo(RO_002A5637)(%1)" : "=r"(vu_1) : "r"(&RO_002A5637));
        s32 vu_2;
        asm volatile("ldr %0, %%lo(RO_002A5630)(%1)" : "=r"(vu_2) : "r"(&RO_002A5637), "0"(vu_1));
        temp_a2 = vu_2;
        M2C_FIELD(arg0, s32 *, 0x18C) = 1;
        QueueSwCallback(&B_003DD490, arg0, temp_a2, arg1);
    }
}
}
