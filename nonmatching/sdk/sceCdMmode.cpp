#include "types.h"

extern "C" {
s32 func_00241F98(s32);
void func_0023B170(void *, s32);
s32 SignalSema(s32);
s32 sceSifCallRpc(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern s32 D_002C7D80;
extern s32 D_002C7940;
extern s32 D_002C676C;
extern s32 D_002C82C0;
extern s32 D_002C82E8;
extern s32 D_002C82EC;
extern s32 D_002C82F0;

s32 sceCdMmode(s32 mode) {
    s32 *modeSlot = &D_002C7D80;
    s32 rpcResult;
    s32 result;

    if (func_00241F98(0x22) == 0) {
        return 0;
    }
    {
        *modeSlot = mode;
        func_0023B170(modeSlot, 4);
        rpcResult = sceSifCallRpc(&D_002C82C0, D_002C82E8, 0, modeSlot, D_002C82EC, &D_002C7940, D_002C82F0, 0, 0);
        if (rpcResult >= 0) {
            result = *(s32 *)((u32)&D_002C7940 | 0x20000000);
            SignalSema(D_002C676C);
            return result;
        }
        SignalSema(D_002C676C);
        return 0;
    }
    return 0;
}
}
