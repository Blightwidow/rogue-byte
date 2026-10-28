#include "m2c_macros.h"

M2C_UNK ContinueAmb(void *);                        /* extern */
f32 GSmooth__FfffP3SMPPf(M2C_UNK *, M2C_UNK, f32, f32, f32); /* extern */
M2C_UNK Mount_SetState(void *, M2C_UNK);            /* extern */
M2C_UNK PauseAmb(void *);                           /* extern */
M2C_UNK SetAmbVolume(void *, f32);                  /* extern */
M2C_UNK SetSmaGoal__FP3SMA3OID(s32, M2C_UNK);       /* extern */
s128 SetVectorCylind__FP6VECTORfff(s32, f32, f32, M2C_UNK); /* extern */
M2C_UNK UpdateSo();                                 /* extern */
M2C_UNK func_0012D108(s32, M2C_UNK);                /* extern */
s32 func_0017F550(void *);                          /* extern */
extern M2C_UNK D_002BE7F0;
extern f32 g_2be7e8;
extern f32 g_2dded4;

void Mount_Update(void *arg0) {
    M2C_UNK jtbl_002A5640;
    f32 temp_f0;
    f32 var_f13;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 var_s3;
    u32 temp_v1;
    void *temp_a0_3;
    void *temp_v0;
    void *temp_v1_2;
    void *var_s1;

    UpdateSo();
loop_1:
    if ((M2C_FIELD(arg0, u32 *, 0x1C0) == 2) && (func_0017F550(arg0) != 0)) {
        Mount_SetState(arg0, 1);
    }
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x1C0);
    if (temp_v1 != M2C_FIELD(arg0, u32 *, 0x1C0)) {
        goto loop_1;
    }
    switch (temp_v1) {
    case 0:
    case 2:
    case 3:
    case 4:
        temp_v0 = arg0 + 0x220;
        M2C_FIELD(temp_v0, s32 *, 4) = 0;
        M2C_FIELD(temp_v0, s32 *, 8) = 0;
        M2C_FIELD(arg0, s32 *, 0x220) = 0;
        break;
    case 1:
        temp_v1_2 = M2C_FIELD(arg0, void **, 0x150);
        var_s3 = 0;
        M2C_FIELD(arg0, f32 *, 0x218) = (f32) M2C_FIELD(temp_v1_2, f32 *, 0x18);
        M2C_FIELD(arg0, s32 *, 0x220) = SetVectorCylind__FP6VECTORfff(*((temp_v1 * 4) + &jtbl_002A5640), M2C_FIELD(temp_v1_2, f32 *, 0x18), M2C_FIELD(temp_v1_2, f32 *, 0x1C) * g_2be7e8, 0);
        M2C_ERROR(/* unknown instruction: pextlw $s2, $a0, $s2 */);
        M2C_ERROR(/* unknown instruction: pcpyld $s2, $a0, $s2 */);
        if (M2C_FIELD(arg0, s32 *, 0x230) > 0) {
            var_s1 = arg0 + 0x234;
            do {
                temp_a0 = M2C_FIELD(var_s1, s32 *, 0xC);
                if (temp_a0 != 0) {
                    func_0012D108(temp_a0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s2 */));
                }
                temp_a0_2 = M2C_FIELD(var_s1, s32 *, 0x14);
                if (temp_a0_2 != 0) {
                    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x2C) > 0.0f) {
                        SetSmaGoal__FP3SMA3OID(temp_a0_2, 0x68);
                    } else {
                        SetSmaGoal__FP3SMA3OID(temp_a0_2, 0x66);
                    }
                }
                var_s3 += 1;
                var_s1 += 0x18;
            } while (var_s3 < M2C_FIELD(arg0, s32 *, 0x230));
        }
        break;
    }
    if (M2C_FIELD(arg0, void **, 0x2A4) != NULL) {
        if (M2C_FIELD(arg0, u32 *, 0x1C0) == 1) {
            var_f13 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C);
        } else {
            var_f13 = 0.0f;
        }
        temp_f0 = GSmooth__FfffP3SMPPf(&D_002BE7F0, 0, M2C_FIELD(arg0, f32 *, 0x2AC), var_f13, g_2dded4);
        M2C_FIELD(arg0, f32 *, 0x2AC) = temp_f0;
        SetAmbVolume(M2C_FIELD(arg0, void **, 0x2A4), temp_f0);
        temp_a0_3 = M2C_FIELD(arg0, void **, 0x2A4);
        if (M2C_FIELD(arg0, f32 *, 0x2AC) > 0.0f) {
            if (M2C_FIELD(temp_a0_3, s16 *, 0x4E) > 0) {
                ContinueAmb(temp_a0_3);
            }
        } else if (M2C_FIELD(temp_a0_3, s16 *, 0x4E) <= 0) {
            PauseAmb(temp_a0_3);
        }
    }
}
