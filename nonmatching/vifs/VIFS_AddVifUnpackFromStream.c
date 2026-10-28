#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Read_thunk(s32, s32, s32); /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(M2C_UNK);   /* extern */

void VIFS_AddVifUnpackFromStream(s32 arg3) {
    M2C_UNK sp0;
    s32 sp4;

    UnpackHelper__4VIFS3UPKiiPiPPUi(M2C_ERROR(/* Read from unset register $t0 */));
    CBinaryInputStream_Read_thunk(arg3, sp0, sp4);
}
