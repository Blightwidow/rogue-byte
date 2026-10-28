#include "m2c_macros.h"

s32 UnRadixFromChConversion__Fc(s32 arg0) {
    s32 temp_a0;

    temp_a0 = arg0 & 0xFF;
    switch (temp_a0) {
    case 0x64:
    case 0x69:
    case 0x75:
        return 0xA;
    case 0x42:
    case 0x62:
        return 2;
    case 0x6F:
        return 8;
    case 0x78:
        return 0x10;
    default:
        return 0xA;
    }
}
