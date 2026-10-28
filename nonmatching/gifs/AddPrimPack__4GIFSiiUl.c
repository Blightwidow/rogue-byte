#include "m2c_macros.h"

void AddPrimPack__4GIFSiiUl(void *arg0, s64 arg1, s64 arg2, s64 arg3) {
    void *temp_v1;
    void *temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK), 0xC)(arg0 + M2C_FIELD(temp_v1, s16 *, 8), 0);
    temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, void **, 0xC) = (void *) (temp_v1_2 + 0x10);
    M2C_FIELD(temp_v1_2, s64 *, 0) = (s64) ((arg1 << 0x2F) | ((arg2 << 0x3C) | (0x8000 << 0x1F)));
    M2C_FIELD(temp_v1_2, s64 *, 8) = arg3;
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) arg2;
    M2C_FIELD(arg0, void **, 0x1C) = temp_v1_2;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
}
