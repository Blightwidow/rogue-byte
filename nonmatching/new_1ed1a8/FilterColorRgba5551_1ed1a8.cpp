#include "sly2.h"
struct RGBA { unsigned char r, g, b, a; };
extern "C" int B_003E12C8;
extern "C" void FilterColorRgba8_1ed278(RGBA *);

void FilterColorRgba5551_1ed1a8(unsigned short *pcolor)
{
    RGBA rgba;
    RGBA copy;
    if (B_003E12C8) {
        int color = *pcolor;
        rgba.r = (*(unsigned char *)pcolor & 0x1F) << 3;
        rgba.g = (color >> 2) & 0xF8;
        rgba.a = (color & 0x8000) ? 0xFF : 0;
        rgba.b = (color >> 7) & 0xF8;
        FilterColorRgba8_1ed278(&rgba);
        copy = rgba;
        *pcolor = ((copy.g & 0xF8) << 2) | (copy.r >> 3) | ((copy.b >> 3) << 10) | ((copy.a >> 7) << 15);
    }
}
