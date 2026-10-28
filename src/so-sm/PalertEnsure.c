#include "m2c_macros.h"

M2C_UNK InitAlert(s32, s32);                        /* extern */
s32 PalertFind();                                   /* extern */
s32 __builtin_new(M2C_UNK);                         /* extern */

void PalertEnsure(s32 arg0) {
    if (PalertFind() == 0) {
        InitAlert(__builtin_new(0xAC), arg0);
    }
}
