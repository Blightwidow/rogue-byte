#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Read_thunk(M2C_UNK, void *); /* extern */
s32 PvAllocSwCopyImpl__FiPv(s32 *, void *);         /* extern */

void func_00228250(s32 arg0, s32 *arg1) {
    char sp[0x400];
    M2C_UNK sp3C;
    M2C_UNK sp4;
    s32 sp40;

    CBinaryInputStream_Read_thunk(0x40, sp);
    if (sp4 != sp3C) {
        sp40 = 0x40;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        *arg1 = PvAllocSwCopyImpl__FiPv(&sp40, sp);
        return;
    }
    *arg1 = 0;
}
