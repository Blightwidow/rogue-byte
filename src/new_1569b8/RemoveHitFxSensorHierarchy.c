#include "m2c_macros.h"

M2C_UNK RemoveDlEntry(M2C_UNK *, s32);              /* extern */
M2C_UNK RemoveLoHierarchy();                        /* extern */
M2C_UNK SweepHitFxSensor(s32, M2C_UNK);             /* extern */
extern M2C_UNK B_003E1468;

void RemoveHitFxSensorHierarchy(s32 arg0) {
    RemoveLoHierarchy();
    SweepHitFxSensor(arg0, 1);
    RemoveDlEntry(&B_003E1468, arg0);
}
