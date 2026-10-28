#include "m2c_macros.h"

M2C_UNK AddPrimPack__4GIFSiiUl(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PackAD__4GIFSll(s32, M2C_UNK, s64);         /* extern */

void CleanupDraw__5CFontP8CTextBoxP4GIFS(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        AddPrimPack__4GIFSiiUl(arg2, 0, 1, 0xE);
        PackAD__4GIFSll(arg2, 0x40, ((0xDF00 << 0x1F) | 0xFF80) << 9);
    }
}
