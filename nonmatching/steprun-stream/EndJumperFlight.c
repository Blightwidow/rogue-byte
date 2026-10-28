#include "m2c_macros.h"

M2C_UNK RecalcSwOxfFilterForObject(M2C_UNK *, void *); /* extern */
M2C_UNK SetXfKind(void *, s32, M2C_UNK);            /* extern */
M2C_UNK func_0012E460(void *);                      /* extern */
extern M2C_UNK B_003DD490;

void EndJumperFlight(void *arg0) {
    void *temp_a0;
    void *temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        M2C_FIELD(arg0, s32 *, 0x60) = 0;
        if (M2C_FIELD(arg0, s32 *, 0x68) != 0) {
            func_0012E460(arg0 + 0x68);
            temp_a0 = M2C_FIELD(arg0, void **, 0x34);
            SetXfKind(temp_a0, M2C_FIELD(temp_a0, s32 *, 0x58), 2);
            temp_v1 = M2C_FIELD(arg0, void **, 0x34);
            M2C_FIELD(temp_v1, s64 *, 0x148) = (s64) (M2C_FIELD(temp_v1, s64 *, 0x148) & 0xFBFFFFFF);
            RecalcSwOxfFilterForObject(&B_003DD490, M2C_FIELD(arg0, void **, 0x34));
        }
    }
}
