typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AdjustStepNewXp {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[8];
    /* 0x18 */ f32 sp18;                            /* inferred */
    /* 0x1C */ char pad1C[0x74];
};                                                  /* size = 0x90 */
M2C_UNK PxpAdd(M2C_UNK *, s32, s32, M2C_UNK, M2C_UNK, s8 *); /* extern */
M2C_UNK func_001F4FB0();                            /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_FLT_002C3C60;
extern M2C_UNK32 D_FLT_002C3C90;
extern s128 g_2a2da0;
void AdjustStepNewXp(s8 *arg0, s8 *arg1, s32 arg2) {
    s8 sp[0x40] __attribute__((aligned(16)));
    M2C_UNK sp10;
    f32 sp18;
    M2C_UNK temp_t1;
    f32 temp_f1;
    s32 temp_v1;
    s32 temp_v1_2;
    s8 *temp_a0;
    func_001F4FB0();
    temp_v1 = M2C_FIELD(arg1, s32 *, 0x9C);
    M2C_FIELD(arg1, M2C_UNK32 *, 0x94) = 0;
    M2C_FIELD(arg1, s32 *, 0x98) = 0;
    if (temp_v1 == 0xE) {
        if (M2C_FIELD(arg1, f32 *, 0x88) > 0.7f) {
            M2C_FIELD(arg1, M2C_UNK32 *, 0x94) = (M2C_UNK32) D_FLT_002C3C90;
            M2C_FIELD(arg1, f32 *, 0xA0) = (f32) (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE8), f32 *, 0xD0) * -4500.0f);
            M2C_FIELD(arg1, f32 *, 0xA4) = (f32) (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE8), f32 *, 0xD0) * 9000.0f);
            return;
        }
        M2C_FIELD(arg1, f32 *, 0xA4) = (f32) (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE8), f32 *, 0xD0) * 9000.0f);
        return;
    }
    if ((temp_v1 == 3) || ((arg2 == 1) && ((temp_v1 == arg2) || (temp_v1 == 4) || (temp_v1 == 5) || (temp_v1 == 6)))) {
        temp_f1 = *((arg2 * 4) + &D_FLT_002C3C60);
        if ((temp_f1 * M2C_FIELD(arg1, f32 *, 0x88)) > 0.0f) {
            asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(arg1));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_f1));
            asm volatile("vmulx.xyzw vf1, vf1, vf2x");
            asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
            sp18 = 0.0f;
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("vmul.xyz vf1, vf4, vf4");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf3, vf1z");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
            if (vu_1 < 0.0001f) {
                asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2da0));
            } else {
                asm volatile("vdiv Q, vf0w, vf1x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf1, vf4, Q");
            }
            asm volatile("sqc2 vf1, (%0)" : : "r"(&sp10));
            temp_v1_2 = (1 - arg2) << 6;
            temp_a0 = temp_v1_2 + arg1;
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"((arg2 << 6) + arg1));
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_a0));
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
            asm volatile("vmul.xyz vf2, vf1, vf3");
            asm volatile("vaddw.x vf4, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf4, vf2z");
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
            temp_t1 = vu_2;
            asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_t1));
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_a0));
            asm volatile("vadda.xyzw ACC, vf0, vf1");
            asm volatile("vmaddx.xyzw vf1, vf3, vf2x");
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_3));
            vu_3;
            asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0x30(%0)" : : "r"(sp));
            s32 vu_4;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
            PxpAdd(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x258), *(arg1 + temp_v1_2), vu_4, temp_t1, arg1 + 0xAC);
        }
    }
}
}
