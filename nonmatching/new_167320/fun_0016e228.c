#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS();                         /* extern */
M2C_UNK AddVifFlusha__4VIFS(s32);                   /* extern */
M2C_UNK AddVifMscal__4VIFSPv(s32, M2C_UNK);         /* extern */
M2C_UNK EndDmaCnt__4DMAS(s32);                      /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK memset(s32, M2C_UNK, M2C_UNK);              /* extern */

void func_0016E228(s32 arg0) {
    M2C_UNK sp0;
    AddDmaCnt__4DMAS();
    UnpackHelper__4VIFS3UPKiiPiPPUi(arg0, 0xD, 0xB, 0xA);
    memset(sp0, 0, 0x58);
    AddVifMscal__4VIFSPv(arg0, 0x3AB0);
    AddVifFlusha__4VIFS(arg0);
    EndDmaCnt__4DMAS(arg0);
}
