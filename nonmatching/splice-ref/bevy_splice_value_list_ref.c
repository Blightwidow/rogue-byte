#include "m2c_macros.h"

M2C_UNK CRef_Destruct();                            /* extern */

void *bevy_splice_value_list_ref(void *arg0, s32 *arg1) {
    *arg1 += 1;
    CRef_Destruct();
    M2C_FIELD(arg0, s32 **, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0) = 0x1F;
    return arg0;
}
