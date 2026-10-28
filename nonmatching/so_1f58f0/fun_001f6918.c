#include "m2c_macros.h"

M2C_UNK RecalcSwOxfFilterForObject(M2C_UNK *, void *, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void func_001F6918(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s64 *, 0x148) = (s64) ((M2C_FIELD(arg0, s64 *, 0x148) & 0xFBFFFFFF) | ((arg1 & 1) << 0x1A));
    RecalcSwOxfFilterForObject(&B_003DD490, arg0, 0xFBFFFFFF);
}
