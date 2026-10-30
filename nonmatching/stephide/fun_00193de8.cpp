typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00193DE8 {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ char pad20[0x80];
};                                                  /* size = 0xA0 */
M2C_UNK FindCrvClosestPointFromU(s8 *, s128, M2C_UNK, s8 *, f32); /* extern */
M2C_UNK GetPathPosFromS(s8 *, s8 *, M2C_UNK, f32); /* extern */
s32 PmatLoWorld(s8 *);                            /* extern */
s128 PosLoWorld(s8 *);                            /* extern */
f32 SMaxCrv(s8 *);                                /* extern */
f32 SMinCrv(s8 *);                                /* extern */
void func_00193DE8(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s128 sp0;
    s128 sp10;
    M2C_UNK var_s2;
    f32 temp_f20;
    f32 temp_f22;
    s128 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_a1;
    s8 *temp_s1;
    s8 *temp_t0;
    s8 *temp_v0_3;
    s8 *temp_v1_2;
    temp_v1 = M2C_FIELD(arg0, s32 *, 8);
    switch (temp_v1) {                              /* irregular */
    case 4:
        temp_v0 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0x14));
        temp_a0 = M2C_FIELD(arg0, s8 **, 0);
        sp0 = temp_v0;
        temp_t0 = M2C_FIELD(temp_a0, s8 **, 0xC);
        s64 vu_1;
        asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(temp_v0));
        M2C_FIELD(temp_t0, M2C_UNK (**)(s8 *, M2C_UNK, s8 *, M2C_UNK), 0x294)(temp_a0 + M2C_FIELD(temp_t0, s16 *, 0x290), 0x23, M2C_FIELD(arg0, s8 **, 0x14), vu_1);
        return;
    case 3:
        temp_s1 = M2C_FIELD(arg0, s8 **, 0x14);
        var_s2 = 0x22;
        FindCrvClosestPointFromU(temp_s1, *M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s128 **, 0x218), 0, sp, M2C_FIELD(arg0, f32 *, 0x1C));
        if ((M2C_FIELD(temp_s1, s32 *, 0x1BC) == 0) && (M2C_FIELD(temp_s1, s32 *, 0xE4) == 0)) {
            temp_a1 = M2C_FIELD(arg0, s8 **, 0);
            temp_v1_2 = M2C_FIELD(temp_a1, s8 **, 0xC);
            asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(temp_v1_2, s32 (**)(s8 *, s8 *), 0x10C)(temp_a1 + M2C_FIELD(temp_v1_2, s16 *, 0x108), temp_a1)));
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
            asm volatile("vmul.xyz vf1, vf2, vf1");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf3, vf1z");
            asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
            temp_f22 = vu_2;
            temp_v0_2 = PmatLoWorld(M2C_FIELD(arg0, s8 **, 0));
            asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(temp_v0_2));
            asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(temp_v0_2));
            asm volatile("lqc2 vf4, (%0)" : : "r"(temp_v0_2));
            asm volatile("lqc2 vf2, 0x190(%0)" : : "r"(M2C_FIELD(arg0, s8 **, 0)));
            asm volatile("vmulax.xyz ACC, vf4, vf2x");
            asm volatile("vmadday.xyz ACC, vf3, vf2y");
            asm volatile("vmaddz.xyz vf2, vf5, vf2z");
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
            asm volatile("vmul.xyz vf2, vf2, vf1");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf3, vf2z");
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
            temp_f20 = -vu_3;
            if ((temp_f22 < -2.0f) || (temp_f20 < 2.0f)) {
                if (M2C_FIELD(arg0, f32 *, 0x20) < (SMinCrv(temp_s1) + 50.0f)) {
                    var_s2 = 0x2A;
                    GetPathPosFromS(temp_s1, sp, 0, SMinCrv(temp_s1) + 50.0f);
                } else {
                    goto block_10;
                }
            } else {
block_10:
                if (((temp_f22 > 2.0f) || (temp_f20 > -2.0f)) && ((SMaxCrv(temp_s1) - 50.0f) < M2C_FIELD(arg0, f32 *, 0x20))) {
                    var_s2 = 0x2A;
                    GetPathPosFromS(temp_s1, sp, 0, SMaxCrv(temp_s1) - 50.0f);
                    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(0xBF800000));
                    asm volatile("vmulx.xyzw vf1, vf1, vf2x");
                    asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
                    asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
                }
            }
        }
        temp_a0_2 = M2C_FIELD(arg0, s8 **, 0);
        temp_v0_3 = M2C_FIELD(temp_a0_2, s8 **, 0xC);
        M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, M2C_UNK, s8 *, s128), 0x294)(temp_a0_2 + M2C_FIELD(temp_v0_3, s16 *, 0x290), var_s2, temp_s1, sp0);
        return;
    }
}
}
