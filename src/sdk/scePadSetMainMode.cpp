typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct PadRequest_2437B8 {
    s32 command;
    s32 port;
    s32 slot;
    s32 arg2;
    s32 arg3;
    s32 result;
};
extern "C" {
s32 func_00243458(s32, s32, s32);
s32 sceSifCallRpc(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern char B_00450580[];
extern PadRequest_2437B8 B_004507C0;
s32 scePadSetMainMode(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    B_004507C0.arg2 = arg2;
    B_004507C0.arg3 = arg3;
    B_004507C0.command = 6;
    B_004507C0.port = arg0;
    B_004507C0.slot = arg1;
    if (sceSifCallRpc(B_00450580, 1, 0, &B_004507C0, 0x80, &B_004507C0, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (B_004507C0.result == 1) {
        func_00243458(arg0, arg1, 2);
    }
    return B_004507C0.result;
}
}
