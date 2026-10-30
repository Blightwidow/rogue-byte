typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FMatchJtXmg {
    /* 0x000 */ char pad0[0x28];
    /* 0x028 */ f32 sp28;                           /* inferred */
    /* 0x02C */ char pad2C[0x14];                   /* maybe part of sp28[6]? */
    /* 0x040 */ f32 sp40;                           /* inferred */
    /* 0x044 */ char pad44[0x1C];                   /* maybe part of sp40[8]? */
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
#define sp28 (*(f32 *)(sp + 0x028))
#define sp40 (*(f32 *)(sp + 0x040))
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s128 ConvertAloPos(s8 *, s8 *, s128);           /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, s128, s32); /* extern */
M2C_UNK SetActadjOffset(s32, s128);                 /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK FFilterOxa;
extern M2C_UNK g_2a2dc0;
extern s128 g_2a2dd0;
s32 FMatchJtXmg(s8 *arg0, s8 *arg1, s32 arg2) {
    s8 sp[0x80] __attribute__((aligned(16)));
    M2C_UNK sp60;
    s32 sp80;
    s32 sp84;
    s128 sp90;
    s128 spA0;
    s128 spB0;
    s128 temp_v0;
    if (M2C_FIELD(arg1, s32 *, 4) != 0) {
        CStackFrame_Construct(&sp60);
        sp90 = ConvertAloPos(arg0, NULL, M2C_FIELD(arg1, s128 *, 0x30));
        spA0 = ConvertAloPos(arg0, NULL, M2C_FIELD(arg1, s128 *, 0x40));
        temp_v0 = ConvertAloPos(arg0, NULL, M2C_FIELD(arg1, s128 *, 0x50));
        spB0 = temp_v0;
        asm volatile("qmtc2.ni %0, vf3" : : "r"(temp_v0));
        asm volatile("lqc2 vf2, 0xa0(%0)" : : "r"(sp));
        asm volatile("vmini.xyz vf1, vf2, vf3");
        asm volatile("lqc2 vf4, 0x90(%0)" : : "r"(sp));
        asm volatile("vmini.xyz vf4, vf4, vf1");
        asm volatile("vmax.xyz vf2, vf2, vf3");
        asm volatile("lqc2 vf1, 0x90(%0)" : : "r"(sp));
        asm volatile("vmax.xyz vf1, vf1, vf2");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_2));
        bevy_camera_follow_push_out(&B_003DD490, vu_2, vu_1, &FFilterOxa);
        if ((PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp90, spA0, sp80) != 0) || (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, spA0, spB0, sp80) != 0)) {
            if (sp40 != 0.0f) {
                if (sp28 > 0.7f) {
                    asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                    asm volatile("lqc2 vf2, (%0)" : : "r"(&g_2a2dc0));
                    asm volatile("vsub.xyzw vf1, vf1, vf2");
                    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                    s32 vu_3;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(ConvertAloPos(NULL, arg0, vu_3)));
                    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(arg1));
                    asm volatile("vsub.xyzw vf3, vf2, vf1");
                    asm volatile("sqc2 vf2, 0x70(%0)" : : "r"(sp));
                    s32 vu_4;
                    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_4));
                    SetActadjOffset(arg2, vu_4);
                    goto block_10;
                }
                goto block_6;
            }
            goto block_7;
        }
block_6:
block_7:
        SetActadjOffset(arg2, g_2a2dd0);
        if ((M2C_FIELD(arg0, s32 *, 0x208) != 0) && (M2C_FIELD(arg1, f32 *, 0x48) < -85.0f)) {
            CStackFrame_Destructor(&sp60, 2);
            return 0;
        }
block_10:
        CStackFrame_Destructor(&sp60, 2);
        goto block_11;
    }
block_11:
    return 1;
}
}
