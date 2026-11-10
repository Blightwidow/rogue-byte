#include "types.h"

struct GIFS {
    char pad0[0xC];
    s64 *cursor;
};

extern "C" {
void CheckReg__4GIFSii(GIFS *gifs, s32 a, s32 b);

void PackAD__4GIFSll(GIFS *gifs, s64 address, s64 data) {
    s64 *quad;

    CheckReg__4GIFSii(gifs, 1, 0xE);
    quad = gifs->cursor;
    gifs->cursor = quad + 2;
    quad[0] = data;
    quad[1] = address;
}
}
