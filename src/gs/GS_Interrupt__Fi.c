#include "m2c_macros.h"

M2C_UNK ClearFrameBuffers__Fv();                    /* extern */
M2C_UNK FlushCache(M2C_UNK);                        /* extern */
M2C_UNK SyncVBlank__Fv();                           /* extern */
M2C_UNK sceGsSwapDBuff(M2C_UNK *, s32);              /* extern */
M2C_UNK sceGsResetGraph(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK sceGsSetHalfOffset(M2C_UNK *, M2C_UNK, M2C_UNK, s16); /* extern */
extern M2C_UNK B_002DEB80;
extern M2C_UNK B_002DEBE0;
extern s32 B_002DEDB4;
extern s32 B_002DFB5C;
extern s32 D_002BE594;
extern M2C_UNK g_2decd0;
extern s32 g_2dedb0;
extern s32 g_2dedb8;
extern s32 g_2dedbc;

void GS_Interrupt__Fi(void) {
    M2C_UNK *var_a0;
    s32 temp_a1;
    s32 temp_v1;

    B_002DFB5C = 1;
    ClearFrameBuffers__Fv();
    SyncVBlank__Fv();
    B_002DFB5C = 0;
    sceGsResetGraph(0, 1, 2, 1);
    temp_v1 = ((u32) *(u32 *)0x12001000 >> 0xD) & 1;
    g_2dedbc = 0;
    D_002BE594 = 0;
    g_2dedb8 = temp_v1;
    B_002DEDB4 = temp_v1 == 0;
    if (g_2dedb0 & 1) {
        var_a0 = &B_002DEBE0;
    } else {
        var_a0 = &g_2decd0;
    }
    sceGsSetHalfOffset(var_a0, 0x800, 0x800, (s16) B_002DEDB4);
    FlushCache(0);
    temp_a1 = g_2dedb0 + 1;
    g_2dedb0 = temp_a1;
    sceGsSwapDBuff(&B_002DEB80, temp_a1);
}
