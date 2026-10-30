typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct PadSlot_243458 {
    s32 buffer;
    s32 pad[3];
    s32 opened;
    s32 pad2[2];
};
struct PadPort_243458 {
    PadSlot_243458 slot[4];
};
extern "C" {
s32 func_00239450();
void func_002394A0();
char *func_00243270(s32, s32);
extern PadPort_243458 B_004505D0[];
s32 func_00243458(s32 arg0, s32 arg1, s32 arg2) {
    s32 interrupts;
    if (B_004505D0[arg0].slot[arg1].opened == 0) {
        return 0;
    }
    interrupts = func_00239450();
    *(u8 *)(func_00243270(arg0, arg1) + 0x71) = arg2;
    if (interrupts == 1) {
        func_002394A0();
    }
    return 1;
}
}
