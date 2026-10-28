#include "m2c_macros.h"

M2C_UNK CRef_AddRef(void *);                        /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */

void *__as__4CRefRC4CRef(void *arg0, void *arg1) {
    CRef_AddRef(arg1);
    CRef_Destruct(arg0);
    M2C_FIELD(arg0, s32 *, 0) = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg1, s32 *, 4);
    return arg0;
}
