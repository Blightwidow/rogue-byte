#include "m2c_macros.h"

s32 GrfsgsFromRef(s32);                             /* extern */
void *PguardanimEnsure(s32, s32);                   /* extern */
M2C_UNK func_0020BD78(s32 *);                       /* extern */
s32 *func_0020C010(M2C_UNK);                        /* extern */

void func_00207D98(s32 arg0, s32 arg1, s32 arg2) {
    s32 *temp_v0_2;
    void *temp_v0;

    temp_v0 = PguardanimEnsure(arg0, GrfsgsFromRef(arg1));
    M2C_FIELD(temp_v0, s32 *, 0) = 2;
    temp_v0_2 = func_0020C010(0x40);
    M2C_FIELD(temp_v0, s32 **, 4) = temp_v0_2;
    func_0020BD78(temp_v0_2);
    *M2C_FIELD(temp_v0, s32 **, 4) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0xC) = 0;
}
