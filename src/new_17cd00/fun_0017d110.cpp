#include "m2c_macros.h"
extern "C" {
f32 SMaxCrv(s32);
f32 SMinCrv(s32);
M2C_UNK func_0017D058(s8 *, M2C_UNK);

void func_0017D110(s8 *arg0, s32 arg1) {
    s8 *v0;
    s32 flag;
    s32 crvId;

    crvId = *(s32 *)(*(s8 **)(arg0 + 0x10) + 0xF84);
    if (arg1 != 0) {
        *(f32 *)(arg0 + 0x38) = SMaxCrv(crvId);
    } else {
        *(f32 *)(arg0 + 0x38) = SMinCrv(crvId);
    }
    v0 = *(s8 **)(arg0 + 0x10);
    flag = (*(f32 *)(v0 + 0xF88) < *(f32 *)(arg0 + 0x38)) ? 1 : 0;
    *(s32 *)(v0 + 0xF8C) = flag;
    func_0017D058(arg0, 0);
}
}
