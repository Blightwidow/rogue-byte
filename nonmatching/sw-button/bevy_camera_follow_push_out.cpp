typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_bevy_camera_follow_push_out {
    /* 0x00 */ f32 sp0;                             /* inferred */
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ f32 sp8;                             /* inferred */
    /* 0x0C */ char padC[4];
    /* 0x10 */ f32 sp10;                            /* inferred */
    /* 0x14 */ f32 sp14;                            /* inferred */
    /* 0x18 */ f32 sp18;                            /* inferred */
    /* 0x1C */ char pad1C[4];
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ char pad24[0xAC];
};                                                  /* size = 0xD0 */
#define sp0 (*(f32 *)(sp + 0x00))
#define sp4 (*(f32 *)(sp + 0x04))
#define sp8 (*(f32 *)(sp + 0x08))
#define sp10 (*(f32 *)(sp + 0x10))
#define sp14 (*(f32 *)(sp + 0x14))
#define sp18 (*(f32 *)(sp + 0x18))
s32 PvAllocStackImpl__Fi(s32 *, M2C_UNK);
void UpdateSwAaox__FP2SW(s8 *);
void func_00133E30(s8 *);
void bevy_camera_follow_push_out(s8 *arg0, s32 arg1, s32 arg2, s32 (*arg3)(s32, s8 *), s32 arg4, s32 *arg5, s32 *arg6) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 sp20;
    f32 *var_s2;
    f32 var_f1;
    s32 temp_s5;
    s32 var_s3;
    s8 **var_s1;
    s8 *var_s0;
    asm volatile("qmtc2.ni %0, vf1" : : "r"(arg1));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(arg2));
    asm volatile("vmax.xyz vf3, vf1, vf2");
    asm volatile("vmini.xyz vf1, vf1, vf2");
    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    var_s3 = 0;
    asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
    sp20 = 0x400;
    M2C_FIELD(&sp20, s32 *, 4) = 0x10;
    temp_s5 = PvAllocStackImpl__Fi(&sp20, 0x10);
    func_00133E30(arg0);
    UpdateSwAaox__FP2SW(arg0);
    var_s2 = M2C_FIELD(arg0, f32 **, 0x3D1C);
    if (var_s2 != NULL) {
        var_f1 = *var_s2;
loop_2:
        if (!(sp10 < var_f1) && !(M2C_FIELD(var_s2, f32 *, 0x10) < sp0) && !(sp14 < M2C_FIELD(var_s2, f32 *, 4)) && !(M2C_FIELD(var_s2, f32 *, 0x14) < sp4) && !(sp18 < M2C_FIELD(var_s2, f32 *, 8)) && !(M2C_FIELD(var_s2, f32 *, 0x18) < sp8)) {
            var_s0 = M2C_FIELD(var_s2, s8 **, 0x34);
            if (var_s0 != NULL) {
                var_s1 = (s8 **)((var_s3 * 4) + temp_s5);
                do {
                    if (((arg3 == NULL) || (arg3(arg4, var_s0) != 0)) && (var_s3 < 0x100)) {
                        *var_s1 = var_s0;
                        var_s3 += 1;
                        var_s1 += 4;
                    }
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0x60);
                } while (var_s0 != NULL);
            }
        }
        var_s2 = M2C_FIELD(var_s2, f32 **, 0x40);
        if (var_s2 != NULL) {
            var_f1 = *var_s2;
            goto loop_2;
        }
    }
    *arg6 = temp_s5;
    *arg5 = var_s3;
}
}
