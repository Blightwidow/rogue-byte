typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AddLaserCustomXps {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ char pad50[0xE0];
};                                                  /* size = 0x130 */
#define sp20 (*(s128 *)(sp + 0x020))
s32 ClsgClipEdgeToObject(s8 *, s128, s128, M2C_UNK, s128 *); /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK GetLaserBeamPoints(s8 *, s32, s128 *, M2C_UNK); /* extern */
M2C_UNK PxpAdd(M2C_UNK *, s32, s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK QueueSwCallbackOnce(M2C_UNK *, s8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001F5990();                            /* extern */
s32 func_00205670(s32, s128, s128, s128 *);         /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A7AC7;
void AddLaserCustomXps(s8 *arg0, s8 *arg1) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s128 sp10;
    s128 sp30;
    s128 sp40;
    s32 temp_s0;
    s32 temp_s3;
    s32 var_s1;
    s32 var_s4;
    var_s4 = 0;
    func_001F5990();
    if (M2C_FIELD(arg0, s32 *, 0x198) > 0) {
        do {
            var_s1 = 0;
            temp_s3 = M2C_FIELD(arg0, s32 *, 0x19C) + (var_s4 * 0x150);
            GetLaserBeamPoints(arg0, temp_s3, &sp10, 0);
            if (ClsgClipEdgeToObject(arg1, sp10, sp20, 1, &sp40) == 0) {
                temp_s0 = *M2C_FIELD(M2C_FIELD(arg1, s8 **, 4), s32 **, 0x14);
                if (FIsBasicDerivedFrom(temp_s0, 0x33) != 0) {
                    var_s1 = func_00205670(temp_s0, sp10, sp20, &sp30);
                }
            } else {
                var_s1 = 1;
                sp30 = sp40;
            }
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
            if (var_s1 != 0) {
                asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf1, vf4, vf5");
                asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
                asm volatile("vmul.xyz vf1, vf1, vf1");
                asm volatile("vaddw.x vf3, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf3, vf1z");
                asm volatile("vsub.xyzw vf2, vf2, vf4");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                asm volatile("vmul.xyz vf4, vf2, vf2");
                asm volatile("vaddw.x vf3, vf0, vf0w");
                asm volatile("vadday.x ACC, vf4, vf4y");
                asm volatile("vmaddz.x vf4, vf3, vf4z");
                asm volatile("vsqrt Q, vf4x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf4, vf0, Q");
                asm volatile("vdiv Q, vf0w, vf4x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf1, vf2, Q");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                s32 vu_3;
                asm volatile("qmfc2.ni %0, vf5" : "=r"(vu_3));
                PxpAdd(&B_003DD490, M2C_FIELD(arg0, s32 *, 0xE4), arg1, vu_3, vu_2, 0xA, vu_1, 0, 0, temp_s3 + 0x148);
                s32 vu_4;
                asm volatile("ldl %0, %%lo(RO_002A7AC7)(%1)" : "=r"(vu_4) : "r"(&RO_002A7AC7));
                s32 vu_5;
                asm volatile("ldr %0, %%lo(RO_002A7AC0)(%1)" : "=r"(vu_5) : "r"(&RO_002A7AC7), "0"(vu_4));
                QueueSwCallbackOnce(&B_003DD490, arg0, vu_5, 0);
            }
            var_s4 += 1;
        } while (var_s4 < M2C_FIELD(arg0, s32 *, 0x198));
    }
}
}
