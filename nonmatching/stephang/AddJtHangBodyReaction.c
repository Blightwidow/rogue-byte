#include "m2c_macros.h"

M2C_UNK AddSoAcceleration(s32, s128);               /* extern */
M2C_UNK AddSoAngularAcceleration(s32, s128);        /* extern */

void AddJtHangBodyReaction(void *arg0) {
    AddSoAcceleration(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1900), s32 *, 4), M2C_FIELD(arg0, s128 *, 0x1930));
    AddSoAngularAcceleration(M2C_FIELD(M2C_FIELD(arg0, void **, 0x1900), s32 *, 4), M2C_FIELD(arg0, s128 *, 0x1940));
}
