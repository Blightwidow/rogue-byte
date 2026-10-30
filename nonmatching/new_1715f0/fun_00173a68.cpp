typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00173A68 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x30];
    /* 0x40 */ s32 sp40;                            /* inferred */
    /* 0x44 */ s8 *sp44;                          /* inferred */
    /* 0x48 */ s8 **sp48;                         /* inferred */
    /* 0x4C */ char pad4C[4];
    /* 0x50 */ s128 sp50;                           /* inferred */
    /* 0x60 */ char pad60[0x70];
};                                                  /* size = 0xD0 */
M2C_UNK FadeAloIn(s8 *, M2C_UNK);                 /* extern */
s8 *PalertFind(s32, M2C_UNK);                     /* extern */
s128 PosSpawnerFocus(s8 *);                       /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK SetAloAlpha(s8 *, M2C_UNK);               /* extern */
M2C_UNK UpdateLo();                                 /* extern */
M2C_UNK func_00154038(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_00173928(s8 *, s8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_00173D18(s8 *, M2C_UNK);             /* extern */
s8 *func_00173E78(s8 *, s32);                   /* extern */
s8 *func_00173F18(s8 *, s128, s8 *, M2C_UNK *, s32 *); /* extern */
s8 *func_00174490(s8 *, s8 *, s8 *, M2C_UNK *, s32); /* extern */
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002BE5CC;
extern f32 D_FLT_002BE5D0;
extern f32 D_FLT_002BE5D4;
extern f32 D_FLT_002BE5D8;
extern f32 g_2dded0;
void func_00173A68(s8 *arg0) {
    s8 sp[0x40] __attribute__((aligned(16)));
    M2C_UNK sp10;
    s32 sp40;
    s8 *sp44;
    s8 **sp48;
    s128 sp50;
    s128 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a1;
    s32 var_v0;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v1_2;
    s8 *var_s2;
    UpdateLo();
    temp_v0 = PosSpawnerFocus(arg0);
    sp50 = temp_v0;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(temp_v0));
    func_00173D18(arg0, vu_1);
    if (!(g_2dded0 < M2C_FIELD(arg0, f32 *, 0xA8))) {
        M2C_FIELD(arg0, f32 *, 0xA8) = (f32) (g_2dded0 + D_FLT_002BE5D0);
        if (M2C_FIELD(arg0, s32 *, 0x58) == M2C_FIELD(arg0, s32 *, 0x5C)) {
            asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(arg0));
            asm volatile("lqc2 vf2, 0x50(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf1, vf2, vf1");
            asm volatile("vmul.xy vf1, vf1, vf1");
            asm volatile("vaddy.x vf1, vf1, vf1y");
            var_v0 = 1;
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
            if (!(vu_2 < D_FLT_002BE5D4)) {
                var_v0 = 0;
            }
            if (var_v0 == 0) {
                goto block_5;
            }
        } else {
block_5:
            var_s2 = NULL;
            temp_v0_2 = PpoSwFocusBase(&B_003DD490);
            var_a1 = 0;
            if ((temp_v0_2 != 0) && (var_s2 = PalertFind(temp_v0_2, 0), var_a1 = 0, (var_s2 != NULL))) {
                if (M2C_FIELD(var_s2, s32 *, 0x28) != 0) {
                    temp_v1 = M2C_FIELD(arg0, s32 *, 0xAC);
                    if (temp_v1 != 1) {
                        var_a1 = 0;
                        if (temp_v1 < 2) {
                            if (temp_v1 != 0) {
                                goto block_17;
                            }
                        } else {
                            goto block_17;
                        }
                    } else if (!(D_FLT_002BE5CC < (g_2dded0 - M2C_FIELD(var_s2, f32 *, 0)))) {
                        var_a1 = 0;
                        goto block_17;
                    }
                } else {
                    var_s2 = NULL;
                    goto block_17;
                }
            } else {
block_17:
                if ((var_s2 != NULL) && (M2C_FIELD(var_s2, s32 *, 0x28) == 1)) {
                    var_a1 = M2C_FIELD(var_s2, s32 *, 0x2C);
                }
                temp_v0_3 = func_00173E78(arg0, var_a1);
                if (temp_v0_3 != NULL) {
                    temp_v0_4 = func_00173F18(arg0, sp50, sp, &sp10, &sp40);
                    if (temp_v0_4 != NULL) {
                        M2C_FIELD(arg0, s128 *, 0x70) = sp50;
                        if (M2C_FIELD(temp_v0_3, s8 **, 0) != NULL) {
                            func_00173928(arg0, temp_v0_3, 0, 1);
                        }
                        temp_v0_5 = func_00174490(arg0, temp_v0_4, sp, &sp10, sp40);
                        sp44 = temp_v0_5;
                        if (temp_v0_5 != NULL) {
                            SetAloAlpha(temp_v0_5, 0x3C23D70A);
                            FadeAloIn(sp44, 0x3F000000);
                            if (var_s2 != NULL) {
                                func_00154038(M2C_FIELD(sp44, s32 *, 0xF64), M2C_FIELD(var_s2, s32 *, 0xC), 2);
                            }
                            M2C_FIELD(temp_v0_3, s8 **, 0) = sp44;
                            M2C_FIELD(temp_v0_3, s8 **, 0xC) = temp_v0_4;
                            M2C_FIELD(temp_v0_3, f32 *, 4) = (f32) g_2dded0;
                            M2C_FIELD(arg0, s32 *, 0x58) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) + 1);
                            M2C_FIELD(temp_v0_4, s32 *, 0x14) = 1;
                            sp48 = &sp44;
                            temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
                            M2C_FIELD(arg0, f32 *, 0xA8) = (f32) (g_2dded0 + D_FLT_002BE5D8);
                            M2C_FIELD(temp_v1_2, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s8 ***, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x18), 0x19, 0, 1, &sp48, 0, 1);
                        }
                    }
                }
            }
        }
    }
}
}
