#include "m2c_macros.h"

M2C_UNK RemoveDlEntry(M2C_UNK *, s32);              /* extern */
M2C_UNK func_001F3E00();                            /* extern */
extern M2C_UNK B_003E13E4;

void OnHbskRemove(s32 arg0) {
    func_001F3E00();
    RemoveDlEntry(&B_003E13E4, arg0);
}
