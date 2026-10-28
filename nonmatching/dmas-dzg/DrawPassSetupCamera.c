#include "m2c_macros.h"

M2C_UNK AddDmaCall__4DMASP2QW();   /* extern */
M2C_UNK AddDmaCnt__4DMAS();                   /* extern */
M2C_UNK AddVifBaseOffset__4VIFSii(); /* extern */
M2C_UNK AddVifDirect__4VIFSiP2QWi(); /* extern */
M2C_UNK AddVifFlush__4VIFS();                 /* extern */
M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(); /* extern */
M2C_UNK EndDmaCnt__4DMAS();                   /* extern */
M2C_UNK bevy_camera_cm_14f768(); /* extern */
M2C_UNK func_0016E1A8();            /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DEA50;
extern M2C_UNK B_002DF010;
extern M2C_UNK B_002DF800;
extern M2C_UNK B_002DF940;
extern M2C_UNK B_002DFA80;
extern M2C_UNK B_003DD490;
extern s128 B_003E12B8;
extern M2C_UNK D_002C1F00;
extern M2C_UNK D_002C1F10;
extern s32 g_2dea4c;

void DrawPassSetupCamera(void *arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    s128 sp20;
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    s128 sp80;
    s128 sp90;
    M2C_UNK var_a1;
    f32 temp_f0;
    f32 temp_f2;
    void *temp_v0;
    void *temp_v1;

    if (M2C_FIELD(&B_003DD490, s32 *, 0x3E38) != 0) {
        if (g_2dea4c == &B_002DEA50) {
            AddDmaCall__4DMASP2QW(arg0, &B_002DF940);
        } else {
            AddDmaCall__4DMASP2QW(arg0, &B_002DFA80);
        }
    } else {
        AddDmaCall__4DMASP2QW(arg0, &B_002DF800);
    }
    M2C_FIELD(arg0, s32 *, 0x20) = 1;
    AddDmaCnt__4DMAS(arg0);
    AddVifFlush__4VIFS(arg0);
    AddVifDirect__4VIFSiP2QWi(arg0, 0x25, &B_002DF010, 0);
    AddVifBaseOffset__4VIFSii(arg0, 0, 0);
    M2C_ERROR(/* unknown instruction: ldl $a1, 0x7($t0) */);
    M2C_ERROR(/* unknown instruction: ldr $a1, ($t0) */);
    M2C_ERROR(/* unknown instruction: sdl $a1, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $a1, ($sp) */);
    temp_f0 = (M2C_FIELD(&B_002DDF40, f32 *, 0x4C) + M2C_FIELD(&B_002DDF40, f32 *, 0x50)) / (M2C_FIELD(&B_002DDF40, f32 *, 0x4C) - M2C_FIELD(&B_002DDF40, f32 *, 0x50));
    temp_f2 = M2C_FIELD(&B_002DDF40, f32 *, 0x4C) * (1.0f - temp_f0);
    M2C_ERROR(/* unknown instruction: ldl $t1, 0x7($v1) */);
    M2C_ERROR(/* unknown instruction: ldr $t1, ($v1) */);
    M2C_ERROR(/* unknown instruction: sdl $t1, 0x17($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $t1, 0x10($sp) */);
    AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, 2, sp, M2C_FIELD(&D_002C1F00, s32 *, 8), 1.0f / temp_f2, M2C_FIELD(&D_002C1F10, s32 *, 8), -temp_f0 / temp_f2);
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3E38) != 0) {
        if (g_2dea4c == &B_002DEA50) {
            var_a1 = 1;
        } else {
            var_a1 = 2;
        }
        bevy_camera_cm_14f768(&B_002DDF40, var_a1, 0, &sp20);
    } else {
        temp_v0 = &B_002DDF40 + 0x140;
        temp_v1 = &B_002DDF40 + 0x60;
        sp20 = M2C_FIELD(&B_002DDF40, s128 *, 0x140);
        sp30 = M2C_FIELD(temp_v0, s128 *, 0x10);
        sp40 = M2C_FIELD(temp_v0, s128 *, 0x20);
        sp50 = M2C_FIELD(temp_v0, s128 *, 0x30);
        sp60 = M2C_FIELD(&B_002DDF40, s128 *, 0x60);
        sp70 = M2C_FIELD(temp_v1, s128 *, 0x10);
        sp80 = M2C_FIELD(temp_v1, s128 *, 0x20);
        sp90 = M2C_FIELD(temp_v1, s128 *, 0x30);
    }
    AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, 4, &sp20);
    AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, 4, &sp60);
    AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, 1, &B_003E12B8);
    AddVifBaseOffset__4VIFSii(arg0, 0x32, 0x1E7);
    EndDmaCnt__4DMAS(arg0);
    func_0016E1A8(arg0, arg1, arg2);
}
