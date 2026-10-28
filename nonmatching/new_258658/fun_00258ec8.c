#include "m2c_macros.h"

s32 *PemitblipEnsureEmitter(void *);                /* extern */
M2C_UNK SetEmitterBlipmk(M2C_UNK);                  /* extern */
extern s32 B_002DE750;

s32 *func_00258EC8(void *arg0, s32 arg1) {
    s32 *var_a0;

    if (arg1 == 1) {
        SetEmitterBlipmk(1);
        var_a0 = M2C_FIELD(arg0, s32 *, 0xE4) + 0xC0;
    } else {
        var_a0 = PemitblipEnsureEmitter(arg0);
    }
    if (*var_a0 == 1) {
        return var_a0 + 0x30;
    }
    return &B_002DE750;
}
