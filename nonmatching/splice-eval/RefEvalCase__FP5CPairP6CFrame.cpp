typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefEvalCase__FP5CPairP6CFrame {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[4];
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ s32 sp24;                            /* inferred */
    /* 0x28 */ char pad28[8];                       /* maybe part of sp24[3]? */
    /* 0x30 */ s32 sp30;                            /* inferred */
    /* 0x34 */ char pad34[0xC];                     /* maybe part of sp30[4]? */
    /* 0x40 */ s32 sp40;                            /* inferred */
    /* 0x44 */ s32 *sp44;                           /* inferred */
    /* 0x48 */ char pad48[0xA8];
};                                                  /* size = 0xF0 */
#define sp24 (*(s32 *)(sp + 0x24))
s32 CRef_CopyConstruct(s32, s32 *);
void CRef_Destruct(s32 *);
s32 RefEval(s32 *, s8 *, s32);
void SetTag__4CRef4TAGK(s32 *, M2C_UNK);
void __as__4CRefRC4CRef(s32 *, s32 *);
s32 bevy_splice_bif_ref_op_eqv(s32 *, M2C_UNK, s32 *, s32);
s32 RefEvalCase__FP5CPairP6CFrame(s32 arg0, s8 *arg1, s32 arg2) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp18;
    s32 sp20;
    s32 sp30;
    s32 sp40;
    s32 *sp44;
    s32 *temp_fp;
    s32 *var_s0_2;
    s32 *var_v1;
    s32 var_a0;
    s32 var_s4;
    s8 *temp_s0;
    s8 *temp_s1;
    s8 *var_a1;
    s8 *var_s0;
    s8 *var_s1;
    s8 *var_s3;
    var_v1 = &sp10;
    sp40 = arg0;
    temp_fp = var_v1;
    sp44 = &sp20;
    var_a0 = 1;
    do {
        *var_v1 = -1;
        var_a0 -= 1;
        var_v1 += 8;
    } while (var_a0 != -1);
    sp20 = -1;
    CRef_Destruct((s32 *)(sp));
    SetTag__4CRef4TAGK((s32 *)(sp), 0x24);
    temp_s0 = M2C_FIELD(M2C_FIELD(arg1, s8 **, 0xC), s8 **, 0x10);
    RefEval(&sp30, temp_s0, arg2);
    __as__4CRefRC4CRef(temp_fp, &sp30);
    CRef_Destruct(&sp30);
    var_s3 = M2C_FIELD(temp_s0, s8 **, 0x10);
    if (var_s3 != NULL) {
        do {
            temp_s1 = M2C_FIELD(var_s3, s8 **, 0xC);
            var_s4 = 1;
            if (M2C_FIELD(temp_s1, s32 *, 8) != 0xB) {
                var_s0 = M2C_FIELD(temp_s1, s8 **, 0xC);
                var_s4 = 0;
                if (var_s0 != NULL) {
                    do {
                        __as__4CRefRC4CRef(&sp18, (s32 *)(var_s0 + 8));
                        bevy_splice_bif_ref_op_eqv(&sp30, 2, temp_fp, arg2);
                        __as__4CRefRC4CRef(sp44, &sp30);
                        CRef_Destruct(&sp30);
                        if (sp20 != 0x17) {
                            var_s0 = M2C_FIELD(var_s0, s8 **, 0x10);
                        } else if (sp24 == 0) {
                            var_s0 = M2C_FIELD(var_s0, s8 **, 0x10);
                        } else {
                            var_s4 = 1;
                            var_s0 = NULL;
                        }
                    } while (var_s0 != NULL);
                }
            }
            if (var_s4 == 0) {
                var_s3 = M2C_FIELD(var_s3, s8 **, 0x10);
            } else {
                var_s1 = M2C_FIELD(temp_s1, s8 **, 0x10);
                if (var_s1 != NULL) {
                    var_a1 = var_s1;
                    do {
                        RefEval(&sp30, var_a1, arg2);
                        __as__4CRefRC4CRef((s32 *)(sp), &sp30);
                        CRef_Destruct(&sp30);
                        var_s1 = M2C_FIELD(var_s1, s8 **, 0x10);
                        var_a1 = var_s1;
                    } while (var_s1 != NULL);
                }
                var_s3 = NULL;
            }
        } while (var_s3 != NULL);
    }
    CRef_CopyConstruct(sp40, (s32 *)(sp));
    CRef_Destruct(&sp20);
    var_s0_2 = sp44 - 8;
    if (temp_fp != sp44) {
        do {
            CRef_Destruct(var_s0_2);
            var_s0_2 -= 8;
        } while (temp_fp != var_s0_2);
    }
    CRef_Destruct((s32 *)(sp));
    return sp40;
}
}
