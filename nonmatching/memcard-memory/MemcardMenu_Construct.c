#include "m2c_macros.h"

M2C_UNK Menu_Construct();                           /* extern */
M2C_UNK Menu_ResetState(void *, M2C_UNK);           /* extern */
extern M2C_UNK D_002D3750;

void *MemcardMenu_Construct(void *arg0) {
    Menu_Construct();
    M2C_FIELD(arg0, s32 *, 0x40) = -1;
    M2C_FIELD(arg0, s32 *, 0x20) = 0x52C;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D3750;
    Menu_ResetState(arg0, 0x52C);
    return arg0;
}
