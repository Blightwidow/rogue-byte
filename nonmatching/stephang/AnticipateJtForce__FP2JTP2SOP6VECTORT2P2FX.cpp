typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AnticipateJtForce__FP2JTP2SOP6VECTORT2P2FX {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0x50];
    /* 0x090 */ M2C_UNK sp90;                       /* inferred */
    /* 0x090 */ char pad90[0x70];
    /* 0x100 */ M2C_UNK sp100;                      /* inferred */
    /* 0x100 */ char pad100[0x20];
    /* 0x120 */ M2C_UNK sp120;                      /* inferred */
    /* 0x120 */ char pad120[0x30];
    /* 0x150 */ M2C_UNK sp150;                      /* inferred */
    /* 0x150 */ char pad150[0x30];
    /* 0x180 */ M2C_UNK sp180;                      /* inferred */
    /* 0x180 */ char pad180[0x30];
    /* 0x1B0 */ M2C_UNK sp1B0;                      /* inferred */
    /* 0x1B0 */ char pad1B0[0x10];
    /* 0x1C0 */ s32 sp1C0;                          /* inferred */
    /* 0x1C4 */ s32 sp1C4;                          /* inferred */
    /* 0x1C8 */ s32 sp1C8;                          /* inferred */
    /* 0x1CC */ char pad1CC[0x14];                  /* maybe part of sp1C8[6]? */
    /* 0x1E0 */ s128 *sp1E0;                        /* inferred */
    /* 0x1E4 */ s32 sp1E4;                          /* inferred */
    /* 0x1E8 */ s32 sp1E8;                          /* inferred */
    /* 0x1EC */ M2C_UNK *sp1EC;                     /* inferred */
    /* 0x1F0 */ M2C_UNK *sp1F0;                     /* inferred */
    /* 0x1F4 */ M2C_UNK *sp1F4;                     /* inferred */
    /* 0x1F8 */ s32 *sp1F8;                         /* inferred */
    /* 0x1FC */ M2C_UNK *sp1FC;                     /* inferred */
    /* 0x200 */ M2C_UNK *sp200;                     /* inferred */
    /* 0x204 */ M2C_UNK *sp204;                     /* inferred */
    /* 0x208 */ M2C_UNK *sp208;                     /* inferred */
    /* 0x20C */ s32 sp20C;                          /* inferred */
    /* 0x210 */ char pad210[0xA0];
};                                                  /* size = 0x2B0 */
#define sp30 (*(s128 *)(sp + 0x030))
#define sp1C4 (*(s32 *)(sp + 0x1C4))
#define sp1C8 (*(s32 *)(sp + 0x1C8))
M2C_UNK CroutDecomp__FiPfT1(M2C_UNK, M2C_UNK *, M2C_UNK *, s32, M2C_UNK *, M2C_UNK, M2C_UNK *, s32); /* extern */
M2C_UNK CroutSolve__FiPfN21(M2C_UNK, M2C_UNK *, M2C_UNK *, s32 *); /* extern */
s128 DvFromImpulse(s32, s128);                      /* extern */
s128 DwFromImpulseAtPos(s32, s128, s128);           /* extern */
s128 PosLoWorld(s8 *, s32);                       /* extern */
extern M2C_UNK RO_002A2D00;
void AnticipateJtForce__FP2JTP2SOP6VECTORT2P2FX(s8 *arg0, s32 arg1, s128 *arg2, s32 arg3, s32 arg4) {
    s8 sp[0x2B0] __attribute__((aligned(16)));
    s128 sp10;
    s128 sp20;
    M2C_UNK sp40;
    M2C_UNK sp90;
    M2C_UNK sp100;
    M2C_UNK sp120;
    M2C_UNK sp150;
    M2C_UNK sp180;
    M2C_UNK sp1B0;
    s32 sp1C0;
    s128 *sp1E0;
    s32 sp1E4;
    s32 sp1E8;
    M2C_UNK *sp1EC;
    M2C_UNK *sp1F0;
    M2C_UNK *sp1F4;
    s32 *sp1F8;
    M2C_UNK *sp1FC;
    M2C_UNK *sp200;
    M2C_UNK *sp204;
    M2C_UNK *sp208;
    s32 sp20C;
    M2C_UNK *temp_a3;
    M2C_UNK *var_s5;
    M2C_UNK *var_v0;
    M2C_UNK *var_v1;
    s128 *var_s4;
    s128 temp_a1;
    s128 temp_v0;
    s32 *var_a0;
    s32 *var_s3;
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_a3_2;
    s32 temp_a7;
    s32 temp_s0;
    s32 var_a1;
    s32 var_a4;
    s32 var_s6;
    s32 var_s6_2;
    s32 var_s7;
    s32 var_s7_2;
    s8 *temp_a1_2;
    s8 *temp_v0_2;
    s8 *var_s1;
    s8 *var_s2;
    sp1E0 = arg2;
    var_s7 = 0;
    sp1E4 = arg3;
    sp1E8 = arg4;
    temp_v0 = PosLoWorld(arg0, arg1);
    sp1F0 = &sp100;
    sp200 = &sp150;
    sp1FC = &sp40;
    sp1EC = &sp180;
    sp1F8 = &sp1C0;
    sp1F4 = &sp1B0;
    sp10 = temp_v0;
    sp20 = *sp1E0;
    sp208 = &RO_002A2D00;
    sp204 = &sp120;
    sp20C = 0;
    do {
        var_s6 = 0;
        var_s4 = &sp10;
        var_s5 = sp1F0;
        var_s1 = sp + (sp20C + 0x50);
        var_s3 = (s32 *)(sp);
        var_s2 = (s8 *)(sp1FC + sp20C);
loop_2:
        temp_s0 = *var_s3;
        asm volatile("lqc2 vf2, (%0)" : : "r"(sp208));
        asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
        if (var_s6 == 1) {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
            asm volatile("vmulx.xyzw vf2, vf2, vf1x");
            asm volatile("sqc2 vf1, 0x1d0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
        }
        temp_a0 = temp_s0;
        var_s6 += 1;
        var_s3 += 4;
        M2C_FIELD(var_s1, s128 *, -0x10) = DvFromImpulse(temp_a0, sp30);
        temp_a1 = *var_s4;
        var_s4 += 0x10;
        M2C_FIELD(var_s1, s128 *, 0) = DwFromImpulseAtPos(temp_s0, temp_a1, sp30);
        temp_a1_2 = var_s2;
        temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
        temp_a3 = var_s5;
        var_s5 += 0x10;
        var_s2 += 0x60;
        var_s1 += 0x60;
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *, s128, M2C_UNK *), 0x22C)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x228), temp_a1_2, *sp1E0, temp_a3);
        if (var_s6 < 2) {
            goto loop_2;
        }
        var_s7 += 1;
        asm volatile("lqc2 vf1, 0x100(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x110(%0)" : : "r"(sp));
        sp20C += 0x20;
        asm volatile("vsub.xyzw vf1, vf1, vf2");
        sp208 += 0x10;
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp204));
        sp204 += 0x10;
    } while (var_s7 < 3);
    var_s7_2 = 0;
    do {
        temp_a3_2 = var_s7_2 + 1;
        temp_a2 = var_s7_2 * 4;
        var_v1 = &RO_002A2D00;
        var_a1 = 2;
        var_a0 = (var_s7_2 * 0xC) + sp200;
loop_8:
        asm volatile("lqc2 vf1, (%0)" : : "r"(var_v1));
        var_a1 -= 1;
        asm volatile("lqc2 vf2, (%0)" : : "r"((var_s7_2 * 0x10) + sp + 0x120));
        var_v1 += 0x10;
        asm volatile("vmul.xyz vf1, vf1, vf2");
        asm volatile("vaddw.x vf3, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf3, vf1z");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        temp_a7 = vu_1;
        *var_a0 = temp_a7;
        var_a0 += 4;
        if (var_a1 >= 0) {
            goto loop_8;
        }
        var_s7_2 = temp_a3_2;
        *(sp1F4 + temp_a2) = *(s32 *)(sp1E4 + temp_a2);
    } while (var_s7_2 < 3);
    var_s6_2 = 1;
    CroutDecomp__FiPfT1(3, sp200, sp1EC, temp_a3_2, sp1F4, 0xC, &RO_002A2D00, temp_a7);
    CroutSolve__FiPfN21(3, sp1EC, sp1F4, sp1F8);
    asm volatile("qmtc2.ni %0, vf4" : : "r"(sp1C8));
    asm volatile("qmtc2.ni %0, vf6" : : "r"(sp1C0));
    var_a4 = sp1E8;
    asm volatile("qmtc2.ni %0, vf5" : : "r"(sp1C4));
    var_v0 = &sp90;
    do {
        asm volatile("sqc2 vf6, 0x1d0(%0)" : : "r"(sp));
        var_s6_2 -= 1;
        asm volatile("lqc2 vf2, -0x50(%0)" : : "r"(var_v0));
        asm volatile("sqc2 vf5, 0x1d0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, -0x30(%0)" : : "r"(var_v0));
        asm volatile("sqc2 vf4, 0x1d0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, -0x10(%0)" : : "r"(var_v0));
        asm volatile("sqc2 vf6, 0x1d0(%0)" : : "r"(sp));
        asm volatile("vmulax.xyzw ACC, vf2, vf6x");
        asm volatile("vmaddax.xyzw ACC, vf3, vf5x");
        asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
        asm volatile("sqc2 vf2, (%0)" : : "r"(var_a4));
        asm volatile("lqc2 vf3, -0x40(%0)" : : "r"(var_v0));
        asm volatile("sqc2 vf5, 0x1d0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, -0x20(%0)" : : "r"(var_v0));
        asm volatile("sqc2 vf4, 0x1d0(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, (%0)" : : "r"(var_v0));
        asm volatile("vmulax.xyzw ACC, vf3, vf6x");
        asm volatile("vmaddax.xyzw ACC, vf2, vf5x");
        asm volatile("vmaddx.xyzw vf3, vf1, vf4x");
        var_v0 += 0x60;
        asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(var_a4));
        var_a4 += 0x20;
    } while (var_s6_2 >= 0);
}
}
