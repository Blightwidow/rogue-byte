typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GoalPartnerFollow_PloFindEnemy {
    /* 0x00 */ s8 *sp0;                           /* inferred */
    /* 0x04 */ char pad4[0xC];                      /* maybe part of sp0[4]? */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ char pad20[0xB0];
};                                                  /* size = 0xD0 */
s32 FIsGuardInSgs(s8 *, M2C_UNK);                 /* extern */
s32 GrfsgsFromSgs(M2C_UNK);                         /* extern */
s8 *PalertFind(s8 *);                           /* extern */
s128 PosLoWorld(s8 *);                            /* extern */
extern M2C_UNK D_FLT_002BD300;
extern M2C_UNK D_FLT_002BD310;
extern M2C_UNK D_FLT_002BD320;
s8 *GoalPartnerFollow_PloFindEnemy(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 *sp0;
    s128 sp10;
    f32 temp_v1;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f21;
    s32 temp_fp;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 var_s6;
    s32 var_s6_2;
    s8 **var_s2;
    s8 **var_s2_2;
    s8 *temp_s1_2;
    s8 *temp_s1_3;
    s8 *temp_s3_2;
    s8 *temp_v0;
    var_s6 = 0;
    var_f21 = 3.4028235e38f;
    sp0 = NULL;
    PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10));
    sp10 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x30));
    temp_s0 = GrfsgsFromSgs(7);
    temp_s4 = GrfsgsFromSgs(0x10);
    temp_s3 = GrfsgsFromSgs(0x16);
    temp_s2 = GrfsgsFromSgs(0x17);
    temp_s1 = GrfsgsFromSgs(0x2A);
    temp_s3_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s8 **, 0x1088);
    temp_fp = temp_s0 | temp_s4 | temp_s3 | temp_s2 | temp_s1 | GrfsgsFromSgs(0x2B);
    if (M2C_FIELD(temp_s3_2, s32 *, 0x28) > 0) {
        var_s2 = (s8 **)(temp_s3_2 + 0x2C);
        do {
            temp_s1_2 = *var_s2;
            if (!(temp_fp & M2C_FIELD(temp_s1_2, s64 *, 0x2C0))) {
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_s1_2)));
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
                var_f20 = vu_1;
                if ((s32)temp_s1_2 == M2C_FIELD(arg0, s32 *, 0x90)) {
                    var_f20 = M2C_FIELD(&D_FLT_002BD300, f32 *, 0) + (var_f20 * (M2C_FIELD(&D_FLT_002BD300, f32 *, 4) + (var_f20 * M2C_FIELD(&D_FLT_002BD300, f32 *, 8))));
                }
                if (FIsGuardInSgs(temp_s1_2, 3) != 0) {
                    var_f20 = M2C_FIELD(&D_FLT_002BD320, f32 *, 0) + (var_f20 * (M2C_FIELD(&D_FLT_002BD320, f32 *, 4) + (var_f20 * M2C_FIELD(&D_FLT_002BD320, f32 *, 8))));
                }
                if (var_f20 < var_f21) {
                    sp0 = temp_s1_2;
                    var_f21 = var_f20;
                }
            }
            var_s6 += 1;
            var_s2 += 4;
        } while (var_s6 < M2C_FIELD(temp_s3_2, s32 *, 0x28));
    }
    temp_v0 = PalertFind(M2C_FIELD(arg0, s8 **, 0x30));
    var_s6_2 = 0;
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x28) > 0)) {
        var_s2_2 = (s8 **)(temp_v0 + 0x2C);
        do {
            temp_s1_3 = *var_s2_2;
            if (!(temp_fp & M2C_FIELD(temp_s1_3, s64 *, 0x2C0))) {
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_s1_3)));
                asm volatile("vsub.xyzw vf1, vf2, vf3");
                asm volatile("vmul.xyz vf1, vf1, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                temp_v1 = vu_2;
                var_f20_2 = M2C_FIELD(&D_FLT_002BD310, f32 *, 0) + (temp_v1 * (M2C_FIELD(&D_FLT_002BD310, f32 *, 4) + (temp_v1 * M2C_FIELD(&D_FLT_002BD310, f32 *, 8))));
                if ((s32)temp_s1_3 == M2C_FIELD(arg0, s32 *, 0x90)) {
                    var_f20_2 = M2C_FIELD(&D_FLT_002BD300, f32 *, 0) + (var_f20_2 * (M2C_FIELD(&D_FLT_002BD300, f32 *, 4) + (var_f20_2 * M2C_FIELD(&D_FLT_002BD300, f32 *, 8))));
                }
                if (FIsGuardInSgs(temp_s1_3, 3) != 0) {
                    var_f20_2 = M2C_FIELD(&D_FLT_002BD320, f32 *, 0) + (var_f20_2 * (M2C_FIELD(&D_FLT_002BD320, f32 *, 4) + (var_f20_2 * M2C_FIELD(&D_FLT_002BD320, f32 *, 8))));
                }
                if (var_f20_2 < var_f21) {
                    sp0 = temp_s1_3;
                    var_f21 = var_f20_2;
                }
            }
            var_s6_2 += 1;
            var_s2_2 += 4;
        } while (var_s6_2 < M2C_FIELD(temp_v0, s32 *, 0x28));
    }
    return sp0;
}
}
