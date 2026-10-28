#include "m2c_macros.h"

M2C_UNK AddBootQueueCardCheck(void *);              /* extern */
M2C_UNK AddBootQueueLevel(void *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddBootQueueMovie(M2C_UNK *);               /* extern */
M2C_UNK RunNextBootQueueEntry(void *);              /* extern */
extern M2C_UNK RO_002A3868;
extern M2C_UNK RO_002A38A8;

void StartBootQueue(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C4) = 0;
    AddBootQueueMovie(&RO_002A3868);
    AddBootQueueCardCheck(arg0);
    AddBootQueueLevel(arg0, &RO_002A38A8, 0x189, 1);
    RunNextBootQueueEntry(arg0);
}
