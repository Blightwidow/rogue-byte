#include "m2c_macros.h"

M2C_UNK AddDirectPacket(s32, M2C_UNK, M2C_UNK *);   /* extern */
M2C_UNK func_0016E228();                            /* extern */
extern M2C_UNK B_002DF010;
extern s32 B_003DCFA0;

void func_0016E380(s32 arg0) {
    func_0016E228();
    if (B_003DCFA0 > 0) {
        AddDirectPacket(arg0, 0x25, &B_002DF010);
    }
}
