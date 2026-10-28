#include "sly2.h"
extern "C" void SetXfKind(void *, void *, int);
extern "C" void WakeXf(void *xf, char *obj)
{
    switch ((short)(*(unsigned short *)(obj + 0x98) - 3)) {
    case 3: case 7:
        SetXfKind(xf, obj, 7);
        break;
    case 9:
        SetXfKind(xf, obj, 0xB);
        break;
    case 16:
        SetXfKind(xf, obj, 0x12);
        break;
    case 0:
        SetXfKind(xf, obj, 1);
        break;
    }
}
