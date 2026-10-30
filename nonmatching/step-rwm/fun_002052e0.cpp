typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_002052E0 {
    /* 0x00 */ char pad0[0x80];
};                                                  /* size = 0x80 */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
M2C_UNK MatchSoOtherObject(s8 *, s8 *);         /* extern */
extern M2C_UNK g_2a2dc0;
extern s128 g_2a2dd0;
void func_002052E0(s8 *arg0, s8 *arg1) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s32 temp_v0;
    s8 *temp_a2;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v1;
    if (arg1 != NULL) {
        if (FIsBasicDerivedFrom(arg1, 3) == 0) {
            MatchSoOtherObject(arg0, arg1);
        } else {
            temp_v1 = M2C_FIELD(arg1, s8 **, 0xC);
            temp_v0 = M2C_FIELD(temp_v1, s32 (**)(s8 *), 0xFC)(arg1 + M2C_FIELD(temp_v1, s16 *, 0xF8));
            asm volatile("lqc2 vf5, (%0)" : : "r"(temp_v0));
            temp_a2 = M2C_FIELD(arg0, s8 **, 0xC);
            asm volatile("sqc2 vf5, (%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf6" : : "r"(0xBF800000));
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(temp_v0));
            asm volatile("lqc2 vf2, 0x240(%0)" : : "r"(arg0));
            asm volatile("vmulx.xyzw vf2, vf2, vf6x");
            asm volatile("sqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(temp_v0));
            asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(temp_v0));
            asm volatile("vmulax.xyz ACC, vf5, vf2x");
            asm volatile("vmadday.xyz ACC, vf4, vf2y");
            asm volatile("vmaddaz.xyz ACC, vf3, vf2z");
            asm volatile("vmaddw.xyz vf7, vf1, vf0w");
            asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
            asm volatile("sqc2 vf6, 0x40(%0)" : : "r"(sp));
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf7" : "=r"(vu_1));
            M2C_FIELD(temp_a2, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0xEC)(arg0 + M2C_FIELD(temp_a2, s16 *, 0xE8), vu_1, temp_a2);
            temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *), 0xF4)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0xF0), sp);
            if (FIsBasicDerivedFrom(arg0, 0x34) != 0) {
                asm volatile("qmtc2.ni %0, vf3" : : "r"(M2C_FIELD(arg0, s32 *, 0x1048)));
                asm volatile("lqc2 vf2, (%0)" : : "r"(&g_2a2dc0));
                asm volatile("lqc2 vf1, 0x30(%0)" : : "r"(sp));
                asm volatile("vadda.xyzw ACC, vf0, vf1");
                asm volatile("vmaddx.xyzw vf1, vf2, vf3x");
                asm volatile("sqc2 vf3, 0x40(%0)" : : "r"(sp));
                asm volatile("sqc2 vf1, 0x1060(%0)" : : "r"(arg0));
            }
            temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x118), g_2a2dd0);
            temp_v0_4 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, s128), 0x124)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0x120), g_2a2dd0);
            M2C_FIELD(arg0, s32 *, 0x208) = 0;
        }
    }
}
}
