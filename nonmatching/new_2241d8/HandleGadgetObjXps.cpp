typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_HandleGadgetObjXps {
    /* 0x00 */ char pad0[0xB0];
};                                                  /* size = 0xB0 */
s32 FGadgetObjAcceptsStick(s8 *, s32);
s32 FGadgetObjCanStick(s8 *);
void func_001F4F10();
extern M2C_UNK D_FLT_002C3C60;
extern f32 D_FLT_002C42E0;
extern f32 g_2dded0;
void HandleGadgetObjXps(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 temp_s0;
    s32 temp_s3;
    s32 temp_s5;
    s8 **var_s4;
    s8 *temp_v0;
    s8 *var_s1;
    func_001F4F10();
    if ((M2C_FIELD(arg0, s32 *, 0x150) != 0) || !((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x154)) < D_FLT_002C42E0)) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0xEC);
        var_s4 = M2C_FIELD(temp_v0, s8 ***, 0x64);
        temp_s5 = M2C_FIELD(temp_v0, s32 *, 0x60);
        if (var_s4 != NULL) {
            var_s1 = *var_s4;
loop_4:
            if (var_s1 != NULL) {
                do {
                    temp_s3 = M2C_FIELD(var_s1, s32 *, 8) != temp_s5;
                    if (M2C_FIELD(*(var_s1 + (temp_s3 << 6)), s32 *, 4) == (s32)arg0) {
                        temp_s0 = M2C_FIELD((var_s1 + ((1 - temp_s3) << 6)), s32 *, 0xC);
                        if ((M2C_FIELD(var_s1, s32 *, 0x9C) != 8) && (FGadgetObjCanStick(arg0) != 0) && (FGadgetObjAcceptsStick(arg0, temp_s0) != 0)) {
                            M2C_FIELD(arg0, s32 *, 0x1A0) = temp_s0;
                            M2C_FIELD(arg0, s32 *, 0x158) = 2;
                            asm volatile("qmtc2.ni %0, vf2" : : "r"(*((temp_s3 * 4) + &D_FLT_002C3C60)));
                            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                            asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(var_s1));
                            asm volatile("vmulx.xyzw vf2, vf1, vf2x");
                            asm volatile("sqc2 vf2, 0x190(%0)" : : "r"(arg0));
                        } else if ((M2C_FIELD(arg0, s32 *, 0x150) == 0) && (M2C_FIELD(arg0, s32 *, 0x158) == -1)) {
                            M2C_FIELD(arg0, s32 *, 0x158) = 4;
                        }
                    }
                    var_s1 = M2C_FIELD(var_s1, s8 **, 0xAC);
                } while (var_s1 != NULL);
            }
            var_s4 = M2C_FIELD(var_s4, s8 ***, 4);
            if (var_s4 != NULL) {
                var_s1 = *var_s4;
                goto loop_4;
            }
        }
    }
}
}
