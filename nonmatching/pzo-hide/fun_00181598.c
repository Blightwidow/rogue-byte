#include "m2c_macros.h"

M2C_UNK TriggerRsmg(M2C_UNK *, s32, void *, void *); /* extern */
M2C_UNK func_0017F6B0();                            /* extern */
M2C_UNK func_001815E8(void *, M2C_UNK);             /* extern */
extern M2C_UNK B_003DD490;

void func_00181598(void *arg0) {
    func_0017F6B0();
    func_001815E8(arg0, 0);
    TriggerRsmg(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x200), arg0 + 0x204, arg0);
}
