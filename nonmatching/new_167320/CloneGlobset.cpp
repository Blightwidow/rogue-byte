typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CloneGlobset {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ char pad1C[0xA4];
};                                                  /* size = 0xC0 */
M2C_UNK ClearSle(s8 *);                           /* extern */
M2C_UNK CopyAb__FPvT0Ui(s8 *, s8 *, s32);       /* extern */
M2C_UNK CopyGlobDmaChain(s8 *, s8 *, s32, s8 **); /* extern */
M2C_UNK PrependSlEntry(s8 *, s8 *);             /* extern */
s8 **PvAllocSwCopyImpl__FiPv(...); /* extern */
M2C_UNK func_001EC740(s32, s32, s32, s8 **);      /* extern */
s8 *func_001ED850(s8 *);                        /* extern */
extern s32 B_003DA790;
extern M2C_UNK B_003DA798;
void CloneGlobset(s8 *arg0, s8 *arg1, s32 arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 temp_a2_2;
    s32 temp_s0_2;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 var_a0;
    s32 var_a2;
    s32 var_fp;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s1_2;
    u32 temp_a0_3;
    u32 temp_a1_2;
    u32 temp_s0;
    u32 temp_v0_5;
    u32 var_s1_3;
    s8 **temp_s5;
    s8 **temp_v0_2;
    s8 **temp_v1;
    s8 **var_s6;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_a1;
    s8 *temp_a1_3;
    s8 *temp_a2;
    s8 *temp_a3;
    s8 *temp_s2;
    s8 *temp_s3;
    s8 *temp_t2;
    s8 *temp_v0;
    s8 *temp_v0_3;
    s8 *var_s0_3;
    s8 *var_s2;
    M2C_FIELD(arg0, s8 **, 0) = arg1;
    sp10 = arg2;
    var_a2 = 0;
    M2C_FIELD(arg0, s8 ***, 0x40) = PvAllocSwCopyImpl__FiPv(sp, M2C_FIELD(arg0, s8 ***, 0x40), M2C_FIELD(arg0, s32 *, 0x38) * 0x28, 0x10);
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    if (M2C_FIELD(arg0, s32 *, 0x24) > 0) {
loop_2:
        if (M2C_FIELD(*((var_a2 * 4) + M2C_FIELD(arg0, s8 ***, 0x28)), s32 *, 0x20) & 4) {
            M2C_FIELD(arg0, s8 ***, 0x28) = PvAllocSwCopyImpl__FiPv(sp, M2C_FIELD(arg0, s8 ***, 0x28), var_a2, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x24) * 4, 0x10);
        } else {
            var_a2 += 1;
            if (var_a2 < M2C_FIELD(arg0, s32 *, 0x24)) {
                goto loop_2;
            }
        }
    }
    var_s0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x38) > 0) {
        do {
            temp_t2 = M2C_FIELD(arg1, s8 **, 0xC);
            var_s1 = 0;
            sp18 = var_s0 + 1;
            temp_s3 = (s8 *)(M2C_FIELD(arg0, s8 ***, 0x40) + (var_s0 * 0x28));
            temp_s2 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x3C) + (var_s0 * 0x14));
            M2C_FIELD(temp_t2, M2C_UNK (**)(s8 *, s32, s8 *), 0x1A4)(arg1 + M2C_FIELD(temp_t2, s16 *, 0x1A0), sp10, temp_s3 + 4);
            M2C_FIELD(temp_s3, s8 ***, 0x18) = PvAllocSwCopyImpl__FiPv(sp, M2C_FIELD(temp_s3, s8 ***, 0x18), M2C_FIELD(temp_s2, s8 *, 1) * 0x50, 0x10);
            if (M2C_FIELD(temp_s2, s8 *, 1) > 0) {
                var_s0_2 = 0;
                do {
                    temp_v0 = M2C_FIELD(arg1, s8 **, 0xC);
                    var_s1 += 1;
                    temp_a2 = (s8 *)(M2C_FIELD(temp_s3, s8 ***, 0x18) + var_s0_2 + 0xC);
                    var_s0_2 += 0x50;
                    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s32, s8 *), 0x1A4)(arg1 + M2C_FIELD(temp_v0, s16 *, 0x1A0), sp10, temp_a2);
                } while (var_s1 < M2C_FIELD(temp_s2, s8 *, 1));
            }
            temp_a0 = M2C_FIELD(temp_s3, s8 **, 0x20);
            var_fp = 0;
            if (temp_a0 != NULL) {
                var_fp = (M2C_FIELD(temp_a0, s32 *, 0x20) & 4) != 0;
            }
            if (var_fp != 0) {
                temp_a1 = func_001ED850(temp_a0);
                var_a0 = 0;
                if (M2C_FIELD(arg0, s32 *, 0x24) > 0) {
                    temp_v1 = M2C_FIELD(arg0, s8 ***, 0x28);
                    temp_a3 = M2C_FIELD(temp_s3, s8 **, 0x20);
                    if (*temp_v1 == temp_a3) {
                        *temp_v1 = temp_a1;
                    } else {
loop_19:
                        var_a0 += 1;
                        if (var_a0 < M2C_FIELD(arg0, s32 *, 0x24)) {
                            temp_v0_2 = &temp_v1[var_a0];
                            if (*temp_v0_2 == temp_a3) {
                                *temp_v0_2 = temp_a1;
                            } else {
                                goto loop_19;
                            }
                        }
                    }
                }
                M2C_FIELD(temp_s3, s8 **, 0x20) = temp_a1;
            }
            if ((M2C_FIELD(temp_s2, s32 *, 8) != 0) || (var_fp != 0)) {
                var_s1_2 = 0;
                var_s6 = NULL;
                if (M2C_FIELD(temp_s2, s8 *, 2) & 1) {
                    var_s1_2 = M2C_FIELD(temp_s2, s32 *, 0x10);
                    var_s6 = M2C_FIELD(temp_s3, s8 ***, 0x10);
                    M2C_FIELD(temp_s3, s8 ***, 0x10) = PvAllocSwCopyImpl__FiPv(sp, var_s6, var_s1_2 * 0x10, 0x10);
                } else {
                    temp_v0_3 = M2C_FIELD(temp_s3, s8 **, 0x20);
                    if (temp_v0_3 != NULL) {
                        temp_s5 = M2C_FIELD(temp_v0_3, s8 ***, 0x48);
                        var_s1_2 = M2C_FIELD(temp_v0_3, s32 *, 0x44);
                        var_s6 = temp_s5;
                        if (var_fp != 0) {
                            M2C_FIELD(M2C_FIELD(temp_s3, s8 **, 0x20), s8 ***, 0x48) = PvAllocSwCopyImpl__FiPv(sp, temp_s5, var_s1_2 * 0x10, 0x10);
                        }
                    }
                    CopyGlobDmaChain(temp_s2, temp_s3, M2C_FIELD(temp_s2, s32 *, 0x10), M2C_FIELD(temp_s3, s8 ***, 0x10));
                }
                if (M2C_FIELD(temp_s3, s8 **, 0x20) != NULL) {
                    temp_s0 = M2C_FIELD(temp_s3, u32 *, 0xC);
                    temp_v0_4 = (temp_s0 >> 0xD) & 0x1FF;
                    temp_s0_2 = ((temp_s0 >> 0x16) & 0x1FF) - temp_v0_4;
                    sp14 = var_s1_2 * 0x10;
                    CopyAb__FPvT0Ui((s8 *)(&B_003DA798 + (B_003DA790 * 0x14)), (s8 *)(&B_003DA798 + (temp_v0_4 * 0x14)), temp_s0_2 * 0x14);
                    temp_a2_2 = B_003DA790 + temp_s0_2;
                    temp_a1_2 = (M2C_FIELD(temp_s3, u32 *, 0xC) & 0xFFC01FFF) | ((B_003DA790 & 0x1FF) << 0xD);
                    M2C_FIELD(temp_s3, u32 *, 0xC) = temp_a1_2;
                    temp_v0_5 = (temp_a1_2 & 0x803FFFFF) | ((temp_a2_2 & 0x1FF) << 0x16);
                    B_003DA790 = temp_a2_2;
                    var_s1_3 = (temp_v0_5 >> 0xD) & 0x1FF;
                    M2C_FIELD(temp_s3, u32 *, 0xC) = temp_v0_5;
                    if (var_s1_3 < (u32) ((temp_v0_5 >> 0x16) & 0x1FF)) {
                        temp_v0_6 = var_s1_3 * 0x14;
                        var_s0_3 = (s8 *)(temp_v0_6 + &B_003DA798);
                        var_s2 = (s8 *)(temp_v0_6 + 0x10 + &B_003DA798);
                        do {
                            if (var_fp != 0) {
                                M2C_FIELD(var_s0_3, s8 **, 4) = (s8 *) (M2C_FIELD(temp_s3, s8 **, 0x20) + 0x24);
                                M2C_FIELD(var_s0_3, s8 **, 0xC) = (s8 *) M2C_FIELD(temp_s3, s8 **, 0x20);
                            }
                            var_s1_3 += 1;
                            ClearSle(var_s2);
                            var_s2 += 0x14;
                            temp_a0_2 = M2C_FIELD(var_s0_3, s8 **, 0xC);
                            temp_a1_3 = var_s0_3;
                            var_s0_3 += 0x14;
                            PrependSlEntry(temp_a0_2 + 0x34, temp_a1_3);
                        } while (var_s1_3 < (u32) (((u32) M2C_FIELD(temp_s3, u32 *, 0xC) >> 0x16) & 0x1FF));
                    }
                    temp_a0_3 = M2C_FIELD(temp_s3, u32 *, 0xC);
                    func_001EC740((temp_a0_3 >> 0xD) & 0x1FF, (temp_a0_3 >> 0x16) & 0x1FF, sp14, var_s6);
                }
            }
            var_s0 = sp18;
        } while (var_s0 < M2C_FIELD(arg0, s32 *, 0x38));
    }
}
}
