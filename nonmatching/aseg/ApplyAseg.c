#include "m2c_macros.h"

M2C_UNK AppendDlEntry(M2C_UNK *, void *);           /* extern */
M2C_UNK BindAsegChn(void *, s32, void *, s32 *);    /* extern */
M2C_UNK CFramePtr_Assign(void *, s32);              /* extern */
f32 GetSuck(M2C_UNK *);                             /* extern */
M2C_UNK HandleAsegaEvent(void *, s32);              /* extern */
M2C_UNK HandleAsegaEventsFF(void *);                /* extern */
M2C_UNK InsertXfAct(s32, s32, void *);              /* extern */
void *PvAllocAct(M2C_UNK);                          /* extern */
void *PvAllocSlotheapImpl(M2C_UNK *);               /* extern */
M2C_UNK SetAsegaHandsOff(void *, s32);              /* extern */
M2C_UNK SetAsegaSpeed(void *, f32);                 /* extern */
M2C_UNK SnapAsega(void *, s32);                     /* extern */
M2C_UNK UpdateAsegaIeaCur__FP5ASEGA(void *);        /* extern */
void *func_0012CE50(M2C_UNK);                       /* extern */
M2C_UNK func_00130010(void *, s32, void *, void **); /* extern */
M2C_UNK func_001F8668(s32, M2C_UNK);                /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK B_002DE578;
extern M2C_UNK B_003E1218;
extern M2C_UNK B_003E1224;
extern M2C_UNK D_002CAF08;
extern M2C_UNK D_002CAF48;

void ApplyAseg(void *arg0, s32 arg1, s32 arg2, void **arg3, f32 fparg0, f32 fparg1) {
    void *sp0;
    s32 sp4;
    s32 sp8;
    void *spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    M2C_UNK *temp_v0_3;
    M2C_UNK *temp_v0_4;
    M2C_UNK *temp_v1;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f3;
    s32 temp_a1;
    s32 temp_v0_6;
    s32 var_s0;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s4;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_5;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;

    temp_v0 = PvAllocSlotheapImpl(&B_003E1224);
    memset(temp_v0, 0, 0x60);
    M2C_FIELD(temp_v0, s32 *, 0) = 0;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = &D_002CAF48;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 0;
    M2C_FIELD(temp_v0, void **, 0x14) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0x18) = arg1;
    M2C_FIELD(temp_v0, f32 *, 0x1C) = fparg0;
    M2C_FIELD(temp_v0, s32 *, 0x3C) = arg2;
    M2C_FIELD(temp_v0, f32 *, 0x48) = (f32) M2C_FIELD(arg0, f32 *, 0x78);
    temp_f0 = GetSuck(&B_002DE578);
    temp_v0_2 = arg0 + 0x80;
    temp_f4 = M2C_FIELD(arg0, f32 *, 0x90);
    var_f3 = M2C_FIELD(arg0, f32 *, 0x80) + (temp_f0 * (M2C_FIELD(temp_v0_2, f32 *, 4) + (temp_f0 * M2C_FIELD(temp_v0_2, f32 *, 8))));
    temp_f5 = M2C_FIELD(arg0, f32 *, 0x94);
    if (var_f3 < temp_f4) {
        var_f3 = temp_f4;
    } else if (temp_f5 < var_f3) {
        var_f3 = temp_f5;
    }
    M2C_FIELD(temp_v0, f32 *, 0x4C) = var_f3;
    SetAsegaSpeed(temp_v0, fparg1);
    AppendDlEntry(&B_003E1218, temp_v0);
    AppendDlEntry(arg0 + 0x50, temp_v0);
    temp_v0_3 = M2C_FIELD(temp_v0, M2C_UNK **, 0xC);
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *), 0xC)(temp_v0 + M2C_FIELD(temp_v0_3, s16 *, 8));
    sp0 = temp_v0;
    temp_v0_4 = M2C_FIELD(temp_v0, M2C_UNK **, 0xC);
    M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *), 0xC)(temp_v0 + M2C_FIELD(temp_v0_4, s16 *, 8));
    CFramePtr_Assign(temp_v0, M2C_FIELD(arg0, s32 *, 0));
    if (arg3 != NULL) {
        *arg3 = temp_v0;
    }
    sp18 = arg2 >> 2;
    var_s3 = 0;
    sp14 = arg2 & 2;
    if (M2C_FIELD(arg0, s32 *, 0x5C) > 0) {
        do {
            temp_s0 = M2C_FIELD(arg0, s32 *, 0x60) + (var_s3 * 8);
            if (!(M2C_FIELD(temp_s0, s32 *, 0) & 0x40000000)) {
                BindAsegChn(arg0, arg1, temp_s0, &sp4);
                if (sp8 != 0) {
                    func_001F8668(sp4, 0);
                    temp_v0_5 = PvAllocAct(0x2C);
                    M2C_FIELD(temp_v0_5, M2C_UNK **, 0x18) = &D_002CAF08;
                    M2C_FIELD(temp_v0_5, s32 *, 0) = 0;
                    temp_v0_6 = M2C_FIELD(temp_s0, s32 *, 4);
                    if (M2C_FIELD(temp_s0, s32 *, 0) & 0x80000000) {
                        M2C_FIELD(temp_v0_5, s32 *, 0x20) = temp_v0_6;
                    } else {
                        M2C_FIELD(temp_v0_5, s32 *, 0x1C) = temp_v0_6;
                    }
                    M2C_FIELD(temp_v0_5, s32 *, 4) = sp4;
                    M2C_FIELD(temp_v0_5, s32 *, 8) = sp8;
                    M2C_FIELD(temp_v0_5, s32 *, 0x14) = (s32) ((arg2 & 1) ? 7 : 5);
                    M2C_FIELD(temp_v0_5, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x6C);
                    M2C_FIELD(temp_v0_5, void **, 0x24) = temp_v0;
                    M2C_FIELD(temp_v0_5, void **, 0x28) = (void *) M2C_FIELD(temp_v0, void **, 0x34);
                    M2C_FIELD(temp_v0, void **, 0x34) = temp_v0_5;
                    InsertXfAct(sp4, sp8, temp_v0_5);
                }
            }
            var_s3 += 1;
        } while (var_s3 < M2C_FIELD(arg0, s32 *, 0x5C));
    }
    var_s3_2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x64) > 0) {
        var_s4 = 0;
        do {
            temp_s0_2 = M2C_FIELD(arg0, s32 *, 0x68) + var_s4;
            func_00130010(arg0, arg1, temp_s0_2, &spC);
            if (sp10 != 0) {
                temp_v0_7 = func_0012CE50(0x14);
                M2C_FIELD(temp_v0_7, s32 *, 0) = (s32) M2C_FIELD(temp_s0_2, s32 *, 8);
                M2C_FIELD(temp_v0_7, s32 *, 4) = sp10;
                M2C_FIELD(temp_v0_7, void **, 8) = spC;
                M2C_FIELD(temp_v0_7, s32 *, 0xC) = (s32) M2C_FIELD(temp_s0_2, s32 *, 0);
                M2C_FIELD(temp_v0_7, void **, 0x10) = (void *) M2C_FIELD(temp_v0, void **, 0x38);
                M2C_FIELD(temp_v0, void **, 0x38) = temp_v0_7;
                temp_v0_8 = M2C_FIELD(spC, void **, 0xC);
                M2C_FIELD(temp_v0_8, M2C_UNK (**)(void *, s32, void *), 0x164)(spC + M2C_FIELD(temp_v0_8, s16 *, 0x160), M2C_FIELD(temp_s0_2, s32 *, 0), spC);
            }
            var_s3_2 += 1;
            var_s4 += 0xC;
        } while (var_s3_2 < M2C_FIELD(arg0, s32 *, 0x64));
    }
    var_s0 = 0;
    SetAsegaHandsOff(temp_v0, M2C_FIELD(arg0, s32 *, 0x70));
    M2C_FIELD(temp_v0, f32 *, 0x20) = fparg0;
    if (M2C_FIELD(arg0, s32 *, 0x98) > 0) {
loop_22:
        temp_a1 = var_s0 * 0x10;
        var_s0 += 1;
        HandleAsegaEvent(temp_v0, M2C_FIELD(arg0, s32 *, 0x9C) + temp_a1);
        if (var_s0 < M2C_FIELD(arg0, s32 *, 0x98)) {
            goto loop_22;
        }
    }
    M2C_FIELD(temp_v0, f32 *, 0x1C) = (f32) M2C_FIELD(temp_v0, f32 *, 0x20);
    SnapAsega(temp_v0, sp18 & 1);
    if (sp14 != 0) {
        if (M2C_FIELD(temp_v0, f32 *, 0x40) < 0.0f) {
            M2C_FIELD(temp_v0, s32 *, 0x50) = (s32) M2C_FIELD(arg0, s32 *, 0xA0);
        }
        HandleAsegaEventsFF(temp_v0);
    } else {
        UpdateAsegaIeaCur__FP5ASEGA(temp_v0);
    }
    temp_v1 = M2C_FIELD(temp_v0, M2C_UNK **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(temp_v0 + M2C_FIELD(temp_v1, s16 *, 0x18), 2, 0, 0);
    temp_v0_9 = M2C_FIELD(sp0, void **, 0xC);
    M2C_FIELD(temp_v0_9, M2C_UNK (**)(void *, void *), 0x14)(sp0 + M2C_FIELD(temp_v0_9, s16 *, 0x10), sp0);
}
