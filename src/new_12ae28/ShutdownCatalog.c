#include "m2c_macros.h"

M2C_UNK ResetFrameHeap();                           /* extern */
M2C_UNK ResetPairHeap();                            /* extern */
M2C_UNK ResetProcHeap();                            /* extern */
M2C_UNK ResetSidebagHeap();                         /* extern */
M2C_UNK ResetSlotheap(M2C_UNK *);                   /* extern */
M2C_UNK ResetVarbHeap();                            /* extern */
M2C_UNK func_00257FC8();                            /* extern */
extern M2C_UNK B_00452188;
extern M2C_UNK B_004521A0;
extern M2C_UNK B_004521B8;
extern M2C_UNK B_004521D0;
extern M2C_UNK B_004521E8;
extern s32 g_2dd5b8;

void ShutdownCatalog(void) {
    g_2dd5b8 = 0;
    ResetPairHeap();
    ResetFrameHeap();
    ResetVarbHeap();
    ResetProcHeap();
    ResetSidebagHeap();
    func_00257FC8();
    ResetSlotheap(&B_00452188);
    ResetSlotheap(&B_004521A0);
    ResetSlotheap(&B_004521B8);
    ResetSlotheap(&B_004521D0);
    ResetSlotheap(&B_004521E8);
}
