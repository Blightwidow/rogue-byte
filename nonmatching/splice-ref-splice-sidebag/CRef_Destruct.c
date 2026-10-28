#include "m2c_macros.h"

M2C_UNK CPairPtr_Destructor(void *, M2C_UNK);       /* extern */
M2C_UNK CProc_DeletingDestructor(void *, M2C_UNK);  /* extern */
M2C_UNK FreeSlotheapPv(M2C_UNK *, void *);          /* extern */
M2C_UNK UnlinkPairNode(void *);                     /* extern */
M2C_UNK func_00256120(void *, void *);              /* extern */
extern M2C_UNK B_004520A8;
extern M2C_UNK B_00452170;
extern M2C_UNK B_00452188;
extern M2C_UNK B_004521A0;
extern M2C_UNK B_004521B8;
extern M2C_UNK B_004521D0;
extern M2C_UNK B_004521E8;

void CRef_Destruct(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v0_8;
    void *temp_a0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_a1_5;
    void *temp_a1_6;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v0_6;
    void *temp_v0_9;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0);
    switch (temp_v0) {
    case 26:
        temp_a1 = M2C_FIELD(arg0, void **, 4);
        temp_v0_2 = M2C_FIELD(temp_a1, s32 *, 0x10) - 1;
        M2C_FIELD(temp_a1, s32 *, 0x10) = temp_v0_2;
        if (temp_v0_2 == 0) {
            FreeSlotheapPv(&B_00452188, temp_a1);
        }
    default:
        break;
    case 27:
        temp_a1_2 = M2C_FIELD(arg0, void **, 4);
        temp_v0_3 = M2C_FIELD(temp_a1_2, s32 *, 0x40) - 1;
        M2C_FIELD(temp_a1_2, s32 *, 0x40) = temp_v0_3;
        if (temp_v0_3 == 0) {
            FreeSlotheapPv(&B_004521A0, temp_a1_2);
        }
        break;
    case 28:
        temp_a1_3 = M2C_FIELD(arg0, void **, 4);
        temp_v0_4 = M2C_FIELD(temp_a1_3, s32 *, 0x10) - 1;
        M2C_FIELD(temp_a1_3, s32 *, 0x10) = temp_v0_4;
        if (temp_v0_4 == 0) {
            FreeSlotheapPv(&B_004521B8, temp_a1_3);
        }
        break;
    case 29:
        temp_a1_4 = M2C_FIELD(arg0, void **, 4);
        temp_v0_5 = M2C_FIELD(temp_a1_4, s32 *, 8) - 1;
        M2C_FIELD(temp_a1_4, s32 *, 8) = temp_v0_5;
        if (temp_v0_5 == 0) {
            FreeSlotheapPv(&B_004521D0, temp_a1_4);
        }
        break;
    case 30:
        temp_a1_5 = M2C_FIELD(arg0, void **, 4);
        temp_v0_6 = M2C_FIELD(temp_a1_5, void **, 0xC) - 1;
        M2C_FIELD(temp_a1_5, void **, 0xC) = temp_v0_6;
        if (temp_v0_6 == NULL) {
            FreeSlotheapPv(&B_004521E8, temp_a1_5);
        }
        break;
    case 31:
        temp_s0 = M2C_FIELD(arg0, void **, 4);
        temp_v0_7 = M2C_FIELD(temp_s0, s32 *, 0) - 1;
        M2C_FIELD(temp_s0, s32 *, 0) = temp_v0_7;
        if ((temp_v0_7 == 0) && (temp_s0 != NULL)) {
            CPairPtr_Destructor(temp_s0 + 0x10, 2);
            CRef_Destruct(temp_s0 + 8);
            UnlinkPairNode(temp_s0);
            FreeSlotheapPv(&B_004520A8, temp_s0);
        }
        break;
    case 32:
        temp_a0 = M2C_FIELD(arg0, void **, 4);
        temp_v0_8 = M2C_FIELD(temp_a0, s32 *, 0) - 1;
        M2C_FIELD(temp_a0, s32 *, 0) = temp_v0_8;
        if (temp_v0_8 == 0) {
            if (temp_a0 != NULL) {
                CProc_DeletingDestructor(temp_a0, 3);
            }
        }
        break;
    case 33:
        temp_a1_6 = M2C_FIELD(arg0, void **, 4);
        if (temp_a1_6 != NULL) {
            temp_v0_9 = M2C_FIELD(temp_a1_6, void **, 0xC);
            M2C_FIELD(temp_v0_9, M2C_UNK (**)(void *, void *), 0x14)(temp_a1_6 + M2C_FIELD(temp_v0_9, s16 *, 0x10), temp_a1_6);
        }
        break;
    case 34:
        temp_s0_2 = M2C_FIELD(arg0, void **, 4);
        temp_v0_10 = M2C_FIELD(temp_s0_2, s32 *, 0) - 1;
        M2C_FIELD(temp_s0_2, s32 *, 0) = temp_v0_10;
        if ((temp_v0_10 == 0) && (temp_s0_2 != NULL)) {
            func_00256120(temp_s0_2, arg0);
            FreeSlotheapPv(&B_00452170, temp_s0_2);
        }
        break;
    }
}
