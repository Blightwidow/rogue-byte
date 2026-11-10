#include "types.h"

struct GIFS {
    char pad0[0x24];
    s32 field_0x24;
};

void CheckReg__4GIFSii(struct GIFS *gifs) {
    gifs->field_0x24 = gifs->field_0x24 + 1;
}
