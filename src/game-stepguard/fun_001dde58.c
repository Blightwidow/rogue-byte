#include "m2c_macros.h"

s32 PchzStringFromId(M2C_UNK *, s32);               /* extern */
M2C_UNK strcpy(s32, s32);                           /* extern */
extern void *B_003DA4D0;
extern M2C_UNK B_003DD490;

void func_001DDE58(s32 arg0) {
    if (B_003DA4D0 != NULL) {
        strcpy(arg0, PchzStringFromId(&B_003DD490, M2C_FIELD(B_003DA4D0, s32 *, 0x6C)));
    }
}
