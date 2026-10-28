#include "m2c_macros.h"

M2C_UNK Clear__13CFileLocation(void *);             /* extern */
M2C_UNK PauseAmb(void *, s32);                      /* extern */
M2C_UNK SetAmbGrf(void *, M2C_UNK, M2C_UNK);        /* extern */
s32 func_001FD080(M2C_UNK *, void *);               /* extern */
M2C_UNK func_00233130(M2C_UNK, M2C_UNK, M2C_UNK, s32 *); /* extern */
extern M2C_UNK B_003DD040;

void StartStreamAmb(void *arg0) {
    char sp[0x400];
    s32 sp0;
    s32 sp4;
    s32 sp8;
    s32 sp110;
    f32 sp114;
    s32 sp118;
    s32 sp11C;
    s32 sp120;
    s32 sp124;
    M2C_UNK var_a1_2;
    s32 temp_a0;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;
    s32 var_v0;
    void *temp_v0_2;
    void *var_a1;

    sp8 = 2;
    Clear__13CFileLocation(sp);
    var_a1 = M2C_FIELD(arg0, void **, 0x60);
    temp_s2 = func_001FD080(&B_003DD040, M2C_FIELD(arg0, void **, 0x60));
    if (var_a1 == NULL) {
        var_v0 = 0;
    } else {
        temp_a0 = M2C_FIELD(var_a1, s32 *, 0x34);
        temp_v0 = M2C_FIELD(var_a1, s32 *, 0);
        temp_v1 = M2C_FIELD(var_a1, s32 *, 4);
        var_a1 = M2C_FIELD(var_a1, void **, 0x3C);
        sp8 = 2;
        sp0 = (temp_v0 ^ temp_a0) + 0xCA0;
        sp4 = temp_v1 ^ (s32) var_a1;
        var_v0 = temp_v1 != (s32) var_a1;
    }
    if (var_v0 != 0) {
        if (sp8 != 2) {
            var_a1_2 = 0x1FFF;
        } else {
            sp110 = sp0;
            PauseAmb(arg0, (s32) var_a1);
            var_a2 = 0;
            sp120 = M2C_FIELD(arg0, s32 *, 0x3B8) | 1;
            sp118 = M2C_FIELD(arg0, s32 *, 0x14);
            sp114 = 1024.0f;
            sp11C = temp_s2;
            if ((M2C_FIELD(&B_003DD040, s32 *, 0x10) != 0) && (temp_s2 == sp8)) {
                var_a2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s32 *, 0x4C) == 0;
            }
            sp124 = var_a2;
            M2C_FIELD(arg0, s16 *, 0x52) = 1;
            temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK *, s32), 0xC)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 8), &B_003DD040, var_a2);
            func_00233130(0x524B5553, 1, 0x18, &sp110);
            var_a1_2 = 0x3F;
        }
        SetAmbGrf(arg0, var_a1_2, 0);
        return;
    }
    SetAmbGrf(arg0, 0x1FFF, 0);
}
