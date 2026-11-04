// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
extern "C" float floorf(float);
static inline float GClamp(float g, float lo, float hi)
{
    if (g < lo)
        return lo;
    if (hi < g)
        return hi;
    return g;
}
void ConvertHsvToRgb(VECTOR *phsv, VECTOR *prgb)
{
    float h = phsv->x >= 0.0f ? GClamp(phsv->x, 0.0f, 360.0f) : -1.0f;
    float s = GClamp(phsv->y, 0.0f, 1.0f);
    float v = GClamp(phsv->z, 0.0f, 1.0f);
    if (s == 0.0f) {
        prgb->x = v;
        prgb->y = v;
        prgb->z = v;
        return;
    }
    if (h == 360.0f)
        h = 0.0f;
    h *= 1.0f / 60.0f;
    int i = (int)floorf(h);
    float f = h - i;
    float p = v * (1.0f - s);
    float q = v * (1.0f - s * f);
    float t = v * (1.0f - s * (1.0f - f));
    switch (i) {
    case 0:
    case 6:
        prgb->x = v; prgb->y = t; prgb->z = p;
        break;
    case 1:
        prgb->x = q; prgb->y = v; prgb->z = p;
        break;
    case 2:
        prgb->x = p; prgb->y = v; prgb->z = t;
        break;
    case 3:
        prgb->x = p; prgb->y = q; prgb->z = v;
        break;
    case 4:
        prgb->x = t; prgb->y = p; prgb->z = v;
        break;
    case 5:
        prgb->x = v; prgb->y = p; prgb->z = q;
        break;
    }
}
