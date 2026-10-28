#include "m2c_macros.h"

M2C_UNK InitZpr__FP3ZPR3ZPKP2LO(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0015F710(M2C_UNK *, s32, void *);      /* extern */
extern M2C_UNK B_002DE770;
extern s32 D_002BE320;

void InitFonts(void) {
    char sp[0x400];
    M2C_UNK *temp_a0;
    M2C_UNK *var_s1;
    s32 *var_s0;
    s32 var_s2;

    var_s2 = 1;
    InitZpr__FP3ZPR3ZPKP2LO(sp, 0x1000, 0x1800);
    var_s1 = &B_002DE770;
    var_s0 = &D_002BE320;
    do {
        temp_a0 = var_s1;
        var_s1 += 0x140;
        func_0015F710(temp_a0, *var_s0, sp);
        var_s2 -= 1;
        var_s0 += 4;
    } while (var_s2 >= 0);
}
