#include "m2c_macros.h"

M2C_UNK CPairPtr_Destructor(M2C_UNK *, M2C_UNK);    /* extern */
M2C_UNK CRef_ConstructPair(M2C_UNK **, M2C_UNK *);  /* extern */
M2C_UNK CRef_Destruct(M2C_UNK *);                   /* extern */
M2C_UNK FreeSlotheapPv(M2C_UNK *, M2C_UNK *);       /* extern */
s32 NRandInRange(M2C_UNK, s32);                     /* extern */
M2C_UNK PairHandle_Assign(M2C_UNK *, M2C_UNK *);    /* extern */
M2C_UNK PairHandle_Init(M2C_UNK **, M2C_UNK *);     /* extern */
M2C_UNK *PpairNew();                                /* extern */
M2C_UNK SetTag__4CRef4TAGK(M2C_UNK **, M2C_UNK);    /* extern */
M2C_UNK UnlinkPairNode(M2C_UNK *);                  /* extern */
M2C_UNK __as__4CRefRC4CRef(M2C_UNK *, M2C_UNK *);   /* extern */
extern M2C_UNK B_004520A8;

M2C_UNK **bevy_splice_bif_bif41_shuffle(M2C_UNK **arg0, s32 arg1, void *arg2) {
    char sp[0x400];
    s32 sp0;
    M2C_UNK *sp200;
    M2C_UNK *sp210;
    M2C_UNK *sp220;
    M2C_UNK **temp_v1_2;
    M2C_UNK **var_s1;
    M2C_UNK **var_s1_2;
    M2C_UNK **var_v1;
    M2C_UNK *temp_a0_2;
    M2C_UNK *temp_s0;
    M2C_UNK *temp_v0;
    M2C_UNK *temp_v0_2;
    M2C_UNK *temp_v0_3;
    M2C_UNK *temp_v0_4;
    M2C_UNK *var_s2;
    M2C_UNK *var_s5;
    s32 *temp_a0;
    s32 temp_s3;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 var_a0;
    s32 var_s2_2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s7;
    void *var_a2;

    temp_v1 = M2C_FIELD(arg2, s32 *, 0);
    if ((temp_v1 == 0) || (temp_v1 != 0x1F)) {
        SetTag__4CRef4TAGK(arg0, 0);
    } else {
        var_a2 = M2C_FIELD(arg2, void **, 4);
        var_s4 = 0;
        var_a0 = -1;
        if (var_a2 != NULL) {
            var_v1 = sp;
            do {
                if (M2C_FIELD(var_a2, s32 *, 8) == 0) {
                    var_a0 = var_s4;
                } else {
                    var_s4 += 1;
                    *var_v1 = var_a2 + 8;
                    var_v1 += 4;
                }
                var_a2 = M2C_FIELD(var_a2, void **, 0x10);
            } while (var_a2 != NULL);
        }
        var_s7 = 0;
        if (var_s4 >= 2) {
            var_s7 = var_a0 < 1;
        }
        var_s2 = &sp200;
        if (var_s7 != 0) {
            temp_s3 = sp0;
            if (var_s4 > 0) {
                var_s1 = sp;
                var_s2_2 = var_s4;
                do {
                    var_s2_2 -= 1;
                    temp_v1_2 = sp + (NRandInRange(0, var_s4 - 1) * 4);
                    temp_v0 = *temp_v1_2;
                    *temp_v1_2 = *var_s1;
                    *var_s1 = temp_v0;
                    var_s1 += 4;
                } while (var_s2_2 != 0);
            }
            var_a0 = var_s4;
            if (sp0 == temp_s3) {
                temp_a0 = sp + ((var_s4 - 1) * 4);
                sp0 = *temp_a0;
                *temp_a0 = temp_s3;
                var_a0 = var_s4;
            }
            var_s2 = &sp200;
        }
        sp200 = NULL;
        var_s3 = 0;
        var_s5 = NULL;
        if (var_s4 > 0) {
            var_s1_2 = sp;
            do {
                PairHandle_Assign(var_s2, PpairNew());
                temp_s0 = *var_s2;
                temp_a0_2 = temp_s0 + 8;
                var_s2 = &*(temp_s0 + 0x10);
                __as__4CRefRC4CRef(temp_a0_2, *var_s1_2);
                var_s1_2 += 4;
                temp_v1_3 = var_s3 ^ (var_a0 - 1);
                var_s3 += 1;
                var_s5 = (temp_v1_3 == 0) ? temp_s0 : var_s5;
            } while (var_s3 < var_s4);
        }
        if (var_s5 != NULL) {
            if (var_s5 != sp200) {
                if (var_s7 == 0) {
                    PairHandle_Init(&sp210, sp200);
                    PairHandle_Assign(&sp200, M2C_FIELD(sp200, M2C_UNK **, 0x10));
                    PairHandle_Assign(sp210 + 0x10, M2C_FIELD(var_s5, M2C_UNK **, 0x10));
                    PairHandle_Assign(var_s5 + 0x10, sp210);
                    if (sp210 != NULL) {
                        temp_v0_2 = *sp210 - 1;
                        *sp210 = temp_v0_2;
                        if (temp_v0_2 == NULL) {
                            CPairPtr_Destructor(sp210 + 0x10, 2);
                            CRef_Destruct(&*(sp210 + 8));
                            UnlinkPairNode(sp210);
                            FreeSlotheapPv(&B_004520A8, sp210);
                        }
                    }
                }
                if (sp200 != var_s5) {
                    PairHandle_Init(&sp210, PpairNew());
                    SetTag__4CRef4TAGK(&sp220, 0);
                    __as__4CRefRC4CRef(sp210 + 8, &sp220);
                    CRef_Destruct(&sp220);
                    PairHandle_Assign(sp210 + 0x10, M2C_FIELD(var_s5, M2C_UNK **, 0x10));
                    PairHandle_Assign(var_s5 + 0x10, sp210);
                    if (sp210 != NULL) {
                        temp_v0_3 = *sp210 - 1;
                        *sp210 = temp_v0_3;
                        if (temp_v0_3 == NULL) {
                            CPairPtr_Destructor(sp210 + 0x10, 2);
                            CRef_Destruct(sp210 + 8);
                            UnlinkPairNode(sp210);
                            FreeSlotheapPv(&B_004520A8, sp210);
                        }
                    }
                }
            }
        }
        CRef_ConstructPair(arg0, sp200);
        if (sp200 != NULL) {
            temp_v0_4 = M2C_FIELD(sp200, M2C_UNK **, 0) - 1;
            M2C_FIELD(sp200, M2C_UNK **, 0) = temp_v0_4;
            if (temp_v0_4 == NULL) {
                CPairPtr_Destructor(sp200 + 0x10, 2);
                CRef_Destruct(sp200 + 8);
                UnlinkPairNode(sp200);
                FreeSlotheapPv(&B_004520A8, sp200);
            }
        }
    }
    return arg0;
}
