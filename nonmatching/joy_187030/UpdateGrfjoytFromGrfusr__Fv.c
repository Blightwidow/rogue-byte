#include "m2c_macros.h"

extern s32 B_002DFBC4;
extern s32 B_002E0CBC;
extern s32 g_2dfbc0;

void UpdateGrfjoytFromGrfusr__Fv(void) {
    s32 var_v0;

    if (B_002DFBC4 & 0x10) {
        var_v0 = 5;
        goto block_8;
    }
    if (B_002DFBC4 & 0xC) {
        g_2dfbc0 = 0;
    } else {
        if (B_002DFBC4 & 1) {
            var_v0 = 5;
        } else {
            var_v0 = 4;
            if (!(B_002DFBC4 & 2)) {
                var_v0 = 7;
            }
        }
block_8:
        g_2dfbc0 = var_v0;
    }
    if (!(g_2dfbc0 & 2)) {
        B_002E0CBC = 0xFFFF;
    }
}
