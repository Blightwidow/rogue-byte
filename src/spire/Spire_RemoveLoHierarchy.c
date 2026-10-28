#include "m2c_macros.h"

M2C_UNK RemoveDlEntry(M2C_UNK *, s32);              /* extern */
M2C_UNK RemoveLoHierarchy();                        /* extern */
extern M2C_UNK B_003E142C;

void Spire_RemoveLoHierarchy(s32 arg0) {
    RemoveLoHierarchy();
    RemoveDlEntry(&B_003E142C, arg0);
}
