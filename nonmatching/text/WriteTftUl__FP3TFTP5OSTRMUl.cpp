typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_WriteTftUl__FP3TFTP5OSTRMUl {
    /* 0x000 */ char pad0[0x50];
    /* 0x050 */ s8 sp50;                            /* inferred */
    /* 0x051 */ char pad51[1];
    /* 0x052 */ u8 sp52;                            /* inferred */
    /* 0x053 */ char pad53[0xD];                    /* maybe part of sp52[0xE]? */
    /* 0x060 */ s8 sp60;                            /* inferred */
    /* 0x061 */ char pad61[0xF];                    /* maybe part of sp60[0x10]? */
    /* 0x070 */ s64 sp70;                           /* inferred */
    /* 0x078 */ char pad78[0x98];
};                                                  /* size = 0x110 */
s32 CbWrite__5OSTRMPvi(s32, s8 *, s32);             /* extern */
s32 CchAchFromUl__FPciUlUi(s8 *, M2C_UNK, s64, s32); /* extern */
s32 FNegTftUl__FP3TFTP2UL(s8 *, s64 *);           /* extern */
s32 UnRadixFromChConversion__Fc(u8);                /* extern */
M2C_UNK UpperizePchz__FPc(s8 *);                    /* extern */
s32 strlen(...);                             /* extern */
extern u16 RO_002A9460;
extern u16 RO_002A9468;
extern u16 RO_002A9470;
extern u16 RO_002A9478;
extern u16 RO_002A9480;
extern u16 RO_002A9488;
void WriteTftUl__FP3TFTP5OSTRMUl(s8 *arg0, s32 arg1, s64 arg2) {
    s8 sp[0x70] __attribute__((aligned(16)));
    s8 sp50;                                        /* compiler-managed */
    u8 sp52;
    s8 sp60;
    s64 sp70;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_s5;
    s32 var_s6;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    u16 *var_v1_2;
    u16 var_a0;
    u16 var_v1;
    u8 temp_v0;
    sp70 = arg2;
    if ((M2C_FIELD(arg0, s32 *, 0x14) != 0) || (M2C_FIELD(arg0, s32 *, 0x1C) != 0)) {
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) != 0) {
        if (sp70 == 0) {
            var_s6 = 0;
            var_s4 = 0;
            var_s5 = 0;
        } else {
            goto block_7;
        }
    } else {
block_7:
        temp_a1 = FNegTftUl__FP3TFTP2UL(arg0, &sp70);
        var_s4_2 = M2C_FIELD(arg0, s32 *, 0x1C);
        temp_v0 = M2C_FIELD(arg0, u8 *, 0x2C);
        sp50 = 0;
        switch (temp_v0) {
        case 0x64:
        case 0x69:
            if (temp_a1 != 0) {
                var_v1 = RO_002A9460;
                goto block_15;
            }
            if (M2C_FIELD(arg0, s32 *, 4) != 0) {
                var_v1 = RO_002A9468;
                goto block_15;
            }
            if (M2C_FIELD(arg0, s32 *, 8) != 0) {
                var_v1 = RO_002A9470;
block_15:
                sp50 = var_v1;
            }
            var_s4_2 -= strlen(arg0, arg1, (u16 *)(&sp50), temp_a1);
            break;
        case 0x62:
            if (M2C_FIELD(arg0, s32 *, 0xC) != 0) {
                var_v1_2 = &RO_002A9478;
                var_a0 = RO_002A9478;
block_23:
                sp50 = var_a0;
                sp52 = M2C_FIELD(var_v1_2, u8 *, 2);
            }
            break;
        case 0x6F:
            if (M2C_FIELD(arg0, s32 *, 0xC) != 0) {
                sp50 = RO_002A9480;
            }
            break;
        case 0x78:
            if (M2C_FIELD(arg0, s32 *, 0xC) != 0) {
                var_v1_2 = &RO_002A9488;
                var_a0 = RO_002A9488;
                goto block_23;
            }
            break;
        }
        var_s6 = strlen(arg0, arg1, (u16 *) &sp50);
        var_s5 = CchAchFromUl__FPciUlUi(sp, 0x40, sp70, UnRadixFromChConversion__Fc(M2C_FIELD(arg0, u8 *, 0x2C)));
        temp_s4 = var_s4_2 - var_s5;
        var_s4 = (temp_s4 <= -1) ? 0 : temp_s4;
    }
    sp[var_s5] = 0;
    if (M2C_FIELD(arg0, s32 *, 0x30) != 0) {
        UpperizePchz__FPc((s8 *) &sp50);
        UpperizePchz__FPc(sp);
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x18);
    temp_v1 = var_s6 + var_s4 + var_s5;
    var_a1 = 0;
    var_s7 = 0;
    if (temp_v1 < temp_a0) {
        temp_v1_2 = temp_a0 - temp_v1;
        if (M2C_FIELD(arg0, s32 *, 0) != 0) {
            var_s7 = temp_v1_2;
        } else if (M2C_FIELD(arg0, s32 *, 0x10) == 0) {
            var_a1 = temp_v1_2;
        } else if (var_s5 == 0) {
            var_a1 = temp_v1_2;
        } else {
            var_s4 += temp_v1_2;
        }
    }
    var_s0 = var_a1;
    sp60 = 0x20;
    var_v0 = var_s0;
loop_38:
    var_s0 -= 1;
    if (var_v0 > 0) {
        var_v0 = var_s0;
        if (CbWrite__5OSTRMPvi(arg1, &sp60, 1) == 1) {
            goto loop_38;
        }
    }
    var_s0_2 = var_s4;
    CbWrite__5OSTRMPvi(arg1, (s8 *) &sp50, var_s6);
    sp60 = 0x30;
    var_v0_2 = var_s0_2;
loop_41:
    var_s0_2 -= 1;
    if (var_v0_2 > 0) {
        var_v0_2 = var_s0_2;
        if (CbWrite__5OSTRMPvi(arg1, &sp60, 1) == 1) {
            goto loop_41;
        }
    }
    var_s0_3 = var_s7;
    CbWrite__5OSTRMPvi(arg1, sp, var_s5);
    sp60 = 0x20;
    var_v0_3 = var_s0_3;
loop_44:
    var_s0_3 -= 1;
    if (var_v0_3 > 0) {
        var_v0_3 = var_s0_3;
        if (CbWrite__5OSTRMPvi(arg1, &sp60, 1) == 1) {
            goto loop_44;
        }
    }
}
}
