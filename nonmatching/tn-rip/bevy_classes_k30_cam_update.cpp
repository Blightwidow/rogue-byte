typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_bevy_classes_k30_cam_update {
    /* 0x000 */ char pad0[0x30];
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ char padD0[0xC];
    /* 0x0DC */ s32 spDC;                           /* inferred */
    /* 0x0E0 */ char padE0[0xC];                    /* maybe part of spDC[4]? */
    /* 0x0EC */ s32 spEC;                           /* inferred */
    /* 0x0F0 */ M2C_UNK spF0;                       /* inferred */
    /* 0x0F0 */ char padF0[0x90];
};                                                  /* size = 0x180 */
#define sp70 (*(s128 *)(sp + 0x070))
#define sp80 (*(s128 *)(sp + 0x080))
#define spA0 (*(s128 *)(sp + 0x0A0))
#define spB0 (*(s128 *)(sp + 0x0B0))
M2C_UNK ContinueAmb(s8 *);                        /* extern */
s128 DecomposeRotateMatrixEuler(s128 *);            /* extern */
M2C_UNK DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(s128 *, s8 *, s8 *); /* extern */
f32 GLimitLm__FP2LMf(M2C_UNK *, f32);               /* extern */
f32 GSmooth__FfffP3SMPPf(M2C_UNK *, M2C_UNK, f32, f32, f32); /* extern */
M2C_UNK LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(...); /* extern */
M2C_UNK PauseAmb(s8 *, f32);                      /* extern */
s128 PosSmooth(s128, s128, M2C_UNK *, M2C_UNK, f32); /* extern */
f32 RadSmooth__FfffP3SMPPf(M2C_UNK *, M2C_UNK, f32, f32, f32); /* extern */
M2C_UNK SetAmbPitch(s8 *, f32);                   /* extern */
M2C_UNK SetAmbVolume(s8 *, f32);                  /* extern */
M2C_UNK SetCmFov(M2C_UNK *, f32);                   /* extern */
M2C_UNK SetCmLookAt(M2C_UNK *, s128, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetCmPosMat(M2C_UNK *, s128 *);             /* extern */
M2C_UNK SmoothMatrix(s8 *, s128 *, M2C_UNK *, s128 *, f32); /* extern */
M2C_UNK UpdateCplcy();                              /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, s128);  /* extern */
s32 bevy_classes_k30_cam_150780(s8 *);            /* extern */
s32 bevy_classes_k30_cam_1507f8(s8 *);            /* extern */
extern M2C_UNK B_002DDF40;
extern f32 B_FLT_003E1BE0;
extern M2C_UNK D_002BBB68;
extern M2C_UNK D_002BD9B8;
extern M2C_UNK D_002BD9C8;
extern M2C_UNK D_002BD9D8;
extern M2C_UNK D_002BD9E8;
extern M2C_UNK D_002BD9F8;
extern M2C_UNK g_2bbb60;
extern M2C_UNK g_2dded0;
void bevy_classes_k30_cam_update(s8 *arg0) {
    s32 unkspCC;
    s8 sp[0xb0] __attribute__((aligned(16)));
    s128 sp30;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp90;
    s128 spC0;
    s32 spDC;
    s32 spEC;
    M2C_UNK spF0;
    M2C_UNK temp_a2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f12;
    f32 temp_f13;
    f32 temp_f1;
    f32 var_f12;
    f32 var_f2;
    s128 temp_s0_3;
    s128 temp_s0_4;
    s128 temp_v0;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_s0;
    s8 *temp_s0_2;
    UpdateCplcy();
    if (M2C_FIELD(&g_2dded0, f32 *, 4) != 0.0f) {
        temp_f13 = M2C_FIELD(arg0, f32 *, 0x18);
        if (temp_f13 >= 0.0f) {
            temp_f0 = GSmooth__FfffP3SMPPf(&D_002BD9B8, 0, M2C_FIELD(arg0, f32 *, 0xAC), temp_f13, M2C_FIELD(&g_2dded0, f32 *, 4));
            var_f2 = 0.0f;
            if (!(temp_f0 < 0.0f)) {
                var_f2 = temp_f0;
                if (temp_f0 > 1.0f) {
                    var_f2 = 1.0f;
                }
            }
            temp_f0_2 = var_f2 - M2C_FIELD(arg0, f32 *, 0xAC);
            M2C_FIELD(arg0, f32 *, 0xAC) = var_f2;
            M2C_FIELD(arg0, f32 *, 0xB0) = (f32) (temp_f0_2 / M2C_FIELD(&g_2dded0, f32 *, 4));
        }
        temp_f12 = M2C_FIELD(arg0, f32 *, 0xB0);
        if (temp_f12 == 0.0f) {
            temp_a0 = M2C_FIELD(arg0, s8 **, 0xC0);
            if (M2C_FIELD(temp_a0, s16 *, 0x4E) <= 0) {
                PauseAmb(temp_a0, temp_f12);
            }
        } else {
            temp_s0 = M2C_FIELD(arg0, s8 **, 0xC0);
            SetAmbPitch(temp_s0, GLimitLm__FP2LMf(&D_002BBB68, fabsf(temp_f12)));
            temp_s0_2 = M2C_FIELD(arg0, s8 **, 0xC0);
            SetAmbVolume(temp_s0_2, GLimitLm__FP2LMf(&g_2bbb60, (fabsf(M2C_FIELD(arg0, f32 *, 0xB0)) * 0.5f) + 0.5f));
            temp_a0_2 = M2C_FIELD(arg0, s8 **, 0xC0);
            if (M2C_FIELD(temp_a0_2, s16 *, 0x4E) > 0) {
                ContinueAmb(temp_a0_2);
            }
        }
        if (M2C_FIELD(arg0, s32 *, 0x40) != 0) {
            M2C_FIELD(arg0, s128 *, 0x50) = PosSmooth(M2C_FIELD(arg0, s128 *, 0x50), M2C_FIELD(arg0, s128 *, 0x80), &D_002BD9C8, 0, M2C_FIELD(&g_2dded0, f32 *, 4));
            LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&sp90, M2C_FIELD(arg0, s128 *, 0x60));
            LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(&sp90, M2C_FIELD(arg0, s128 *, 0x90), sp90, sp90, spA0, spB0);
            sp50 = spB0;
            sp40 = spA0;
            sp30 = sp90;
            SmoothMatrix(sp, &sp30, &D_002BD9D8, &sp60, M2C_FIELD(&g_2dded0, f32 *, 4));
            M2C_FIELD(arg0, s128 *, 0x60) = DecomposeRotateMatrixEuler(&sp60);
            M2C_FIELD(arg0, f32 *, 0x70) = RadSmooth__FfffP3SMPPf(&D_002BD9E8, 0, M2C_FIELD(arg0, f32 *, 0x70), M2C_FIELD(arg0, f32 *, 0xA0), M2C_FIELD(&g_2dded0, f32 *, 4));
            __as__6VECTORG9VU_VECTOR(&spF0, M2C_FIELD(arg0, s128 *, 0x50));
            spC0 = sp60;
            M2C_FIELD(&spC0, s128 *, 0x10) = sp70;
            M2C_FIELD(&spC0, s128 *, 0x20) = sp80;
            spEC = 0;
            spDC = 0;
            unkspCC = 0;
            M2C_FIELD(&spC0, f32 *, 0x3C) = 1.0f;
            SetCmPosMat(&B_002DDF40, &spC0);
            SetCmFov(&B_002DDF40, M2C_FIELD(arg0, f32 *, 0x70));
            DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(&spC0, arg0 + 0xA4, arg0 + 0xA8);
            temp_f0_3 = M2C_FIELD(arg0, f32 *, 0xB8);
            temp_f1 = M2C_FIELD(arg0, f32 *, 0xBC);
            if (temp_f0_3 == temp_f1) {
                var_f12 = 0.0f;
            } else {
                var_f12 = (M2C_FIELD(arg0, f32 *, 0x70) - temp_f0_3) / (temp_f1 - temp_f0_3);
            }
            M2C_FIELD(arg0, f32 *, 0xAC) = GLimitLm__FP2LMf(&g_2bbb60, var_f12);
        } else {
            temp_f0_4 = 1.0f - M2C_FIELD(arg0, f32 *, 0xAC);
            SetCmFov(&B_002DDF40, ((1.0f - temp_f0_4) * M2C_FIELD(arg0, f32 *, 0xB8)) + (temp_f0_4 * M2C_FIELD(arg0, f32 *, 0xBC)));
            temp_s0_3 = M2C_FIELD(arg0, s128 *, 0x30);
            temp_s0_4 = M2C_FIELD(arg0, s128 *, 0x20);
            s64 vu_1;
            asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(bevy_classes_k30_cam_1507f8(arg0)));
            s64 vu_2;
            asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s0_3));
            M2C_FIELD(arg0, s128 *, 0x30) = PosSmooth(vu_2, vu_1, &D_002BD9F8, 0, M2C_FIELD(&g_2dded0, f32 *, 4));
            s64 vu_3;
            asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(bevy_classes_k30_cam_150780(arg0)));
            s64 vu_4;
            asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_s0_4));
            temp_v0 = PosSmooth(vu_4, vu_3, &D_002BD9F8, 0, M2C_FIELD(&g_2dded0, f32 *, 4));
            s64 vu_5;
            asm volatile("por %0, %1, %2" : "=r"(vu_5) : "r"(0), "r"(temp_v0));
            temp_a2 = vu_5;
            M2C_FIELD(arg0, s128 *, 0x20) = temp_v0;
            SetCmLookAt(&B_002DDF40, M2C_FIELD(arg0, s128 *, 0x30), temp_a2, 0, 0);
        }
        B_FLT_003E1BE0 = M2C_FIELD(&g_2dded0, f32 *, 0);
    }
}
}
