#include "types.h"

struct GIFS {
    char pad0[0xC];
    f32 *cursor;
};

extern "C" {
void CheckReg__4GIFSii(GIFS *gifs, s32 a, s32 b);

void PackSTQ__4GIFSfff(GIFS *gifs, f32 s, f32 t, f32 q) {
    f32 *quad;

    CheckReg__4GIFSii(gifs, 1, 2);
    quad = gifs->cursor;
    gifs->cursor = quad + 4;
    quad[0] = s;
    quad[1] = t;
    quad[2] = q;
}
}
