#include "m2c_macros.h"

M2C_UNK func_0014AE38(void *, M2C_UNK);             /* extern */
M2C_UNK func_001EEF70();                            /* extern */
extern f32 g_2dded0;

void func_0014A200(void *arg0) {
    func_001EEF70();
    func_0014AE38(arg0, 0);
    M2C_FIELD(arg0, f32 *, 0x48) = (f32) g_2dded0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x4A4) = 0;
}
