#include "sly2.h"
struct V4 { float x, y, z, w; };
struct MT { char pad0[0x14]; unsigned char rgba[4]; char pad18[8]; V4 add; V4 mul; V4 addBase; V4 mulBase; };

void CMovieText_UpdateFont(MT *t)
{
    t->mul.z = t->mulBase.z;
    float red = t->addBase.x + (float)t->rgba[0];
    t->mul.y = t->mulBase.y;
    t->add.w = t->addBase.w;
    t->add.x = red < 255.0f ? red : 255.0f;
    float blue = t->addBase.z + (float)t->rgba[2];
    t->mul.x = t->mulBase.x;
    float alpha = t->mulBase.w * 0.007874016f * (float)t->rgba[3];
    float green = t->addBase.y + (float)t->rgba[1];
    t->add.y = green < 255.0f ? green : 255.0f;
    t->add.z = blue < 255.0f ? blue : 255.0f;
    float r;
    if (alpha < 0.0f) r = 0.0f;
    else { r = alpha; if (1.0f < r) r = 1.0f; }
    t->mul.w = r;
}
