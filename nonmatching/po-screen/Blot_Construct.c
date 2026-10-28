#include "m2c_macros.h"

M2C_UNK InitSl(void *, M2C_UNK);                    /* extern */
extern M2C_UNK D_002DAF30;

void *Blot_Construct(void *arg0) {
    s32 *var_v1;
    u32 var_a0;

    M2C_FIELD(arg0, s32 *, 0x7C) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002DAF30;
    var_a0 = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    var_v1 = arg0 + 0xCC;
    do {
        *var_v1 = -1;
        var_a0 += 1;
        var_v1 += 4;
    } while (var_a0 < 0xAU);
    InitSl(arg0 + 0xFC, 0x68);
    return arg0;
}
