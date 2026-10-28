#include "m2c_macros.h"

M2C_UNK RemoveSwGrfEntry(M2C_UNK *, s32);           /* extern */
extern M2C_UNK B_003DD490;

void RemoveAloHierarchy(s32 arg0) {
    RemoveSwGrfEntry(&B_003DD490, arg0);
}
