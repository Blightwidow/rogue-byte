#include "m2c_macros.h"

void *PvAllocSlotheapImpl(M2C_UNK *);               /* extern */
extern M2C_UNK B_003E1144;

void SubscribeRipObject(void *arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = PvAllocSlotheapImpl(&B_003E1144);
    M2C_FIELD(temp_v0, s32 *, 0) = arg1;
    M2C_FIELD(temp_v0, void **, 8) = (void *) M2C_FIELD(arg0, void **, 0xE8);
    M2C_FIELD(arg0, void **, 0xE8) = temp_v0;
}
