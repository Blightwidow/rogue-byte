#include "m2c_macros.h"

M2C_UNK RemoveAloHierarchy();                       /* extern */
M2C_UNK SetTnTns__FP2TN3TNS(s32, M2C_UNK);          /* extern */

void OnTnRemove(s32 arg0) {
    RemoveAloHierarchy();
    SetTnTns__FP2TN3TNS(arg0, 0);
}
