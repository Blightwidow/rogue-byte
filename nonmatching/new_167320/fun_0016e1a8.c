#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS(s32);                      /* extern */
M2C_UNK AddVifMscal__4VIFSPv(s32, M2C_UNK);         /* extern */
M2C_UNK EndDmaCnt__4DMAS(s32);                      /* extern */
M2C_UNK EnsureVu1Code__FP4VIFSPvT1(M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK memset(s32, M2C_UNK, M2C_UNK);              /* extern */
extern M2C_UNK RO_0025E680;
extern M2C_UNK RO_00262320;

void func_0016E1A8(s32 arg0) {
    M2C_UNK sp0;
    EnsureVu1Code__FP4VIFSPvT1(&RO_0025E680, &RO_00262320);
    AddDmaCnt__4DMAS(arg0);
    UnpackHelper__4VIFS3UPKiiPiPPUi(arg0, 0xD, 0xB, 0xA);
    memset(sp0, 0, 0x58);
    AddVifMscal__4VIFSPv(arg0, 0);
    EndDmaCnt__4DMAS(arg0);
}
