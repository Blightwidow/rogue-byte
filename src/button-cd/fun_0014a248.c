#include "m2c_macros.h"

M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(void *, M2C_UNK);            /* extern */
M2C_UNK func_0014AE38(void *, M2C_UNK);             /* extern */
M2C_UNK func_001FEEA0(M2C_UNK *);                   /* extern */
extern M2C_UNK B_003DD040;

void func_0014A248(void *arg0) {
    Goal_Deactivate();
    func_0014AE38(arg0, -1);
    RemoveGuardSgs(M2C_FIELD(arg0, void **, 0x10), 0x24);
    func_001FEEA0(&B_003DD040);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x4A4) = 1;
}
