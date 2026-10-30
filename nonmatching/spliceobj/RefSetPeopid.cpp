typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefSetPeopid {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s32 sp10;                           /* inferred */
    /* 0x014 */ s128 *sp14;                         /* inferred */
    /* 0x018 */ char pad18[8];                      /* maybe part of sp14[3]? */
    /* 0x020 */ s32 sp20;                           /* inferred */
    /* 0x024 */ char pad24[0xC];                    /* maybe part of sp20[4]? */
    /* 0x030 */ s32 sp30;                           /* inferred */
    /* 0x034 */ char pad34[0xC];                    /* maybe part of sp30[4]? */
    /* 0x040 */ s32 sp40;                           /* inferred */
    /* 0x044 */ s32 sp44;                           /* inferred */
    /* 0x048 */ s64 sp48;                           /* inferred */
    /* 0x050 */ s64 sp50;                           /* inferred */
    /* 0x058 */ s64 sp58;                           /* inferred */
    /* 0x060 */ s64 sp60;                           /* inferred */
    /* 0x068 */ s64 sp68;                           /* inferred */
    /* 0x070 */ s64 sp70;                           /* inferred */
    /* 0x078 */ char pad78[0xB8];
};                                                  /* size = 0x130 */
#define sp14 (*(s128 * *)(sp + 0x014))
s32 CRef_CopyConstruct(s32, s32 *);
void CRef_Destruct(...);
s32 CRef_RefCoerceF32(s32 *, s8 *);
s32 CRef_RefCoerceS32(s32 *, s8 *);
void RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(s32 *, M2C_UNK, s8 *, s8 *);
void SetTag__4CRef4TAGK(s32 *, M2C_UNK);
void __as__4CRefRC4CRef(s32 *, s32 *);
#define sp10 (*(s32 *)(sp + 0x10))
#define sp20 (*(s32 *)(sp + 0x20))
#define sp30 (*(s32 *)(sp + 0x30))
#define sp40 (*(s32 *)(sp + 0x40))
#define sp44 (*(s32 *)(sp + 0x44))
#define sp48 (*(s64 *)(sp + 0x48))
#define sp50 (*(s64 *)(sp + 0x50))
#define sp58 (*(s64 *)(sp + 0x58))
#define sp60 (*(s64 *)(sp + 0x60))
#define sp68 (*(s64 *)(sp + 0x68))
#define sp70 (*(s64 *)(sp + 0x70))
s32 RefSetPeopid(s32 arg0, s32 arg1, s8 *arg2, s8 *arg3) {
    s8 sp[0x80] __attribute__((aligned(16)));
    s128 *var_f20;
    s128 *var_s0_2;
    s16 temp_a1;
    s16 temp_a1_10;
    s16 temp_a1_11;
    s16 temp_a1_12;
    s16 temp_a1_2;
    s16 temp_a1_3;
    s16 temp_a1_4;
    s16 temp_a1_5;
    s16 temp_a1_6;
    s16 temp_a1_7;
    s16 temp_a1_8;
    s16 temp_a1_9;
    s16 temp_a2;
    s16 temp_a2_2;
    s16 temp_a2_3;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s16 var_a2_3;
    s16 var_v0;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_v0_4;
    s16 var_v0_5;
    s16 var_v0_6;
    s16 var_v0_7;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s3;
    s64 temp_v1_4;
    s64 temp_v1_5;
    s64 temp_v1_6;
    s64 temp_v1_7;
    s64 temp_v1_8;
    s64 temp_v1_9;
    s64 var_a0;
    s64 var_a2;
    s64 var_a2_2;
    s64 var_fp;
    s64 var_s0;
    s64 var_s4;
    s64 var_s5;
    s64 var_s6;
    s64 var_s7;
    s64 var_v1;
    s64 var_v1_2;
    s64 var_v1_3;
    s64 var_v1_4;
    s64 var_v1_5;
    u32 temp_v0_2;
    sp44 = arg0;
    var_s3 = arg1;
    CRef_Destruct((s32 *)(sp), -1);
    SetTag__4CRef4TAGK((s32 *)(sp), 0x24);
    temp_v1 = M2C_FIELD(arg2, s32 *, 4);
    temp_v0 = temp_v1 & 0x2000;
    if (temp_v1 & 0x10) {
        if (temp_v0 != 0) {
            temp_a1 = M2C_FIELD(arg2, s16 *, 0x22);
            if (temp_a1 >= 0) {
                var_s0 = M2C_FIELD(((temp_a1 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x24))), s64 *, -8);
                var_a2 = var_s0 >> 0x20;
            } else {
                var_a2 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x24);
            }
            temp_v1_2 = M2C_FIELD(arg2, s16 *, 0x20);
            if (temp_a1 >= 0) {
                var_v0 = (s16) (var_s0 & 0xFFFF) + temp_v1_2;
            } else {
                var_v0 = temp_v1_2;
            }
            var_s3 = ((s32 (*)(s32, M2C_UNK, s64)) var_a2)(var_s3 + var_v0, 1, var_a2);
        }
        sp40 = var_s3 + M2C_FIELD(arg2, s32 *, 0x10);
        RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(&sp10, 1, arg3, arg2);
        __as__4CRefRC4CRef((s32 *)(sp), &sp10);
        CRef_Destruct(&sp10);
    } else {
        if (temp_v0 != 0) {
            temp_a1_2 = M2C_FIELD(arg2, s16 *, 0x22);
            if (temp_a1_2 >= 0) {
                var_s4 = M2C_FIELD(((temp_a1_2 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x24))), s64 *, -8);
                var_a2_2 = var_s4 >> 0x20;
            } else {
                var_a2_2 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x24);
            }
            temp_v1_3 = M2C_FIELD(arg2, s16 *, 0x20);
            if (temp_a1_2 >= 0) {
                var_v0_2 = (s16) (var_s4 & 0xFFFF) + temp_v1_3;
            } else {
                var_v0_2 = temp_v1_3;
            }
            var_s3 = ((s32 (*)(s32, M2C_UNK, s64)) var_a2_2)(var_s3 + var_v0_2, 1, var_a2_2);
        }
        temp_v0_2 = M2C_FIELD(arg2, u32 *, 0);
        switch (temp_v0_2) {
        case 5:
        case 6:
        case 7:
        case 8:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 19:
        case 20:
        case 23:
            if (M2C_FIELD(arg3, s32 *, 0) == 0x15) {
                var_s0_2 = M2C_FIELD(arg3, s128 **, 4);
            } else {
                sp10 = -1;
                CRef_RefCoerceS32(&sp20, arg3);
                __as__4CRefRC4CRef(&sp10, &sp20);
                CRef_Destruct(&sp20);
                var_s0_2 = sp14;
                CRef_Destruct(&sp10);
            }
            temp_a1_3 = M2C_FIELD(arg2, s16 *, 0x12);
            if (temp_a1_3 >= 0) {
                temp_v1_4 = M2C_FIELD(((temp_a1_3 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x14))), s64 *, -8);
                sp48 = temp_v1_4;
                var_v1 = temp_v1_4 >> 0x20;
            } else {
                var_v1 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x14);
            }
            temp_a2 = (s16) M2C_FIELD(arg2, s32 *, 0x10);
            if (temp_a1_3 < 0) {
                var_v0_3 = temp_a2;
            } else {
                var_v0_3 = (s16) (sp48 & 0xFFFF) + temp_a2;
            }
            ((M2C_UNK (*)(s32, s128 *, s16)) var_v1)(var_s3 + var_v0_3, var_s0_2, temp_a2);
            break;
        case 1:
            if (M2C_FIELD(arg3, s32 *, 0) == 0x16) {
                var_f20 = M2C_FIELD(arg3, s128 **, 4);
            } else {
                sp10 = -1;
                CRef_RefCoerceF32(&sp30, arg3);
                __as__4CRefRC4CRef(&sp10, &sp30);
                CRef_Destruct(&sp30);
                var_f20 = sp14;
                CRef_Destruct(&sp10);
            }
            temp_a1_4 = M2C_FIELD(arg2, s16 *, 0x12);
            if (temp_a1_4 >= 0) {
                temp_v1_5 = M2C_FIELD(((temp_a1_4 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x14))), s64 *, -8);
                sp50 = temp_v1_5;
                var_v1_2 = temp_v1_5 >> 0x20;
            } else {
                var_v1_2 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x14);
            }
            temp_a2_2 = (s16) M2C_FIELD(arg2, s32 *, 0x10);
            if (temp_a1_4 < 0) {
                var_v0_4 = temp_a2_2;
            } else {
                var_v0_4 = (s16) (sp50 & 0xFFFF) + temp_a2_2;
            }
            ((M2C_UNK (*)(s32, s16, s16, s128 *)) var_v1_2)(var_s3 + var_v0_4, temp_a1_4, temp_a2_2, var_f20);
            break;
        case 0:
            temp_a1_5 = M2C_FIELD(arg2, s16 *, 0x12);
            if (temp_a1_5 >= 0) {
                var_s5 = M2C_FIELD(((temp_a1_5 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x14))), s64 *, -8);
                var_v1_3 = var_s5 >> 0x20;
            } else {
                var_v1_3 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x14);
            }
            var_v0_5 = var_s5 & 0xFFFF;
            if (temp_a1_5 >= 0) {
block_80:
                var_v0_6 = var_v0_5 + (s16) M2C_FIELD(arg2, s32 *, 0x10);
            } else {
block_81:
                var_v0_6 = (s16) M2C_FIELD(arg2, s32 *, 0x10);
            }
block_82:
            ((M2C_UNK (*)(s32, s128 *, s16)) var_v1_3)(var_s3 + var_v0_6, M2C_FIELD(arg3, s128 **, 4), (s16) M2C_FIELD(arg2, s32 *, 0x10));
            break;
        case 2:
            temp_a1_6 = M2C_FIELD(arg2, s16 *, 0x12);
            if (temp_a1_6 >= 0) {
                var_s6 = M2C_FIELD(((temp_a1_6 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x14))), s64 *, -8);
                var_v1_4 = var_s6 >> 0x20;
            } else {
                var_v1_4 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x14);
            }
            var_a2_3 = (s16) M2C_FIELD(arg2, s32 *, 0x10);
            if (temp_a1_6 >= 0) {
                var_a2_3 += (s16) (var_s6 & 0xFFFF);
            }
            ((M2C_UNK (*)(s32, s128, s16)) var_v1_4)(var_s3 + var_a2_3, *M2C_FIELD(arg3, s128 **, 4), var_a2_3);
            break;
        case 4:
            temp_a1_7 = M2C_FIELD(arg2, s16 *, 0x12);
            if (temp_a1_7 >= 0) {
                var_s7 = M2C_FIELD(((temp_a1_7 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x14))), s64 *, -8);
                var_v1_3 = var_s7 >> 0x20;
            } else {
                var_v1_3 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x14);
            }
            var_v0_5 = var_s7 & 0xFFFF;
            if (temp_a1_7 >= 0) {
                goto block_80;
            }
            goto block_81;
            goto block_82;
        case 9:
            temp_a1_8 = M2C_FIELD(arg2, s16 *, 0x12);
            if (temp_a1_8 >= 0) {
                var_fp = M2C_FIELD(((temp_a1_8 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x14))), s64 *, -8);
                var_v1_3 = var_fp >> 0x20;
            } else {
                var_v1_3 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x14);
            }
            var_v0_5 = var_fp & 0xFFFF;
            if (temp_a1_8 >= 0) {
                goto block_80;
            }
            goto block_81;
            goto block_82;
        case 10:
            temp_a1_9 = M2C_FIELD(arg2, s16 *, 0x12);
            if (temp_a1_9 >= 0) {
                temp_v1_6 = M2C_FIELD(((temp_a1_9 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x14))), s64 *, -8);
                sp58 = temp_v1_6;
                var_v1_3 = temp_v1_6 >> 0x20;
            } else {
                var_v1_3 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x14);
            }
            if (temp_a1_9 >= 0) {
                var_a0 = sp58;
block_79:
                var_v0_5 = var_a0 & 0xFFFF;
                goto block_80;
            }
            goto block_81;
            goto block_82;
        case 11:
            temp_a1_10 = M2C_FIELD(arg2, s16 *, 0x12);
            if (temp_a1_10 >= 0) {
                temp_v1_7 = M2C_FIELD(((temp_a1_10 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x14))), s64 *, -8);
                sp60 = temp_v1_7;
                var_v1_3 = temp_v1_7 >> 0x20;
            } else {
                var_v1_3 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x14);
            }
            if (temp_a1_10 >= 0) {
                var_a0 = sp60;
                goto block_79;
            }
            goto block_81;
            goto block_82;
        default:
            if (temp_v0_2 & 0x1000) {
                temp_a1_11 = M2C_FIELD(arg2, s16 *, 0x12);
                if (temp_a1_11 >= 0) {
                    temp_v1_8 = M2C_FIELD(((temp_a1_11 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x14))), s64 *, -8);
                    sp68 = temp_v1_8;
                    var_v1_3 = temp_v1_8 >> 0x20;
                } else {
                    var_v1_3 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x14);
                }
                if (temp_a1_11 >= 0) {
                    var_a0 = sp68;
                    goto block_79;
                }
                goto block_81;
                goto block_82;
            }
            if (temp_v0_2 & 0x2000) {
                temp_a1_12 = M2C_FIELD(arg2, s16 *, 0x12);
                if (temp_a1_12 >= 0) {
                    temp_v1_9 = M2C_FIELD(((temp_a1_12 * 8) + *(s32 *)(var_s3 + M2C_FIELD(arg2, s16 *, 0x14))), s64 *, -8);
                    sp70 = temp_v1_9;
                    var_v1_5 = temp_v1_9 >> 0x20;
                } else {
                    var_v1_5 = (s64) (s32) M2C_FIELD(arg2, s16 *, 0x14);
                }
                temp_a2_3 = (s16) M2C_FIELD(arg2, s32 *, 0x10);
                if (temp_a1_12 < 0) {
                    var_v0_7 = temp_a2_3;
                } else {
                    var_v0_7 = (s16) (sp70 & 0xFFFF) + temp_a2_3;
                }
                ((M2C_UNK (*)(s32, s128 *, s16)) var_v1_5)(var_s3 + var_v0_7, M2C_FIELD(arg3, s128 **, 4), temp_a2_3);
            }
            break;
        }
    }
    CRef_CopyConstruct(sp44, (s32 *)sp);
    CRef_Destruct(sp);
    return sp44;
}
}
