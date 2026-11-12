#include "types.h"

extern s32 B_00450880[];
extern s32 B_00450900[];
extern s32 B_00450D80[];
extern s32 B_00451E40[];
extern s32 B_004508A8;
extern s32 B_004508AC;
extern s32 B_004508B0;
extern s32 D_002C8350;
extern s32 D_002C8354;

s32 PollSema(s32);
void SignalSema(s32);
void func_0023B170(void *, s32);
s32 sceSifCallRpc(void *, s32, s32, void *, s32, void *, s32, void *, void *);
void func_00244518(void);

s32 sceMcGetInfo(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 rpcResult;

    if (B_00450880[9] == 0) {
        return -100;
    }
    if (PollSema(D_002C8354) < 0) {
        return -200;
    }
    B_00450900[1] = arg0;
    B_00450900[2] = arg1;
    B_00450900[7] = (s32)B_00450D80;
    if (arg2 != 0) {
        B_00450900[5] = 1;
    } else {
        B_00450900[5] = 0;
    }
    if (arg3 != 0) {
        B_00450900[4] = 1;
    } else {
        B_00450900[4] = 0;
    }
    if (arg4 != 0) {
        B_00450900[3] = 1;
    } else {
        B_00450900[3] = 0;
    }
    B_004508A8 = arg2;
    B_004508AC = arg3;
    B_004508B0 = arg4;
    func_0023B170(B_00450D80, 0xC0);
    rpcResult = sceSifCallRpc(B_00450880, 1, 1, B_00450900, 0x30, B_00451E40, 4,
                              (void *)func_00244518, B_00450D80);
    if (rpcResult != 0) {
        SignalSema(D_002C8354);
        return -0x5B;
    }
    D_002C8350 = 1;
    return 0;
}
