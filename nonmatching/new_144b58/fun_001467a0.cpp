typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001467A0 {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
s32 FIsLoInWorld(s8 *);                           /* extern */
f32 GRandInRange(M2C_UNK, M2C_UNK);                 /* extern */
s32 PmatLoWorld(s8 *);                            /* extern */
s128 PosLoWorld(...);                      /* extern */
M2C_UNK func_00146E18(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_001EEF98();                            /* extern */
extern f32 D_FLT_002BD360;
extern f32 D_FLT_002BD368;
extern f32 D_FLT_002BD36C;
extern f32 D_FLT_002BD370;
extern f32 g_2dded0;
void func_001467A0(s8 *arg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    f32 temp_f20;
    s32 temp_v1;
    u32 temp_s1;
    s8 *temp_a0;
    s8 *temp_a0_2;
    func_001EEF98();
    if (M2C_FIELD(arg0, u32 *, 0x30) != -1U) {
        if ((M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xDF4) == -1) && (FIsLoInWorld(M2C_FIELD(arg0, s8 **, 0x38)) != 0)) {
            temp_a0 = M2C_FIELD(arg0, s8 **, 0x38);
            if (M2C_FIELD(temp_a0, s32 *, 0x330) != 0) {
                goto block_5;
            }
            asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10), PosLoWorld(temp_a0))));
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf1, vf2, vf3");
            asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
            asm volatile("vmul.xyz vf1, vf3, vf3");
            asm volatile("vaddw.x vf2, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf2, vf1z");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf2, vf0, Q");
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
            if (vu_1 < 0.0001f) {
            } else {
                asm volatile("vdiv Q, vf0w, vf2x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf1, vf3, Q");
                asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
            }
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
            temp_f20 = vu_2;
            do {
                temp_s1 = M2C_FIELD(arg0, u32 *, 0x30);
                switch (temp_s1) {
                case 0:
                    if (temp_f20 < D_FLT_002BD360) {
                        asm volatile("lqc2 vf2, (%0)" : : "r"(PmatLoWorld(M2C_FIELD(arg0, s8 **, 0x10))));
                        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                        asm volatile("vmul.xyz vf2, vf2, vf1");
                        asm volatile("vaddw.x vf3, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf2, vf2y");
                        asm volatile("vmaddz.x vf2, vf3, vf2z");
                        s32 vu_3;
                        asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
                        if (vu_3 > 0.8f) {
                            if (GRandInRange(0, 0x3F800000) < 0.3f) {
                                func_00146E18(arg0, 3);
                            } else {
                                func_00146E18(arg0, 2);
                            }
                        }
                    } else if (D_FLT_002BD36C < temp_f20) {
                        func_00146E18(arg0, 1);
                    }
                    break;
                case 1:
                    if (temp_f20 < D_FLT_002BD368) {
                        func_00146E18(arg0, 0);
                    }
                    break;
                case 2:
                    if ((M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0x18D8) == -1) && ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x34)) > 0.1f)) {
block_30:
                        func_00146E18(arg0, -1);
                    }
                    break;
                case 3:
                    if ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x34)) > 0.1f) {
                        temp_a0_2 = M2C_FIELD(arg0, s8 **, 0x10);
                        temp_v1 = M2C_FIELD(temp_a0_2, s32 *, 0x2DC);
                        if (temp_v1 != -1) {
                            if ((temp_v1 == 1) && (D_FLT_002BD370 < (g_2dded0 - M2C_FIELD(temp_a0_2, f32 *, 0x2E0)))) {
                                func_00146E18(arg0, 4);
                            }
                        } else {
                            goto block_30;
                        }
                    }
                    break;
                case 4:
                    if (((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x34)) > 0.1f) && (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0x18C8) != 0xD)) {
                        func_00146E18(arg0, -1);
                    }
                    break;
                }
            } while (M2C_FIELD(arg0, u32 *, 0x30) != temp_s1);
        } else {
block_5:
            func_00146E18(arg0, -1);
        }
    }
}
}
