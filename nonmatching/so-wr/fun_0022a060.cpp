typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0022A060 {
    /* 0x00 */ char pad0[0x70];
};                                                  /* size = 0x70 */
s32 FIsBasicDerivedFrom(s8 *, s32);               /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
s8 *PpoSwFocusBase(M2C_UNK *);                    /* extern */
M2C_UNK UpdateSo();                                 /* extern */
extern M2C_UNK B_003DD490;
void func_0022A060(s8 *arg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    f32 var_f20;
    s32 temp_v1;
    s32 var_s2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v1_2;
    UpdateSo();
    temp_v0 = PpoSwFocusBase(&B_003DD490);
    var_s2 = 0;
    if (temp_v0 != NULL) {
        var_s2 = 0;
        if (FIsBasicDerivedFrom(temp_v0, M2C_FIELD(arg0, s32 *, 0x154)) != 0) {
            if (M2C_FIELD(arg0, s32 *, 0x164) == 0) {
                var_f20 = M2C_FIELD(arg0, f32 *, 0x158);
            } else {
                var_f20 = M2C_FIELD(arg0, f32 *, 0x15C);
            }
            var_s2 = 1;
            asm volatile("qmtc2.ni %0, vf1" : : "r"(PosLoWorld(temp_v0)));
            asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg0)));
            asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf1, vf1, vf2");
            asm volatile("vmul.xyz vf1, vf1, vf1");
            asm volatile("vaddw.x vf2, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf2, vf1z");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
            if (!(vu_1 < var_f20)) {
                var_s2 = 0;
            }
        }
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    if ((temp_v1 == 0) || (temp_v1 == 2)) {
        var_s2 = (M2C_FIELD(&B_003DD490, s32 *, 0x3B0C) != 0) ? 0 : var_s2;
    }
    if ((var_s2 != 0) && (FIsBasicDerivedFrom(temp_v0, 0x34) != 0) && ((M2C_FIELD(temp_v0, s32 *, 0x2DC) != -1) || (temp_v1_2 = M2C_FIELD(temp_v0, s8 **, 0xC), (M2C_FIELD(temp_v1_2, s32 (**)(s8 *), 0x26C)(temp_v0 + M2C_FIELD(temp_v1_2, s16 *, 0x268)) == 2)))) {
        var_s2 = M2C_FIELD(arg0, s32 *, 0x164);
    }
    if (var_s2 != M2C_FIELD(arg0, s32 *, 0x164)) {
        M2C_FIELD(arg0, s32 *, 0x164) = var_s2;
        if (var_s2 != 0) {
            temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x18), 5, 0, 0, 0, 0);
        } else {
            temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x18), 6, 0, 0, 0, 0);
        }
    }
}
}
