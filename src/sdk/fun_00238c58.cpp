typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
extern "C" {
struct RpcClient_44BE80 { int pad[9]; int serve; };
extern RpcClient_44BE80 B_0044BE80;
extern s32 B_0044BEC0;
extern s32 B_0044BF00;
extern s32 D_002C4A94;
s32 sceSifCallRpc(RpcClient_44BE80 *, u32, u32, void *, u32, void *, u32, void *, void *);
s32 func_00238C58(s32 arg0) {
    if (D_002C4A94 < 0) return 0;
    B_0044BF00 = arg0;
    if (sceSifCallRpc(&B_0044BE80, 1, 0, &B_0044BF00, 4, &B_0044BEC0, 4, 0, 0) < 0) return 0;
    return B_0044BEC0;
}
}
