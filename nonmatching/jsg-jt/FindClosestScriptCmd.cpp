typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FindClosestScriptCmd {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ M2C_UNK32 sp8;                       /* inferred */
    /* 0x0C */ char padC[4];
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ M2C_UNK32 sp20;                      /* inferred */
    /* 0x24 */ char pad24[0xC];                     /* maybe part of sp20[4]? */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ char pad40[0x70];
};                                                  /* size = 0xB0 */
M2C_UNK FindCrvClosestPointAll(s8 *, s128, M2C_UNK, s128 *); /* extern */
M2C_UNK FindCrvClosestPointFromS(s8 *, s128, M2C_UNK, s128 *, M2C_UNK32); /* extern */
M2C_UNK GetScriptPose(s8 *, s128, s8 *, s128 *); /* extern */
s8 *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s8 *); /* extern */
extern M2C_UNK B_003DD490;
void FindClosestScriptCmd(s8 *arg0, s128 arg1, s8 *arg2) {
    s8 sp[0x30] __attribute__((aligned(16)));
    M2C_UNK32 sp8;
    s128 sp10;
    M2C_UNK32 sp20;
    s128 sp30;
    M2C_UNK temp_v1_2;
    f32 temp_v0_2;
    f32 temp_v0_3;
    f32 var_f20;
    s128 *temp_v0;
    s32 temp_a2;
    s32 var_s3;
    u32 temp_v1;
    s8 *temp_a0;
    s8 *var_s0;
    s8 *var_s1;
    var_s1 = arg0;
    var_s3 = 0;
    sp30 = arg1;
    var_s0 = M2C_FIELD(var_s1, s8 **, 0x50);
    var_f20 = 3.4028235e38f;
    if (var_s0 != NULL) {
        do {
            temp_v1 = M2C_FIELD(var_s0, u32 *, 0);
            switch (temp_v1) {
            case 11:
                var_s3 = 1;
                break;
            case 12:
                var_s3 = 0;
                break;
            case 3:
            case 7:
                if (var_s3 == 0) {
                    temp_a2 = M2C_FIELD(var_s0, s32 *, 4);
                    if (temp_a2 != -1) {
                        GetScriptPose(arg0, sp30, PloFindSwObject_thunk(&B_003DD490, 4, temp_a2, var_s1), &sp10);
                        goto block_10;
                    }
                    temp_v0 = M2C_FIELD(var_s0, s128 **, 8);
                    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
                    if (temp_v0 != NULL) {
                        sp10 = *temp_v0;
block_10:
                        asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
                    }
                    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
                    asm volatile("vsub.xyzw vf1, vf2, vf1");
                    asm volatile("vmul.xyz vf1, vf1, vf1");
                    asm volatile("vaddw.x vf2, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf2, vf1z");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    s32 vu_1;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                    temp_v0_2 = vu_1;
                    if (temp_v0_2 < var_f20) {
                        var_f20 = temp_v0_2;
                    }
                }
                break;
            case 6:
                if (var_s3 == 0) {
                    temp_a0 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(var_s0, s32 *, 4), var_s1);
                    if (arg2 != NULL) {
                        if (M2C_FIELD(arg2, s32 *, 0) == (s32)var_s0) {
                            FindCrvClosestPointFromS(temp_a0, sp30, 0, &sp10, M2C_FIELD(arg2, M2C_UNK32 *, 8));
                        } else {
                            goto block_18;
                        }
                    } else {
block_18:
                        FindCrvClosestPointAll(temp_a0, sp30, 0, &sp10);
                    }
                    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
                    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
                    asm volatile("vsub.xyzw vf1, vf2, vf1");
                    asm volatile("vmul.xyz vf1, vf1, vf1");
                    asm volatile("vaddw.x vf2, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf2, vf1z");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    s32 vu_2;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                    temp_v0_3 = vu_2;
                    if (temp_v0_3 < var_f20) {
                        var_f20 = temp_v0_3;
                        sp8 = sp20;
                    }
                }
                break;
            case 0:
                var_s1 = PloFindSwObject_thunk(&B_003DD490, (var_s1 != NULL) ? 4 : 5, M2C_FIELD(var_s0, s32 *, 4), var_s1);
                break;
            }
            var_s0 = M2C_FIELD(var_s0, s8 **, 0x18);
        } while (var_s0 != NULL);
    }
    if (arg2 != NULL) {
        s32 vu_3;
        asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_3) : "r"(sp));
        s32 vu_4;
        asm volatile("ldr %0, (%1)" : "=r"(vu_4) : "r"(sp), "0"(vu_3));
        temp_v1_2 = vu_4;
        asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_v1_2), "r"(arg2));
        asm volatile("sdr %0, (%1)" : : "r"(temp_v1_2), "r"(arg2));
        M2C_FIELD(arg2, M2C_UNK32 *, 8) = sp8;
    }
}
}
