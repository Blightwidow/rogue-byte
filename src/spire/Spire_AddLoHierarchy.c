#include "m2c_macros.h"

M2C_UNK AddLoHierarchy();                           /* extern */
M2C_UNK AppendDlEntry(M2C_UNK *, s32);              /* extern */
extern M2C_UNK B_003E142C;

void Spire_AddLoHierarchy(s32 arg0) {
    AddLoHierarchy();
    AppendDlEntry(&B_003E142C, arg0);
}
