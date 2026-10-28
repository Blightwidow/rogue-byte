#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK func_001D8A38(void *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK RO_002A8A78;

s32 NEpisodeBest(void) {
    char sp[0x400];
    M2C_UNK sp4;
    func_001D8A38(sp, &RO_002A8A78, 0);
    CRef_Destruct(sp);
    return sp4;
}
