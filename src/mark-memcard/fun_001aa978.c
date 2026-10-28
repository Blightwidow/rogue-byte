#include "m2c_macros.h"

M2C_UNK InitSave(M2C_UNK *, M2C_UNK, M2C_UNK);      /* extern */
M2C_UNK JobMgr_Construct(M2C_UNK *);                /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_002E65E0;
extern s32 B_004425D8;

void func_001AA978(void) {
    JobMgr_Construct(&B_002DEB30);
    B_004425D8 = -1;
    InitSave(&B_002E65E0, 0, 0);
}
