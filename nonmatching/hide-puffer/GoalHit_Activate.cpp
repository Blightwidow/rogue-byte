typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GoalHit_Activate {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
f32 *PmatLoWorld(s8 *);                           /* extern */
s32 PosLoWorld(...);                       /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
M2C_UNK ReplaceSwHitFx(M2C_UNK *, M2C_UNK, M2C_UNK, s8 *); /* extern */
M2C_UNK SetJumperTarget(s32, M2C_UNK);              /* extern */
s128 SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
M2C_UNK TriggerJoyRumbleRumk__FP3JOY4RUMKf(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
f32 atan2f(f32, f32);                               /* extern */
M2C_UNK func_00174950();                            /* extern */
s32 func_001A6AF8(s32, s32);                        /* extern */
M2C_UNK func_001EEFC0(s8 *);                      /* extern */
M2C_UNK func_00209818(s8 *, f32);                 /* extern */
M2C_UNK func_0020AB68(s8 *, M2C_UNK, M2C_UNK, s128); /* extern */
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;
extern f32 g_2dded0;
extern s32 g_2f7900;
void GoalHit_Activate(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 *temp_s0;
    f32 var_f0;
    f32 var_f0_2;
    s32 temp_v0;
    s32 var_v0;
    s8 *temp_v1;
    func_00174950();
    asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(arg0));
    var_v0 = 0;
    asm volatile("vmul.xyz vf1, vf1, vf1");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
    if (vu_1 > 0.0001f) {
        var_v0 = M2C_FIELD(arg0, s32 *, 0x5C) != 0x40000;
    }
    if (var_v0 != 0) {
        var_f0 = atan2f(-M2C_FIELD(arg0, f32 *, 0x84), -M2C_FIELD(arg0, f32 *, 0x80));
    } else {
        temp_s0 = PmatLoWorld(M2C_FIELD(arg0, s8 **, 0x10));
        var_f0 = atan2f(M2C_FIELD(temp_s0, f32 *, 4), *PmatLoWorld(M2C_FIELD(arg0, s8 **, 0x10)));
    }
    func_00209818(M2C_FIELD(arg0, s8 **, 0x10) + 0xFD0, var_f0);
    temp_v1 = M2C_FIELD(arg0, s8 **, 0x40);
    if (temp_v1 != NULL) {
        if (M2C_FIELD(temp_v1, s32 *, 0) == 2) {
            asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10), SetVectorCylind__FP6VECTORfff(RadNormalize__Ff(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), f32 *, 0x1A8) + 3.1415927f), M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x40), s8 **, 4), f32 *, 0x1C), 0))));
            asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
            asm volatile("vadd.xyzw vf1, vf1, vf2");
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
            SetJumperTarget(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x40), s32 *, 8), vu_2);
        }
    }
    func_0020AB68(M2C_FIELD(arg0, s8 **, 0x10), 0, 0, g_2a2dd0);
    if (M2C_FIELD(arg0, s32 *, 0x30) == 0) {
        func_001EEFC0(arg0);
    }
    s64 vu_3;
    asm volatile("por %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10))));
    ReplaceSwHitFx(&B_003DD490, 1, vu_3, M2C_FIELD(arg0, s8 **, 0x10));
    M2C_FIELD(arg0, f32 *, 0xB0) = 3.4028235e38f;
    M2C_FIELD(arg0, f32 *, 0xB4) = 3.4028235e38f;
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xF04) = 0;
    if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0x334) != 0) {
        temp_v0 = PpoSwFocusBase(&B_003DD490);
        var_f0_2 = g_2dded0;
        if (temp_v0 != 0) {
            if (func_001A6AF8(M2C_FIELD(arg0, s32 *, 0x50), temp_v0) != 0) {
                if ((temp_v0 == g_2f7900) || (var_f0_2 = g_2dded0, ((M2C_FIELD(arg0, s32 *, 0x5C) & 0x40000) != 0))) {
                    TriggerJoyRumbleRumk__FP3JOY4RUMKf(&B_002DFC00, 3, 0x3E19999A);
                    M2C_FIELD(arg0, f32 *, 0xB0) = (f32) (g_2dded0 + 0.050000004f);
                    goto block_17;
                }
            } else {
block_17:
                var_f0_2 = g_2dded0;
            }
        }
        M2C_FIELD(arg0, f32 *, 0xB4) = (f32) (var_f0_2 + 0.13333334f);
    }
}
}
