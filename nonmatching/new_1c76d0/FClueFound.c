#include "m2c_macros.h"

M2C_UNK CRef_Destruct();                   /* extern */
M2C_UNK CStackFrame_Construct();              /* extern */
M2C_UNK CStackFrame_Destructor(); /* extern */
s32 PpathClueFlag();                             /* extern */
M2C_UNK RefGetGameSaveValue(); /* extern */
extern M2C_UNK B_003D4A60;

s32 FClueFound(s32 arg0) {
    char sp[0x400];
    M2C_UNK sp14;
    M2C_UNK sp10;
    s32 temp_v0;

    CStackFrame_Construct(sp);
    temp_v0 = PpathClueFlag(arg0);
    if (temp_v0 != 0) {
        RefGetGameSaveValue(&sp10, temp_v0, &B_003D4A60);
        CRef_Destruct(&sp10);
        CStackFrame_Destructor(sp, 2);
        return sp14;
    }
    CStackFrame_Destructor(sp, 2, &B_003D4A60);
    return 0;
}
