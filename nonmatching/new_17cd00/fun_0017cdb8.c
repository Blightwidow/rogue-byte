#include "m2c_macros.h"

f32 SMaxCrv(s32);                                   /* extern */
f32 SMinCrv(s32);                                   /* extern */
M2C_UNK func_0017CD00(void *, M2C_UNK);             /* extern */

void func_0017CDB8(void *arg0, s32 arg1) {
    f32 var_f0;
    s32 temp_a0;
    s32 var_v1;
    void *temp_v0;

    temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF84);
    if (arg1 != 0) {
        var_f0 = SMaxCrv(temp_a0);
    } else {
        var_f0 = SMinCrv(temp_a0);
    }
    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    M2C_FIELD(arg0, f32 *, 0x3C) = var_f0;
    var_v1 = 1;
    if (!(M2C_FIELD(temp_v0, f32 *, 0xF88) < M2C_FIELD(arg0, f32 *, 0x3C))) {
        var_v1 = 0;
    }
    M2C_FIELD(temp_v0, s32 *, 0xF8C) = var_v1;
    func_0017CD00(arg0, 0);
}
