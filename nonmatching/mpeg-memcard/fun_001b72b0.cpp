typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001B72B0 {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ char pad70[0x30];                   /* maybe part of sp60[4]? */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ s128 spE0;                          /* inferred */
    /* 0x0F0 */ char padF0[0x30];                   /* maybe part of spE0[4]? */
    /* 0x120 */ s128 sp120;                         /* inferred */
    /* 0x130 */ s128 sp130;                         /* inferred */
    /* 0x140 */ s128 sp140;                         /* inferred */
    /* 0x150 */ s128 sp150;                         /* inferred */
    /* 0x160 */ s128 sp160;                         /* inferred */
    /* 0x170 */ s128 sp170;                         /* inferred */
    /* 0x180 */ s128 sp180;                         /* inferred */
    /* 0x190 */ s128 sp190;                         /* inferred */
    /* 0x1A0 */ s128 sp1A0;                         /* inferred */
    /* 0x1B0 */ s128 sp1B0;                         /* inferred */
    /* 0x1C0 */ s128 sp1C0;                         /* inferred */
    /* 0x1D0 */ s128 sp1D0;                         /* inferred */
    /* 0x1E0 */ s128 sp1E0;                         /* inferred */
    /* 0x1F0 */ s128 sp1F0;                         /* inferred */
    /* 0x200 */ s128 sp200;                         /* inferred */
    /* 0x210 */ s128 sp210;                         /* inferred */
    /* 0x220 */ s128 sp220;                         /* inferred */
    /* 0x230 */ char pad230[0x30];                  /* maybe part of sp220[4]? */
    /* 0x260 */ s128 sp260;                         /* inferred */
    /* 0x270 */ char pad270[0x30];                  /* maybe part of sp260[4]? */
    /* 0x2A0 */ s8 *sp2A0;                        /* inferred */
    /* 0x2A4 */ s128 *sp2A4;                        /* inferred */
    /* 0x2A8 */ s128 *sp2A8;                        /* inferred */
    /* 0x2AC */ s32 sp2AC;                          /* inferred */
    /* 0x2B0 */ s32 sp2B0;                          /* inferred */
    /* 0x2B4 */ s128 *sp2B4;                        /* inferred */
    /* 0x2B8 */ s128 *sp2B8;                        /* inferred */
    /* 0x2BC */ s128 *sp2BC;                        /* inferred */
    /* 0x2C0 */ s128 *sp2C0;                        /* inferred */
    /* 0x2C4 */ s32 sp2C4;                          /* inferred */
    /* 0x2C8 */ char pad2C8[0xA8];
};                                                  /* size = 0x370 */
#define sp130 (*(s128 *)(sp + 0x130))
#define sp140 (*(s128 *)(sp + 0x140))
#define sp1F0 (*(s128 *)(sp + 0x1F0))
#define sp200 (*(s128 *)(sp + 0x200))
#define sp210 (*(s128 *)(sp + 0x210))
M2C_UNK ConvertXfMat(s128 *, s32, s128 *);          /* extern */
M2C_UNK ConvertXfMatrix4(s128 *, s32, s32, M2C_UNK *); /* extern */
s128 ConvertXfPos(s32, s32, s128);                  /* extern */
s128 DecomposeRotateMatrixEuler(...); /* extern */
M2C_UNK InvertMatrix4Affine(s128 *, s128 *);        /* extern */
M2C_UNK LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(s128 *, M2C_UNK); /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s128 *, s128);     /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(...); /* extern */
extern M2C_UNK RO_002A2D30;
void func_001B72B0(s8 *arg0, s32 arg1, s128 *arg2, s128 *arg3, s128 *arg4) {
    s32 unksp12C;
    s32 unksp13C;
    s32 unksp14C;
    s8 sp[0x140] __attribute__((aligned(16)));
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 spA0;
    s128 spB0;
    s128 spC0;
    s128 spD0;
    s128 spE0;
    s128 sp120;
    s128 sp150;
    s128 sp160;
    s128 sp170;
    s128 sp180;
    s128 sp190;
    s128 sp1A0;
    s128 sp1B0;
    s128 sp1C0;
    s128 sp1D0;
    s128 sp1E0;
    s128 sp220;
    s128 sp260;
    s8 *sp2A0;
    s128 *sp2A4;
    s128 *sp2A8;
    s32 sp2AC;
    s32 sp2B0;
    s128 *sp2B4;
    s128 *sp2B8;
    s128 *sp2BC;
    s128 *sp2C0;
    s32 sp2C4;
    M2C_UNK temp_a1;
    s128 **var_s0;
    s128 **var_s1_3;
    s128 *var_a1;
    s128 *var_a2;
    s128 *var_a2_2;
    s128 temp_v0;
    s128 var_v0;
    s32 var_a0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s1_2;
    s8 *temp_s2;
    s8 *temp_v1;
    sp2A0 = arg0;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0x13F0);
    sp2A4 = arg3;
    sp2A8 = arg4;
    if (M2C_FIELD(temp_v1, s32 *, 0x188) == 0) {
        ConvertXfMat(&sp30, M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_v1, s8 **, 0x180), s8 **, 0x5C), s32 *, 0xA0), arg2);
        *sp2A4 = DecomposeRotateMatrixEuler((s128 *)(sp), sp30, sp30, sp40, sp50);
        var_v0 = ConvertXfPos(arg1, M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(sp2A0, s8 **, 0x13F0), s8 **, 0x180), s8 **, 0x58), s32 *, 0xA0), M2C_FIELD(arg2, s128 *, 0x30));
        goto block_25;
    }
    temp_s2 = M2C_FIELD(temp_v1, s8 **, 0x180);
    var_s1 = 0;
    InvertMatrix4Affine(&sp60, arg2);
    sp2AC = -1;
    sp2BC = &spE0;
    sp2C0 = &sp220;
    sp2B4 = &sp260;
    sp2B8 = &sp150;
    sp2B0 = -1;
    var_a0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(sp2A0, s8 **, 0x13F0), s8 **, 0x188), s32 *, 0x50);
    if (var_a0 != arg1) {
        var_a1 = (s128 *)(sp);
        do {
            *var_a1 = var_a0;
            var_a1 += 4;
            sp2AC = ((var_a0 ^ M2C_FIELD(temp_s2, s32 *, 0x58)) == 0) ? var_s1 : sp2AC;
            sp2B0 = ((var_a0 ^ M2C_FIELD(temp_s2, s32 *, 0x5C)) == 0) ? var_s1 : sp2B0;
            var_a0 = M2C_FIELD(var_a0, s32 *, 0xA0);
            var_s1 += 1;
        } while (var_a0 != arg1);
    }
    var_s1_2 = var_s1 - 1;
    sp2C4 = sp2AC - 1;
    ConvertXfMatrix4(&spA0, M2C_FIELD(M2C_FIELD(M2C_FIELD(sp2A0, s8 **, 0x13F0), s8 **, 0x188), s32 *, 0x50), M2C_FIELD(temp_s2, s32 *, 0x5C), &RO_002A2D30);
    ConvertXfMatrix4(sp2BC, M2C_FIELD(M2C_FIELD(temp_s2, s32 *, 0x5C), s32 *, 0xA0), arg1, &RO_002A2D30);
    __ml__FRC7MATRIX4T0(arg0, arg1, &sp120, &spA0, (s128 *)(M2C_FIELD(M2C_FIELD(sp2A0, s8 **, 0x13F0), s32 *, 0x188) + 0x60));
    spC0 = sp140;
    spA0 = sp120;
    spB0 = sp130;
    spD0 = sp150;
    __ml__FRC7MATRIX4T0(arg0, arg1, &sp1A0, &spA0, &sp60, sp130, sp120);
    __ml__FRC7MATRIX4T0(arg0, arg1, &sp160, &sp1A0, sp2BC);
    InvertMatrix4Affine(&sp120, &sp160);
    temp_v0 = DecomposeRotateMatrixEuler(&sp120);
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(temp_v0));
    temp_a1 = vu_1;
    sp40 = temp_v0;
    LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&sp160, temp_a1);
    __as__6VECTORG9VU_VECTOR(sp2B8, M2C_FIELD(*(sp + (sp2B0 * 4)), s128 *, 0x30));
    sp120 = sp160;
    M2C_FIELD(&sp120, s128 *, 0x10) = sp170;
    M2C_FIELD(&sp120, s128 *, 0x20) = sp180;
    unksp14C = 0;
    unksp13C = 0;
    unksp12C = 0;
    M2C_FIELD(&sp120, f32 *, 0x3C) = 1.0f;
    sp1A0 = M2C_FIELD(&RO_002A2D30, s128 *, 0);
    sp1B0 = M2C_FIELD(&RO_002A2D30, s128 *, 0x10);
    sp1C0 = M2C_FIELD(&RO_002A2D30, s128 *, 0x20);
    sp1D0 = M2C_FIELD(&RO_002A2D30, s128 *, 0x30);
    sp160 = M2C_FIELD(&RO_002A2D30, s128 *, 0);
    sp170 = M2C_FIELD(&RO_002A2D30, s128 *, 0x10);
    sp180 = M2C_FIELD(&RO_002A2D30, s128 *, 0x20);
    sp190 = M2C_FIELD(&RO_002A2D30, s128 *, 0x30);
    if (sp2AC < var_s1_2) {
        var_s0 = (s128 **)((var_s1_2 * 4) + sp);
        do {
            if (var_s1_2 != sp2B0) {
                var_a2 = *var_s0;
            } else {
                var_a2 = &sp120;
            }
            var_s1_2 -= 1;
            __ml__FRC7MATRIX4T0(arg0, arg1, &sp1E0, &sp160, var_a2);
            sp160 = sp1E0;
            sp170 = sp1F0;
            sp180 = sp200;
            sp190 = sp210;
            var_s0 -= 4;
        } while (sp2AC < var_s1_2);
    }
    var_s0_2 = sp2C4;
    if (var_s0_2 >= 0) {
        var_s1_3 = (s128 **)((var_s0_2 * 4) + sp);
        do {
            if (var_s0_2 != sp2B0) {
                var_a2_2 = *var_s1_3;
            } else {
                var_a2_2 = &sp120;
            }
            var_s1_3 -= 4;
            __ml__FRC7MATRIX4T0(arg0, arg1, &sp1E0, &sp1A0, var_a2_2);
            sp1A0 = sp1E0;
            sp1B0 = sp1F0;
            sp1C0 = sp200;
            var_s0_2 -= 1;
            sp1D0 = sp210;
        } while (var_s0_2 >= 0);
    }
    __ml__FRC7MATRIX4T0(arg0, arg1, &sp1E0, &sp1A0, M2C_FIELD(M2C_FIELD(sp2A0, s8 **, 0x13F0), s32 *, 0x188) + 0x60);
    sp1D0 = sp210;
    sp1A0 = sp1E0;
    sp1B0 = sp1F0;
    sp1C0 = sp200;
    __ml__FRC7MATRIX4T0(arg0, arg1, sp2B4, &sp1A0, &sp60, sp1F0, sp1E0);
    __ml__FRC7MATRIX4T0(arg0, arg1, sp2C0, sp2B4, &sp160);
    InvertMatrix4Affine(&sp1E0, sp2C0);
    sp50 = sp210;
    if (sp2A4 != NULL) {
        *sp2A4 = sp40;
    }
    var_v0 = sp50;
    if (sp2A8 != NULL) {
block_25:
        *sp2A8 = var_v0;
    }
}
}
