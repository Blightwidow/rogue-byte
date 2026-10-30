typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ShopMenu_Update {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[8];                        /* maybe part of sp4[3]? */
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x20];
    /* 0x30 */ s32 sp30;                            /* inferred */
    /* 0x34 */ char pad34[0xC];                     /* maybe part of sp30[4]? */
    /* 0x40 */ s32 sp40;                            /* inferred */
    /* 0x44 */ s32 sp44;                            /* inferred */
    /* 0x48 */ char pad48[0x78];
};                                                  /* size = 0xC0 */
#define sp4 (*(s32 *)(sp + 0x04))
M2C_UNK CRef_Destruct(s32 *);                       /* extern */
s32 FJoyButtonPressed(s32, M2C_UNK);                /* extern */
s32 GetGameCoins(M2C_UNK *);                        /* extern */
M2C_UNK Menu_SetDialog(s8 *, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK Menu_Update();                              /* extern */
M2C_UNK Menu_UpdateStick(s8 *);                   /* extern */
s32 NewEmitter(M2C_UNK);                            /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
M2C_UNK SetGadgetAcquired(s32, M2C_UNK);            /* extern */
M2C_UNK SetGameCoins(...);        /* extern */
M2C_UNK ShopMenu_BuildList(s8 *);                 /* extern */
M2C_UNK ShopMenu_SetPage(s8 *, s32);              /* extern */
M2C_UNK ShopMenu_UpdateBlot(s8 *);                /* extern */
M2C_UNK __as__4CRefRC4CRef(s32 *, s32 *);           /* extern */
M2C_UNK func_0019F0A8(M2C_UNK *);                   /* extern */
M2C_UNK func_001D8A38(s32 *, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_001D8B20(s32 *, s32 *, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK sprintf(M2C_UNK *, M2C_UNK *, s32, s32);    /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002BCD00;
extern M2C_UNK D_002C3288;
extern M2C_UNK RO_002A79A0;
extern M2C_UNK RO_002A79D0;
extern M2C_UNK RO_002A79D8;
void ShopMenu_Update(s8 *arg0) {
    s8 sp[0x40] __attribute__((aligned(16)));
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
                            func_001D8A38(&sp30, &RO_002A79D0, &RO_002A79D8, &sp10, 0);
                            __as__4CRefRC4CRef((s32 *)(sp), &sp30);
                            CRef_Destruct(&sp30);
                            if (sp4 > 0) {
                                sp44 = sp4 - 1;
                                sp40 = 0x15;
                                func_001D8B20(&sp30, &sp40, &RO_002A79D0, &RO_002A79D8, &sp10, 0);
                                CRef_Destruct(&sp30);
                                CRef_Destruct(&sp40);
                                temp_a2_2 = (M2C_FIELD(arg0, s32 *, 0x258) * 0xC) + &D_002C3288;
                                SetGameCoins(&B_002DEB30, GetGameCoins(&B_002DEB30) + *temp_a2_2, temp_a2_2);
                                ShopMenu_BuildList(arg0);
                                SetEmitterUnpositioned(NewEmitter(0x29), 0);
                            }
                            CRef_Destruct((s32 *)(sp));
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
}
