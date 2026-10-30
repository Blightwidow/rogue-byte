typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_bevy_player_p14_jts8_enter {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK SetBentleyState(s32, M2C_UNK, s8 *);      /* extern */
M2C_UNK SetJmpBodyState(s8 *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK SetJtState(s8 *, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK StartAttach(s32, s32, s8 *, s8 *);      /* extern */
extern s32 g_2dd5bc;
void bevy_player_p14_jts8_enter(s8 *arg0) {
    s32 temp_v0;
    s32 var_a1;
    s8 *temp_a0;
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_a3;
    s8 *temp_a3_2;
    s8 *temp_a3_3;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *var_a2;
    s8 *var_a3;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1C);
    switch (temp_v0) {
    case 6:
        temp_a3 = M2C_FIELD(arg0, s8 **, 0xC);
        var_a1 = 1;
        var_a2 = temp_a3;
        var_a3 = temp_a3 + 0x150;
block_9:
        StartAttach((int)(M2C_FIELD(arg0, s8 **, 0) + 0x4C0), var_a1, var_a2, (var_a2 == NULL) ? NULL : var_a3);
        return;
    case 11:
        var_a1 = 0;
block_8:
        var_a2 = M2C_FIELD(arg0, s8 **, 0xC);
        var_a3 = M2C_FIELD(arg0, s8 **, 0xC) + 0x190;
        goto block_9;
    case 12:
        temp_a3_2 = M2C_FIELD(arg0, s8 **, 0xC);
        var_a1 = 0;
        var_a2 = temp_a3_2;
        var_a3 = temp_a3_2 + 0xE0;
        goto block_9;
    case 13:
        temp_v0_2 = M2C_FIELD(arg0, s8 **, 0xC);
        var_a2 = temp_v0_2;
        var_a3 = temp_v0_2 + 0xE0;
        var_a1 = M2C_FIELD(temp_v0_2, s32 *, 0x10C);
        goto block_9;
    case 9:
        temp_a3_3 = M2C_FIELD(arg0, s8 **, 0xC);
        var_a1 = 4;
        var_a2 = temp_a3_3;
        var_a3 = temp_a3_3 + 0xE0;
        goto block_9;
    case 10:
        var_a1 = 3;
        goto block_8;
    case 14:
        temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xC);
        temp_a2 = M2C_FIELD(arg0, s8 **, 0);
        M2C_FIELD(temp_a2, s8 **, 0x18C4) = temp_v0_3;
        if (M2C_FIELD(temp_v0_3, s32 *, 0x124) == 3) {
            SetJtState(temp_a2, 0x16, -1);
            return;
        }
        SetJtState(temp_a2, 3, 1);
        return;
    case 15:
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s8 **, 0xF5C) = (s8 *) M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), f32 *, 0xF60) = (f32) M2C_FIELD(arg0, f32 *, 0x14);
        temp_a2_2 = M2C_FIELD(arg0, s8 **, 0);
        temp_v0_4 = M2C_FIELD(temp_a2_2, s8 **, 0xC);
        M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x2C4)(temp_a2_2 + M2C_FIELD(temp_v0_4, s16 *, 0x2C0), 8, temp_a2_2);
        return;
    case 16:
        temp_a0 = M2C_FIELD(arg0, s8 **, 0);
        M2C_FIELD(temp_a0, s8 **, 0x1F18) = (s8 *) M2C_FIELD(arg0, s8 **, 0xC);
        SetJtState(temp_a0, 0x15, 0xA);
        return;
    case 18:
        SetBentleyState(g_2dd5bc, 8, arg0);
        return;
    default:
        SetJmpBodyState(arg0, 4, 0);
        return;
    }
}
}
