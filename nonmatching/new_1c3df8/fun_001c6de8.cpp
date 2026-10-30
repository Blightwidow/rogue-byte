typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C6DE8 {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ char pad20[8];
    /* 0x028 */ f32 sp28;                           /* inferred */
    /* 0x02C */ char pad2C[0xC];                    /* maybe part of sp28[4]? */
    /* 0x038 */ f32 sp38;                           /* inferred */
    /* 0x03C */ char pad3C[4];
    /* 0x040 */ f32 sp40;                           /* inferred */
    /* 0x044 */ f32 sp44;                           /* inferred */
    /* 0x048 */ char pad48[0x18];                   /* maybe part of sp44[7]? */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x20];
    /* 0x080 */ s32 sp80;                           /* inferred */
    /* 0x084 */ s32 sp84;                           /* inferred */
    /* 0x088 */ char pad88[8];                      /* maybe part of sp84[3]? */
    /* 0x090 */ s128 sp90;                          /* inferred */
    /* 0x0A0 */ s128 spA0;                          /* inferred */
    /* 0x0B0 */ s128 spB0;                          /* inferred */
    /* 0x0C0 */ char padC0[0x50];
};                                                  /* size = 0x110 */
#define sp0 (*(s128 *)(sp + 0x000))
#define sp10 (*(s128 *)(sp + 0x010))
#define sp28 (*(f32 *)(sp + 0x028))
#define sp38 (*(f32 *)(sp + 0x038))
#define sp40 (*(f32 *)(sp + 0x040))
#define sp44 (*(f32 *)(sp + 0x044))
#define spA0 (*(s128 *)(sp + 0x0A0))
#define spB0 (*(s128 *)(sp + 0x0B0))
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, s128, s32); /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, s128, s128, M2C_UNK *); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK FFilterDprizeObjects;
extern M2C_UNK g_2a2dc0;
s32 func_001C6DE8(s128 arg0, s32 arg1, s32 arg2, s128 *arg3, f32 fparg0, f32 fparg1, f32 fparg2) {
    s8 sp[0x80] __attribute__((aligned(16)));
    M2C_UNK sp60;
    s32 sp80;
    s32 sp84;
    s128 sp90;
    s128 var_v0;
    sp90 = arg0;
    sp84 = arg2;
    sp80 = arg1;
    CStackFrame_Construct(&sp60);
    asm volatile("qmtc2.ni %0, vf2" : : "r"(fparg1));
    asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
    asm volatile("qmtc2.ni %0, vf3" : : "r"(fparg0));
    asm volatile("lqc2 vf4, 0x90(%0)" : : "r"(sp));
    asm volatile("vadda.xyzw ACC, vf0, vf4");
    asm volatile("vmaddx.xyzw vf4, vf1, vf3x");
    asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(sp));
    asm volatile("sqc2 vf4, 0xb0(%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x90(%0)" : : "r"(sp));
    asm volatile("vadda.xyzw ACC, vf0, vf4");
    asm volatile("vmaddx.xyzw vf4, vf1, vf2x");
    asm volatile("sqc2 vf4, 0xa0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x70(%0)" : : "r"(sp));
    if (sp84 == 0) {
        bevy_camera_follow_push_out(&B_003DD490, sp90, spA0, &FFilterDprizeObjects);
    }
    if (fparg1 > 0.0f) {
        if ((PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp90, spA0, sp80) != 0) && (sp40 == 0.0f)) {
            if (sp44 != 1.0f) {
                var_v0 = sp10;
                if (!(sp38 < fparg2)) {
                    goto block_17;
                }
            }
            goto block_15;
        }
        goto block_9;
    }
block_9:
    if (fparg0 < 0.0f) {
        if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp90, spB0, sp80) != 0) {
            if (sp40 != 0.0f) {
                var_v0 = sp0;
                if (!(sp28 < fparg2)) {
                    goto block_17;
                }
            }
            goto block_15;
        }
block_15:
        CStackFrame_Destructor(&sp60, 2);
        return 0;
    }
    var_v0 = sp90;
block_17:
    *arg3 = var_v0;
    CStackFrame_Destructor(&sp60, 2);
    return 1;
}
}
