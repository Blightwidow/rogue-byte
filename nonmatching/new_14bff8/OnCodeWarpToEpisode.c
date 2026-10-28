#include "m2c_macros.h"

s32 PdescFromEpisode();                      /* extern */
M2C_UNK RequestTransition(); /* extern */
extern M2C_UNK B_003DD490;

void OnCodeWarpToEpisode(void) {
    s32 var_v0;

    var_v0 = PdescFromEpisode();
    if (var_v0 == 0) {
        var_v0 = PdescFromEpisode(0);
    }
    RequestTransition(&B_003DD490, var_v0, 0x189, -1);
}
