#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_ReadVector4();   /* extern */
s32 PvAllocSwClearImpl__Fi();       /* extern */
s32 PvAllocSwImpl__Fi();            /* extern */
s32 S32Read__18CBinaryInputStream();             /* extern */
s16 U16Read__18CBinaryInputStream();             /* extern */
s32 U32Read__18CBinaryInputStream();             /* extern */

void LoadPzgraphFromBrx(void *arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    s32 temp_a1;
    s32 temp_v0;
    u8 *temp_v1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    void *temp_s0;

    M2C_FIELD(arg0, s32 *, 0) = arg1;
    var_s2 = 0;
    M2C_FIELD(arg0, s32 *, 8) = U32Read__18CBinaryInputStream(arg2);
    M2C_FIELD(arg0, s32 *, 0x10) = U32Read__18CBinaryInputStream(arg2);
    M2C_FIELD(arg0, s32 *, 4) = PvAllocSwImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0) * 8, 0x10);
    M2C_FIELD(arg0, s32 *, 0xC) = PvAllocSwImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 8) * 0x10, 0x10);
    M2C_FIELD(arg0, s32 *, 0x18) = PvAllocSwClearImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0x10) * 4, 0x10);
    M2C_FIELD(arg0, s32 *, 0x14) = PvAllocSwImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0x10) * 4, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0) > 0) {
        do {
            temp_v0 = var_s2 * 8;
            var_s2 += 1;
            temp_s0 = M2C_FIELD(arg0, s32 *, 4) + temp_v0;
            M2C_FIELD(temp_s0, s32 *, 0) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + (U16Read__18CBinaryInputStream(arg2) * 0x10));
            M2C_FIELD(temp_s0, s16 *, 4) = U16Read__18CBinaryInputStream(arg2);
            M2C_FIELD(temp_s0, s16 *, 6) = U16Read__18CBinaryInputStream(arg2);
        } while (var_s2 < M2C_FIELD(arg0, s32 *, 0));
    }
    var_s0 = 0;
    if (M2C_FIELD(arg0, s32 *, 8) > 0) {
loop_4:
        temp_a1 = var_s0 * 0x10;
        var_s0 += 1;
        CBinaryInputStream_ReadVector4(arg2, M2C_FIELD(arg0, s32 *, 0xC) + temp_a1);
        if (var_s0 < M2C_FIELD(arg0, s32 *, 8)) {
            goto loop_4;
        }
    }
    var_s0_2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x10) > 0) {
        do {
            temp_v1 = var_s0_2 * 4;
            var_s0_2 += 1;
            *(temp_v1 + M2C_FIELD(arg0, s32 *, 0x14)) = S32Read__18CBinaryInputStream(arg2);
        } while (var_s0_2 < M2C_FIELD(arg0, s32 *, 0x10));
    }
}
