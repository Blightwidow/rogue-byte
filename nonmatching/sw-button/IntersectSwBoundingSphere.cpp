typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_IntersectSwBoundingSphere {
    /* 0x00 */ char pad0[0xD0];
};                                                  /* size = 0xD0 */
s32 PvAllocStackImpl__Fi(s8 *, s32, s32, s128);
void UpdateSwAaox__FP2SW(s8 *);
void func_00133E30(s8 *);
void IntersectSwBoundingSphere(s8 *arg0, s128 arg1, s32 (*arg2)(s32, s8 *), s32 arg3, s32 *arg4, s32 *arg5, f32 fparg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 var_f0;
    s32 temp_s5;
    s32 var_s3;
    s8 **var_s1;
    s8 *var_s0;
    s8 *var_s2;
    var_s3 = 0;
    temp_s5 = PvAllocStackImpl__Fi(sp, 0x400, 0x10, arg1);
    func_00133E30(arg0);
    UpdateSwAaox__FP2SW(arg0);
    var_s2 = M2C_FIELD(arg0, s8 **, 0x3D1C);
    if (var_s2 != NULL) {
        var_f0 = M2C_FIELD(var_s2, f32 *, 0x30);
loop_2:
        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
        temp_f0 = fparg0 + var_f0;
        asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(var_s2));
        asm volatile("vsub.xyzw vf1, vf2, vf1");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        if (!((temp_f0 * temp_f0) < vu_1)) {
            var_s0 = M2C_FIELD(var_s2, s8 **, 0x34);
            if (var_s0 != NULL) {
                var_s1 = (s8 **)((var_s3 * 4) + temp_s5);
                do {
                    if (((arg2 == NULL) || (arg2(arg3, var_s0) != 0)) && (var_s3 < 0x100)) {
                        *var_s1 = var_s0;
                        var_s3 += 1;
                        var_s1 += 4;
                    }
                    var_s0 = M2C_FIELD(var_s0, s8 **, 0x60);
                } while (var_s0 != NULL);
            }
        }
        var_s2 = M2C_FIELD(var_s2, s8 **, 0x40);
        if (var_s2 != NULL) {
            var_f0 = M2C_FIELD(var_s2, f32 *, 0x30);
            goto loop_2;
        }
    }
    *arg5 = temp_s5;
    *arg4 = var_s3;
}
}
