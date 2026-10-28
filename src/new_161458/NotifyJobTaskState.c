#include "m2c_macros.h"

M2C_UNK ActivateJobOfTask(void *);                  /* extern */
M2C_UNK BeginJobComplete(void *);                   /* extern */
s32 FJobRunning();                                  /* extern */
M2C_UNK SetSwRestartTask(M2C_UNK *, void *);        /* extern */
extern M2C_UNK B_003DD490;

void NotifyJobTaskState(void *arg0, void *arg1) {
    if (FJobRunning() != 0) {
        if (arg1 == M2C_FIELD(arg0, s32 *, 0x64)) {
            ActivateJobOfTask(arg0);
        }
        if (arg1 == M2C_FIELD(arg0, s32 *, 0x68)) {
            BeginJobComplete(arg0);
        }
        if (M2C_FIELD(arg1, s32 *, 0xB8) != -1) {
            SetSwRestartTask(&B_003DD490, arg1);
        }
    }
}
