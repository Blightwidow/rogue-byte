#include "m2c_macros.h"

M2C_UNK func_0017F090();                            /* extern */
M2C_UNK func_0017F3E0(void *, M2C_UNK, s32);        /* extern */
extern void *g_2dfb80;

void Mount_Init(void *arg0) {
    func_0017F090();
    func_0017F3E0(arg0, 5, arg0 + 0x1C8);
    M2C_FIELD(arg0, s32 *, 0x1C0) = -1;
    g_2dfb80 = arg0;
    M2C_FIELD(arg0, s32 *, 0x2A8) = -1;
}
