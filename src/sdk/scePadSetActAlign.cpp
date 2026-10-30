typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct PadRequest_243930 {
    s32 command;
    s32 port;
    s32 slot;
    u8 data[8];
    s32 result;
};
extern "C" {
s32 func_00243458(s32, s32, s32);
s32 sceSifCallRpc(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern char B_00450580[];
extern PadRequest_243930 B_004507C0;
s32 scePadSetActAlign(s32 arg0, s32 arg1, u8 *arg2) {
    PadRequest_243930 *request = &B_004507C0;
    s32 index;
    request->command = 8;
    request->port = arg0;
    request->slot = arg1;
    for (index = 0; index < 6; index++) {
        request->data[index] = arg2[index];
    }
    if (sceSifCallRpc(B_00450580, 1, 0, request, 0x80, request, 0x80, 0, 0) < 0) {
        return 0;
    }
    if (request->result == 1) {
        func_00243458(arg0, arg1, 2);
    }
    return request->result;
}
}
