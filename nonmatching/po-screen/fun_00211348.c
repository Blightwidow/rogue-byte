#include "m2c_macros.h"

s32 PchzStringFromId(M2C_UNK *, s32, void *);       /* extern */
M2C_UNK strcpy(s32, s32);                           /* extern */
extern M2C_UNK B_003DD490;

void func_00211348(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_a2;

    temp_a2 = arg2 + (arg1 * 4);
    strcpy(arg0, PchzStringFromId(&B_003DD490, M2C_FIELD(temp_a2, s32 *, 0xCC), temp_a2));
}
