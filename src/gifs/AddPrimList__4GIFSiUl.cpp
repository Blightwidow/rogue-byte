#include "types.h"

struct GIFSClass {
    char pad0[8];
    s16 delta;
    char pad1[2];
    void (*field_0xC)(void *, s32);
};

struct GIFS {
    char pad0[0xC];
    char *cursor;
    char pad1[4];
    s32 field_0x14;
    GIFSClass *classInfo;
    char *field_0x1C;
    s32 field_0x20;
    s32 field_0x24;
};

extern "C" {
void AddPrimList__4GIFSiUl(GIFS *gifs, s32 prim, u64 data) {
    GIFSClass *classInfo;
    char *entry;

    classInfo = gifs->classInfo;
    classInfo->field_0xC((char *)gifs + classInfo->delta, 0);
    entry = gifs->cursor;
    gifs->cursor = entry + 0x10;
    *(u64 *)(entry + 8) = data;
    *(u64 *)entry = ((u64)prim << 0x3C) | ((u64)0x8000 << 0x2B);
    gifs->field_0x20 = prim;
    gifs->field_0x1C = entry;
    gifs->field_0x24 = 0;
}
}
