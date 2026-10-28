#include "m2c_macros.h"

M2C_UNK AdvanceAfterJobEnd(void *);                 /* extern */
M2C_UNK PublishJobEnd(void *);                      /* extern */
M2C_UNK SetJobEndSequence(M2C_UNK);                 /* extern */

void BeginJobComplete(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xB8) != 0) {
        SetJobEndSequence(1);
        return;
    }
    PublishJobEnd(arg0);
    AdvanceAfterJobEnd(arg0);
}
