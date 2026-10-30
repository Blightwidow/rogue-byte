typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C0B50 {
    /* 0x000 */ char pad0[0x200];
    /* 0x200 */ s128 sp200;                         /* inferred */
    /* 0x210 */ s128 sp210;                         /* inferred */
    /* 0x220 */ s32 sp220;                          /* inferred */
    /* 0x224 */ s32 sp224;                          /* inferred */
    /* 0x228 */ s32 sp228;                          /* inferred */
    /* 0x22C */ char pad22C[4];
    /* 0x230 */ M2C_UNK sp230;                      /* inferred */
    /* 0x230 */ char pad230[0x10];
    /* 0x240 */ M2C_UNK sp240;                      /* inferred */
    /* 0x240 */ char pad240[0x50];
    /* 0x290 */ s128 sp290;                         /* inferred */
    /* 0x2A0 */ f32 sp2A0;                          /* inferred */
    /* 0x2A4 */ char pad2A4[0xAC];
};                                                  /* size = 0x350 */
s32 ClosestPointOnSegment(M2C_UNK, s128, s128, s128 *);
s32 ClsgClipEdgeToPathzone(s32, s128, s128, M2C_UNK);
s32 CobstacleFindPathzoneBox(s32, M2C_UNK, M2C_UNK, M2C_UNK);
s32 ConvertAloPos(s8 *, M2C_UNK, s128);
s32 FFindPathzoneClosestPoint(s32, s128, s128 *, M2C_UNK);
s32 FObstacleContainsPos(s8 *, M2C_UNK);
s32 PcgtPointInCgQuick(s32, M2C_UNK);
s32 PosClosestOnCgt(s32, M2C_UNK);
s32 func_001C0B50(s32 arg0, s32 arg1, s128 *arg2) {
    s32 unksp208;
    s32 unksp218;
    s8 sp[0x350] __attribute__((aligned(16)));
    s128 sp200;
    s128 sp210;
    s32 sp220;                                      /* compiler-managed */
    s32 sp224;
    s32 sp228;
    M2C_UNK sp230;
    M2C_UNK sp240;
    s128 sp290;
    f32 sp2A0;
    M2C_UNK *var_s0_3;
    M2C_UNK temp_s1;
    f32 temp_v1;
    f32 var_f20;
    s128 temp_s2;
    s32 temp_s4;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s3;
    s8 **var_s0;
    s8 *var_s5;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg1));
    temp_s1 = vu_1;
    temp_v0 = PcgtPointInCgQuick(arg0 + 0xE0, 1);
    if (temp_v0 == 0) {
        return 0;
    }
    var_s5 = NULL;
    s64 vu_2;
    asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s1));
    s64 vu_3;
    asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(PosClosestOnCgt(temp_v0, vu_2)));
    temp_s2 = vu_3;
    var_s3 = 0;
    s64 vu_4;
    asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_s2));
    s64 vu_5;
    asm volatile("por %0, %1, %2" : "=r"(vu_5) : "r"(0), "r"(temp_s2));
    temp_s4 = CobstacleFindPathzoneBox(arg0, 0, vu_5, vu_4);
    var_s0 = (s8 **)(sp);
loop_5:
    if (var_s3 < temp_s4) {
        s64 vu_6;
        asm volatile("por %0, %1, %2" : "=r"(vu_6) : "r"(0), "r"(temp_s1));
        if (FObstacleContainsPos(*var_s0, vu_6) == 0) {
            var_s0 += 4;
            var_s3 += 1;
            goto loop_5;
        }
        var_s5 = *var_s0;
    }
    if (var_s5 != NULL) {
        sp228 = 0;
        sp224 = 0;
        sp220 = 0;
        var_f20 = 3.4028235e38f;
        var_s0_2 = 1;
        s64 vu_7;
        asm volatile("pextuw %0, %1, %2" : "=r"(vu_7) : "r"(0), "r"(temp_s2));
        temp_v1 = vu_7;
        sp200 = ConvertAloPos(var_s5, 0, *M2C_FIELD(var_s5, s128 **, 0xF4));
        unksp208 = temp_v1;
        if (M2C_FIELD(var_s5, s32 *, 0xE8) > 1) {
            do {
                sp210 = ConvertAloPos(var_s5, 0, *((var_s0_2 * 0x10) + M2C_FIELD(var_s5, s128 **, 0xF4)));
                unksp218 = temp_v1;
                temp_v0_2 = ClsgClipEdgeToPathzone(arg0, sp200, sp210, 1);
                var_s0_3 = &sp240;
                if (temp_v0_2 > 0) {
                    var_s1 = temp_v0_2;
                    do {
                        s64 vu_8;
                        asm volatile("por %0, %1, %2" : "=r"(vu_8) : "r"(0), "r"(temp_s2));
                        ClosestPointOnSegment(vu_8, M2C_FIELD(var_s0_3, s128 *, -0x10), M2C_FIELD(var_s0_3, s128 *, 0), &sp290);
                        if (sp2A0 < var_f20) {
                            var_f20 = sp2A0;
                            sp220 = sp290;
                        }
                        var_s1 -= 1;
                        var_s0_3 += 0x60;
                    } while (var_s1 != 0);
                }
                var_s0_2 += 1;
                sp200 = sp210;
            } while (var_s0_2 < M2C_FIELD(var_s5, s32 *, 0xE8));
        }
        FFindPathzoneClosestPoint(arg0, sp220, arg2, 0);
    } else {
        *arg2 = temp_s2;
    }
    return 1;
}
}
