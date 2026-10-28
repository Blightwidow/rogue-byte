#include "m2c_macros.h"

extern M2C_UNK B_002DE9F0;

void CFontBrx_Register(s32 *arg0) {
    *((*arg0 * 4) + &B_002DE9F0) = arg0;
}
