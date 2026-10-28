#include "m2c_macros.h"

M2C_UNK memset(u32 *, M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK D_002D7468;
extern M2C_UNK D_002D74B8;
extern M2C_UNK D_002D7508;
extern M2C_UNK D_002D7558;
extern M2C_UNK D_002D75A8;
extern M2C_UNK D_002D75F8;
extern M2C_UNK D_002D7648;
extern M2C_UNK D_002D7698;
extern M2C_UNK D_002D76E8;
extern M2C_UNK D_002D7738;
extern M2C_UNK D_002D7788;

u32 *ConstructRipOfType(u32 *arg0, u32 arg1, u32 *arg2) {
    M2C_UNK *var_v1;
    u32 *var_a2;

    var_a2 = arg2;
    switch (arg1) {
    case 3:
        memset(arg0, 0, 0x100);
        var_a2 = arg0;
        var_v1 = &D_002D7738;
block_13:
        M2C_FIELD(arg0, M2C_UNK **, 0xEC) = var_v1;
        break;
    case 10:
        memset(arg0, 0, 0x100);
        var_a2 = arg0;
        var_v1 = &D_002D76E8;
        goto block_13;
    case 8:
        memset(arg0, 0, 0x100);
        var_a2 = arg0;
        var_v1 = &D_002D7698;
        goto block_13;
    case 6:
        memset(arg0, 0, 0x110);
        var_a2 = arg0;
        var_v1 = &D_002D7648;
        goto block_13;
    case 4:
        memset(arg0, 0, 0x100);
        var_a2 = arg0;
        var_v1 = &D_002D75F8;
        goto block_13;
    case 9:
        memset(arg0, 0, 0x110);
        var_a2 = arg0;
        var_v1 = &D_002D75A8;
        goto block_13;
    case 5:
        memset(arg0, 0, 0xF0);
        var_a2 = arg0;
        var_v1 = &D_002D74B8;
        goto block_13;
    case 1:
        memset(arg0, 0, 0x100);
        var_a2 = arg0;
        var_v1 = &D_002D7558;
        goto block_13;
    case 0:
        memset(arg0, 0, 0xF0);
        var_a2 = arg0;
        var_v1 = &D_002D7508;
        goto block_13;
    case 7:
        memset(arg0, 0, 0xF0);
        var_a2 = arg0;
        var_v1 = &D_002D7788;
        goto block_13;
    case 2:
        memset(arg0, 0, 0x100);
        var_a2 = arg0;
        var_v1 = &D_002D7468;
        goto block_13;
    }
    *var_a2 = arg1;
    return var_a2;
}
