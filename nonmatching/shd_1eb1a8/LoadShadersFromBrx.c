#include "m2c_macros.h"

M2C_UNK AppendSlEntry();              /* extern */
M2C_UNK FillShaders__Fi();                          /* extern */
M2C_UNK LoadBitmapsFromBrx();                    /* extern */
M2C_UNK LoadShdFromBrx();                   /* extern */
s32 PqwVifsBitmapUpload__Fi();          /* extern */
s32 PvAllocStackClearImpl__Fi(); /* extern */
s32 PvAllocSwClearImpl__Fi();       /* extern */
s32 U16Read__18CBinaryInputStream();             /* extern */
M2C_UNK func_001EAE40();                         /* extern */
M2C_UNK func_001EB678();                 /* extern */
s32 func_001ED7A8();                    /* extern */
M2C_UNK func_0020F640();                    /* extern */
extern u32 B_003DCFA0;
extern M2C_UNK B_003DCFA8;
extern s32 B_003DCFE8;
extern s32 B_003DCFEC;
extern s32 B_003DD000;
extern s32 B_003DD004;
extern M2C_UNK B_003E1590;

void LoadShadersFromBrx(s32 arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    s32 sp10;
    s32 *temp_v1_2;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    u8 *temp_v1;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s3;
    void *temp_s1;

    var_s2 = 0;
    sp10 = arg1;
    func_001EAE40(arg2);
    LoadBitmapsFromBrx(arg2);
    temp_v0 = U16Read__18CBinaryInputStream(arg2);
    B_003DD000 = temp_v0;
    B_003DD004 = PvAllocStackClearImpl__Fi(sp, temp_v0 * 4, 0x10);
    if (B_003DD000 > 0) {
        do {
            temp_v1 = var_s2 * 4;
            var_s2 += 1;
            *(temp_v1 + B_003DD004) = func_001ED7A8(0, arg2);
        } while (var_s2 < B_003DD000);
    }
    var_s1 = 0;
    temp_v0_2 = U16Read__18CBinaryInputStream(arg2);
    temp_a1 = temp_v0_2 * 0x2C;
    B_003DCFE8 = temp_v0_2;
    B_003DCFEC = PvAllocStackClearImpl__Fi(sp, temp_a1, temp_a1, 0x10);
    if (B_003DCFE8 > 0) {
        var_s0 = 0;
        do {
            var_s1 += 1;
            LoadShdFromBrx(arg2, B_003DCFEC + var_s0);
            var_s0 += 0x2C;
        } while (var_s1 < B_003DCFE8);
    }
    func_0020F640(arg0, arg2);
    temp_v0_3 = PqwVifsBitmapUpload__Fi(sp10, 3);
    if ((temp_v0_3 != 0) && ((u32) B_003DCFA0 < 0x10U)) {
        temp_v1_2 = (B_003DCFA0 * 4) + &B_003DCFA8;
        B_003DCFA0 += 1;
        *temp_v1_2 = temp_v0_3;
    }
    var_s2_2 = 0;
    FillShaders__Fi();
    if (B_003DCFE8 > 0) {
        var_s3 = 0;
        do {
            temp_s1 = B_003DCFEC + var_s3;
            temp_v0_4 = B_003DCFE8;
            if (M2C_FIELD(temp_s1, u8 *, 5) & 0x40) {
                temp_v0_5 = PvAllocSwClearImpl__Fi(sp, 0x1C, 0x10);
                func_001EB678(temp_s1, temp_v0_5);
                AppendSlEntry(&B_003E1590, temp_v0_5);
            }
            var_s2_2 += 1;
            var_s3 += 0x2C;
        } while (var_s2_2 < temp_v0_4);
    }
}
