#include "m2c_macros.h"

M2C_UNK CPairPtr_Destructor();        /* extern */
M2C_UNK CRef_ConstructPair();               /* extern */
M2C_UNK CRef_CopyConstruct();                 /* extern */
M2C_UNK CRef_Destruct();                       /* extern */
M2C_UNK FreeSlotheapPv();           /* extern */
M2C_UNK PairHandle_Assign();           /* extern */
M2C_UNK PairHandle_Init();             /* extern */
s32 *PpairNew();                                    /* extern */
M2C_UNK RefEval();                 /* extern */
M2C_UNK SetTag__4CRef4TAGK();           /* extern */
M2C_UNK UnlinkPairNode();                      /* extern */
M2C_UNK __as__4CRefRC4CRef();          /* extern */
M2C_UNK bevy_splice_value_list_ref();   /* extern */
M2C_UNK func_00121578();      /* extern */
extern M2C_UNK B_004520A8;

s32 RefOpFilter(s32 arg0, s32 arg1, void *arg2, s32 arg3) {
    M2C_UNK saved_reg_s2;
    char sp[0x400];
    u8 *sp0;
    M2C_UNK sp24;
    s32 *sp10;
    s32 sp20;
    s32 *sp30;
    s32 *sp40;
    s32 *sp44;
    s32 *var_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    void *temp_s0;
    void *var_s1;

    var_s2 = saved_reg_s2;
    if (M2C_FIELD(arg2, s32 *, 8) == 0) {
        CRef_CopyConstruct(arg2 + 8);
    } else {
        func_00121578(sp, &sp40, &sp44);
        __as__4CRefRC4CRef(sp40, arg2);
        var_s1 = M2C_FIELD(arg2, void **, 0xC);
        sp10 = NULL;
        if (var_s1 != NULL) {
            do {
                temp_s0 = var_s1 + 8;
                __as__4CRefRC4CRef(sp44, temp_s0);
                RefEval(&sp20, sp0, arg3);
                if ((sp20 == 0x17) && (sp24 != 0)) {
                    PairHandle_Init(&sp30, PpairNew());
                    __as__4CRefRC4CRef(sp30 + 8, temp_s0);
                    if (sp10 == NULL) {
                        PairHandle_Assign(&sp10, PpairNew());
                        bevy_splice_value_list_ref(sp10 + 8, sp30);
                    } else {
                        PairHandle_Assign(var_s2 + 0x10, sp30);
                    }
                    var_s2 = sp30;
                    if (sp30 != NULL) {
                        temp_v0 = *sp30 - 1;
                        *sp30 = temp_v0;
                        if (temp_v0 == 0) {
                            CPairPtr_Destructor(sp30 + 0x10, 2);
                            CRef_Destruct(sp30 + 8);
                            UnlinkPairNode(sp30);
                            FreeSlotheapPv(&B_004520A8, sp30);
                        }
                    }
                }
                var_s1 = M2C_FIELD(var_s1, void **, 0x10);
                CRef_Destruct(&sp20);
            } while (var_s1 != NULL);
        }
        if (sp10 != NULL) {
            CRef_ConstructPair(arg0, M2C_FIELD(sp10, s32 *, 0xC));
            if (sp10 != NULL) {
                temp_v0_2 = M2C_FIELD(sp10, s32 *, 0) - 1;
                M2C_FIELD(sp10, s32 *, 0) = temp_v0_2;
                if (temp_v0_2 == 0) {
                    CPairPtr_Destructor(sp10 + 0x10, 2);
                    CRef_Destruct(sp10 + 8);
                    UnlinkPairNode(sp10);
                    FreeSlotheapPv(&B_004520A8, sp10);
                }
            }
            if (sp0 != NULL) {
                temp_v0_3 = *sp0 - 1;
                *sp0 = temp_v0_3;
                if (temp_v0_3 == 0) {
                    CPairPtr_Destructor(sp0 + 0x10, 2);
                    CRef_Destruct(sp0 + 8);
                    UnlinkPairNode(sp0);
                    FreeSlotheapPv(&B_004520A8, sp0);
                }
            }
        } else {
            SetTag__4CRef4TAGK(arg0, 0);
            if (sp10 != NULL) {
                temp_v0_4 = M2C_FIELD(sp10, s32 *, 0) - 1;
                M2C_FIELD(sp10, s32 *, 0) = temp_v0_4;
                if (temp_v0_4 == 0) {
                    CPairPtr_Destructor(sp10 + 0x10, 2);
                    CRef_Destruct(sp10 + 8);
                    UnlinkPairNode(sp10);
                    FreeSlotheapPv(&B_004520A8, sp10);
                }
            }
            if (sp0 != NULL) {
                temp_v0_5 = *sp0 - 1;
                *sp0 = temp_v0_5;
                if (temp_v0_5 == 0) {
                    CPairPtr_Destructor(sp0 + 0x10, 2);
                    CRef_Destruct(sp0 + 8);
                    UnlinkPairNode(sp0);
                    FreeSlotheapPv(&B_004520A8, sp0);
                }
            }
        }
    }
    return arg0;
}
