#include "m2c_macros.h"

M2C_UNK InitStaticSlotheaps_frm(M2C_UNK, M2C_UNK);  /* extern */

void InitStaticSlotheaps_frm_thunk(void) {
    InitStaticSlotheaps_frm(1, 0xFFFF);
}
