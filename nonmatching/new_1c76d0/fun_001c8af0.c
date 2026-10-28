#include "m2c_macros.h"

M2C_UNK ShowClueBlot(M2C_UNK *);                    /* extern */
M2C_UNK StartStream(M2C_UNK *, s32, M2C_UNK);       /* extern */
M2C_UNK func_001C8730(void *, M2C_UNK);             /* extern */
extern M2C_UNK B_003DD040;
extern M2C_UNK B_003DD490;

void func_001C8AF0(void *arg0, s32 arg1) {
    s32 temp_a1;

    if (M2C_FIELD(&B_003DD490, s32 *, 0x4764) >= M2C_FIELD(&B_003DD490, s32 *, 0x4768)) {
        M2C_FIELD(arg0, s32 *, 0x190) = arg1;
        func_001C8730(arg0, 1);
        return;
    }
    ShowClueBlot(&B_003DD490);
    temp_a1 = M2C_FIELD(arg0, s32 *, 0x1F8);
    if (temp_a1 != -1) {
        StartStream(&B_003DD040, temp_a1, 1);
    }
}
