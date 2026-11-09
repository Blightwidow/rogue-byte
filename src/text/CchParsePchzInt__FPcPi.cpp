#include "types.h"
extern "C" {
s32 CchParsePchzInt__FPcPi(u8 *text, s32 *result) {
    s32 sign;
    s32 value;
    s32 length;
    u8 *cursor;

    cursor = text;
    value = 0;
    sign = ((*cursor ^ 0x2D) == 0) ? -1 : 1;
    length = 0;
    if (sign == -1) {
        cursor += 1;
        length = 1;
    }
    if ((unsigned)(*cursor - 0x30) < 0xAU) {
        do {
            length += 1;
            value = value * 0xA + (*cursor++ - 0x30);
        } while ((unsigned)(*cursor - 0x30) < 0xAU);
    }
    *result = value * sign;
    return length;
}
}
