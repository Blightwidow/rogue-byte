#include "m2c_macros.h"

M2C_UNK AddDmaCnt__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddDmaRet__4DMAS(M2C_UNK *);                /* extern */
M2C_UNK AddVifDirect__4VIFSiP2QWi(M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK BuildClearGifs__FP2QWG4RGBAi(M2C_UNK *, M2C_UNK *, M2C_UNK, s32); /* extern */
M2C_UNK EndDmaCnt__4DMAS(M2C_UNK *);                /* extern */
void *OnGameLoad__FP4GAME();                        /* extern */
extern f32 g_2dded0;
extern M2C_UNK g_2dea28;

void DrawFade(void *arg0, s32 arg3) {
    M2C_UNK sp41;
    M2C_UNK sp42;
    M2C_UNK sp43;
    M2C_UNK sp51;
    M2C_UNK sp52;
    M2C_UNK sp53;
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_UNK sp30;
    u8 sp40;
    u8 sp50;
    u8 sp60;
    u8 sp61;
    u8 sp62;
    u8 sp63;
    M2C_UNK sp70;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f2_2;
    s32 temp_a0;
    s32 temp_s2;
    s32 var_a3;
    s32 var_v0_5;
    u8 var_v0;
    u8 var_v0_2;
    u8 var_v0_3;
    u8 var_v0_4;
    void *temp_v0;

    var_a3 = arg3;
    temp_f2 = M2C_FIELD(arg0, f32 *, 0x5C);
    temp_f0 = g_2dded0 - M2C_FIELD(arg0, f32 *, 0x68);
    if (!(temp_f0 < temp_f2)) {
        temp_f0_2 = temp_f0 - temp_f2;
        temp_f2_2 = M2C_FIELD(arg0, f32 *, 0x60);
        if (!(temp_f0_2 < temp_f2_2)) {
            if ((temp_f0_2 - temp_f2_2) < M2C_FIELD(arg0, f32 *, 0x64)) {
                sp10 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x54));
                sp20 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x58));
            }
        } else {
            sp10 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x54));
            var_a3 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x54));
            sp20 = var_a3;
        }
    } else {
        sp10 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x50));
        sp20 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x54));
    }
    sp40 = M2C_UNALIGNED32(sp10);
    sp50 = M2C_UNALIGNED32(sp20);
    if (sp40 == sp50) {
        var_v0 = sp50;
    } else if ((s32) sp40 < (s32) sp50) {
        var_v0 = sp40 + 0x3F7FBE77;
    } else {
        var_v0 = sp50 + M2C_BITWISE(s32, (((f32) sp40 + 0.999f) - (f32) sp50));
    }
    sp60 = var_v0;
    if (sp41 == sp51) {
        var_v0_2 = sp51;
    } else if ((s32) sp41 < (s32) sp51) {
        var_v0_2 = sp41 + 0x3F7FBE77;
    } else {
        var_v0_2 = sp51 + M2C_BITWISE(s32, (((f32) sp41 + 0.999f) - (f32) sp51));
    }
    sp61 = var_v0_2;
    if (sp42 == sp52) {
        var_v0_3 = sp52;
    } else if ((s32) sp42 < (s32) sp52) {
        var_v0_3 = sp42 + 0x3F7FBE77;
    } else {
        var_v0_3 = sp52 + M2C_BITWISE(s32, (((f32) sp42 + 0.999f) - (f32) sp52));
    }
    sp62 = var_v0_3;
    if (sp43 == sp53) {
        var_v0_4 = sp53;
    } else if ((s32) sp43 < (s32) sp53) {
        var_v0_4 = sp43 + 0x3F7FBE77;
    } else {
        var_v0_4 = sp53 + M2C_BITWISE(s32, (((f32) sp43 + 0.999f) - (f32) sp53));
    }
    sp63 = var_v0_4;
    sp30 = M2C_UNALIGNED32(sp60);
    sp0 = M2C_UNALIGNED32(sp30);
    sp30 = M2C_UNALIGNED32(sp0);
    BuildClearGifs__FP2QWG4RGBAi(&sp70, &sp30, 3, var_a3);
    temp_s2 = M2C_FIELD(&g_2dea28, s32 *, 0xC);
    AddDmaCnt__4DMAS(&g_2dea28);
    AddVifDirect__4VIFSiP2QWi(&g_2dea28, 0x25, &sp70, 0);
    EndDmaCnt__4DMAS(&g_2dea28);
    AddDmaRet__4DMAS(&g_2dea28);
    temp_v0 = OnGameLoad__FP4GAME();
    M2C_FIELD(temp_v0, s32 *, 8) = temp_s2;
    M2C_FIELD(temp_v0, f32 *, 4) = -1.0f;
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x6C);
    var_v0_5 = 1;
    switch (temp_a0) {                              /* irregular */
    case 0:
block_35:
        M2C_FIELD(temp_v0, s32 *, 0) = var_v0_5;
        return;
    case 1:
        var_v0_5 = 0xE;
        goto block_35;
    }
}
