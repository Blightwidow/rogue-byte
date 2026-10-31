typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_JobBlot_Update {
    /* 0x00 */ char pad0[0x80];
};                                                  /* size = 0x80 */
s32 FBlotLabelPlaying(s8 *, M2C_UNK);             /* extern */
s32 FTaskComplete(s8 *);                          /* extern */
M2C_UNK UpdateBlotMovie(s8 *);                          /* extern */
M2C_UNK sprintf(M2C_UNK *, M2C_UNK *, s32);         /* extern */
extern M2C_UNK D_STR_002C3EC0;
extern M2C_UNK RO_002A8AA0;
void JobBlot_Update(s8 *arg0) {
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s8 **var_s0;
    s8 **var_s0_2;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_v0;
    s8 *temp_v0_2;
    var_s4 = 0;
    var_s5 = 0;
    var_s3 = 0;
    UpdateBlotMovie(arg0);
    for (var_s1 = 0; var_s1 < M2C_FIELD(arg0, s32 *, 0x194); var_s1++) {
        var_s0 = (s8 **)(arg0 + 0x19C) + var_s1 * 8;
            temp_a0 = *var_s0;
            if (temp_a0 != NULL) {
                if (M2C_FIELD(temp_a0, s32 *, 0x54) == 1) {
                    var_s3 += 1;
                } else if (FTaskComplete(temp_a0) != 0) {
                    var_s4 += 1;
                    var_s5 += 1;
                }
            }
    }
    var_s1_2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x110) > 0) {
        var_s0_2 = (s8 **)(arg0 + 0x118);
        do {
            temp_a0_2 = *var_s0_2;
            if (temp_a0_2 != NULL) {
                if (M2C_FIELD(temp_a0_2, s32 *, 0x54) == 1) {
                    var_s3 += 1;
                } else {
                    var_s4 = (FTaskComplete(temp_a0_2) != 0) ? (var_s4 + 1) : var_s4;
                }
            }
            var_s1_2 += 1;
            var_s0_2 += 8;
        } while (var_s1_2 < M2C_FIELD(arg0, s32 *, 0x110));
    }
    if (FBlotLabelPlaying(arg0, 0x314) != 0) {
        sprintf(&D_STR_002C3EC0, &RO_002A8AA0, var_s5);
        sprintf(&D_STR_002C3EC0 + 0x30, &RO_002A8AA0, M2C_FIELD(arg0, s32 *, 0x194));
        sprintf(&D_STR_002C3EC0 + 0x60, &RO_002A8AA0, M2C_FIELD(arg0, s32 *, 0x194) - var_s5);
    }
    if ((var_s4 == (M2C_FIELD(arg0, s32 *, 0x194) + M2C_FIELD(arg0, s32 *, 0x110))) || (var_s3 == 0)) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *), 0x194)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x190));
        return;
    }
    if (var_s3 > 0) {
        temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, M2C_UNK), 0x18C)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x188), -1);
    }
}
}
