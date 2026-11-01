#include "m2c_macros.h"

M2C_UNK CPairPtr_Destructor();        /* extern */
M2C_UNK CRef_ConstructPair();             /* extern */
M2C_UNK CRef_CopyConstruct();          /* extern */
M2C_UNK CRef_Destruct();                       /* extern */
M2C_UNK CRef_SetBasic();                  /* extern */
M2C_UNK FreeSlotheapPv();           /* extern */
M2C_UNK PairHandle_Assign();              /* extern */
M2C_UNK PairHandle_Init();               /* extern */
s32 PloFindSwObject(); /* extern */
s32 PpairNew();                                     /* extern */
M2C_UNK UnlinkPairNode();                      /* extern */
M2C_UNK __as__4CRefRC4CRef();           /* extern */
M2C_UNK bevy_splice_value_list_ref();   /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK B_004520A8;

void *func_001242B8(void *arg0, void *arg2) {
    M2C_UNK saved_reg_s5;
    char sp[0x400];
    s32 *sp10;
    s32 *sp20;
    s32 sp30;
    s32 *var_s5;
    s32 temp_v0;
    s32 temp_v0_2;
    void *temp_s3;
    void *var_s1;
    void *var_s2;

    var_s5 = saved_reg_s5;
    if (M2C_FIELD(arg2, s32 *, 0) == 0) {
        CRef_CopyConstruct(arg2);
        CRef_Destruct(sp);
    } else {
        temp_s3 = M2C_FIELD(arg2, void **, 0xC);
        if (M2C_FIELD(arg2, s32 *, 0x10) != 0) {
            var_s2 = M2C_FIELD(M2C_FIELD(arg2, void **, 0x14), void **, 0xC);
        } else {
            var_s2 = temp_s3;
        }
        PairHandle_Init(&sp10, PpairNew());
        var_s1 = M2C_FIELD(arg2, void **, 4);
        if (var_s1 != NULL) {
            do {
                PairHandle_Init(&sp20, PpairNew());
                if (var_s2 != NULL) {

                }
                CRef_SetBasic(sp20 + 8, PloFindSwObject(&B_003DD490, (temp_s3 != NULL) ? 1 : 5, M2C_FIELD(var_s1, s32 *, 0xC), temp_s3));
                if (M2C_FIELD(sp10, s32 *, 8) != 0x1F) {
                    bevy_splice_value_list_ref(sp10 + 8, sp20);
                } else {
                    PairHandle_Assign(var_s5 + 0x10, sp20);
                }
                var_s1 = M2C_FIELD(var_s1, void **, 0x10);
                var_s5 = sp20;
                if (sp20 != NULL) {
                    temp_v0 = *sp20 - 1;
                    *sp20 = temp_v0;
                    if (temp_v0 == 0) {
                        CPairPtr_Destructor(sp20 + 0x10, 2);
                        CRef_Destruct(sp20 + 8);
                        UnlinkPairNode(sp20);
                        FreeSlotheapPv(&B_004520A8, sp20);
                    }
                }
            } while (var_s1 != NULL);
        }
        CRef_ConstructPair(&sp30, M2C_FIELD(sp10, s32 *, 0xC));
        __as__4CRefRC4CRef(sp, &sp30);
        CRef_Destruct(&sp30);
        CRef_CopyConstruct(arg0, sp);
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
        CRef_Destruct(sp);
    }
    return arg0;
}
