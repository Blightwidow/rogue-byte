#include "m2c_macros.h"

s32 FBlotLabelPlaying(void *, M2C_UNK);             /* extern */
s32 FTaskComplete(void *);                          /* extern */
M2C_UNK UpdateBlotMovie();                          /* extern */
M2C_UNK sprintf(M2C_UNK *, M2C_UNK *, s32);         /* extern */
extern M2C_UNK D_STR_002C3EC0;
extern M2C_UNK RO_002A8AA0;

void JobBlot_Update(void *arg0) {
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    void **var_s0;
    void **var_s0_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_v0;
    void *temp_v0_2;

    var_s1 = 0;
    var_s4 = 0;
    var_s5 = 0;
    var_s3 = 0;
    UpdateBlotMovie();
    if (M2C_FIELD(arg0, s32 *, 0x194) > 0) {
        var_s0 = arg0 + 0x19C;
        do {
            temp_a0 = *var_s0;
            if (temp_a0 != NULL) {
                if (M2C_FIELD(temp_a0, s32 *, 0x54) == 1) {
                    var_s3 += 1;
                } else if (FTaskComplete(temp_a0) != 0) {
                    var_s4 += 1;
                    var_s5 += 1;
                }
            }
            var_s1 += 1;
            var_s0 += 8;
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 0x194));
    }
    var_s1_2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x110) > 0) {
        var_s0_2 = arg0 + 0x118;
        do {
            temp_a0_2 = *var_s0_2;
            if (temp_a0_2 != NULL) {
                if (M2C_FIELD(temp_a0_2, s32 *, 0x54) == 1) {
                    var_s3 += 1;
                } else {
                    var_s4 = (FTaskComplete(temp_a0_2) != 0) ? (var_s4 + 1) : var_s4;
                }
            }
            var_s1_2 += 1;
            var_s0_2 += 8;
        } while (var_s1_2 < M2C_FIELD(arg0, s32 *, 0x110));
    }
    if (FBlotLabelPlaying(arg0, 0x314) != 0) {
        sprintf(&D_STR_002C3EC0, &RO_002A8AA0, var_s5);
        sprintf(&D_STR_002C3EC0 + 0x30, &RO_002A8AA0, M2C_FIELD(arg0, s32 *, 0x194));
        sprintf(&D_STR_002C3EC0 + 0x60, &RO_002A8AA0, M2C_FIELD(arg0, s32 *, 0x194) - var_s5);
    }
    if ((var_s4 == (M2C_FIELD(arg0, s32 *, 0x194) + M2C_FIELD(arg0, s32 *, 0x110))) || (var_s3 == 0)) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x194)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x190));
        return;
    }
    if (var_s3 > 0) {
        temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK), 0x18C)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x188), -1);
    }
}
