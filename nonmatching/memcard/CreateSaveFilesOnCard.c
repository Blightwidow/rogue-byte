#include "m2c_macros.h"

M2C_UNK BuildSlotFilePath(void *, void *, M2C_UNK *); /* extern */
s32 CreateSaveDirectory(void *, s32);               /* extern */
M2C_UNK DeleteMemcardFile(void *, M2C_UNK *);       /* extern */
s32 FUN_0018c1e8(M2C_UNK *);                        /* extern */
s32 InitAndWriteSaveSlot(void *, void *);           /* extern */
s32 McSync(s32, s32, M2C_UNK, s32 *);               /* extern */
M2C_UNK func_001ACC38(M2C_UNK *, M2C_UNK);          /* extern */
s32 sceMcGetEntSpace(s32, s32, M2C_UNK *);          /* extern */
extern M2C_UNK B_002E6550;
extern M2C_UNK RO_002A38E8;
extern M2C_UNK RO_002A6BB0;
extern M2C_UNK RO_002A6BC8;

s32 CreateSaveFilesOnCard(void *arg0) {
    char sp[0x400];
    s32 sp50;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s3;
    s32 var_v0;
    void *temp_a1_2;
    void *var_s0;

    var_s3 = McSync(arg0 + 0xFD5C, sceMcGetEntSpace(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4), "/"), 0x12, &sp50);
    if (var_s3 == 0) {
        temp_v0 = FUN_0018c1e8(&RO_002A38E8);
        temp_a1 = temp_v0 + 0x3FF;
        var_s3 = 1;
        if (M2C_FIELD(arg0, s32 *, 0x1C) >= (((sp50 == 0) ? 2 : 1) + 5 + ((s32) ((temp_a1 > -1) ? temp_a1 : (temp_v0 + 0x7FE)) >> 0xA) + 0x42)) {
            var_s3 = CreateSaveDirectory(arg0, temp_a1);
            var_s0 = arg0 + 0x24;
            if (var_s3 == 0) {
                var_s2 = 0;
loop_4:
                var_s3 = InitAndWriteSaveSlot(arg0, var_s0);
                var_s2 += 1;
                if (var_s3 == 0) {
                    var_s0 += 0x5464;
                    if (var_s2 >= 3) {
                        if (M2C_FIELD(arg0, s32 *, 0xC) < 5) {
                            M2C_FIELD(arg0, s32 *, 0xC) = 5;
                        }
                        goto block_14;
                    }
                    goto loop_4;
                }
                var_s0 = arg0 + 0x24;
                goto block_9;
            }
block_9:
            var_s2_2 = 2;
            do {
                temp_a1_2 = var_s0;
                var_s0 += 0x5464;
                BuildSlotFilePath(arg0, temp_a1_2, sp);
                var_s2_2 -= 1;
                DeleteMemcardFile(arg0, sp);
            } while (var_s2_2 >= 0);
            DeleteMemcardFile(arg0, "/BASCUS-97316YAOTWTD!/icon.sys");
            DeleteMemcardFile(arg0, "/BASCUS-97316YAOTWTD!/memcard_icon.ico");
            DeleteMemcardFile(arg0, &RO_002A6BC8);
            DeleteMemcardFile(arg0, &RO_002A6BB0);
            goto block_12;
        }
block_12:
        var_v0 = var_s3;
        if (var_s3 != 0) {
            goto block_13;
        }
    } else {
block_13:
        func_001ACC38(&B_002E6550, 3);
block_14:
        var_v0 = var_s3;
    }
    return var_v0;
}
