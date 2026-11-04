#include "m2c_macros.h"

M2C_UNK PosLoWorld();                               /* extern */

void func_001FF4F0(s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        PosLoWorld();
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x240($s1) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s0) */);
    }
}
