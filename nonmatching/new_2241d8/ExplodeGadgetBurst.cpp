typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ExplodeGadgetBurst {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0x10];
    /* 0x020 */ M2C_UNK sp20;                       /* inferred */
    /* 0x020 */ char pad20[0xC00];
    /* 0xC20 */ s32 spC20;                          /* inferred */
    /* 0xC24 */ s32 spC24;                          /* inferred */
    /* 0xC28 */ s32 spC28;                          /* inferred */
    /* 0xC2C */ s32 spC2C;                          /* inferred */
    /* 0xC30 */ s32 spC30;                          /* inferred */
    /* 0xC34 */ char padC34[0xC];                   /* maybe part of spC30[4]? */
    /* 0xC40 */ s128 spC40;                         /* inferred */
    /* 0xC50 */ char padC50[0xB0];
};                                                  /* size = 0xD00 */
void AddGadgetBurstWkr(s8 *, s32, s32, s128, s32 *, M2C_UNK *);
s32 CStackFrame_Construct(M2C_UNK *);
void CStackFrame_Destructor(M2C_UNK *, M2C_UNK);
void IntersectSwBoundingSphere(M2C_UNK *, s128, M2C_UNK *, s32, f32);
s32 LimitVectorLength__FP6VECTORfT0(M2C_UNK, f32);
s32 PaloAbsorbWkr(M2C_UNK *);
s32 *PhitfxSpawn(s32, s128, s8 *);
s32 SetVectorSphere__FP6VECTORfff(f32, f32, f32);
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002C4368;
extern M2C_UNK D_FLT_002C4338;
extern M2C_UNK FFilterOxaBasic;
void ExplodeGadgetBurst(s8 *arg0, s32 arg1, s32 arg2, s128 arg3, f32 fparg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    M2C_UNK sp10;
    M2C_UNK sp20;
    s32 spC20;
    s32 spC24;
    s32 spC28;
    s32 spC2C;
    s32 spC30;
    s128 spC40;
    M2C_UNK *var_s0_2;
    f32 temp_f12;
    s32 **temp_a0;
    s32 *temp_s0;
    s32 temp_s1;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    u32 var_v1;
    spC40 = arg3;
    spC30 = arg2;
    spC2C = arg1;
    CStackFrame_Construct(&sp10);
    IntersectSwBoundingSphere(&B_003DD490, spC40, &FFilterOxaBasic, M2C_FIELD(arg0, s32 *, 0xEC), fparg0);
    spC28 = 0;
    var_v1 = 0;
    do {
        temp_s1 = var_v1 * 4;
        var_s2 = 0;
        if (*(temp_s1 + &D_002C4368) > 0) {
            do {
                temp_s0 = temp_s1 + &D_002C4368;
                temp_f12 = (2.0f * (f32) var_s2 * 3.1415927f) / (f32) *temp_s0;
                var_s2 += 1;
                asm volatile("qmtc2.ni %0, vf2" : : "r"(SetVectorSphere__FP6VECTORfff(temp_f12, *(temp_s1 + &D_FLT_002C4338), fparg0)));
                asm volatile("lqc2 vf1, 0xc40(%0)" : : "r"(sp));
                asm volatile("vadd.xyzw vf1, vf1, vf2");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                vu_1;
                AddGadgetBurstWkr(arg0, spC2C, spC30, spC40, &spC28, &sp20);
            } while (var_s2 < *temp_s0);
        }
        var_v1 += 1;
    } while (var_v1 < 0xBU);
    var_s0 = 0;
    if (spC20 > 0) {
        do {
            asm volatile("lqc2 vf2, 0xc40(%0)" : : "r"(sp));
            temp_a0 = (s32 **)((var_s0 * 4) + spC24);
            var_s0 += 1;
            asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(**temp_a0));
            asm volatile("vsub.xyzw vf2, vf1, vf2");
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(LimitVectorLength__FP6VECTORfT0(vu_2, fparg0)));
            asm volatile("lqc2 vf1, 0xc40(%0)" : : "r"(sp));
            asm volatile("vadd.xyzw vf1, vf1, vf2");
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
            vu_3;
            AddGadgetBurstWkr(arg0, spC2C, spC30, spC40, &spC28, &sp20);
        } while (var_s0 < spC20);
    }
    var_s1 = 0;
    if (spC28 > 0) {
        var_s0_2 = &sp20;
        do {
            var_s1 += 1;
            PaloAbsorbWkr(var_s0_2);
            var_s0_2 += 0x60;
        } while (var_s1 < spC28);
    }
    M2C_FIELD(PhitfxSpawn(M2C_FIELD(&B_003DD490, s32 *, 0x402C), spC40, arg0), s32 *, 0x54) = 1;
    CStackFrame_Destructor(&sp10, 2);
}
}
