#include "types.h"

struct GIFS {
    char pad0[0xC];
    s32 *cursor;
};

extern "C" {
void CheckReg__4GIFSii(GIFS *gifs, s32 a, s32 b);

void PackUV__4GIFSii(GIFS *gifs, s32 u, s32 v) {
    s32 *quad;

    CheckReg__4GIFSii(gifs, 1, 3);
    quad = gifs->cursor;
    gifs->cursor = quad + 4;
    quad[0] = u;
    quad[1] = v;
}
}
