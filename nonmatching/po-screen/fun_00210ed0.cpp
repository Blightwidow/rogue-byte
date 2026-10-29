#include "m2c_macros.h"
extern "C" {

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK RefGetGameSaveValue(void *, s32 *, M2C_UNK *); /* extern */
M2C_UNK sprintf(s32, M2C_UNK *, s32);               /* extern */
extern M2C_UNK B_003D4A60;
extern M2C_UNK RO_002A8AA0;

void func_00210ED0(s32 arg0, s32 **arg1) {
    char sp[0x20];
    M2C_UNK sp4;
    s32 *temp_a1;

    temp_a1 = *arg1;
    if ((temp_a1 != NULL) && (*temp_a1 != 0)) {
        RefGetGameSaveValue(sp, temp_a1, &B_003D4A60);
        CRef_Destruct(sp);
        sprintf(arg0, &RO_002A8AA0, sp4);
    }
}
}
