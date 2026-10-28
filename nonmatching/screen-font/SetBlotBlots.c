#include "m2c_macros.h"

M2C_UNK PlayBlotLabel(void *, s32);                 /* extern */
M2C_UNK PrepareBlotMovie(void *);                   /* extern */
M2C_UNK ReleaseBlotMovie(void *, s32);              /* extern */
M2C_UNK SetClockRate(M2C_UNK *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK StopBlotLabel(void *, s32);                 /* extern */
extern M2C_UNK B_003DD490;
extern s32 g_2be538;
extern s32 g_2dd318;
extern M2C_UNK g_2dded0;

void SetBlotBlots(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x58);
    if (temp_v1 != arg1) {
        if (M2C_FIELD(arg0, s32 *, 0xA4) >= 0x10) {
            temp_v0 = arg1 < 2;
            if (temp_v1 < 2) {
                if (temp_v0 == 0) {
                    var_v0 = M2C_FIELD(&B_003DD490, s32 *, 0x3BEC) + 1;
                    goto block_8;
                }
                goto block_6;
            }
            if (temp_v0 != 0) {
block_6:
                if (M2C_FIELD(arg0, s32 *, 0x58) >= 2) {
                    var_v0 = M2C_FIELD(&B_003DD490, s32 *, 0x3BEC) - 1;
block_8:
                    M2C_FIELD(&B_003DD490, s32 *, 0x3BEC) = var_v0;
                }
            }
        }
        if (M2C_FIELD(arg0, s32 *, 0xB0) != 0) {
            temp_v0_2 = arg1 < 2;
            if (M2C_FIELD(arg0, s32 *, 0x58) < 2) {
                if (temp_v0_2 == 0) {
                    temp_v1_2 = g_2dd318 + 1;
                    g_2dd318 = temp_v1_2;
                    if (temp_v1_2 == 1) {
                        SetClockRate(&g_2dded0, 7, 0);
                    }
                } else {
                    goto block_15;
                }
            } else if (temp_v0_2 != 0) {
block_15:
                if (M2C_FIELD(arg0, s32 *, 0x58) >= 2) {
                    temp_v0_3 = g_2dd318 - 1;
                    g_2dd318 = temp_v0_3;
                    if (temp_v0_3 == 0) {
                        SetClockRate(&g_2dded0, 7, 0x3F800000);
                    }
                }
            }
        }
        if (M2C_FIELD(arg0, s32 *, 0x58) == 0) {
            PrepareBlotMovie(arg0);
        }
        M2C_FIELD(arg0, s32 *, 0x58) = arg1;
        temp_a1 = (u32) arg1 < 5U;
        M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(&g_2dded0, f32 *, 0x3C);
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) g_2be538;
        if (temp_a1 != 0) {
            switch (arg1) {
            case 0:
                ReleaseBlotMovie(arg0, temp_a1);
                return;
            case 1:
                StopBlotLabel(arg0, temp_a1);
                return;
            case 2:
                PlayBlotLabel(arg0, M2C_FIELD(arg0, s32 *, 0x70));
                return;
            case 3:
                PlayBlotLabel(arg0, M2C_FIELD(arg0, s32 *, 0x74));
                return;
            case 4:
                PlayBlotLabel(arg0, M2C_FIELD(arg0, s32 *, 0x78));
                break;
            }
        }
    }
}
