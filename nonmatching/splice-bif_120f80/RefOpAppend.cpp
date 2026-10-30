typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefOpAppend {
    /* 0x00 */ s32 *sp0;                            /* inferred */
    /* 0x04 */ char pad4[0xC];                      /* maybe part of sp0[4]? */
    /* 0x10 */ s32 *sp10;                           /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of sp10[4]? */
    /* 0x20 */ s32 *sp20;                           /* inferred */
    /* 0x24 */ char pad24[0x7C];
};                                                  /* size = 0xA0 */
M2C_UNK CPairPtr_Destructor(s32 *, M2C_UNK);        /* extern */
M2C_UNK CRef_ConstructPair(s32, s32);               /* extern */
M2C_UNK CRef_CopyConstruct(s8 *);                 /* extern */
M2C_UNK CRef_Destruct(s32 *);                       /* extern */
M2C_UNK FreeSlotheapPv(M2C_UNK *, s32 *);           /* extern */
M2C_UNK PairHandle_Assign(s32 **, s32 *);           /* extern */
M2C_UNK PpairClone(s32 **, s32 *, M2C_UNK, M2C_UNK); /* extern */
s32 *PpairNew();                                    /* extern */
M2C_UNK SetTag__4CRef4TAGK(s32, M2C_UNK);           /* extern */
M2C_UNK UnlinkPairNode(s32 *);                      /* extern */
M2C_UNK bevy_splice_value_list_ref(s32 *, s32 *);   /* extern */
extern M2C_UNK B_004520A8;
s32 RefOpAppend(s32 arg0, s8 *arg2) {
    s32 saved_reg_s1;
    s8 sp[0x40] __attribute__((aligned(16)));
    s32 *sp0;
    s32 *sp10;
    s32 *sp20;
    s32 *temp_s0;
    s32 *var_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s8 *var_s2;
    var_s1 = (s32 *)(saved_reg_s1);
    if (M2C_FIELD(arg2, s32 *, 0) == 0) {
        CRef_CopyConstruct(arg2);
    } else {
        var_s2 = M2C_FIELD(arg2, s8 **, 4);
        sp0 = NULL;
        if (var_s2 != NULL) {
            do {
                if (M2C_FIELD(var_s2, s32 *, 8) == 0x1F) {
                    sp10 = NULL;
                    if (M2C_FIELD(var_s2, s8 **, 0x10) != NULL) {
                        PpairClone(&sp20, M2C_FIELD(var_s2, s32 **, 0xC), 0, 0);
                        PairHandle_Assign(&sp10, sp20);
                        if (sp20 != NULL) {
                            temp_v0 = *sp20 - 1;
                            *sp20 = temp_v0;
                            if (temp_v0 == 0) {
                                CPairPtr_Destructor(sp20 + 0x10, 2);
                                CRef_Destruct(sp20 + 8);
                                UnlinkPairNode(sp20);
                                FreeSlotheapPv(&B_004520A8, sp20);
                            }
                        }
                    } else {
                        PairHandle_Assign(&sp10, M2C_FIELD(var_s2, s32 **, 0xC));
                    }
                    if (sp0 == NULL) {
                        PairHandle_Assign((s32 **)(sp), PpairNew());
                        bevy_splice_value_list_ref(sp0 + 8, sp10);
                    } else {
                        PairHandle_Assign((s32 **)(var_s1 + 0x10), sp10);
                    }
                    var_s1 = sp10;
                    temp_s0 = var_s1;
                    if (M2C_FIELD(var_s1, s32 *, 0x10) != 0) {
                        do {
                            var_s1 = M2C_FIELD(var_s1, s32 **, 0x10);
                        } while (M2C_FIELD(var_s1, s32 *, 0x10) != 0);
                    }
                    if (temp_s0 != NULL) {
                        temp_v0_2 = M2C_FIELD(temp_s0, s32 *, 0) - 1;
                        M2C_FIELD(temp_s0, s32 *, 0) = temp_v0_2;
                        if (temp_v0_2 == 0) {
                            CPairPtr_Destructor(temp_s0 + 0x10, 2);
                            CRef_Destruct(temp_s0 + 8);
                            UnlinkPairNode(temp_s0);
                            FreeSlotheapPv(&B_004520A8, temp_s0);
                        }
                    }
                }
                var_s2 = M2C_FIELD(var_s2, s8 **, 0x10);
            } while (var_s2 != NULL);
        }
        if (sp0 != NULL) {
            CRef_ConstructPair(arg0, M2C_FIELD(sp0, s32 *, 0xC));
            if (sp0 != NULL) {
                temp_v0_3 = M2C_FIELD(sp0, s32 *, 0) - 1;
                M2C_FIELD(sp0, s32 *, 0) = temp_v0_3;
                if (temp_v0_3 == 0) {
                    CPairPtr_Destructor(sp0 + 0x10, 2);
                    CRef_Destruct(sp0 + 8);
                    UnlinkPairNode(sp0);
                    FreeSlotheapPv(&B_004520A8, sp0);
                }
            }
        } else {
            SetTag__4CRef4TAGK(arg0, 0);
            if (sp0 != NULL) {
                temp_v0_4 = M2C_FIELD(sp0, s32 *, 0) - 1;
                M2C_FIELD(sp0, s32 *, 0) = temp_v0_4;
                if (temp_v0_4 == 0) {
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
