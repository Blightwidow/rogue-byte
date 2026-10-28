#include "m2c_macros.h"

s32 SidEpisodeName(u32 arg0) {
    s32 var_a1;

    var_a1 = -1;
    switch (arg0) {
    case 0:
        var_a1 = 0x6D;
        break;
    case 1:
        var_a1 = 0x6E;
        break;
    case 2:
        var_a1 = 0x6F;
        break;
    case 3:
        var_a1 = 0x70;
        break;
    case 4:
        var_a1 = 0x71;
        break;
    case 5:
        var_a1 = 0x72;
        break;
    case 6:
        var_a1 = 0x73;
        break;
    case 7:
        var_a1 = 0x74;
        break;
    case 8:
        var_a1 = 0x75;
        break;
    }
    return var_a1;
}
