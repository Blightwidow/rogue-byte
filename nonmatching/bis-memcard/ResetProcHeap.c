#include "m2c_macros.h"

M2C_UNK ResetSlotheap(M2C_UNK *, s32 *, s32 *);     /* extern */
extern s32 B_002DD2B0;
extern s32 B_002DD2B4;
extern s32 B_002DD2B8;
extern s32 B_002DD2BC;
extern M2C_UNK B_00452120;

void ResetProcHeap(void) {
    B_002DD2B0 = 0;
    B_002DD2B8 = 0;
    B_002DD2BC = 0;
    B_002DD2B4 = 0;
    ResetSlotheap(&B_00452120, &B_002DD2BC, &B_002DD2B4);
}
