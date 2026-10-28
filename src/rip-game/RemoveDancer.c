#include "m2c_macros.h"

M2C_UNK PlayDancerAnim(s32, M2C_UNK, M2C_UNK);      /* extern */
M2C_UNK RemoveSoLoHierarchy();                      /* extern */

void RemoveDancer(s32 arg0) {
    RemoveSoLoHierarchy();
    PlayDancerAnim(arg0, 0, 0);
}
