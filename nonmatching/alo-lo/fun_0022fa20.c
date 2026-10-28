#include "m2c_macros.h"

M2C_UNK AddAloToRenderTree(void *);                 /* extern */
M2C_UNK ReinsertSwRoot(M2C_UNK *, s32);             /* extern */
M2C_UNK RemoveAloFromRenderTree(void *);            /* extern */
extern M2C_UNK B_003DD490;

void func_0022FA20(void *arg0) {
    s32 temp_a0;

    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x140);
        if ((temp_a0 != -1) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s32 *, 0xA4) != temp_a0)) {
            RemoveAloFromRenderTree(arg0);
            AddAloToRenderTree(arg0);
        }
        if (M2C_FIELD(arg0, s32 *, 0x10) == 0) {
            ReinsertSwRoot(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x14));
        }
    }
}
