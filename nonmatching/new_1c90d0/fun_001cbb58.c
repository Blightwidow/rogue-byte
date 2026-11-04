#include "m2c_macros.h"

M2C_UNK GetPathPosFromS(void *, M2C_UNK);           /* extern */

void func_001CBB58(s32 arg1, s32 arg2) {
    char sp[0x400];
    GetPathPosFromS(sp, 0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    if (arg2 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x240($s0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s1) */);
    }
}
