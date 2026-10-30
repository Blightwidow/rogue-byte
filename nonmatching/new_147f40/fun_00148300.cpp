typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00148300 {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ char pad20[0x70];
};                                                  /* size = 0x90 */
M2C_UNK AppendDlEntry(s32, s32);                    /* extern */
s32 FFindDlEntry(s32, s32);                         /* extern */
s128 PosLoWorld(s8 *);                            /* extern */
s8 *PpoSwFocusBase();                             /* extern */
M2C_UNK RemoveDlEntry(s32, s32);                    /* extern */
extern M2C_UNK B_002DDF40;
extern s32 B_003E0E70;
void func_00148300(s32 arg0, s8 *arg1) {
    s32 saved_reg_s2;
    s8 sp[0x20] __attribute__((aligned(16)));
    s128 sp0;
    s128 sp10;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 var_f20;
    s128 var_v0;
    s32 temp_s0;
    s32 temp_s3;
    s32 var_s0;
    s32 var_s2;
    s64 temp_a0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    var_s2 = saved_reg_s2;
    if (B_003E0E70 == 0) {
        temp_s0 = M2C_FIELD(&B_002DDF40, s32 *, 0x14);
        sp0 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
        temp_v0 = PpoSwFocusBase();
        if (temp_v0 == NULL) {
            var_v0 = sp0;
        } else {
            var_v0 = PosLoWorld(temp_v0);
        }
        sp10 = var_v0;
        temp_a0 = (s64) (M2C_FIELD(arg1, s64 *, 0x28) << 8) >> 0x3C;
        temp_s3 = M2C_FIELD(arg1, s32 *, 0x14);
        switch (temp_a0) {                          /* irregular */
        case 0:
            if (temp_s0 & M2C_FIELD(arg1, u8 *, 0x2D)) {
                temp_f20 = M2C_FIELD(arg1, f32 *, 0x38);
                var_s2 = 1;
                var_f20 = temp_f20 * temp_f20;
                asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg1)));
                asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
block_21:
                asm volatile("vsub.xyzw vf1, vf2, vf3");
                asm volatile("vmul.xyz vf1, vf1, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                var_s0 = arg0 + 0x2C;
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                if (!(vu_1 < var_f20)) {
                    goto block_22;
                }
            } else {
            case 2:
block_22:
                var_s2 = 0;
            default:
block_23:
                var_s0 = arg0 + 0x2C;
            }
            break;
        case 3:
            if (temp_s0 & M2C_FIELD(arg1, u8 *, 0x2D)) {
                temp_f20_2 = M2C_FIELD(arg1, f32 *, 0x38);
                var_s2 = 1;
                var_f20 = temp_f20_2 * temp_f20_2;
                asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(arg1)));
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
                goto block_21;
            }
            goto block_22;
        case 1:
            var_s2 = 1;
            goto block_23;
        }
        if (var_s2 != FFindDlEntry(var_s0, temp_s3)) {
            if (var_s2 == 0) {
                temp_v0_2 = M2C_FIELD(arg1, s8 **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *), 0xB4)(arg1 + M2C_FIELD(temp_v0_2, s16 *, 0xB0));
                RemoveDlEntry(var_s0, temp_s3);
            } else {
                AppendDlEntry(var_s0, temp_s3);
                temp_v0_3 = M2C_FIELD(arg1, s8 **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *), 0xBC)(arg1 + M2C_FIELD(temp_v0_3, s16 *, 0xB8));
            }
        }
    }
}
}
