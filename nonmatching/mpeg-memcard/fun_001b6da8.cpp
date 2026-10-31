typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001B6DA8 {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s8 *sp10;                         /* inferred */
    /* 0x014 */ s32 sp14;                           /* inferred */
    /* 0x018 */ s32 sp18;                           /* inferred */
    /* 0x01C */ s32 sp1C;                           /* inferred */
    /* 0x020 */ s32 sp20;                           /* inferred */
    /* 0x024 */ char pad24[0xC];                    /* maybe part of sp20[4]? */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ char pad50[0xC0];
};                                                  /* size = 0x110 */
void FreeSwMqList__FP2SWP2MQ(M2C_UNK *, s8 *);
s32 PaloAbsorbWkr(s8 **);
s32 PaloFindWkrAbsorber(s32, M2C_UNK);
s32 *PeaFindAsegLabel(s32, M2C_UNK);
void RetractAsega(s8 *, M2C_UNK);
void SeekAsega(s8 *, M2C_UNK, f32, M2C_UNK);
s32 memset(s8 **, M2C_UNK, M2C_UNK);
extern M2C_UNK B_003DD490;
extern s32 D_002C09A8;
extern M2C_UNK g_2a2dc0;
extern f32 g_2dded0;
void func_001B6DA8(s8 *arg0, s32 arg1) {
    s8 sp[0x70] __attribute__((aligned(16)));
#define sp10 (*(s8 **)(sp + 0x10))
#define sp14 (*(s32 *)(sp + 0x14))
#define sp18 (*(s32 *)(sp + 0x18))
#define sp1C (*(s32 *)(sp + 0x1C))
#define sp20 (*(s32 *)(sp + 0x20))
#define sp30 (*(s128 *)(sp + 0x30))
#define sp40 (*(s128 *)(sp + 0x40))
    f32 *temp_v0_6;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 var_v0;
    s8 *temp_a1;
    s8 *temp_s3;
    s8 *temp_s4;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v1;
    s8 *var_s1;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x13D8);
    if (temp_v0 != arg1) {
        if (temp_v0 == -1) {
            temp_v0_2 = arg0 + 0x190;
            M2C_FIELD(temp_v0_2, s32 *, 8) = 0;
            M2C_FIELD(temp_v0_2, s32 *, 4) = 0;
            M2C_FIELD(arg0, s32 *, 0x190) = 0;
        }
        M2C_FIELD(arg0, s32 *, 0x13D8) = arg1;
        M2C_FIELD(arg0, f32 *, 0x13DC) = (f32) g_2dded0;
        switch (arg1) {                             /* irregular */
        case 0:
            break;
        case -1:
            FreeSwMqList__FP2SWP2MQ(&B_003DD490, M2C_FIELD(arg0, s8 **, 0x13E4));
            M2C_FIELD(arg0, s8 **, 0x13E4) = NULL;
            break;
        case 1:
            temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
            asm volatile("qmtc2.ni %0, vf3" : : "r"(M2C_FIELD(temp_v1, s32 (**)(s8 *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108))));
            temp_a1 = M2C_FIELD(arg0, s8 **, 0xC);
            asm volatile("lqc2 vf2, (%0)" : : "r"(&g_2a2dc0));
            asm volatile("vmul.xyz vf1, vf3, vf2");
            asm volatile("vaddw.x vf4, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf4, vf1z");
            asm volatile("vmulx.xyzw vf1, vf2, vf1x");
            asm volatile("qmtc2.ni %0, vf4" : : "r"(D_002C09A8));
            asm volatile("vsub.xyzw vf3, vf3, vf1");
            asm volatile("vadda.xyzw ACC, vf0, vf3");
            asm volatile("vmaddx.xyzw vf1, vf2, vf4x");
            asm volatile("sqc2 vf4, (%0)" : : "r"(sp));
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
            M2C_FIELD(temp_a1, M2C_UNK (**)(s8 *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_a1, s16 *, 0x118), vu_1);
            M2C_FIELD(arg0, f32 *, 0x131C) = (f32) g_2dded0;
            break;
        case 2:
            temp_v0_3 = arg0 + 0x190;
            M2C_FIELD(temp_v0_3, s32 *, 8) = 0;
            M2C_FIELD(temp_v0_3, s32 *, 4) = 0;
            M2C_FIELD(arg0, s32 *, 0x190) = 0;
            var_s1 = M2C_FIELD(arg0, s8 **, 0x13E4);
            if (var_s1 != NULL) {
                var_v0 = M2C_FIELD(var_s1, s32 *, 8);
loop_14:
                temp_v0_4 = var_v0 != (s32) arg0;
                temp_s3 = var_s1 + ((1 - temp_v0_4) << 6);
                temp_s4 = var_s1 + (temp_v0_4 << 6);
                temp_v0_5 = PaloFindWkrAbsorber(M2C_FIELD(temp_s3, s32 *, 0xC), 4);
                if (temp_v0_5 != 0) {
                    memset(&sp10, 0, 0x60);
                    sp10 = arg0;
                    sp18 = temp_v0_5;
                    sp14 = M2C_FIELD(temp_s4, s32 *, 0);
                    sp1C = 4;
                    sp20 = -0x14;
                    sp30 = M2C_FIELD(temp_s3, s128 *, 0x10);
                    sp40 = M2C_FIELD(temp_s4, s128 *, 0x30);
                    PaloAbsorbWkr(&sp10);
                }
                var_s1 = M2C_FIELD(var_s1, s8 **, 0xAC);
                if (var_s1 != NULL) {
                    var_v0 = M2C_FIELD(var_s1, s32 *, 8);
                    goto loop_14;
                }
            }
            FreeSwMqList__FP2SWP2MQ(&B_003DD490, M2C_FIELD(arg0, s8 **, 0x13E4));
            M2C_FIELD(arg0, s8 **, 0x13E4) = NULL;
            temp_v0_6 = (f32 *)PeaFindAsegLabel(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x1030), s32 *, 0x14), 0x1A5);
            if (temp_v0_6 != NULL) {
                SeekAsega(M2C_FIELD(arg0, s8 **, 0x1030), 0, *temp_v0_6, 0x3F800000);
            } else {
                RetractAsega(M2C_FIELD(arg0, s8 **, 0x1030), 0);
            }
            break;
        }
    }
}
}
