#include "types.h"

struct GIFS {
    char pad0[0xC];
    u32 *cursor;
};

extern "C" {
void CheckReg__4GIFSii(GIFS *gifs, s32 a, s32 b);

void PackRGBA__4GIFSUi(GIFS *gifs, u32 color) {
    u32 *quad;

    CheckReg__4GIFSii(gifs, 1, 1);
    quad = gifs->cursor;
    gifs->cursor = quad + 4;
    quad[0] = color & 0xFF;
    quad[1] = (color & 0xFF00) >> 8;
    quad[2] = (color >> 0x10) & 0xFF;
    quad[3] = color >> 0x18;
}
}
