#include "m2c_macros.h"

M2C_UNK AddVifUnpackRefs__4VIFS3UPKiPviPPPv(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK g_2dded0;
extern M2C_UNK g_2dea28;

void func_0013A688(void *arg0) {
    M2C_UNK sp0;
    void *sp4;

    UnpackHelper__4VIFS3UPKiiPiPPUi(&g_2dea28, 0xC, 1, 5);
    M2C_FIELD(sp0, f32 *, 0) = (f32) M2C_FIELD(&B_002DDF40, f32 *, 0x100);
    M2C_FIELD(sp0, f32 *, 4) = (f32) M2C_FIELD(&B_002DDF40, f32 *, 0x114);
    M2C_FIELD(sp0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x440);
    M2C_FIELD(sp0, f32 *, 0xC) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0);
    UnpackHelper__4VIFS3UPKiiPiPPUi(&g_2dea28, 0xC, 1, 6);
    M2C_FIELD(sp4, s32 *, 0) = 0;
    if (M2C_FIELD(arg0, s32 *, 0x434) != 0) {
        M2C_FIELD(sp4, s32 *, 0) = (s32) (M2C_FIELD(sp4, s32 *, 0) | 1);
    }
    M2C_FIELD(sp4, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x3B0);
    M2C_FIELD(sp4, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x1A0);
    M2C_FIELD(sp4, f32 *, 0xC) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0x40);
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 0xE, M2C_FIELD(arg0, s32 *, 0x3B0), arg0 + 0x3B4);
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 8, 1, arg0 + 0x130);
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 8, 1, arg0 + 0x110);
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 8, 1, arg0 + 0x140);
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 8, 1, arg0 + 0x150);
    AddVifUnpack__4VIFS3UPKiPvi(&g_2dea28, 0xC, 4, M2C_FIELD(arg0, void **, 0x438));
    AddVifUnpackRefs__4VIFS3UPKiPviPPPv(&g_2dea28, 0xC, M2C_FIELD(arg0, s32 *, 0x1A0), arg0 + 0x1B0);
}
