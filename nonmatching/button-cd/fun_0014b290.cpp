typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0014B290 {
    /* 0x00 */ char pad0[0xC0];
};                                                  /* size = 0xC0 */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
s32 FIsGuardInSgs(M2C_UNK);                         /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
s8 *func_002082D0(s8 *);                        /* extern */
extern M2C_UNK g_2bd4b0;
s8 *func_0014B290(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 var_f20;
    f32 var_f3;
    s32 var_s1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s8 *temp_a0;
    s8 *temp_s0;
    s8 *temp_v1;
    s8 *var_fp;
    if (FIsGuardInSgs(0x24) == 0) {
        temp_v1 = M2C_FIELD(arg0, s8 **, 0x390);
        var_fp = NULL;
        if (temp_v1 != NULL) {
            if ((int)((u64) M2C_FIELD(temp_v1, u64 *, 0x28) >> 0x3C) & 1) {
                var_fp = temp_v1;
            } else {
                goto block_8;
            }
        } else {
block_8:
            var_f20 = 3.4028235e38f;
            var_s5 = 0x3E7;
            PosLoWorld(arg0);
            var_s3 = 0;
            if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xF64), s32 *, 0xFC) > 0) {
                var_s4 = 0x100;
                do {
                    temp_s0 = M2C_FIELD(arg0, s8 **, 0xF64) + var_s4;
                    if (M2C_FIELD(temp_s0, s32 *, 4) != 0) {
                        var_s1 = 0;
                        if (FIsBasicDerivedFrom(M2C_FIELD(temp_s0, s8 **, 0), 0x34) == 0) {
                            var_s1 = (FIsBasicDerivedFrom(M2C_FIELD(temp_s0, s8 **, 0), 0x3A) != 0) ? 1 : 2;
                        }
                        asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                        asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(M2C_FIELD(temp_s0, s8 **, 0))));
                        temp_a0 = M2C_FIELD(temp_s0, s8 **, 0);
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
                        var_f3 = vu_1;
                        if ((s32)temp_a0 == M2C_FIELD(arg0, s32 *, 0x38C)) {
                            var_f3 = M2C_FIELD(&g_2bd4b0, f32 *, 0) + (var_f3 * (M2C_FIELD(&g_2bd4b0, f32 *, 4) + (var_f3 * M2C_FIELD(&g_2bd4b0, f32 *, 8))));
                        }
                        if ((var_s1 < var_s5) || ((var_s1 == var_s5) && (var_f3 < var_f20))) {
                            var_s5 = var_s1;
                            var_f20 = var_f3;
                            var_fp = temp_a0;
                        }
                    }
                    var_s3 += 1;
                    var_s4 += 0x10;
                } while (var_s3 < M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xF64), s32 *, 0xFC));
            }
        }
        return var_fp;
    }
    return func_002082D0(arg0);
}
}
