typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefOpFilter {
    /* 0x00 */ s32 *sp0;                            /* inferred */
    /* 0x04 */ char pad4[0xC];                      /* maybe part of sp0[4]? */
    /* 0x10 */ s32 *sp10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of sp10[4]? */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ s32 sp24;                            /* inferred */
    /* 0x28 */ char pad28[8];                       /* maybe part of sp24[3]? */
    /* 0x30 */ s32 *sp30;                           /* inferred */
    /* 0x34 */ char pad34[0xC];                     /* maybe part of sp30[4]? */
    /* 0x40 */ s32 *sp40;                           /* inferred */
    /* 0x44 */ s32 *sp44;                           /* inferred */
    /* 0x48 */ char pad48[0x88];
};                                                  /* size = 0xD0 */
#define sp0 (*(s32 * *)(sp + 0x00))
#define sp24 (*(s32 *)(sp + 0x24))
M2C_UNK CPairPtr_Destructor(s32 *, M2C_UNK);        /* extern */
M2C_UNK CRef_ConstructPair(s32, s32);               /* extern */
M2C_UNK CRef_CopyConstruct(s8 *);                 /* extern */
M2C_UNK CRef_Destruct(s32 *);                       /* extern */
M2C_UNK FreeSlotheapPv(M2C_UNK *, s32 *);           /* extern */
M2C_UNK PairHandle_Assign(s32 **, s32 *);           /* extern */
M2C_UNK PairHandle_Init(s32 **, s32 *);             /* extern */
s32 *PpairNew();                                    /* extern */
M2C_UNK RefEval(s32 *, s32 *, s32);                 /* extern */
M2C_UNK SetTag__4CRef4TAGK(s32, M2C_UNK);           /* extern */
M2C_UNK UnlinkPairNode(s32 *);                      /* extern */
M2C_UNK __as__4CRefRC4CRef(s32 *, s8 *);          /* extern */
M2C_UNK bevy_splice_value_list_ref(s32 *, s32 *);   /* extern */
M2C_UNK func_00121578(s8 *, s32 **, s32 **);      /* extern */
extern M2C_UNK B_004520A8;
s32 RefOpFilter(s32 arg0, s8 *arg2, s32 arg3) {
    s32 saved_reg_s2;
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 *sp10;
    s32 sp20;
    s32 *sp30;
    s32 *sp40;
    s32 *sp44;
    s32 *var_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s8 *temp_s0;
    s8 *var_s1;
    var_s2 = (s32 *)(saved_reg_s2);
    if (M2C_FIELD(arg2, s32 *, 8) == 0) {
        CRef_CopyConstruct(arg2 + 8);
    } else {
        func_00121578(sp, &sp40, &sp44);
        __as__4CRefRC4CRef(sp40, arg2);
        var_s1 = M2C_FIELD(arg2, s8 **, 0xC);
        sp10 = NULL;
        if (var_s1 != NULL) {
            do {
                temp_s0 = var_s1 + 8;
                __as__4CRefRC4CRef(sp44, temp_s0);
                RefEval(&sp20, sp0, arg3);
                if ((sp20 == 0x17) && (sp24 != 0)) {
                    PairHandle_Init(&sp30, PpairNew());
                    __as__4CRefRC4CRef(sp30 + 8, temp_s0);
                    if (sp10 == NULL) {
                        PairHandle_Assign(&sp10, PpairNew());
                        bevy_splice_value_list_ref(sp10 + 8, sp30);
                    } else {
                        PairHandle_Assign((s32 **)(var_s2 + 0x10), sp30);
                    }
                    var_s2 = sp30;
                    if (sp30 != NULL) {
                        temp_v0 = *sp30 - 1;
                        *sp30 = temp_v0;
                        if (temp_v0 == 0) {
                            CPairPtr_Destructor(sp30 + 0x10, 2);
                            CRef_Destruct(sp30 + 8);
                            UnlinkPairNode(sp30);
                            FreeSlotheapPv(&B_004520A8, sp30);
                        }
                    }
                }
                var_s1 = M2C_FIELD(var_s1, s8 **, 0x10);
                CRef_Destruct(&sp20);
            } while (var_s1 != NULL);
        }
        if (sp10 != NULL) {
            CRef_ConstructPair(arg0, M2C_FIELD(sp10, s32 *, 0xC));
            if (sp10 != NULL) {
                temp_v0_2 = M2C_FIELD(sp10, s32 *, 0) - 1;
                M2C_FIELD(sp10, s32 *, 0) = temp_v0_2;
                if (temp_v0_2 == 0) {
                    CPairPtr_Destructor(sp10 + 0x10, 2);
                    CRef_Destruct(sp10 + 8);
                    UnlinkPairNode(sp10);
                    FreeSlotheapPv(&B_004520A8, sp10);
                }
            }
            if (sp0 != NULL) {
                temp_v0_3 = *sp0 - 1;
                *sp0 = temp_v0_3;
                if (temp_v0_3 == 0) {
                    CPairPtr_Destructor(sp0 + 0x10, 2);
                    CRef_Destruct(sp0 + 8);
                    UnlinkPairNode(sp0);
                    FreeSlotheapPv(&B_004520A8, sp0);
                }
            }
        } else {
            SetTag__4CRef4TAGK(arg0, 0);
            if (sp10 != NULL) {
                temp_v0_4 = M2C_FIELD(sp10, s32 *, 0) - 1;
                M2C_FIELD(sp10, s32 *, 0) = temp_v0_4;
                if (temp_v0_4 == 0) {
                    CPairPtr_Destructor(sp10 + 0x10, 2);
                    CRef_Destruct(sp10 + 8);
                    UnlinkPairNode(sp10);
                    FreeSlotheapPv(&B_004520A8, sp10);
                }
            }
            if (sp0 != NULL) {
                temp_v0_5 = *sp0 - 1;
                *sp0 = temp_v0_5;
                if (temp_v0_5 == 0) {
                    CPairPtr_Destructor(sp0 + 0x10, 2);
                    CRef_Destruct(sp0 + 8);
                    UnlinkPairNode(sp0);
                    FreeSlotheapPv(&B_004520A8, sp0);
                }
            }
        }
    }
    return arg0;
}
}
