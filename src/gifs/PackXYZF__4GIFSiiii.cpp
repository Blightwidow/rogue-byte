#include "types.h"

struct GIFS {
    char pad0[0xC];
    s32 *cursor;
};

extern "C" {
void CheckReg__4GIFSii(GIFS *gifs, s32 a, s32 b);

void PackXYZF__4GIFSiiii(GIFS *gifs, s32 x, s32 y, s32 z, s32 fog) {
    s32 *quad;

    CheckReg__4GIFSii(gifs, 1, 4);
    quad = gifs->cursor;
    gifs->cursor = quad + 4;
    quad[0] = x;
    quad[1] = y;
    quad[2] = z;
    quad[3] = (fog & 0xFF) * 0x10;
}
}
