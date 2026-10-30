typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetHbskHbsks {
    /* 0x00 */ char pad0[0x30];
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ char pad60[0x50];
};                                                  /* size = 0xB0 */
#define sp40 (*(s128 *)(sp + 0x40))
#define sp50 (*(s128 *)(sp + 0x50))
M2C_UNK ConvertXfMat(s128 *, M2C_UNK, s32, s8 *); /* extern */
s32 ConvertXfPos(M2C_UNK, s32, M2C_UNK);            /* extern */
s32 DecomposeRotateMatrixEuler(s8 *, s128, s128, s128, s128); /* extern */
s32 PmatLoWorld(s8 *);                            /* extern */
M2C_UNK SetSoCnstrForce(s8 *, M2C_UNK);           /* extern */
M2C_UNK SetSoCnstrTorque(s8 *, M2C_UNK);          /* extern */
M2C_UNK SetXfKind(s8 *, s8 *, M2C_UNK);         /* extern */
M2C_UNK TiltMatUpright__FP7MATRIX3N20(s32, M2C_UNK, s8 *); /* extern */
M2C_UNK func_00147F40(M2C_UNK *);                   /* extern */
M2C_UNK func_001A58D0(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_001F68A8(s8 *, M2C_UNK);             /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;
extern M2C_UNK g_2be8f0;
extern f32 g_2dded0;
void SetHbskHbsks(s8 *arg0, s16 arg1) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s128 sp30;
    M2C_UNK temp_s0;
    f32 temp_f0;
    s128 temp_s0_2;
    s32 temp_v1;
    s32 var_s2;
    s8 *temp_a1;
    s8 *temp_v0;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *temp_v1_5;
    s8 *temp_v1_6;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x17C);
    if (temp_v1 != arg1) {
        if (temp_v1 == 2) {
            if (M2C_FIELD(arg0, s32 *, 0x18C) != 0) {
                func_001A58D0(0, 0xF);
                SetXfKind(arg0, M2C_FIELD(arg0, s8 **, 0x58), 1);
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x58), s16 *, 0x9A) = 0;
                SetXfKind(arg0, M2C_FIELD(arg0, s8 **, 0x5C), 1);
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x5C), s16 *, 0x9A) = 0;
                temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(s8 *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x118), g_2a2dd0);
                SetSoCnstrForce(arg0, 0);
                SetSoCnstrTorque(arg0, 0);
                func_001F68A8(arg0, 0);
            }
            temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v1_3, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x18), 6, 0, 0, 0, 0);
            func_00147F40(&B_003DD490);
            M2C_FIELD(arg0, s8 **, 0x190) = NULL;
        }
        if (arg1 == 2) {
            if (M2C_FIELD(arg0, s32 *, 0x18C) != 0) {
                SetSoCnstrForce(arg0, 1);
                SetSoCnstrTorque(arg0, 1);
                temp_a1 = M2C_FIELD(arg0, s8 **, 0x190);
                var_s2 = M2C_FIELD(temp_a1, s32 *, 0x10BC);
                if (var_s2 == 0) {
                    var_s2 = M2C_FIELD(temp_a1, s32 *, 0x60);
                }
                temp_v1_4 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v1_4, M2C_UNK (**)(s8 *, s8 *, s32, M2C_UNK), 0x54)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x50), temp_a1, var_s2, 3);
                TiltMatUpright__FP7MATRIX3N20(PmatLoWorld(arg0), 0, sp);
                ConvertXfMat(&sp30, 0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x5C), s32 *, 0xA0), sp);
                s64 vu_1;
                asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(DecomposeRotateMatrixEuler(sp, sp30, sp30, sp40, sp50)));
                temp_s0 = vu_1;
                SetXfKind(arg0, M2C_FIELD(arg0, s8 **, 0x5C), 7);
                temp_v1_5 = M2C_FIELD(arg0, s8 **, 0x5C);
                s64 vu_2;
                asm volatile("pextuw %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s0));
                temp_f0 = vu_2;
                M2C_FIELD(temp_v1_5, s32 *, 0xC0) = 0;
                temp_v1_6 = temp_v1_5 + 0xC0;
                M2C_FIELD(temp_v1_6, f32 *, 8) = temp_f0;
                M2C_FIELD(temp_v1_6, s32 *, 4) = 0;
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x5C), s16 *, 0x9A) = arg1;
                asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2be8f0));
                asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(var_s2));
                asm volatile("vadd.xyzw vf3, vf2, vf1");
                s32 vu_3;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_3));
                s64 vu_4;
                asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(ConvertXfPos(0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x58), s32 *, 0xA0), vu_3)));
                temp_s0_2 = vu_4;
                SetXfKind(arg0, M2C_FIELD(arg0, s8 **, 0x58), 7);
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x58), s128 *, 0xC0) = temp_s0_2;
                M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x58), s16 *, 0x9A) = arg1;
                func_001F68A8(arg0, 1);
            }
            temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x18), 5, 0, 0, 0, 0);
        }
        M2C_FIELD(arg0, s32 *, 0x17C) = (s32) arg1;
        M2C_FIELD(arg0, f32 *, 0x180) = (f32) g_2dded0;
    }
}
}
