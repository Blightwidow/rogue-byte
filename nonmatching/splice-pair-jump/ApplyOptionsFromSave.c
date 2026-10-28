#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK RefGetGameSaveValue(void *, s32, s32);      /* extern */
M2C_UNK SetSndPlaybackMode(M2C_UNK *, f32);         /* extern */
M2C_UNK SetSndbankVolumeFactor(M2C_UNK *, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_001A2BD0(f32);                         /* extern */
s32 func_001A2C98();                                /* extern */
s32 func_0023E1C8(f32);                             /* extern */
extern M2C_UNK B_002DEB80;
extern M2C_UNK B_003DD040;
extern f32 B_003DD050;
extern M2C_UNK B_003DD490;

void ApplyOptionsFromSave(s32 arg0) {
    char sp[0x400];
    M2C_UNK sp4;
    s32 temp_a2;
    s64 temp_a1;

    if (M2C_FIELD(&B_003DD490, s32 *, 0x3B2C) != 0) {
        if (func_001A2C98() >= 2) {
            RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B2C), arg0);
            CRef_Destruct(sp);
            func_001A2BD0(sp4);
        }
    }
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3B30) != 0) {
        RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B30), arg0);
        CRef_Destruct(sp);
        SetSndPlaybackMode(&B_003DD040, sp4);
    }
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3B34) != 0) {
        RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B34), arg0);
        CRef_Destruct(sp);
        SetSndbankVolumeFactor(&B_003DD040, 1, 1, 1.0f - sp4);
    }
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3B38) != 0) {
        RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B38), arg0);
        CRef_Destruct(sp);
        SetSndbankVolumeFactor(&B_003DD040, 0, 1, 1.0f - sp4);
        RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B38), arg0);
        CRef_Destruct(sp);
        SetSndbankVolumeFactor(&B_003DD040, 3, 1, 1.0f - sp4);
    }
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3B3C) != 0) {
        RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B3C), arg0);
        CRef_Destruct(sp);
        B_003DD050 = sp4;
    }
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3B40) != 0) {
        RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B40), arg0);
        CRef_Destruct(sp);
        temp_a2 = func_0023E1C8(sp4 + 636.0f) & 0xFFF;
        M2C_FIELD(&B_002DEB80, s64 *, 0x40) = (s64) ((M2C_FIELD(&B_002DEB80, s64 *, 0x40) & ~0xFFF) | temp_a2);
        M2C_FIELD(&B_002DEB80, s64 *, 0x18) = (s64) ((M2C_FIELD(&B_002DEB80, s64 *, 0x18) & ~0xFFF) | temp_a2);
    }
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3B44) != 0) {
        RefGetGameSaveValue(sp, M2C_FIELD(&B_003DD490, s32 *, 0x3B44), arg0);
        CRef_Destruct(sp);
        temp_a1 = func_0023E1C8(sp4 + 50.0f) & 0x7FE;
        M2C_FIELD(&B_002DEB80, s64 *, 0x40) = (s64) ((M2C_FIELD(&B_002DEB80, s64 *, 0x40) & 0xFF800FFF) | (temp_a1 << 0xC));
        M2C_FIELD(&B_002DEB80, s64 *, 0x18) = (s64) ((M2C_FIELD(&B_002DEB80, s64 *, 0x18) & 0xFF800FFF) | (temp_a1 << 0xC));
    }
}
