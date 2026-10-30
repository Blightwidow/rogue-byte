typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct PadSlot_243870 {
    s32 buffer;
    u8 *dma;
    s32 pad[5];
};
struct PadPort_243870 {
    PadSlot_243870 slot[4];
};
extern "C" {
s32 func_00242F70(s32, s32);
char *func_00243270();
extern PadPort_243870 B_004505D0[];
s32 scePadSetActDirect(s32 arg0, s32 arg1, u8 *arg2) {
    s32 index;
    s32 result;
    u8 *request;
    u8 *data;
    if (*(u8 *)(func_00243270() + 0x72) != 1) {
        return 0;
    }
    request = B_004505D0[arg0].slot[arg1].dma;
    data = request + 0xC;
    for (index = 0; index < 6; index++) {
        data[index] = arg2[index];
    }
    result = 1;
    *(s32 *)(request + 4) = result;
    *(s32 *)(request + 8) = 6;
    if (func_00242F70(arg0, arg1) != 1) {
        result = 0;
    }
    return result;
}
}
