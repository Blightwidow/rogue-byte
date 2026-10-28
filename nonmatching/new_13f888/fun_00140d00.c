#include "m2c_macros.h"

M2C_UNK func_00193DE8(void *);                      /* extern */
M2C_UNK func_001991A0(void *);                      /* extern */
M2C_UNK func_0019E950(void *);                      /* extern */
M2C_UNK func_001F4FA8();                            /* extern */

void func_00140D00(void *arg0) {
    func_001F4FA8();
    if (M2C_FIELD(arg0, s32 *, 0x2DC) != -1) {
        func_001991A0(arg0 + 0x2C0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x4CC) != -1) {
        func_00193DE8(arg0 + 0x4C0);
    }
    if (M2C_FIELD(arg0, s32 *, 0xF54) != -1) {
        func_0019E950(arg0 + 0xF50);
    }
}
