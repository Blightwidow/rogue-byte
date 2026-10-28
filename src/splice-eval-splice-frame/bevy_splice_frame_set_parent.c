#include "m2c_macros.h"

M2C_UNK CFramePtr_Assign(void *);                   /* extern */

void bevy_splice_frame_set_parent(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = 1;
    CFramePtr_Assign(arg0 + 0xC);
}
