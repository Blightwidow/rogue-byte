typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_MarkSoContactsSweptPoints {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x40];
    /* 0x050 */ f32 sp50;                           /* inferred */
    /* 0x054 */ char pad54[8];                      /* maybe part of sp50[3]? */
    /* 0x05C */ s32 sp5C;                           /* inferred */
    /* 0x060 */ char pad60[0x70];                   /* maybe part of sp5C[0x1D]? */
    /* 0x0D0 */ M2C_UNK spD0;                       /* inferred */
    /* 0x0D0 */ char padD0[0xF0];
};                                                  /* size = 0x1C0 */
#define sp50 (*(f32 *)(sp + 0x050))
#define sp5C (*(s32 *)(sp + 0x05C))
s32 ClsgClipEdgeToObject(s8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK InvertMatrix4Affine(M2C_UNK *, s8 *);     /* extern */
M2C_UNK PxpAdd(s32, s8 *, s8 *, M2C_UNK, f32, s32); /* extern */
void MarkSoContactsSweptPoints(s32 arg0, s8 *arg1, s8 *arg2, s32 arg3) {
    s8 sp[0x130] __attribute__((aligned(16)));
    M2C_UNK sp10;
    M2C_UNK spD0;
    f32 temp_a3;
    f32 temp_f0;
    f32 var_f12;
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a0;
    s32 var_s1;
    s32 var_v1;
    s32 var_v1_2;
    s8 *temp_s4;
    var_s1 = M2C_FIELD(arg1, s32 *, 0x1C);
    if (var_s1 < M2C_FIELD(arg1, s32 *, 0x78)) {
        temp_s4 = arg1 + 0x20;
        do {
            temp_s3 = var_s1 * 0x10;
            asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(arg1));
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(temp_s4));
            asm volatile("lqc2 vf3, (%0)" : : "r"(temp_s3 + M2C_FIELD(arg1, s32 *, 0x7C)));
            asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_s4));
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(temp_s4));
            asm volatile("vmulax.xyz ACC, vf5, vf3x");
            asm volatile("vmadday.xyz ACC, vf4, vf3y");
            asm volatile("vmaddaz.xyz ACC, vf2, vf3z");
            asm volatile("vmaddw.xyz vf6, vf1, vf0w");
            if (M2C_FIELD(arg2, s32 *, 0xA8) != M2C_FIELD(arg2, s32 *, 0xAC)) {
                asm volatile("sqc2 vf6, 0x120(%0)" : : "r"(sp));
                InvertMatrix4Affine(&spD0, arg2 + 0x20);
                temp_v1 = M2C_FIELD(arg2, s32 *, 0);
                asm volatile("lqc2 vf3, 0xe0(%0)" : : "r"(sp));
                asm volatile("lqc2 vf2, 0xf0(%0)" : : "r"(sp));
                temp_v0 = temp_v1 + 0x40;
                asm volatile("lqc2 vf1, 0x100(%0)" : : "r"(sp));
                asm volatile("lqc2 vf5, 0xd0(%0)" : : "r"(sp));
                asm volatile("lqc2 vf6, 0x120(%0)" : : "r"(sp));
                asm volatile("vmulax.xyz ACC, vf5, vf6x");
                asm volatile("vmadday.xyz ACC, vf3, vf6y");
                asm volatile("vmaddaz.xyz ACC, vf2, vf6z");
                asm volatile("vmaddw.xyz vf6, vf1, vf0w");
                asm volatile("lqc2 vf4, 0x40(%0)" : : "r"(temp_v1));
                asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(temp_v0));
                asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0));
                asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_v0));
                asm volatile("vmulax.xyz ACC, vf4, vf6x");
                asm volatile("vmadday.xyz ACC, vf2, vf6y");
                asm volatile("vmaddaz.xyz ACC, vf1, vf6z");
                asm volatile("vmaddw.xyz vf6, vf3, vf0w");
            }
            asm volatile("lqc2 vf1, (%0)" : : "r"(temp_s3 + M2C_FIELD(arg1, s32 *, 0x94)));
            var_s1 += 1;
            asm volatile("sqc2 vf6, 0x120(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0x110(%0)" : : "r"(sp));
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_2));
            temp_v0_2 = ClsgClipEdgeToObject(arg2, vu_2, vu_1, 2);
            asm volatile("lqc2 vf1, 0x110(%0)" : : "r"(sp));
            asm volatile("lqc2 vf6, 0x120(%0)" : : "r"(sp));
            if (temp_v0_2 != 0) {
                var_f12 = 0.0f;
                var_v1 = 1;
                if (sp50 != 0.0f) {
                    var_v1 = 0;
                }
                if (var_v1 < temp_v0_2) {
                    asm volatile("vsub.xyzw vf1, vf6, vf1");
                    var_v1_2 = M2C_FIELD(arg1, s32 *, 0x90);
                    asm volatile("vmul.xyz vf2, vf1, vf1");
                    asm volatile("vaddw.x vf3, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf2, vf2y");
                    asm volatile("vmaddz.x vf2, vf3, vf2z");
                    asm volatile("lqc2 vf6, 0x10(%0)" : : "r"(sp));
                    asm volatile("vsqrt Q, vf2x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf2, vf0, Q");
                    asm volatile("vdiv Q, vf0w, vf2x");
                    asm volatile("vwaitq");
                    asm volatile("vmulq.xyzw vf5, vf1, Q");
                    if (var_v1_2 > 0) {
                        var_a0 = M2C_FIELD(arg1, s32 *, 0x94);
                        asm volatile("vmove.xyzw vf4, vf6");
                        asm volatile("vmove.xyzw vf3, vf5");
                        do {
                            asm volatile("lqc2 vf1, (%0)" : : "r"(var_a0));
                            asm volatile("vsub.xyzw vf1, vf1, vf4");
                            asm volatile("vmul.xyz vf1, vf1, vf3");
                            asm volatile("vaddw.x vf2, vf0, vf0w");
                            asm volatile("vadday.x ACC, vf1, vf1y");
                            asm volatile("vmaddz.x vf1, vf2, vf1z");
                            s32 vu_3;
                            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                            temp_a3 = vu_3;
                            if (temp_a3 < var_f12) {
                                var_f12 = temp_a3;
                            }
                            var_v1_2 -= 1;
                            var_a0 += 0x10;
                        } while (var_v1_2 != 0);
                    }
                    if (M2C_FIELD(arg1, s64 *, 0x10) & (0x8000 << 0x22)) {
                        asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(M2C_FIELD(arg1, s32 *, 0)));
                        asm volatile("vsub.xyzw vf1, vf1, vf6");
                        asm volatile("vmul.xyz vf1, vf1, vf5");
                        asm volatile("vaddw.x vf2, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf1, vf1y");
                        asm volatile("vmaddz.x vf1, vf2, vf1z");
                        s32 vu_4;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
                        temp_f0 = vu_4 - M2C_FIELD(arg1, f32 *, 8);
                        if (temp_f0 < var_f12) {
                            var_f12 = temp_f0;
                        }
                    }
                    s32 vu_5;
                    asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_5));
                    vu_5;
                    s32 vu_6;
                    asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_6));
                    PxpAdd(arg0, arg1, arg2, vu_6, var_f12, arg3);
                }
            }
        } while (var_s1 < M2C_FIELD(arg1, s32 *, 0x78));
    }
}
}
