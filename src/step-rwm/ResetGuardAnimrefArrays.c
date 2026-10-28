#include "m2c_macros.h"

void ResetAnimrefArray();                /* extern */

void ResetGuardAnimrefArrays(s32 arg0) {
    ResetAnimrefArray(arg0, arg0 + 0xC10);
    ResetAnimrefArray(arg0, arg0 + 0x8D0);
    ResetAnimrefArray(arg0, arg0 + 0xA70);
}
