#include "sly2.h"
struct ITEM { int a; int type; int c[5]; };
struct GC { char pad0[0xC - 0]; ITEM items[1]; };
struct GCX { char pad0[0xC]; ITEM items[0x20]; };
struct GCH { char pad0[0x24]; int index; char pad1[0x1E8 - 0x28]; int mode; int alt; };
extern char D_002BFE08;
int CGc_FFindScreen();
int func_001B01E8(GCH *gc)
{
    if (!CGc_FFindScreen()) return 0;
    int index = gc->index;
    if (index <= 0) return 0;
    ITEM *item = (ITEM *)((char *)gc + 0xC) + index;
    if (gc->mode == 1) {
        int alt = gc->alt;
        if (index < alt) item = (ITEM *)((char *)gc + 0xC) + alt;
    }
    return item->type == (int)&D_002BFE08;
}
