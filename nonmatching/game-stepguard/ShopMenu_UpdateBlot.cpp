typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ShopMenu_UpdateBlot {
    /* 0x00 */ char pad0[0x14];
    /* 0x14 */ f32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[8];                       /* maybe part of sp14[3]? */
    /* 0x20 */ s8 *sp20;                          /* inferred */
    /* 0x24 */ s8 *sp24;                          /* inferred */
    /* 0x28 */ char pad28[0xA8];
};                                                  /* size = 0xD0 */
s32 ShopMenu_IrowEnd(s8 *, f32, f32);             /* extern */
M2C_UNK SwitchBlotLabel(s8 *, M2C_UNK, s8 *);   /* extern */
M2C_UNK func_00213928(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_00213A08(s8 *, s32, s32);            /* extern */
M2C_UNK func_00213B00(s8 *, M2C_UNK);             /* extern */
M2C_UNK func_00213BD8(s8 *, s32, s32);            /* extern */
M2C_UNK func_00213CD8(...); /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
extern s32 B_003DA570;
extern M2C_UNK D_002BCD04;
extern M2C_UNK D_002C3588;
extern f32 D_FLT_002C35B0;
void ShopMenu_UpdateBlot(s8 *arg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    f32 sp14;
    s8 *sp20;
    s8 *sp24;
    M2C_UNK temp_s0;
    M2C_UNK temp_s0_2;
    s32 temp_s2;
    s32 temp_s5;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s3;
    s8 *temp_a0;
    s8 *var_s0;
    if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x24), s32 *, 0x58) == 2) {
        memset(sp, 0, 0x20);
        temp_s5 = ShopMenu_IrowEnd(arg0, 1.0f, 1.0f);
        if (M2C_FIELD(arg0, s32 *, 0x250) > 0) {
            temp_s0 = (M2C_FIELD(arg0, s32 *, 0x40) == 0) ? 0x4DA : 0x4A1;
            if (B_003DA570 != 0) {
                func_00213CD8(arg0, M2C_FIELD(arg0, s8 **, 0x24), temp_s0, sp);
                sp14 += D_FLT_002C35B0;
            }
            SwitchBlotLabel(M2C_FIELD(arg0, s8 **, 0x24), temp_s0, arg0 + 0x260);
        } else {
            SwitchBlotLabel(M2C_FIELD(arg0, s8 **, 0x24), -1, arg0 + 0x260);
        }
        var_s3 = M2C_FIELD(arg0, s32 *, 0x250);
        sp24 = arg0 + 0x264;
        sp20 = arg0 + 0x25C;
        if (var_s3 < temp_s5) {
            var_s0 = (var_s3 * 8) + 0x4C + arg0;
            do {
                temp_v1 = M2C_FIELD(arg0, s32 *, 0x40);
                temp_s2 = *(((var_s3 - M2C_FIELD(arg0, s32 *, 0x250)) * 4) + &D_002C3588);
                switch (temp_v1) {                  /* switch 1; irregular */
                case 1:                             /* switch 1 */
                    if (M2C_FIELD(var_s0, s32 *, 0) != -1) {
                        func_00213BD8(M2C_FIELD(arg0, s8 **, 0x24), 0x455, temp_s2);
                    } else {
                        func_00213A08(M2C_FIELD(arg0, s8 **, 0x24), 0x455, temp_s2);
                    }
                    break;
                case 0:                             /* switch 1 */
                    temp_v0 = M2C_FIELD(var_s0, s32 *, 0);
                    if (temp_v0 != -1) {
                        temp_v1_2 = *((temp_v0 << 5) + &D_002BCD04);
                        switch (temp_v1_2) {        /* switch 2; irregular */
                        case 7:                     /* switch 2 */
                            M2C_FIELD(var_s0, s32 *, 4) = 0x456;
                            break;
                        case 9:                     /* switch 2 */
                            M2C_FIELD(var_s0, s32 *, 4) = 0x458;
                            break;
                        case 8:                     /* switch 2 */
                            M2C_FIELD(var_s0, s32 *, 4) = 0x457;
                            break;
                        }
                        func_00213BD8(M2C_FIELD(arg0, s8 **, 0x24), 0x455, temp_s2);
                        func_00213BD8(M2C_FIELD(arg0, s8 **, 0x24), M2C_FIELD(var_s0, s32 *, 4), temp_s2);
                    } else {
                        func_00213A08(M2C_FIELD(arg0, s8 **, 0x24), 0x455, temp_s2);
                        func_00213A08(M2C_FIELD(arg0, s8 **, 0x24), M2C_FIELD(var_s0, s32 *, 4), temp_s2);
                        M2C_FIELD(var_s0, s32 *, 4) = -1;
                    }
                    break;
                }
                var_s3 += 1;
                var_s0 += 8;
            } while (var_s3 < temp_s5);
        }
        temp_a0 = M2C_FIELD(arg0, s8 **, 0x24);
        if (M2C_FIELD(arg0, s32 *, 0x24C) >= 0) {
            func_00213B00(temp_a0, 0x437);
            memset(sp, 0, 0x20);
            sp14 = D_FLT_002C35B0 * (f32) (M2C_FIELD(arg0, s32 *, 0x24C) - M2C_FIELD(arg0, s32 *, 0x250));
            func_00213CD8(arg0, M2C_FIELD(arg0, s8 **, 0x24), 0x437, sp, 1.0f, 1.0f);
        } else {
            func_00213928(temp_a0, 0x437);
        }
        if (temp_s5 < M2C_FIELD(arg0, s32 *, 0x48)) {
            temp_s0_2 = (M2C_FIELD(arg0, s32 *, 0x40) == 0) ? 0x4DD : 0x4A4;
            if (B_003DA570 != 0) {
                func_00213CD8(arg0, M2C_FIELD(arg0, s8 **, 0x24), temp_s0_2, sp);
                sp14 += D_FLT_002C35B0;
            }
            SwitchBlotLabel(M2C_FIELD(arg0, s8 **, 0x24), temp_s0_2, sp24);
        } else {
            SwitchBlotLabel(M2C_FIELD(arg0, s8 **, 0x24), -1, sp24);
        }
        SwitchBlotLabel(M2C_FIELD(arg0, s8 **, 0x24), (~M2C_FIELD(arg0, s32 *, 0x30) == 0) ? 0x439 : 0x43B, sp20);
    }
}
}
