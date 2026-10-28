#include "m2c_macros.h"

M2C_UNK RemoveAloHierarchy();                       /* extern */
M2C_UNK RemoveLightFromSw(M2C_UNK *, s32);          /* extern */
extern M2C_UNK B_003DD490;

void OnLightRemove(s32 arg0) {
    RemoveAloHierarchy();
    RemoveLightFromSw(&B_003DD490, arg0);
}
