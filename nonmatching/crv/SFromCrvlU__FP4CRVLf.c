#include "m2c_macros.h"

f32 GetSuck();                                      /* extern */

s32 SFromCrvlU__FP4CRVLf(void *arg0, s32 arg1) {
    return M2C_BITWISE(s32, (GetSuck() * M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), f32 *, 0x24)));
}
