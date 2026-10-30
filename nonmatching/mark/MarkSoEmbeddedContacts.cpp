typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_MarkSoEmbeddedContacts {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x10];
    /* 0x020 */ M2C_UNK sp20;                       /* inferred */
    /* 0x020 */ char pad20[0x10];
    /* 0x030 */ M2C_UNK sp30;                       /* inferred */
    /* 0x030 */ char pad30[0x10];
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0x10];
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x10];
    /* 0x070 */ M2C_UNK sp70;                       /* inferred */
    /* 0x070 */ char pad70[0x10];
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s32 sp90;                           /* inferred */
    /* 0x094 */ s32 sp94;                           /* inferred */
    /* 0x098 */ s32 sp98;                           /* inferred */
    /* 0x09C */ s32 sp9C;                           /* inferred */
    /* 0x0A0 */ s32 spA0;                           /* inferred */
    /* 0x0A4 */ s32 spA4;                           /* inferred */
    /* 0x0A8 */ s8 *spA8;                         /* inferred */
    /* 0x0AC */ char padAC[4];
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 *spD0;                         /* inferred */
    /* 0x0D4 */ s32 spD4;                           /* inferred */
    /* 0x0D8 */ char padD8[0xF8];
};                                                  /* size = 0x1D0 */
#define spB0 (*(s128 *)(sp + 0x0B0))
M2C_UNK PxpAdd(s32, s8 *, s32, s128, s128, M2C_UNK, s32, s8 *, f32, s32); /* extern */
M2C_UNK func_002564B8(...);            /* extern */
M2C_UNK func_002564C0(s128 *);                      /* extern */
void MarkSoEmbeddedContacts(s32 arg0, s8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    f32 saved_reg_f24;
    s8 sp[0x70] __attribute__((aligned(16)));
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_UNK sp30;
    M2C_UNK sp40;
    s128 sp50;
    M2C_UNK sp60;
    M2C_UNK sp70;
    s128 sp80;
    s32 sp90;
    s32 sp94;
    s32 sp98;
    s32 sp9C;
    s32 spA0;
    s32 spA4;
    s8 *spA8;
    s128 spC0;
    s128 *spD0;
    s32 spD4;
    f32 temp_v0_2;
    f32 temp_v0_3;
    f32 temp_v1_2;
    f32 var_f21;
    f32 var_f23;
    f32 var_f24;
    s128 temp_a3;
    s128 temp_s0;
    s32 temp_s4;
    s32 temp_s7;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a1;
    s32 var_v1;
    u16 *temp_a1;
    s8 *temp_s2;
    s8 *temp_s3;
    s8 *temp_v1_3;
    s8 *var_fp;
    s8 *var_s0;
    s8 *var_s0_2;
    s8 *var_s1;
    s8 *var_s1_2;
    var_f24 = saved_reg_f24;
    sp98 = arg3;
    var_a1 = 0;
    sp90 = arg0;
    sp94 = arg2;
    sp9C = arg4;
    spA0 = arg5;
    spA4 = arg6;
    if (arg3 > 0) {
        spA8 = arg1 + 0x90;
        spD0 = &sp50;
        do {
            temp_v0 = var_a1 * 4;
            var_fp = NULL;
            temp_s4 = M2C_FIELD(spA8, s32 *, 4);
            temp_s7 = *(s32 *)(temp_v0 + sp9C);
            temp_s3 = (s8 *)(*(s32 *)(temp_v0 + spA0));
            spD4 = var_a1 + 1;
            var_f23 = -3.4028235e38f;
            var_s0 = temp_s3;
            spC0 = *(s32 *)((temp_s7 * 0x10) + temp_s4);
            if (temp_s3 != NULL) {
                do {
                    temp_s2 = M2C_FIELD(var_s0, s8 **, 0x50);
                    temp_v1 = M2C_FIELD(temp_s2, s32 *, 0x18);
                    asm volatile("lqc2 vf3, (%0)" : : "r"(temp_s2));
                    if (!(temp_v1 & 8)) {
                        M2C_FIELD(temp_s2, s32 *, 0x18) = (s32) (temp_v1 | 8);
                        var_s1 = temp_s3;
                        asm volatile("sqc2 vf3, 0xf0(%0)" : : "r"(sp));
                        func_002564B8(&sp10);
                        func_002564B8(&sp20);
                        asm volatile("lqc2 vf3, 0xf0(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf4, 0xc0(%0)" : : "r"(sp));
                        asm volatile("vmul.xyz vf1, vf3, vf4");
                        asm volatile("vaddw.x vf2, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf1, vf1y");
                        asm volatile("vmaddaz.x ACC, vf2, vf1z");
                        asm volatile("vmsubw.x vf1, vf2, vf3w");
                        s32 vu_1;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                        temp_v0_2 = vu_1;
                        asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
                        var_f21 = temp_v0_2;
                        if (var_s1 != NULL) {
                            var_v1 = M2C_FIELD(var_s1, s32 *, 0x58);
loop_6:
                            temp_a1 = (u16 *)(M2C_FIELD(var_s1, s32 *, 0x54) + ((1 - var_v1) * 2));
                            asm volatile("lqc2 vf1, (%0)" : : "r"((*temp_a1 * 0x10) + temp_s4));
                            asm volatile("sqc2 vf3, 0xf0(%0)" : : "r"(sp));
                            asm volatile("sqc2 vf1, 0xe0(%0)" : : "r"(sp));
                            func_002564B8(&sp30, temp_a1);
                            func_002564B8(&sp40);
                            asm volatile("lqc2 vf1, 0xe0(%0)" : : "r"(sp));
                            asm volatile("lqc2 vf3, 0xf0(%0)" : : "r"(sp));
                            asm volatile("vmul.xyz vf1, vf3, vf1");
                            asm volatile("vaddw.x vf2, vf0, vf0w");
                            asm volatile("vadday.x ACC, vf1, vf1y");
                            asm volatile("vmaddaz.x ACC, vf2, vf1z");
                            asm volatile("vmsubw.x vf1, vf2, vf3w");
                            s32 vu_2;
                            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                            temp_v1_2 = vu_2;
                            asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
                            asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
                            if (temp_v1_2 < var_f21) {
                                var_f21 = temp_v1_2;
                            }
                            var_s1 = M2C_FIELD(var_s1, s8 **, 0x5C);
                            if (var_s1 != NULL) {
                                var_v1 = M2C_FIELD(var_s1, s32 *, 0x58);
                                goto loop_6;
                            }
                        }
                        if (var_f23 < var_f21) {
                            asm volatile("sqc2 vf3, 0xb0(%0)" : : "r"(sp));
                            var_fp = temp_s2;
                            var_f23 = var_f21;
                            var_f24 = temp_v0_2;
                        }
                    }
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0x5C);
                } while (var_s0 != NULL);
            }
            var_s0_2 = temp_s3;
            if (temp_s3 != NULL) {
                do {
                    temp_v1_3 = M2C_FIELD(var_s0_2, s8 **, 0x50);
                    M2C_FIELD(temp_v1_3, s32 *, 0x18) = (s32) (M2C_FIELD(temp_v1_3, s32 *, 0x18) & ~8);
                    var_s0_2 = M2C_FIELD(var_s0_2, s8 **, 0x5C);
                } while (var_s0_2 != NULL);
            }
            var_s1_2 = temp_s3;
            func_002564C0(spD0);
            sp50 = spB0;
            PxpAdd(sp90, arg1, sp94, spC0, spB0, 1, M2C_FIELD(arg1, s32 *, 0x94) + (temp_s7 * 0x10), var_fp, var_f24, spA4);
            var_a1 = spD4;
            if (var_s1_2 != NULL) {
                asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(var_s1_2));
loop_19:
                asm volatile("sqc2 vf1, 0xe0(%0)" : : "r"(sp));
                func_002564B8(&sp60);
                func_002564B8(&sp70);
                asm volatile("lqc2 vf1, 0xe0(%0)" : : "r"(sp));
                asm volatile("lqc2 vf3, 0xb0(%0)" : : "r"(sp));
                asm volatile("vmul.xyz vf1, vf3, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddaz.x ACC, vf2, vf1z");
                asm volatile("vmsubw.x vf1, vf2, vf3w");
                s32 vu_3;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                temp_v0_3 = vu_3;
                asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(sp));
                asm volatile("sqc2 vf1, 0x60(%0)" : : "r"(sp));
                if (temp_v0_3 < var_f24) {
                    temp_s0 = M2C_FIELD(var_s1_2, s128 *, 0x10);
                    func_002564C0(&sp80);
                    s64 vu_4;
                    asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_s0));
                    temp_a3 = vu_4;
                    sp80 = spB0;
                    s64 vu_5;
                    asm volatile("por %0, %1, %2" : "=r"(vu_5) : "r"(0), "r"(spB0));
                    PxpAdd(sp90, arg1, sp94, temp_a3, vu_5, 2, M2C_FIELD(var_s1_2, s32 *, 0x54), var_fp, temp_v0_3, spA4);
                }
                var_s1_2 = M2C_FIELD(var_s1_2, s8 **, 0x5C);
                if (var_s1_2 != NULL) {
                    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(var_s1_2));
                    goto loop_19;
                }
                var_a1 = spD4;
            }
        } while (var_a1 < sp98);
    }
}
}
