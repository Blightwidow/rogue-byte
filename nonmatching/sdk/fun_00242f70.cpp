typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00242F70 {
    /* 0x000 */ char pad0[0x150];
};                                                  /* size = 0x150 */
M2C_UNK func_00234F48(s32 *, s8 *, s32);     /* extern */
M2C_UNK func_00236960(M2C_UNK *);                   /* extern */
s32 sceSifDmaStat(s32, s8 *);                     /* extern */
s32 sceSifSetDma(s8 *, M2C_UNK, s32 *, s32, s32, f32); /* extern */
extern M2C_UNK B_004505D0;
extern s32 D_002C830C;
s32 func_00242F70(s32 arg0, s32 arg1) {
    s8 sp[0x100] __attribute__((aligned(16)));
    s32 *temp_s1;
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_v0;
    s8 *temp_a1;
    temp_a1 = (s8 *)(&B_004505D0 + ((arg1 * 0x1C) + (arg0 * 0x70)));
    temp_a0 = M2C_FIELD(temp_a1, s32 *, 0xC);
    temp_s1 = M2C_FIELD(temp_a1, s32 **, 4);
    if ((temp_a0 == 0) || (sceSifDmaStat(temp_a0, temp_a1) < 0)) {
        temp_a3 = arg1 * 0x1C;
        temp_a2 = *temp_s1 + 1;
        temp_s2 = temp_a3 + (arg0 * 0x70);
        *temp_s1 = temp_a2;
        temp_s0 = M2C_FIELD((&B_004505D0 + temp_s2), s32 *, 8) + ((temp_a2 & 1) << 5);
        func_00234F48(temp_s1, (s8 *)((s8 *)temp_s1 + 0x1F), temp_a2);
        temp_v0 = sceSifSetDma(sp, 1, temp_s1, temp_s0, 0x20, 0);
        if (temp_v0 == 0) {
            goto block_4;
        }
        M2C_FIELD((&B_004505D0 + temp_s2), s32 *, 0xC) = temp_v0;
        return 1;
    }
block_4:
    if (D_002C830C != 0) {
        func_00236960((M2C_UNK *)("libpad: sceSifSetDma faild\n"));
    }
    return 0;
}
}
