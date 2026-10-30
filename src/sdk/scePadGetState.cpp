typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct PadSlot_243500 {
    s32 buffer;
    s32 pad[3];
    s32 opened;
    s32 pad2[2];
};
struct PadPort_243500 {
    PadSlot_243500 slot[4];
};
extern "C" {
char *func_00243270(s32, s32);
extern PadPort_243500 B_004505D0[];
u8 scePadGetState(s32 arg0, s32 arg1) {
    if (B_004505D0[arg0].slot[arg1].opened == 0) {
        return 0;
    }
    return *(u8 *)(func_00243270(arg0, arg1) + 0x71);
}
}
