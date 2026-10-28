#include "m2c_macros.h"

M2C_UNK BuildPlainBlend(void *, void *, void *);    /* extern */
s32 CreateXfActadj(void *, s32, M2C_UNK);           /* extern */
M2C_UNK EnsureAsegBlendDynamic(void *, M2C_UNK, M2C_UNK, void *); /* extern */
M2C_UNK InitJtLookRig(void *, M2C_UNK);             /* extern */
M2C_UNK PostJtLoad();                               /* extern */
M2C_UNK PostJtLoadSwing(void *, void *, void *);    /* extern */
M2C_UNK PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(void *); /* extern */
s32 PsmaApplySm(s32, s32, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK RemoveXfAct(void *, s32, s32);              /* extern */
M2C_UNK SetJtState(void *, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK SetSoProperties(void *, M2C_UNK, M2C_UNK *); /* extern */
s32 func_0012DC18(void *, s32, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_0018B348(void *);                      /* extern */
M2C_UNK func_001A6CA8(void *, M2C_UNK);             /* extern */
M2C_UNK func_001CC5E8(void *, void *, void *);      /* extern */
s32 func_001F4C58(void *, M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK D_002BF1B0;

void PostSlyLoad(void *arg0) {
    s32 temp_a0_2;
    s32 temp_v0;
    void *temp_a0;

    PostJtLoad();
    SetSoProperties(arg0, 0x12, &D_002BF1B0);
    M2C_FIELD(arg0, s32 *, 0x10B8) = func_001F4C58(arg0, 0x138, 1);
    M2C_FIELD(arg0, s32 *, 0x19E0) = func_001F4C58(arg0, 0x18, 6);
    M2C_FIELD(arg0, s32 *, 0x19DC) = func_001F4C58(arg0, 0x19, 6);
    M2C_FIELD(arg0, s32 *, 0x19D8) = func_001F4C58(arg0, 0x13, 1);
    M2C_FIELD(arg0, s32 *, 0x19D4) = func_001F4C58(arg0, 0x12, 1);
    M2C_FIELD(arg0, s32 *, 0x19D0) = func_001F4C58(arg0, 0x1C, 6);
    M2C_FIELD(arg0, s32 *, 0x19CC) = func_001F4C58(arg0, 0x1D, 6);
    M2C_FIELD(arg0, s32 *, 0x19C8) = func_001F4C58(arg0, 0xD, 1);
    M2C_FIELD(arg0, s32 *, 0x19C4) = func_001F4C58(arg0, 0xC, 1);
    M2C_FIELD(arg0, s32 *, 0x19C0) = func_001F4C58(arg0, 0xC, 6);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(arg0 + 0x1320);
    PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(arg0 + 0x1C30);
    BuildPlainBlend(arg0, arg0 + 0x1AC0, arg0 + 0x1BC0);
    PostJtLoadSwing(arg0, arg0 + 0x1970, arg0 + 0x1994);
    BuildPlainBlend(arg0, arg0 + 0x1E10, arg0 + 0x1F10);
    M2C_FIELD(arg0, s32 *, 0x19E4) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x10B8), 5);
    M2C_FIELD(arg0, s32 *, 0x19E8) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x19C8), 5);
    M2C_FIELD(arg0, s32 *, 0x19EC) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x19C4), 5);
    M2C_FIELD(arg0, s32 *, 0x19F0) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x19D8), 7);
    temp_a0 = M2C_FIELD(arg0, void **, 0x19A0);
    M2C_FIELD(arg0, s32 *, 0x19F4) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x19D4), 7);
    M2C_FIELD(arg0, s32 *, 0x19FC) = CreateXfActadj(temp_a0, M2C_FIELD(temp_a0, s32 *, 0x58), 5);
    M2C_FIELD(arg0, s32 *, 0x19F8) = CreateXfActadj(arg0, M2C_FIELD(arg0, s32 *, 0x19C0), 5);
    temp_v0 = func_0012DC18(arg0, M2C_FIELD(arg0, s32 *, 0x19C0), 5, 5);
    M2C_FIELD(arg0, s32 *, 0x1A00) = temp_v0;
    RemoveXfAct(arg0, M2C_FIELD(arg0, s32 *, 0x19C0), temp_v0);
    InitJtLookRig(arg0, 0x17);
    func_0018B348(arg0);
    EnsureAsegBlendDynamic(arg0, 0xC, 2, arg0 + 0x1A04);
    EnsureAsegBlendDynamic(arg0, 0xC, 2, arg0 + 0x1A20);
    EnsureAsegBlendDynamic(arg0, 0xC, 2, arg0 + 0x1A3C);
    EnsureAsegBlendDynamic(arg0, 0xC, 2, arg0 + 0x1A58);
    BuildPlainBlend(arg0, arg0 + 0x13D0, arg0 + 0x14D0);
    EnsureAsegBlendDynamic(arg0, 0xC, 4, arg0 + 0x1F60);
    EnsureAsegBlendDynamic(arg0, 0xC, 3, arg0 + 0x2014);
    M2C_FIELD(arg0, s32 *, 0x1804) = (s32) M2C_FIELD(arg0, s32 *, 0x19A4);
    func_001CC5E8(arg0 + 0x17D0, arg0, arg0 + 0x18E0);
    SetJtState(arg0, 0, -1);
    func_001A6CA8(arg0, 1);
    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x1D24);
    if (temp_a0_2 != 0) {
        M2C_FIELD(arg0, s32 *, 0x1D28) = PsmaApplySm(temp_a0_2, M2C_FIELD(arg0, s32 *, 0x1D20), -1, 1);
    }
}
