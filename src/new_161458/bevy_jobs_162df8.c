#include "m2c_macros.h"

M2C_UNK RestartAtTask(s32);                         /* extern */
extern s32 B_003E0FA4;

void bevy_jobs_162df8(void *arg0) {
    if (B_003E0FA4 != 0) {
        RestartAtTask(B_003E0FA4);
        return;
    }
    RestartAtTask(M2C_FIELD(arg0, s32 *, 0x64));
}
