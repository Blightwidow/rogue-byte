#include "m2c_macros.h"

void *PdcbAllocSw(M2C_UNK *);                       /* extern */
extern M2C_UNK B_003DD490;

void func_001A5D58(void *arg0) {
    void *temp_v0;

    temp_v0 = PdcbAllocSw(&B_003DD490);
    M2C_FIELD(temp_v0, void **, 8) = (void *) M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(arg0, void **, 0x34) = temp_v0;
}
