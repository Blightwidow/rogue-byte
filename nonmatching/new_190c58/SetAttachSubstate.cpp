typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((char *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetAttachSubstate {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x10];
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ char pad50[0xC0];
};                                                  /* size = 0x110 */
void ApplyAsegToHandle(s8 *, s8 *, M2C_UNK, s8 *, f32, M2C_UNK);
void Carry_Detach(s8 *);
void Carry_SetState(s8 *, M2C_UNK);
s32 ConvertAloPos(M2C_UNK, s8 *, M2C_UNK);
void EvaluateCrvFromU(s8 *, s8 *, M2C_UNK *, f32);
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);
void FindCrvClosestPointAll(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
void FixStepAngularVelocity__FP4STEP(s8 *);
s32 NewEmitter(M2C_UNK);
s128 *PmatLoWorld(s8 *);
s32 PosLoWorld(s8 *);
void ResetJtDynamicTunnel__FP2JT(s8 *, s8 *);
void ResetRunBlendFootsteps(s8 *);
void RetractAsegaHandle(s8 *);
void RetractSmaRef(s8 *);
void RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, M2C_UNK, s8 *);
void SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, s8 *, s8 *);
void SetEmitterUnpositioned(s32, M2C_UNK);
void SetHbskHbsks(s8 *, M2C_UNK);
void SetJtJtcs(s8 *, M2C_UNK);
void SetJtLookats(s8 *, M2C_UNK);
void SetStepRadTargetDir(s8 *, s128);
void StopAmb(s32, M2C_UNK);
void SubscribeLoObject(s8 *, s8 *);
void UnsubscribeLoObject(s8 *, s8 *);
void VirtualRefPtr_Assign(s8 *, s32);
void func_00140C88(s8 *, s8 *);
void func_001F1448(s32, s8 *, M2C_UNK, M2C_UNK);
void func_002046F0(s8 *, s8 *);
void func_00204F78(s8 *, s8 *, M2C_UNK);
extern M2C_UNK B_002DDF40;
extern M2C_UNK D_002BF650;
extern f32 D_FLT_002BF63C;
extern f32 D_FLT_002BF640;
extern s128 g_2a2da0;
extern M2C_UNK g_2a2dc0;
extern s128 g_2a2dd0;
extern f32 g_2dded0;
extern s8 *g_2e1e40;
extern s8 *g_2f7900;
#define sp20 (*(s128 *)(sp + 0x20))
#define sp30 (*(s128 *)(sp + 0x30))
#define sp40 (*(s128 *)(sp + 0x40))
#define sp10 (*(M2C_UNK *)(sp + 0x10))
void SetAttachSubstate(s8 *arg0, s32 arg1) {
    s8 sp[0x70] __attribute__((aligned(16)));
    M2C_UNK (*temp_a2_2)(s8 *, s8 *);
    M2C_UNK var_f21;
    M2C_UNK var_s1;
    M2C_UNK var_s6;
    f32 *var_s7;
    f32 temp_f1;
    f32 var_f20;
    s128 *temp_v0_10;
    s128 *temp_v0_13;
    s128 temp_a1_5;
    s128 temp_a2_4;
    s128 var_v1_2;
    s16 temp_a2;
    s32 temp_a0_10;
    s32 temp_a0_16;
    s32 temp_a1_4;
    s32 temp_v0;
    s32 temp_v0_11;
    s32 temp_v0_4;
    s32 temp_v1_11;
    s32 temp_v1_12;
    s32 var_s5;
    s32 var_v0;
    u32 temp_v0_2;
    u32 temp_v1_10;
    u32 temp_v1_6;
    u32 temp_v1_8;
    u32 temp_v1_9;
    u32 var_v1;
    s8 *temp_a0;
    s8 *temp_a0_11;
    s8 *temp_a0_12;
    s8 *temp_a0_13;
    s8 *temp_a0_14;
    s8 *temp_a0_15;
    s8 *temp_a0_2;
    s8 *temp_a0_3;
    s8 *temp_a0_4;
    s8 *temp_a0_5;
    s8 *temp_a0_6;
    s8 *temp_a0_7;
    s8 *temp_a0_8;
    s8 *temp_a0_9;
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *temp_a1_3;
    s8 *temp_a1_6;
    s8 *temp_a1_7;
    s8 *temp_a2_3;
    s8 *temp_a3;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s0_3;
    s8 *temp_s0_4;
    s8 *temp_s0_5;
    s8 *temp_s0_6;
    s8 *temp_s0_7;
    s8 *temp_s0_8;
    s8 *temp_s0_9;
    s8 *temp_s1;
    s8 *temp_s1_2;
    s8 *temp_t2;
    s8 *temp_v0_12;
    s8 *temp_v0_14;
    s8 *temp_v0_15;
    s8 *temp_v0_16;
    s8 *temp_v0_3;
    s8 *temp_v0_5;
    s8 *temp_v0_6;
    s8 *temp_v0_7;
    s8 *temp_v0_8;
    s8 *temp_v0_9;
    s8 *temp_v1;
    s8 *temp_v1_13;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *temp_v1_5;
    s8 *temp_v1_7;
    s8 *var_a1;
    s8 *var_s3;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0xC);
    if (arg1 != temp_v0) {
        var_s7 = &g_2dded0;
        switch (temp_v0) {                          /* switch 1 */
        case 1:                                     /* switch 1 */
            var_s7 = (f32 *)0x2E0000;
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x1038) = -1;
        default:                                    /* switch 1 */
block_34:
            var_v1 = arg1 + 1;
            break;
        case -1:                                    /* switch 1 */
            temp_a0 = M2C_FIELD(arg0, s8 **, 0x14);
            if ((temp_a0 != NULL) && (FIsBasicDerivedFrom(temp_a0, 0xA) != 0)) {
                temp_s0 = M2C_FIELD(arg0, s8 **, 0x14);
                s64 vu_1;
                asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0))));
                FindCrvClosestPointAll(temp_s0, vu_1, 0, 0);
            }
            temp_v0_2 = M2C_FIELD(arg0, u32 *, 8);
            switch (temp_v0_2) {                    /* switch 2 */
            case 1:                                 /* switch 2 */
                temp_v1 = M2C_FIELD(arg0, s8 **, 0x14);
                M2C_FIELD(temp_v1, s8 **, 0x190) = (s8 *) M2C_FIELD(arg0, s8 **, 0);
                SetHbskHbsks(temp_v1, 2);
                temp_a0_2 = M2C_FIELD(arg0, s8 **, 0);
                if (temp_a0_2 == g_2e1e40) {
                    temp_a1 = M2C_FIELD(temp_a0_2, s8 **, 0x19A0);
                    temp_v0_3 = M2C_FIELD(temp_a1, s8 **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s8 *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0_3, s16 *, 0x48), temp_a1);
                default:                            /* switch 2 */
                    ;
                }
                break;
            case 4:                                 /* switch 2 */
                temp_s1 = M2C_FIELD(arg0, s8 **, 0x14);
                temp_v1_2 = M2C_FIELD(temp_s1, s8 **, 0xC);
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(temp_s1 + M2C_FIELD(temp_v1_2, s16 *, 0x18), 5, 0, 0);
                SubscribeLoObject(temp_s1, M2C_FIELD(arg0, s8 **, 0));
                func_00204F78(M2C_FIELD(arg0, s8 **, 0), temp_s1, 1);
                temp_s0_2 = M2C_FIELD(arg0, s8 **, 0);
                M2C_FIELD(temp_s0_2, s128 *, 0x230) = PosLoWorld(temp_s1);
                break;
            case 3:                                 /* switch 2 */
                temp_s0_3 = M2C_FIELD(arg0, s8 **, 0x14);
                temp_v1_3 = M2C_FIELD(temp_s0_3, s8 **, 0xC);
                M2C_FIELD(temp_v1_3, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(temp_s0_3 + M2C_FIELD(temp_v1_3, s16 *, 0x18), 5, 0, 0);
                SubscribeLoObject(temp_s0_3, M2C_FIELD(arg0, s8 **, 0));
                func_00204F78(M2C_FIELD(arg0, s8 **, 0), temp_s0_3, 1);
                M2C_FIELD(arg0, s32 *, 0x28) = -1;
                EvaluateCrvFromU(temp_s0_3, M2C_FIELD(arg0, s8 **, 0) + 0x230, &sp10, M2C_FIELD(arg0, f32 *, 0x1C));
                asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
                asm volatile("vmul.xyz vf1, vf3, vf3");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                if (vu_2 < 0.0001f) {
                    asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2da0));
                } else {
                    asm volatile("vdiv Q, vf0w, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vmulq.xyzw vf1, vf3, Q");
                }
                asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                asm volatile("sqc2 vf1, 0x50(%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, (%0)" : : "r"(PmatLoWorld(M2C_FIELD(arg0, s8 **, 0))));
                asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(sp));
                asm volatile("vmul.xyz vf1, vf1, vf2");
                asm volatile("vaddw.x vf3, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf3, vf1z");
                var_v0 = 1;
                s32 vu_3;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                if (!(vu_3 < D_FLT_002BF63C)) {
                    var_v0 = 0;
                }
                M2C_FIELD(arg0, s32 *, 0x24) = var_v0;
                break;
            case 2:                                 /* switch 2 */
                temp_v0_4 = NewEmitter(0x5C);
                SetEmitterUnpositioned(temp_v0_4, 0);
                VirtualRefPtr_Assign(g_2e1e40 + 0x2048, temp_v0_4);
                break;
            case 11:                                /* switch 2 */
                temp_a0_3 = M2C_FIELD(arg0, s8 **, 0x14);
                if (temp_a0_3 != NULL) {
                    SubscribeLoObject(temp_a0_3, M2C_FIELD(arg0, s8 **, 0));
                }
                break;
            case 12:                                /* switch 2 */
                temp_a1_2 = M2C_FIELD(arg0, s8 **, 0x14);
                if (temp_a1_2 != NULL) {
                    func_002046F0(M2C_FIELD(arg0, s8 **, 0), temp_a1_2);
                }
                FixStepAngularVelocity__FP4STEP(M2C_FIELD(arg0, s8 **, 0));
                break;
            }
            M2C_FIELD(arg0, s32 *, 0x2C) = -1;
            var_s7 = &g_2dded0;
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), f32 *, 0x20C) = (f32) g_2dded0;
            goto block_34;
        case 7:                                     /* switch 1 */
            var_s7 = (f32 *)0x2E0000;
            if (arg1 < 0xB) {
                var_v1 = arg1 + 1;
                if (arg1 >= 9) {
                    temp_s0_4 = M2C_FIELD(arg0, s8 **, 0x14);
                    temp_a0_4 = M2C_FIELD(temp_s0_4, s8 **, 0x15C);
                    if (temp_a0_4 != NULL) {
                        temp_a0_5 = M2C_FIELD(arg0, s8 **, 0);
                        asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_a0_4)));
                        temp_v0_5 = M2C_FIELD(temp_a0_5, s8 **, 0xC);
                        asm volatile("lqc2 vf1, 0x240(%0)" : : "r"(temp_a0_5));
                        temp_a2 = M2C_FIELD(temp_v0_5, s16 *, 0xE8);
                        asm volatile("vsub.xyzw vf2, vf3, vf1");
                        asm volatile("sqc2 vf3, 0x60(%0)" : : "r"(sp));
                        s32 vu_4;
                        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_4));
                        M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, M2C_UNK, s16), 0xEC)(temp_a0_5 + temp_a2, vu_4, temp_a2);
                        temp_v1_4 = M2C_FIELD(arg0, s8 **, 0);
                        asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(temp_v1_4, s32 *, 0x1048)));
                        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
                        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                        asm volatile("vadda.xyzw ACC, vf0, vf3");
                        asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
                        asm volatile("sqc2 vf3, 0x1060(%0)" : : "r"(temp_v1_4));
                        SetStepRadTargetDir(M2C_FIELD(arg0, s8 **, 0), *(s128 *)PmatLoWorld(M2C_FIELD(temp_s0_4, s8 **, 0x15C)));
                        temp_v0_6 = M2C_FIELD(arg0, s8 **, 0);
                        temp_v1_5 = M2C_FIELD(temp_v0_6, s8 **, 0xC);
                        temp_a2_2 = M2C_FIELD(temp_v1_5, M2C_UNK (**)(s8 *, s8 *), 0xF4);
                        temp_a2_2(temp_v0_6 + M2C_FIELD(temp_v1_5, s16 *, 0xF0), temp_v0_6 + 0x1B0);
                        temp_a3 = M2C_FIELD(arg0, s8 **, 0);
                        temp_v0_7 = M2C_FIELD(temp_a3, s8 **, 0xC);
                        M2C_FIELD(temp_v0_7, M2C_UNK (**)(s8 *, s128), 0x11C)(temp_a3 + M2C_FIELD(temp_v0_7, s16 *, 0x118), g_2a2dd0);
                        temp_a2_3 = M2C_FIELD(arg0, s8 **, 0);
                        temp_v0_8 = M2C_FIELD(temp_a2_3, s8 **, 0xC);
                        M2C_FIELD(temp_v0_8, M2C_UNK (**)(s8 *, s128, s8 *), 0x124)(temp_a2_3 + M2C_FIELD(temp_v0_8, s16 *, 0x120), g_2a2dd0, temp_a2_3);
                    }
                    SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(&B_002DDF40, 0xA, (s8 *)&B_002DDF40 + 0x4C0, M2C_FIELD(arg0, s8 **, 0));
                    goto block_34;
                }
            } else {
                goto block_34;
            }
            break;
        case 9:                                     /* switch 1 */
        case 10:                                    /* switch 1 */
            if ((arg1 >= 0xB) || (var_s7 = (f32 *)0x2E0000, ((arg1 < 9) != 0))) {
                RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DDF40, 2, 0xA, (s8 *)&B_002DDF40 + 0x4C0);
                var_s7 = &g_2dded0;
            }
            goto block_34;
        }
        var_s3 = NULL;
        var_s5 = 0;
        var_s1 = 1;
        var_f20 = 0.0f;
        var_f21 = 0x3F800000;
        var_s6 = 0;
        switch (var_v1) {                           /* switch 3 */
        case 0:                                     /* switch 3 */
            temp_v1_6 = M2C_FIELD(arg0, u32 *, 8);
            M2C_FIELD(arg0, s32 *, 0x500) = 0;
            switch (temp_v1_6) {                    /* switch 4 */
            case 1:                                 /* switch 4 */
                SetHbskHbsks(M2C_FIELD(arg0, s8 **, 0x14), 0);
                temp_a0_6 = M2C_FIELD(arg0, s8 **, 0);
                if (temp_a0_6 == g_2e1e40) {
                    temp_a1_3 = M2C_FIELD(temp_a0_6, s8 **, 0x19A0);
                    temp_v0_9 = M2C_FIELD(temp_a1_3, s8 **, 0xC);
                    M2C_FIELD(temp_v0_9, M2C_UNK (**)(s8 *, s8 *), 0x44)(temp_a1_3 + M2C_FIELD(temp_v0_9, s16 *, 0x40), temp_a1_3);
                default:                            /* switch 4 */
                    ;
                }
                break;
            case 3:                                 /* switch 4 */
            case 4:                                 /* switch 4 */
                temp_s0_5 = M2C_FIELD(arg0, s8 **, 0x14);
                temp_v1_7 = M2C_FIELD(temp_s0_5, s8 **, 0xC);
                M2C_FIELD(temp_v1_7, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(temp_s0_5 + M2C_FIELD(temp_v1_7, s16 *, 0x18), 6, 0, 0);
                UnsubscribeLoObject(temp_s0_5, M2C_FIELD(arg0, s8 **, 0));
                func_00204F78(M2C_FIELD(arg0, s8 **, 0), temp_s0_5, 0);
                break;
            case 6:                                 /* switch 4 */
                temp_a0_7 = M2C_FIELD(arg0, s8 **, 0);
                if (M2C_FIELD(temp_a0_7, s32 *, 0x18D8) == 0) {
                    SetJtJtcs(temp_a0_7, -1);
                }
                break;
            case 11:                                /* switch 4 */
                temp_a0_8 = M2C_FIELD(arg0, s8 **, 0x14);
                if (temp_a0_8 != NULL) {
                    UnsubscribeLoObject(temp_a0_8, M2C_FIELD(arg0, s8 **, 0));
                }
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x130C) = 0;
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x9BC) = -1;
                break;
            case 5:                                 /* switch 4 */
            case 9:                                 /* switch 4 */
                Carry_SetState(arg0 + 0x440, -1);
                break;
            case 12:                                /* switch 4 */
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x1318) = -1;
                Carry_Detach(M2C_FIELD(arg0, s8 **, 0) + 0x900);
                temp_a0_9 = M2C_FIELD(arg0, s8 **, 0);
                if (temp_a0_9 == g_2e1e40) {
                    M2C_FIELD(temp_a0_9, s32 *, 0x1BCC) = 0;
                }
                break;
            case 2:                                 /* switch 4 */
                temp_a0_10 = M2C_FIELD(g_2e1e40, s32 *, 0x2048);
                if (temp_a0_10 != 0) {
                    StopAmb(temp_a0_10, 0);
                    VirtualRefPtr_Assign(g_2e1e40 + 0x2048, 0);
                }
                break;
            }
            temp_a1_4 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x1024);
            if (temp_a1_4 != 0) {
                if (temp_a1_4 != (s32)M2C_FIELD(arg0, s8 **, 0x68)) {
                    if (temp_a1_4 == *M2C_FIELD(arg0, s32 **, 0x18)) {
                        func_00140C88(M2C_FIELD(arg0, s8 **, 0), NULL);
                    }
                } else {
                    func_00140C88(M2C_FIELD(arg0, s8 **, 0), NULL);
                }
            }
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x1038) = -1;
            M2C_FIELD(arg0, u32 *, 8) = -1U;
            M2C_FIELD(arg0, s8 **, 0x14) = NULL;
            M2C_FIELD(arg0, f32 *, 0x20) = 0.0f;
            M2C_FIELD(arg0, f32 *, 0x1C) = 0.0f;
            M2C_FIELD(arg0, s32 **, 0x18) = NULL;
            M2C_FIELD(arg0, s32 *, 0x4FC) = -1;
            M2C_FIELD(arg0, s32 *, 0xC) = -1;
            M2C_FIELD(arg0, s32 *, 0x34) = 0;
            break;
        case 1:                                     /* switch 3 */
        case 6:                                     /* switch 3 */
            temp_v1_8 = M2C_FIELD(arg0, u32 *, 8);
            switch (temp_v1_8) {                    /* switch 5 */
            case 13:                                /* switch 5 */
                if (arg1 != 0) {
                    var_s3 = M2C_FIELD(arg0, s8 **, 0x174);
                } else {
                    var_s3 = M2C_FIELD(arg0, s8 **, 0x510);
                }
block_71:
                var_s1 = 9;
            default:                                /* switch 5 */
                break;
            case 0:                                 /* switch 5 */
                var_s3 = M2C_FIELD(arg0, s8 **, 0x174);
                goto block_71;
            case 2:                                 /* switch 5 */
                var_s3 = M2C_FIELD(arg0, s8 **, 0x514);
                goto block_71;
            case 1:                                 /* switch 5 */
                var_s5 = M2C_FIELD(arg0, s32 *, 0x230);
                var_s1 = 1;
                break;
            case 4:                                 /* switch 5 */
                var_s3 = M2C_FIELD(arg0, s8 **, 0x234);
                var_s1 = 9;
                var_s6 = 7;
                break;
            case 3:                                 /* switch 5 */
                if ((M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0x1BC) != 0) && (temp_a0_11 = M2C_FIELD(arg0, s8 **, 0x314), var_s3 = temp_a0_11, (temp_a0_11 != NULL))) {
                    M2C_FIELD(arg0, f32 *, 0x318) = 0.0f;
                    M2C_FIELD(arg0, f32 *, 0x31C) = 0.0f;
                } else {
                    var_s3 = M2C_FIELD(arg0, s8 **, 0x238);
                }
                var_s1 = 9;
                var_s6 = 0x1F;
                break;
            case 6:                                 /* switch 5 */
            case 7:                                 /* switch 5 */
                var_s3 = M2C_FIELD(arg0, s8 **, 0x320);
                goto block_71;
            case 5:                                 /* switch 5 */
            case 9:                                 /* switch 5 */
                var_f21 = 0;
                M2C_FIELD(arg0, s8 **, 0x4C4) = (s8 *) M2C_FIELD(arg0, s8 **, 0x14);
                Carry_SetState(arg0 + 0x440, 0);
                var_s3 = M2C_FIELD(arg0, s8 **, 0x470);
                var_f20 = M2C_FIELD(var_s3, f32 *, 0x74) * 0.5f;
                break;
            case 10:                                /* switch 5 */
                if (!(D_FLT_002BF640 <= M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0x150), f32 *, 0x1C))) {
                    var_s3 = M2C_FIELD(arg0, s8 **, 0x4F4);
                } else {
                    var_s3 = M2C_FIELD(arg0, s8 **, 0x4F0);
                }
                break;
            case 11:                                /* switch 5 */
                if (M2C_FIELD(arg0, s32 *, 0x4FC) != 0x15) {
                    var_s3 = M2C_FIELD(arg0, s8 **, 0x4F8);
                } else {
                    var_s3 = M2C_FIELD(g_2f7900, s8 **, 0x1AF0);
                    if (var_s3 == NULL) {
                        var_s3 = M2C_FIELD(arg0, s8 **, 0x4F8);
                    }
                }
                break;
            case 12:                                /* switch 5 */
                var_s3 = M2C_FIELD(arg0, s8 **, 0x50C);
                break;
            }
            var_v1_2 = g_2a2dd0;
block_141:
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s128 *, 0x190) = var_v1_2;
            break;
        case 2:                                     /* switch 3 */
            temp_v1_9 = M2C_FIELD(arg0, u32 *, 8);
            if (temp_v1_9 != 0) {
                var_s1 = 9;
                if (temp_v1_9 != 0xD) {
                } else {
                    var_s3 = M2C_FIELD(arg0, s8 **, 0x170);
                    goto block_121;
                }
            } else {
                var_s3 = M2C_FIELD(arg0, s8 **, 0x170);
                if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x1024) == 0) {
                    if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x14), 0xC) == 0) {
                        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x14), 0x22) == 0) {
                            var_s1 = 9;
                            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x14), 0x26) != 0) {
                                temp_s0_6 = M2C_FIELD(arg0, s8 **, 0x14);
                                var_a1 = M2C_FIELD(temp_s0_6, s8 **, 0xE0);
                                if (var_a1 != NULL) {
                                    goto block_109;
                                }
                                ResetJtDynamicTunnel__FP2JT(arg0, var_a1);
                                temp_v0_10 = PmatLoWorld(temp_s0_6);
                                asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(temp_v0_10));
                                asm volatile("lqc2 vf4, (%0)" : : "r"(&D_002BF650));
                                asm volatile("lqc2 vf2, (%0)" : : "r"(temp_v0_10));
                                asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v0_10));
                                asm volatile("vmulax.xyz ACC, vf2, vf4x");
                                asm volatile("vmadday.xyz ACC, vf1, vf4y");
                                asm volatile("vmaddz.xyz vf5, vf3, vf4z");
                                s32 vu_5;
                                asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_5));
                                temp_v0_11 = vu_5;
                                M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x68), s8 **, 0x114), s32 *, 0x10) = temp_v0_11;
                                s64 vu_6;
                                asm volatile("pextuw %0, %1, %2" : "=r"(vu_6) : "r"(0), "r"(temp_v0_11));
                                temp_f1 = vu_6;
                                s64 vu_7;
                                asm volatile("prot3w %0, %1" : "=r"(vu_7) : "r"(temp_v0_11));
                                M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x68), s8 **, 0x114), f32 *, 0x20) = vu_7;
                                M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x68), s8 **, 0x114), f32 *, 0x30) = temp_f1;
                                goto block_111;
                            }
                        } else {
                            temp_s1_2 = M2C_FIELD(arg0, s8 **, 0x14);
                            var_a1 = M2C_FIELD(temp_s1_2, s8 **, 0xE0);
                            if (var_a1 == NULL) {
                                ResetJtDynamicTunnel__FP2JT(arg0, var_a1);
                                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x68), s32 *, 0x12C) = 1;
                                temp_s0_7 = M2C_FIELD(arg0, s8 **, 0x68);
                                s64 vu_8;
                                asm volatile("por %0, %1, %2" : "=r"(vu_8) : "r"(0), "r"(PosLoWorld(temp_s1_2)));
                                M2C_FIELD(temp_s0_7, s128 *, 0x150) = ConvertAloPos(0, M2C_FIELD(arg0, s8 **, 0x68), vu_8);
                                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x68), f32 *, 0x160) = (f32) M2C_FIELD(temp_s1_2, f32 *, 0x10C);
                                goto block_111;
                            }
                            goto block_109;
                        }
                    } else {
                        temp_s0_8 = M2C_FIELD(arg0, s8 **, 0x14);
                        var_a1 = M2C_FIELD(temp_s0_8, s8 **, 0x190);
                        if (var_a1 == NULL) {
                            ResetJtDynamicTunnel__FP2JT(arg0, var_a1);
                            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x68), s8 **, 0x10C) = temp_s0_8;
block_111:
                            func_00140C88(M2C_FIELD(arg0, s8 **, 0), M2C_FIELD(arg0, s8 **, 0x68));
                            var_s1 = 9;
                        } else {
block_109:
                            func_00140C88(M2C_FIELD(arg0, s8 **, 0), var_a1);
                            var_s1 = 9;
                        }
                    }
                } else {
block_121:
                    var_s1 = 9;
                }
            }
            break;
        case 5:                                     /* switch 3 */
            temp_v1_10 = M2C_FIELD(arg0, u32 *, 8);
            if (temp_v1_10 != 2) {
                if ((s32) temp_v1_10 < 3) {
                    var_s1 = 9;
                    if (temp_v1_10 != 1) {
                    } else {
                        var_s3 = M2C_FIELD(arg0, s8 **, 0x184);
                        ResetRunBlendFootsteps(arg0 + 0x180);
                        var_s1 = 9;
                    }
                } else {
                    var_s1 = 9;
                    if (temp_v1_10 == 3) {
                        var_s3 = M2C_FIELD(arg0, s8 **, 0x244);
                        ResetRunBlendFootsteps(arg0 + 0x240);
                        var_s1 = 9;
                    }
                }
            } else {
                temp_v0_12 = M2C_FIELD(arg0, s8 **, 0);
                var_s3 = M2C_FIELD(temp_v0_12, s8 **, 0x1C34);
                ResetRunBlendFootsteps(temp_v0_12 + 0x1C30);
                goto block_121;
            }
            break;
        case 4:                                     /* switch 3 */
            var_s3 = M2C_FIELD(arg0, s8 **, 0x17C);
            var_v1_2 = g_2a2dd0;
            goto block_141;
        case 3:                                     /* switch 3 */
            var_s3 = M2C_FIELD(arg0, s8 **, 0x178);
            var_v1_2 = g_2a2dd0;
            goto block_141;
        case 8:                                     /* switch 3 */
            temp_s0_9 = M2C_FIELD(arg0, s8 **, 0x14);
            temp_a0_12 = M2C_FIELD(temp_s0_9, s8 **, 0x15C);
            var_s3 = M2C_FIELD(arg0, s8 **, 0x324);
            if (temp_a0_12 != NULL) {
                temp_v0_13 = PmatLoWorld(temp_a0_12);
                temp_a1_5 = M2C_FIELD(temp_v0_13, s128 *, 0);
                sp20 = temp_a1_5;
                sp30 = M2C_FIELD(temp_v0_13, s128 *, 0x10);
                temp_a2_4 = M2C_FIELD(temp_v0_13, s128 *, 0x20);
                sp40 = temp_a2_4;
                SetStepRadTargetDir(M2C_FIELD(arg0, s8 **, 0), temp_a1_5);
            }
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s128 *, 0x190) = (s128) g_2a2dd0;
            temp_v0_14 = M2C_FIELD(temp_s0_9, s8 **, 0xC);
            M2C_FIELD(temp_v0_14, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(temp_s0_9 + M2C_FIELD(temp_v0_14, s16 *, 0x18), 5, 0, 0);
            break;
        case 9:                                     /* switch 3 */
            var_s3 = M2C_FIELD(arg0, s8 **, 0x328);
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s128 *, 0x190) = (s128) g_2a2dd0;
            temp_t2 = M2C_FIELD(arg0, s8 **, 0x14);
            temp_v0_15 = M2C_FIELD(temp_t2, s8 **, 0xC);
            M2C_FIELD(temp_v0_15, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(temp_t2 + M2C_FIELD(temp_v0_15, s16 *, 0x18), 6, 0, 0);
            break;
        case 10:                                    /* switch 3 */
            var_s5 = M2C_FIELD(arg0, s32 *, 0x32C);
            if (M2C_FIELD(arg0, s32 *, 0xC) == 7) {
                temp_a0_13 = M2C_FIELD(arg0, s8 **, 0);
                temp_v1_11 = M2C_FIELD(temp_a0_13, s32 *, 0x40);
                if ((temp_v1_11 ^ 1) & 1) {
                    *(s32 *)temp_v1_11 = (s32) (*(s32 *)temp_v1_11 | 0x10);
                } else {
                    M2C_FIELD(temp_a0_13, s32 *, 0x40) = (s32) (temp_v1_11 | 0x10);
                }
                temp_a0_14 = M2C_FIELD(arg0, s8 **, 0);
                if (temp_a0_14 == g_2e1e40) {
                    temp_a0_15 = M2C_FIELD(temp_a0_14, s8 **, 0x19A0);
                    temp_v1_12 = M2C_FIELD(temp_a0_15, s32 *, 0x40);
                    if ((temp_v1_12 ^ 1) & 1) {
                        *(s32 *)temp_v1_12 = (s32) (*(s32 *)temp_v1_12 | 0x10);
                    } else {
                        M2C_FIELD(temp_a0_15, s32 *, 0x40) = (s32) (temp_v1_12 | 0x10);
                    }
                    temp_v1_13 = M2C_FIELD(g_2e1e40, s8 **, 0x19A4);
                    temp_a0_16 = M2C_FIELD(temp_v1_13, s32 *, 0x40);
                    if ((temp_a0_16 ^ 1) & 1) {
                        *(s32 *)temp_a0_16 = (s32) (*(s32 *)temp_a0_16 | 0x10);
                    } else {
                        M2C_FIELD(temp_v1_13, s32 *, 0x40) = (s32) (temp_a0_16 | 0x10);
                    }
                }
            }
            var_v1_2 = g_2a2dd0;
            goto block_141;
        case 11:                                    /* switch 3 */
            var_s3 = M2C_FIELD(arg0, s8 **, 0x430);
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x1038) = -1;
            var_s1 = 9;
            var_v1_2 = g_2a2dd0;
            goto block_141;
        }
        M2C_FIELD(arg0, s32 *, 0xC) = arg1;
        M2C_FIELD(arg0, f32 *, 0x10) = (f32) *var_s7;
        if (arg1 != -1) {
            RetractAsegaHandle(M2C_FIELD(arg0, s8 **, 0) + 0x1030);
            RetractSmaRef(M2C_FIELD(arg0, s8 **, 0) + 0x1034);
            temp_a1_6 = M2C_FIELD(arg0, s8 **, 0);
            ApplyAsegToHandle(var_s3, temp_a1_6, var_s1, temp_a1_6 + 0x1030, var_f20, var_f21);
            func_001F1448(var_s5, M2C_FIELD(arg0, s8 **, 0), -1, var_s1);
            temp_a1_7 = M2C_FIELD(arg0, s8 **, 0);
            temp_v0_16 = M2C_FIELD(temp_a1_7, s8 **, 0xC);
            M2C_FIELD(temp_v0_16, M2C_UNK (**)(s8 *, s8 *), 0x2D4)(temp_a1_7 + M2C_FIELD(temp_v0_16, s16 *, 0x2D0), temp_a1_7);
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0), 0x35) != 0) {
                SetJtLookats(M2C_FIELD(arg0, s8 **, 0), var_s6);
            }
        }
    }
}
}
