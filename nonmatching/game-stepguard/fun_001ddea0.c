#include "m2c_macros.h"

s32 PchzStringFromId(M2C_UNK *, s32, s32);          /* extern */
M2C_UNK strcpy(s32, s32);                           /* extern */
extern M2C_UNK B_003DA3C0;
extern M2C_UNK B_003DD490;

void func_001DDEA0(s32 arg0, s32 arg1) {
    s32 temp_a2;

    if (arg1 < M2C_FIELD(&B_003DA3C0, s32 *, 0x48)) {
        temp_a2 = arg1 * 0xC;
        strcpy(arg0, PchzStringFromId(&B_003DD490, M2C_FIELD(M2C_FIELD((temp_a2 + &B_003DA3C0), void **, 0x4C), s32 *, 0x6C), temp_a2));
    }
}
