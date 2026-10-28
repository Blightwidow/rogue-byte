#include "m2c_macros.h"

void *PvAllocAct(M2C_UNK);                          /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
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

void *PactNew(u32 arg0) {
    M2C_UNK *var_v1;
    s32 var_a0;
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *var_a2;
    void *var_v0;

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
        var_a2 = temp_v0_2;
        M2C_FIELD(temp_v0_2, s32 *, 0) = 1;
        M2C_FIELD(temp_v0_2, s32 *, 0x1C) = 2;
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
