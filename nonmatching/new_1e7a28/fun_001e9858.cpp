typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001E9858 {
    /* 0x000 */ char pad0[0x800];
    /* 0x800 */ s32 sp800;                          /* inferred */
    /* 0x804 */ char pad804[0xC];                   /* maybe part of sp800[4]? */
    /* 0x810 */ s128 sp810;                         /* inferred */
    /* 0x820 */ s128 sp820;                         /* inferred */
    /* 0x830 */ s128 sp830;                         /* inferred */
    /* 0x840 */ s128 sp840;                         /* inferred */
    /* 0x850 */ s128 sp850;                         /* inferred */
    /* 0x860 */ s128 sp860;                         /* inferred */
    /* 0x870 */ s128 sp870;                         /* inferred */
    /* 0x880 */ s128 sp880;                         /* inferred */
    /* 0x890 */ s128 sp890;                         /* inferred */
    /* 0x8A0 */ s128 sp8A0;                         /* inferred */
    /* 0x8B0 */ f32 sp8B0;                          /* inferred */
    /* 0x8B4 */ char pad8B4[0xC];                   /* maybe part of sp8B0[4]? */
    /* 0x8C0 */ s128 sp8C0;                         /* inferred */
    /* 0x8D0 */ s32 sp8D0;                          /* inferred */
    /* 0x8D4 */ char pad8D4[0xBC];
};                                                  /* size = 0x990 */
M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, s128, s128); /* extern */
M2C_UNK CopyAb__FPvT0Ui(s8 *, s32, s32);          /* extern */
M2C_UNK FindCrvClosestPointAll(s32, M2C_UNK, M2C_UNK, s32 *); /* extern */
s8 *PmatLoWorld(s8 *);                          /* extern */
M2C_UNK PostSoLoad();                               /* extern */
s8 *PvAllocSwImpl__Fi(s32 *);                     /* extern */
M2C_UNK func_0016EF00(s8 *, s32, s32);            /* extern */
extern M2C_UNK D_002C44F0;
void func_001E9858(s8 *arg0) {
    s8 sp[0x990] __attribute__((aligned(16)));
    s32 sp800;
    s128 sp810;
    s128 sp820;
    s128 sp830;
    s128 sp840;
    s128 sp850;
    s128 sp860;
    s128 sp870;
    s128 sp880;
    s128 sp890;
    s128 sp8A0;
    f32 sp8B0;
    s128 sp8C0;
    s32 sp8D0;
    M2C_UNK *temp_fp;
    M2C_UNK temp_a1_2;
    M2C_UNK temp_v1_2;
    s128 temp_t1;
    s128 temp_t2;
    s128 temp_t3;
    s32 temp_a1;
    s32 temp_a2;
    s32 var_s0;
    s32 var_s5;
    s32 var_v0;
    s8 *temp_s1;
    s8 *temp_s3;
    s8 *temp_v1;
    s8 *var_s0_2;
    s8 *var_s2;
    s8 *var_s4;
    PostSoLoad();
    if (M2C_FIELD(arg0, s32 *, 0x150) != 0) {
        if (M2C_FIELD(arg0, s8 **, 0xDC) != NULL) {
            sp8C0 = M2C_FIELD(PmatLoWorld(arg0), s128 *, 0x20);
            var_s4 = M2C_FIELD(arg0, s8 **, 0xDC);
            if (var_s4 != NULL) {
loop_4:
                var_s0 = 0;
                temp_a1 = (s32) ((M2C_FIELD(var_s4, s32 *, 0) - M2C_FIELD(arg0, s32 *, 0xBC)) * 0xCCCCCCCD) >> 2;
                temp_a2 = temp_a1 * 0x28;
                temp_v1 = (s8 *)(M2C_FIELD(arg0, s32 *, 0xC0) + temp_a2);
                temp_fp = M2C_FIELD(temp_v1, M2C_UNK **, 4);
                M2C_FIELD(temp_v1, M2C_UNK **, 4) = &D_002C44F0;
                func_0016EF00(arg0 + 0x80, temp_a1, temp_a2);
                if (M2C_FIELD(var_s4, s32 *, 4) > 0) {
                    var_v0 = 0 << 5;
                    do {
                        sp8D0 = var_s0 + 1;
                        temp_s1 = (s8 *)(M2C_FIELD(var_s4, s32 *, 8) + var_v0);
                        var_s5 = 0;
                        CopyAb__FPvT0Ui(sp, M2C_FIELD(temp_s1, s32 *, 0xC), M2C_FIELD(temp_s1, s32 *, 0) * 0x10);
                        sp800 = M2C_FIELD(temp_s1, s32 *, 0) * 0x10;
                        M2C_FIELD(&sp800, s32 *, 4) = 0x10;
                        var_s0_2 = PvAllocSwImpl__Fi(&sp800);
                        M2C_FIELD(temp_s1, s8 **, 0x1C) = var_s0_2;
                        if (M2C_FIELD(temp_s1, s32 *, 0) > 0) {
                            temp_s3 = (s8 *)(temp_fp + 0x40);
                            var_s2 = sp;
                            do {
                                asm volatile("lqc2 vf5, (%0)" : : "r"(var_s2));
                                asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(temp_s3));
                                asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(temp_s3));
                                asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(temp_s3));
                                asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(temp_fp));
                                asm volatile("vmulax.xyz ACC, vf3, vf5x");
                                asm volatile("vmadday.xyz ACC, vf4, vf5y");
                                asm volatile("vmaddaz.xyz ACC, vf2, vf5z");
                                asm volatile("vmaddw.xyz vf3, vf1, vf0w");
                                var_s5 += 1;
                                asm volatile("sqc2 vf3, 0x8e0(%0)" : : "r"(sp));
                                var_s2 += 0x10;
                                s32 vu_1;
                                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_1));
                                FindCrvClosestPointAll(M2C_FIELD(arg0, s32 *, 0x150), vu_1, 0, &sp800);
                                BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp850, sp810, sp8C0);
                                asm volatile("lqc2 vf1, 0x800(%0)" : : "r"(sp));
                                s64 vu_2;
                                asm volatile("pextlw %0, %1, %2" : "=r"(vu_2) : "r"(sp860), "r"(sp850));
                                temp_a1_2 = vu_2;
                                s64 vu_3;
                                asm volatile("pextlw %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(sp870));
                                temp_v1_2 = vu_3;
                                asm volatile("lqc2 vf3, 0x8e0(%0)" : : "r"(sp));
                                s64 vu_4;
                                asm volatile("pcpyld %0, %1, %2" : "=r"(vu_4) : "r"(temp_v1_2), "r"(temp_a1_2));
                                temp_t1 = vu_4;
                                s64 vu_5;
                                asm volatile("pcpyud %0, %1, %2" : "=r"(vu_5) : "r"(temp_a1_2), "r"(temp_v1_2));
                                temp_t2 = vu_5;
                                s64 vu_6;
                                asm volatile("pextuw %0, %1, %2" : "=r"(vu_6) : "r"(sp860), "r"(sp850));
                                s64 vu_7;
                                asm volatile("pextuw %0, %1, %2" : "=r"(vu_7) : "r"(0), "r"(sp870));
                                s64 vu_8;
                                asm volatile("pcpyld %0, %1, %2" : "=r"(vu_8) : "r"(vu_7), "r"(vu_6));
                                temp_t3 = vu_8;
                                asm volatile("vsub.xyzw vf3, vf3, vf1");
                                asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_t2));
                                asm volatile("qmtc2.ni %0, vf1" : : "r"(temp_t1));
                                sp820 = sp850;
                                asm volatile("qmtc2.ni %0, vf4" : : "r"(temp_t3));
                                sp830 = sp860;
                                sp840 = sp870;
                                asm volatile("vmulax.xyz ACC, vf1, vf3x");
                                asm volatile("vmadday.xyz ACC, vf2, vf3y");
                                asm volatile("vmaddz.xyz vf3, vf4, vf3z");
                                sp850 = temp_t1;
                                sp860 = temp_t2;
                                sp870 = temp_t3;
                                sp880 = temp_t1;
                                sp890 = temp_t2;
                                sp8A0 = temp_t3;
                                asm volatile("sqc2 vf3, (%0)" : : "r"(var_s0_2));
                                M2C_FIELD(var_s0_2, f32 *, 0xC) = sp8B0;
                                var_s0_2 += 0x10;
                            } while (var_s5 < M2C_FIELD(temp_s1, s32 *, 0));
                        }
                        var_s0 = sp8D0;
                        var_v0 = var_s0 << 5;
                    } while (var_s0 < M2C_FIELD(var_s4, s32 *, 4));
                }
                var_s4 = M2C_FIELD(var_s4, s8 **, 0xC);
                if (var_s4 != NULL) {
                    goto loop_4;
                }
            }
        }
    }
}
}
