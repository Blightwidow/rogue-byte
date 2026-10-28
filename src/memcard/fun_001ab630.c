#include "m2c_macros.h"

M2C_UNK SetMemcardThreadHighPrio__FP7MEMCARD(void *); /* extern */
M2C_UNK SetSaveState(void *, M2C_UNK);              /* extern */
M2C_UNK ValidateSaveSlot(void *, void *);           /* extern */
extern s32 B_003E0EA8;

void func_001AB630(void *arg0) {
    s32 var_s2;
    void *var_s0;

    if ((M2C_FIELD(arg0, s32 *, 8) == 5) && (B_003E0EA8 != 0)) {
        var_s0 = arg0 + 0x24;
        var_s2 = 2;
        SetMemcardThreadHighPrio__FP7MEMCARD(arg0 + 0xFD5C);
        do {
            ValidateSaveSlot(arg0, var_s0);
            var_s2 -= 1;
            var_s0 += 0x5464;
        } while (var_s2 >= 0);
        M2C_FIELD(arg0, s32 *, 0xC) = 6;
        SetSaveState(arg0, 6);
    }
}
