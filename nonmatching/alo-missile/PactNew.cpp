typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PactNew {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s8 *PvAllocAct(M2C_UNK);                          /* extern */
M2C_UNK memset(s8 *, f32, M2C_UNK);           /* extern */
extern M2C_UNK D_002CA6A0;
extern M2C_UNK D_002CA6E0;
extern M2C_UNK D_002CA720;
extern M2C_UNK D_002CA760;
extern M2C_UNK D_002CA7A0;
extern M2C_UNK D_002CA7E0;
extern M2C_UNK D_002CA820;
extern M2C_UNK D_002CAF08;
extern M2C_UNK D_002D2E58;
extern M2C_UNK D_002DB338;
s8 *PactNew(u32 arg0) {
    M2C_UNK *var_v1;
    s32 var_a0;
    s8 *temp_s0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *var_a2;
    s8 *var_v0;
    switch (arg0) {
    case 0:
        temp_v0 = PvAllocAct(0x2C);
        var_a2 = temp_v0;
        M2C_FIELD(temp_v0, s32 *, 0) = 0;
        M2C_FIELD(temp_v0, M2C_UNK **, 0x18) = &D_002CAF08;
        break;
    case 1:
        temp_v0_2 = PvAllocAct(0x30);
        M2C_FIELD(temp_v0_2, M2C_UNK **, 0x18) = &D_002CA820;
        M2C_FIELD(temp_v0_2, s32 *, 0) = 1;
        M2C_FIELD(temp_v0_2, s32 *, 0x1C) = 2;
        var_a2 = temp_v0_2;
        break;
    case 2:
        var_v0 = PvAllocAct(0x80);
        var_a0 = 2;
        var_v1 = &D_002CA7E0;
block_11:
        var_a2 = var_v0;
        M2C_FIELD(var_v0, M2C_UNK **, 0x18) = var_v1;
        M2C_FIELD(var_v0, s32 *, 0) = var_a0;
        break;
    case 3:
        var_v0 = PvAllocAct(0x20);
        var_a0 = 3;
        var_v1 = &D_002DB338;
        goto block_11;
    case 4:
        var_v0 = PvAllocAct(0x28);
        var_a0 = 4;
        var_v1 = &D_002CA7A0;
        goto block_11;
    case 5:
        var_v0 = PvAllocAct(0x30);
        var_a0 = 5;
        var_v1 = &D_002CA760;
        goto block_11;
    case 6:
        temp_v0_3 = PvAllocAct(0x60);
        temp_s0 = temp_v0_3 + 0x20;
        M2C_FIELD(temp_v0_3, M2C_UNK **, 0x18) = &D_002CA720;
        M2C_FIELD(temp_v0_3, s32 *, 0) = 6;
        memset(temp_s0, 0, 0x40);
        var_a2 = temp_v0_3;
        M2C_FIELD(temp_s0, f32 *, 0x14) = 1.0f;
        M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
        M2C_FIELD(temp_s0, f32 *, 0x28) = 1.0f;
        M2C_FIELD(temp_v0_3, f32 *, 0x20) = 1.0f;
        break;
    case 7:
        var_v0 = PvAllocAct(0x20);
        var_a0 = 7;
        var_v1 = &D_002D2E58;
        goto block_11;
    case 8:
        var_v0 = PvAllocAct(0x40);
        var_a0 = 8;
        var_v1 = &D_002CA6E0;
        goto block_11;
    case 9:
        temp_v0_4 = PvAllocAct(0x30);
        M2C_FIELD(temp_v0_4, M2C_UNK **, 0x18) = &D_002CA6A0;
        var_a2 = temp_v0_4;
        M2C_FIELD(temp_v0_4, s32 *, 0) = 9;
        M2C_FIELD(temp_v0_4, s32 *, 0x14) = 0x14;
        break;
    default:
        var_a2 = NULL;
        break;
    }
    return var_a2;
}
}
