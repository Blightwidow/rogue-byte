#include "m2c_macros.h"

s32 FIsCurrentJob();                                /* extern */
M2C_UNK StopJob(s32);                               /* extern */

void StopJobIfCurrent(s32 arg0) {
    if (FIsCurrentJob() != 0) {
        StopJob(arg0);
    }
}
