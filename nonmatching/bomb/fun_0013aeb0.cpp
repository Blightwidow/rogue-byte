typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0013AEB0 {
    /* 0x00 */ char pad0[0xB0];
};                                                  /* size = 0xB0 */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK PrepareBombDetonation(s8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PrimeBomb__FP4BOMBf(s8 *, M2C_UNK);       /* extern */
M2C_UNK QueueSwCallback(M2C_UNK *, s8 *, M2C_UNK, s32); /* extern */
s32 func_0013B1C8(s8 *, s32);                     /* extern */
s32 func_001C4098(s32);                             /* extern */
M2C_UNK func_001F4F10();                            /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A4B17;
extern s128 g_2a2da0;
void func_0013AEB0(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 temp_v0;
    f32 var_f21;
    s128 temp_s0_3;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v1;
    s32 var_s4;
    s32 var_v0;
    s8 *temp_v1_2;
    s8 *var_s1;
    s8 *var_s5;
    s8 *var_s6;
    func_001F4F10();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    switch (temp_v1) {                              /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        var_v0 = M2C_FIELD(arg0, s32 *, 0x174);
block_10:
        if (var_v0 == 0) {
        default:                                    /* switch 1 */
            var_s6 = NULL;
            var_s5 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 **, 0x64);
            var_f21 = 3.4028235e38f;
            if (var_s5 != NULL) {
                do {
                    var_s1 = M2C_FIELD(var_s5, s8 **, 0);
                    if (var_s1 != NULL) {
                        asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                        do {
                            asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(var_s1));
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
                            temp_v0 = vu_1;
                            if (!(var_f21 <= temp_v0)) {
                                temp_s0 = M2C_FIELD(arg0, s32 *, 0x150);
                                var_s4 = 0;
                                switch (temp_s0) {  /* switch 2; irregular */
                                case 0:             /* switch 2 */
                                    var_s4 = 1;
                                    break;
                                case 2:             /* switch 2 */
                                    temp_s0_2 = M2C_FIELD((var_s1 + ((1 - ((s32) arg0 != M2C_FIELD(var_s1, s32 *, 8))) << 6)), s32 *, 8);
                                    if (FIsBasicDerivedFrom(temp_s0_2, 0x32) != 0) {
                                        var_s4 = (func_001C4098(temp_s0_2) != 0) ? 1 : 0;
                                    }
                                    break;
                                case 1:             /* switch 2 */
                                    var_s4 = (func_0013B1C8(arg0, M2C_FIELD((var_s1 + ((temp_s0 - ((s32) arg0 != M2C_FIELD(var_s1, s32 *, 8))) << 6)), s32 *, 0xC)) != 0) ? temp_s0 : 0;
                                    break;
                                }
                                if (var_s4 != 0) {
                                    var_f21 = temp_v0;
                                    var_s6 = var_s1;
                                }
                            }
                            var_s1 = M2C_FIELD(var_s1, s8 **, 0xAC);
                            asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                        } while (var_s1 != NULL);
                    }
                    var_s5 = M2C_FIELD(var_s5, s8 **, 4);
                } while (var_s5 != NULL);
            }
            if (var_s6 != NULL) {
                temp_a3 = M2C_FIELD(arg0, s32 *, 0x150);
                switch (temp_a3) {                  /* switch 3; irregular */
                case 0:                             /* switch 3 */
                case 2:                             /* switch 3 */
                    temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
                    temp_s0_3 = M2C_FIELD(var_s6, s128 *, 0x10);
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(M2C_FIELD(temp_v1_2, s32 (**)(s8 *), 0x10C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x108))));
                    asm volatile("vmul.xyz vf1, vf3, vf3");
                    asm volatile("vaddw.x vf2, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf2, vf1z");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    s32 vu_2;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                    if (vu_2 < 0.0001f) {
                        asm volatile("qmtc2.ni %0, vf1" : : "r"(g_2a2da0));
                    } else {
                        asm volatile("vdiv Q, vf0w, vf1x");
                        asm volatile("vwaitq");
                        asm volatile("vmulq.xyzw vf1, vf3, Q");
                    }
                    s32 vu_3;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                    s64 vu_4;
                    asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_s0_3));
                    PrepareBombDetonation(arg0, vu_4, vu_3);
                    PrimeBomb__FP4BOMBf(arg0, 0);
                    break;
                case 1:                             /* switch 3 */
                    s32 vu_5;
                    asm volatile("ldl %0, %%lo(RO_002A4B17)(%1)" : "=r"(vu_5) : "r"(&RO_002A4B17));
                    s32 vu_6;
                    asm volatile("ldr %0, %%lo(RO_002A4B10)(%1)" : "=r"(vu_6) : "r"(&RO_002A4B17), "0"(vu_5));
                    QueueSwCallback(&B_003DD490, arg0, vu_6, M2C_FIELD((var_s6 + ((temp_a3 - ((s32) arg0 != M2C_FIELD(var_s6, s32 *, 8))) << 6)), s32 *, 0xC));
                    break;
                }
            }
        } else {
            return;
        }
        break;
    case 2:                                         /* switch 1 */
        var_v0 = M2C_FIELD(arg0, s32 *, 0x174);
        goto block_10;
    case 1:                                         /* switch 1 */
        if (M2C_FIELD(arg0, s32 *, 0x1E4) != 0) {
            var_v0 = M2C_FIELD(arg0, s32 *, 0x1E8);
            goto block_10;
        }
        break;
    }
}
}
