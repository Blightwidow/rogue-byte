typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
void func_00254898(u32);
void func_00254910(u32);
void func_00254988(s8 *arg0) {
    func_00254910(1);
    M2C_FIELD(arg0, s32 *, 0) = *(volatile s32 *)0x1000B410;
    M2C_FIELD(arg0, s32 *, 4) = *(volatile s32 *)0x1000B430;
    M2C_FIELD(arg0, s32 *, 8) = *(volatile s32 *)0x1000B420;
    M2C_FIELD(arg0, s32 *, 0xC) = *(volatile s32 *)0x1000B400;
    while (*(volatile s32 *)0x10002010 & 0xF0) {
    }
    func_00254898(0);
    M2C_FIELD(arg0, s32 *, 0x10) = *(volatile s32 *)0x1000B010;
    M2C_FIELD(arg0, s32 *, 0x14) = *(volatile s32 *)0x1000B020;
    M2C_FIELD(arg0, s32 *, 0x18) = *(volatile s32 *)0x1000B000;
    M2C_FIELD(arg0, s32 *, 0x1C) = *(volatile s32 *)0x10002020;
    M2C_FIELD(arg0, s32 *, 0x20) = *(volatile s32 *)0x10002010;
}
