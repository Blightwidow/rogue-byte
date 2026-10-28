#include "m2c_macros.h"

s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001F1900(s32);                         /* extern */
extern M2C_UNK B_003DD490;

void UpdateAllGuardLightStates(void) {
    char sp[0x400];
    s32 *var_s0;
    s32 temp_a0;
    s32 temp_v0;
    s32 var_s1;

    temp_v0 = CploFindSwObjectsByClass(&B_003DD490, 0x505, 0x38, 0);
    var_s1 = temp_v0;
    if (temp_v0 > 0) {
        var_s0 = sp;
        do {
            temp_a0 = *var_s0;
            var_s1 -= 1;
            var_s0 += 4;
            func_001F1900(temp_a0);
        } while (var_s1 != 0);
    }
}
