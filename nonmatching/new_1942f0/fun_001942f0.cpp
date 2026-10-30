typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001942F0 {
    /* 0x00 */ f32 sp0;                             /* inferred */
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[8];                        /* maybe part of sp4[3]? */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ char pad20[0x30];
};                                                  /* size = 0x50 */
#define sp0 (*(f32 *)(sp + 0x00))
#define sp4 (*(f32 *)(sp + 0x04))
M2C_UNK AddSafePointOnGeom(s8 *, s32, s128, s8 *); /* extern */
M2C_UNK AddSafePointOnMember(s32, s32, f32);        /* extern */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
s128 PosLoWorld(s8 *);                            /* extern */
f32 atan2f(f32, f32);                               /* extern */
void func_001942F0(s8 *arg0) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s128 sp10;
    f32 var_f12;
    f32 var_f20;
    s32 temp_v1;
    s8 *temp_a1;
    s8 *temp_v1_2;
    temp_v1 = M2C_FIELD(arg0, s32 *, 8);
    switch (temp_v1) {                              /* irregular */
    case 0:
block_17:
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x14), 0xC) == 0) {
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x14), 0x26) == 0) {
                if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0x14), 0x22) == 0) {
                    var_f20 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), f32 *, 0x184);
                    goto block_33;
                }
                temp_v1_2 = M2C_FIELD(arg0, s8 **, 0x14);
                if (M2C_FIELD(temp_v1_2, s32 *, 0xEC) == 0) {
                    var_f20 = M2C_FIELD(temp_v1_2, f32 *, 0x10C);
block_33:
                    sp10 = PosLoWorld(M2C_FIELD(arg0, s8 **, 0));
                    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x14))));
                    asm volatile("vsub.xyzw vf1, vf2, vf3");
                    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                    var_f12 = atan2f(sp4, sp0) * var_f20;
                    goto block_34;
                }
            } else if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0xEC) == 0) {
                var_f12 = 0.0f;
                goto block_34;
            }
        } else if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0x19C) == 0) {
            var_f12 = M2C_FIELD(arg0, f32 *, 0x20);
block_34:
            AddSafePointOnMember((int)(M2C_FIELD(arg0, s8 **, 0) + 0x9E0), M2C_FIELD(arg0, s32 *, 0x18), var_f12);
        }
        break;
    case 13:
        goto block_17;
    case 3:
        if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0x19C) == 0) {
            var_f12 = M2C_FIELD(arg0, f32 *, 0x20);
            goto block_34;
        }
        break;
    case 4:
        if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0xEC) == 0) {
            var_f12 = 0.0f;
            goto block_34;
        }
        break;
    default:
        temp_a1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0x208);
        if ((temp_a1 != NULL) && (M2C_FIELD(temp_a1, f32 *, 0x88) > 0.7f)) {
            if (!(M2C_FIELD(M2C_FIELD(temp_a1, s8 **, 0x4C), s64 *, 0x148) & 0x20000000)) {
                if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x108C) == 0) {
                    AddSafePointOnGeom(M2C_FIELD(arg0, s8 **, 0) + 0x9E0, M2C_FIELD(temp_a1, s32 *, 0x40), M2C_FIELD(temp_a1, s128 *, 0x60), M2C_FIELD(arg0, s8 **, 0));
                }
            }
        }
        break;
    }
}
}
