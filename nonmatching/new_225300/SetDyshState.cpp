typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetDyshState {
    /* 0x000 */ char pad0[0x80];
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x088 */ f32 sp88;                           /* overlap; inferred */
    /* 0x090 */ char pad90[0x10];                   /* maybe part of sp88[5]? */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ char padB0[0x70];
};                                                  /* size = 0x120 */
#define sp80 (*(s128 *)(sp + 0x080))
void AddSoXa__FP2SOP2XA(s8 *, s8 *);
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 FCanSetGuardMode(s8 *, M2C_UNK);
s32 PosLoWorld(s8 *);
void PostGuardStunCommand(s8 *, M2C_UNK);
void RemoveSoXa__FP2SOP2XA(s8 *, s8 *);
void SetGadgetObjState(s8 *, s32);
void func_0012D108(s32, s128);
void func_0017A8C8(s32, M2C_UNK);
s32 func_00205458(s8 *, M2C_UNK);
extern M2C_UNK B_003DD490;
extern s32 D_002C43F0;
extern f32 D_FLT_002C43F4;
extern s128 RO_002A2DE0;
void SetDyshState(s8 *arg0, s32 arg1) {
    s8 sp[0xb0] __attribute__((aligned(16)));
    f32 sp88;
    s128 spA0;
    f32 temp_v0_3;
    f32 var_f20;
    s128 var_v0;
    s32 temp_a0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s3;
    s8 **var_s1;
    s8 *temp_a0;
    s8 *temp_a0_3;
    s8 *temp_s0;
    s8 *temp_v0_4;
    s8 *temp_v1_2;
    s8 *var_s2;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    if (arg1 != temp_v1) {
        if (temp_v1 == 5) {
            temp_a0 = M2C_FIELD(arg0, s8 **, 0x1B4);
            if (temp_a0 != NULL) {
                RemoveSoXa__FP2SOP2XA(temp_a0, arg0 + 0x1B8);
                temp_v0 = func_00205458(M2C_FIELD(arg0, s8 **, 0x1B4), 0xB0);
                if (temp_v0 != 0) {
                    func_0017A8C8(temp_v0, 2);
                }
                temp_a0_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1B4), s32 *, 0xFC4);
                if (temp_a0_2 != 0) {
                    func_0012D108(temp_a0_2, RO_002A2DE0);
                }
                M2C_FIELD(arg0, s8 **, 0x1B4) = NULL;
            }
        }
        SetGadgetObjState(arg0, arg1);
        if (arg1 == 5) {
            temp_a0_3 = M2C_FIELD(arg0, s8 **, 0x1B0);
            if (temp_a0_3 != NULL) {
                var_v0 = PosLoWorld(temp_a0_3);
            } else {
                var_v0 = PosLoWorld(arg0);
            }
            spA0 = var_v0;
            temp_v0_2 = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x38, 0);
            var_f20 = 400.0f;
            var_s2 = NULL;
            if (temp_v0_2 > 0) {
                var_s3 = temp_v0_2;
                var_s1 = (s8 **)(sp);
                do {
                    temp_s0 = *var_s1;
                    if (FCanSetGuardMode(temp_s0, 0xB) == 0) {
                        var_s3 -= 1;
                    } else {
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(temp_s0)));
                        asm volatile("lqc2 vf3, 0xa0(%0)" : : "r"(sp));
                        asm volatile("vsub.xyzw vf1, vf2, vf3");
                        asm volatile("vmul.xyz vf1, vf1, vf1");
                        asm volatile("vaddw.x vf2, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf1, vf1y");
                        asm volatile("vmaddz.x vf1, vf2, vf1z");
                        asm volatile("vsqrt Q, vf1x");
                        asm volatile("vwaitq");
                        asm volatile("vaddq.x vf1, vf0, Q");
                        s32 vu_1;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                        temp_v0_3 = vu_1;
                        var_s3 -= 1;
                        if (temp_v0_3 < var_f20) {
                            var_f20 = temp_v0_3;
                            var_s2 = temp_s0;
                        }
                    }
                    var_s1 += 4;
                } while (var_s3 != 0);
            }
            if (var_s2 != NULL) {
                M2C_FIELD(arg0, s8 **, 0x1B4) = var_s2;
                M2C_FIELD(arg0, s8 **, 0x1B8) = arg0;
                M2C_FIELD(arg0, s8 **, 0x1BC) = var_s2;
                AddSoXa__FP2SOP2XA(var_s2, arg0 + 0x1B8);
                temp_v1_2 = M2C_FIELD(var_s2, s8 **, 0xC);
                asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(temp_v1_2, s32 (**)(s8 *), 0x10C)(var_s2 + M2C_FIELD(temp_v1_2, s16 *, 0x108))));
                asm volatile("qmtc2.ni %0, vf3" : : "r"(D_002C43F0));
                asm volatile("sqc2 vf2, 0x80(%0)" : : "r"(sp));
                asm volatile("vmulx.xyzw vf1, vf2, vf3x");
                asm volatile("sqc2 vf1, 0x80(%0)" : : "r"(sp));
                asm volatile("sqc2 vf3, 0x90(%0)" : : "r"(sp));
                sp88 = D_FLT_002C43F4;
                temp_v0_4 = M2C_FIELD(var_s2, s8 **, 0xC);
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, s128), 0x11C)(var_s2 + M2C_FIELD(temp_v0_4, s16 *, 0x118), sp80);
                PostGuardStunCommand(var_s2, 0);
            }
        }
    }
}
}
