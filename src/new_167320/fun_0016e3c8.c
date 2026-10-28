#include "m2c_macros.h"

M2C_UNK AddDirectPacket(s32, M2C_UNK, M2C_UNK *);   /* extern */
M2C_UNK func_0016E1A8();                            /* extern */
extern M2C_UNK B_002DF700;

void func_0016E3C8(s32 arg0) {
    func_0016E1A8();
    AddDirectPacket(arg0, 2, &B_002DF700);
}
