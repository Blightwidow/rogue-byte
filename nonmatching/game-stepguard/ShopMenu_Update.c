#include "m2c_macros.h"

M2C_UNK CRef_Destruct();                       /* extern */
s32 FJoyButtonPressed();                /* extern */
s32 GetGameCoins();                        /* extern */
M2C_UNK Menu_SetDialog();   /* extern */
M2C_UNK Menu_Update();                              /* extern */
M2C_UNK Menu_UpdateStick();                   /* extern */
s32 NewEmitter();                            /* extern */
M2C_UNK SetEmitterUnpositioned();       /* extern */
M2C_UNK SetGadgetAcquired();            /* extern */
M2C_UNK SetGameCoins();        /* extern */
M2C_UNK ShopMenu_BuildList();                 /* extern */
M2C_UNK ShopMenu_SetPage();              /* extern */
M2C_UNK ShopMenu_UpdateBlot();                /* extern */
M2C_UNK __as__4CRefRC4CRef();           /* extern */
M2C_UNK func_0019F0A8();                   /* extern */
M2C_UNK func_001D8A38(); /* extern */
M2C_UNK func_001D8B20(); /* extern */
M2C_UNK sprintf();    /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002BCD00;
extern M2C_UNK D_002C3288;
extern M2C_UNK RO_002A79A0;
extern M2C_UNK RO_002A79D0;
extern M2C_UNK RO_002A79D8;

void ShopMenu_Update(void *arg0) {
    char sp[0x400];
    M2C_UNK sp4;
    M2C_UNK sp10;
    s32 sp30;
    s32 sp40;
    s32 sp44;
    s32 *temp_a2_2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_s2;

    Menu_Update();
    if (M2C_FIELD(arg0, s32 *, 0x40) != -1) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x10);
        if (temp_a0 != 0) {
            if (M2C_FIELD(arg0, s32 *, 0x30) != 0) {
                if (FJoyButtonPressed(temp_a0, 0x10) != 0) {
                    ShopMenu_SetPage(arg0, -1);
                } else {
                    goto block_6;
                }
            } else {
block_6:
                switch (M2C_FIELD(arg0, s32 *, 0x40)) { /* irregular */
                case 1:
                    if (FJoyButtonPressed(M2C_FIELD(arg0, s32 *, 0x10), 0x40) != 0) {
                        temp_a2 = M2C_FIELD(arg0, s32 *, 0x258);
                        if (temp_a2 == -1) {
block_20:
                            SetEmitterUnpositioned(NewEmitter(0x36), 0);
                        } else {
                            sprintf(&sp10, &RO_002A79A0, temp_a2, -1);
                            func_001D8A38(&sp30, &RO_002A79D0, &RO_002A79D8, &sp10);
                            __as__4CRefRC4CRef(sp, &sp30);
                            CRef_Destruct(&sp30);
                            if (sp4 > 0) {
                                sp44 = sp4 - 1;
                                sp40 = 0x15;
                                func_001D8B20(&sp30, &sp40, &RO_002A79D0, &RO_002A79D8);
                                CRef_Destruct(&sp30);
                                CRef_Destruct(&sp40);
                                temp_a2_2 = (M2C_FIELD(arg0, s32 *, 0x258) * 0xC) + &D_002C3288;
                                SetGameCoins(&B_002DEB30, GetGameCoins(&B_002DEB30) + *temp_a2_2, temp_a2_2);
                                ShopMenu_BuildList(arg0);
                                SetEmitterUnpositioned(NewEmitter(0x29), 0);
                            }
                            CRef_Destruct(sp);
                        }
                    }
                    break;
                case 0:
                    if (FJoyButtonPressed(M2C_FIELD(arg0, s32 *, 0x10), 0x40) != 0) {
                        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x254);
                        if (temp_a0_2 != -1) {
                            temp_s2 = M2C_FIELD((&D_002BCD00 + (temp_a0_2 << 5)), s32 *, 8);
                            temp_s0 = GetGameCoins(&B_002DEB30);
                            if (M2C_FIELD(arg0, s32 *, 0x30) == 0) {
                                Menu_SetDialog(arg0, -1, -1);
                                SetGameCoins(&B_002DEB30, temp_s0 - temp_s2);
                                SetGadgetAcquired(M2C_FIELD(arg0, s32 *, 0x254), 1);
                                ShopMenu_BuildList(arg0);
                                SetEmitterUnpositioned(NewEmitter(0x29), 0);
                                func_0019F0A8(&B_003DD490);
                            } else if (temp_s0 >= temp_s2) {
                                Menu_SetDialog(arg0, 0, 0x34);
                            } else {
                                Menu_SetDialog(arg0, 1, 0x35);
                            }
                        } else {
                            goto block_20;
                        }
                    }
                    break;
                }
                if (M2C_FIELD(arg0, s32 *, 0x30) == 0) {
                    if (FJoyButtonPressed(M2C_FIELD(arg0, s32 *, 0x10), 0x10) != 0) {
                        Menu_SetDialog(arg0, -1, -1);
                    }
                }
                if (FJoyButtonPressed(M2C_FIELD(arg0, s32 *, 0x10), 0x80) != 0) {
                    Menu_SetDialog(arg0, -1, -1);
                    ShopMenu_SetPage(arg0, M2C_FIELD(arg0, s32 *, 0x40) == 0);
                }
                if (M2C_FIELD(arg0, s32 *, 0x30) != 0) {
                    Menu_UpdateStick(arg0);
                }
                ShopMenu_UpdateBlot(arg0);
            }
        }
    }
}
