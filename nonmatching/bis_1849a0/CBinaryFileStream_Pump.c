#include "m2c_macros.h"

M2C_UNK CBinaryFileStream_PumpFile();               /* extern */
M2C_UNK PumpCd__18CBinaryInputStream();             /* extern */

void CBinaryFileStream_Pump(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x3C) < 0) {
        if (M2C_FIELD(arg0, s32 *, 0x50) < 0) {
            M2C_FIELD(arg0, s32 *, 0x14) = 0;
            M2C_FIELD(arg0, s32 *, 0x10) = 0;
            return;
        }
        PumpCd__18CBinaryInputStream();
        return;
    }
    CBinaryFileStream_PumpFile();
}
