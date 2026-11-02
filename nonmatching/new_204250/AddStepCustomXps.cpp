typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AddStepCustomXps {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ M2C_UNK sp10;                        /* inferred */
    /* 0x10 */ char pad10[0x28];
    /* 0x38 */ f32 sp38;                            /* inferred */
    /* 0x3C */ char pad3C[0x14];                    /* maybe part of sp38[6]? */
    /* 0x50 */ f32 sp50;                            /* inferred */
    /* 0x54 */ char pad54[4];
    /* 0x58 */ s32 sp58;                            /* inferred */
    /* 0x5C */ s32 sp5C;                            /* inferred */
    /* 0x60 */ char pad60[0x70];
};                                                  /* size = 0xD0 */
#define sp38 (*(f32 *)(sp + 0x38))
#define sp50 (*(f32 *)(sp + 0x50))
#define sp58 (*(s32 *)(sp + 0x58))
#define sp5C (*(s32 *)(sp + 0x5C))
s32 ClsgClipEdgeToObjectPruned(s8 *, s32, M2C_UNK, s128, M2C_UNK, M2C_UNK *); /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
M2C_UNK PxpAdd(M2C_UNK *, s32, s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 bevy_physics_motor_2048c8(s8 *, s128, s8 *, s32); /* extern */
M2C_UNK func_001F5990();                            /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK g_2a2dc0;
void AddStepCustomXps(s8 *arg0, s8 *arg1, s32 arg4, s32 arg5) {
    s8 sp[0x40] __attribute__((aligned(16)));
    M2C_UNK sp10;
    M2C_UNK temp_a2;
    s128 *var_a3;
    s32 temp_v0;
    s8 *temp_v1;
    func_001F5990();
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    temp_v0 = M2C_FIELD(temp_v1, s32 (**)(s8 *), 0x2AC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x2A8));
    if ((temp_v0 & 1) && (FIsBasicDerivedFrom(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg1, s8 **, 4), s8 **, 0xEC), s32 *, 0x60), 0x33) == 0)) {
        s64 vu_1;
        asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(arg0)));
        temp_a2 = vu_1;
        if (!(temp_v0 & 2)) {
            var_a3 = M2C_FIELD(arg0, s128 **, 0x218);
        } else {
            var_a3 = M2C_FIELD(arg0, s128 **, 0x21C);
        }
        if ((ClsgClipEdgeToObjectPruned(arg1, arg4, temp_a2, *var_a3, 1, &sp10) > 0) && (sp50 > 0.0f)) {
            asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(sp));
            if (!(temp_v0 & 8)) {
                if (!(sp38 > 0.7f)) {
                    if (sp58 == 0) {
                        if (bevy_physics_motor_2048c8(arg0, *M2C_FIELD(arg0, s128 **, 0x218), arg1, sp5C) != 0) {
                            goto block_12;
                        }
                        asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(sp));
                    }
                } else {
block_12:
                    asm volatile("lqc2 vf4, (%0)" : : "r"(&g_2a2dc0));
                }
            }
            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, (%0)" : : "r"(M2C_FIELD(arg0, s128 **, 0x218)));
            asm volatile("vsub.xyzw vf1, vf2, vf1");
            asm volatile("vmul.xyz vf1, vf1, vf4");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf3, vf1z");
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_3));
            s32 vu_4;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_4));
            PxpAdd(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x258), arg1, vu_4, vu_3, 0xE, 0, 0, vu_2, arg5);
        }
    }
}
}
