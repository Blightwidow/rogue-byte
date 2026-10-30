typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateDprize {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK CheckDprizeBounce(...);         /* extern */
M2C_UNK CheckDprizeCollect(s8 *);                 /* extern */
M2C_UNK UpdateSo();                                 /* extern */
M2C_UNK func_001C6308(s8 *);                      /* extern */
extern f32 D_FLT_002C0D50;
extern f32 g_2dded0;
void UpdateDprize(s8 *arg0) {
    M2C_UNK var_a1;
    u32 temp_v1;
    s8 *temp_v0;
    UpdateSo();
    func_001C6308(arg0);
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x150);
    switch (temp_v1) {
    case 0:
        asm volatile("lqc2 vf1, 0x180(%0)" : : "r"(arg0));
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        if (vu_1 > 10000.0f) {
            CheckDprizeBounce(arg0);
        }
        /* fallthrough */
    case 5:
        CheckDprizeCollect(arg0);
        return;
    case 3:
        var_a1 = 4;
        if (M2C_FIELD(arg0, f32 *, 0x188) < 0.0f) {
block_11:
            temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x260), var_a1);
            return;
        }
    default:
        return;
    case 4:
        if (M2C_FIELD(arg0, s32 *, 0x1C4) != 0) {
            var_a1 = 0;
            if (M2C_FIELD(arg0, f32 *, 0x188) < 25.0f) {
                M2C_FIELD(arg0, s32 *, 0x1C4) = 0;
                goto block_11;
            }
        }
        var_a1 = 2;
        if (D_FLT_002C0D50 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x154))) {
            goto block_11;
        }
        CheckDprizeBounce(arg0, 2);
        CheckDprizeCollect(arg0);
        break;
    }
}
}
