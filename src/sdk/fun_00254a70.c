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
void func_00254A70(s8 *arg0) {
    u32 flags;
    s32 sourceAddress;
    s32 sourceCount;
    s32 total;
    s32 destinationAddress;
    s32 destinationCount;
    s32 mode;
    flags = M2C_FIELD(arg0, u32 *, 0x1C);
    mode = flags & 0x7F;
    sourceAddress = M2C_FIELD(arg0, s32 *, 0);
    total = ((flags >> 0x10) & 3) + ((flags >> 8) & 0xF);
    destinationAddress = M2C_FIELD(arg0, s32 *, 0x10);
    destinationCount = M2C_FIELD(arg0, s32 *, 8) + total;
    sourceCount = sourceAddress - total * 0x10;
    if (destinationAddress != 0 && M2C_FIELD(arg0, s32 *, 0x14) != 0) {
        *(volatile s32 *)0x1000B010 = destinationAddress;
        *(volatile s32 *)0x1000B020 = M2C_FIELD(arg0, s32 *, 0x14);
        func_00254898(M2C_FIELD(arg0, u32 *, 0x18) | 0x100);
    }
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    *(volatile s32 *)0x10002000 = mode;
    while (*(volatile s32 *)0x10002010 < 0) {
    }
    if (sourceCount != 0 && destinationCount != 0) {
        *(volatile s32 *)0x1000B410 = sourceCount;
        *(volatile s32 *)0x1000B430 = M2C_FIELD(arg0, s32 *, 4);
        *(volatile s32 *)0x1000B420 = destinationCount;
        func_00254910(M2C_FIELD(arg0, u32 *, 0xC) | 0x100);
    }
}
