#include "m2c_macros.h"

M2C_UNK Menu_Construct();                           /* extern */
M2C_UNK Menu_ResetState(void *);                    /* extern */
extern M2C_UNK D_002D83E8;

void *func_001DD648(void *arg0) {
    Menu_Construct();
    M2C_FIELD(arg0, s32 *, 0x20) = 0x52D;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D83E8;
    Menu_ResetState(arg0);
    return arg0;
}
