#include "m2c_macros.h"

M2C_UNK AppendDlEntry(M2C_UNK *, void *);           /* extern */
M2C_UNK func_001F3EA8();                            /* extern */
extern M2C_UNK B_003E1444;

void AddStepguardHierarchy(void *arg0) {
    func_001F3EA8();
    AppendDlEntry(&B_003E1444, arg0);
    M2C_FIELD(arg0, f32 *, 0xFF8) = 3.4028235e38f;
}
