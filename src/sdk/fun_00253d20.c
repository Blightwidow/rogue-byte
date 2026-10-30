typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
int func_00252148(s8 *, int);
void func_002542B8(s8 *);
void func_002544C0(s8 *, int);
void func_00253D20(s8 *arg0) {
    int delta;
    int flag;
    int previous;
    int total;
    delta = func_00252148(arg0, 10);
    M2C_FIELD(arg0, s32 *, 0x160) = func_00252148(arg0, 3);
    func_00252148(arg0, 0x10);
    if ((u32) (M2C_FIELD(arg0, s32 *, 0x160) - 2) < 2U) {
        M2C_FIELD(arg0, s32 *, 0x164) = func_00252148(arg0, 1);
        M2C_FIELD(arg0, s32 *, 0x168) = func_00252148(arg0, 3);
    }
    if (M2C_FIELD(arg0, s32 *, 0x160) == 3) {
        M2C_FIELD(arg0, s32 *, 0x16C) = func_00252148(arg0, 1);
        M2C_FIELD(arg0, s32 *, 0x170) = func_00252148(arg0, 3);
    }
    while (func_00252148(arg0, 1) != 0) {
        func_002544C0(arg0, 8);
    }
    func_002542B8(arg0);
    flag = 0;
    previous = 0;
    if (M2C_FIELD(arg0, s32 *, 0x160) != 3 && delta != 0) {
        if (delta < 0) {
            flag = M2C_FIELD(arg0, s32 *, 0x864) == 0;
        }
        M2C_FIELD(arg0, s32 *, 0x864) = 0;
        previous = delta;
    }
    total = M2C_FIELD(arg0, s32 *, 0x85C) + delta;
    M2C_FIELD(arg0, s32 *, 0x1BC) = total;
    if (flag != 0 && previous >= delta) {
        M2C_FIELD(arg0, s32 *, 0x1BC) = total + 0x400;
    }
    {
        int current = M2C_FIELD(arg0, s32 *, 0x860);
        int limit = M2C_FIELD(arg0, s32 *, 0x1BC);
        if (current < limit) current = limit;
        M2C_FIELD(arg0, s32 *, 0x860) = current;
    }
}
