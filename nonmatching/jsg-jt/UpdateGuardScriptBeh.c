#include "m2c_macros.h"

s32 FGuardScriptWaiting(void *);                    /* extern */
M2C_UNK func_001EEF98();                            /* extern */

void UpdateGuardScriptBeh(void *arg0) {
    void *temp_a1;
    void *temp_v0;

    func_001EEF98();
    if (M2C_FIELD(arg0, void **, 0x38) != NULL) {
loop_1:
        if (FGuardScriptWaiting(arg0) == 0) {
            temp_a1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x38), void **, 0x18);
            M2C_FIELD(arg0, void **, 0x38) = temp_a1;
            if (temp_a1 != NULL) {
                temp_v0 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x7C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x78), temp_a1);
                if (M2C_FIELD(arg0, void **, 0x38) != NULL) {
                    goto loop_1;
                }
            }
        }
    }
}
