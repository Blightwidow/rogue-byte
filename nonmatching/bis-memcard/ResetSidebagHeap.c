#include "m2c_macros.h"

M2C_UNK ResetSlotheap(M2C_UNK *, s32 *, s32 *);     /* extern */
extern s32 B_002DD2C0;
extern s32 B_002DD2C4;
extern s32 B_002DD2C8;
extern s32 B_002DD2CC;
extern M2C_UNK B_00452148;

void ResetSidebagHeap(void) {
    B_002DD2C0 = 0;
    B_002DD2C8 = 0;
    B_002DD2CC = 0;
    B_002DD2C4 = 0;
    ResetSlotheap(&B_00452148, &B_002DD2CC, &B_002DD2C4);
}
