#include "m2c_macros.h"

s32 PvAllocSwImpl__Fi(void *, s32, s32);            /* extern */
M2C_UNK ResolveStringTable(M2C_UNK *);              /* extern */
s32 S16Read__18CBinaryInputStream(s32);             /* extern */
s32 U8Read__18CBinaryInputStream(s32);              /* extern */
M2C_UNK Unknown1__18CBinaryInputStream(s32);        /* extern */
M2C_UNK func_00118380(s32, void *, M2C_UNK *, M2C_UNK); /* extern */
extern s32 B_002E1E54;
extern M2C_UNK B_003E1C20;
extern M2C_UNK g_2dd590;

void LoadSwStringsFromBrx(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 *temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s4;

    var_s0 = 0;
    var_s4 = 0;
    temp_v0 = U8Read__18CBinaryInputStream(arg1);
    if (temp_v0 > 0) {
        do {
            var_s4 = ((U8Read__18CBinaryInputStream(arg1) ^ B_002E1E54) == 0) ? var_s0 : var_s4;
            var_s0 += 1;
        } while (var_s0 < temp_v0);
    }
    var_s0_2 = 0;
    temp_v0_2 = S16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0x4640) = temp_v0_2;
    M2C_FIELD(arg0, s32 *, 0x4644) = PvAllocSwImpl__Fi(sp, temp_v0_2 * 8, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0x4640) > 0) {
loop_5:
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x4644) + (var_s0_2 * 8);
        var_s0_3 = 0;
        *temp_s1 = S16Read__18CBinaryInputStream(arg1);
        if (temp_v0 > 0) {
            do {
                if (var_s0_3 == var_s4) {
                    func_00118380(arg1, temp_s1 + 4, &g_2dd590, 0x2E);
                } else {
                    Unknown1__18CBinaryInputStream(arg1);
                }
                var_s0_3 += 1;
            } while (var_s0_3 < temp_v0);
        }
        var_s0_2 += 1;
        if (var_s0_2 < M2C_FIELD(arg0, s32 *, 0x4640)) {
            goto loop_5;
        }
    }
    ResolveStringTable(&B_003E1C20);
}
