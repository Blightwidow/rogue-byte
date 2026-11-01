#include "m2c_macros.h"

s128 ConvertAloPos(void *, M2C_UNK, s128);          /* extern */
s128 PosLoWorld(s32);                               /* extern */
extern f32 g_2be908;
extern s32 g_2dfb84;

void AttachZone_GetAimPos(void *arg0, s32 arg1, void *arg2) {
    f32 var_f0;

    if (arg2 != NULL) {
        if (g_2dfb84 == 0) {
            M2C_FIELD(arg2, s128 *, 0) = ConvertAloPos(arg0, 0, M2C_FIELD(arg0, s128 *, 0x110));
            PosLoWorld(M2C_FIELD(arg0, s32 *, 0x15C));
            var_f0 = M2C_ERROR(/* unknown instruction: pextuw $a0, $zero, $v0 */);
        } else {
            M2C_FIELD(arg2, s128 *, 0) = PosLoWorld(M2C_FIELD(arg0, s32 *, 0x15C));
            var_f0 = M2C_FIELD(arg2, f32 *, 8);
        }
        M2C_FIELD(arg2, f32 *, 8) = (f32) (var_f0 + g_2be908);
    }
}
