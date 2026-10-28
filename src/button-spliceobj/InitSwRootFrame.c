#include "m2c_macros.h"

M2C_UNK CFramePtr_Assign(void *, s32);              /* extern */
s32 PframeNew();                                    /* extern */
M2C_UNK func_00259A88(s32);                         /* extern */

void InitSwRootFrame(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3A14) = 1;
    CFramePtr_Assign(arg0, PframeNew());
    func_00259A88(M2C_FIELD(arg0, s32 *, 0));
}
