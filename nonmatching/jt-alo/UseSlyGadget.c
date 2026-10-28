#include "m2c_macros.h"

M2C_UNK CarryThrow_SetState(void *, M2C_UNK);       /* extern */
M2C_UNK ExplodeExpl(s32);                           /* extern */
s32 FGadgetObjKept(void *);                         /* extern */
M2C_UNK GrfbtnJtGadget(void *, s32);                /* extern */
s32 NewEmitter(M2C_UNK);                            /* extern */
void *PloLeaseCloneObject(s32, M2C_UNK, s32);       /* extern */
M2C_UNK SetClockRate(M2C_UNK *, M2C_UNK, f32);      /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
M2C_UNK SetJmpBodyState(void *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK SetJmpState(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetJtState(void *, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK SpendJtGadgetPower(void *, s32);            /* extern */
M2C_UNK StartAttach(void *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK VirtualRefPtr_Assign(void *, s32);          /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
M2C_UNK func_00141D38(void *, s32);                 /* extern */
M2C_UNK func_0018D698(void *, void *, void *);      /* extern */
void *func_0018D6F8(void *, s32);                   /* extern */
extern M2C_UNK B_002DEB30;
extern f32 B_FLT_003E1BEC;
extern f32 D_FLT_002BF3EC;
extern f32 D_FLT_002BF3F0;
extern M2C_UNK g_2dded0;

void UseSlyGadget(void *arg0, s32 arg1) {
    M2C_UNK var_a0;
    M2C_UNK var_a1;
    M2C_UNK var_a1_2;
    M2C_UNK var_a1_3;
    f32 var_f0;
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a2;
    s32 var_v0;
    void *temp_s3;
    void *temp_v0_2;
    void *var_a0_2;
    void *var_a0_3;

    M2C_FIELD(&B_002DEB30, s32 *, 0xC) = arg1;
    bevy_camera_follow_activity(&B_002DEB30, 0x3C, arg0);
    switch (arg1) {
    case 29:
        SpendJtGadgetPower(arg0, arg1);
        SetClockRate(&g_2dded0, 1, D_FLT_002BF3EC);
        var_f0 = -1.0f;
        var_a0 = 0x67;
block_4:
        B_FLT_003E1BEC = var_f0;
        temp_v0 = NewEmitter(var_a0);
        SetEmitterUnpositioned(temp_v0, 0);
        VirtualRefPtr_Assign(arg0 + 0x2044, temp_v0);
        return;
    case 42:
        SpendJtGadgetPower(arg0, arg1);
        SetClockRate(&g_2dded0, 1, D_FLT_002BF3F0);
        var_f0 = 0.7f;
        var_a0 = 0x66;
        goto block_4;
    case 33:
        SpendJtGadgetPower(arg0, arg1);
        var_a1 = 9;
block_20:
        SetJtState(arg0, var_a1, -1);
        return;
    case 27:
        SpendJtGadgetPower(arg0, arg1);
        SetJmpBodyState(arg0 + 0x2C0, 0x13, 0);
        return;
    case 26:
    case 37:
    case 38:
    case 41:
        temp_s3 = func_0018D6F8(arg0, arg1);
        if ((u32) (M2C_FIELD(arg0, s32 *, 0x11B4) - 4) < 3U) {
            CarryThrow_SetState(arg0 + 0x11B0, 7);
            return;
        }
        var_a2 = M2C_FIELD(temp_s3, s32 *, 8);
        var_a0_2 = arg0 + 0x4C0;
        if (var_a2 != 0) {
            var_a1_2 = 0xB;
block_25:
            StartAttach(var_a0_2, var_a1_2, var_a2, 0);
            return;
        }
        temp_v0_2 = PloLeaseCloneObject(M2C_FIELD(temp_s3, s32 *, 4), 0, var_a2);
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, s32 *, 0x15C) = (s32) M2C_FIELD(temp_s3, s32 *, 0);
            if (FGadgetObjKept(temp_v0_2) != 0) {
                M2C_FIELD(temp_v0_2, void **, 0x16C) = arg0;
                func_0018D698(arg0, temp_s3, temp_v0_2);
            }
            M2C_FIELD(arg0, void **, 0x11C0) = temp_v0_2;
            GrfbtnJtGadget(arg0, arg1);
            SetJtState(arg0, 0x17, -1);
            CarryThrow_SetState(arg0 + 0x11B0, 4);
            return;
        }
        return;
    case 34:
    case 35:
        M2C_FIELD(arg0, s32 *, 0x9BC) = arg1;
        if (arg1 == 0x23) {
            var_v0 = M2C_FIELD(arg0, s32 *, 0x1FE0);
        } else {
            var_v0 = M2C_FIELD(arg0, s32 *, 0x1FE4);
        }
        M2C_FIELD(arg0, s32 *, 0x130C) = var_v0;
        var_a0_2 = arg0 + 0x4C0;
        var_a1_2 = 0xB;
block_24:
        var_a2 = 0;
        goto block_25;
    case 24:
        SpendJtGadgetPower(arg0, arg1);
        var_a1 = 6;
        goto block_20;
    case 25:
        SpendJtGadgetPower(arg0, arg1);
        SetJtState(arg0, 0x18, 0xC);
        return;
    case 39:
        SpendJtGadgetPower(arg0, arg1);
        SetJtState(arg0, 5, 9);
        return;
    case 40:
        SpendJtGadgetPower(arg0, arg1);
        var_a0_2 = arg0 + 0x4C0;
        var_a1_2 = 2;
        goto block_24;
    case 31:
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x204C);
        if (temp_a0 != 0) {
            ExplodeExpl(temp_a0);
        }
        SpendJtGadgetPower(arg0, arg1);
        var_a0_3 = arg0 + 0x2C0;
        var_a1_3 = 9;
block_30:
        SetJmpState(var_a0_3, var_a1_3, 0, 0);
        return;
    case 30:
        SpendJtGadgetPower(arg0, arg1);
        var_a0_3 = arg0 + 0x2C0;
        var_a1_3 = 0xE;
        goto block_30;
    default:
        func_00141D38(arg0, arg1);
        break;
    }
}
