#include "m2c_macros.h"

M2C_UNK PemitblipEnsureEmitter(M2C_UNK);            /* extern */
M2C_UNK PemitripEnsureEmitter(M2C_UNK);             /* extern */

void func_002589A8(s32 arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 0:
        PemitblipEnsureEmitter(1);
        return;
    case 1:
        PemitripEnsureEmitter(1);
        break;
    }
}
