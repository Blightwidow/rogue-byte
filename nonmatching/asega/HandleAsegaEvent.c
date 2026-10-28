#include "m2c_macros.h"

M2C_UNK ApplyAseg(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 CidGetBasic(s32, void *);                       /* extern */
M2C_UNK EnableDisableLoPart(M2C_UNK *, s32, void *, M2C_UNK32); /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK, s32);         /* extern */
M2C_UNK HideCountdownBlot(M2C_UNK *, u32, s32);     /* extern */
M2C_UNK JoltCm(M2C_UNK *, void *, s32);             /* extern */
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, void *, s32); /* extern */
s32 PloRootOrAseg(void *, u32, s32);                /* extern */
M2C_UNK RetractAsega(void *, u32, s32);             /* extern */
M2C_UNK SeekAsega(void *, M2C_UNK, s32, void *, M2C_UNK32); /* extern */
M2C_UNK SetAloSelectedOid(s32, void *, s32);        /* extern */
M2C_UNK SetAsegaHandsOff(void *, s32, s32);         /* extern */
M2C_UNK SetEyesClosedByOid(M2C_UNK *, s32, s32, s32, f32); /* extern */
M2C_UNK SetJtLookLimits(s32, void *, void *, void *); /* extern */
M2C_UNK ShowCountdownBlot(M2C_UNK *, u32, s32, f32); /* extern */
M2C_UNK ShowHideLo(M2C_UNK *, s32, void *, s32, M2C_UNK32); /* extern */
M2C_UNK ShowHideLoGlob(M2C_UNK *, s32, void *, M2C_UNK32); /* extern */
M2C_UNK SnapAsega(void *, void *, s32);             /* extern */
M2C_UNK StartJsg(s32, M2C_UNK);                     /* extern */
M2C_UNK StartSwAmbSfx(M2C_UNK *, s32, s32, s32, f32, f32, f32, void *); /* extern */
M2C_UNK StopSwAmbSfx(M2C_UNK *, void *, void *, void *); /* extern */
M2C_UNK TriggerJoyRumbleRumk__FP3JOY4RUMKf(M2C_UNK *, void *, s32, M2C_UNK32); /* extern */
M2C_UNK func_00210538(M2C_UNK *, s32, s32, s32, f32); /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_003DD490;

void HandleAsegaEvent(void *arg0, void *arg1) {
    void *sp10;
    void *sp20;
    f32 sp24;
    void *sp28;
    void *sp30;
    s32 temp_a0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_a2;
    u32 temp_v0_2;
    u32 temp_v1;
    void *temp_a1;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_s4;
    void *temp_t4;
    void *temp_v0;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v1_2;

    sp10 = arg0;
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8));
    var_a2 = 0;
    temp_s4 = M2C_FIELD(arg0, void **, 0x14);
    M2C_FIELD(arg0, f32 *, 0x1C) = (f32) M2C_FIELD(arg1, f32 *, 0);
    if (M2C_FIELD(arg0, f32 *, 0x40) < 0.0f) {
        temp_v1 = M2C_FIELD(temp_s4, u32 *, 0xA4);
        if ((u32) arg1 >= temp_v1) {
            var_a2 = (u32) arg1 < (u32) (temp_v1 + (M2C_FIELD(temp_s4, s32 *, 0xA0) * 0x10));
        }
    }
    temp_v0_2 = M2C_FIELD(arg1, u32 *, 4);
    switch (temp_v0_2) {                            /* switch 1 */
    case 0:                                         /* switch 1 */
        PloRootOrAseg(arg0, temp_v0_2, var_a2);
        temp_t4 = M2C_FIELD(arg1, void **, 8);
        StartSwAmbSfx(&B_003DD490, M2C_FIELD(temp_t4, s32 *, 0), M2C_FIELD(temp_t4, s32 *, 4), M2C_FIELD(temp_t4, s32 *, 8), M2C_FIELD(temp_t4, f32 *, 0x10), M2C_FIELD(temp_t4, f32 *, 0x14), M2C_FIELD(temp_t4, f32 *, 0x18), arg0 + 0x5C);
    default:                                        /* switch 1 */
        break;
    case 1:                                         /* switch 1 */
        StopSwAmbSfx(&B_003DD490, M2C_FIELD(arg1, void **, 8), temp_s4, arg0 + 0x5C);
        break;
    case 2:                                         /* switch 1 */
        JoltCm(&B_002DDF40, M2C_FIELD(arg1, void **, 8), var_a2);
        break;
    case 3:                                         /* switch 1 */
        TriggerJoyRumbleRumk__FP3JOY4RUMKf(&B_002DFC00, M2C_FIELD(arg1, void **, 8), var_a2, M2C_FIELD(arg1, M2C_UNK32 *, 0xC));
        break;
    case 4:                                         /* switch 1 */
        temp_v0_3 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(arg1, void **, 8), PloRootOrAseg(arg0, temp_v0_2, var_a2));
        if (temp_v0_3 != 0) {
            temp_v0_4 = CidGetBasic(temp_v0_3, sp10);
            switch (temp_v0_4) {                    /* switch 2; irregular */
            case 0x6D:                              /* switch 2 */
                ApplyAseg(temp_v0_3, 0, 0, 0, 0, 0x3F800000);
                break;
            case 0x72:                              /* switch 2 */
                StartJsg(temp_v0_3, 0);
                break;
            }
        }
        break;
    case 5:                                         /* switch 1 */
        SeekAsega(arg0, 0, var_a2, M2C_FIELD(arg1, void **, 8), M2C_FIELD(arg1, M2C_UNK32 *, 0xC));
        break;
    case 6:                                         /* switch 1 */
        RetractAsega(arg0, temp_v0_2, var_a2);
        break;
    case 9:                                         /* switch 1 */
    case 10:                                        /* switch 1 */
        SetAsegaHandsOff(arg0, (temp_v0_2 == 9) ^ var_a2, var_a2);
        break;
    case 7:                                         /* switch 1 */
    case 8:                                         /* switch 1 */
        ShowHideLo(&B_003DD490, (temp_v0_2 == 7) ^ var_a2, M2C_FIELD(arg1, void **, 8), PloRootOrAseg(arg0, temp_v0_2, var_a2), M2C_FIELD(arg1, M2C_UNK32 *, 0xC));
        break;
    case 11:                                        /* switch 1 */
        sp24 = M2C_FIELD(arg1, f32 *, 0);
        sp20 = arg0;
        sp28 = M2C_FIELD(arg1, void **, 8);
        temp_v0_5 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, M2C_UNK, void **), 0x24)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x20), 9, &sp20);
        break;
    case 12:                                        /* switch 1 */
        temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
        sp30 = arg1 + 8;
        M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x18), 4, 0, 1);
        break;
    case 17:                                        /* switch 1 */
        temp_s1 = M2C_FIELD(arg1, void **, 8);
        PloRootOrAseg(arg0, temp_v0_2, var_a2);
        func_00210538(&B_003DD490, M2C_FIELD(temp_s1, s32 *, 0), M2C_FIELD(temp_s1, s32 *, 4), M2C_FIELD(temp_s1, s32 *, 8), M2C_FIELD(temp_s1, f32 *, 0xC));
        break;
    case 13:                                        /* switch 1 */
    case 14:                                        /* switch 1 */
        PloRootOrAseg(arg0, temp_v0_2, var_a2);
        ShowHideLoGlob(&B_003DD490, (temp_v0_2 == 0xD) ^ var_a2, M2C_FIELD(arg1, void **, 8), M2C_FIELD(arg1, M2C_UNK32 *, 0xC));
        break;
    case 15:                                        /* switch 1 */
    case 16:                                        /* switch 1 */
        PloRootOrAseg(arg0, temp_v0_2, var_a2);
        EnableDisableLoPart(&B_003DD490, (temp_v0_2 == 0xF) ^ var_a2, M2C_FIELD(arg1, void **, 8), M2C_FIELD(arg1, M2C_UNK32 *, 0xC));
        break;
    case 18:                                        /* switch 1 */
        ShowCountdownBlot(&B_003DD490, temp_v0_2, var_a2, M2C_FIELD(arg0, f32 *, 0x1C));
        break;
    case 19:                                        /* switch 1 */
        HideCountdownBlot(&B_003DD490, temp_v0_2, var_a2);
        break;
    case 20:                                        /* switch 1 */
        temp_s1_2 = M2C_FIELD(arg1, void **, 8);
        SetEyesClosedByOid(&B_003DD490, M2C_FIELD(temp_s1_2, s32 *, 0), M2C_FIELD(temp_s1_2, s32 *, 4), PloRootOrAseg(arg0, temp_v0_2, var_a2), M2C_FIELD(temp_s1_2, f32 *, 8));
        break;
    case 21:                                        /* switch 1 */
        SnapAsega(arg0, M2C_FIELD(arg1, void **, 8), var_a2);
        break;
    case 22:                                        /* switch 1 */
        SetAloSelectedOid(M2C_FIELD(arg0, s32 *, 0x18), M2C_FIELD(arg1, void **, 8), var_a2);
        break;
    case 23:                                        /* switch 1 */
        SetAloSelectedOid(M2C_FIELD(arg0, s32 *, 0x18), (void *)-1, var_a2);
        break;
    case 24:                                        /* switch 1 */
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x18);
        if ((temp_a0 != 0) && (FIsBasicDerivedFrom(temp_a0, 0x34, var_a2) != 0)) {
            temp_a1 = M2C_FIELD(arg1, void **, 8);
            SetJtLookLimits(M2C_FIELD(arg0, s32 *, 0x18), temp_a1, temp_a1 + 8, temp_a1 + 0x10);
        }
        break;
    }
    temp_v0_6 = M2C_FIELD(sp10, void **, 0xC);
    M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, void *), 0x14)(sp10 + M2C_FIELD(temp_v0_6, s16 *, 0x10), sp10);
}
