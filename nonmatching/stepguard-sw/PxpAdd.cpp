typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PxpAdd {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s8 *sp10;                          /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of sp10[4]? */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ char pad30[0xC0];
};                                                  /* size = 0xF0 */
s128 ConvertXfPos(M2C_UNK, s32, s128);              /* extern */
s8 *PvAllocSlotheapImpl(s32);                     /* extern */
M2C_UNK RecalcSwXpMovement(s32, M2C_UNK, s8 **);  /* extern */
extern f32 D_FLT_002BFD30;
extern f32 D_FLT_002BFD34;
void PxpAdd(s32 arg0, s8 *arg1, s8 *arg2, s32 arg3, s128 arg4, s32 arg5, s32 arg6, s32 arg7, f32 fparg0, s8 **arg_sp0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s8 *sp10;
    s128 sp20;
    s32 var_s1;
    s32 var_s1_2;
    s8 *temp_a0;
    s8 *temp_a3;
    s8 *temp_s0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v1;
    s8 *var_v1;
    asm volatile("qmtc2.ni %0, vf2" : : "r"(arg3));
    sp20 = arg4;
    asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
    var_s1 = 0;
    temp_v0 = PvAllocSlotheapImpl(arg0 + 0x3D40);
    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
    sp10 = temp_v0;
    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(temp_v0));
    asm volatile("qmtc2.ni %0, vf1" : : "r"(-fparg0));
    asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    asm volatile("vadda.xyzw ACC, vf0, vf2");
    asm volatile("vmaddx.xyzw vf2, vf3, vf1x");
    asm volatile("sqc2 vf2, 0x50(%0)" : : "r"(temp_v0));
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_1));
    M2C_FIELD(temp_v0, s128 *, 0x80) = vu_1;
    do {
        temp_s0 = sp10 + (var_s1 << 6);
        if (var_s1 == 0) {
            M2C_FIELD(temp_s0, s8 **, 0) = arg1;
        } else {
            M2C_FIELD(temp_s0, s8 **, 0) = arg2;
        }
        temp_v1 = M2C_FIELD(temp_s0, s8 **, 0);
        if (temp_v1 != NULL) {
            M2C_FIELD(temp_s0, s32 *, 4) = (s32) M2C_FIELD(temp_v1, s32 *, 0);
            temp_a0 = M2C_FIELD(temp_v1, s8 **, 4);
            M2C_FIELD(temp_s0, s8 **, 0xC) = temp_a0;
            M2C_FIELD(temp_s0, s32 *, 8) = (s32) M2C_FIELD(M2C_FIELD(temp_a0, s8 **, 0xEC), s32 *, 0x60);
        }
        var_s1 += 1;
        M2C_FIELD(temp_s0, s128 *, 0x20) = ConvertXfPos(0, M2C_FIELD(temp_s0, s32 *, 4), M2C_FIELD(temp_s0, s128 *, 0x10));
    } while (var_s1 < 2);
    var_s1_2 = 0;
    M2C_FIELD(sp10, s32 *, 0xA4) = arg7;
    M2C_FIELD(sp10, f32 *, 0x90) = fparg0;
    M2C_FIELD(sp10, s32 *, 0x9C) = arg5;
    M2C_FIELD(sp10, f32 *, 0x94) = (f32) D_FLT_002BFD30;
    M2C_FIELD(sp10, f32 *, 0x98) = (f32) D_FLT_002BFD34;
    M2C_FIELD(sp10, s32 *, 0xA0) = arg6;
    do {
        temp_a3 = M2C_FIELD((sp10 + (var_s1_2 << 6)), s8 **, 0xC);
        if (temp_a3 != NULL) {
            temp_v0_2 = M2C_FIELD(temp_a3, s8 **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *, s32, s8 *), 0x1BC)(temp_a3 + M2C_FIELD(temp_v0_2, s16 *, 0x1B8), sp10, var_s1_2, temp_a3);
        }
        var_s1_2 += 1;
    } while (var_s1_2 < 2);
    RecalcSwXpMovement(arg0, 1, &sp10);
    var_v1 = sp10;
    if (M2C_FIELD(var_v1, s8 **, 0xAC) != NULL) {
        var_v1 = M2C_FIELD(var_v1, s8 **, 0xAC);
loop_13:
        if (M2C_FIELD(var_v1, s8 **, 0xAC) != NULL) {
            var_v1 = M2C_FIELD(var_v1, s8 **, 0xAC);
            goto loop_13;
        }
    }
    M2C_FIELD(var_v1, s8 **, 0xAC) = (s8 *) *arg_sp0;
    *arg_sp0 = sp10;
}
}
