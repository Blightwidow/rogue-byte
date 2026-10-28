#include "m2c_macros.h"

M2C_UNK AddPrimPack__4GIFSiiUl(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void AddPrimEnd__4GIFS(void *arg0) {
    void *temp_v0;
    void *temp_v0_2;

    if (M2C_FIELD(arg0, s32 *, 0x1C) != 0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x18);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8), 1);
        return;
    }
    AddPrimPack__4GIFSiiUl(arg0, 0, 1, 0xE);
    temp_v0_2 = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK), 0xC)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 8), 1);
}
