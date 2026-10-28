#include "m2c_macros.h"

M2C_UNK ResetSlotheap(M2C_UNK *, s32 *, s32 *);     /* extern */
extern s32 B_002DD2A0;
extern s32 B_002DD2A4;
extern s32 B_002DD2A8;
extern s32 B_002DD2AC;
extern M2C_UNK B_004520F8;

void ResetFrameHeap(void) {
    B_002DD2A0 = 0;
    B_002DD2A8 = 0;
    B_002DD2AC = 0;
    B_002DD2A4 = 0;
    ResetSlotheap(&B_004520F8, &B_002DD2AC, &B_002DD2A4);
}
