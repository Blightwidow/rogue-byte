#include "m2c_macros.h"

M2C_UNK EvaluateCrvFromU(s32, s32, s32, f32);       /* extern */
f32 UFromCrvS();                                    /* extern */

void GetPathPosFromS(s32 arg0, s32 arg1, s32 arg2) {
    EvaluateCrvFromU(arg0, arg1, arg2, UFromCrvS());
}
