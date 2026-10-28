#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_Read_thunk(); /* extern */
M2C_UNK CBinaryInputStream_Skip();          /* extern */
s32 FIsCidDerivedFrom();                /* extern */
s32 MakeCloneId();                      /* extern */
M2C_UNK PcnodeFindOrAddClonePath(); /* extern */
s32 PloFindSwObject(); /* extern */
s32 PloFindSwObject_thunk(); /* extern */
void *PloNew();                   /* extern */
s32 S16Read__18CBinaryInputStream(); /* extern */
s32 S32Read__18CBinaryInputStream();             /* extern */
s32 S8Read__18CBinaryInputStream();              /* extern */
s32 func_0013FAD0();                  /* extern */
M2C_UNK func_001C9B08();    /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002CBE38;

void LoadSwObjectsFromBrx(s32 arg0, s32 arg1, void **arg2) {
    char sp[0x400];
    M2C_UNK sp10;
    s32 sp110;
    void *sp114;
    void *sp118;
    s32 sp11C;
    s32 sp120;
    M2C_UNK (*temp_a2)(void *, s32, M2C_UNK);
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s1;
    void **var_s2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;

    sp11C = arg0;
    temp_v0 = S16Read__18CBinaryInputStream(arg1, &D_002CBE38, -1, -1);
    if (temp_v0 > 0) {
        sp120 = temp_v0;
        do {
            temp_v0_2 = S8Read__18CBinaryInputStream(arg1);
            if ((temp_v0_2 > 0) || (var_s1 = temp_v0_2 < -2, (var_s1 != 0))) {
                CBinaryInputStream_Read_thunk(arg1, temp_v0_2 * 2, &sp10);
                var_s1 = temp_v0_2 < -2;
            }
            var_s2 = arg2;
            temp_s3 = S16Read__18CBinaryInputStream(arg1);
            temp_s4 = S32Read__18CBinaryInputStream(arg1);
            temp_s6 = S16Read__18CBinaryInputStream(arg1);
            temp_s7 = S32Read__18CBinaryInputStream(arg1);
            if (var_s1 == 0) {
                if (temp_v0_2 >= 0) {
                    if (temp_v0_2 == 0) {
                        goto block_20;
                    }
                    goto block_16;
                }
                sp110 = MakeCloneId(M2C_FIELD(&B_003DD490, s32 *, 0x3F10), -1);
                PcnodeFindOrAddClonePath(M2C_FIELD(&B_003DD490, s32 *, 0x3F0C), 1, &sp110);
                if (temp_v0_2 == -2) {
                    if (PloFindSwObject_thunk(&B_003DD490, 0x405, temp_s4, 0) == 0) {
                        goto block_14;
                    }
                    goto block_26;
                }
                if (PloFindSwObject(&B_003DD490, 0x805, temp_s4, 0) == 0) {
block_14:
                    var_s2 = sp;
block_20:
                    goto block_21;
                }
                goto block_26;
            }
block_16:
            if (func_0013FAD0(temp_v0_2, &sp10) == 0) {
                if ((u32) (temp_s3 - 0x84) < 2U) {
                    temp_v0_3 = PloNew(temp_s3, sp11C, temp_s4, -1);
                    sp114 = temp_v0_3;
                    M2C_FIELD(temp_v0_3, s32 *, 0x50) = 1;
                    temp_v0_4 = M2C_FIELD(sp114, void **, 0xC);
                    M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, s32, void *), 0x74)(sp114 + M2C_FIELD(temp_v0_4, s16 *, 0x70), arg1, sp114);
                    if (arg2 != NULL) {
                        temp_v0_5 = *arg2;
                        M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, M2C_UNK, void **), 0xC)(arg2 + M2C_FIELD(temp_v0_5, s16 *, 8), 1, &sp114);
                    }
                } else {
block_26:
                    CBinaryInputStream_Skip(arg1, temp_s7);
                }
            } else {
block_21:
                if (FIsCidDerivedFrom(temp_s3, 6) != 0) {
                    func_001C9B08(&B_003DD490, sp11C, temp_s3, temp_s4);
                } else {
                    temp_v0_6 = PloNew(temp_s3, sp11C, temp_s4, temp_s6);
                    sp118 = temp_v0_6;
                    temp_v0_7 = M2C_FIELD(temp_v0_6, void **, 0xC);
                    temp_a2 = M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *, s32, M2C_UNK), 0x74);
                    temp_a2(temp_v0_6 + M2C_FIELD(temp_v0_7, s16 *, 0x70), arg1, temp_a2);
                    if (var_s2 != NULL) {
                        temp_v0_8 = *var_s2;
                        M2C_FIELD(temp_v0_8, M2C_UNK (**)(void *, M2C_UNK, void **), 0xC)(var_s2 + M2C_FIELD(temp_v0_8, s16 *, 8), 1, &sp118);
                    }
                }
            }
            temp_v1 = sp120 - 1;
            sp120 = temp_v1;
        } while (temp_v1 != 0);
    }
}
