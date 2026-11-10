#include "types.h"

struct GIFS {
    char pad0[0xC];
    s64 *cursor;
};

extern "C" {
void CheckReg__4GIFSii(GIFS *gifs, s32 a, s32 b);

void GIFS_ListXYZ(GIFS *gifs, s32 x, s32 y, s64 z) {
    s64 *entry;

    CheckReg__4GIFSii(gifs, 0, 5);
    entry = gifs->cursor;
    gifs->cursor = entry + 1;
    *entry = x | (y << 0x10) | (z << 0x20);
}
}
