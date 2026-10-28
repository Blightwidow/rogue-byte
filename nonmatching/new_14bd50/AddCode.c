#include "m2c_macros.h"

M2C_UNK AppendSlEntry(s32, void *);                 /* extern */
s32 FFindSlEntry();                                 /* extern */
extern s32 B_002E0CB4;

void AddCode(s32 arg0, void *arg1) {
    if (FFindSlEntry() == 0) {
        AppendSlEntry(arg0, arg1);
        if (*M2C_FIELD(arg1, s32 **, 0) != B_002E0CB4) {
            M2C_FIELD(arg1, s32 *, 0x10) = 0;
            return;
        }
        M2C_FIELD(arg1, s32 *, 0x10) = 1;
    }
}
