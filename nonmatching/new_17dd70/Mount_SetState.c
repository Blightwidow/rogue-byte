#include "m2c_macros.h"

M2C_UNK ConvertXfMatrix4(s128 *, s32, s32, void *); /* extern */
M2C_UNK DecomposeRotateMatrixEuler(void *);         /* extern */
M2C_UNK Mount_UpdateHealthBlot(void *);             /* extern */
s32 NewEmitter(s32);                                /* extern */
M2C_UNK PauseAmb(s32);                              /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
M2C_UNK SetSmaGoal__FP3SMA3OID(s32, M2C_UNK);       /* extern */
M2C_UNK SetSoCnstrForce(void *, M2C_UNK);           /* extern */
M2C_UNK SetSoCnstrTorque(void *, M2C_UNK);          /* extern */
M2C_UNK SetXfKind(void *, void *, M2C_UNK);         /* extern */
M2C_UNK StopAmb(s32, M2C_UNK);                      /* extern */
M2C_UNK VirtualRefPtr_Assign(void *, s32);          /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
s32 func_0012DC18(void *, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0012E460(void *);                      /* extern */
M2C_UNK func_0017F4C0(void *, void *);              /* extern */
M2C_UNK func_001A58D0(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_001F68A8(void *, M2C_UNK);             /* extern */
M2C_UNK func_00213B00(void *, M2C_UNK);             /* extern */
extern M2C_UNK B_002DEB30;
extern s128 g_2a2dd0;
extern f32 g_2dded0;

void Mount_SetState(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp50;
    M2C_UNK sp60;
    M2C_UNK sp70;
    s128 sp30;
    s128 sp40;
    s32 *var_s0;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0_2;
    s32 var_s2;
    void *temp_a1;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_t0;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v1;
    void *var_a1;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x1C0);
    if (arg1 != temp_s0) {
        if (temp_s0 != 1) {
            if (temp_s0 < 2) {
                if (temp_s0 != -1) {

                } else {
                    temp_a2 = M2C_FIELD(arg0, void **, 0x2A0);
                    if (temp_a2 != NULL) {
                        temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
                        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x18C)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x188), -1, temp_a2);
                        func_00213B00(M2C_FIELD(arg0, void **, 0x2A0), 0x34F);
                        Mount_UpdateHealthBlot(arg0);
                        temp_a0 = M2C_FIELD(arg0, s32 *, 0x2A8);
                        if (temp_a0 != temp_s0) {
                            temp_v0_2 = NewEmitter(temp_a0);
                            SetEmitterUnpositioned(temp_v0_2, 0);
                            VirtualRefPtr_Assign(arg0 + 0x2A4, temp_v0_2);
                            PauseAmb(M2C_FIELD(arg0, s32 *, 0x2A4));
                        }
                    }
                }
                goto block_16;
            }
            if (temp_s0 != 3) {
                M2C_FIELD(arg0, s32 *, 0x1C0) = arg1;
            } else {
                func_0012E460(arg0 + 0x298);
                func_0012E460(arg0 + 0x29C);
                SetXfKind(arg0, M2C_FIELD(arg0, void **, 0x58), 2);
                SetXfKind(arg0, M2C_FIELD(arg0, void **, 0x5C), 2);
                func_001A58D0(arg0, 0, 0xF);
                SetSoCnstrForce(arg0, 5);
                SetSoCnstrTorque(arg0, 4);
                func_001F68A8(arg0, 0);
                M2C_FIELD(arg0, void **, 0x294) = NULL;
                goto block_16;
            }
        } else {
            var_s2 = 0;
            if (M2C_FIELD(arg0, s32 *, 0x230) > 0) {
                var_s0 = arg0 + 0x248;
                do {
                    temp_a0_2 = *var_s0;
                    if (temp_a0_2 != 0) {
                        SetSmaGoal__FP3SMA3OID(temp_a0_2, 0x66);
                    }
                    var_s2 += 1;
                    var_s0 += 0x18;
                } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x230));
            }
block_16:
            M2C_FIELD(arg0, s32 *, 0x1C0) = arg1;
        }
        M2C_FIELD(arg0, f32 *, 0x1C4) = (f32) g_2dded0;
        switch (arg1) {                             /* irregular */
        case -1:
            temp_a1 = M2C_FIELD(arg0, void **, 0x2A0);
            if (temp_a1 != NULL) {
                temp_v0_3 = M2C_FIELD(temp_a1, void **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *), 0x194)(temp_a1 + M2C_FIELD(temp_v0_3, s16 *, 0x190), temp_a1);
            }
            temp_a0_3 = M2C_FIELD(arg0, s32 *, 0x2A4);
            if (temp_a0_3 != 0) {
                StopAmb(temp_a0_3, 0);
                VirtualRefPtr_Assign(arg0 + 0x2A4, 0);
            }
            break;
        case 3:
            temp_a2_2 = M2C_FIELD(arg0, void **, 0x294);
            temp_v1 = M2C_FIELD(temp_a2_2, void **, 0xC);
            temp_s0_2 = M2C_FIELD(temp_v1, s32 (**)(void *, void *, void *), 0x104)(temp_a2_2 + M2C_FIELD(temp_v1, s16 *, 0x100), sp, temp_a2_2);
            ConvertXfMatrix4(&sp40, M2C_FIELD(M2C_FIELD(arg0, void **, 0x54), s32 *, 0xA0), M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s32 *, 0xA0), sp);
            sp30 = sp70;
            temp_t0 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_t0, M2C_UNK (**)(void *, s32, s32, M2C_UNK, s128, s128, s128), 0x54)(arg0 + M2C_FIELD(temp_t0, s16 *, 0x50), M2C_FIELD(M2C_FIELD(arg0, void **, 0x294), s32 *, 0x10), temp_s0_2, 3, sp40, sp50, sp60);
            temp_v0_4 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0x118), g_2a2dd0);
            temp_v0_5 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, s128), 0x124)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x120), g_2a2dd0);
            M2C_FIELD(arg0, s32 *, 0x298) = func_0012DC18(arg0, M2C_FIELD(arg0, void **, 0x58), 1, 7);
            DecomposeRotateMatrixEuler(sp);
            M2C_ERROR(/* unknown instruction: por $t1, $zero, $v0 */);
            M2C_FIELD(arg0, s32 *, 0x29C) = func_0012DC18(arg0, M2C_FIELD(arg0, void **, 0x5C), 1, 7);
            SetSoCnstrForce(arg0, 1);
            SetSoCnstrTorque(arg0, 1);
            func_001F68A8(arg0, 1);
            break;
        case 4:
            bevy_camera_follow_activity(&B_002DEB30, 0x10, arg0);
            break;
        }
        if (arg1 != -1) {
            var_a1 = arg0 + ((arg1 * 0x10) + 0x1C8);
        } else {
            var_a1 = NULL;
        }
        func_0017F4C0(arg0, var_a1);
    }
}
