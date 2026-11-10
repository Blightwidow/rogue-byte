#include "types.h"

extern void *__4DMAS();
extern char D_002CF508[];

struct GIFS {
    char pad0[0x14];
    s32 field_0x14;
    char *field_0x18;
    s32 field_0x1C;
    s32 field_0x20;
    s32 field_0x24;
};

struct GIFS *__4GIFS(struct GIFS *gifs) {
    __4DMAS();
    gifs->field_0x14 = 1;
    gifs->field_0x18 = D_002CF508;
    gifs->field_0x1C = 0;
    gifs->field_0x20 = 0;
    gifs->field_0x24 = 0;
    return gifs;
}
