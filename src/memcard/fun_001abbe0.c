#include "m2c_macros.h"

M2C_UNK BusyMenu_Hide(M2C_UNK *);                   /* extern */
s32 CheckCardStatus();                              /* extern */
M2C_UNK MemcardMenu_SetState(M2C_UNK *, M2C_UNK);   /* extern */
s32 WriteSaveSlot(void *, s32);                     /* extern */
M2C_UNK func_001ACC38(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK B_002E6550;
extern M2C_UNK B_002E65A0;

s32 func_001ABBE0(void *arg0) {
    s32 var_s1;

    var_s1 = CheckCardStatus();
    if ((var_s1 != 0) || (var_s1 = WriteSaveSlot(arg0, M2C_FIELD(arg0, s32 *, 0xFD50)), (var_s1 != 0))) {
        func_001ACC38(&B_002E6550, 3);
        MemcardMenu_SetState(&B_002E6550, 0x23);
        BusyMenu_Hide(&B_002E65A0);
    }
    return var_s1;
}
