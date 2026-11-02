#include "sly2.h"
struct Rgba8 { unsigned char r, g, b, a; };
extern "C" {
void GreyColor_1ed2d8(void *);
void PackColorVecToU8_11dd30(void *, unsigned char, Rgba8 *);
void UnpackColorU8ToVec_11dcd8(Rgba8 *, void *);
extern int B_003E12C8;
void FilterColorRgba8_1ed278(Rgba8 *color)
{
    struct { QW vec; QW copy; } frame;
    if (B_003E12C8 != 0) {
        *(Rgba8 *)&frame.copy = *color;
        UnpackColorU8ToVec_11dcd8((Rgba8 *)&frame.copy, &frame.vec);
        GreyColor_1ed2d8(&frame.vec);
        PackColorVecToU8_11dd30(&frame.vec, color->a, color);
    }
}
}
