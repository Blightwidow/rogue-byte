#include "m2c_macros.h"

M2C_UNK ResetSlotheap(M2C_UNK *, s32 *, s32 *);     /* extern */
extern s32 B_002DD280;
extern s32 B_002DD284;
extern s32 B_002DD288;
extern s32 B_002DD28C;
extern M2C_UNK B_004520A8;

void ResetPairHeap(void) {
    B_002DD280 = 0;
    B_002DD288 = 0;
    B_002DD28C = 0;
    B_002DD284 = 0;
    ResetSlotheap(&B_004520A8, &B_002DD28C, &B_002DD284);
}
