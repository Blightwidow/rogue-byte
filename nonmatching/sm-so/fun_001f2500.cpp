typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001F2500 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 PosLoWorld(s8 *);                             /* extern */
s8 *PvAllocSlotheapImpl(M2C_UNK *);               /* extern */
extern M2C_UNK B_003E12D4;
void func_001F2500(s8 *arg0) {
    f32 temp_f1;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_a2;
    s8 *temp_v0;
    s8 *var_a0;
    s8 *var_s1;
    s8 *var_v1;
    if (M2C_FIELD(arg0, s64 *, 0xD0) & (0xC000 << 0x12)) {
        var_v1 = M2C_FIELD(arg0, s8 **, 0x134);
        var_s1 = arg0;
        if (var_v1 == NULL) {
            var_a0 = M2C_FIELD(var_s1, s8 **, 0x10);
loop_3:
            if (var_a0 != NULL) {
                if (((s32) (((s64) (M2C_FIELD(var_s1, s64 *, 0x148) << 0x20) >> 0x20) << 8) >> 0x1C) != 1) {
                    var_s1 = var_a0;
                    var_v1 = M2C_FIELD(var_s1, s8 **, 0x134);
                    if (var_v1 == NULL) {
                        var_a0 = M2C_FIELD(var_s1, s8 **, 0x10);
                        goto loop_3;
                    }
                    M2C_FIELD(arg0, s8 **, 0x134) = var_v1;
                    goto block_13;
                }
                goto block_7;
            }
block_7:
            temp_v0 = PvAllocSlotheapImpl(&B_003E12D4);
            M2C_FIELD(var_s1, s8 **, 0x134) = temp_v0;
            M2C_FIELD(arg0, s8 **, 0x134) = temp_v0;
            M2C_FIELD(temp_v0, s32 *, 4) = (s32) (M2C_FIELD(var_s1, s32 *, 0x60) + 0x70);
            temp_a0 = M2C_FIELD(arg0, s8 **, 0x134);
            M2C_FIELD(temp_a0, s32 *, 8) = (s32) (M2C_FIELD(temp_a0, s32 *, 8) + 1);
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x134), f32 *, 0x20) = (f32) M2C_FIELD(arg0, f32 *, 0x13C);
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x134), s8 **, 0) = arg0;
            if (var_s1 != arg0) {
                var_v1 = M2C_FIELD(arg0, s8 **, 0x134);
                goto block_13;
            }
        } else {
block_13:
            M2C_FIELD(var_v1, s32 *, 8) = (s32) (M2C_FIELD(var_v1, s32 *, 8) + 1);
        }
        temp_a2 = M2C_FIELD(arg0, s8 **, 0x134);
        asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(arg0)));
        asm volatile("lqc2 vf2, (%0)" : : "r"(M2C_FIELD(temp_a2, s32 *, 4)));
        asm volatile("vsub.xyzw vf1, vf3, vf2");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        temp_f1 = M2C_FIELD(arg0, f32 *, 0xA0) + vu_1;
        if ((M2C_FIELD(arg0, s64 *, 0xD0) & (0x8000 << 0x11)) && (M2C_FIELD(temp_a2, f32 *, 0x10) < temp_f1)) {
            M2C_FIELD(temp_a2, f32 *, 0x10) = temp_f1;
        }
        if (M2C_FIELD(arg0, s64 *, 0xD0) & (0x8000 << 0x12)) {
            temp_a0_2 = M2C_FIELD(arg0, s8 **, 0x134);
            if (M2C_FIELD(temp_a0_2, f32 *, 0x1C) < temp_f1) {
                M2C_FIELD(temp_a0_2, f32 *, 0x1C) = temp_f1;
            }
        }
    }
}
}
