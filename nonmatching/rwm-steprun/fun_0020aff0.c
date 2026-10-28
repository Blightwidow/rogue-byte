#include "m2c_macros.h"

M2C_UNK ResetAnimref(void *, s32);                  /* extern */
M2C_UNK func_0020BD78(s32 *);                       /* extern */
s32 *func_0020C010(M2C_UNK);                        /* extern */

void func_0020AFF0(void *arg0, s32 arg1) {
    s32 *temp_v0;
    void *temp_s1;

    temp_s1 = arg0 + 0xB0;
    ResetAnimref(temp_s1, M2C_FIELD(arg0, s32 *, 0xAC));
    M2C_FIELD(arg0, s32 *, 0xB0) = 2;
    temp_v0 = func_0020C010(0x40);
    M2C_FIELD(temp_s1, s32 **, 4) = temp_v0;
    func_0020BD78(temp_v0);
    *M2C_FIELD(temp_s1, s32 **, 4) = arg1;
    M2C_FIELD(temp_s1, s32 *, 0xC) = 0;
}
