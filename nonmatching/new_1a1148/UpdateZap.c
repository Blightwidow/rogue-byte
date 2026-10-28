#include "m2c_macros.h"

s32 FAsegaGone(s32);                                /* extern */
M2C_UNK ZapContinue(void *);                        /* extern */

void UpdateZap(void *arg0) {
    s32 temp_s1;
    s32 temp_v0;

loop_1:
    temp_s1 = M2C_FIELD(arg0, s32 *, 4);
    if (FAsegaGone(M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1030)) != 0) {
        ZapContinue(arg0);
    }
    temp_v0 = M2C_FIELD(arg0, s32 *, 4);
    if ((temp_v0 != -1) && (temp_v0 != temp_s1)) {
        goto loop_1;
    }
}
