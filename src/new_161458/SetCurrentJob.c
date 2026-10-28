#include "m2c_macros.h"

s32 FIsCurrentJob();                                /* extern */
M2C_UNK StartJob(s32);                              /* extern */
M2C_UNK StopJobIfCurrent(s32);                      /* extern */
extern s32 B_003E0F9C;

void SetCurrentJob(s32 arg0) {
    if (FIsCurrentJob() == 0) {
        if (B_003E0F9C != 0) {
            StopJobIfCurrent(B_003E0F9C);
        }
        StartJob(arg0);
    }
}
