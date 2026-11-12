typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_sceGsResetGraph {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
M2C_UNK GsPutIMR(M2C_UNK);                          /* extern */
M2C_UNK RemoveIntcHandler(M2C_UNK, s32);            /* extern */
M2C_UNK SetGsCrt(s32, s32, s32);                    /* extern */
M2C_UNK func_00235110(M2C_UNK);                     /* extern */
s8 *func_002405F0(s16, s32, s32, s32);            /* extern */
void sceGsResetGraph(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    s8 *temp_s0;
    s8 *temp_v0;
    temp_a1 = arg1 << 0x10;
    temp_a2 = arg2 << 0x10;
    temp_a3 = arg3 << 0x10;
    switch (arg0) {                                 /* irregular */
    case 0:
        temp_s0 = func_002405F0(arg0, temp_a1, temp_a2, temp_a3);
        *(s8 *)0x12001000 = 0x200U;
        M2C_FIELD(temp_s0, s16 *, 0) = arg1;
        M2C_FIELD(temp_s0, s16 *, 2) = arg2;
        M2C_FIELD(temp_s0, s16 *, 6) = (s16) (((u64) *(s8 *)0x12001000 >> 0x10) & 0xFF & 0xFFFF);
        GsPutIMR(0xFF00);
        M2C_FIELD(temp_s0, s16 *, 4) = (s16) (arg3 != 0);
        if (M2C_FIELD(temp_s0, s32 *, 8) != 0) {
            func_00235110(2);
            RemoveIntcHandler(2, M2C_FIELD(temp_s0, s32 *, 0xC));
            M2C_FIELD(temp_s0, s32 *, 0xC) = 0;
            M2C_FIELD(temp_s0, s32 *, 8) = 0;
        }
        SetGsCrt(arg1 & 1, arg2 & 0xFF, arg3 & 1);
        return;
    case 1:
        *(s8 *)0x12001000 = 0x100U;
        return;
    case 5:
        temp_v0 = func_002405F0(arg0, temp_a1, temp_a2, temp_a3);
        M2C_FIELD(temp_v0, s16 *, 4) = (s16) (arg3 != 0);
        M2C_FIELD(temp_v0, s16 *, 0) = arg1;
        M2C_FIELD(temp_v0, s16 *, 2) = arg2;
        M2C_FIELD(temp_v0, s16 *, 6) = (s16) (((u64) *(u64 *)0x12001000 >> 0x10) & 0xFF & 0xFFFF);
        SetGsCrt(arg1 & 1, arg2 & 0xFF, arg3 & 1);
        return;
    }
}
}
