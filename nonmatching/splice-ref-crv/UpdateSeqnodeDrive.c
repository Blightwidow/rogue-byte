#include "m2c_macros.h"

s32 FSeqnodeRecordDone(void *);                     /* extern */
M2C_UNK SetSeqnodeDrive(void *, M2C_UNK, M2C_UNK);  /* extern */

void UpdateSeqnodeDrive(void *arg0) {
    s32 var_a1;
    void *temp_a0;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x40);
    if ((temp_a1 != NULL) && (FSeqnodeRecordDone(temp_a1) != 0)) {
        temp_a0 = M2C_FIELD(arg0, void **, 0x40);
        var_a1 = 1;
        if (M2C_FIELD(temp_a0, s32 *, 0) == 0x1D) {
            var_a1 = ~M2C_FIELD(temp_a0, s32 *, 0x10) == 0;
        }
        if (var_a1 != 0) {
            SetSeqnodeDrive(arg0, 0, 0);
        }
    }
}
