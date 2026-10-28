#include "m2c_macros.h"

M2C_UNK Reset__9CRichText();                        /* extern */

void *__9CRichTextPcP5CFont(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 0xC) = arg2;
    M2C_FIELD(arg0, s32 *, 0x154) = 0xFF808080;
    M2C_FIELD(arg0, s32 *, 0x160) = 0xFF808080;
    M2C_FIELD(arg0, s32 *, 0x15C) = 0xFF808080;
    M2C_FIELD(arg0, s32 *, 0x158) = 0xFF808080;
    Reset__9CRichText();
    return arg0;
}
