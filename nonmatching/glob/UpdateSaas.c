#include "m2c_macros.h"

s32 FUpdatableSaa__FP3SAA(void *);                  /* extern */
extern void *B_003E159C;

void UpdateSaas(void) {
    void *temp_v0;
    void *var_s0;

    var_s0 = B_003E159C;
loop_4:
    if ((var_s0 != NULL) && (M2C_FIELD(var_s0, s32 *, 0x30) == 0)) {
        if (FUpdatableSaa__FP3SAA(var_s0) != 0) {
            temp_v0 = M2C_FIELD(var_s0, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x44)(var_s0 + M2C_FIELD(temp_v0, s16 *, 0x40));
        }
        var_s0 = M2C_FIELD(var_s0, void **, 0x40);
        goto loop_4;
    }
}
