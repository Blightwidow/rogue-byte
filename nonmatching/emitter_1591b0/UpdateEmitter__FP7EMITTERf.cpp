typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateEmitter__FP7EMITTERf {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s8 *sp10;                          /* inferred */
    /* 0x14 */ s8 *sp14;                          /* inferred */
    /* 0x18 */ s8 *sp18;                          /* inferred */
    /* 0x1C */ char pad1C[0x64];
};                                                  /* size = 0x80 */
s32 CPvDl__FP2DL(s32);                              /* extern */
M2C_UNK EmitParticles__FiP5EMITBP5EMITG(s32, s8 *, s8 **); /* extern */
s32 FIsDlEmpty__FP2DL(s8 *);                      /* extern */
s32 FIsLoInWorld(s8 *);                           /* extern */
s32 FPausedEmitter__FP7EMITTER(s8 *);             /* extern */
f32 GRandInRange(f32, f32);                         /* extern */
M2C_UNK ModifyEmitterParticles__FP7EMITTER(s8 *); /* extern */
M2C_UNK OnEmitterValuesChanged__FP7EMITTER();       /* extern */
M2C_UNK PauseEmitterIndefinite__FP7EMITTER(s8 *); /* extern */
M2C_UNK PauseEmitter__FP7EMITTERf(s8 *, f32);     /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
M2C_UNK UpdateLo(s8 *);                           /* extern */
M2C_UNK memset(s8 **, M2C_UNK, M2C_UNK);          /* extern */
extern M2C_UNK B_002DDF40;
extern f32 g_2dded0;
void UpdateEmitter__FP7EMITTERf(s8 *arg0) {
    s8 *sp10;
    s8 *sp14;
    s8 *sp18;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 temp_a0;
    s32 temp_s0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 var_s2;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s8 **temp_v1_3;
    s8 *temp_a0_2;
    s8 *temp_s0;
    s8 *var_s0;
    if (M2C_FIELD(arg0, s32 *, 0xE0) != 0) {
        OnEmitterValuesChanged__FP7EMITTER();
    }
    UpdateLo(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x118) == -1) {
        if (FIsDlEmpty__FP2DL(arg0 + 0x11C) != 0) {
            if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
                temp_f20 = M2C_FIELD(arg0, f32 *, 0x38) * M2C_FIELD(&B_002DDF40, f32 *, 0x1C);
                asm volatile("lqc2 vf2, 0x90(%0)" : : "r"(&B_002DDF40));
                var_v1 = 1;
                asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(arg0)));
                asm volatile("vsub.xyzw vf1, vf3, vf2");
                asm volatile("vmul.xyz vf1, vf1, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                if (!((temp_f20 * temp_f20) < vu_1)) {
                    var_v1 = 0;
                }
                if (var_v1 == 0) {
                    goto block_19;
                }
            } else {
                goto block_19;
            }
        } else {
            var_s0 = M2C_FIELD(arg0, s8 **, 0x11C);
            if (var_s0 != NULL) {
loop_8:
                if (FIsLoInWorld(var_s0) != 0) {
                    if (M2C_FIELD(var_s0, s32 *, 0x10) != 0) {
                        temp_f20_2 = M2C_FIELD(var_s0, f32 *, 0x38) * M2C_FIELD(&B_002DDF40, f32 *, 0x1C);
                        asm volatile("lqc2 vf2, 0x90(%0)" : : "r"(&B_002DDF40));
                        var_v1_2 = 1;
                        asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(var_s0)));
                        asm volatile("vsub.xyzw vf1, vf3, vf2");
                        asm volatile("vmul.xyz vf1, vf1, vf1");
                        asm volatile("vaddw.x vf2, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf1, vf1y");
                        asm volatile("vmaddz.x vf1, vf2, vf1z");
                        s32 vu_2;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                        if (!(vu_2 < (temp_f20_2 * temp_f20_2))) {
                            var_v1_2 = 0;
                        }
                        if (var_v1_2 == 0) {
                            goto block_13;
                        }
                        goto block_19;
                    }
block_19:
                    if (FPausedEmitter__FP7EMITTER(arg0) == 0) {
                        temp_v1 = M2C_FIELD(arg0, s32 *, 0xF0);
                        var_s2 = 0;
                        switch (temp_v1) {          /* irregular */
                        case 3:
                            temp_f0 = M2C_FIELD(arg0, f32 *, 0x144) + (M2C_FIELD(arg0, f32 *, 0x130) * M2C_FIELD(arg0, f32 *, 0x13C) * M2C_FIELD(&g_2dded0, f32 *, 4));
                            var_s2 = (s32) temp_f0;
                            temp_f1 = (f32) var_s2;
                            M2C_FIELD(arg0, f32 *, 0x144) = (f32) (temp_f0 - temp_f1);
                            if (temp_f1 > 1.0f) {
                                temp_v1_2 = M2C_FIELD(arg0, s32 *, 0xF4);
                                if (temp_v1_2 >= 0) {
                                    var_s2 = (var_s2 >= temp_v1_2) ? temp_v1_2 : var_s2;
                                    M2C_FIELD(arg0, s32 *, 0xF4) = (s32) (temp_v1_2 - var_s2);
                                }
                                if (M2C_FIELD(arg0, s32 *, 0x114) != 0) {
                                    PauseEmitterIndefinite__FP7EMITTER(arg0);
                                    goto block_35;
                                }
                                if (GRandInRange(0.0f, 1.0f) <= M2C_FIELD(arg0, f32 *, 0x104)) {
                                    PauseEmitter__FP7EMITTERf(arg0, GRandInRange(M2C_FIELD(arg0, f32 *, 0x108), M2C_FIELD(arg0, f32 *, 0x10C)));
block_35:
                                    M2C_FIELD(arg0, f32 *, 0x130) = (f32) (GRandInRange(M2C_FIELD(arg0, f32 *, 0xF8), M2C_FIELD(arg0, f32 *, 0xFC)) * 60.0f);
                                }
                            }
                        default:
block_54:
                            if (var_s2 != 0) {
                                memset(&sp10, 0, 0xC);
                                sp18 = arg0;
                                sp14 = arg0 + 0x14C;
                                sp10 = arg0 + 0x150;
                                temp_v1_3 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE4), s8 ***, 8);
                                temp_s0 = M2C_FIELD(temp_v1_3, s8 **, 0);
                                if ((temp_s0 == NULL) && (M2C_FIELD(temp_v1_3, s32 *, 4) == 0)) {
                                    M2C_FIELD(temp_v1_3, s8 **, 0) = arg0;
                                }
                                EmitParticles__FiP5EMITBP5EMITG(var_s2, M2C_FIELD(arg0, s8 **, 0xE4), &sp10);
                                *M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE4), s8 ***, 8) = temp_s0;
                            }
                            break;
                        case 2:
                            temp_v1_4 = M2C_FIELD(arg0, s32 *, 0xF4);
                            var_s2 = (s32) M2C_FIELD(arg0, f32 *, 0x130);
                            if (temp_v1_4 >= 0) {
                                var_s2 = (var_s2 >= temp_v1_4) ? temp_v1_4 : var_s2;
                                M2C_FIELD(arg0, s32 *, 0xF4) = (s32) (temp_v1_4 - var_s2);
                            }
                            if (M2C_FIELD(arg0, s32 *, 0x114) != 0) {
                                PauseEmitterIndefinite__FP7EMITTER(arg0);
                            } else if (GRandInRange(0.0f, 1.0f) <= M2C_FIELD(arg0, f32 *, 0x104)) {
                                PauseEmitter__FP7EMITTERf(arg0, GRandInRange(M2C_FIELD(arg0, f32 *, 0x108), M2C_FIELD(arg0, f32 *, 0x10C)));
                            }
                            M2C_FIELD(arg0, f32 *, 0x130) = GRandInRange(M2C_FIELD(arg0, f32 *, 0xF8), M2C_FIELD(arg0, f32 *, 0xFC));
                            goto block_54;
                        case 0:
                            temp_f0_2 = M2C_FIELD(arg0, f32 *, 0x144) + (M2C_FIELD(arg0, f32 *, 0x130) * M2C_FIELD(arg0, f32 *, 0x13C) * M2C_FIELD(&g_2dded0, f32 *, 4));
                            var_s2 = (s32) temp_f0_2;
                            M2C_FIELD(arg0, f32 *, 0x144) = (f32) (temp_f0_2 - (f32) var_s2);
                            if (var_s2 != 0) {
                                temp_v1_5 = M2C_FIELD(arg0, s32 *, 0xF4);
                                if (temp_v1_5 >= 0) {
                                    var_s2 = (var_s2 >= temp_v1_5) ? temp_v1_5 : var_s2;
                                    M2C_FIELD(arg0, s32 *, 0xF4) = (s32) (temp_v1_5 - var_s2);
                                }
                                goto block_54;
                            }
                            break;
                        case 1:
                            temp_s0_2 = (s32) (M2C_FIELD(arg0, f32 *, 0x110) * M2C_FIELD(arg0, f32 *, 0x13C));
                            if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE4), s32 *, 4) != 0) {
                                temp_a0 = M2C_FIELD(arg0, s32 *, 0x14C);
                                var_v0 = 0;
                                if (temp_a0 != 0) {
                                    var_v0 = CPvDl__FP2DL(temp_a0 + 0x15C);
                                }
                            } else {
                                temp_a0_2 = M2C_FIELD(arg0, s8 **, 0x150);
                                var_v0 = 0;
                                if (temp_a0_2 != NULL) {
                                    var_v0 = M2C_FIELD(temp_a0_2, s32 *, 0x444);
                                }
                            }
                            temp_v1_6 = temp_s0_2 - var_v0;
                            var_s2 = (temp_v1_6 > 0) ? temp_v1_6 : 0;
                            goto block_54;
                        }
                        if (M2C_FIELD(arg0, f32 *, 0x138) <= M2C_FIELD(&g_2dded0, f32 *, 0)) {
                            M2C_FIELD(arg0, f32 *, 0x130) = GRandInRange(M2C_FIELD(arg0, f32 *, 0xF8), M2C_FIELD(arg0, f32 *, 0xFC));
                            M2C_FIELD(arg0, f32 *, 0x138) = (f32) (M2C_FIELD(&g_2dded0, f32 *, 0) + M2C_FIELD(arg0, f32 *, 0x134));
                        }
                        ModifyEmitterParticles__FP7EMITTER(arg0);
                    }
                } else {
block_13:
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0x128);
                    if (var_s0 == NULL) {
                    } else {
                        goto loop_8;
                    }
                }
            }
        }
    }
}
}
