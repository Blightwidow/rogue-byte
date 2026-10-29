#include "sly2.h"
#include "m2c_macros.h"
s32 CheckCardStatus(s8 *);
s32 CreateSaveDirectory(s8 *);
s32 InitAndWriteSaveSlot(s8 *, s32);
void func_001ACC38(M2C_UNK *, M2C_UNK);
extern M2C_UNK B_002E6550;

s32 func_001ABC68(s8 *arg0)
{
    s32 result = CheckCardStatus(arg0);
    if (result == 0) {
        result = CreateSaveDirectory(arg0);
        if (result == 0) {
            result = InitAndWriteSaveSlot(arg0, *(s32 *)(arg0 + 0xFD58));
        }
    }
    if (result != 0) {
        func_001ACC38(&B_002E6550, 3);
    }
    return result;
}
