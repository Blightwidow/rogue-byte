#include "m2c_macros.h"

s128 ConvertXfPos();                  /* extern */
s128 ConvertXfVec();                  /* extern */
f32 F32Read__18CBinaryInputStream();             /* extern */
M2C_UNK InsertXfAct();        /* extern */
void *PvAllocAct();                    /* extern */
void *PvAllocSwClearImpl__Fi(); /* extern */
M2C_UNK ReadVector__18CBinaryInputStreamP6VECTOR(); /* extern */
s32 S16Read__18CBinaryInputStream();             /* extern */
s32 S8Read__18CBinaryInputStream();              /* extern */
s32 U8Read__18CBinaryInputStream();              /* extern */
extern M2C_UNK D_002DB338;

void func_0021C888(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 sp10;
    s32 sp14;
    s128 temp_a1;
    s128 var_v0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_s6;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_s2;
    void *temp_s2_2;
    void *temp_s3;
    void *temp_v0_3;
    void *temp_v0_4;

    var_s0 = 0;
    temp_v0 = S8Read__18CBinaryInputStream(arg1);
    sp10 = temp_v0;
    if (temp_v0 > 0) {
        do {
            var_s4 = 0;
            sp14 = var_s0 + 1;
            temp_s3 = PvAllocSwClearImpl__Fi(sp, 0x50, 0x10);
            M2C_FIELD(temp_s3, s32 *, 8) = U8Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s3, f32 *, 0xC) = F32Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s3, f32 *, 0x10) = F32Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s3, f32 *, 0x14) = F32Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s3, f32 *, 0x18) = F32Read__18CBinaryInputStream(arg1);
            ReadVector__18CBinaryInputStreamP6VECTOR(arg1, temp_s3 + 0x20);
            ReadVector__18CBinaryInputStreamP6VECTOR(arg1, temp_s3 + 0x30);
            temp_v0_2 = S8Read__18CBinaryInputStream(arg1);
            M2C_FIELD(temp_s3, s32 *, 0) = temp_v0_2;
            M2C_FIELD(temp_s3, void **, 4) = PvAllocSwClearImpl__Fi(sp, 0x10, temp_v0_2 * 0x70, 0x10);
            if (M2C_FIELD(temp_s3, s32 *, 0) > 0) {
                var_s6 = 0;
                do {
                    var_s4 += 1;
                    temp_s2 = M2C_FIELD(temp_s3, void **, 4) + var_s6;
                    M2C_FIELD(temp_s2, void **, 0x60) = temp_s3;
                    var_s6 += 0x70;
                    temp_s0 = M2C_FIELD(arg0, void **, 0xC);
                    temp_s0_2 = temp_s0 + 0x198;
                    temp_s1 = arg0 + M2C_FIELD(temp_s0, s16 *, 0x198);
                    temp_v0_3 = M2C_FIELD(temp_s0_2, void *(**)(void *, s32), 4)(temp_s1, S16Read__18CBinaryInputStream(arg1));
                    M2C_FIELD(temp_s2, void **, 0x64) = temp_v0_3;
                    M2C_FIELD(temp_s2, s128 *, 0) = (s128) M2C_FIELD(temp_v0_3, s128 *, 0);
                    temp_a1 = M2C_FIELD(temp_v0_3, s128 *, 0x10);
                    M2C_FIELD(temp_s2, s128 *, 0x10) = temp_a1;
                    M2C_FIELD(temp_s2, s128 *, 0x20) = (s128) M2C_FIELD(temp_v0_3, s128 *, 0x20);
                    temp_v0_4 = PvAllocAct(0x20, temp_a1);
                    M2C_FIELD(temp_v0_4, s32 *, 0) = 3;
                    M2C_FIELD(temp_v0_4, M2C_UNK **, 0x18) = &D_002DB338;
                    M2C_FIELD(temp_v0_4, void **, 4) = arg0;
                    M2C_FIELD(temp_v0_4, s32 *, 0xC) = -1;
                    M2C_FIELD(temp_v0_4, void **, 8) = (void *) M2C_FIELD(temp_s2, void **, 0x64);
                    M2C_FIELD(temp_v0_4, void **, 0x1C) = temp_s2;
                    M2C_FIELD(temp_v0_4, s32 *, 0x14) = 0x10;
                    InsertXfAct(arg0, M2C_FIELD(temp_s2, void **, 0x64), temp_v0_4);
                    M2C_FIELD(M2C_FIELD(temp_s2, void **, 0x64), void **, 0xA8) = temp_s2;
                } while (var_s4 < M2C_FIELD(temp_s3, s32 *, 0));
            }
            var_s4_2 = 0;
            if (M2C_FIELD(temp_s3, s32 *, 0) > 0) {
                var_s0_2 = 0;
                do {
                    temp_s2_2 = M2C_FIELD(temp_s3, void **, 4) + var_s0_2;
                    if (var_s4_2 < (M2C_FIELD(temp_s3, s32 *, 0) - 1)) {
                        var_v0 = ConvertXfPos(0, M2C_FIELD(temp_s2_2, s32 *, 0x64), M2C_FIELD(M2C_FIELD(temp_s2_2, void **, 0xD4), s128 *, 0x70));
                    } else if (var_s4_2 <= 0) {
                        var_v0 = M2C_FIELD(temp_s3, s128 *, 0x30);
                    } else {
                        var_v0 = ConvertXfVec(M2C_FIELD(temp_s2_2, s32 *, -0xC), M2C_FIELD(temp_s2_2, s32 *, 0x64), M2C_FIELD(temp_s2_2, s128 *, -0x40));
                    }
                    M2C_FIELD(temp_s2_2, s128 *, 0x30) = var_v0;
                    var_s4_2 += 1;
                    var_s0_2 += 0x70;
                    M2C_FIELD(temp_s2_2, s128 *, 0x40) = ConvertXfPos(M2C_FIELD(temp_s2_2, s32 *, 0x64), 0, M2C_FIELD(temp_s2_2, s128 *, 0x30));
                } while (var_s4_2 < M2C_FIELD(temp_s3, s32 *, 0));
            }
            var_s0 = sp14;
        } while (var_s0 < sp10);
    }
}
