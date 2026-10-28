#include "m2c_macros.h"

M2C_UNK LoadStepFromBrx();                          /* extern */
M2C_UNK SetSoProperties(s32, M2C_UNK, M2C_UNK *);   /* extern */
extern M2C_UNK D_002BC390;

void LoadBentleyFromBrx(s32 arg0) {
    LoadStepFromBrx();
    SetSoProperties(arg0, 0x76, &D_002BC390);
}
