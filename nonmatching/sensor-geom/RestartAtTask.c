#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void **);                     /* extern */
M2C_UNK EndJob(void *, M2C_UNK, M2C_UNK *);         /* extern */
s32 IdCurrentLevel(s32);                            /* extern */
s32 PdescFromLevelRow(s32);                         /* extern */
M2C_UNK RequestTransition(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
M2C_UNK SetCurrentJob(void *);                      /* extern */
M2C_UNK SetTaskState(void *, M2C_UNK);              /* extern */
M2C_UNK SwitchCurrentTask(void *);                  /* extern */
M2C_UNK func_001D8B20(void **, void **, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A5238;

void RestartAtTask(void *arg0) {
    void *sp0;
    void *sp4;
    s32 sp8;
    s32 spC;
    void *sp10;
    void *sp14;
    s32 sp18;
    s32 sp1C;
    void *sp20;
    void *sp24;
    s32 sp28;
    s32 sp2C;
    void *sp30;
    s32 sp34;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v1_2;
    s32 temp_v1_3;
    void *temp_a0;
    void *temp_v1;

    sp0 = NULL;
    sp4 = arg0;
    if (arg0 != NULL) {
        sp8 = M2C_FIELD(arg0, s32 *, 0xF4);
        spC = M2C_FIELD(arg0, s32 *, 0xF8);
        M2C_FIELD(arg0, s32 *, 0xF4) = 2;
        M2C_FIELD(arg0, s32 *, 0xF8) = 0;
    }
    temp_v1 = M2C_FIELD(arg0, void **, 0x7C);
    sp14 = NULL;
    sp10 = temp_v1;
    if (temp_v1 != NULL) {
        sp18 = M2C_FIELD(temp_v1, s32 *, 0xF0);
        M2C_FIELD(temp_v1, s32 *, 0xF0) = 2;
        sp1C = M2C_FIELD(sp10, s32 *, 0xF4);
        M2C_FIELD(sp10, s32 *, 0xF4) = 0;
    }
    if (M2C_FIELD(arg0, void **, 0x7C) != M2C_FIELD(&B_003DD490, void **, 0x3B0C)) {
        if (M2C_FIELD(&B_003DD490, void **, 0x3B0C) != NULL) {
            sp20 = M2C_FIELD(&B_003DD490, void **, 0x3B0C);
            sp24 = NULL;
            temp_v0 = M2C_FIELD(M2C_FIELD(&B_003DD490, void **, 0x3B0C), s32 *, 0xF0);
            sp28 = temp_v0;
            M2C_FIELD(M2C_FIELD(&B_003DD490, void **, 0x3B0C), s32 *, 0xF0) = 2;
            sp2C = M2C_FIELD(sp20, s32 *, 0xF4);
            M2C_FIELD(sp20, s32 *, 0xF4) = 0;
            EndJob(M2C_FIELD(&B_003DD490, void **, 0x3B0C), 2, &B_003DD490);
            if (sp20 != NULL) {
                M2C_FIELD(sp20, s32 *, 0xF0) = temp_v0;
                M2C_FIELD(sp20, s32 *, 0xF4) = sp2C;
            }
            if (sp24 != NULL) {
                M2C_FIELD(sp24, s32 *, 0xF4) = sp28;
                M2C_FIELD(sp24, s32 *, 0xF8) = sp2C;
            }
        }
        temp_a0 = M2C_FIELD(arg0, void **, 0x7C);
        if (temp_a0 != NULL) {
            SetCurrentJob(temp_a0);
        }
    }
    SetTaskState(arg0, 1);
    SwitchCurrentTask(arg0);
    temp_v1_2 = M2C_FIELD(arg0, s32 *, 0xC0);
    if (temp_v1_2 != -1) {
        sp30 = (void *)0x15;
        sp34 = temp_v1_2;
        func_001D8B20(&sp20, &sp30, &RO_002A5238, 0);
        CRef_Destruct(&sp20);
        CRef_Destruct(&sp30);
    }
    temp_v1_3 = M2C_FIELD(arg0, s32 *, 0xB8);
    temp_s1 = (~temp_v1_3 != 0) ? temp_v1_3 : 0x189;
    if ((M2C_FIELD(&B_003DD490, s32 *, 0x3E38) != 0) && ((M2C_FIELD(arg0, s32 *, 0xBC) == -1) || (M2C_FIELD(arg0, s32 *, 0xBC) == IdCurrentLevel(M2C_FIELD(&B_003DD490, s32 *, 0x3E38))))) {

    }
    RequestTransition(&B_003DD490, PdescFromLevelRow(M2C_FIELD(arg0, s32 *, 0xBC)), temp_s1, -1);
    if (sp10 != NULL) {
        M2C_FIELD(sp10, s32 *, 0xF0) = sp18;
        M2C_FIELD(sp10, s32 *, 0xF4) = sp1C;
    }
    if (sp14 != NULL) {
        M2C_FIELD(sp14, s32 *, 0xF4) = sp18;
        M2C_FIELD(sp14, s32 *, 0xF8) = sp1C;
    }
    if (sp0 != NULL) {
        M2C_FIELD(sp0, s32 *, 0xF0) = sp8;
        M2C_FIELD(sp0, s32 *, 0xF4) = spC;
    }
    if (sp4 != NULL) {
        M2C_FIELD(sp4, s32 *, 0xF4) = sp8;
        M2C_FIELD(sp4, s32 *, 0xF8) = spC;
    }
}
