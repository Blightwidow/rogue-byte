typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Swarm_Render {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ char pad40[0xC];
    /* 0x04C */ s32 sp4C;                           /* inferred */
    /* 0x050 */ char pad50[0xC];                    /* maybe part of sp4C[4]? */
    /* 0x05C */ s32 sp5C;                           /* inferred */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x10];
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ M2C_UNK spA0;                       /* inferred */
    /* 0x0A0 */ char padA0[0xE0];
};                                                  /* size = 0x180 */
#define sp80 (*(s128 *)(sp + 0x080))
#define sp90 (*(s128 *)(sp + 0x090))
M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, s128, s128); /* extern */
M2C_UNK LoadRotateMatrixRad(M2C_UNK *, s128, f32);  /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_001A5EE8(s32, s128 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001F3C70();                            /* extern */
extern s128 g_2a2dc0;
void Swarm_Render(s8 *arg0) {
    s32 unksp3C;
    s8 sp[0xa0] __attribute__((aligned(16)));
    s128 sp0;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s32 sp4C;
    s32 sp5C;
    M2C_UNK sp60;
    s128 sp70;
    M2C_UNK spA0;
    f32 temp_f12;
    f32 temp_f1;
    s32 var_v1;
    s8 *var_s0;
    func_001F3C70();
    if (M2C_FIELD(arg0, s32 *, 0x1C4) != 0) {
        var_v1 = 0;
        if (M2C_FIELD(arg0, s32 *, 0x1C8) > 0) {
            do {
                var_s0 = M2C_FIELD(((var_v1 * 0x30) + arg0), s8 **, 0x1DC);
                if (var_s0 != NULL) {
                    asm volatile("lqc2 vf7, (%0)" : : "r"(var_s0));
loop_5:
                    asm volatile("sqc2 vf7, 0x100(%0)" : : "r"(sp));
                    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp70, M2C_FIELD(var_s0, s128 *, 0x10), g_2a2dc0);
                    sp0 = sp70;
                    sp10 = sp80;
                    sp20 = sp90;
                    temp_f1 = M2C_FIELD(var_s0, f32 *, 0x50);
                    asm volatile("lqc2 vf7, 0x100(%0)" : : "r"(sp));
                    if (fabsf(temp_f1) > 1.0f) {
                        asm volatile("qmtc2.ni %0, vf3" : : "r"(temp_f1));
                        asm volatile("lqc2 vf2, (%0)" : : "r"(&g_2a2dc0));
                        asm volatile("sqc2 vf3, 0x70(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(var_s0));
                        asm volatile("vopmula.xyz ACC, vf2, vf1");
                        asm volatile("vopmsub.xyz vf2, vf1, vf2");
                        asm volatile("vadda.xyzw ACC, vf0, vf7");
                        asm volatile("vmaddx.xyzw vf7, vf2, vf3x");
                    }
                    temp_f12 = M2C_FIELD(var_s0, f32 *, 0x54);
                    if (fabsf(temp_f12) > 0.01f) {
                        asm volatile("sqc2 vf7, 0x100(%0)" : : "r"(sp));
                        LoadRotateMatrixRad(&spA0, g_2a2dc0, temp_f12);
                        asm volatile("lqc2 vf5, (%0)" : : "r"(sp));
                        asm volatile("lqc2 vf6, 0x10(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf2, 0xb0(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf5, vf1x");
                        asm volatile("vmadday.xyz ACC, vf6, vf1y");
                        asm volatile("vmaddz.xyz vf1, vf3, vf1z");
                        asm volatile("vmulax.xyz ACC, vf5, vf2x");
                        asm volatile("vmadday.xyz ACC, vf6, vf2y");
                        asm volatile("vmaddz.xyz vf2, vf3, vf2z");
                        asm volatile("lqc2 vf4, 0xc0(%0)" : : "r"(sp));
                        asm volatile("vmulax.xyz ACC, vf5, vf4x");
                        asm volatile("vmadday.xyz ACC, vf6, vf4y");
                        asm volatile("vmaddz.xyz vf5, vf3, vf4z");
                        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                        asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf5, 0x20(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf1, 0xd0(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf1, 0x70(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf2, 0xe0(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf2, 0x80(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf5, 0xf0(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf5, 0x90(%0)" : : "r"(sp));
                        asm volatile("lqc2 vf7, 0x100(%0)" : : "r"(sp));
                    }
                    s32 vu_1;
                    asm volatile("qmfc2.ni %0, vf7" : "=r"(vu_1));
                    __as__6VECTORG9VU_VECTOR(&sp60, vu_1);
                    sp30 = sp0;
                    M2C_FIELD(&sp30, s128 *, 0x10) = sp10;
                    M2C_FIELD(&sp30, s128 *, 0x20) = sp20;
                    sp5C = 0;
                    sp4C = 0;
                    unksp3C = 0;
                    M2C_FIELD(&sp30, f32 *, 0x3C) = 1.0f;
                    func_001A5EE8(M2C_FIELD(arg0, s32 *, 0x1C4), &sp30, 0x3F800000, 0x3F800000);
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0x60);
                    if (var_s0 != NULL) {
                        asm volatile("lqc2 vf7, (%0)" : : "r"(var_s0));
                        goto loop_5;
                    }
                }
                var_v1 += 1;
            } while (var_v1 < M2C_FIELD(arg0, s32 *, 0x1C8));
        }
    }
}
}
