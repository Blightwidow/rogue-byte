#include "sly2.h"
struct B8 { char b[8]; };
struct PAL { B8 h0; B8 h1; };
struct PALH { char pad[8]; unsigned short count; short pad2; unsigned *colors; int qwords; };
extern "C" void FilterColorRgba8_1ed278(unsigned *);
PALH *CopyPaletteHeader(PALH *dst, PALH *src)
{
    PAL *d = (PAL *)dst; PAL *s = (PAL *)src;
    d[0] = s[0];
    unsigned *p = dst->colors;
    for (; p < dst->colors + dst->count; p++)
        FilterColorRgba8_1ed278(p);
    dst->qwords = ((unsigned)dst->count * 4 + 0xF) >> 4;
    return dst;
}
