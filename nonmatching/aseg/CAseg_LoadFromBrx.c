#include "m2c_macros.h"

f32 F32Read__18CBinaryInputStream();             /* extern */
M2C_UNK LoadAsegEventsFromBrx(); /* extern */
M2C_UNK LoadOptionsFromBrx__FPvP18CBinaryInputStream(); /* extern */
void **PacpNew__F4ACVK();                        /* extern */
void **PacrNew();                                /* extern */
s32 PvAllocSwClearImpl__Fi();  /* extern */
s32 PvAllocSwImpl__Fi();            /* extern */
s32 S16Read__18CBinaryInputStream();    /* extern */
s32 S32Read__18CBinaryInputStream();             /* extern */
s32 S8Read__18CBinaryInputStream();              /* extern */
s32 U8Read__18CBinaryInputStream();              /* extern */

void LoadAsegFromBrx(void *arg0, s32 arg1) {
    char sp[0x400];
    void *sp10;
    void *sp14;
    M2C_UNK (*temp_a2)(void *, s32, M2C_UNK);
    M2C_UNK (*temp_a2_2)(void *, s32, M2C_UNK);
    M2C_UNK (*temp_a2_3)(void *, s32, M2C_UNK);
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s4;
    void **temp_v0_3;
    void **temp_v0_5;
    void **temp_v0_7;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;

    var_s3 = 0;
    M2C_FIELD(arg0, f32 *, 0x74) = F32Read__18CBinaryInputStream(arg1);
    temp_v0 = S16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_v0;
    M2C_FIELD(arg0, s32 *, 0x60) = PvAllocSwImpl__Fi(sp, temp_v0 * 8, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0x5C) > 0) {
loop_2:
        temp_s0 = M2C_FIELD(arg0, s32 *, 0x60) + (var_s3 * 8);
        M2C_FIELD(temp_s0, s32 *, 0) = (s32) ((M2C_FIELD(temp_s0, s32 *, 0) & 0xFFF00000) | (S32Read__18CBinaryInputStream(arg1) & 0xFFFFF));
        M2C_FIELD(temp_s0, s32 *, 0) = (s32) ((M2C_FIELD(temp_s0, s32 *, 0) & 0xC00FFFFF) | ((S16Read__18CBinaryInputStream(arg1, 0xFFF00000) & 0x3FF) << 0x14));
        temp_v0_2 = S8Read__18CBinaryInputStream(arg1);
        if (temp_v0_2 != -1) {
            temp_v0_3 = PacrNew(temp_v0_2);
            M2C_FIELD(temp_s0, void ***, 4) = temp_v0_3;
            temp_v1 = *temp_v0_3;
            temp_a2 = M2C_FIELD(temp_v1, M2C_UNK (**)(void *, s32, M2C_UNK), 0xC);
            temp_a2(temp_v0_3 + M2C_FIELD(temp_v1, s16 *, 8), arg1, temp_a2);
            M2C_FIELD(temp_s0, s32 *, 0) = (s32) (M2C_FIELD(temp_s0, s32 *, 0) & 0x7FFFFFFF);
        }
        temp_v0_4 = S8Read__18CBinaryInputStream(arg1);
        if (temp_v0_4 != -1) {
            temp_v0_5 = PacpNew__F4ACVK(temp_v0_4);
            M2C_FIELD(temp_s0, void ***, 4) = temp_v0_5;
            temp_v1_2 = *temp_v0_5;
            temp_a2_2 = M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, s32, M2C_UNK), 0xC);
            temp_a2_2(temp_v0_5 + M2C_FIELD(temp_v1_2, s16 *, 8), arg1, temp_a2_2);
            M2C_FIELD(temp_s0, s32 *, 0) = (s32) (M2C_FIELD(temp_s0, s32 *, 0) | 0x80000000);
        }
        var_s3 += 1;
        M2C_FIELD(temp_s0, s32 *, 0) = (s32) ((M2C_FIELD(temp_s0, s32 *, 0) & 0xBFFFFFFF) | ((U8Read__18CBinaryInputStream(arg1) != 0) << 0x1E));
        if (var_s3 < M2C_FIELD(arg0, s32 *, 0x5C)) {
            goto loop_2;
        }
    }
    var_s3_2 = 0;
    temp_v0_6 = U8Read__18CBinaryInputStream(arg1);
    sp10 = arg0 + 0x98;
    temp_a1 = temp_v0_6 * 0xC;
    M2C_FIELD(arg0, s32 *, 0x64) = temp_v0_6;
    sp14 = arg0 + 0xA8;
    M2C_FIELD(arg0, s32 *, 0x68) = PvAllocSwClearImpl__Fi(sp, temp_a1, temp_a1, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0x64) > 0) {
        var_s4 = 0;
        do {
            var_s3_2 += 1;
            temp_s0_2 = M2C_FIELD(arg0, s32 *, 0x68) + var_s4;
            var_s4 += 0xC;
            M2C_FIELD(temp_s0_2, s32 *, 0) = U8Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s0_2, s32 *, 4) = S32Read__18CBinaryInputStream(arg1);
            temp_v0_7 = PacpNew__F4ACVK(S8Read__18CBinaryInputStream(arg1));
            M2C_FIELD(temp_s0_2, void ***, 8) = temp_v0_7;
            temp_v1_3 = *temp_v0_7;
            temp_a2_3 = M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, s32, M2C_UNK), 0xC);
            temp_a2_3(temp_v0_7 + M2C_FIELD(temp_v1_3, s16 *, 8), arg1, temp_a2_3);
        } while (var_s3_2 < M2C_FIELD(arg0, s32 *, 0x64));
    }
    LoadAsegEventsFromBrx(arg0, arg1, 0, sp10);
    LoadAsegEventsFromBrx(arg0, arg1, 1, arg0 + 0xA0);
    LoadAsegEventsFromBrx(arg0, arg1, 0, sp14);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(arg0, arg1);
}
