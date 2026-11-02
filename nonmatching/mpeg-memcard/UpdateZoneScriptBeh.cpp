typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateZoneScriptBeh {
    /* 0x00 */ char pad0[0x90];
};                                                  /* size = 0x90 */
s32 FIsGuardInSgs(s8 *, M2C_UNK);                 /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
M2C_UNK SetZoneScriptState(s8 *, M2C_UNK);        /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8(s8 *);                          /* extern */
s8 *func_00205458(s8 *, M2C_UNK);               /* extern */
s32 func_00227C90(s32, M2C_UNK);                    /* extern */
extern f32 g_2dded0;
extern s8 *g_2e1e40;
void UpdateZoneScriptBeh(s8 *arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    f32 temp_a0;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f20;
    s32 temp_s2;
    s8 *temp_s0;
    s8 *temp_s0_2;
    s8 *temp_s0_3;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v1;
    func_001EEF98();
loop_11:
    if (func_001EF0A8(arg0) == 0) {
        temp_s2 = M2C_FIELD(arg0, s32 *, 0x30);
        switch (temp_s2) {                          /* irregular */
        case 0:
            temp_s0 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s8 **, 0xF64);
            s64 vu_1;
            asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(PosLoWorld(g_2e1e40)));
            if (func_00227C90(M2C_FIELD(temp_s0, s32 *, 0xEC), vu_1) == 0) {
                SetZoneScriptState(arg0, 1);
            }
            break;
        case 1:
            temp_s0_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s8 **, 0xF64);
            s64 vu_2;
            asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(PosLoWorld(g_2e1e40)));
            if (func_00227C90(M2C_FIELD(temp_s0_2, s32 *, 0xE8), vu_2) != 0) {
                SetZoneScriptState(arg0, 0);
            } else if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), f32 *, 0x1088) < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x34))) {
                SetZoneScriptState(arg0, 2);
            }
            break;
        }
        if (temp_s2 != M2C_FIELD(arg0, s32 *, 0x30)) {
            goto loop_11;
        }
    }
    if ((M2C_FIELD(arg0, s32 *, 0x30) == 0) && (FIsGuardInSgs(M2C_FIELD(arg0, s8 **, 0x10), 9) != 0)) {
        asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0x10))));
        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(g_2e1e40)));
        temp_v1 = M2C_FIELD(arg0, s8 **, 0x10);
        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf1, vf2");
        temp_v0 = temp_v1 + 0x1070;
        asm volatile("vmul.xy vf1, vf1, vf1");
        asm volatile("vaddy.x vf1, vf1, vf1y");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
        temp_a0 = vu_3;
        temp_f4 = M2C_FIELD(temp_v1, f32 *, 0x1080);
        temp_f3 = M2C_FIELD(temp_v1, f32 *, 0x1070) + (temp_a0 * (M2C_FIELD(temp_v0, f32 *, 4) + (temp_a0 * M2C_FIELD(temp_v0, f32 *, 8))));
        temp_f5 = M2C_FIELD(temp_v1, f32 *, 0x1084);
        if (temp_f3 < temp_f4) {
            var_f20 = temp_f4;
        } else {
            var_f20 = temp_f3;
            if (temp_f5 < temp_f3) {
                var_f20 = temp_f5;
            }
        }
        temp_s0_3 = func_00205458(M2C_FIELD(arg0, s8 **, 0x10), 0xA7);
        temp_v0_2 = func_00205458(M2C_FIELD(arg0, s8 **, 0x10), 0xB8);
        if (temp_s0_3 != NULL) {
            M2C_FIELD(temp_s0_3, f32 *, 0xC4) = var_f20;
        } else if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, f32 *, 0x38) = var_f20;
        }
    }
}
}
