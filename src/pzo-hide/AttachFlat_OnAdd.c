#include "m2c_macros.h"

M2C_UNK AppendDlEntry(M2C_UNK *, s32);              /* extern */
M2C_UNK func_001A6178();                            /* extern */
extern M2C_UNK B_003E1408;

void AttachFlat_OnAdd(s32 arg0) {
    func_001A6178();
    AppendDlEntry(&B_003E1408, arg0);
}
