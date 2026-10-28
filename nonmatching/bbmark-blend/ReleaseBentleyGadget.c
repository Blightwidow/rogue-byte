#include "m2c_macros.h"

s32 FGadgetObjKept(void *);                         /* extern */
M2C_UNK UnlockLeaseOfPlo(s32, void *);              /* extern */
M2C_UNK func_0018D698(void *, void *, void *);      /* extern */

void ReleaseBentleyGadget(void *arg0) {
    if (FGadgetObjKept(M2C_FIELD(arg0, void **, 0x186C)) != 0) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x186C), void **, 0x16C) = arg0;
        func_0018D698(arg0, M2C_FIELD(arg0, void **, 0x16B4), M2C_FIELD(arg0, void **, 0x186C));
    }
    UnlockLeaseOfPlo(M2C_FIELD(M2C_FIELD(arg0, void **, 0x16B4), s32 *, 4), M2C_FIELD(arg0, void **, 0x186C));
    M2C_FIELD(arg0, void **, 0x16B4) = NULL;
    M2C_FIELD(arg0, void **, 0x186C) = NULL;
}
