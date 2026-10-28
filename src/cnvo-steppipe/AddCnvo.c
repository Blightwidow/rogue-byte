#include "m2c_macros.h"

M2C_UNK AddLoHierarchy();                           /* extern */
M2C_UNK AppendDlEntry(M2C_UNK *, s32);              /* extern */
extern M2C_UNK B_003E1420;

void AddCnvo(s32 arg0) {
    AddLoHierarchy();
    AppendDlEntry(&B_003E1420, arg0);
}
