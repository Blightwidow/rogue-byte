#include "m2c_macros.h"
extern "C" {
s32 FFindDlEntry(M2C_UNK *, s8 *);
M2C_UNK AppendDlEntry(M2C_UNK *, s8 *);
extern M2C_UNK B_003DD08C;

void ActivateAmb(s8 *arg0) {
    s8 *vt;
    s16 off;
    void (*fn)(s8 *);

    if (FFindDlEntry(&B_003DD08C, arg0) == 0) {
        vt = *(s8 **)(arg0 + 0xC);
        off = *(s16 *)(vt + 0x8);
        fn = *(void (**)(s8 *))(vt + 0xC);
        fn(arg0 + off);
        AppendDlEntry(&B_003DD08C, arg0);
    }
}
}
