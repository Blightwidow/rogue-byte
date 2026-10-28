#include "m2c_macros.h"

M2C_UNK ContinueAmb();                      /* extern */
f32 GSmooth__FfffP3SMPPf(); /* extern */
M2C_UNK PauseAmb();                         /* extern */
M2C_UNK SetSndbankVolumeFactor(); /* extern */
s64 TickReadCount();                       /* extern */
M2C_UNK UpdateAmb();                          /* extern */
M2C_UNK UpdateSndMix();                       /* extern */
M2C_UNK UpdateStreamCues();                   /* extern */
M2C_UNK func_001FDA48();                      /* extern */
M2C_UNK func_001FDBA8();                      /* extern */
M2C_UNK func_001FDEC0();                      /* extern */
s32 func_001FE5E0();                /* extern */
M2C_UNK snd_FlushSoundCommands();             /* extern */
extern M2C_UNK RO_002A8288;
extern s32 g_2bd4c0;
extern M2C_UNK g_2dded0;

void UpdateSnd(void *arg0) {
    char sp[0x400];
    f32 temp_f0;
    f32 var_f21;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    void *var_a0;
    void *var_s0;

    M2C_FIELD(arg0, s64 *, 0x1F8) = (s64) M2C_FIELD(arg0, s64 *, 0x1F0);
    M2C_FIELD(arg0, s64 *, 0x1F0) = TickReadCount(&g_2dded0);
    func_001FDA48(arg0);
    func_001FDBA8(arg0);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x204);
    if (temp_v0 > 0) {
        var_a1 = M2C_FIELD(((temp_v0 * 4) + arg0), s32 *, 0x204);
    } else {
        var_a1 = 0;
    }
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x58);
    if (g_2bd4c0 == 3) {
        if (temp_v0_2 != 0) {
            if (var_a1 != 0) {
                ContinueAmb(var_a1, var_a1);
            }
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x228);
            if (temp_a0 != 0) {
                ContinueAmb(temp_a0);
            }
            temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x200);
            if (temp_a0_2 == 0) {
                M2C_FIELD(arg0, s32 *, 0x58) = 0;
            } else {
                ContinueAmb(temp_a0_2);
                M2C_FIELD(arg0, s32 *, 0x58) = 0;
            }
        }
    } else if (temp_v0_2 == 0) {
        if (var_a1 != 0) {
            PauseAmb(var_a1, var_a1);
        }
        temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x228);
        if (temp_a0_3 != 0) {
            PauseAmb(temp_a0_3);
        }
        temp_a0_4 = M2C_FIELD(arg0, s32 *, 0x200);
        if (temp_a0_4 != 0) {
            PauseAmb(temp_a0_4);
        }
        M2C_FIELD(arg0, s32 *, 0x58) = 1;
    }
    var_f21 = 1.0f;
    UpdateSndMix(arg0);
    func_001FDEC0(arg0);
    UpdateStreamCues(arg0);
    M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a3) */);
    M2C_ERROR(/* unknown instruction: ldr $v1, ($a3) */);
    M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($sp) */);
    M2C_ERROR(/* unknown instruction: sdr $v1, ($sp) */);
    if (func_001FE5E0(arg0, M2C_FIELD(&RO_002A8288, s32 *, 8), M2C_FIELD(&RO_002A8288, s32 *, 8)) != 0) {
        if (M2C_FIELD(&g_2dded0, f32 *, 4) == 0.0f) {
            var_f21 = 0.0f;
        }
    }
    temp_f0 = GSmooth__FfffP3SMPPf(sp, 0, M2C_FIELD(arg0, f32 *, 0x15C), var_f21, M2C_FIELD(&g_2dded0, f32 *, 0x40));
    SetSndbankVolumeFactor(arg0, 0, 2, temp_f0);
    SetSndbankVolumeFactor(arg0, 1, 2, temp_f0);
    SetSndbankVolumeFactor(arg0, 2, 2, var_f21);
    var_s0 = M2C_FIELD(arg0, void **, 0x4C);
    var_a0 = var_s0;
    if (var_s0 != NULL) {
        do {
            var_s0 = M2C_FIELD(var_s0, void **, 0x38);
            UpdateAmb(var_a0);
            var_a0 = var_s0;
        } while (var_s0 != NULL);
    }
    snd_FlushSoundCommands(var_a0);
}
