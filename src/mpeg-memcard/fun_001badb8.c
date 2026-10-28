#include "m2c_macros.h"

M2C_UNK AppendDlEntry(M2C_UNK *, s32);              /* extern */
M2C_UNK func_001F3EA8();                            /* extern */
extern M2C_UNK B_003E1450;

void func_001BADB8(s32 arg0) {
    func_001F3EA8();
    AppendDlEntry(&B_003E1450, arg0);
}
