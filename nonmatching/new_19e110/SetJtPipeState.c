#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(void *, void *, M2C_UNK, void *, f32, M2C_UNK); /* extern */
M2C_UNK ConvertAloPos(void *, M2C_UNK, s128);       /* extern */
f32 GLimitLm__FP2LMf(M2C_UNK *, f32);               /* extern */
M2C_UNK GetPathPosFromS(void *, s128 *, M2C_UNK, f32); /* extern */
s32 NewEmitter(s32);                                /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK RetractSmaRef(void *);                      /* extern */
M2C_UNK SetAmbPos(s32, s128);                       /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
M2C_UNK SetJtJtcs(void *, M2C_UNK);                 /* extern */
M2C_UNK SubscribeLoObject(void *, void *);          /* extern */
M2C_UNK UnsubscribeLoObject(void *, void *);        /* extern */
M2C_UNK bevy_player_p14_19e110(void *, M2C_UNK *);  /* extern */
M2C_UNK func_00140C88(void *, s32);                 /* extern */
f32 func_001E6728(void *, f32);                     /* extern */
M2C_UNK func_00204F78(void *, void *, M2C_UNK);     /* extern */
extern f32 g_2dded0;
extern s32 g_2e1e40;

void SetJtPipeState(void *arg0, s32 arg1) {
    char sp[0x400];
    s128 sp10;
    M2C_UNK sp20;
    s128 sp30;
    s128 sp50;
    M2C_UNK var_f20;
    M2C_UNK var_s2;
    f32 temp_f0;
    f32 var_f21;
    s32 temp_a0;
    s32 temp_a0_3;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_s0_2;
    void *temp_t2;
    void *temp_t2_2;
    void *temp_v0_3;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_s0;

    temp_s0 = M2C_FIELD(arg0, s32 *, 4);
    if (arg1 != temp_s0) {
        switch (temp_s0) {                          /* switch 1; irregular */
        case -1:                                    /* switch 1 */
            temp_t2 = M2C_FIELD(arg0, void **, 0xC);
            temp_v1 = M2C_FIELD(temp_t2, void **, 0xC);
            M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(temp_t2 + M2C_FIELD(temp_v1, s16 *, 0x18), 5, 0, 0);
            SubscribeLoObject(M2C_FIELD(arg0, void **, 0xC), M2C_FIELD(arg0, void **, 0));
            func_00204F78(M2C_FIELD(arg0, void **, 0), M2C_FIELD(arg0, void **, 0xC), 1);
            M2C_FIELD(arg0, s32 *, 0x20) = temp_s0;
            GetPathPosFromS(M2C_FIELD(arg0, void **, 0xC), sp, 0, func_001E6728(M2C_FIELD(arg0, void **, 0xC), M2C_FIELD(arg0, f32 *, 0x10) + 50.0f));
            GetPathPosFromS(M2C_FIELD(arg0, void **, 0xC), &sp10, 0, func_001E6728(M2C_FIELD(arg0, void **, 0xC), M2C_FIELD(arg0, f32 *, 0x10) - 50.0f));
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f)) {
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf3, $q */);
                M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
            }
            var_v0 = 1;
            if (!(M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */) < -0.5f)) {
                var_v0 = 0;
            }
            M2C_FIELD(arg0, s32 *, 0x18) = var_v0;
            bevy_player_p14_19e110(arg0, &sp20);
            temp_f0 = GLimitLm__FP2LMf(&sp20, M2C_FIELD(arg0, f32 *, 0x10));
            M2C_FIELD(arg0, f32 *, 0x10) = temp_f0;
            GetPathPosFromS(M2C_FIELD(arg0, void **, 0xC), &sp30, 0, temp_f0);
            ConvertAloPos(M2C_FIELD(arg0, void **, 0), 0, M2C_FIELD(arg0, s128 *, 0x30));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x1010($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1060($v1) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x1070($v1) */);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1078) = 0;
            func_00140C88(M2C_FIELD(arg0, void **, 0), M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s32 *, 0x190));
            temp_a0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s32 *, 0x1D0);
            if (temp_a0 != 0) {
                temp_v0 = NewEmitter(temp_a0);
                SetEmitterUnpositioned(temp_v0, 0);
                SetAmbPos(temp_v0, sp30);
            }
            break;
        case 0:                                     /* switch 1 */
            temp_a0_2 = M2C_FIELD(arg0, void **, 0);
            if (temp_a0_2 == g_2e1e40) {
                SetJtJtcs(temp_a0_2, (M2C_FIELD(temp_a0_2, s32 *, 0x14D4) == 0) ? 2 : 0xA);
            }
            break;
        }
        M2C_FIELD(arg0, s32 *, 4) = arg1;
        var_s0 = NULL;
        var_s2 = 1;
        var_f21 = 0.0f;
        var_f20 = 0x3F800000;
        M2C_FIELD(arg0, f32 *, 8) = (f32) g_2dded0;
        switch (arg1) {                             /* switch 2 */
        case -1:                                    /* switch 2 */
            temp_t2_2 = M2C_FIELD(arg0, void **, 0xC);
            temp_v1_2 = M2C_FIELD(temp_t2_2, void **, 0xC);
            M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(temp_t2_2 + M2C_FIELD(temp_v1_2, s16 *, 0x18), 6, 0, 0);
            UnsubscribeLoObject(M2C_FIELD(arg0, void **, 0xC), M2C_FIELD(arg0, void **, 0));
            func_00204F78(M2C_FIELD(arg0, void **, 0), M2C_FIELD(arg0, void **, 0xC), 0);
            temp_s0_2 = M2C_FIELD(arg0, void **, 0);
            sp50 = M2C_FIELD(temp_s0_2, s128 *, 0x1060);
            PosLoWorld(temp_s0_2);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x1070($s0) */);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x1078) = 0;
            func_00140C88(M2C_FIELD(arg0, void **, 0), 0);
            temp_a0_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s32 *, 0x1D4);
            if (temp_a0_3 == 0) {
                M2C_FIELD(arg0, void **, 0xC) = NULL;
                return;
            }
            temp_v0_2 = NewEmitter(temp_a0_3);
            SetEmitterUnpositioned(temp_v0_2, 0);
            PosLoWorld(M2C_FIELD(arg0, void **, 0));
            SetAmbPos(temp_v0_2, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
            M2C_FIELD(arg0, void **, 0xC) = NULL;
            return;
        case 0:                                     /* switch 2 */
            var_s0 = M2C_FIELD(arg0, void **, 0x74);
            if (var_s0 != NULL) {
                M2C_FIELD(arg0, s32 *, 0x1C) = 0;
            } else {
                var_s0 = M2C_FIELD(arg0, void **, 0x7C);
                var_f20 = 0x3F000000;
                var_f21 = M2C_FIELD(var_s0, f32 *, 0x74) * 0.5f;
                M2C_FIELD(arg0, s32 *, 0x1C) = 0;
            }
        default:                                    /* switch 2 */
block_28:
            RetractSmaRef(M2C_FIELD(arg0, void **, 0) + 0x1034);
            temp_a1 = M2C_FIELD(arg0, void **, 0);
            ApplyAsegToHandle(var_s0, temp_a1, var_s2, temp_a1 + 0x1030, var_f21, var_f20);
            temp_v1_3 = M2C_FIELD(arg0, void **, 0);
            temp_v0_3 = temp_v1_3 + 0x190;
            M2C_FIELD(temp_v0_3, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_3, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_3, s32 *, 0x190) = 0;
            break;
        case 1:                                     /* switch 2 */
            var_s0 = M2C_FIELD(arg0, void **, 0x78);
            var_s2 = 9;
            goto block_28;
        case 2:                                     /* switch 2 */
            var_s0 = M2C_FIELD(arg0, void **, 0x70);
            var_s2 = 9;
            goto block_28;
        case 3:                                     /* switch 2 */
            var_s0 = M2C_FIELD(arg0, void **, 0x70);
            var_f20 = 0xBF800000;
            var_s2 = 9;
            goto block_28;
        case 4:                                     /* switch 2 */
            var_s0 = M2C_FIELD(arg0, void **, 0x7C);
            M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) == 0);
            goto block_28;
        }
    }
}
