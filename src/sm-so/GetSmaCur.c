#include "m2c_macros.h"

M2C_UNK OidFromSmIsms(s32, s32);                    /* extern */

void GetSmaCur(void *arg0) {
    OidFromSmIsms(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x34));
}
