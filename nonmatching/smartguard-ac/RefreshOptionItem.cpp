#include "m2c_macros.h"
extern "C" {

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK RefGetGameSaveValue(void *, s32, M2C_UNK *); /* extern */
extern M2C_UNK B_003D4A60;
extern s32 B_003DD050;
extern s32 B_003E0FC0;
extern s32 B_003E0FD8;
extern s32 B_003E0FDC;
extern s32 B_003E0FE0;
extern s32 g_2c2d8c;

void RefreshOptionItem(s32 *arg0) {
    char sp[0x10];
    M2C_UNK sp4;
    s32 temp_v0;
    s32 var_s0;
    s32 var_v0;

    temp_v0 = *arg0;
    switch (temp_v0) {
    case 0x4C:
    case 0x4D:
    case 0x4E:
        RefGetGameSaveValue(sp, B_003E0FC0, &B_003D4A60);
        CRef_Destruct(sp);
        if (sp4 != 1) {
            var_v0 = 0x4E;
            if (sp4 >= 2) {
                var_v0 = 0x4E;
                if (sp4 != 2) {

                } else {
                    var_v0 = 0x4D;
                }
            }
        } else {
            var_v0 = 0x4C;
        }
block_26:
        *arg0 = var_v0;
        break;
    case 0x4F:
    case 0x50:
        var_v0 = (B_003DD050 != 0) ? 0x4F : 0x50;
        goto block_26;
    case 0x48:
    case 0x49:
        if (g_2c2d8c != 2) {
            if (g_2c2d8c < 3) {
                var_s0 = 0;
                if (g_2c2d8c != 1) {

                } else {
                    RefGetGameSaveValue(sp, B_003E0FD8, &B_003D4A60);
                    var_s0 = sp4;
                    CRef_Destruct(sp);
                }
            } else {
                var_s0 = 0;
                if (g_2c2d8c != 3) {

                } else {
                    var_s0 = 1;
                }
            }
        } else {
            var_s0 = 0;
        }
        var_v0 = 0x49;
        if (var_s0 == 0) {
            var_v0 = 0x48;
        }
        goto block_26;
    case 0x51:
    case 0x52:
        RefGetGameSaveValue(sp, B_003E0FDC, &B_003D4A60);
        CRef_Destruct(sp);
        var_v0 = 0x52;
        if (sp4 == 0) {
            var_v0 = 0x51;
        }
        goto block_26;
    case 0x53:
    case 0x54:
        RefGetGameSaveValue(sp, B_003E0FE0, &B_003D4A60);
        CRef_Destruct(sp);
        var_v0 = 0x53;
        if (sp4 != 0) {
            var_v0 = 0x54;
        }
        goto block_26;
    }
}
}
