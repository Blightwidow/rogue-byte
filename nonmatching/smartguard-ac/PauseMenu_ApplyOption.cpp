#include "m2c_macros.h"
extern "C" {

M2C_UNK ApplyOptionsFromSave();            /* extern */
M2C_UNK CRef_CopyConstruct(); /* extern */
M2C_UNK CRef_Destruct();                   /* extern */
M2C_UNK PauseMenu_SetState();           /* extern */
M2C_UNK RefSetGameSaveValue(); /* extern */
extern M2C_UNK B_003D4A60;
extern M2C_UNK B_003DD490;
extern s32 B_003E0FC0;
extern s32 B_003E0FC4;
extern s32 B_003E0FC8;
extern s32 B_003E0FCC;
extern s32 B_003E0FD8;
extern s32 B_003E0FDC;
extern s32 B_003E0FE0;
extern f32 B_FLT_002F6468;
extern f32 B_FLT_002F646C;
extern f32 B_FLT_003DD18C;
extern f32 B_FLT_003DD190;
extern s32 g_2c2d8c;

void PauseMenu_ApplyOption(s32 arg0, s32 *arg1) {
    char sp[0x10];
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_UNK *var_s0;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s1;
    s32 temp_v1;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_v0;
    s32 var_v0_2;

    var_s0 = &B_003D4A60;
    temp_v1 = *arg1;
    switch (temp_v1) {
    case 0x67:
        temp_s0 = B_003E0FC4;
        CRef_CopyConstruct(&sp10, sp, 0x16, 1.0f - B_FLT_003DD190);
        RefSetGameSaveValue(&sp20, temp_s0, &sp10, &B_003D4A60);
block_5:
        var_s0 = &B_003D4A60;
        CRef_Destruct(&sp20);
        CRef_Destruct(&sp10);
        CRef_Destruct(sp);
        PauseMenu_SetState(arg0, 9);
        break;
    case 0x68:
        temp_s0_2 = B_003E0FC8;
        CRef_CopyConstruct(&sp10, sp, 0x16, 1.0f - B_FLT_003DD18C);
        RefSetGameSaveValue(&sp20, temp_s0_2, &sp10, &B_003D4A60);
        CRef_Destruct(&sp20);
        CRef_Destruct(&sp10);
        CRef_Destruct(sp);
        PauseMenu_SetState(arg0, 9);
        var_s0 = &B_003D4A60;
        break;
    case 0x3F:
        temp_s0_3 = M2C_FIELD(&B_003DD490, s32 *, 0x3B40);
        CRef_CopyConstruct(&sp10, sp, 0x16, B_FLT_002F6468 - 636.0f);
        RefSetGameSaveValue(&sp20, temp_s0_3, &sp10, &B_003D4A60);
        CRef_Destruct(&sp20);
        CRef_Destruct(&sp10);
        CRef_Destruct(sp);
        temp_s0_4 = M2C_FIELD(&B_003DD490, s32 *, 0x3B44);
        CRef_CopyConstruct(&sp10, sp, 0x16, B_FLT_002F646C - 50.0f);
        RefSetGameSaveValue(&sp20, temp_s0_4, &sp10, &B_003D4A60);
        goto block_5;
    case 0x4E:
        var_s0_2 = B_003E0FC0;
block_14:
block_15:
        CRef_CopyConstruct(&sp10, sp);
        RefSetGameSaveValue(&sp20, var_s0_2, &sp10, &B_003D4A60);
        CRef_Destruct(&sp20);
        CRef_Destruct(&sp10);
        CRef_Destruct(sp);
        var_s0 = &B_003D4A60;
        break;
    case 0x4D:
        var_s0_2 = B_003E0FC0;
        goto block_15;
    case 0x4C:
        var_s0_2 = B_003E0FC0;
        goto block_15;
    case 0x4F:
    case 0x50:
        var_v0 = *arg1 ^ 0x4F;
        var_s1 = B_003E0FCC;
block_17:
        CRef_CopyConstruct(&sp10, sp, var_v0 == 0);
        var_s0 = &B_003D4A60;
        RefSetGameSaveValue(&sp20, var_s1, &sp10, &B_003D4A60);
        CRef_Destruct(&sp20);
        CRef_Destruct(&sp10);
        CRef_Destruct(sp);
        break;
    case 0x48:
    case 0x49:
        if (*arg1 == 0x49) {
            var_v0_2 = 3;
        } else {
            var_v0_2 = 2;
        }
        g_2c2d8c = var_v0_2;
        var_s0_2 = B_003E0FD8;
        goto block_14;
    case 0x51:
    case 0x52:
        var_v0 = *arg1 ^ 0x52;
        var_s1 = B_003E0FDC;
        goto block_17;
    case 0x53:
    case 0x54:
        temp_s1 = B_003E0FE0;
        CRef_CopyConstruct(&sp10, sp, 0x17, M2C_BITWISE(f32, (*arg1 == 0x54)));
        var_s0 = &B_003D4A60;
        RefSetGameSaveValue(&sp20, temp_s1, &sp10, &B_003D4A60);
        CRef_Destruct(&sp20);
        CRef_Destruct(&sp10);
        CRef_Destruct(sp);
        break;
    }
    ApplyOptionsFromSave(var_s0);
}
}
