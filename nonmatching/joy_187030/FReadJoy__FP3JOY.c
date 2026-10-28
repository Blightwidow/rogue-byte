#include "m2c_macros.h"

M2C_UNK CopyAb__FPvT0Ui(void *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK GetJoyXYDeflection__FP3JOYUcUcPfN23PUcT6PiP2LM(void *, u8, u8, void *, void *, void *); /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK _MatchCodes__FP3JOYUs(M2C_UNK *, void *, s32); /* extern */
M2C_UNK bevy_camera_follow_activity(f32 *, M2C_UNK, s32); /* extern */
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);        /* extern */
s32 scePadRead(s32, s32, M2C_UNK *);                /* extern */
extern M2C_UNK B_002DDEC0;
extern M2C_UNK B_002DDF40;
extern f32 B_002DEB30;
extern M2C_UNK B_003DD490;
extern M2C_UNK g_2dded0;
extern f32 g_2ddf0c;

s32 FReadJoy__FP3JOY(void *arg0) {
    M2C_UNK sp11;
    M2C_UNK sp12;
    M2C_UNK sp13;
    M2C_UNK sp14;
    M2C_UNK sp15;
    M2C_UNK sp16;
    M2C_UNK sp17;
    M2C_UNK sp10;
    M2C_UNK sp18;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f23;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f0;
    f32 var_f0_2;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s4;

    var_s4 = 1;
    memset(&sp10, 0, 0x40);
    if (scePadRead(M2C_FIELD(arg0, s32 *, 0x1000), M2C_FIELD(arg0, s32 *, 0x1004), &sp10) > 0) {
        temp_s3 = M2C_FIELD(arg0, s32 *, 0x10B4);
        temp_a1 = M2C_FIELD(arg0, s32 *, 0x10BC);
        temp_v0 = ((sp12 << 8) | sp13) ^ 0xFFFF;
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x1008);
        M2C_FIELD(arg0, s32 *, 0x10B8) = (s32) (temp_v0 & ~temp_s3 & ~temp_a1);
        M2C_FIELD(arg0, s32 *, 0x10BC) = (s32) (temp_a1 & temp_v0);
        M2C_FIELD(arg0, s32 *, 0x10B4) = temp_v0;
        if (temp_a0 != 0) {
            var_s4 = ((temp_a0 ^ sp11) != 0) ? 0 : 1;
        }
        M2C_FIELD(arg0, s32 *, 0x1008) = (s32) sp11;
        if (M2C_FIELD(arg0, s32 *, 0x1010) == 4) {
            CopyAb__FPvT0Ui(arg0 + 0x10C0, &sp18, 0xC);
        }
        temp_f20 = M2C_FIELD(arg0, f32 *, 0x103C);
        temp_f21 = M2C_FIELD(arg0, f32 *, 0x1040);
        temp_f22 = M2C_FIELD(arg0, f32 *, 0x1070);
        temp_f23 = M2C_FIELD(arg0, f32 *, 0x1074);
        if (M2C_FIELD(arg0, s32 *, 0x1010) >= 2) {
            GetJoyXYDeflection__FP3JOYUcUcPfN23PUcT6PiP2LM(arg0, sp16, sp17, arg0 + 0x103C, arg0 + 0x104C, arg0 + 0x1050);
            GetJoyXYDeflection__FP3JOYUcUcPfN23PUcT6PiP2LM(arg0, sp14, sp15, arg0 + 0x1070, arg0 + 0x1080, arg0 + 0x1084);
        } else {
            M2C_FIELD(arg0, f32 *, 0x1070) = 0.0f;
            M2C_FIELD(arg0, f32 *, 0x1044) = 0.0f;
            M2C_FIELD(arg0, f32 *, 0x1040) = 0.0f;
            M2C_FIELD(arg0, f32 *, 0x103C) = 0.0f;
            M2C_FIELD(arg0, f32 *, 0x1078) = 0.0f;
            M2C_FIELD(arg0, f32 *, 0x1074) = 0.0f;
        }
        if ((M2C_FIELD(&B_002DDF40, s32 *, 0x30C) == 0) || (M2C_FIELD(&B_002DDF40, s32 *, 0x314) != (&B_002DDF40 + 0x3A0))) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x10B4);
            if (temp_v1 & 0xF000) {
                M2C_FIELD(arg0, f32 *, 0x103C) = 0.0f;
                M2C_FIELD(arg0, f32 *, 0x1044) = 0.0f;
                M2C_FIELD(arg0, f32 *, 0x1040) = 0.0f;
                if (temp_v1 & 0x8000) {
                    var_f0 = -M2C_FIELD(arg0, f32 *, 0x10EC);
                    goto block_15;
                }
                if (temp_v1 & 0x2000) {
                    var_f0 = M2C_FIELD(arg0, f32 *, 0x10EC);
block_15:
                    M2C_FIELD(arg0, f32 *, 0x103C) = var_f0;
                }
                temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x10B4);
                if (temp_v1_2 & 0x1000) {
                    var_f0_2 = M2C_FIELD(arg0, f32 *, 0x10EC);
                    goto block_20;
                }
                if (temp_v1_2 & 0x4000) {
                    var_f0_2 = -M2C_FIELD(arg0, f32 *, 0x10EC);
block_20:
                    M2C_FIELD(arg0, f32 *, 0x1040) = var_f0_2;
                }
                temp_f2 = M2C_FIELD(arg0, f32 *, 0x103C);
                temp_f3 = M2C_FIELD(arg0, f32 *, 0x1040);
                if ((temp_f2 * temp_f3) != 0.0f) {
                    M2C_ERROR(/* unknown instruction: c1 0x44 */);
                    M2C_FIELD(arg0, f32 *, 0x103C) = (f32) (temp_f2 * 0.0f);
                    M2C_ERROR(/* unknown instruction: c1 0x84 */);
                    M2C_FIELD(arg0, f32 *, 0x1040) = (f32) (temp_f3 * temp_f2);
                }
                M2C_FIELD(arg0, f32 *, 0x1044) = 1.0f;
            }
        }
        M2C_FIELD(arg0, f32 *, 0x10A4) = (f32) ((M2C_FIELD(arg0, f32 *, 0x103C) - temp_f20) / M2C_FIELD(&g_2dded0, f32 *, 0x40));
        M2C_FIELD(arg0, f32 *, 0x10A8) = (f32) ((M2C_FIELD(arg0, f32 *, 0x1040) - temp_f21) / M2C_FIELD(&g_2dded0, f32 *, 0x40));
        M2C_FIELD(arg0, f32 *, 0x10AC) = (f32) ((M2C_FIELD(arg0, f32 *, 0x1070) - temp_f22) / M2C_FIELD(&g_2dded0, f32 *, 0x40));
        M2C_FIELD(arg0, f32 *, 0x10B0) = (f32) ((M2C_FIELD(arg0, f32 *, 0x1074) - temp_f23) / M2C_FIELD(&g_2dded0, f32 *, 0x40));
        _MatchCodes__FP3JOYUs(&B_002DDEC0, arg0, temp_s3 & 0xFFFF);
        M2C_FIELD(arg0, f32 *, 0x1018) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0x3C);
        if ((M2C_FIELD(arg0, s32 *, 0x10B4) == 0) && (M2C_FIELD(arg0, f32 *, 0x1044) == 0.0f)) {
            if (M2C_FIELD(arg0, f32 *, 0x1078) == 0.0f) {
                M2C_FIELD(arg0, f32 *, 0x1020) = (f32) M2C_FIELD(arg0, f32 *, 0x101C);
            } else {
                goto block_29;
            }
        } else {
block_29:
            M2C_FIELD(arg0, f32 *, 0x1020) = 0.0f;
            M2C_FIELD(arg0, f32 *, 0x101C) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0x3C);
            if ((M2C_FIELD(&g_2dded0, f32 *, 0x3C) - B_002DEB30) > 15.0f) {
                bevy_camera_follow_activity(&B_002DEB30, 0xE, PpoSwFocusBase(&B_003DD490));
                B_002DEB30 = M2C_FIELD(&g_2dded0, f32 *, 0x3C);
            }
        }
    } else if ((g_2ddf0c - M2C_FIELD(arg0, f32 *, 0x1018)) >= 2.0f) {
        var_s4 = 0;
    }
    return var_s4;
}
