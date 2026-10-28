#include "m2c_macros.h"

M2C_UNK ResetSlotheap(M2C_UNK *, s32 *, s32 *);     /* extern */
extern s32 B_002DD290;
extern s32 B_002DD294;
extern s32 B_002DD298;
extern s32 B_002DD29C;
extern M2C_UNK B_004520D0;

void ResetVarbHeap(void) {
    B_002DD290 = 0;
    B_002DD298 = 0;
    B_002DD29C = 0;
    B_002DD294 = 0;
    ResetSlotheap(&B_004520D0, &B_002DD29C, &B_002DD294);
}
