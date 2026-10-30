typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefEvalCond__FP5CPairP6CFrame {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[8];                       /* maybe part of sp14[3]? */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ char pad24[0xAC];
};                                                  /* size = 0xD0 */
#define sp14 (*(s32 *)(sp + 0x14))
M2C_UNK CRef_CopyConstruct(s32, s32 *);             /* extern */
M2C_UNK CRef_Destruct(...);                  /* extern */
M2C_UNK RefEval(s32 *, s8 *, s32);                /* extern */
M2C_UNK SetTag__4CRef4TAGK(s32 *, M2C_UNK);         /* extern */
M2C_UNK __as__4CRefRC4CRef(s32 *, s32 *);           /* extern */
s32 RefEvalCond__FP5CPairP6CFrame(s32 arg0, s8 *arg1, s32 arg2) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp20;
    s32 var_s2;
    s8 *temp_s1;
    s8 *var_a1;
    s8 *var_s0;
    s8 *var_s1;
    sp10 = -1;
    CRef_Destruct((s32 *)(sp), -1);
    SetTag__4CRef4TAGK((s32 *)(sp), 0x24);
    var_s0 = M2C_FIELD(M2C_FIELD(arg1, s8 **, 0xC), s8 **, 0x10);
    if (var_s0 != NULL) {
        do {
            temp_s1 = M2C_FIELD(var_s0, s8 **, 0xC);
            if (M2C_FIELD(temp_s1, s32 *, 8) == 0xB) {
                var_s2 = 1;
                goto block_12;
            }
            var_s2 = 0;
            RefEval(&sp20, temp_s1, arg2);
            __as__4CRefRC4CRef(&sp10, &sp20);
            CRef_Destruct(&sp20);
            if ((sp10 != 0x17) || (sp14 != 0)) {
                var_s2 = 1;
            }
            if (var_s2 == 0) {
                var_s0 = M2C_FIELD(var_s0, s8 **, 0x10);
            } else {
                if (M2C_FIELD(temp_s1, s8 **, 0x10) == NULL) {
                    __as__4CRefRC4CRef((s32 *)(sp), &sp10);
                }
block_12:
                if (var_s2 == 0) {
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0x10);
                } else {
                    var_s1 = M2C_FIELD(temp_s1, s8 **, 0x10);
                    if (var_s1 != NULL) {
                        var_a1 = var_s1;
                        do {
                            RefEval(&sp20, var_a1, arg2);
                            __as__4CRefRC4CRef((s32 *)(sp), &sp20);
                            CRef_Destruct(&sp20);
                            var_s1 = M2C_FIELD(var_s1, s8 **, 0x10);
                            var_a1 = var_s1;
                        } while (var_s1 != NULL);
                    }
                    var_s0 = NULL;
                }
            }
        } while (var_s0 != NULL);
    }
    CRef_CopyConstruct(arg0, (s32 *)(sp));
    CRef_Destruct(&sp10);
    CRef_Destruct(sp);
    return arg0;
}
}
