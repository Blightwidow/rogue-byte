#include "m2c_macros.h"

M2C_UNK func_001A4478(M2C_UNK *, M2C_UNK, void *);  /* extern */
extern M2C_UNK B_003DD490;

void func_001F3C10(void *arg0) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 0x134);
    if ((temp_a2 != NULL) && (M2C_FIELD(temp_a2, s32 *, 0xC) != M2C_FIELD(&B_003DD490, s32 *, 0x3D60))) {
        func_001A4478(&B_003DD490, 0, temp_a2);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x134), s32 *, 0xC) = (s32) M2C_FIELD(&B_003DD490, s32 *, 0x3D60);
    }
}
