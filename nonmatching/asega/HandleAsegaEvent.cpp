typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_HandleAsegaEvent {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s8 *sp10;                          /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of sp10[4]? */
    /* 0x20 */ s8 *sp20;                          /* inferred */
    /* 0x24 */ f32 sp24;                            /* inferred */
    /* 0x28 */ s8 *sp28;                          /* inferred */
    /* 0x2C */ char pad2C[4];
    /* 0x30 */ s8 *sp30;                          /* inferred */
    /* 0x34 */ char pad34[0x6C];
};                                                  /* size = 0xA0 */
M2C_UNK ApplyAseg(s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 CidGetBasic(s32, s8 *);                       /* extern */
M2C_UNK EnableDisableLoPart(M2C_UNK *, s32, s8 *, M2C_UNK32, s32, s32, s8 *); /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK, s32);         /* extern */
M2C_UNK HideCountdownBlot(M2C_UNK *, u32, s32);     /* extern */
M2C_UNK JoltCm(M2C_UNK *, s8 *, s32);             /* extern */
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s8 *, s32); /* extern */
s32 PloRootOrAseg(s8 *, u32, s32);                /* extern */
M2C_UNK RetractAsega(s8 *, u32, s32);             /* extern */
M2C_UNK SeekAsega(s8 *, M2C_UNK, s32, s8 *, M2C_UNK32); /* extern */
M2C_UNK SetAloSelectedOid(s32, s8 *, s32);        /* extern */
M2C_UNK SetAsegaHandsOff(s8 *, s32, s32);         /* extern */
M2C_UNK SetEyesClosedByOid(M2C_UNK *, s32, s32, s32, s8 *, f32); /* extern */
M2C_UNK SetJtLookLimits(s32, s8 *, s8 *, s8 *); /* extern */
M2C_UNK ShowCountdownBlot(M2C_UNK *, u32, s32, f32); /* extern */
M2C_UNK ShowHideLo(M2C_UNK *, s32, s8 *, s32, s8 *, M2C_UNK32); /* extern */
M2C_UNK ShowHideLoGlob(M2C_UNK *, s32, s8 *, M2C_UNK32, s32, s32, s8 *); /* extern */
M2C_UNK SnapAsega(s8 *, s8 *, s32);             /* extern */
M2C_UNK StartJsg(s32, M2C_UNK);                     /* extern */
M2C_UNK StartSwAmbSfx(M2C_UNK *, s32, s32, s32, s32, s32, s32, s8 *, f32, f32, f32, s8 *); /* extern */
M2C_UNK StopSwAmbSfx(M2C_UNK *, s8 *, s8 *, s8 *); /* extern */
M2C_UNK TriggerJoyRumbleRumk__FP3JOY4RUMKf(M2C_UNK *, s8 *, s32, M2C_UNK32); /* extern */
M2C_UNK func_00210538(M2C_UNK *, s32, s32, s32, s32, s8 *, f32); /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_003DD490;
void HandleAsegaEvent(s8 *arg0, s8 *arg1) {
    s8 *sp10;
    s8 *sp20;
    f32 sp24;
    s8 *sp28;
    s8 *sp30;
    s32 temp_a0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_a2;
    u32 temp_v0_2;
    u32 temp_v1;
    s8 *temp_a1;
    s8 *temp_s1;
    s8 *temp_s1_2;
    s8 *temp_s4;
    s8 *temp_t0;
    s8 *temp_v0;
    s8 *temp_v0_5;
    s8 *temp_v0_6;
    s8 *temp_v1_2;
    sp10 = arg0;
    temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8));
    var_a2 = 0;
    temp_s4 = M2C_FIELD(arg0, s8 **, 0x14);
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
        temp_t0 = M2C_FIELD(arg1, s8 **, 8);
        StartSwAmbSfx(&B_003DD490, M2C_FIELD(temp_t0, s32 *, 0), M2C_FIELD(temp_t0, s32 *, 4), M2C_FIELD(temp_t0, s32 *, 8), M2C_FIELD(temp_t0, s32 *, 0xC), M2C_FIELD(arg0, s32 *, 0x18), PloRootOrAseg(arg0, temp_v0_2, var_a2), temp_s4, M2C_FIELD(temp_t0, f32 *, 0x10), M2C_FIELD(temp_t0, f32 *, 0x14), M2C_FIELD(temp_t0, f32 *, 0x18), arg0 + 0x5C);
    default:                                        /* switch 1 */
        break;
    case 1:                                         /* switch 1 */
        StopSwAmbSfx(&B_003DD490, M2C_FIELD(arg1, s8 **, 8), temp_s4, arg0 + 0x5C);
        break;
    case 2:                                         /* switch 1 */
        JoltCm(&B_002DDF40, M2C_FIELD(arg1, s8 **, 8), var_a2);
        break;
    case 3:                                         /* switch 1 */
        TriggerJoyRumbleRumk__FP3JOY4RUMKf(&B_002DFC00, M2C_FIELD(arg1, s8 **, 8), var_a2, M2C_FIELD(arg1, M2C_UNK32 *, 0xC));
        break;
    case 4:                                         /* switch 1 */
        temp_v0_3 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(arg1, s8 **, 8), PloRootOrAseg(arg0, temp_v0_2, var_a2));
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
        SeekAsega(arg0, 0, var_a2, M2C_FIELD(arg1, s8 **, 8), M2C_FIELD(arg1, M2C_UNK32 *, 0xC));
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
        ShowHideLo(&B_003DD490, (temp_v0_2 == 7) ^ var_a2, M2C_FIELD(arg1, s8 **, 8), PloRootOrAseg(arg0, temp_v0_2, var_a2), temp_s4, M2C_FIELD(arg1, M2C_UNK32 *, 0xC));
        break;
    case 11:                                        /* switch 1 */
        sp24 = M2C_FIELD(arg1, f32 *, 0);
        sp20 = arg0;
        sp28 = M2C_FIELD(arg1, s8 **, 8);
        temp_v0_5 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, M2C_UNK, s8 **), 0x24)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x20), 9, &sp20);
        break;
    case 12:                                        /* switch 1 */
        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
        sp30 = arg1 + 8;
        M2C_FIELD(temp_v1_2, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s8 **, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x18), 4, 0, 1, &sp30, 0);
        break;
    case 17:                                        /* switch 1 */
        temp_s1 = M2C_FIELD(arg1, s8 **, 8);
        func_00210538(&B_003DD490, M2C_FIELD(temp_s1, s32 *, 0), M2C_FIELD(temp_s1, s32 *, 4), M2C_FIELD(temp_s1, s32 *, 8), PloRootOrAseg(arg0, temp_v0_2, var_a2), temp_s4, M2C_FIELD(temp_s1, f32 *, 0xC));
        break;
    case 13:                                        /* switch 1 */
    case 14:                                        /* switch 1 */
        ShowHideLoGlob(&B_003DD490, (temp_v0_2 == 0xD) ^ var_a2, M2C_FIELD(arg1, s8 **, 8), M2C_FIELD(arg1, M2C_UNK32 *, 0xC), M2C_FIELD(arg0, s32 *, 0x18), PloRootOrAseg(arg0, temp_v0_2, var_a2), temp_s4);
        break;
    case 15:                                        /* switch 1 */
    case 16:                                        /* switch 1 */
        EnableDisableLoPart(&B_003DD490, (temp_v0_2 == 0xF) ^ var_a2, M2C_FIELD(arg1, s8 **, 8), M2C_FIELD(arg1, M2C_UNK32 *, 0xC), M2C_FIELD(arg0, s32 *, 0x18), PloRootOrAseg(arg0, temp_v0_2, var_a2), temp_s4);
        break;
    case 18:                                        /* switch 1 */
        ShowCountdownBlot(&B_003DD490, temp_v0_2, var_a2, M2C_FIELD(arg0, f32 *, 0x1C));
        break;
    case 19:                                        /* switch 1 */
        HideCountdownBlot(&B_003DD490, temp_v0_2, var_a2);
        break;
    case 20:                                        /* switch 1 */
        temp_s1_2 = M2C_FIELD(arg1, s8 **, 8);
        SetEyesClosedByOid(&B_003DD490, M2C_FIELD(temp_s1_2, s32 *, 0), M2C_FIELD(temp_s1_2, s32 *, 4), PloRootOrAseg(arg0, temp_v0_2, var_a2), temp_s4, M2C_FIELD(temp_s1_2, f32 *, 8));
        break;
    case 21:                                        /* switch 1 */
        SnapAsega(arg0, M2C_FIELD(arg1, s8 **, 8), var_a2);
        break;
    case 22:                                        /* switch 1 */
        SetAloSelectedOid(M2C_FIELD(arg0, s32 *, 0x18), M2C_FIELD(arg1, s8 **, 8), var_a2);
        break;
    case 23:                                        /* switch 1 */
        SetAloSelectedOid(M2C_FIELD(arg0, s32 *, 0x18), (s8 *)-1, var_a2);
        break;
    case 24:                                        /* switch 1 */
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x18);
        if ((temp_a0 != 0) && (FIsBasicDerivedFrom(temp_a0, 0x34, var_a2) != 0)) {
            temp_a1 = M2C_FIELD(arg1, s8 **, 8);
            SetJtLookLimits(M2C_FIELD(arg0, s32 *, 0x18), temp_a1, temp_a1 + 8, temp_a1 + 0x10);
        }
        break;
    }
    temp_v0_6 = M2C_FIELD(sp10, s8 **, 0xC);
    M2C_FIELD(temp_v0_6, M2C_UNK (**)(s8 *, s8 *), 0x14)(sp10 + M2C_FIELD(temp_v0_6, s16 *, 0x10), sp10);
}
}
