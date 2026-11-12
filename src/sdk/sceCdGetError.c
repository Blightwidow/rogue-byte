#include "types.h"

extern s32 D_002C676C;
extern s32 D_002C7940;
extern s32 D_002C82C0;

s32 func_00241F98(s32);
void SignalSema(s32);
s32 sceSifCallRpc(void *, s32, s32, void *, s32, void *, s32, void *, void *);

s32 sceCdGetError(void) {
    s32 result;
    s32 value;

    if (func_00241F98(3) == 0) {
        return -1;
    }
    result = sceSifCallRpc(&D_002C82C0, 4, 0, 0, 0, &D_002C7940, 4, 0, 0);
    if (result < 0) {
        SignalSema(D_002C676C);
        return -1;
    }
    value = *(s32 *)((u32)&D_002C7940 | 0x20000000);
    SignalSema(D_002C676C);
    return value;
}
