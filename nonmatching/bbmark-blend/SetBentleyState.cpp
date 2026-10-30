typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetBentleyState {
    /* 0x00 */ char pad0[0xA0];
};                                                  /* size = 0xA0 */
void ApplyAsegToHandle(s8 *, s8 *, M2C_UNK, s8 *, f32, M2C_UNK);
void CarryThrow_SetState(s8 *, M2C_UNK);
void ExplodeExpl(s8 *);
s32 IsmsFindSmOptional__FP2SM3OID(s32, M2C_UNK);
void ReleaseBentleyGadget(s8 *);
void ResetRunBlendFootsteps(s8 *);
void RetractAsegaHandle(s8 *);
void RetractSmaRef(s8 *);
void ScheduleJtGlance(s8 *);
void SetAttachSubstate(s8 *, M2C_UNK);
void SetBentleyGadgetAnim(s8 *, M2C_UNK);
void SetBinocState(s8 *, M2C_UNK);
void SetJmpBodyState(s8 *, M2C_UNK, M2C_UNK);
void SetJtPipeState(s8 *, M2C_UNK);
void SetJtZapState(s8 *, M2C_UNK);
void SetXfKind(s8 *, s32, M2C_UNK);
void func_00136530(s8 *, M2C_UNK);
s32 func_00142868(s8 *, M2C_UNK);
s32 func_001430C8(s8 *);
void func_001F14F8(s32, s8 *, M2C_UNK, M2C_UNK);
extern s128 g_2a2dd0;
extern f32 g_2dded0;
void SetBentleyState(s8 *arg0, s32 arg1) {
    M2C_UNK var_f21;
    M2C_UNK var_s4;
    M2C_UNK var_s4_2;
    M2C_UNK var_s5;
    f32 var_f20;
    s32 temp_v1_2;
    s32 var_s6;
    u32 temp_s0;
    u32 temp_v1;
    s8 *temp_a2;
    s8 *temp_s0_2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v0_6;
    s8 *var_a0;
    s8 *var_a0_2;
    s8 *var_s0;
    s8 *var_s3;
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x13D0);
    if (arg1 != temp_v1) {
        switch (temp_v1) {                          /* switch 1 */
        case 0:                                     /* switch 1 */
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 2);
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 2);
            ScheduleJtGlance(arg0);
            break;
        case 9:                                     /* switch 1 */
        case 10:                                    /* switch 1 */
        case 11:                                    /* switch 1 */
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 2);
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 2);
            break;
        case 2:                                     /* switch 1 */
            var_a0 = arg0 + 0x2C0;
            if (M2C_FIELD(arg0, s32 *, 0x108C) == 0) {
                var_s0 = NULL;
                if (arg1 >= 0) {
                    if (arg1 >= 2) {
                        if (arg1 == 3) {
                            temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x4C8);
                            if (temp_v1_2 != 1) {
                                if ((temp_v1_2 > 0) && (temp_v1_2 < 5) && (temp_v1_2 >= 3)) {
                                    var_s0 = M2C_FIELD(arg0, s8 **, 0x16D4);
                                } else {
                                    goto block_14;
                                }
                            }
                        }
                    } else {
block_14:
                        var_s0 = M2C_FIELD(arg0, s8 **, 0x16D0);
                    }
                }
                var_a0 = arg0 + 0x2C0;
                if (var_s0 != NULL) {
                    temp_v0 = M2C_FIELD(var_s0, s8 **, 0xC);
                    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *), 0x44)(var_s0 + M2C_FIELD(temp_v0, s16 *, 0x40));
                    ExplodeExpl(var_s0);
                    temp_v0_2 = M2C_FIELD(var_s0, s8 **, 0xC);
                    M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *), 0x4C)(var_s0 + M2C_FIELD(temp_v0_2, s16 *, 0x48));
                    var_a0 = arg0 + 0x2C0;
                }
            }
            SetJmpBodyState(var_a0, -1, 0);
            break;
        case 3:                                     /* switch 1 */
            SetAttachSubstate(arg0 + 0x4C0, -1);
            break;
        case 4:                                     /* switch 1 */
            SetJtZapState(arg0 + 0xDF0, -1);
            break;
        case 13:                                    /* switch 1 */
            SetJtPipeState(arg0 + 0xF50, -1);
            break;
        case 6:                                     /* switch 1 */
            temp_a2 = M2C_FIELD(arg0, s8 **, 0x186C);
            if (temp_a2 != NULL) {
                temp_v0_3 = M2C_FIELD(temp_a2, s8 **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x264)(temp_a2 + M2C_FIELD(temp_v0_3, s16 *, 0x260), 1, temp_a2);
                ReleaseBentleyGadget(arg0);
            }
            SetBentleyGadgetAnim(arg0, -1);
            break;
        case 8:                                     /* switch 1 */
            func_00136530(arg0, -1);
            temp_v0_4 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, M2C_UNK), 0x27C)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0x278), 1);
            break;
        case 1:                                     /* switch 1 */
        case 7:                                     /* switch 1 */
            temp_v0_5 = M2C_FIELD(arg0, s8 **, 0x1030);
            M2C_FIELD(arg0, f32 *, 0x1A0) = (f32) (M2C_FIELD(temp_v0_5, f32 *, 0x1C) / M2C_FIELD(M2C_FIELD(temp_v0_5, s8 **, 0x14), f32 *, 0x74));
            break;
        case 12:                                    /* switch 1 */
            CarryThrow_SetState(arg0 + 0x11B0, -1);
            break;
        }
        temp_s0 = M2C_FIELD(arg0, u32 *, 0x13D0);
        M2C_FIELD(arg0, u32 *, 0x13D0) = (u32) arg1;
        var_s3 = NULL;
        var_s6 = 0;
        var_s5 = 1;
        var_s4 = -1;
        var_f20 = 0.0f;
        var_f21 = 0x3F800000;
        M2C_FIELD(arg0, f32 *, 0x13D4) = (f32) g_2dded0;
        switch (arg1) {                             /* switch 2 */
        case 0:                                     /* switch 2 */
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 1);
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 1);
            if (M2C_FIELD(arg0, s32 *, 0x181C) != 0) {
                var_s3 = M2C_FIELD(arg0, s8 **, 0x1820);
                var_s5 = 9;
            } else {
                var_s6 = M2C_FIELD(arg0, s32 *, 0x1028);
                if (temp_s0 != 2) {
                    var_s4_2 = ((temp_s0 ^ 7) != 0) ? 0x175 : 0x176;
                } else {
                    var_s4_2 = 0x178;
                }
                var_s4 = (IsmsFindSmOptional__FP2SM3OID(var_s6, var_s4_2) <= -1) ? -1 : var_s4_2;
            }
            M2C_FIELD(arg0, s128 *, 0x190) = (s128) g_2a2dd0;
            func_001430C8(arg0);
            func_00142868(arg0, 1);
        default:                                    /* switch 2 */
block_49:
            temp_s0_2 = arg0 + 0x1030;
            RetractAsegaHandle(temp_s0_2);
            RetractSmaRef(arg0 + 0x1034);
            ApplyAsegToHandle(var_s3, arg0, var_s5, temp_s0_2, var_f20, var_f21);
            func_001F14F8(var_s6, arg0, var_s4, var_s5);
            temp_v0_6 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_6, M2C_UNK (**)(s8 *), 0x2D4)(arg0 + M2C_FIELD(temp_v0_6, s16 *, 0x2D0));
            break;
        case 1:                                     /* switch 2 */
            var_s3 = M2C_FIELD(arg0, s8 **, 0x1324);
            var_a0_2 = arg0 + 0x1320;
block_38:
            var_s5 = 9;
            var_f20 = M2C_FIELD(arg0, f32 *, 0x1A0) * M2C_FIELD(var_s3, f32 *, 0x74);
            ResetRunBlendFootsteps(var_a0_2);
            goto block_49;
        case 7:                                     /* switch 2 */
            var_s3 = M2C_FIELD(arg0, s8 **, 0x1604);
            var_a0_2 = arg0 + 0x1600;
            goto block_38;
        case 4:                                     /* switch 2 */
            SetBinocState(arg0 + 0xF00, -1);
            goto block_49;
        case 5:                                     /* switch 2 */
            var_s3 = M2C_FIELD(arg0, s8 **, 0x14E0);
block_48:
            var_s5 = 9;
            goto block_49;
        case 13:                                    /* switch 2 */
            SetJtPipeState(arg0 + 0xF50, 0);
            return;
        case 6:                                     /* switch 2 */
            SetBentleyGadgetAnim(arg0, 0);
            return;
        case 8:                                     /* switch 2 */
            func_00136530(arg0, 0);
            return;
        case 9:                                     /* switch 2 */
            var_s6 = M2C_FIELD(arg0, s32 *, 0x102C);
            /* fallthrough */
        case 10:                                    /* switch 2 */
        case 11:                                    /* switch 2 */
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 1);
            SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 1);
            M2C_FIELD(arg0, s128 *, 0x190) = (s128) g_2a2dd0;
            goto block_49;
        case 14:                                    /* switch 2 */
            var_s3 = M2C_FIELD(arg0, s8 **, 0x1878);
            var_s5 = 9;
            if (var_s3 == NULL) {
                var_s3 = M2C_FIELD(arg0, s8 **, 0x1374);
                var_f21 = 0x3FC00000;
                goto block_48;
            }
            goto block_49;
        }
    }
}
}
