#include "m2c_macros.h"

M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK UpdateSo();                                 /* extern */
extern M2C_UNK g_2ddfa0;

void bevy_gfx_screen_C2d9500_v15(void *arg0) {
    M2C_UNK unksp8;
    s128 sp0;
    void *temp_v0;

    UpdateSo();
    sp0 = M2C_FIELD(&g_2ddfa0, s128 *, 0x30);
    if (M2C_FIELD(arg0, s32 *, 0x150) == 0) {
        PosLoWorld(arg0);
        unksp8 = M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */);
    }
    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s128), 0xEC)(arg0 + M2C_FIELD(temp_v0, s16 *, 0xE8), sp0);
}
