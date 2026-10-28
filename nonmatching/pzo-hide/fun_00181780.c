#include "m2c_macros.h"

M2C_UNK TriggerRsmg(M2C_UNK *, s32, s32, void *);   /* extern */
extern M2C_UNK B_003DD490;

void func_00181780(void *arg0) {
    void *temp_v1;

    TriggerRsmg(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x200), arg0 + 0x204, arg0);
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 5, 0, 0);
}
