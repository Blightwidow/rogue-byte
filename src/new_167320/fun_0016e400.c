#include "m2c_macros.h"

M2C_UNK AddDirectPacket(s32, M2C_UNK, M2C_UNK *);   /* extern */
M2C_UNK func_0016E228();                            /* extern */
extern M2C_UNK B_002DF720;

void func_0016E400(s32 arg0) {
    func_0016E228();
    AddDirectPacket(arg0, 2, &B_002DF720);
}
