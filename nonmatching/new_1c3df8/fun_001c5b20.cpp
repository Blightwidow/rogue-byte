typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C5B20 {
    /* 0x00 */ char pad0[0xD0];
};                                                  /* size = 0xD0 */
s32 CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(M2C_UNK, s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s8 *, f32); /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
extern f32 D_FLT_002C0D7C;
s32 func_001C5B20(s8 *arg0, s8 *arg1) {
    s8 sp[0x50] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_v0;
    s32 var_s3;
    s32 var_s4;
    s64 temp_v1;
    s8 *temp_s0;
    s8 *temp_v0_2;
    if (M2C_FIELD(arg1, s32 *, 0) != 0) {
        if (M2C_FIELD(arg1, s8 **, 0xC) != NULL) {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(arg0)));
            asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(M2C_FIELD(arg1, s8 **, 0xC))));
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            asm volatile("vmul.xyz vf1, vf1, vf1");
            asm volatile("vaddw.x vf2, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf2, vf1z");
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
            temp_v0 = vu_1;
            if (!((D_FLT_002C0D7C * D_FLT_002C0D7C) < temp_v0)) {
                temp_f0 = M2C_FIELD(arg1, f32 *, 8);
                if (!(temp_v0 < (temp_f0 * temp_f0))) {
                    var_s3 = 0;
                    if (M2C_FIELD(M2C_FIELD(arg1, s8 **, 0xC), s32 *, 0xE0) > 0) {
                        var_s4 = 0;
loop_6:
                        temp_s0 = (s8 *)(M2C_FIELD(M2C_FIELD(arg1, s8 **, 0xC), s32 *, 0xE4) + var_s4);
                        temp_v1 = M2C_FIELD(temp_s0, s64 *, 0x10);
                        if (!(temp_v1 & (0x8000 << 0x23))) {
                            if (temp_v1 & (0x8000 << 0x22)) {
                                temp_f20 = M2C_FIELD(arg0, f32 *, 0x1DC) + M2C_FIELD(temp_s0, f32 *, 8);
                                asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(arg0)));
                                asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(M2C_FIELD(temp_s0, s32 *, 0)));
                                asm volatile("vsub.xyzw vf1, vf3, vf2");
                                asm volatile("vmul.xyz vf1, vf1, vf1");
                                asm volatile("vaddw.x vf3, vf0, vf0w");
                                asm volatile("vadday.x ACC, vf1, vf1y");
                                asm volatile("vmaddz.x vf1, vf3, vf1z");
                                s32 vu_2;
                                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                                if (vu_2 < (temp_f20 * temp_f20)) {
                                    goto block_9;
                                }
                                goto block_11;
                            }
                            s64 vu_3;
                            asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(PosLoWorld(arg0)));
                            if (CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(vu_3, temp_s0, 0x7FFFFFFF, 0, 0, 1, sp, M2C_FIELD(arg0, f32 *, 0x1DC)) == 0) {
                                goto block_11;
                            }
                            goto block_9;
                        }
block_11:
                        var_s3 += 1;
                        var_s4 += 0xB0;
                        if (var_s3 >= M2C_FIELD(M2C_FIELD(arg1, s8 **, 0xC), s32 *, 0xE0)) {
                            goto block_12;
                        }
                        goto loop_6;
                    }
                    goto block_12;
                }
block_9:
                temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x260), 1);
                return 1;
            }
            goto block_12;
        }
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 0;
    }
block_12:
    return 0;
}
}
