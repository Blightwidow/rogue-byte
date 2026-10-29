#include "m2c_macros.h"
extern "C" {

M2C_UNK PemitblipEnsureEmitter(s32, M2C_UNK);            /* extern */
M2C_UNK PemitripEnsureEmitter(s32, M2C_UNK);             /* extern */

void func_002589A8(s32 arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 0:
        PemitblipEnsureEmitter(arg0, 1);
        return;
    case 1:
        PemitripEnsureEmitter(arg0, 1);
        break;
    }
}
}
