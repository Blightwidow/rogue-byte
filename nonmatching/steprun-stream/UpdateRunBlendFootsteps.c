#include "m2c_macros.h"

f32 GModPositive__Fff(f32, f32);                    /* extern */
s32 NewEmitter(s32);                                /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
M2C_UNK SetAmbPos(s32, M2C_UNK);                    /* extern */
M2C_UNK SetAmbRange(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK SetAmbVolume(s32, f32);                     /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */

void UpdateRunBlendFootsteps(void *arg0) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    s32 *var_s2;
    s32 temp_v0;
    s32 var_s3;
    s32 var_s5;
    s32 var_s6;
    void *temp_s0;
    void *temp_s4;
    void *temp_v1;

    var_s2 = arg0 + 0x9C;
    var_s5 = 0;
    var_s6 = 0;
    temp_s4 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x50);
    temp_f21 = M2C_FIELD(temp_s4, f32 *, 0x1C);
    do {
        temp_v1 = M2C_FIELD(arg0, void **, 4);
        var_s3 = 1;
        temp_s0 = M2C_FIELD((var_s5 + M2C_FIELD(temp_v1, s32 *, 0xD0)), void **, 8);
        if (!(M2C_FIELD(temp_s0, f32 *, 4) <= GModPositive__Fff(temp_f21 - M2C_FIELD(temp_s0, f32 *, 0), M2C_FIELD(temp_v1, f32 *, 0x74)))) {
            var_s3 = 0;
        }
        if (var_s3 != *var_s2) {
            if (var_s3 == 0) {
                temp_f20 = M2C_FIELD(arg0, f32 *, 0x50);
                temp_f20_2 = (temp_f20 * M2C_FIELD(arg0, f32 *, 0x98)) + ((1.0f - temp_f20) * M2C_FIELD(arg0, f32 *, 0x94));
                temp_v0 = NewEmitter(M2C_FIELD(arg0, s32 *, 0x90));
                SetEmitterUnpositioned(temp_v0, 0);
                PosLoWorld(M2C_FIELD(temp_s4, s32 *, 0x18));
                SetAmbPos(temp_v0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
                SetAmbRange(temp_v0, 0x43FA0000, 0x44FA0000);
                SetAmbVolume(temp_v0, temp_f20_2);
            }
            *var_s2 = var_s3;
        }
        var_s6 += 1;
        var_s2 += 4;
        var_s5 += 0xC;
    } while (var_s6 < 2);
}
